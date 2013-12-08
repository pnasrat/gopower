// Derived from Inferno utils/qc/gc.h
// http://code.google.com/p/inferno-os/source/browse/utils/qc/gc.h
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

/*
 * qc/power
 * powerpc
 */
#define	SZ_CHAR		1
#define	SZ_SHORT	2
#define	SZ_INT		4
#define	SZ_LONG		4
#define	SZ_IND		4
#define	SZ_FLOAT	4
#define	SZ_VLONG	8
#define	SZ_DOUBLE	8
#define	FNX		100

typedef	struct	Case	Case;
typedef	struct	C1	C1;
typedef	struct	Multab	Multab;
typedef	struct	Hintab	Hintab;
typedef	struct	Reg	Reg;
typedef	struct	Rgn	Rgn;

#ifdef notdef
struct	Adr
{
	long	offset;
	double dval;
	char	sval[NSNAME];

	Sym*	sym;
	char	type;
	char	reg;
	char	name;
	char	etype;
};
#define	A	((Adr*)0)

#define	INDEXED	9
struct	Prog
{
	Adr	from;
	Adr	from3;		/* third argument for fmadd, fmsub, ... */
	Adr	to;
	Prog*	link;
	long	lineno;
	short	as;
	char	reg;
};
#define	P	((Prog*)0)
#endif

struct	Case
{
	Case*	link;
	long	val;
	long	label;
	char	def;
};
#define	C	((Case*)0)

struct	C1
{
	long	val;
	long	label;
};

struct	Multab
{
	long	val;
	char	code[20];
};

struct	Hintab
{
	ushort	val;
	char	hint[10];
};

struct	Reg
{
	long	pc;
	long	rpo;		/* reverse post ordering */

	Bits	set;
	Bits	use1;
	Bits	use2;

	Bits	refbehind;
	Bits	refahead;
	Bits	calbehind;
	Bits	calahead;
	Bits	regdiff;
	Bits	act;

	long	regu;
	long	loop;		/* could be shorter */

	Reg*	log5;
	int	active;

	Reg*	p1;
	Reg*	p2;
	Reg*	p2link;
	Reg*	s1;
	Reg*	s2;
	Reg*	link;
	Prog*	prog;
};
#define	R	((Reg*)0)

#define	NRGN	600
struct	Rgn
{
	Reg*	enter;
	short	cost;
	short	varno;
	short	regno;
};

EXTERN	Case*	cases;
EXTERN	Node	constnode;
EXTERN	Node	fconstnode;
EXTERN	long	curarg;
EXTERN	long	cursafe;
EXTERN	Prog*	firstp;
EXTERN	Prog*	lastp;
EXTERN	int	hintabsize;
EXTERN	long	maxargsafe;
EXTERN	Multab	multab[20];
EXTERN	int	mnstring;
EXTERN	int	retok;
EXTERN	Node*	nodrat;
EXTERN	Node*	nodret;
EXTERN	Node*	nodsafe;
EXTERN	long	nrathole;
EXTERN	long	nstring;
EXTERN	Prog*	p;
EXTERN	Node	regnode;
EXTERN	char	string[NSNAME];
EXTERN	Sym*	symrathole;
EXTERN	Node	znode;
EXTERN	Prog	zprog;
EXTERN	long	exregoffset;
EXTERN	long	exfregoffset;

#define	BLOAD(r)	band(bnot(r->refbehind), r->refahead)
#define	BSTORE(r)	band(bnot(r->calbehind), r->calahead)
#define	LOAD(r)		(~r->refbehind.b[z] & r->refahead.b[z])
#define	STORE(r)	(~r->calbehind.b[z] & r->calahead.b[z])

#define	bset(a,n)	((a).b[(n)/32]&(1L<<(n)%32))

#define	CLOAD	5
#define	CREF	5
#define	CINF	1000
#define	LOOP	3

EXTERN	Rgn	region[NRGN];
EXTERN	Rgn*	rgp;
EXTERN	int	nregion;
EXTERN	int	nvar;

EXTERN	Bits	externs;
EXTERN	Bits	params;
EXTERN	Bits	consts;
EXTERN	Bits	addrs;

EXTERN	long	regbits;
EXTERN	long	exregbits;

EXTERN	int	change;
EXTERN	int	suppress;

