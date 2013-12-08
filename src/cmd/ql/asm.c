// Inferno utils/ql/asm.c
// http://code.google.com/p/inferno-os/source/browse/utils/ql/asm.c
//
//	Copyright © 1994-1999 Lucent Technologies Inc.  All rights reserved.
//	Portions Copyright © 1995-1997 C H Forsyth (forsyth@terzarima.net)
//	Portions Copyright © 1997-1999 Vita Nuova Limited
//	Portions Copyright © 2000-2007 Vita Nuova Holdings Limited (www.vitanuova.com)
//	Portions Copyright © 2004,2006 Bruce Ellis
//	Portions Copyright © 2005-2007 C H Forsyth (forsyth@terzarima.net)
//	Revisions Copyright © 2000-2007 Lucent Technologies Inc. and others
//	Portions Copyright © 2010 The Go Authors.  All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include	"l.h"
#include "../ld/lib.h"
#include "../ld/elf.h"
#include "../ld/macho.h"

#define	Dbufslop	100

#define	KMASK	0xF0000000

void	strnput(char*, int);

char linuxdynld[] = "/lib/ld-linux.so.2";
char freebsddynld[] = "/usr/libexec/ld-elf.so.1";

static Prog *datp;

vlong
entryvalue(void)
{
	char *a;
	Sym *s;

	a = INITENTRY;
	if(*a >= '0' && *a <= '9')
		return atolwhex(a);
	s = lookup(a, 0);
	if(s->type == 0)
		return INITTEXT;
	if(dlm && s->type == SDATA)
		return s->value+INITDAT;
	if(s->type != STEXT && s->type != SLEAF)
		diag("entry not text: %s", s->name);
	return s->value;
}

vlong
addstring(Sym *s, char *str)
{
	int n, m;
	vlong r;
	Prog *p;

	if(s->type == 0)
		s->type = SDATA;
	s->reachable = 1;
	r = s->value;
	n = strlen(str)+1;
	while(n > 0) {
		m = n;
		if(m > sizeof(p->to.sval))
			m = sizeof(p->to.sval);
		p = newdata(s, s->value, m, D_EXTERN);
		p->to.type = D_SCONST;
		memmove(p->to.sval, str, m);
		s->value += m;
		str += m;
		n -= m;
	}
	return r;
}

vlong
adduintxx(Sym *s, uint64 v, int wid)
{
	vlong r;
	Prog *p;

	if(s->type == 0)
		s->type = SDATA;
	s->reachable = 1;
	r = s->value;
	p = newdata(s, s->value, wid, D_EXTERN);
	s->value += wid;
	p->to.type = D_CONST;
	p->to.offset = v;
	return r;
}

vlong
adduint8(Sym *s, uint8 v)
{
	return adduintxx(s, v, 1);
}

vlong
adduint16(Sym *s, uint16 v)
{
	return adduintxx(s, v, 2);
}

vlong
adduint32(Sym *s, uint32 v)
{
	return adduintxx(s, v, 4);
}

vlong
adduint64(Sym *s, uint64 v)
{
	return adduintxx(s, v, 8);
}

vlong
addaddr(Sym *s, Sym *t)
{
	vlong r;
	Prog *p;
	enum { Ptrsize = 8 };

	if(s->type == 0)
		s->type = SDATA;
	s->reachable = 1;
	r = s->value;
	p = newdata(s, s->value, Ptrsize, D_EXTERN);
	s->value += Ptrsize;
	p->to.type = D_ADDR;
	// p->to.index = D_EXTERN;		// fixme
	p->to.offset = 0;
	p->to.sym = t;
	return r;
}

vlong
addsize(Sym *s, Sym *t)
{
	vlong r;
	Prog *p;
	enum { Ptrsize = 8 };

	if(s->type == 0)
		s->type = SDATA;
	s->reachable = 1;
	r = s->value;
	p = newdata(s, s->value, Ptrsize, D_EXTERN);
	s->value += Ptrsize;
	p->to.type = D_SIZE;
	// p->to.index = D_EXTERN;		// fixme
	p->to.offset = 0;
	p->to.sym = t;
	return r;
}

vlong
datoff(vlong addr)
{
	if(addr >= INITDAT)
		return addr - INITDAT + rnd(HEADR+textsize, INITRND);
	diag("datoff %#llx", addr);
	return 0;
}

enum {
	ElfStrEmpty,
	ElfStrInterp,
	ElfStrHash,
	ElfStrGot,
	ElfStrGotPlt,
	ElfStrDynamic,
	ElfStrDynsym,
	ElfStrDynstr,
	ElfStrRela,
	ElfStrText,
	ElfStrData,
	ElfStrBss,
	ElfStrGosymcounts,
	ElfStrGosymtab,
	ElfStrGopclntab,
	ElfStrShstrtab,
	ElfStrSymtab,
	ElfStrStrtab,
	NElfStr
};

