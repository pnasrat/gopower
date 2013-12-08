// Derived from Inferno utils/qc/list.c
// http://code.google.com/p/inferno-os/source/browse/utils/qc/list.c
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

#include "gg.h"

static int sconsize;

void
listinit(void)
{

	fmtinstall('A', Aconv);		// as
	fmtinstall('P', Pconv);		// Prog*
	fmtinstall('D', Dconv);		// Addr*
	fmtinstall('R', Rconv);		// reg
	fmtinstall('Y', Yconv);		// sconst
}

int
Pconv(Fmt *fp)
{
	char str[STRINGSZ];
	Prog *p;
	int a;

	p = va_arg(fp->args, Prog*);
	sconsize = 8;
	switch (p->as) {
	case ADATA:
		sconsize = p->from.scale;
		sprint(str, "	%A	%D/%d,%D", a, &p->from, p->reg, &p->to);
		break;
	case ATEXT:
		sprint(str, "	%A	%D,%d,%D", a, &p->from, p->reg, &p->to);
		break;
	default:
		if(p->reg == NREG)
		    sprint(str, "	%A	%D,%D", a, &p->from, &p->to);
		else if(p->from.type != D_FREG)
		    sprint(str, "	%A	%D,R%d,%D", a, &p->from, p->reg, &p->to);
		else
		    sprint(str, "	%A	%D,F%d,%D", a, &p->from, p->reg, &p->to);
		break;
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
	if(a >= AXXX && a <= AEND)
		s = anames[a];
	return fmtstrcpy(fp, s);
}

int
Dconv(Fmt *fp)
{
	char str[STRINGSZ];
	Addr *a;

	a = va_arg(fp->args, Addr*);
	switch(a->type) {

	default:
		sprint(str, "GOK-type(%d)", a->type);
		break;

	case D_NONE:
		str[0] = 0;
		if(a->name != D_NONE || a->reg != NREG || a->sym != S)
			sprint(str, "%N(R%d)(NONE)", a, a->reg);
		break;

	case D_CONST:
		if(a->reg != NREG)
			sprint(str, "$%N(R%d)", a, a->reg);
		else
			sprint(str, "$%N", a);
		break;

	case D_OREG:
		if(a->reg != NREG)
			sprint(str, "%N(R%d)", a, a->reg);
		else
			sprint(str, "%N", a);
		break;

	case D_REG:
		sprint(str, "R%d", a->reg);
		if(a->name != D_NONE || a->sym != S)
			sprint(str, "%N(R%d)(REG)", a, a->reg);
		break;

	case D_FREG:
		sprint(str, "F%d", a->reg);
		if(a->name != D_NONE || a->sym != S)
			sprint(str, "%N(F%d)(REG)", a, a->reg);
		break;

	case D_CREG:
		sprint(str, "C%d", a->reg);
		if(a->name != D_NONE || a->sym != S)
			sprint(str, "%N(C%d)(REG)", a, a->reg);
		break;

	case D_BRANCH:
		sprint(str, "%ld(PC)", a->offset-pc);
		break;

	case D_FCONST:
		sprint(str, "$%.17e", a->dval);
		break;

	case D_SCONST:
		sprint(str, "$\"%S\"", a->sval);
		break;
	}
	return fmtstrcpy(fp, str);
}

int
Yconv(Fmt *fp)
{
	int i, c;
	char str[STRINGSZ], *p, *a;

	a = va_arg(fp->args, char*);
	p = str;
	for(i=0; i < sconsize; i++) {
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
		case '\r':
			*p++ = 'r';
			continue;
		case '\f':
			*p++ = 'f';
			continue;
		}
		*p++ = (c>>6) + '0';
		*p++ = ((c>>3) & 7) + '0';
		*p++ = (c & 7) + '0';
	}
	*p = 0;
	return fmtstrcpy(fp, str);
}

int
Dconv(Fmt *fp)
{
	char str[STRINGSZ];
	Addr *a;
	Sym *s;

	a = va_arg(fp->args, Addr*);
	s = a->sym;
	if(s == S) {
		sprint(str, "%ld", a->offset);
		goto out;
	}
	switch(a->name) {
	default:
		sprint(str, "GOK-name(%d)", a->name);
		break;

	case D_EXTERN:
		sprint(str, "%s+%ld(SB)", s->name, a->offset);
		break;

	case D_STATIC:
		sprint(str, "%s<>+%ld(SB)", s->name, a->offset);
		break;

	case D_AUTO:
		sprint(str, "%s-%ld(SP)", s->name, -a->offset);
		break;

	case D_PARAM:
		sprint(str, "%s+%ld(FP)", s->name, a->offset);
		break;
	}
out:
	return fmtstrcpy(fp, str);
}
