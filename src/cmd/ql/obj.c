// Inferno utils/ql/obj.c
// http://code.google.com/p/inferno-os/source/browse/utils/ql/obj.c
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

#define	EXTERN
#include	"l.h"
#include	"../ld/lib.h"
#include	"../ld/elf.h"
#include	"../ld/macho.h"
#include	<ar.h>

char	*noname		= "<none>";
char	thechar		= 'q';
char	*thestring 	= "power";

/*
 *	-H0 -T0x200000 -R0		is boot
 *	-H1 -T0x100000 -R4		is Be boot
 *	-H2 -T4128 -R4096		is plan9 format
 *	-H3 -T0x02010000 -D0x00001000	is raw
 *	-H4 -T0x1000200 -D0x20000e00 -R4	is aix xcoff executable
 *	-H5 -T0x80010000 -t0x10000	ELF, phys = 10000, vaddr = 0x8001...
 *	-H6 -Tx -Rx			is apple MH-exec
 *	-H7 -Tx -Rx			is linux elf-exec
 *      -H9 -Tx -Rx			is FreeBSD elf-exec
 */

static int
isobjfile(char *f)
{
	int n, v;
	Biobuf *b;
	char buf1[5], buf2[SARMAG];

	b = Bopen(f, OREAD);
	if(b == nil)
		return 0;
	n = Bread(b, buf1, 5);
	if(n == 5 && (buf1[2] == 1 && buf1[3] == '<' || buf1[3] == 1 && buf1[4] == '<'))
		v = 1;	/* good enough for our purposes */
	else{
		Bseek(b, 0, 0);
		n = Bread(b, buf2, SARMAG);
		v = n == SARMAG && strncmp(buf2, ARMAG, SARMAG) == 0;
	}
	Bterm(b);
	return v;
}

void
usage(void)
{
	fprint(2, "usage: ql [-options] [-E entry] [-H head] [-L dir] [-T text] [-R rnd] [-r path] [-o out] main.q\n");
	exits("usage");
}