vlong elfstr[NElfStr];

static int
needlib(char *name)
{
	char *p;
	Sym *s;

	/* reuse hash code in symbol table */
	p = smprint(".elfload.%s", name);
	s = lookup(p, 0);
	if(s->type == 0) {
		s->type = 100;	// avoid SDATA, etc.
		return 1;
	}
	return 0;
}

void
doelf(void)
{
	Sym *s, *shstrtab, *dynamic, *dynstr, *d;
	int h, nsym, t;

	if(HEADTYPE != 7 && HEADTYPE != 9)
		return;

	/* predefine strings we need for section headers */
	shstrtab = lookup(".shstrtab", 0);
	elfstr[ElfStrEmpty] = addstring(shstrtab, "");
	elfstr[ElfStrText] = addstring(shstrtab, ".text");
	elfstr[ElfStrData] = addstring(shstrtab, ".data");
	elfstr[ElfStrBss] = addstring(shstrtab, ".bss");
	if(!debug['s']) {
		elfstr[ElfStrGosymcounts] = addstring(shstrtab, ".gosymcounts");
		elfstr[ElfStrGosymtab] = addstring(shstrtab, ".gosymtab");
		elfstr[ElfStrGopclntab] = addstring(shstrtab, ".gopclntab");
		if(debug['e']) {
			elfstr[ElfStrSymtab] = addstring(shstrtab, ".symtab");
			elfstr[ElfStrStrtab] = addstring(shstrtab, ".strtab");
		}
	}
	elfstr[ElfStrShstrtab] = addstring(shstrtab, ".shstrtab");

	if(!debug['d']) {	/* -d suppresses dynamic loader format */
		elfstr[ElfStrInterp] = addstring(shstrtab, ".interp");
		elfstr[ElfStrHash] = addstring(shstrtab, ".hash");
		elfstr[ElfStrGot] = addstring(shstrtab, ".got");
		elfstr[ElfStrGotPlt] = addstring(shstrtab, ".got.plt");
		elfstr[ElfStrDynamic] = addstring(shstrtab, ".dynamic");
		elfstr[ElfStrDynsym] = addstring(shstrtab, ".dynsym");
		elfstr[ElfStrDynstr] = addstring(shstrtab, ".dynstr");
		elfstr[ElfStrRela] = addstring(shstrtab, ".rela");

		/* dynamic symbol table - first entry all zeros */
		s = lookup(".dynsym", 0);
		s->type = SELFDATA;
		s->reachable = 1;
		s->value += ELF64SYMSIZE;

		/* dynamic string table */
		s = lookup(".dynstr", 0);
		s->type = SELFDATA;
		s->reachable = 1;
		s->value += ELF64SYMSIZE;
		addstring(s, "");
		dynstr = s;

		/* relocation table */
		s = lookup(".rela", 0);
		s->reachable = 1;
		s->type = SELFDATA;

		/* global offset table */
		s = lookup(".got", 0);
		s->reachable = 1;
		s->type = SELFDATA;

		/* got.plt - ??? */
		s = lookup(".got.plt", 0);
		s->reachable = 1;
		s->type = SELFDATA;
		
		/* hash */
		s = lookup(".hash", 0);
		s->reachable = 1;
		s->type = SELFDATA;

		/* define dynamic elf table */
		s = lookup(".dynamic", 0);
		s->reachable = 1;
		s->type = SELFDATA;
		dynamic = s;

		/*
		 * relocation entries for dynimport symbols
		 */
		nsym = 1;	// sym 0 is reserved
		for(h=0; h<NHASH; h++) {
			for(s=hash[h]; s!=S; s=s->link) {
				if(!s->reachable || (s->type != STEXT && s->type != SDATA && s->type != SBSS) || s->dynimpname == nil)
					continue;

				if(!s->dynexport) {
					d = lookup(".rela", 0);
					addaddr(d, s);
					adduint64(d, ELF64_R_INFO(nsym, R_X86_64_64));
					adduint64(d, 0);
				}

				nsym++;

				d = lookup(".dynsym", 0);
				adduint32(d, addstring(lookup(".dynstr", 0), s->dynimpname));
				/* type */
				t = STB_GLOBAL << 4;
				if(s->dynexport && s->type == STEXT)
					t |= STT_FUNC;
				else
					t |= STT_OBJECT;
				adduint8(d, t);

				/* reserved */
				adduint8(d, 0);

				/* section where symbol is defined */
				if(!s->dynexport)
					adduint16(d, SHN_UNDEF);
				else {
					switch(s->type) {
					default:
					case STEXT:
						t = 9;
						break;
					case SDATA:
						t = 10;
						break;
					case SBSS:
						t = 11;
						break;
					}
					adduint16(d, t);
				}

				/* value */
				if(!s->dynexport)
					adduint64(d, 0);
				else
					addaddr(d, s);

				/* size of object */
				adduint64(d, 0);

				if(!s->dynexport && needlib(s->dynimplib))
					elfwritedynent(dynamic, DT_NEEDED, addstring(dynstr, s->dynimplib));
			}
		}

		elfdynhash(nsym);

		/*
		 * .dynamic table
		 */
		s = dynamic;
		elfwritedynentsym(s, DT_HASH, lookup(".hash", 0));
		elfwritedynentsym(s, DT_SYMTAB, lookup(".dynsym", 0));
		elfwritedynent(s, DT_SYMENT, ELF64SYMSIZE);
		elfwritedynentsym(s, DT_STRTAB, lookup(".dynstr", 0));
		elfwritedynentsymsize(s, DT_STRSZ, lookup(".dynstr", 0));
		elfwritedynentsym(s, DT_RELA, lookup(".rela", 0));
		elfwritedynentsymsize(s, DT_RELASZ, lookup(".rela", 0));
		elfwritedynent(s, DT_RELAENT, ELF64RELASIZE);
		if(rpath)
			elfwritedynent(s, DT_RUNPATH, addstring(dynstr, rpath));
		elfwritedynent(s, DT_NULL, 0);
	}
}

