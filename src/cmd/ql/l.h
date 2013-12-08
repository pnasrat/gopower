// Inferno utils/ql/l.h
// http://code.google.com/p/inferno-os/source/browse/utils/ql/l.h
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

#include <u.h>
#include <libc.h>
#include <bio.h>
#include "../ql/q.out.h"

#ifndef	EXTERN
#define	EXTERN	extern
#endif

#define SYMDATVA 0x99LL<<24

enum
{
	PtrSize = 8
};

#define	cput(c) { *cbp++ = c; if(--cbc <= 0) cflush(); }

typedef	struct	Adr	Adr;
typedef	struct	Sym	Sym;
typedef	struct	Auto	Auto;
typedef	struct	Prog	Prog;
typedef	struct	Optab	Optab;

#define	P		((Prog*)0)
#define	S		((Sym*)0)
#define	TNAME		(curtext&&curtext->from.sym?curtext->from.sym->name:noname)

struct	Adr
{
	union
	{
		int32	u0offset;
		char	u0sval[NSNAME];
		Ieee	u0ieee;
		char	*u0sbig;
	}u0;
	Sym	*sym;
	Auto	*autom;
	char	type;
	uchar	reg;
	char	name;
	char	class;
	char	index;
	char	scale;
};

#define	offset	u0.u0offset
#define	sval	u0.u0sval
#define	ieee	u0.u0ieee
#define sbing	u0.u0sbig

struct	Prog
{
	Adr	from;
	Adr	from3;	/* fma and rlwm */
	Adr	to;
	Prog	*forwd;
	Prog	*pcond;
	Prog	*link;
	Prog*	dlink;
	int32	pc;
	int32	regused;
	int32	line;
	short	mark;
	short	optab;		/* could be uchar */
	ushort	as;
	char	ft;	/* oclass cache */
	char	tt;
	char	reg;
};
struct	Sym
{
	char	*name;
	short	type;
	short	version;
	short	become;
	short	frame;
	uchar	subtype;
	uchar	dupok;
	uchar	reachable;
	uchar	dynexport;
	vlong	value;
	vlong	size;
	int32	sig;
	Sym*	link;
	Prog*	text;
	Prog*	data;
	Sym*	gotype;
	char*	file;
	char*	dynimpname;
	char*	dynimplib;
};
struct	Auto
{
	Sym	*asym;
	Auto	*link;
	int32	aoffset;
	short	type;
	Sym*	gotype;
};
struct	Optab
{
	ushort	as;
	uchar	a1;
	uchar	a2;
	uchar	a3;
	uchar	a4;
	uchar	type;
	uchar	size;
	uchar	param;
};
struct
{
	Optab*	start;
	Optab*	stop;
} oprange[ALAST];

enum
{
	FPCHIP		= 1,
	BIG		= 32768-8,
	STRINGSZ	= 200,
	MAXIO		= 8192,
	MAXHIST		= 20,				/* limit of path elements for history symbols */
	DATBLK		= 1024,
	//NHASH		= 10007,
	NHUNK		= 100000,
	MINSIZ		= 64,
	NENT		= 100,
	NSCHED		= 20,

/* mark flags */
	LABEL		= 1<<0,
	LEAF		= 1<<1,
	FLOAT		= 1<<2,
	BRANCH		= 1<<3,
	LOAD		= 1<<4,
	FCMP		= 1<<5,
	SYNC		= 1<<6,
	LIST		= 1<<7,
	FOLL		= 1<<8,
	NOSCHED		= 1<<9,

	/*STEXT		= 1,
	SDATA,
	SBSS,
	SDATA1,
	SXREF,
	SLEAF,
	SFILE,
	SCONST,
	SUNDEF,

	SIMPORT,
	SEXPORT,

	SMACHO,
	SFIXED,
	SELFDATA, */

	C_NONE		= 0,
	C_REG,
	C_FREG,
	C_CREG,
	C_SPR,		/* special processor register */
	C_SREG,		/* segment register (32 bit implementations only) */
	C_ZCON,
	C_SCON,		/* 16 bit signed */
	C_UCON,		/* low 16 bits 0 */
	C_ADDCON,	/* -0x8000 <= v < 0 */
	C_ANDCON,	/* 0 < v <= 0xFFFF */
	C_LCON,		/* other */
	C_SACON,
	C_SECON,
	C_LACON,
	C_LECON,
	C_SBRA,
	C_LBRA,
	C_SAUTO,
	C_LAUTO,
	C_SEXT,
	C_LEXT,
	C_ZOREG,
	C_SOREG,
	C_LOREG,
	C_FPSCR,
	C_MSR,
	C_XER,
	C_LR,
	C_CTR,
	C_ANY,
	C_GOK,
	C_ADDR,

	C_NCLASS,

	Roffset	= 22,		/* no. bits for offset in relocation address */
	Rindex	= 10,		/* no. bits for index in relocation address */
	Maxand	= 10		/* in -a output widht of the byte codes */
};

//EXTERN union
//{
//	struct
//	{
//		uchar	obuf[MAXIO];			/* output buffer */
//		uchar	ibuf[MAXIO];			/* input buffer */
//	} u;
//	char	dbuf[1];
//} buf;

#define	cbuf	u.obuf
#define	xbuf	u.ibuf