void
main(int argc, char *argv[])
{
	int c;

	Binit(&bso, 1, OWRITE);
	cout = -1;
	listinit();
	outfile = 0;
	nerrors = 0;
	curtext = P;
	HEADTYPE = -1;
	INITTEXT = -1;
	INITDAT = -1;
	INITRND = -1;
	INITENTRY = 0;

	ARGBEGIN {
	default:
		c = ARGC();
		if(c == 'l')
			usage();
		if(c >= 0 && c < sizeof(debug))
			debug[c]++;
		break;
	case 'o':
		outfile = EARGF(usage());
		break;
	case 'E':
		INITENTRY = EARGF(usage());
		break;
	case 'T':
		INITTEXT = atolwhex(EARGF(usage()));
		break;
	case 'D':
		INITDAT = atolwhex(EARGF(usage()));
		break;
	case 'R':
		INITRND = atolwhex(EARGF(usage()));
		break;
	case 'r':
		rpath = EARGF(usage());
		break;
	case 'H':
		HEADTYPE = atolwhex(EARGF(usage()));
		break;
	case 'L':
		Lflag(EARGF(usage()));
		break;
	case 'x':	/* produce export table */
		doexp = 1;
		if(argv[1] != nil && argv[1][0] != '-' && !isobjfile(argv[1]))
			readundefs(ARGF(), SEXPORT);
		break;
	case 'u':	/* produce dynamically loadable module */
		dlm = 1;
		if(argv[1] != nil && argv[1][0] != '-' && !isobjfile(argv[1]))
			readundefs(ARGF(), SIMPORT);
		break;
	case 'V':
		print("%cl version %s\n", thechar, getgoversion());
		errorexit();
	} ARGEND

	if (1 != argc)
		usage();

	libinit();

	r0iszero = debug['0'] == 0;
	if(HEADTYPE == -1) {
		HEADTYPE = 2;
		if(strcmp(goos, "linux") == 0)
			HEADTYPE = 7;
		else
		if(strcmp(goos, "darwin") == 0)
			HEADTYPE = 6;
		else
		if(strcmp(goos, "freebsd") == 0)
			HEADTYPE = 9;
		else
			print("goos is not known: %s\n", goos);
	}
	switch(HEADTYPE) {
	default:
		diag("unknown -H option");
		errorexit();

	case 0:	/* boot */
		HEADR = 32L;
		if(INITTEXT == -1)
			INITTEXT = 0x200000L;
		if(INITDAT == -1)
			INITDAT = 0;
		if(INITRND == -1)
			INITRND = 4096L;
		break;
	case 1:	/* Be boot format (PEF) */
		HEADR = 208L;
		if(INITTEXT == -1)
			INITTEXT = 0x100000;
		if(INITDAT == -1)
			INITDAT = 0;
		if(INITRND == -1)
			INITRND = 4;
		break;
	case 2:	/* plan 9 */
		HEADR = 32L+8L;
		if(INITTEXT == -1)
			INITTEXT = 4096+HEADR;
		if(INITDAT == -1)
			INITDAT = 0;
		if(INITRND == -1)
			INITRND = 4096;
		break;
	case 3:	/* raw */
		HEADR = 32L;
		if(INITTEXT == -1)
			INITTEXT = 4128;
		if(INITDAT == -1)
			INITDAT = 0;
		if(INITRND == -1)
			INITRND = 4096;
		break;
	case 4:	/* aix unix xcoff executable */
		HEADR = 20L+72L+3*40L;
		if(INITTEXT == -1)
			INITTEXT = 0x1000000L+HEADR;
		if(INITDAT == -1)
			INITDAT = 0x20000000;
		if(INITRND == -1)
			INITRND = 0;
		break;
	case 5:	/* elf executable */
		HEADR = rnd(52L+3*32L, 16);
		if(INITTEXT == -1)
			INITTEXT = 0x00400000L+HEADR;
		if(INITDAT == -1)
			INITDAT = 0x10000000;
		if(INITRND == -1)
			INITRND = 0;
		break;
	case 6:	/* apple MACH */
		machoinit();
		HEADR = MACHORESERVE;
		if(INITRND == -1)
			INITRND = 4096;
		if(INITTEXT == -1)
			INITTEXT = 4096+HEADR;
		if(INITDAT == -1)
			INITDAT = 0;
		break;
	case 7:	/* elf64 executable */
	case 9: /* freebsd */
		elfinit();
		HEADR = ELFRESERVE;
		if(INITTEXT == -1)
			INITTEXT = (1<<22)+HEADR;
		if(INITDAT == -1)
			INITDAT = 0;
		if(INITRND == -1)
			INITRND = 4096;
		break;
	}
	if(INITDAT != 0 && INITRND != 0)
		print("warning: -D0x%lux is ignored because of -R0x%lux\n",
			INITDAT, INITRND);
	if(debug['v'])
		Bprint(&bso, "HEADER = -H0x%x -T0x%lux -D0x%lux -R0x%lux\n",
			HEADTYPE, INITTEXT, INITDAT, INITRND);
	Bflush(&bso);
	zprg.as = AGOK;
	zprg.reg = NREG;
	zprg.from.name = D_NONE;
	zprg.from.type = D_NONE;
	zprg.from.reg = NREG;
	zprg.from3 = zprg.from;
	zprg.to = zprg.from;
	buildop();
	histgen = 0;
	textp = P;
	datap = P;
	pc = 0;
	dtype = 4;

	nuxiinit();
	version = 0;
	cbp = buf.cbuf;
	cbc = sizeof(buf.cbuf);
	firstp = prg();
	lastp = firstp;

	addlibpath("command line", "command line", argv[0], "main");
	loadlib();

	deadcode();

	firstp = firstp->link;
	if(firstp == P)
		goto out;

	if(doexp || dlm){
		EXPTAB = "_exporttab";
		zerosig(EXPTAB);
		zerosig("etext");
		zerosig("edata");
		zerosig("end");
		if(dlm){
			import();
			HEADTYPE = 2;
			INITTEXT = INITDAT = 0;
			INITRND = 8;
			INITENTRY = EXPTAB;
		}
		export();
	}

	patch();
	follow();
	doelf();
	if (6 == HEADTYPE)
		domacho();
	dodata();
	if(firstp == P)
		goto out;
	noops();
	if(debug['p'])
		if(debug['1'])
			doprof1();
		else
			doprof2();
	span();
	asmb();
	undef();

out:
	if(debug['v']) {
		Bprint(&bso, "%5.2f cpu time\n", cputime());
		Bprint(&bso, "%ld symbols\n", nsymbol);
		Bprint(&bso, "%d sizeof adr\n", sizeof(Adr));
		Bprint(&bso, "%d sizeof prog\n", sizeof(Prog));
	}
	Bflush(&bso);

	errorexit();
}

