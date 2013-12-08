// Inferno utils/ql/list.c
// http://code.google.com/p/inferno-os/source/browse/utils/ql/list.c
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

#include "l.h"

void
listinit(void)
{

	fmtinstall('A', Aconv);
	fmtinstall('D', Dconv);
	fmtinstall('P', Pconv);
	fmtinstall('S', Sconv);
	fmtinstall('N', Nconv);
	fmtinstall('R', Rconv);
}

void
prasm(Prog *p)
{
	print("%P\n", p);
}

int
Pconv(Fmt *fp)
{
	char str[STRINGSZ], *s;
	Prog *p;
	int a;

	p = va_arg(fp->args, Prog*);
	if (p == P)
		return fmtstrcpy(fp, "<P>");

	curp = p;
	a = p->as;
	if(a == ADATA || a == AINIT || a == ADYNT)
		snprint(str, sizeof(str), "(%d)	%A	%D/%d,%D", p->line, a, &p->from, p->reg, &p->to);
	else {
		int n, nstr;
		s = str;
		nstr = sizeof(str);
		if(p->mark & NOSCHED) {
			n = snprint(s, nstr, "*");
			s += n;
			nstr -= n;
		}
		if(p->reg == NREG && p->from3.type == D_NONE)
			snprint(s, nstr, "(%d)	%A	%D,%D", p->line, a, &p->from, &p->to);
		else
		if(a != ATEXT && p->from.type == D_OREG) {
			snprint(s, nstr, "(%d)	%A	%ld(R%d+R%d),%D", p->line, a,
				p->from.offset, p->from.reg, p->reg, &p->to);
		} else
		if(p->to.type == D_OREG) {
			snprint(s, nstr, "(%d)	%A	%D,%ld(R%d+R%d)", p->line, a,
					&p->from, p->to.offset, p->to.reg, p->reg);
		} else {
			n = snprint(s, nstr, "(%d)	%A	%D", p->line, a, &p->from);
			s += n;
			nstr -= n;
			if(p->reg != NREG) {
				n = snprint(s, nstr, ",%c%d", p->from.type==D_FREG?'F':'R', p->reg);
				s += n;
				nstr -= n;
			}
			if(p->from3.type != D_NONE) {
				n = snprint(s, nstr, ",%D", &p->from3);
				s += n;
				nstr -= n;
			}
			snprint(s, nstr, ",%D", &p->to);
		}
	}
	return fmtstrcpy(fp, str);
}

int
Aconv(Fmt *fp)
{
	char *s;
	int a;

	a = va_arg(fp->args, int);
	s = "???";
	if(a >= AXXX && a < ALAST)
		s = anames[a];
	return fmtstrcpy(fp, s);
}

int
Dconv(Fmt *fp)
{
	char str[STRINGSZ];
	Adr *a;
	long v;

	if (fp->flags & FmtLong) {
	    diag("Dconv FmtLong not implemnted");
	}

	a = va_arg(fp->args, Adr*);
	switch(a->type) {

	default:
		snprint(str, sizeof(str), "GOK-type(%d)", a->type);
		break;

	case D_NONE:
		str[0] = 0;
		if(a->name != D_NONE || a->reg != NREG || a->sym != S)
			snprint(str, sizeof(str), "%N(R%d)(NONE)", a, a->reg);
		break;

	case D_CONST:
		if(a->reg != NREG)
			snprint(str, sizeof(str), "$%N(R%d)", a, a->reg);
		else
			snprint(str, sizeof(str), "$%N", a);
		break;

	case D_OREG:
		if(a->reg != NREG)
			snprint(str, sizeof(str), "%N(R%d)", a, a->reg);
		else
			snprint(str, sizeof(str), "%N", a);
		break;

	case D_REG:
		snprint(str, sizeof(str), "R%d", a->reg);
		if(a->name != D_NONE || a->sym != S)
			snprint(str, sizeof(str), "%N(R%d)(REG)", a, a->reg);
		break;

	case D_FREG:
		snprint(str, sizeof(str), "F%d", a->reg);
		if(a->name != D_NONE || a->sym != S)
			snprint(str, sizeof(str), "%N(F%d)(REG)", a, a->reg);
		break;

	case D_CREG:
		if(a->reg == NREG)
			strcpy(str, "CR");
		else
			snprint(str, sizeof(str), "CR%d", a->reg);
		if(a->name != D_NONE || a->sym != S)
			snprint(str, sizeof(str), "%N(C%d)(REG)", a, a->reg);
		break;

	case D_SPR:
		if(a->name == D_NONE && a->sym == S) {
			switch(a->offset) {
			case D_XER: snprint(str, sizeof(str), "XER"); break;
			case D_LR: snprint(str, sizeof(str), "LR"); break;
			case D_CTR: snprint(str, sizeof(str), "CTR"); break;
			default: snprint(str, sizeof(str), "SPR(%ld)", a->offset); break;
			}
			break;
		}
		snprint(str, sizeof(str), "SPR-GOK(%d)", a->reg);
		if(a->name != D_NONE || a->sym != S)
			snprint(str, sizeof(str), "%N(SPR-GOK%d)(REG)", a, a->reg);
		break;

	case D_DCR:
		if(a->name == D_NONE && a->sym == S) {
			snprint(str, sizeof(str), "DCR(%ld)", a->offset);
			break;
		}
		snprint(str, sizeof(str), "DCR-GOK(%d)", a->reg);
		if(a->name != D_NONE || a->sym != S)
			snprint(str, sizeof(str), "%N(DCR-GOK%d)(REG)", a, a->reg);
		break;

	case D_OPT:
		snprint(str, sizeof(str), "OPT(%d)", a->reg);
		break;

	case D_FPSCR:
		if(a->reg == NREG)
			strcpy(str, "FPSCR");
		else
			snprint(str, sizeof(str), "FPSCR(%d)", a->reg);
		break;

	case D_MSR:
		snprint(str, sizeof(str), "MSR");
		break;

	case D_SREG:
		snprint(str, sizeof(str), "SREG(%d)", a->reg);
		if(a->name != D_NONE || a->sym != S)
			snprint(str, sizeof(str), "%N(SREG%d)(REG)", a, a->reg);
		break;

	case D_BRANCH:
		if(curp->pcond != P) {
			v = curp->pcond->pc;
			if(v >= INITTEXT)
				v -= INITTEXT-HEADR;
			if(a->sym != S)
				snprint(str, sizeof(str), "%s+%.5lux(BRANCH)", a->sym->name, v);
			else
				snprint(str, sizeof(str), "%.5lux(BRANCH)", v);
		} else
			if(a->sym != S)
				snprint(str, sizeof(str), "%s+%ld(APC)", a->sym->name, a->offset);
			else
				snprint(str, sizeof(str), "%ld(APC)", a->offset);
		break;

	case D_FCONST:
		snprint(str, sizeof(str), "$%lux-%lux", a->ieee.h, a->ieee.l);
		break;

	case D_SCONST:
		snprint(str, sizeof(str), "$\"%S\"", a->sval);
		break;
	}
	return fmtstrcpy(fp, str);
}