EXTERN	Reg*	firstr;
EXTERN	Reg*	lastr;
EXTERN	Reg	zreg;
EXTERN	Reg*	freer;
EXTERN	Var	var[NVAR];
EXTERN	long*	idom;
EXTERN	Reg**	rpo2r;
EXTERN	long	maxnr;

#define	R0ISZERO	(debug['0']==0)

extern	char*	anames[];
extern	Hintab	hintab[];

/*
 * sgen.c
 */
void	codgen(Node*, Node*);
void	gen(Node*);
void	usedset(Node*, int);
void	noretval(int);
void	xcom(Node*);
int	bcomplex(Node*, Node*);

/*
 * cgen.c
 */
void	cgen(Node*, Node*);
void	reglcgen(Node*, Node*, Node*);
void	lcgen(Node*, Node*);
void	bcgen(Node*, int);
void	boolgen(Node*, int, Node*);
void	sugen(Node*, Node*, long);
void	layout(Node*, Node*, int, int, Node*);

/*
 * txt.c
 */
void	ginit(void);
void	gclean(void);
void	nextpc(void);
void	gargs(Node*, Node*, Node*);
void	garg1(Node*, Node*, Node*, int, Node**);
Node*	nod32const(vlong);
void	regret(Node*, Node*);
void	regfree(Node*);
void	regialloc(Node*, Node*, Node*);
void	regsalloc(Node*, Node*);
void	regaalloc1(Node*, Node*);
void	regaalloc(Node*, Node*);
void	regind(Node*, Node*);
void	gprep(Node*, Node*);
void	raddr(Node*, Prog*);
void	gmove(Node*, Node*);
void	gopcode(int, Node*, Node*, Node*);
int	samaddr(Node*, Node*);
int	sconst(Node*);
int	sval(long);
int	uconst(Node*);
void	gpseudo(int, Sym*, Node*);

/*
 * swt.c
 */
void	doswit(Node*);
void	swit1(C1*, int, long, Node*, Node*);
void	cas(void);
void	bitload(Node*, Node*, Node*, Node*, Node*);
void	bitstore(Node*, Node*, Node*, Node*, Node*);
int	mulcon(Node*, Node*);
Multab*	mulcon0(Node*, long);
int	mulcon1(Node*, long, Node*);
void	nullwarn(Node*, Node*);
void	outcode(void);

/*
 * list
 */
void	listinit(void);
int	Pconv(Fmt*);
int	Aconv(Fmt*);
int	Dconv(Fmt*);
int	Sconv(Fmt*);
int	Nconv(Fmt*);
int	Bconv(Fmt*);

/*
 * reg.c
 */
Reg*	rega(void);
void	regopt(Prog*);
void	addmove(Reg*, int, int, int);
Bits	mkvar(Addr*, int);
void	prop(Reg*, Bits, Bits);
void	loopit(Reg*, long);
void	synch(Reg*, Bits);
ulong	allreg(ulong, Rgn*);
void	paint1(Reg*, int);
ulong	paint2(Reg*, int);
void	paint3(Reg*, int, long, int);
void	addreg(Addr*, int);

/*
 * peep.c
 */
void	peep(void);
void	excise(Reg*);
Reg*	uniqp(Reg*);
Reg*	uniqs(Reg*);
int	regtyp(Addr*);
int	regzer(Addr*);
int	anyvar(Addr*);
int	subprop(Reg*);
int	copyprop(Reg*);
int	copy1(Addr*, Addr*, Reg*, int);
int	copyu(Prog*, Addr*, Addr*);

int	copyas(Addr*, Addr*);
int	copyau(Addr*, Addr*);
int	copyau1(Prog*, Addr*);
int	copysub(Addr*, Addr*, Addr*, int);
int	copysub1(Prog*, Addr*, Addr*, int);

long	RtoB(int);
long	FtoB(int);
int	BtoR(long);
int	BtoF(long);

/*
 * com64.c
 */
int	com64(Node*);
void	com64init(void);
void	bool64(Node*);

#pragma	varargck	type	"A"	int
#pragma	varargck	type	"B"	Bits
#pragma	varargck	type	"D"	Addr*
#pragma	varargck	type	"N"	Addr*
#pragma	varargck	type	"P"	Prog*
#pragma	varargck	type	"S"	char*