void
zaddr(Biobuf *f, Adr *a, Sym *h[])
{
	int i, c;
	int32 l;
	Sym *s;
	Auto *u;

	a->type = Bgetc(f);
	a->reg = Bgetc(f);
	c = Bgetc(f);
	if(c < 0 || c > NSYM){
		diag("sym out of range: %d\n", c);
		return;
	}

	a->sym = h[c];
	a->name = Bgetc(f);

	if(a->reg > NREG) {
		diag("register out of range %d\n", a->reg);
		return;	/*  force real diagnostic */
	}

	switch(a->type) {
	default:
		diag("unknown type %d\n", a->type);
		return;	/* force real diagnostic */

	case D_NONE:
	case D_REG:
	case D_FREG:
	case D_CREG:
	case D_FPSCR:
	case D_MSR:
	case D_SREG:
	case D_OPT:
		break;

	case D_SPR:
	case D_DCR:
	case D_BRANCH:
	case D_OREG:
	case D_CONST:
		a->offset = Bget4(f);
		break;

	case D_SCONST:
		Bread(f, a->sval, NSNAME);
		break;

	case D_FCONST:
		a->ieee.l = Bget4(f);
		a->ieee.h = Bget4(f);
		break;
	}
	adrgotype = S;
	if (a->type & T_GOTYPE)			// D_GOTYPE ???
		adrgotype = h[Bgetc(f)];
	s = a->sym;
	if(s == S)
		return;
	i = a->name;
	if(i != D_AUTO && i != D_PARAM) {
		if (adrgotype)
			s->gotype = adrgotype;
		return;
	}

	l = a->offset;
	for(u=curauto; u; u=u->link)
		if(u->asym == s)
		if(u->type == i) {
			if(u->aoffset > l)
				u->aoffset = l;
			if (adrgotype)
				s->gotype = adrgotype;
			return;
		}

	u = mal(sizeof(*u));

	u->link = curauto;
	curauto = u;
	u->asym = s;
	u->aoffset = l;
	u->type = i;
	u->gotype = adrgotype;
}

void
nopout(Prog *p)
{
	p->as = ANOP;
	p->from.type = D_NONE;
	p->to.type = D_NONE;
}