int
Nconv(Fmt *fp)
{
	char str[STRINGSZ];
	Adr *a;
	Sym *s;

	a = va_arg(fp->args, Adr*);
	s = a->sym;
	if(s == S) {
		snprint(str, sizeof(str), "%ld", a->offset);
		goto out;
	}
	switch(a->name) {
	default:
		snprint(str, sizeof(str), "GOK-name(%d)", a->name);
		break;

	case D_EXTERN:
		snprint(str, sizeof(str), "%s+%ld(SB)", s->name, a->offset);
		break;

	case D_STATIC:
		snprint(str, sizeof(str), "%s<>+%ld(SB)", s->name, a->offset);
		break;

	case D_AUTO:
		snprint(str, sizeof(str), "%s-%ld(SP)", s->name, -a->offset);
		break;

	case D_PARAM:
		snprint(str, sizeof(str), "%s+%ld(FP)", s->name, a->offset);
		break;
	}
out:
	return fmtstrcpy(fp, str);
}

int
Rconv(Fmt *fp)
{
	char *s;
	int a;

	a = va_arg(fp->args, int);
	s = "C_??";
	if(a >= C_NONE && a <= C_NCLASS)
		s = cnames[a];
	return fmtstrcpy(fp, s);
}

int
Sconv(Fmt *fp)
{
	int i, c;
	char str[STRINGSZ], *p, *a;

	a = va_arg(fp->args, char*);
	p = str;
	for(i=0; i<sizeof(long); i++) {
		c = a[i] & 0xff;
		if(c >= 'a' && c <= 'z' ||
		   c >= 'A' && c <= 'Z' ||
		   c >= '0' && c <= '9' ||
		   c == ' ' || c == '%') {
			*p++ = c;
			continue;
		}
		*p++ = '\\';
		switch(c) {
		case 0:
			*p++ = 'z';
			continue;
		case '\\':
		case '"':
			*p++ = c;
			continue;
		case '\n':
			*p++ = 'n';
			continue;
		case '\t':
			*p++ = 't';
			continue;
		}
		*p++ = (c>>6) + '0';
		*p++ = ((c>>3) & 7) + '0';
		*p++ = (c & 7) + '0';
	}
	*p = 0;
	return fmtstrcpy(fp, str);
}

void
diag(char *fmt, ...)
{
	char buf[STRINGSZ], *tn;
	va_list arg;

	tn = "??none??";
	if(curtext != P && curtext->from.sym != S)
		tn = curtext->from.sym->name;
	va_start(arg, fmt);
	vseprint(buf, buf+sizeof(buf), fmt, arg);
	va_end(arg);
	print("%s: %s\n", tn, buf);

	nerrors++;
	if(nerrors > 10) {
		print("too many errors\n");
		errorexit();
	}
}