void
shsym(Elf64_Shdr *sh, Sym *s)
{
	sh->addr = symaddr(s);
	sh->off = datoff(sh->addr);
	sh->size = s->size;
}

void
phsh(Elf64_Phdr *ph, Elf64_Shdr *sh)
{
	ph->vaddr = sh->addr;
	ph->paddr = ph->vaddr;
	ph->off = sh->off;
	ph->filesz = sh->size;
	ph->memsz = sh->size;
	ph->align = sh->addralign;
}

void
asmb(void)
{
	Prog *p;
	int32 v, t;
	Optab *o;
	vlong vl, va, startva, fo, w, symo, elfsymo, elfstro, elfsymsize, machlink;
	vlong symdatva = SYMDATVA;
	int a, dynsym;
	ElfEhdr *eh;
	ElfPhdr *ph, *pph;
	ElfShdr *sh;

	if(debug['v'])
		Bprint(&bso, "%5.2f asm\n", cputime());
	Bflush(&bso);

	elftextsh = 0;
	elfsymsize = 0;
	elfstro = 0;
	elfsymo = 0;
	seek(cout, HEADR, 0);
	pc = INITTEXT;
	for(p = firstp; p != P; p = p->link) {
		if(p->as == ATEXT) {
			curtext = p;
			autosize = p->to.offset + 4;
			if(p->from3.type == D_CONST) {
				for(; pc < p->pc; pc++)
					cput(0);
			}
		}
		if(p->pc != pc) {
			diag("phase error %lux sb %lux",
				p->pc, pc);
			if(!debug['a'])
				prasm(curp);
			pc = p->pc;
		}
		curp = p;
		o = oplook(p);	/* could probably avoid this call */
		if(asmout(p, o, 0)) {
			p = p->link;
			pc += 4;
		}
		pc += o->size;
	}
	if(debug['a'])
		Bprint(&bso, "\n");
	Bflush(&bso);
	cflush();

	curtext = P;
	switch(HEADTYPE) {
	default:
		diag("unknown header type %ld", HEADTYPE);
	case 2:
	case 5:
		seek(cout, HEADR+textsize, 0);
		break;
	case 6:
		debug['8'] = 1;	/* 64-bit addresses */
		v = HEADR+textsize;
		seek(cout, v, 0);
		v = rnd(v, 4096) - v;
		while(v > 0) {
			cput(0);
			v--;
		}
		cflush();
		break;

	case 7:
	case 9:
		debug['8'] = 1;	/* 64-bit addresses */
		v = rnd(HEADR+textsize, INITRND);
		seek(cout, v, 0);
		
		/* index of elf text section; needed by asmelfsym, double-checked below */
		/* debug['d'] causes 8 extra sections before the .text section */
		elftextsh = 1;
		if(!debug['d'])
			elftextsh += 8;
		break;
	}

	if(dlm){
		char buf[8];

		write(cout, buf, INITDAT-textsize);
		textsize = INITDAT;
	}

	for(t = 0; t < datsize; t += sizeof(buf)-Dbufslop) {
		if(datsize-t > sizeof(buf)-Dbufslop)
			datblk(t, sizeof(buf)-Dbufslop);
		else
			datblk(t, datsize-t);
	}

	machlink = 0;
	if(HEADTYPE == 6)
		machlink = domacholink();

	symsize = 0;
	lcsize = 0;
	symo = 0;
	if(!debug['s']) {
		if(debug['v'])
			Bprint(&bso, "%5.2f sym\n", cputime());
		Bflush(&bso);
		switch(HEADTYPE) {
		case 2:
		case 5:
			debug['s'] = 1;
			symo = HEADR+textsize+datsize;
			break;
		case 6:
			symo = rnd(HEADR+textsize, INITRND)+rnd(datsize, INITRND)+machlink;
			break;
		case 7:
		case 9:
			symo = rnd(HEADR+textsize, INITRND)+datsize;
			symo = rnd(symo, INITRND);
			break;
		}
		/*
		 * the symbol information is stored as
		 *	32-bit symbol table size
		 *	32-bit line number table size
		 *	symbol table
		 *	line number table
		 */
		seek(cout, symo+8, 0);
		if(!debug['s'])
			asmsym();
		if(debug['v'])
			Bprint(&bso, "%5.2f sp\n", cputime());
		Bflush(&bso);
		if(!debug['s'])
			asmlc();
		if(dlm)
			asmdyn();
		if(HEADTYPE == 0 || HEADTYPE == 1)	/* round up file length for boot image */
			if((symsize+lcsize) & 1)
				cput(0);
		cflush();
		seek(cout, symo, 0);
		lputb(symsize);
		lputb(lcsize);
		cflush();
		if(!debug['s'] && debug['e']) {
			elfsymo = symo+8+symsize+lcsize;
			seek(cout, elfsymo, 0);
			asmsym();
			cflush();
			elfstro = seek(cout, 0, 1);
			elfsymsize = elfstro - elfsymo;
			write(cout, elfstrdat, elfstrsize);
		}
	}
	else if(dlm){
		seek(cout, HEADR+textsize+datsize, 0);
		asmdyn();
		cflush();
	}

	seek(cout, 0L, 0);
	switch(HEADTYPE) {
	case 2:
		if(dlm)
			lputb(0x80000000 | (4*21*21+7));		/* magic */
		else
			lputb(4*21*21+7);	/* magic */
		lputb(textsize);			/* sizes */
		lputb(datsize);
		lputb(bsssize);
		lputb(symsize);			/* nsyms */
		vl = entryvalue();
		lputb(vl);			/* va of entry   fixme: PADDR(vl) */
		lputb(0L);		/* ??spsize */
		lputb(lcsize);
		lputb(vl>>32);
		lputb(vl);			/* va of entry */
		break;
	case 3:
		if(dlm)
			lputb(0x80000000 | (4*21*21+7));		/* magic */
		else
			lputb(4*21*21+7);	/* magic */
		lputb(textsize);			/* sizes */
		lputb(datsize);
		lputb(bsssize);
		lputb(symsize);			/* nsyms */
		lputb(entryvalue());		/* va of entry */
		lputb(spsize);
		lputb(lcsize);
		break;
	case 6:
		asmbmacho(symdatva, symo);
		break;
	case 7:
	case 9:
		/* elf amd-64 */

		eh = getElfEhdr();
		fo = HEADR;
		startva = INITTEXT - HEADR;
		va = startva + fo;
		w = textsize;

		/* This null SHdr must appear before all others */
		sh = newElfShdr(elfstr[ElfStrEmpty]);

		/* program header info */
		pph = newElfPhdr();
		pph->type = PT_PHDR;
		pph->flags = PF_R + PF_X;
		pph->off = eh->ehsize;
		pph->vaddr = INITTEXT - HEADR + pph->off;
		pph->paddr = INITTEXT - HEADR + pph->off;
		pph->align = INITRND;

		if(!debug['d']) {
			/* interpreter */
			sh = newElfShdr(elfstr[ElfStrInterp]);
			sh->type = SHT_PROGBITS;
			sh->flags = SHF_ALLOC;
			sh->addralign = 1;
			switch(HEADTYPE) {
			case 7:
				elfinterp(sh, startva, linuxdynld);
				break;
			case 9:
				elfinterp(sh, startva, freebsddynld);
				break;
			}

			ph = newElfPhdr();
			ph->type = PT_INTERP;
			ph->flags = PF_R;
			phsh(ph, sh);
		}

		ph = newElfPhdr();
		ph->type = PT_LOAD;
		ph->flags = PF_X+PF_R;
		ph->vaddr = va - fo;
		ph->paddr = va - fo;
		ph->off = 0;
		ph->filesz = w + fo;
		ph->memsz = w + fo;
		ph->align = INITRND;

		fo = rnd(fo+w, INITRND);
		va = rnd(va+w, INITRND);
		w = datsize;

		ph = newElfPhdr();
		ph->type = PT_LOAD;
		ph->flags = PF_W+PF_R;
		ph->off = fo;
		ph->vaddr = va;
		ph->paddr = va;
		ph->filesz = w;
		ph->memsz = w+bsssize;
		ph->align = INITRND;

		if(!debug['s']) {
			ph = newElfPhdr();
			ph->type = PT_LOAD;
			ph->flags = PF_R;
			ph->off = symo;
			ph->vaddr = symdatva;
			ph->paddr = symdatva;
			ph->filesz = 8+symsize+lcsize;
			ph->memsz = 8+symsize+lcsize;
			ph->align = INITRND;
		}

		/* Dynamic linking sections */
		if (!debug['d']) {	/* -d suppresses dynamic loader format */
			/* S headers for dynamic linking */
			sh = newElfShdr(elfstr[ElfStrGot]);
			sh->type = SHT_PROGBITS;
			sh->flags = SHF_ALLOC+SHF_WRITE;
			sh->entsize = 8;
			sh->addralign = 8;
			shsym(sh, lookup(".got", 0));

			sh = newElfShdr(elfstr[ElfStrGotPlt]);
			sh->type = SHT_PROGBITS;
			sh->flags = SHF_ALLOC+SHF_WRITE;
			sh->entsize = 8;
			sh->addralign = 8;
			shsym(sh, lookup(".got.plt", 0));

			dynsym = eh->shnum;
			sh = newElfShdr(elfstr[ElfStrDynsym]);
			sh->type = SHT_DYNSYM;
			sh->flags = SHF_ALLOC;
			sh->entsize = ELF64SYMSIZE;
			sh->addralign = 8;
			sh->link = dynsym+1;	// dynstr
			// sh->info = index of first non-local symbol (number of local symbols)
			shsym(sh, lookup(".dynsym", 0));

			sh = newElfShdr(elfstr[ElfStrDynstr]);
			sh->type = SHT_STRTAB;
			sh->flags = SHF_ALLOC;
			sh->addralign = 1;
			shsym(sh, lookup(".dynstr", 0));

			sh = newElfShdr(elfstr[ElfStrHash]);
			sh->type = SHT_HASH;
			sh->flags = SHF_ALLOC;
			sh->entsize = 4;
			sh->addralign = 8;
			sh->link = dynsym;
			shsym(sh, lookup(".hash", 0));

			sh = newElfShdr(elfstr[ElfStrRela]);
			sh->type = SHT_RELA;
			sh->flags = SHF_ALLOC;
			sh->entsize = ELF64RELASIZE;
			sh->addralign = 8;
			sh->link = dynsym;
			shsym(sh, lookup(".rela", 0));

			/* sh and PT_DYNAMIC for .dynamic section */
			sh = newElfShdr(elfstr[ElfStrDynamic]);
			sh->type = SHT_DYNAMIC;
			sh->flags = SHF_ALLOC+SHF_WRITE;
			sh->entsize = 16;
			sh->addralign = 8;
			sh->link = dynsym+1;	// dynstr
			shsym(sh, lookup(".dynamic", 0));
			ph = newElfPhdr();
			ph->type = PT_DYNAMIC;
			ph->flags = PF_R + PF_W;
			phsh(ph, sh);
		}

		ph = newElfPhdr();
		ph->type = PT_GNU_STACK;
		ph->flags = PF_W+PF_R;
		ph->align = 8;

		fo = ELFRESERVE;
		va = startva + fo;
		w = textsize;

		if(elftextsh != eh->shnum)
			diag("elftextsh = %d, want %d", elftextsh, eh->shnum);
		sh = newElfShdr(elfstr[ElfStrText]);
		sh->type = SHT_PROGBITS;
		sh->flags = SHF_ALLOC+SHF_EXECINSTR;
		sh->addr = va;
		sh->off = fo;
		sh->size = w;
		sh->addralign = 8;

		fo = rnd(fo+w, INITRND);
		va = rnd(va+w, INITRND);
		w = datsize;

		sh = newElfShdr(elfstr[ElfStrData]);
		sh->type = SHT_PROGBITS;
		sh->flags = SHF_WRITE+SHF_ALLOC;
		sh->addr = va + elfdatsize;
		sh->off = fo + elfdatsize;
		sh->size = w - elfdatsize;
		sh->addralign = 8;

		fo += w;
		va += w;
		w = bsssize;

		sh = newElfShdr(elfstr[ElfStrBss]);
		sh->type = SHT_NOBITS;
		sh->flags = SHF_WRITE+SHF_ALLOC;
		sh->addr = va;
		sh->off = fo;
		sh->size = w;
		sh->addralign = 8;

		if (!debug['s']) {
			fo = symo;
			w = 8;

			sh = newElfShdr(elfstr[ElfStrGosymcounts]);
			sh->type = SHT_PROGBITS;
			sh->flags = SHF_ALLOC;
			sh->off = fo;
			sh->size = w;
			sh->addralign = 1;
			sh->addr = symdatva;

			fo += w;
			w = symsize;

			sh = newElfShdr(elfstr[ElfStrGosymtab]);
			sh->type = SHT_PROGBITS;
			sh->flags = SHF_ALLOC;
			sh->off = fo;
			sh->size = w;
			sh->addralign = 1;
			sh->addr = symdatva + 8;

			fo += w;
			w = lcsize;

			sh = newElfShdr(elfstr[ElfStrGopclntab]);
			sh->type = SHT_PROGBITS;
			sh->flags = SHF_ALLOC;
			sh->off = fo;
			sh->size = w;
			sh->addralign = 1;
			sh->addr = symdatva + 8 + symsize;
			
			if(debug['e']) {
				sh = newElfShdr(elfstr[ElfStrSymtab]);
				sh->type = SHT_SYMTAB;
				sh->off = elfsymo;
				sh->size = elfsymsize;
				sh->addralign = 8;
				sh->entsize = 24;
				sh->link = eh->shnum;	// link to strtab
			
				sh = newElfShdr(elfstr[ElfStrStrtab]);
				sh->type = SHT_STRTAB;
				sh->off = elfstro;
				sh->size = elfstrsize;
				sh->addralign = 1;
			}
		}

		sh = newElfShstrtab(elfstr[ElfStrShstrtab]);
		sh->type = SHT_STRTAB;
		sh->addralign = 1;
		shsym(sh, lookup(".shstrtab", 0));

		/* Main header */
		eh->ident[EI_MAG0] = '\177';
		eh->ident[EI_MAG1] = 'E';
		eh->ident[EI_MAG2] = 'L';
		eh->ident[EI_MAG3] = 'F';
		if(HEADTYPE == 9)
			eh->ident[EI_OSABI] = 9;
		eh->ident[EI_CLASS] = ELFCLASS64;
		eh->ident[EI_DATA] = ELFDATA2LSB;
		eh->ident[EI_VERSION] = EV_CURRENT;

		eh->type = ET_EXEC;
		eh->machine = EM_X86_64;
		eh->version = EV_CURRENT;
		eh->entry = entryvalue();

		pph->filesz = eh->phnum * eh->phentsize;
		pph->memsz = pph->filesz;

		seek(cout, 0, 0);
		a = 0;
		a += elfwritehdr();
		a += elfwritephdrs();
		a += elfwriteshdrs();
		cflush();
		if(a+elfwriteinterp() > ELFRESERVE)
			diag("ELFRESERVE too small: %d > %d", a, ELFRESERVE);
		break;
	}
	cflush();
}