EXTERN	int32	HEADR;			/* length of header */
EXTERN	int32	HEADTYPE;		/* type of header */
EXTERN	int32	INITDAT;		/* data location */
EXTERN	int32	INITRND;		/* data round above text location */
EXTERN	int32	INITTEXT;		/* text location */
EXTERN	char*	INITENTRY;		/* entry point */
EXTERN	int32	autosize;
EXTERN	Biobuf	bso;
EXTERN	int32	bsssize;
EXTERN	int	cbc;
EXTERN	uchar*	cbp;
EXTERN	char*	pcstr;
EXTERN	Auto*	curauto;
EXTERN	Auto*	curhist;
EXTERN	Prog*	curp;
EXTERN	Prog*	curtext;
EXTERN	Prog*	datap;
EXTERN	Prog*	edatap;
EXTERN	Prog*	prog_movsw;
EXTERN	Prog*	prog_movdw;
EXTERN	Prog*	prog_movws;
EXTERN	Prog*	prog_movwd;
EXTERN	int32	datsize;
EXTERN	int32	elfdatsize;
EXTERN	char	debug[128];
EXTERN	Prog*	etextp;
EXTERN	Prog*	firstp;
EXTERN	int	xrefresolv;
EXTERN	Prog*	lastp;
EXTERN	int32	lcsize;
EXTERN	char	literal[32];
EXTERN	int	nerrors;
EXTERN	char*	noname;
EXTERN	int32	instoffset;
EXTERN	char*	outfile;
EXTERN	int32	pc;
EXTERN	int	r0iszero;
EXTERN	int32	symsize;
EXTERN	int32	staticgen;
EXTERN	Prog*	textp;
EXTERN	int32	textsize;
EXTERN	int32	tothunk;
EXTERN	char	xcmp[C_NCLASS][C_NCLASS];
EXTERN	int	version;
EXTERN	Prog	zprg;
EXTERN	int	dtype;
EXTERN	Sym*	adrgotype;		// type symbol on last Adr read
EXTERN	Sym*	fromgotype;		// type symbol on last p->from read
EXTERN	char*	rpath;
EXTERN	int32	spsize;

EXTERN	Adr*	reloca;
EXTERN	int	doexp;			// export table
EXTERN  int	dlm;			// dynamically loadable module
EXTERN	int	imports, nimports;
EXTERN	int	exports, nexports;
EXTERN	char*	EXPTAB;
EXTERN	Prog	undefp;
EXTERN	vlong	textstksiz;
EXTERN	vlong	textarg;
extern	char	thechar;
EXTERN	int	dynptrsize;
EXTERN	int	elfstrsize;
EXTERN	char*	elfstrdat;
EXTERN	int	elftextsh;

#define	UP	(&undefp)

extern	Optab	optab[];
extern	char*	anames[];
extern	char*	cnames[];

int	Aconv(Fmt*);
int	Dconv(Fmt*);
int	Nconv(Fmt*);
int	Pconv(Fmt*);
int	Sconv(Fmt*);
int	Rconv(Fmt*);
int	aclass(Adr*);
void	addhist(int32, int);
void	histtoauto(void);
void	addnop(Prog*);
void	append(Prog*, Prog*);
void	asmb(void);
void	asmdyn(void);
void	asmlc(void);
void	asmelfsym(void);
int	asmout(Prog*, Optab*, int);
void	asmsym(void);
int32	atolwhex(char*);
Prog*	brloop(Prog*);
void	buildop(void);
void	cflush(void);
void	ckoff(Sym*, int32);
int	cmp(int, int);
int	compound(Prog*);
double	cputime(void);
void	datblk(int32, int32);
void	diag(char*, ...);
void	dodata(void);
void	doelf(void);
void	doprof1(void);
void	doprof2(void);
void	dynreloc(Sym*, int32, int, int, int);
void	errorexit(void);
void	exchange(Prog*);
void	export(void);
vlong	entryvalue(void);
int	find1(int32, int);
void	follow(void);
void	gethunk(void);
double	ieeedtod(Ieee*);
int32	ieeedtof(Ieee*);
void	import(void);
int	isnop(Prog*);
void	loadlib(void);
void	listinit(void);
void	initmuldiv(void);
Sym*	lookup(char*, int);
void	lputb(int32);
void	mkfwd(void);
void*	mysbrk(uint32);
void	names(void);
Prog*	newdata(Sym*, int, int, int);
Prog*	newtext(Prog*, Sym*);
void	nocache(Prog*);
void	noops(void);
void	nuxiinit(void);
int	ocmp(const void*, const void*);
int32	opcode(int);
Optab*	oplook(Prog*);
void	patch(void);
void	prasm(Prog*);
void	prepend(Prog*, Prog*);
Prog*	prg(void);
int	pseudo(Prog*);
void	putsymb(char*, int, int32, int);
void	readundefs(char*, int);
int32	regoff(Adr*);
int	relinv(int);
int32	rnd(int32, int32);
void	sched(Prog*, Prog*);
void	span(void);
void	strnput(char*, int);
vlong	symaddr(Sym*);
void	undef(void);
void	undefsym(Sym*);
vlong	vaddr(Adr *a);
void	wputb(int32);
void vputb(uint64 v);
void	xdefine(char*, int, int32);
void	xfol(Prog*);
void	zerosig(char*);

vlong adduint32(Sym *s, uint32 v);
vlong adduint64(Sym *s, uint64 v);
vlong addaddr(Sym *s, Sym *t);
vlong addsize(Sym *s, Sym *t);

/* Native is big-endian */
#define	LPUT(a)	lputb(a)
#define	WPUT(a)	wputb(a)
#define	VPUT(a)	vputb(a)

#pragma	varargck	type	"D"	Adr*
#pragma	varargck	type	"N"	Adr*
#pragma	varargck	type	"P"	Prog*
#pragma	varargck	type	"R"	int
#pragma	varargck	type	"A"	int
#pragma	varargck	type	"S"	char*