void
ldobj1(Biobuf *f, char *pkg, int64 len, char *pn)
{
	Prog *p, *t;
	Sym *h[NSYM], *s, *di;
	int v, o, r, skip;
	int32 ipc;
	uint32 sig;
	char *name, *x;
	int ntext;
	vlong eof;
	char src[1024];			// size ???

	ntext = 0;
	eof = Boffset(f) + len;
	di = S;

newloop:
	memset(h, 0, sizeof(h));
	histfrogp = 0;
	version++;
	ipc = pc;
	skip = 0;

loop:
	if ((Bracteof == f->state) || (eof <= Boffset(f)))
		goto eof;
	o = Bgetc(f);
	if (Beof == o) 
		goto eof;
	
	if(o <= 0 || o >= ALAST) {
		diag("%s:#%lld: opcode out of range: %#ux", pn, Boffset(f), o);
		print("	probably not a .q file\n");
		errorexit();
	}
	if(o == ANAME || o == ASIGNAME) {
		sig = 0;
		if(o == ASIGNAME) 
			sig = Bget4(f);
		v = Bgetc(f);		// type
		o = Bgetc(f);		// sym
		r = 0;
		if(v == D_STATIC)
			r = version;
		name = Brdline(f, '\0');
		if(name == nil) {
			if(Blinelen(f) > 0) {
				fprint(2, "%s: name too long\n", pn);
				errorexit();
			}
			goto eof;
		}
		x = expandpkg(name, pkg);
		s = lookup(x, r);
		if (x != name)
		    	free(x);
		name = nil;

		if(sig != 0){
			if(s->sig != 0 && s->sig != sig)
				diag("incompatible type signatures %lux(%s) and %lux(%s) for %s",
				    s->sig, s->file, sig, pn, s->name);
			s->sig = sig;
			s->file = pn;
		}


		if(debug['W'])
			print("	ANAME	%s\n", s->name);
		h[o] = s;
		if((v == D_EXTERN || v == D_STATIC) && s->type == 0)
			s->type = SXREF;
		if(v == D_FILE) {
			if(s->type != SFILE) {
				histgen++;
				s->type = SFILE;
				s->value = histgen;
			}
			if(histfrogp < MAXHIST) {
				histfrog[histfrogp] = s;
				histfrogp++;
			} else
				collapsefrog(s);
		}
		goto loop;
	}

	p = mal(sizeof(*p));

	p->as = o;
	p->reg = Bgetc(f) & 0x3f;
	if(p->reg & 0x80)
		p->mark = NOSCHED;
	p->line = Bget4(f);
	// p->back = 2;
	// p->mode = mode;
	p->ft = 0;
	p->tt = 0;
	zaddr(f, &p->from, h);
	fromgotype = adrgotype;
	if(p->reg & 0x40)
		zaddr(f, &p->from3, h);
	else
		p->from3 = zprg.from3;
	zaddr(f, &p->to, h);
	p->reg = p->reg & 0x3f;

	if(p->reg < 0 || p->reg > NREG)
		diag("register out of range %d", p->reg);

	p->link = P;
	p->pcond = P;

	if(debug['W'])
		print("%P\n", p);

	switch(o) {
	case AHISTORY:
		if(p->to.offset == -1) {
			addlib(src, pn);
			histfrogp = 0;
			goto loop;
		}
		if(src[0] == '\0')
			copyhistfrog(src, sizeof src);
		addhist(p->line, D_FILE);		/* 'z' */
		if(p->to.offset)
			addhist(p->to.offset, D_FILE1);	/* 'Z' */
		histfrogp = 0;
		goto loop;

	case AEND:
		histtoauto();
		if(curtext != P)
			curtext->to.autom = curauto;
		curauto = 0;
		curtext = P;
		if (eof == Boffset(f))
			return;
		goto newloop;

	case AGLOBL:
		s = p->from.sym;
		if(s == S) {
			diag("GLOBL must have a name\n%P", p);
			errorexit();
		}
		if(s->type == 0 || s->type == SXREF) {
			s->type = SBSS;
			s->value = 0;
		}
		if(s->type != SBSS) {
			diag("redefinition: %s\n%P", s->name, p);
			s->type = SBSS;
			s->value = 0;
		}
		if(p->to.offset > s->value)
			s->value = p->to.offset;
		if (p->from.scale & DUPOK)
			s->dupok = 1;
		break;

	case ADYNT:
		if(p->to.sym == S) {
			diag("DYNT without a sym\n%P", p);
			break;
		}
		di = p->to.sym;
		p->reg = 4;
		if(di->type == SXREF) {
			if(debug['z'])
				Bprint(&bso, "%P set to %d\n", p, dtype);
			di->type = SCONST;
			di->value = dtype;
			dtype += 4;
		}
		if(p->from.sym == S)
			break;

		p->from.offset = di->value;
		p->from.sym->type = SDATA;
		if(curtext == P) {
			diag("DYNT not in text: %P", p);
			break;
		}
		p->to.sym = curtext->from.sym;
		p->to.type = D_CONST;
		p->link = datap;
		datap = p;
		break;

	case AINIT:
		if(p->from.sym == S) {
			diag("INIT without a sym\n%P", p);
			break;
		}
		if(di == S) {
			diag("INIT without previous DYNT\n%P", p);
			break;
		}
		p->from.offset = di->value;
		p->from.sym->type = SDATA;
		p->link = datap;
		datap = p;
		break;

	case ADATA:
		// Assume that AGLOBL comes after ADATA.
		// If we've seen an AGLOBL that said this sym was DUPOK,
		// ignore any more ADATA we see, which must be
		// redefinitions.
		s = p->from.sym;
		if(s != S && s->dupok) {
//			if(debug['v'])
//				Bprint(&bso, "skipping %s in %s: dupok\n", s->name, pn);
			goto loop;
		}
		if(s != S) {
			p->dlink = s->data;
			s->data = p;
			if(s->file == nil)
				s->file = pn;
			else if(s->file != pn) {
				diag("multiple initialization for %s: in both %s and %s", s->name, s->file, pn);
				errorexit();
			}
		}
		p->link = datap;
		datap = p;
		break;

	case AGOK:
		diag("unknown opcode\n%P", p);
		p->pc = pc;
		pc++;
		break;

	case ATEXT:
		s = p->from.sym;
		if(ntext++ == 0 && s->type != 0 && s->type != SXREF) {
			/* redefinition, so file has probably been seen before */
			if(debug['v'])
				Bprint(&bso, "skipping: %s: redefinition: %s", pn, s->name);
			return;
		}
		if(curtext != P) {
			histtoauto();
			curtext->to.autom = curauto;
			curauto = 0;
		}
		curtext = p;
		autosize = (p->to.offset+3L) & ~3L;
		p->to.offset = autosize;
		autosize += 4;

		if(s == S) {
			diag("TEXT must have a name\n%P", p);
			errorexit();
		}
		if(s->type != 0 && s->type != SXREF) {
			if(p->reg & DUPOK) {
				skip = 1;
				goto casedef;
			}
			diag("redefinition: %s\n%P", s->name, p);
		}
		if(fromgotype) {
			if(s->gotype && s->gotype != fromgotype)
				diag("%s: type mismatch for %s", pn, s->name);
			s->gotype = fromgotype;
		}
		newtext(p, s);
		break;

	case AFMOVS:
		if(skip)
			goto casedef;

		if(p->from.type == D_FCONST) {
			/* size sb 9 max */
			sprint(literal, "$%lux", ieeedtof(&p->from.ieee));
			s = lookup(literal, 0);
			if(s->type == 0) {
				s->type = SBSS;
				s->value = 4;
				t = prg();
				t->as = ADATA;
				t->line = p->line;
				t->from.type = D_OREG;
				t->from.sym = s;
				t->from.name = D_EXTERN;
				t->reg = 4;
				t->to = p->from;
				t->link = datap;
				datap = t;
			}
			p->from.type = D_OREG;
			p->from.sym = s;
			p->from.name = D_EXTERN;
			p->from.offset = 0;
		}
		goto casedef;

	case AFMOVD:
		if(skip)
			goto casedef;
		if(p->from.type == D_FCONST) {
			/* size sb 18 max */
			sprint(literal, "$%lux.%lux",
				p->from.ieee.l, p->from.ieee.h);
			s = lookup(literal, 0);
			if(s->type == 0) {
				s->type = SBSS;
				s->value = 8;
				t = prg();
				t->as = ADATA;
				t->line = p->line;
				t->from.type = D_OREG;
				t->from.sym = s;
				t->from.name = D_EXTERN;
				t->reg = 8;
				t->to = p->from;
				t->link = datap;
				datap = t;
			}
			p->from.type = D_OREG;
			p->from.sym = s;
			p->from.name = D_EXTERN;
			p->from.offset = 0;
		}
		goto casedef;

	case ASUBC:
		if(p->from.type == D_CONST) {
			p->from.offset = -p->from.offset;
			p->as = AADDC;
		}
		goto casedef;

	case ASUBCCC:
		if(p->from.type == D_CONST) {
			p->from.offset = -p->from.offset;
			p->as = AADDCCC;
		}
		goto casedef;

	case ASUB:
		if(p->from.type == D_CONST) {
			p->from.offset = -p->from.offset;
			p->as = AADD;
		}
		goto casedef;

	default:
	casedef:
		if(skip)
			nopout(p);

		if(p->to.type == D_BRANCH)
			p->to.offset += ipc;
		lastp->link = p;
		lastp = p;
		p->pc = pc;
		pc++;
		break;
	}
	goto loop;

eof:
	diag("truncated object file: %s", pn);
}