void
strnput(char *s, int n)
{
	for(; *s; s++){
		cput(*s);
		n--;
	}
	for(; n > 0; n--)
		cput(0);
}

void
wputb(int32 l)
{
	cbp[0] = l>>8;
	cbp[1] = l;
	cbp += 2;
	cbc -= 2;
	if(cbc <= 0)
		cflush();
}

void
lputb(int32 l)
{
	cbp[0] = (l)>>24;
	cbp[1] = (l)>>16;
	cbp[2] = (l)>>8;
	cbp[3] = (l) && 0xff;
	cbp += 4;
	cbc -= 4;
	if(cbc <= 0)
		cflush();
}

void
vputb(uint64 v)
{
	lputb(v>>32);
	lputb(v);
}

void
cflush(void)
{
	int n;

	n = sizeof(buf.cbuf) - cbc;
	if(n)
		write(cout, buf.cbuf, n);
	cbp = buf.cbuf;
	cbc = sizeof(buf.cbuf);
}

void
outa(int n, uchar *cast, uchar *map, vlong l)
{
	int i, j;

	Bprint(&bso, pcstr, l);
	for(i=0; i<n; i++) {
		j = i;
		if(map != nil)
			j = map[j];
		Bprint(&bso, "%.2ux", cast[j]);
	}
	for(; i<Maxand; i++)
		Bprint(&bso, "  ");
	Bprint(&bso, "%P\n", curp);
}

