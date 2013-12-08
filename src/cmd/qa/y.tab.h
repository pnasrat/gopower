/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LMOVW = 258,
     LMOVB = 259,
     LABS = 260,
     LLOGW = 261,
     LSHW = 262,
     LADDW = 263,
     LCMP = 264,
     LCROP = 265,
     LBRA = 266,
     LFMOV = 267,
     LFCONV = 268,
     LFCMP = 269,
     LFADD = 270,
     LFMA = 271,
     LTRAP = 272,
     LXORW = 273,
     LNOP = 274,
     LEND = 275,
     LRETT = 276,
     LWORD = 277,
     LTEXT = 278,
     LDATA = 279,
     LRETRN = 280,
     LCONST = 281,
     LSP = 282,
     LSB = 283,
     LFP = 284,
     LPC = 285,
     LCREG = 286,
     LFLUSH = 287,
     LREG = 288,
     LFREG = 289,
     LR = 290,
     LCR = 291,
     LF = 292,
     LFPSCR = 293,
     LLR = 294,
     LCTR = 295,
     LSPR = 296,
     LSPREG = 297,
     LSEG = 298,
     LMSR = 299,
     LSCHED = 300,
     LXLD = 301,
     LXST = 302,
     LXOP = 303,
     LXMV = 304,
     LRLWM = 305,
     LMOVMW = 306,
     LMOVEM = 307,
     LMOVFL = 308,
     LMTFSB = 309,
     LMA = 310,
     LFCONST = 311,
     LSCONST = 312,
     LNAME = 313,
     LLAB = 314,
     LVAR = 315
   };
#endif
/* Tokens.  */
#define LMOVW 258
#define LMOVB 259
#define LABS 260
#define LLOGW 261
#define LSHW 262
#define LADDW 263
#define LCMP 264
#define LCROP 265
#define LBRA 266
#define LFMOV 267
#define LFCONV 268
#define LFCMP 269
#define LFADD 270
#define LFMA 271
#define LTRAP 272
#define LXORW 273
#define LNOP 274
#define LEND 275
#define LRETT 276
#define LWORD 277
#define LTEXT 278
#define LDATA 279
#define LRETRN 280
#define LCONST 281
#define LSP 282
#define LSB 283
#define LFP 284
#define LPC 285
#define LCREG 286
#define LFLUSH 287
#define LREG 288
#define LFREG 289
#define LR 290
#define LCR 291
#define LF 292
#define LFPSCR 293
#define LLR 294
#define LCTR 295
#define LSPR 296
#define LSPREG 297
#define LSEG 298
#define LMSR 299
#define LSCHED 300
#define LXLD 301
#define LXST 302
#define LXOP 303
#define LXMV 304
#define LRLWM 305
#define LMOVMW 306
#define LMOVEM 307
#define LMOVFL 308
#define LMTFSB 309
#define LMA 310
#define LFCONST 311
#define LSCONST 312
#define LNAME 313
#define LLAB 314
#define LVAR 315




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 38 "a.y"

	Sym	*sym;
	long	lval;
	double	dval;
	char	sval[8];
	Gen	gen;



/* Line 2068 of yacc.c  */
#line 180 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


