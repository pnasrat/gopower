// Inferno utils/ql/optab.c
// http://code.google.com/p/inferno-os/source/browse/utils/ql/optab.c
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

Optab	optab[] =
{
	{ ATEXT,	C_LEXT,	C_NONE, C_NONE, 	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_LEXT,	C_REG, C_NONE, 	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_LEXT,	C_NONE, C_LCON, 	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_LEXT,	C_REG, C_LCON, 	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_ADDR,	C_NONE, C_NONE, 	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_ADDR,	C_REG, C_NONE, 	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_ADDR,	C_NONE, C_LCON, 	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_ADDR,	C_REG, C_LCON, 	C_LCON, 	 0, 0, 0 },

	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_REG,		 1, 4, 0 },
	{ AMOVB,	C_REG,	C_NONE, C_NONE, 	C_REG,		12, 4, 0 },
	{ AMOVBZ,	C_REG,	C_NONE, C_NONE, 	C_REG,		13, 4, 0 },

	{ AADD,		C_REG,	C_REG, C_NONE, 	C_REG,		 2, 4, 0 },
	{ AADD,		C_REG,	C_NONE, C_NONE, 	C_REG,		 2, 4, 0 },
	{ AADD,		C_ADDCON,C_REG, C_NONE, 	C_REG,		 4, 4, 0 },
	{ AADD,		C_ADDCON,C_NONE, C_NONE, C_REG,		 4, 4, 0 },
	{ AADD,		C_UCON,	C_REG, C_NONE, 	C_REG,		20, 4, 0 },
	{ AADD,		C_UCON,	C_NONE, C_NONE, 	C_REG,		20, 4, 0 },
	{ AADD,		C_LCON,	C_REG, C_NONE, 	C_REG,		22, 12, 0 },
	{ AADD,		C_LCON,	C_NONE, C_NONE, 	C_REG,		22, 12, 0 },

	{ AADDC,	C_REG,	C_REG, C_NONE, 	C_REG,		 2, 4, 0 },
	{ AADDC,	C_REG,	C_NONE, C_NONE, 	C_REG,		 2, 4, 0 },
	{ AADDC,	C_ADDCON,C_REG, C_NONE, 	C_REG,		 4, 4, 0 },
	{ AADDC,	C_ADDCON,C_NONE, C_NONE, C_REG,		 4, 4, 0 },
	{ AADDC,	C_LCON,	C_REG, C_NONE, 	C_REG,		22, 12, 0 },
	{ AADDC,	C_LCON,	C_NONE, C_NONE, 	C_REG,		22, 12, 0 },

	{ AAND,		C_REG,	C_REG, C_NONE, 	C_REG,		6, 4, 0 },	/* logical, no literal */
	{ AAND,		C_REG,	C_NONE, C_NONE, 	C_REG,		6, 4, 0 },
	{ AANDCC,	C_REG,	C_REG, C_NONE, 	C_REG,		6, 4, 0 },
	{ AANDCC,	C_REG,	C_NONE, C_NONE, 	C_REG,		6, 4, 0 },

	{ AANDCC,	C_ANDCON,C_NONE, C_NONE, C_REG,		58, 4, 0 },
	{ AANDCC,	C_ANDCON,C_REG, C_NONE, 	C_REG,		58, 4, 0 },
	{ AANDCC,	C_UCON,	C_NONE, C_NONE, 	C_REG,		59, 4, 0 },
	{ AANDCC,	C_UCON,	C_REG, C_NONE, 	C_REG,		59, 4, 0 },
	{ AANDCC,	C_LCON,	C_NONE, C_NONE, 	C_REG,		23, 12, 0 },
	{ AANDCC,	C_LCON,	C_REG, C_NONE, 	C_REG,		23, 12, 0 },

	{ AMULLW,	C_REG,	C_REG, C_NONE, 	C_REG,		 2, 4, 0 },
	{ AMULLW,	C_REG,	C_NONE, C_NONE, 	C_REG,		 2, 4, 0 },
	{ AMULLW,	C_ADDCON,C_REG, C_NONE, 	C_REG,		 4, 4, 0 },
	{ AMULLW,	C_ADDCON,C_NONE, C_NONE, C_REG,		 4, 4, 0 },
	{ AMULLW,	C_ANDCON,C_REG, C_NONE, 	C_REG,		 4, 4, 0 },
	{ AMULLW,	C_ANDCON,	C_NONE, C_NONE,	C_REG,	 4, 4, 0 },
	{ AMULLW,	C_LCON,	C_REG,	C_NONE,	C_REG,		22, 12, 0},
	{ AMULLW,	C_LCON,	C_NONE,	C_NONE,	C_REG,		22, 12, 0},

	{ ASUBC,	C_REG,	C_REG, C_NONE, 	C_REG,		 10, 4, 0 },
	{ ASUBC,	C_REG,	C_NONE, C_NONE, 	C_REG,		 10, 4, 0 },
	{ ASUBC,	C_REG,	C_NONE, C_ADDCON, 	C_REG,	 27, 4, 0 },
	{ ASUBC,	C_REG,	C_NONE,	C_LCON,	C_REG,		28, 12, 0},

	{ AOR,		C_REG,	C_REG, C_NONE, 	C_REG,		6, 4, 0 },	/* logical, literal not cc (or/xor) */
	{ AOR,		C_REG,	C_NONE, C_NONE, 	C_REG,		6, 4, 0 },
	{ AOR,		C_ANDCON, C_NONE, C_NONE,  C_REG,	58, 4, 0 },
	{ AOR,		C_ANDCON, C_REG, C_NONE,  C_REG,		58, 4, 0 },
	{ AOR,		C_UCON, C_NONE, C_NONE,  C_REG,		59, 4, 0 },
	{ AOR,		C_UCON, C_REG, C_NONE,  C_REG,		59, 4, 0 },
	{ AOR,		C_LCON,	C_NONE, C_NONE, 	C_REG,		23, 12, 0 },
	{ AOR,		C_LCON,	C_REG, C_NONE, 	C_REG,		23, 12, 0 },

	{ ADIVW,	C_REG,	C_REG, C_NONE, 	C_REG,		 2, 4, 0 },	/* op r1[,r2],r3 */
	{ ADIVW,	C_REG,	C_NONE, C_NONE, 	C_REG,		 2, 4, 0 },
	{ ASUB,	C_REG,	C_REG, C_NONE, 	C_REG,		 10, 4, 0 },	/* op r2[,r1],r3 */
	{ ASUB,	C_REG,	C_NONE, C_NONE, 	C_REG,		 10, 4, 0 },

	{ ASLW,	C_REG,	C_NONE, C_NONE, 	C_REG,		 6, 4, 0 },
	{ ASLW,	C_REG,	C_REG, C_NONE, 	C_REG,		 6, 4, 0 },
	{ ASLW,	C_SCON,	C_REG, C_NONE, 	C_REG,		57, 4, 0 },
	{ ASLW,	C_SCON,	C_NONE, C_NONE, 	C_REG,		57, 4, 0 },

	{ ASRAW,	C_REG,	C_NONE, C_NONE, 	C_REG,		 6, 4, 0 },
	{ ASRAW,	C_REG,	C_REG, C_NONE, 	C_REG,		 6, 4, 0 },
	{ ASRAW,	C_SCON,	C_REG, C_NONE, 	C_REG,		56, 4, 0 },
	{ ASRAW,	C_SCON,	C_NONE, C_NONE, 	C_REG,		56, 4, 0 },

	{ ARLWMI,	C_SCON, C_REG, C_LCON, 	C_REG,		62, 4, 0 },
	{ ARLWMI,	C_REG,	C_REG, C_LCON, 	C_REG,		63, 4, 0 },

	{ AFADD,	C_FREG,	C_NONE, C_NONE, 	C_FREG,		 2, 4, 0 },
	{ AFADD,	C_FREG,	C_REG, C_NONE, 	C_FREG,		 2, 4, 0 },
	{ AFABS,	C_FREG,	C_NONE, C_NONE, 	C_FREG,		33, 4, 0 },
	{ AFABS,	C_NONE,	C_NONE, C_NONE, 	C_FREG,		33, 4, 0 },
	{ AFMOVD,	C_FREG,	C_NONE, C_NONE, 	C_FREG,		33, 4, 0 },

	{ AFMADD,	C_FREG,	C_REG, C_FREG, 	C_FREG,		 34, 4, 0 },
	{ AFMUL,	C_FREG,	C_NONE, C_NONE, 	C_FREG,		 32, 4, 0 },
	{ AFMUL,	C_FREG,	C_REG, C_NONE, 	C_FREG,		 32, 4, 0 },

	{ AMOVW,	C_REG,	C_REG, C_NONE, 	C_ZOREG,	 7, 4, REGZERO },
	{ AMOVBZ,	C_REG,	C_REG, C_NONE, 	C_ZOREG,	 7, 4, REGZERO },
	{ AMOVBZU,	C_REG,	C_REG, C_NONE, 	C_ZOREG,	 7, 4, REGZERO },
	{ AMOVB,	C_REG,	C_REG, C_NONE, 	C_ZOREG,	 7, 4, REGZERO },
	{ AMOVBU,	C_REG,	C_REG, C_NONE, 	C_ZOREG,	 7, 4, REGZERO },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_SEXT,		 7, 4, REGSB },
	{ AMOVBZ,	C_REG,	C_NONE, C_NONE, 	C_SEXT,		 7, 4, REGSB },
	{ AMOVB,	C_REG,	C_NONE, C_NONE, 	C_SEXT,		 7, 4, REGSB },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_SAUTO,	 7, 4, REGSP },
	{ AMOVBZ,	C_REG,	C_NONE, C_NONE, 	C_SAUTO,	 7, 4, REGSP },
	{ AMOVB,	C_REG,	C_NONE, C_NONE, 	C_SAUTO,	 7, 4, REGSP },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_SOREG,	 7, 4, REGZERO },
	{ AMOVBZ,	C_REG,	C_NONE, C_NONE, 	C_SOREG,	 7, 4, REGZERO },
	{ AMOVBZU,	C_REG,	C_NONE, C_NONE, 	C_SOREG,	 7, 4, REGZERO },
	{ AMOVB,	C_REG,	C_NONE, C_NONE, 	C_SOREG,	 7, 4, REGZERO },
	{ AMOVBU,	C_REG,	C_NONE, C_NONE, 	C_SOREG,	 7, 4, REGZERO },

	{ AMOVW,	C_ZOREG,C_REG, C_NONE, 	C_REG,		 8, 4, REGZERO },
	{ AMOVBZ,	C_ZOREG,C_REG, C_NONE, 	C_REG,		 8, 4, REGZERO },
	{ AMOVBZU,	C_ZOREG,C_REG, C_NONE, 	C_REG,		 8, 4, REGZERO },
	{ AMOVB,	C_ZOREG,C_REG, C_NONE, 	C_REG,		9, 8, REGZERO },
	{ AMOVBU,	C_ZOREG,C_REG, C_NONE, 	C_REG,		9, 8, REGZERO },
	{ AMOVW,	C_SEXT,	C_NONE, C_NONE, 	C_REG,		 8, 4, REGSB },
	{ AMOVBZ,	C_SEXT,	C_NONE, C_NONE, 	C_REG,		 8, 4, REGSB },
	{ AMOVB,	C_SEXT,	C_NONE, C_NONE, 	C_REG,		9, 8, REGSB },
	{ AMOVW,	C_SAUTO,C_NONE, C_NONE, 	C_REG,		 8, 4, REGSP },
	{ AMOVBZ,	C_SAUTO,C_NONE, C_NONE, 	C_REG,		 8, 4, REGSP },
	{ AMOVB,	C_SAUTO,C_NONE, C_NONE, 	C_REG,		9, 8, REGSP },
	{ AMOVW,	C_SOREG,C_NONE, C_NONE, 	C_REG,		 8, 4, REGZERO },
	{ AMOVBZ,	C_SOREG,C_NONE, C_NONE, 	C_REG,		 8, 4, REGZERO },
	{ AMOVBZU,	C_SOREG,C_NONE, C_NONE, 	C_REG,		 8, 4, REGZERO },
	{ AMOVB,	C_SOREG,C_NONE, C_NONE, 	C_REG,		9, 8, REGZERO },
	{ AMOVBU,	C_SOREG,C_NONE, C_NONE, 	C_REG,		9, 8, REGZERO },

	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_LEXT,		35, 8, REGSB },
	{ AMOVBZ,	C_REG,	C_NONE, C_NONE, 	C_LEXT,		35, 8, REGSB },
	{ AMOVB,	C_REG,	C_NONE, C_NONE, 	C_LEXT,		35, 8, REGSB },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_LAUTO,	35, 8, REGSP },
	{ AMOVBZ,	C_REG,	C_NONE, C_NONE, 	C_LAUTO,	35, 8, REGSP },
	{ AMOVB,	C_REG,	C_NONE, C_NONE, 	C_LAUTO,	35, 8, REGSP },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_LOREG,	35, 8, REGZERO },
	{ AMOVBZ,	C_REG,	C_NONE, C_NONE, 	C_LOREG,	35, 8, REGZERO },
	{ AMOVB,	C_REG,	C_NONE, C_NONE, 	C_LOREG,	35, 8, REGZERO },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_ADDR,		74, 8, 0 },
	{ AMOVBZ,	C_REG,	C_NONE, C_NONE, 	C_ADDR,		74, 8, 0 },
	{ AMOVB,	C_REG,	C_NONE, C_NONE, 	C_ADDR,		74, 8, 0 },

	{ AMOVW,	C_LEXT,	C_NONE, C_NONE, 	C_REG,		36, 8, REGSB },
	{ AMOVBZ,	C_LEXT,	C_NONE, C_NONE, 	C_REG,		36, 8, REGSB },
	{ AMOVB,	C_LEXT,	C_NONE, C_NONE, 	C_REG,		37, 12, REGSB },
	{ AMOVW,	C_LAUTO,C_NONE, C_NONE, 	C_REG,		36, 8, REGSP },
	{ AMOVBZ,	C_LAUTO,C_NONE, C_NONE, 	C_REG,		36, 8, REGSP },
	{ AMOVB,	C_LAUTO,C_NONE, C_NONE, 	C_REG,		37, 12, REGSP },
	{ AMOVW,	C_LOREG,C_NONE, C_NONE, 	C_REG,		36, 8, REGZERO },
	{ AMOVBZ,	C_LOREG,C_NONE, C_NONE, 	C_REG,		36, 8, REGZERO },
	{ AMOVB,	C_LOREG,C_NONE, C_NONE, 	C_REG,		37, 12, REGZERO },
	{ AMOVW,	C_ADDR,	C_NONE, C_NONE, 	C_REG,		75, 8, 0 },
	{ AMOVBZ,	C_ADDR,	C_NONE, C_NONE, 	C_REG,		75, 8, 0 },
	{ AMOVB,	C_ADDR,	C_NONE, C_NONE, 	C_REG,		76, 12, 0 },

	{ AMOVW,	C_SECON,C_NONE, C_NONE, 	C_REG,		 3, 4, REGSB },
	{ AMOVW,	C_SACON,C_NONE, C_NONE, 	C_REG,		 3, 4, REGSP },
	{ AMOVW,	C_LECON,C_NONE, C_NONE, 	C_REG,		26, 8, REGSB }, 
	{ AMOVW,	C_LACON,C_NONE, C_NONE, 	C_REG,		26, 8, REGSP },
	{ AMOVW,	C_ADDCON,C_NONE, C_NONE, C_REG,		 3, 4, REGZERO },

	{ AMOVW,	C_UCON, C_NONE, C_NONE,  C_REG,		3, 4, REGZERO },
	{ AMOVW,	C_LCON,	C_NONE, C_NONE, 	C_REG,		19, 8, 0 },

	{ AMOVHBR,	C_ZOREG,	C_REG, C_NONE, C_REG,		45, 4, 0 },
	{ AMOVHBR,	C_ZOREG, C_NONE, C_NONE, C_REG,	45, 4, 0 },
	{ AMOVHBR,	C_REG,	C_REG, C_NONE,	C_ZOREG,		44, 4, 0 },
	{ AMOVHBR,	C_REG,	C_NONE, C_NONE,	C_ZOREG,		44, 4, 0 },

	{ ASYSCALL,	C_NONE,	C_NONE, C_NONE, 	C_NONE,		 5, 4, 0 },

	{ ABEQ,		C_NONE,	C_NONE, C_NONE, 	C_SBRA,		16, 4, 0 },
	{ ABEQ,		C_CREG,	C_NONE, C_NONE, 	C_SBRA,		16, 4, 0 },

	{ ABR,		C_NONE,	C_NONE, C_NONE, 	C_LBRA,		11, 4, 0 },

	{ ABC,		C_SCON,	C_REG, C_NONE, 	C_SBRA,		16, 4, 0 },
	{ ABC,		C_SCON, C_REG, C_NONE, 	C_LBRA,		17, 4, 0 },

	{ ABR,		C_NONE,	C_NONE, C_NONE, 	C_LR,		18, 4, 0 },
	{ ABR,		C_NONE,	C_NONE, C_NONE, 	C_CTR,		18, 4, 0 },
	{ ABR,		C_NONE,	C_NONE, C_NONE, 	C_ZOREG,		15, 8, 0 },

	{ ABC,		C_NONE,	C_REG, C_NONE, 	C_LR,		18, 4, 0 },
	{ ABC,		C_NONE,	C_REG, C_NONE, 	C_CTR,		18, 4, 0 },
	{ ABC,		C_SCON,	C_REG, C_NONE, 	C_LR,		18, 4, 0 },
	{ ABC,		C_SCON,	C_REG, C_NONE, 	C_CTR,		18, 4, 0 },
	{ ABC,		C_NONE,	C_NONE, C_NONE, 	C_ZOREG,		15, 8, 0 },

	{ AFMOVD,	C_SEXT,	C_NONE, C_NONE, 	C_FREG,		8, 4, REGSB },
	{ AFMOVD,	C_SAUTO,C_NONE, C_NONE, 	C_FREG,		8, 4, REGSP },
	{ AFMOVD,	C_SOREG,C_NONE, C_NONE, 	C_FREG,		8, 4, REGZERO },

	{ AFMOVD,	C_LEXT,	C_NONE, C_NONE, 	C_FREG,		8, 4, REGSB },
	{ AFMOVD,	C_LAUTO,C_NONE, C_NONE, 	C_FREG,		8, 4, REGSP },
	{ AFMOVD,	C_LOREG,C_NONE, C_NONE, 	C_FREG,		8, 4, REGZERO },
	{ AFMOVD,	C_ADDR,	C_NONE, C_NONE, 	C_FREG,		75, 8, 0 },

	{ AFMOVD,	C_FREG,	C_NONE, C_NONE, 	C_SEXT,		7, 4, REGSB },
	{ AFMOVD,	C_FREG,	C_NONE, C_NONE, 	C_SAUTO,	7, 4, REGSP },
	{ AFMOVD,	C_FREG,	C_NONE, C_NONE, 	C_SOREG,	7, 4, REGZERO },

	{ AFMOVD,	C_FREG,	C_NONE, C_NONE, 	C_LEXT,		7, 4, REGSB },
	{ AFMOVD,	C_FREG,	C_NONE, C_NONE, 	C_LAUTO,	7, 4, REGSP },
	{ AFMOVD,	C_FREG,	C_NONE, C_NONE, 	C_LOREG,	7, 4, REGZERO },
	{ AFMOVD,	C_FREG,	C_NONE, C_NONE, 	C_ADDR,		74, 8, 0 },

	{ ASYNC,		C_NONE,	C_NONE, C_NONE, 	C_NONE,		46, 4, 0 },
	{ AWORD,	C_LCON,	C_NONE, C_NONE, 	C_NONE,		40, 4, 0 },

	{ AADDME,	C_REG,	C_NONE, C_NONE, 	C_REG,		47, 4, 0 },

	{ AEXTSB,	C_REG,	C_NONE, C_NONE, 	C_REG,		48, 4, 0 },
	{ AEXTSB,	C_NONE,	C_NONE, C_NONE, 	C_REG,		48, 4, 0 },

	{ ANEG,		C_REG,	C_NONE, C_NONE, 	C_REG,		47, 4, 0 },
	{ ANEG,		C_NONE,	C_NONE, C_NONE, 	C_REG,		47, 4, 0 },

	{ AREM,		C_REG,	C_NONE, C_NONE, 	C_REG,		51, 12, 0 },
	{ AREM,		C_REG,	C_REG, C_NONE, 	C_REG,		51, 12, 0 },

	{ AMTFSB0,	C_SCON,	C_NONE, C_NONE, 	C_NONE,		52, 4, 0 },
	{ AMOVFL, C_FPSCR, C_NONE, C_NONE,	C_FREG,		53, 4, 0 },
	{ AMOVFL, C_FREG, C_NONE, C_NONE,	C_FPSCR,		64, 4, 0 },
	{ AMOVFL, C_FREG, C_NONE, C_LCON,	C_FPSCR,		64, 4, 0 },
	{ AMOVFL,	C_LCON, C_NONE, C_NONE,	C_FPSCR,		65, 4, 0 },

	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_MSR,		54, 4, 0 },
	{ AMOVW,	C_MSR,	C_NONE, C_NONE, 	C_REG,		54, 4, 0 },

	{ AMOVW,	C_SREG,	C_NONE, C_NONE, 	C_REG,		55, 4, 0 },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_SREG,		55, 4, 0 },
	{ AMOVW,	C_SREG, C_REG, C_NONE, 	C_REG,		55, 4, 0 },	/* MOVW SR(Rn), Rm and v.v.*/
	{ AMOVW,	C_REG,	C_REG, C_NONE, 	C_SREG,		55, 4, 0 },

	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_SPR,		66, 4, 0 },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_LR,		66, 4, 0 },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_CTR,		66, 4, 0 },
	{ AMOVW,	C_REG,	C_NONE, C_NONE, 	C_XER,		66, 4, 0 },
	{ AMOVW,	C_SPR,	C_NONE, C_NONE, 	C_REG,		66, 4, 0 },
	{ AMOVW,	C_LR,	C_NONE, C_NONE, 	C_REG,		66, 4, 0 },
	{ AMOVW,	C_CTR,	C_NONE, C_NONE, 	C_REG,		66, 4, 0 },
	{ AMOVW,	C_XER,	C_NONE, C_NONE, 	C_REG,		66, 4, 0 },

	{ AMOVFL,	C_FPSCR, C_NONE, C_NONE, 	C_CREG,		73, 4, 0 },
	{ AMOVFL,	C_CREG,	C_NONE, C_NONE, 	C_CREG,		67, 4, 0 },
	{ AMOVW,	C_XER,	C_NONE, C_NONE, 	C_CREG,		72, 4, 0 },
	{ AMOVW,	C_CREG,	C_NONE,	C_NONE,		C_REG,		68, 4, 0 },
	{ AMOVFL,	C_REG, C_NONE, C_LCON, C_CREG,		69, 4, 0 },
	{ AMOVFL,	C_REG, C_NONE, C_NONE, C_CREG,		69, 4, 0 },
	{ AMOVW,	C_REG, C_NONE, C_NONE, C_CREG,		69, 4, 0 },

	{ ACMP,	C_REG,	C_NONE, C_NONE, 	C_REG,	70, 4, 0 },
	{ ACMP,	C_REG,	C_REG, C_NONE, 	C_REG,	70, 4, 0 },
	{ ACMP,	C_REG,	C_NONE, C_NONE,	C_ADDCON,	71, 4, 0 },
	{ ACMP,	C_REG,	C_REG, C_NONE,	C_ADDCON,	71, 4, 0 },

	{ ACMPU,	C_REG,	C_NONE, C_NONE, 	C_REG,	70, 4, 0 },
	{ ACMPU,	C_REG,	C_REG, C_NONE, 	C_REG,	70, 4, 0 },
	{ ACMPU,	C_REG,	C_NONE, C_NONE,	C_ANDCON,	71, 4, 0 },
	{ ACMPU,	C_REG,	C_REG, C_NONE,	C_ANDCON,	71, 4, 0 },

	{ AFCMPO,	C_FREG,	C_NONE, C_NONE, 	C_FREG,	70, 4, 0 },
	{ AFCMPO,	C_FREG,	C_REG, C_NONE, 	C_FREG,	70, 4, 0 },

	{ ATW,		C_LCON,	C_REG, C_NONE, 	C_REG,		60, 4, 0 },
	{ ATW,		C_LCON,	C_REG, C_NONE, 	C_ADDCON,	61, 4, 0 },

	{ ADCBF,	C_ZOREG, C_NONE, C_NONE,  C_NONE,	43, 4, 0 },
	{ ADCBF,	C_ZOREG, C_REG, C_NONE,  C_NONE,	43, 4, 0 },

	{ AECOWX,	C_REG,	C_REG, C_NONE, 	C_ZOREG,	44, 4, 0 },
	{ AECIWX,	C_ZOREG, C_REG, C_NONE,  C_REG,		45, 4, 0 },
	{ AECOWX,	C_REG,	C_NONE, C_NONE, 	C_ZOREG,	44, 4, 0 },
	{ AECIWX,	C_ZOREG, C_NONE, C_NONE,  C_REG,		45, 4, 0 },

	{ AEIEIO,	C_NONE,	C_NONE, C_NONE, 	C_NONE,		46, 4, 0 },
	{ ATLBIE,	C_REG, C_NONE, C_NONE,		C_NONE,		49, 4, 0 },

	{ ASTSW,	C_REG,	C_NONE, C_NONE, 	C_ZOREG,	44, 4, 0 },
	{ ASTSW,	C_REG,	C_NONE, C_LCON, 	C_ZOREG,	41, 4, 0 },
	{ ALSW,	C_ZOREG, C_NONE, C_NONE,  C_REG,		45, 4, 0 },
	{ ALSW,	C_ZOREG, C_NONE, C_LCON,  C_REG,		42, 4, 0 },

	{ AMACCHW,	C_REG,	C_REG, C_NONE, 	C_REG,		 2, 4, 0 },	/* op rb,ra,rt */

	{ AXXX,		C_NONE,	C_NONE, C_NONE, 	C_NONE,		 0, 4, 0 },
};