void
asmsym(void)
{
	Prog *p;
	Auto *a;
	Sym *s;
	int h;

	s = lookup("etext", 0);
	if(s->type == STEXT)
		putsymb(s->name, 'T', s->value, s->version);

	for(h=0; h<NHASH; h++)
		for(s=hash[h]; s!=S; s=s->link)
			switch(s->type) {
			case SCONST:
				putsymb(s->name, 'D', s->value, s->version);
				continue;

			case SDATA:
				putsymb(s->name, 'D', s->value+INITDAT, s->version);
				continue;

			case SBSS:
				putsymb(s->name, 'B', s->value+INITDAT, s->version);
				continue;

			case SFILE:
				putsymb(s->name, 'f', s->value, s->version);
				continue;
			}

	for(p=textp; p!=P; p=p->pcond) {
		s = p->from.sym;
		if(s->type != STEXT && s->type != SLEAF)
			continue;

		/* filenames first */
		for(a=p->to.autom; a; a=a->link)
			if(a->type == D_FILE)
				putsymb(a->asym->name, 'z', a->aoffset, 0);
			else
			if(a->type == D_FILE1)
				putsymb(a->asym->name, 'Z', a->aoffset, 0);

		if(s->type == STEXT)
			putsymb(s->name, 'T', s->value, s->version);
		else
			putsymb(s->name, 'L', s->value, s->version);

		/* frame, auto and param after */
		putsymb(".frame", 'm', p->to.offset+4, 0);
		for(a=p->to.autom; a; a=a->link)
			if(a->type == D_AUTO)
				putsymb(a->asym->name, 'a', -a->aoffset, 0);
			else
			if(a->type == D_PARAM)
				putsymb(a->asym->name, 'p', a->aoffset, 0);
	}
	if(debug['v'] || debug['n'])
		Bprint(&bso, "symsize = %lud\n", symsize);
	Bflush(&bso);
}