Prog*
prg(void)
{
	Prog *p;

	p = mal(sizeof(*p));
	*p = zprg;
	return p;
}

void
doprof1(void)
{
	Sym *s;
	int32 n;
	Prog *p, *q;

	if(debug['v'])
		Bprint(&bso, "%5.2f profile 1\n", cputime());
	Bflush(&bso);
	s = lookup("__mcount", 0);
	n = 1;
	for(p = firstp->link; p != P; p = p->link) {
		if(p->as == ATEXT) {
			q = prg();
			q->line = p->line;
			q->link = datap;
			datap = q;
			q->as = ADATA;
			q->from.type = D_OREG;
			q->from.name = D_EXTERN;
			q->from.offset = n*4;
			q->from.sym = s;
			q->reg = 4;
			q->to = p->from;
			q->to.type = D_CONST;

			q = prg();
			q->line = p->line;
			q->pc = p->pc;
			q->link = p->link;
			p->link = q;
			p = q;
			p->as = AMOVW;
			p->from.type = D_OREG;
			p->from.name = D_EXTERN;
			p->from.sym = s;
			p->from.offset = n*4 + 4;
			p->to.type = D_REG;
			p->to.reg = REGTMP;

			q = prg();
			q->line = p->line;
			q->pc = p->pc;
			q->link = p->link;
			p->link = q;
			p = q;
			p->as = AADD;
			p->from.type = D_CONST;
			p->from.offset = 1;
			p->to.type = D_REG;
			p->to.reg = REGTMP;

			q = prg();
			q->line = p->line;
			q->pc = p->pc;
			q->link = p->link;
			p->link = q;
			p = q;
			p->as = AMOVW;
			p->from.type = D_REG;
			p->from.reg = REGTMP;
			p->to.type = D_OREG;
			p->to.name = D_EXTERN;
			p->to.sym = s;
			p->to.offset = n*4 + 4;

			n += 2;
			continue;
		}
	}
	q = prg();
	q->line = 0;
	q->link = datap;
	datap = q;

	q->as = ADATA;
	q->from.type = D_OREG;
	q->from.name = D_EXTERN;
	q->from.sym = s;
	q->reg = 4;
	q->to.type = D_CONST;
	q->to.offset = n;

	s->type = SBSS;
	s->value = n*4;
}