void
putsymb(char *s, int t, int32 v, int ver)
{
	int i, f;

	if(t == 'f')
		s++;
	lputb(v);
	if(ver)
		t += 'a' - 'A';
	cput(t+0x80);			/* 0x80 is variable length */

	if(t == 'Z' || t == 'z') {
		cput(s[0]);
		for(i=1; s[i] != 0 || s[i+1] != 0; i += 2) {
			cput(s[i]);
			cput(s[i+1]);
		}
		cput(0);
		cput(0);
		i++;
	}
	else {
		for(i=0; s[i]; i++)
			cput(s[i]);
		cput(0);
	}
	symsize += 4 + 1 + i + 1;

	if(debug['n']) {
		if(t == 'z' || t == 'Z') {
			Bprint(&bso, "%c %.8lux ", t, v);
			for(i=1; s[i] != 0 || s[i+1] != 0; i+=2) {
				f = ((s[i]&0xff) << 8) | (s[i+1]&0xff);
				Bprint(&bso, "/%x", f);
			}
			Bprint(&bso, "\n");
			return;
		}
		if(ver)
			Bprint(&bso, "%c %.8lux %s<%d>\n", t, v, s, ver);
		else
			Bprint(&bso, "%c %.8lux %s\n", t, v, s);
	}
}