void
doprof2(void)
{
	Sym *s2, *s4;
	Prog *p, *q, *ps2, *ps4;

	if(debug['v'])
		Bprint(&bso, "%5.2f profile 2\n", cputime());
	Bflush(&bso);

	s2 = lookup("_profin", 0);
	s4 = lookup("_profout", 0);
	if(s2->type != STEXT || s4->type != STEXT) {
		diag("_profin/_profout not defined");
		return;
	}

	ps2 = P;
	ps4 = P;
	for(p = firstp; p != P; p = p->link) {
		if(p->as == ATEXT) {
			if(p->from.sym == s2) {
				p->reg = 1;
				ps2 = p;
			}
			if(p->from.sym == s4) {
				p->reg = 1;
				ps4 = p;
			}
		}
	}
	for(p = firstp; p != P; p = p->link) {
		if(p->as == ATEXT) {
			curtext = p;

			if(p->reg & NOPROF) {	/* dont profile */
				for(;;) {
					q = p->link;
					if(q == P)
						break;
					if(q->as == ATEXT)
						break;
					p = q;
				}
				continue;
			}

			/*
			 * BL	profin
			 */
			q = prg();
			q->line = p->line;
			q->pc = p->pc;
			q->link = p->link;
			p->link = q;
			p = q;
			p->as = ABL;
			p->to.type = D_BRANCH;
			p->pcond = ps2;
			p->to.sym = s2;

			continue;
		}
		if(p->as == ARETURN) {

			/*
			 * RETURN
			 */
			q = prg();
			q->as = ARETURN;
			q->from = p->from;
			q->to = p->to;
			q->link = p->link;
			p->link = q;

			/*
			 * BL profout
			 */
			p->as = ABL;
			p->from = zprg.from;
			p->to = zprg.to;
			p->to.type = D_BRANCH;
			p->pcond = ps4;
			p->to.sym = s4;

			p = q;

			continue;
		}
	}
}