#define	MINLC	4
void
asmlc(void)
{
	long oldpc, oldlc;
	Prog *p;
	long v, s;

	oldpc = INITTEXT;
	oldlc = 0;
	for(p = firstp; p != P; p = p->link) {
		if(p->line == oldlc || p->as == ATEXT || p->as == ANOP) {
			if(p->as == ATEXT)
				curtext = p;
			if(debug['L'])
				Bprint(&bso, "%6lux %P\n",
					p->pc, p);
			continue;
		}
		if(debug['L'])
			Bprint(&bso, "\t\t%6ld", lcsize);
		v = (p->pc - oldpc) / MINLC;
		while(v) {
			s = 127;
			if(v < 127)
				s = v;
			cput(s+128);	/* 129-255 +pc */
			if(debug['L'])
				Bprint(&bso, " pc+%ld*%d(%ld)", s, MINLC, s+128);
			v -= s;
			lcsize++;
		}
		s = p->line - oldlc;
		oldlc = p->line;
		oldpc = p->pc + MINLC;
		if(s > 64 || s < -64) {
			cput(0);	/* 0 vv +lc */
			cput(s>>24);
			cput(s>>16);
			cput(s>>8);
			cput(s);
			if(debug['L']) {
				if(s > 0)
					Bprint(&bso, " lc+%ld(%d,%ld)\n",
						s, 0, s);
				else
					Bprint(&bso, " lc%ld(%d,%ld)\n",
						s, 0, s);
				Bprint(&bso, "%6lux %P\n",
					p->pc, p);
			}
			lcsize += 5;
			continue;
		}
		if(s > 0) {
			cput(0+s);	/* 1-64 +lc */
			if(debug['L']) {
				Bprint(&bso, " lc+%ld(%ld)\n", s, 0+s);
				Bprint(&bso, "%6lux %P\n",
					p->pc, p);
			}
		} else {
			cput(64-s);	/* 65-128 -lc */
			if(debug['L']) {
				Bprint(&bso, " lc%ld(%ld)\n", s, 64-s);
				Bprint(&bso, "%6lux %P\n",
					p->pc, p);
			}
		}
		lcsize++;
	}
	while(lcsize & 1) {
		s = 129;
		cput(s);
		lcsize++;
	}
	if(debug['v'] || debug['L'])
		Bprint(&bso, "lcsize = %ld\n", lcsize);
	Bflush(&bso);
}

void
datblk(int32 s, int32 n)
{
	Prog *p;
	uchar *cast;
	int32 l, fl, j, d;
	vlong o;
	int i, c;
	Adr *a;

	for(p = datp; p != P; p = p->link) {
		a = &p->from;
		l = a->offset - s;
		if(l+a->scale < 0)
			continue;
		datp = p;
		break;
	}

	memset(buf.dbuf, 0, n+100);
	for(p = datp; p != P; p = p->link) {
		a = &p->from;
		l = a->offset - s;
		c = p->reg;
		i = 0;
		if(l < 0) {
			if(l+c <= 0)
				continue;
			i = -l;
			l = 0;
		}

		curp = p;
		if(!a->sym->reachable)
			diag("unreachable symbol in datblk - %s", a->sym->name);
		if(a->sym->type == SMACHO)
			continue;

		if(p->as != AINIT && p->as != ADYNT) {
			for(j=l+(c-i)-1; j>=l; j--)
				if(buf.dbuf[j]) {
					print("%P\n", p);
					diag("multiple initialization for %d %d", s, j);
					break;
				}
		}
		switch(p->to.type) {
		default:
			diag("unknown mode in initialization\n%P", p);
			break;

		case D_FCONST:
			switch(c) {
			default:
			case 4:
				fl = ieeedtof(&p->to.ieee);
				cast = (uchar*)&fl;
				for(; i<c; i++) {
					buf.dbuf[l] = cast[fnuxi8[i+4]];
					l++;
				}
				break;
			case 8:
				cast = (uchar*)&p->to.ieee;
				for(; i<c; i++) {
					buf.dbuf[l] = cast[fnuxi8[i]];
					l++;
				}
				break;
			}
			break;

		case D_SCONST:
			for(; i<c; i++) {
				buf.dbuf[l] = p->to.sval[i];
				l++;
			}
			break;

		case D_CONST:
			d = p->to.offset;
			if(p->to.sym) {
				if(p->to.sym->type == SUNDEF){
					ckoff(p->to.sym, d);
					d += p->to.sym->value;
				}
				if(p->to.sym->type == STEXT ||
				   p->to.sym->type == SLEAF)
					d += p->to.sym->value;
				if(p->to.sym->type == SDATA)
					d += p->to.sym->value + INITDAT;
				if(p->to.sym->type == SBSS)
					d += p->to.sym->value + INITDAT;
				if(dlm)
					dynreloc(p->to.sym, l+s+INITDAT, 1, 0, 0);
			}
			cast = (uchar*)&d;
			switch(c) {
			default:
				diag("bad nuxi %d %d\n%P", c, i, curp);
				break;
			case 1:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi1[i]];
					l++;
				}
				break;
			case 2:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi2[i]];
					l++;
				}
				break;
			case 4:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi4[i]];
					l++;
				}
				break;
			}
			break;
		}
	}
	write(cout, buf.dbuf, n);
	if(!debug['a'])
		return;

	/*
	 * a second pass just to print the asm
	 */
	for(p = datap; p != P; p = p->link) {
		a = &p->from;

		l = a->offset - s;
		if(l >= n)
			continue;

		c = a->scale;
		i = 0;
		if(l < 0)
			continue;

		if(a->sym->type == SMACHO)
			continue;

		switch(p->to.type) {
		case D_FCONST:
			switch(c) {
			default:
			case 4:
				fl = ieeedtof(&p->to.ieee);
				cast = (uchar*)&fl;
				outa(c, cast, fnuxi4, l+s+INITDAT);
				break;
			case 8:
				cast = (uchar*)&p->to.ieee;
				outa(c, cast, fnuxi8, l+s+INITDAT);
				break;
			}
			break;

		case D_SCONST:
			outa(c, (uchar*)p->to.sval, nil, l+s+INITDAT);
			break;

		default:
			o = p->to.offset;
			if(p->to.type == D_SIZE)
				o += p->to.sym->size;
			if(p->to.type == D_ADDR) {
				if(p->to.sym) {
					o += p->to.sym->value;
					if(p->to.sym->type != STEXT && p->to.sym->type != SUNDEF)
						o += INITDAT;
				}
			}
			fl = o;
			cast = (uchar*)&fl;
			switch(c) {
			case 1:
				outa(c, cast, inuxi1, l+s+INITDAT);
				break;
			case 2:
				outa(c, cast, inuxi2, l+s+INITDAT);
				break;
			case 4:
				outa(c, cast, inuxi4, l+s+INITDAT);
				break;
			case 8:
				cast = (uchar*)&o;
				outa(c, cast, inuxi8, l+s+INITDAT);
				break;
			}
			break;
		}
	}
}
