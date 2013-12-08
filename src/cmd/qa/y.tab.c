/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 31 "a.y"

#include <u.h>
#include <stdio.h>	/* if we don't, bison will, and a.h re-#defines getc */
#include <libc.h>
#include "a.h"


/* Line 268 of yacc.c  */
#line 79 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
#line 38 "a.y"

	Sym	*sym;
	long	lval;
	double	dval;
	char	sval[8];
	Gen	gen;



/* Line 293 of yacc.c  */
#line 245 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 257 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   877

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  188
/* YYNRULES -- Number of states.  */
#define YYNSTATES  462

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    77,    12,     5,     2,
      75,    76,    10,     8,    74,     9,     2,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    73,
       6,    72,     7,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,    78,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    13,    14,    19,    24,
      29,    32,    34,    37,    40,    45,    50,    55,    60,    65,
      70,    75,    80,    85,    90,    95,   100,   105,   110,   115,
     120,   125,   130,   135,   140,   147,   152,   157,   162,   169,
     174,   179,   186,   193,   200,   205,   210,   217,   222,   229,
     234,   241,   246,   251,   254,   261,   266,   271,   276,   283,
     288,   293,   298,   303,   308,   313,   318,   323,   328,   333,
     336,   339,   344,   348,   352,   358,   363,   368,   375,   380,
     385,   392,   399,   406,   415,   420,   425,   429,   432,   437,
     442,   449,   458,   463,   470,   475,   480,   487,   494,   503,
     512,   521,   530,   535,   540,   545,   552,   557,   564,   569,
     574,   577,   580,   584,   588,   592,   596,   600,   604,   607,
     612,   619,   626,   635,   642,   649,   656,   659,   664,   667,
     670,   672,   674,   676,   678,   680,   682,   684,   686,   691,
     693,   698,   703,   705,   710,   712,   717,   719,   724,   726,
     730,   733,   736,   739,   743,   746,   748,   753,   757,   763,
     765,   770,   775,   781,   789,   790,   792,   793,   796,   799,
     801,   803,   805,   807,   809,   812,   815,   818,   822,   824,
     828,   832,   836,   840,   844,   849,   854,   858,   862
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      80,     0,    -1,    -1,    80,    81,    -1,    -1,    69,    71,
      82,    81,    -1,    -1,    68,    71,    83,    81,    -1,    68,
      72,   111,    73,    -1,    70,    72,   111,    73,    -1,    55,
      73,    -1,    73,    -1,    84,    73,    -1,     1,    73,    -1,
      13,    86,    74,    86,    -1,    13,   105,    74,    86,    -1,
      13,   104,    74,    86,    -1,    14,    86,    74,    86,    -1,
      14,   105,    74,    86,    -1,    14,   104,    74,    86,    -1,
      22,   105,    74,    96,    -1,    22,   104,    74,    96,    -1,
      22,   101,    74,    96,    -1,    22,    96,    74,    96,    -1,
      22,    96,    74,   105,    -1,    22,    96,    74,   104,    -1,
      13,    86,    74,   105,    -1,    13,    86,    74,   104,    -1,
      14,    86,    74,   105,    -1,    14,    86,    74,   104,    -1,
      13,    96,    74,   105,    -1,    13,    96,    74,   104,    -1,
      13,    94,    74,    96,    -1,    13,    96,    74,    94,    -1,
      13,    96,    74,   102,    74,    94,    -1,    13,    94,    74,
      97,    -1,    13,   102,    74,    95,    -1,    64,   102,    74,
     110,    -1,    13,    86,    74,   102,    74,    89,    -1,    13,
      86,    74,    97,    -1,    13,    86,    74,    89,    -1,    18,
      86,    74,   103,    74,    86,    -1,    18,   102,    74,   103,
      74,    86,    -1,    18,    86,    74,   102,    74,    86,    -1,
      18,    86,    74,    86,    -1,    18,   102,    74,    86,    -1,
      16,    86,    74,   103,    74,    86,    -1,    16,    86,    74,
      86,    -1,    17,    86,    74,   103,    74,    86,    -1,    17,
      86,    74,    86,    -1,    17,   102,    74,   103,    74,    86,
      -1,    17,   102,    74,    86,    -1,    15,    86,    74,    86,
      -1,    15,    86,    -1,    65,    86,    74,   103,    74,    86,
      -1,    13,   102,    74,    86,    -1,    13,   100,    74,    86,
      -1,    20,    98,    74,    98,    -1,    20,    98,    74,   110,
      74,    98,    -1,    13,    97,    74,    97,    -1,    13,    92,
      74,    97,    -1,    13,    89,    74,    86,    -1,    13,    92,
      74,    86,    -1,    13,    93,    74,    86,    -1,    13,    86,
      74,    93,    -1,    13,    87,    74,    86,    -1,    13,    86,
      74,    87,    -1,    13,    97,    74,    92,    -1,    13,    86,
      74,    92,    -1,    21,    85,    -1,    21,   105,    -1,    21,
      75,    87,    76,    -1,    21,    74,    85,    -1,    21,    74,
     105,    -1,    21,    74,    75,    87,    76,    -1,    21,    97,
      74,    85,    -1,    21,    97,    74,   105,    -1,    21,    97,
      74,    75,    87,    76,    -1,    21,   110,    74,    85,    -1,
      21,   110,    74,   105,    -1,    21,   110,    74,    75,    87,
      76,    -1,    21,   110,    74,   110,    74,    85,    -1,    21,
     110,    74,   110,    74,   105,    -1,    21,   110,    74,   110,
      74,    75,    87,    76,    -1,    27,    86,    74,   103,    -1,
      27,   102,    74,   103,    -1,    27,    86,   107,    -1,    27,
     107,    -1,    23,    96,    74,    96,    -1,    25,    96,    74,
      96,    -1,    25,    96,    74,    96,    74,    96,    -1,    26,
      96,    74,    96,    74,    96,    74,    96,    -1,    24,    96,
      74,    96,    -1,    24,    96,    74,    96,    74,    97,    -1,
      19,    86,    74,    86,    -1,    19,    86,    74,   102,    -1,
      19,    86,    74,    86,    74,    97,    -1,    19,    86,    74,
     102,    74,    97,    -1,    60,   102,    74,    86,    74,   102,
      74,    86,    -1,    60,   102,    74,    86,    74,    99,    74,
      86,    -1,    60,    86,    74,    86,    74,   102,    74,    86,
      -1,    60,    86,    74,    86,    74,    99,    74,    86,    -1,
      61,   105,    74,    86,    -1,    61,    86,    74,   105,    -1,
      56,   104,    74,    86,    -1,    56,   104,    74,   102,    74,
      86,    -1,    57,    86,    74,   104,    -1,    57,    86,    74,
     102,    74,   104,    -1,    59,   104,    74,    86,    -1,    59,
      86,    74,   104,    -1,    58,   104,    -1,    29,   107,    -1,
      29,    86,   107,    -1,    29,    96,   107,    -1,    29,    74,
      86,    -1,    29,    74,    96,    -1,    32,   102,   107,    -1,
      32,   100,   107,    -1,    30,   107,    -1,    33,   106,    74,
     102,    -1,    33,   106,    74,   110,    74,   102,    -1,    33,
     106,    74,   102,    71,   102,    -1,    33,   106,    74,   110,
      74,   102,    71,   102,    -1,    34,   106,    11,   110,    74,
     102,    -1,    34,   106,    11,   110,    74,   100,    -1,    34,
     106,    11,   110,    74,   101,    -1,    35,   107,    -1,   110,
      75,    40,    76,    -1,    68,   108,    -1,    69,   108,    -1,
     103,    -1,    88,    -1,    90,    -1,    49,    -1,    46,    -1,
      50,    -1,    54,    -1,    52,    -1,    51,    75,   110,    76,
      -1,    91,    -1,    53,    75,   110,    76,    -1,    53,    75,
     103,    76,    -1,    48,    -1,    48,    75,   110,    76,    -1,
      44,    -1,    47,    75,   110,    76,    -1,    41,    -1,    46,
      75,   110,    76,    -1,   110,    -1,   110,    74,   110,    -1,
      77,   105,    -1,    77,    67,    -1,    77,    66,    -1,    77,
       9,    66,    -1,    77,   110,    -1,    43,    -1,    45,    75,
     110,    76,    -1,    75,   103,    76,    -1,    75,   103,     8,
     103,    76,    -1,   106,    -1,   110,    75,   103,    76,    -1,
     110,    75,   109,    76,    -1,    68,   108,    75,   109,    76,
      -1,    68,     6,     7,   108,    75,    38,    76,    -1,    -1,
      74,    -1,    -1,     8,   110,    -1,     9,   110,    -1,    38,
      -1,    37,    -1,    39,    -1,    36,    -1,    70,    -1,     9,
     110,    -1,     8,   110,    -1,    78,   110,    -1,    75,   111,
      76,    -1,   110,    -1,   111,     8,   111,    -1,   111,     9,
     111,    -1,   111,    10,   111,    -1,   111,    11,   111,    -1,
     111,    12,   111,    -1,   111,     6,     6,   111,    -1,   111,
       7,     7,   111,    -1,   111,     5,   111,    -1,   111,     4,
     111,    -1,   111,     3,   111,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    67,    71,    70,    78,    77,    83,    88,
      94,    98,    99,   100,   106,   110,   114,   118,   122,   126,
     133,   137,   141,   145,   149,   153,   160,   164,   168,   172,
     179,   183,   190,   194,   198,   202,   206,   210,   217,   221,
     225,   235,   239,   243,   247,   251,   255,   259,   263,   267,
     271,   275,   279,   283,   290,   297,   301,   308,   312,   320,
     324,   328,   332,   336,   343,   350,   354,   358,   362,   371,
     375,   379,   383,   387,   391,   395,   399,   403,   407,   411,
     415,   419,   427,   435,   446,   450,   454,   458,   465,   469,
     473,   477,   481,   485,   492,   496,   500,   504,   511,   515,
     519,   523,   530,   534,   542,   546,   550,   554,   558,   562,
     566,   573,   577,   581,   585,   589,   596,   600,   607,   614,
     618,   622,   626,   633,   637,   641,   648,   654,   660,   669,
     678,   686,   687,   690,   698,   706,   714,   721,   727,   733,
     736,   745,   754,   762,   770,   776,   784,   790,   798,   806,
     827,   832,   840,   846,   853,   861,   862,   870,   877,   887,
     888,   897,   905,   913,   922,   923,   926,   929,   933,   939,
     940,   941,   944,   945,   949,   953,   957,   961,   967,   968,
     972,   976,   980,   984,   988,   992,   996,  1000,  1004
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "LMOVW", "LMOVB", "LABS", "LLOGW", "LSHW",
  "LADDW", "LCMP", "LCROP", "LBRA", "LFMOV", "LFCONV", "LFCMP", "LFADD",
  "LFMA", "LTRAP", "LXORW", "LNOP", "LEND", "LRETT", "LWORD", "LTEXT",
  "LDATA", "LRETRN", "LCONST", "LSP", "LSB", "LFP", "LPC", "LCREG",
  "LFLUSH", "LREG", "LFREG", "LR", "LCR", "LF", "LFPSCR", "LLR", "LCTR",
  "LSPR", "LSPREG", "LSEG", "LMSR", "LSCHED", "LXLD", "LXST", "LXOP",
  "LXMV", "LRLWM", "LMOVMW", "LMOVEM", "LMOVFL", "LMTFSB", "LMA",
  "LFCONST", "LSCONST", "LNAME", "LLAB", "LVAR", "':'", "'='", "';'",
  "','", "'('", "')'", "'$'", "'~'", "$accept", "prog", "line", "$@1",
  "$@2", "inst", "rel", "rreg", "xlreg", "lr", "lcr", "ctr", "msr", "psr",
  "seg", "fpscr", "fpscrf", "freg", "creg", "cbit", "mask", "ximm", "fimm",
  "imm", "sreg", "regaddr", "addr", "name", "comma", "offset", "pointer",
  "con", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   124,    94,    38,    60,    62,    43,    45,
      42,    47,    37,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    58,    61,    59,    44,    40,    41,    36,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    82,    81,    83,    81,    81,    81,
      81,    81,    81,    81,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    85,
      86,    87,    87,    88,    89,    90,    91,    92,    92,    92,
      93,    93,    94,    95,    96,    96,    97,    97,    98,    99,
     100,   100,   101,   101,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   107,   107,   108,   108,   108,   109,
     109,   109,   110,   110,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     4,     0,     4,     4,     4,
       2,     1,     2,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     6,     4,
       4,     6,     6,     6,     4,     4,     6,     4,     6,     4,
       6,     4,     4,     2,     6,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       2,     4,     3,     3,     5,     4,     4,     6,     4,     4,
       6,     6,     6,     8,     4,     4,     3,     2,     4,     4,
       6,     8,     4,     6,     4,     4,     6,     6,     8,     8,
       8,     8,     4,     4,     4,     6,     4,     6,     4,     4,
       2,     2,     3,     3,     3,     3,     3,     3,     2,     4,
       6,     6,     8,     6,     6,     6,     2,     4,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       4,     4,     1,     4,     1,     4,     1,     4,     1,     3,
       2,     2,     2,     3,     2,     1,     4,     3,     5,     1,
       4,     4,     5,     7,     0,     1,     0,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     2,     3,     1,     3,
       3,     3,     3,     3,     4,     4,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   164,
     164,     0,     0,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     3,     0,
      13,     0,     0,   172,   146,   155,   144,     0,   134,     0,
     142,   133,   135,     0,   137,     0,   136,   166,   173,     0,
       0,     0,     0,     0,   131,     0,   132,   139,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,   159,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,   166,   166,     0,     0,    69,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   164,     0,    87,   165,   164,   164,   111,
     118,   164,   164,     0,     0,     0,   126,    10,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     4,     0,    12,   175,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   178,     0,   151,
     150,   154,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,   128,   129,
       0,    72,    73,     0,     0,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,   165,    86,
       0,   114,   115,   112,   113,   117,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,   167,   168,     0,     0,   157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,    14,    66,    40,
      68,    64,    39,     0,    27,    26,    65,    61,    62,    60,
      63,    32,    35,    33,     0,    31,    30,    67,    59,    56,
       0,    55,    36,    16,    15,   170,   169,   171,     0,     0,
      17,    29,    28,    19,    18,    52,    47,   130,    49,   130,
      51,   130,    44,     0,   130,    45,   130,    94,    95,    57,
     148,     0,    71,     0,    75,    76,     0,    78,    79,     0,
       0,   153,    23,    25,    24,    22,    21,    20,    88,    92,
      89,     0,    84,    85,   119,     0,     0,   104,     0,     0,
     106,   109,   108,     0,     0,   103,   102,    37,     0,     7,
       8,     5,     9,   156,   147,   145,   138,   141,   140,     0,
       0,     0,   188,   187,   186,     0,     0,   179,   180,   181,
     182,   183,     0,     0,     0,   160,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   158,   184,   185,   134,    38,    34,
       0,    46,    48,    50,    43,    41,    42,    96,    97,    58,
      77,    80,     0,    81,    82,    93,    90,     0,   121,   120,
       0,   124,   125,   123,   105,   107,     0,     0,     0,     0,
       0,    54,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,    83,    91,   122,   101,   100,   149,
      99,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,   232,   230,    39,    99,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   282,    71,    72,    92,
     436,    73,   105,    74,    75,    76,   160,    78,   115,   155,
     289,   157,   158
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -178
static const yytype_int16 yypact[] =
{
    -178,   519,  -178,   -54,   611,   406,     8,     8,   -13,   -13,
       8,   615,   634,   663,    24,    24,    24,    24,   -14,    -1,
     -51,   -38,   792,   792,   -51,    -7,    29,     8,    29,   -10,
     -13,   675,     7,     8,    23,    27,    41,  -178,  -178,    66,
    -178,   615,   615,  -178,  -178,  -178,  -178,    34,    45,    82,
    -178,  -178,  -178,    89,  -178,    90,  -178,   219,  -178,    47,
     692,   615,    96,   102,  -178,   108,  -178,  -178,   126,   136,
     147,   152,   159,   163,   165,  -178,   166,   167,  -178,   142,
     168,   169,   170,   174,   175,   615,   176,   178,   184,   189,
     191,   615,   193,  -178,    45,   219,    53,   718,   756,  -178,
     195,  -178,    49,     6,   196,   197,   200,   203,   206,   210,
     211,   220,  -178,   231,   233,  -178,    83,   -51,   -51,  -178,
    -178,   -51,   -51,   245,   246,   309,  -178,  -178,     8,   248,
     249,  -178,   252,   255,   257,   260,   262,   271,   272,   274,
    -178,   615,  -178,   615,  -178,  -178,  -178,   615,   615,   615,
     615,    47,   326,   615,   615,   275,    10,  -178,   306,  -178,
    -178,   142,  -178,   352,     8,     8,   151,     8,   157,   669,
     205,     8,     9,     8,     8,   304,   406,     8,     8,     8,
       8,  -178,     8,     8,   -13,     8,   -13,   615,   275,  -178,
     756,  -178,  -178,   276,   277,   743,   774,   259,   288,  -178,
     688,    24,    24,    24,    24,    24,    24,    24,     8,  -178,
       8,  -178,  -178,  -178,  -178,  -178,  -178,   198,    37,   615,
     -13,    63,    29,     8,     8,     8,   792,     8,   615,     8,
     580,   484,   580,   555,   279,   280,   281,   283,   286,   290,
      53,  -178,  -178,    37,     8,  -178,   615,   615,   615,   358,
     360,   615,   615,   615,   615,   615,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,   294,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,   295,  -178,  -178,  -178,  -178,  -178,
     296,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   302,   303,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,   311,  -178,   312,
    -178,   313,  -178,   315,   316,  -178,   317,   320,   333,  -178,
     337,   307,  -178,   756,  -178,  -178,   756,  -178,  -178,    60,
     324,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   338,
     339,   343,  -178,  -178,   299,   344,   345,  -178,   349,   350,
    -178,  -178,  -178,   354,   357,  -178,  -178,  -178,   359,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   305,
     356,   361,   504,   517,   461,   615,   615,    77,    77,  -178,
    -178,  -178,   380,   386,   615,  -178,  -178,     8,     8,     8,
       8,     8,     8,     4,     4,   615,  -178,   362,   363,   786,
    -178,     4,    24,    24,     7,     7,   364,     8,    29,   198,
     198,     8,   402,  -178,  -178,   143,   143,  -178,  -178,  -178,
     369,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,   756,  -178,  -178,  -178,  -178,   374,  -178,   379,
     706,  -178,  -178,  -178,  -178,  -178,   378,   384,   385,   388,
     389,  -178,   377,  -178,   399,    24,     7,   799,     8,     8,
     615,     8,     8,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,   -21,  -178,  -178,  -178,   -89,    -5,   -78,  -178,
    -156,  -178,  -178,  -136,   291,  -160,  -178,    86,    25,  -177,
      64,   -15,    69,    61,   155,   103,   132,    58,    -3,   -84,
     234,    36,  -105
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      80,    83,    84,    86,    88,    90,   121,   259,   191,   273,
     309,   188,   189,   113,   117,   198,   119,   120,   244,    40,
     194,   126,   130,   112,   132,   134,   136,   260,   139,    45,
      45,    47,    47,    45,   277,    47,   231,   100,   233,    60,
      79,    79,    45,    46,    47,    44,    49,    93,   102,    79,
      94,    45,    45,    47,    47,    41,    42,   280,   124,   124,
     112,   153,   154,    85,    85,   128,   127,    79,    46,    87,
      89,    49,   199,   116,   285,   286,   287,   145,   146,   114,
     123,   125,   122,    43,    85,   258,   245,   253,   254,   255,
      45,   135,    47,   138,   140,   141,   161,   162,   142,   104,
     108,   109,   110,   111,   128,   118,   314,   317,    81,   147,
     209,   211,   311,   143,   213,   214,   106,    58,   215,   216,
     148,   181,    91,   196,   197,    61,    45,    46,    47,   129,
      49,   131,   133,   193,   389,   197,    77,    82,   128,   144,
      85,   362,   363,   364,   101,   107,   367,   368,   369,   370,
     371,   251,   252,   253,   254,   255,   359,   149,   257,   266,
     267,   268,   270,   137,   150,   151,   279,   281,   283,   284,
     163,   290,   293,   294,   295,   296,   164,   298,   300,   302,
     305,   307,   165,   234,   235,   236,   237,   239,   262,   241,
     242,   269,    44,   272,    45,   278,    47,    94,    44,    79,
     166,    46,   212,    94,    49,    79,    41,    42,   419,   349,
     167,   351,    79,   409,   156,   337,   408,   175,   342,   343,
     344,   168,   346,   310,   263,   152,   169,   153,   154,   192,
     274,   193,   319,   170,    43,   387,    79,   171,   388,   172,
     173,   174,   176,   177,   178,   303,    44,   308,   179,   180,
     182,    94,   183,   335,   271,   336,    53,    54,   184,    56,
     405,   406,    79,   185,   347,   186,   264,   187,    58,   195,
     200,   201,   275,    91,   202,    85,    61,   203,   334,   291,
     204,   338,   339,   156,   205,   206,   322,   325,   326,   327,
     328,   329,   330,   331,   207,   265,   285,   286,   287,   320,
     423,   276,    45,   323,    47,   208,   238,   210,   292,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   217,
     219,   218,   220,   221,   340,   341,   222,   315,   318,   223,
     288,   224,   324,   240,   225,   297,   226,   299,   301,   304,
     306,   285,   286,   287,   444,   227,   228,    45,   229,    47,
     243,   197,   288,   312,   321,   353,   354,   355,   345,   356,
      41,    42,   357,   332,   365,   333,   358,   366,   372,   373,
     394,   374,   411,   412,   413,   414,   415,   416,   375,   376,
     402,   431,   256,   386,   348,   377,   378,   379,    43,   380,
     381,   382,   434,    44,   383,    45,   441,    47,    48,   361,
     390,    51,    52,    53,    54,    55,    56,   384,   417,   418,
     410,   385,   391,   392,    41,    42,   425,   393,   395,   396,
      57,    93,    58,   397,   398,   193,   407,    59,   399,    85,
      61,   400,   403,   401,    50,   438,   438,   404,   420,   421,
     442,   430,    43,   457,   458,   443,   460,   461,   445,    45,
     446,    47,   448,   453,   261,   428,   429,   433,   449,   450,
     437,   440,   451,   452,   439,   432,   161,   249,   250,   251,
     252,   253,   254,   255,    57,   454,    58,   360,   426,   427,
       0,    59,     0,   146,    61,     0,   459,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,   456,   247,   248,
     249,   250,   251,   252,   253,   254,   255,     0,     0,     2,
       3,   424,   248,   249,   250,   251,   252,   253,   254,   255,
       0,   455,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     0,    19,    20,
       0,    21,    22,    23,    24,     0,     0,   350,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
      31,     3,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,    19,
      20,     0,    21,    22,    23,    24,     0,     0,     0,    41,
      42,     0,     0,    41,    42,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      30,    31,    41,    42,    32,    33,     0,    43,    34,    35,
      36,    43,    44,    37,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
      43,    41,    42,     0,     0,    44,     0,    41,    42,    57,
      94,    58,     0,    41,    42,    58,    59,     0,    60,    61,
      91,     0,     0,    61,     0,     0,    41,    42,     0,    43,
      41,    42,    95,    96,    58,    43,     0,    46,    97,    98,
      49,    43,    61,     0,    41,   447,     0,    50,    45,     0,
      47,     0,     0,     0,    43,     0,    41,    42,    43,     0,
       0,    57,    46,    58,     0,    49,     0,    57,    59,    58,
     103,    61,    43,    57,    59,    58,    85,    61,     0,     0,
      91,    41,    42,    61,    43,     0,    57,     0,    58,   159,
      57,     0,    58,    59,    41,    42,    61,    91,     0,     0,
      61,     0,   199,   159,    57,     0,    58,     0,     0,    43,
       0,    91,    41,    42,    61,     0,    95,    96,    58,     0,
       0,     0,    43,   190,    41,    42,    61,     0,     0,     0,
      41,    42,     0,     0,     0,    51,    52,    41,    42,     0,
      43,    95,    96,    58,     0,     0,     0,     0,   313,     0,
       0,    61,    43,     0,     0,     0,    58,     0,    43,     0,
       0,    91,     0,     0,    61,    43,     0,     0,     0,     0,
       0,     0,    95,    96,    58,     0,     0,     0,     0,   316,
       0,     0,    61,     0,    95,    96,    58,     0,     0,     0,
      57,   422,    58,     0,    61,   321,     0,    91,     0,    58,
      61,     0,     0,     0,    91,     0,     0,    61
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-178))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       5,     6,     7,     8,     9,    10,    21,   163,    97,   169,
     187,    95,    96,    18,    19,     9,    19,    20,     8,    73,
      98,    24,    27,    74,    29,    30,    31,   163,    33,    43,
      43,    45,    45,    43,   170,    45,   141,    12,   143,    77,
       4,     5,    43,    44,    45,    41,    47,    11,    12,    13,
      46,    43,    43,    45,    45,     8,     9,    48,    22,    23,
      74,     8,     9,    77,    77,    75,    73,    31,    44,     8,
       9,    47,    66,    74,    37,    38,    39,    41,    42,    18,
      22,    23,    21,    36,    77,   163,    76,    10,    11,    12,
      43,    30,    45,    32,    71,    72,    60,    61,    71,    13,
      14,    15,    16,    17,    75,    19,   195,   196,     5,    75,
     113,   116,   190,    72,   117,   118,    13,    70,   121,   122,
      75,    85,    75,    74,    75,    78,    43,    44,    45,    26,
      47,    28,    29,    97,    74,    75,     4,     5,    75,    73,
      77,   246,   247,   248,    12,    13,   251,   252,   253,   254,
     255,     8,     9,    10,    11,    12,   240,    75,   163,   164,
     165,   166,   167,    31,    75,    75,   171,   172,   173,   174,
      74,   176,   177,   178,   179,   180,    74,   182,   183,   184,
     185,   186,    74,   147,   148,   149,   150,   151,   163,   153,
     154,   166,    41,   168,    43,   170,    45,    46,    41,   163,
      74,    44,   116,    46,    47,   169,     8,     9,   385,   230,
      74,   232,   176,   373,    59,   220,   372,    75,   223,   224,
     225,    74,   227,   187,   163,     6,    74,     8,     9,    97,
     169,   195,   196,    74,    36,   313,   200,    74,   316,    74,
      74,    74,    74,    74,    74,   184,    41,   186,    74,    74,
      74,    46,    74,   217,   168,   219,    51,    52,    74,    54,
     365,   366,   226,    74,   228,    74,   163,    74,    70,    74,
      74,    74,   169,    75,    74,    77,    78,    74,   217,   176,
      74,   220,   221,   128,    74,    74,   200,   201,   202,   203,
     204,   205,   206,   207,    74,   163,    37,    38,    39,    40,
     389,   169,    43,   200,    45,    74,   151,    74,   176,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    74,
      11,    75,    74,    74,   221,   222,    74,   195,   196,    74,
     175,    74,   200,     7,    74,   180,    74,   182,   183,   184,
     185,    37,    38,    39,   422,    74,    74,    43,    74,    45,
      75,    75,   197,    76,    66,    76,    76,    76,   226,    76,
       8,     9,    76,   208,     6,   210,    76,     7,    74,    74,
      71,    75,   377,   378,   379,   380,   381,   382,    76,    76,
      75,   396,    76,    76,   229,    74,    74,    74,    36,    74,
      74,    74,   397,    41,    74,    43,   401,    45,    46,   244,
      76,    49,    50,    51,    52,    53,    54,    74,   383,   384,
     374,    74,    74,    74,     8,     9,   391,    74,    74,    74,
      68,   385,    70,    74,    74,   389,    46,    75,    74,    77,
      78,    74,    76,    74,    48,   399,   400,    76,    76,    76,
      38,    77,    36,   448,   449,    76,   451,   452,    74,    43,
      71,    45,    74,    76,   163,   394,   395,   396,    74,    74,
     399,   400,    74,    74,   400,   396,   430,     6,     7,     8,
       9,    10,    11,    12,    68,    76,    70,   243,   392,   393,
      -1,    75,    -1,   447,    78,    -1,   450,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,   398,    -1,    -1,    -1,    -1,    -1,   446,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,     0,
       1,   389,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,   445,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    33,    34,    35,    -1,    -1,    73,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,     1,    -1,    64,    65,    -1,    -1,    68,    69,    70,
      -1,    -1,    73,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,     8,
       9,    -1,    -1,     8,     9,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,     8,     9,    64,    65,    -1,    36,    68,    69,
      70,    36,    41,    73,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      36,     8,     9,    -1,    -1,    41,    -1,     8,     9,    68,
      46,    70,    -1,     8,     9,    70,    75,    -1,    77,    78,
      75,    -1,    -1,    78,    -1,    -1,     8,     9,    -1,    36,
       8,     9,    68,    69,    70,    36,    -1,    44,    74,    75,
      47,    36,    78,    -1,     8,     9,    -1,    48,    43,    -1,
      45,    -1,    -1,    -1,    36,    -1,     8,     9,    36,    -1,
      -1,    68,    44,    70,    -1,    47,    -1,    68,    75,    70,
      77,    78,    36,    68,    75,    70,    77,    78,    -1,    -1,
      75,     8,     9,    78,    36,    -1,    68,    -1,    70,    67,
      68,    -1,    70,    75,     8,     9,    78,    75,    -1,    -1,
      78,    -1,    66,    67,    68,    -1,    70,    -1,    -1,    36,
      -1,    75,     8,     9,    78,    -1,    68,    69,    70,    -1,
      -1,    -1,    36,    75,     8,     9,    78,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    49,    50,     8,     9,    -1,
      36,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    36,    -1,    -1,    -1,    70,    -1,    36,    -1,
      -1,    75,    -1,    -1,    78,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,    -1,    68,    69,    70,    -1,    -1,    -1,
      68,    75,    70,    -1,    78,    66,    -1,    75,    -1,    70,
      78,    -1,    -1,    -1,    75,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,     0,     1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    29,
      30,    32,    33,    34,    35,    55,    56,    57,    58,    59,
      60,    61,    64,    65,    68,    69,    70,    73,    81,    84,
      73,     8,     9,    36,    41,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    68,    70,    75,
      77,    78,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    96,    97,   100,   102,   103,   104,   105,   106,   110,
      86,   104,   105,    86,    86,    77,    86,   102,    86,   102,
      86,    75,    98,   110,    46,    68,    69,    74,    75,    85,
      97,   105,   110,    77,    96,   101,   104,   105,    96,    96,
      96,    96,    74,    86,   102,   107,    74,    86,    96,   107,
     107,   100,   102,   106,   110,   106,   107,    73,    75,   104,
      86,   104,    86,   104,    86,   102,    86,   105,   102,    86,
      71,    72,    71,    72,    73,   110,   110,    75,    75,    75,
      75,    75,     6,     8,     9,   108,   103,   110,   111,    67,
     105,   110,   110,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    74,    74,    74,    74,
      74,   110,    74,    74,    74,    74,    74,    74,   108,   108,
      75,    85,   105,   110,    87,    74,    74,    75,     9,    66,
      74,    74,    74,    74,    74,    74,    74,    74,    74,   107,
      74,    86,    96,   107,   107,   107,   107,    74,    75,    11,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      83,   111,    82,   111,   110,   110,   110,   110,   103,   110,
       7,   110,   110,    75,     8,    76,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    76,    86,    87,    89,
      92,    93,    97,   102,   104,   105,    86,    86,    86,    97,
      86,    96,    97,    94,   102,   104,   105,    92,    97,    86,
      48,    86,    95,    86,    86,    37,    38,    39,   103,   109,
      86,   104,   105,    86,    86,    86,    86,   103,    86,   103,
      86,   103,    86,   102,   103,    86,   103,    86,   102,    98,
     110,    87,    76,    75,    85,   105,    75,    85,   105,   110,
      40,    66,    96,   104,   105,    96,    96,    96,    96,    96,
      96,    96,   103,   103,   102,   110,   110,    86,   102,   102,
     104,   104,    86,    86,    86,   105,    86,   110,   103,    81,
      73,    81,    73,    76,    76,    76,    76,    76,    76,   108,
     109,   103,   111,   111,   111,     6,     7,   111,   111,   111,
     111,   111,    74,    74,    75,    76,    76,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    76,    87,    87,    74,
      76,    74,    74,    74,    71,    74,    74,    74,    74,    74,
      74,    74,    75,    76,    76,   111,   111,    46,    89,    94,
     110,    86,    86,    86,    86,    86,    86,    97,    97,    98,
      76,    76,    75,    85,   105,    97,    96,    96,   102,   102,
      77,   100,   101,   102,    86,   104,    99,   102,   110,    99,
     102,    86,    38,    76,    87,    74,    71,     9,    74,    74,
      74,    74,    74,    76,    76,    96,   102,    86,    86,   110,
      86,    86
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1806 of yacc.c  */
#line 71 "a.y"
    {
		if((yyvsp[(1) - (2)].sym)->value != pc)
			yyerror("redeclaration of %s", (yyvsp[(1) - (2)].sym)->name);
		(yyvsp[(1) - (2)].sym)->value = pc;
	}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 78 "a.y"
    {
		(yyvsp[(1) - (2)].sym)->type = LLAB;
		(yyvsp[(1) - (2)].sym)->value = pc;
	}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 84 "a.y"
    {
		(yyvsp[(1) - (4)].sym)->type = LVAR;
		(yyvsp[(1) - (4)].sym)->value = (yyvsp[(3) - (4)].lval);
	}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 89 "a.y"
    {
		if((yyvsp[(1) - (4)].sym)->value != (yyvsp[(3) - (4)].lval))
			yyerror("redeclaration of %s", (yyvsp[(1) - (4)].sym)->name);
		(yyvsp[(1) - (4)].sym)->value = (yyvsp[(3) - (4)].lval);
	}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 95 "a.y"
    {
		nosched = (yyvsp[(1) - (2)].lval);
	}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 107 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 111 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 115 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 119 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 123 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 127 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 134 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 138 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 142 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 146 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 150 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 154 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 161 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 165 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 169 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 173 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 180 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 184 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 191 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 195 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 199 "a.y"
    {
		outgcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), NREG, &(yyvsp[(4) - (6)].gen), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 203 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 207 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 211 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), (yyvsp[(4) - (4)].lval), &nullgen);
	}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 218 "a.y"
    {
		outgcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), NREG, &(yyvsp[(4) - (6)].gen), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 222 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 226 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 236 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 240 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 244 "a.y"
    {
		outgcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), NREG, &(yyvsp[(4) - (6)].gen), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 248 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 252 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 256 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 260 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 264 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 268 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 272 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 276 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 280 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 284 "a.y"
    {
		outcode((yyvsp[(1) - (2)].lval), &(yyvsp[(2) - (2)].gen), NREG, &(yyvsp[(2) - (2)].gen));
	}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 291 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 298 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 302 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 309 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), (yyvsp[(4) - (4)].gen).reg, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 313 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 321 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 325 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 329 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 333 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 337 "a.y"
    {
		int r;
		r = (yyvsp[(2) - (4)].gen).offset;
		(yyvsp[(2) - (4)].gen).offset = 0;
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), r, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 344 "a.y"
    {
		int r;
		r = (yyvsp[(4) - (4)].gen).offset;
		(yyvsp[(4) - (4)].gen).offset = 0;
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), r, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 351 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 355 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 359 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 363 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 372 "a.y"
    {
		outcode((yyvsp[(1) - (2)].lval), &nullgen, NREG, &(yyvsp[(2) - (2)].gen));
	}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 376 "a.y"
    {
		outcode((yyvsp[(1) - (2)].lval), &nullgen, NREG, &(yyvsp[(2) - (2)].gen));
	}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 380 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &nullgen, NREG, &(yyvsp[(3) - (4)].gen));
	}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 384 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &nullgen, NREG, &(yyvsp[(3) - (3)].gen));
	}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 388 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &nullgen, NREG, &(yyvsp[(3) - (3)].gen));
	}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 392 "a.y"
    {
		outcode((yyvsp[(1) - (5)].lval), &nullgen, NREG, &(yyvsp[(4) - (5)].gen));
	}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 396 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 400 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 404 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), NREG, &(yyvsp[(5) - (6)].gen));
	}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 408 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &nullgen, (yyvsp[(2) - (4)].lval), &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 412 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &nullgen, (yyvsp[(2) - (4)].lval), &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 416 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &nullgen, (yyvsp[(2) - (6)].lval), &(yyvsp[(5) - (6)].gen));
	}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 420 "a.y"
    {
		Gen g;
		g = nullgen;
		g.type = D_CONST;
		g.offset = (yyvsp[(2) - (6)].lval);
		outcode((yyvsp[(1) - (6)].lval), &g, (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 428 "a.y"
    {
		Gen g;
		g = nullgen;
		g.type = D_CONST;
		g.offset = (yyvsp[(2) - (6)].lval);
		outcode((yyvsp[(1) - (6)].lval), &g, (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 436 "a.y"
    {
		Gen g;
		g = nullgen;
		g.type = D_CONST;
		g.offset = (yyvsp[(2) - (8)].lval);
		outcode((yyvsp[(1) - (8)].lval), &g, (yyvsp[(4) - (8)].lval), &(yyvsp[(7) - (8)].gen));
	}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 447 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), (yyvsp[(4) - (4)].lval), &nullgen);
	}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 451 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), (yyvsp[(4) - (4)].lval), &nullgen);
	}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 455 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &(yyvsp[(2) - (3)].gen), NREG, &nullgen);
	}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 459 "a.y"
    {
		outcode((yyvsp[(1) - (2)].lval), &nullgen, NREG, &nullgen);
	}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 466 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 470 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 474 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].gen).reg, &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 478 "a.y"
    {
		outgcode((yyvsp[(1) - (8)].lval), &(yyvsp[(2) - (8)].gen), (yyvsp[(4) - (8)].gen).reg, &(yyvsp[(6) - (8)].gen), &(yyvsp[(8) - (8)].gen));
	}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 482 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 486 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(6) - (6)].gen).reg, &(yyvsp[(4) - (6)].gen));
	}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 493 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 497 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 501 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(6) - (6)].gen).reg, &(yyvsp[(4) - (6)].gen));
	}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 505 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(6) - (6)].gen).reg, &(yyvsp[(4) - (6)].gen));
	}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 512 "a.y"
    {
		outgcode((yyvsp[(1) - (8)].lval), &(yyvsp[(2) - (8)].gen), (yyvsp[(4) - (8)].gen).reg, &(yyvsp[(6) - (8)].gen), &(yyvsp[(8) - (8)].gen));
	}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 516 "a.y"
    {
		outgcode((yyvsp[(1) - (8)].lval), &(yyvsp[(2) - (8)].gen), (yyvsp[(4) - (8)].gen).reg, &(yyvsp[(6) - (8)].gen), &(yyvsp[(8) - (8)].gen));
	}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 520 "a.y"
    {
		outgcode((yyvsp[(1) - (8)].lval), &(yyvsp[(2) - (8)].gen), (yyvsp[(4) - (8)].gen).reg, &(yyvsp[(6) - (8)].gen), &(yyvsp[(8) - (8)].gen));
	}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 524 "a.y"
    {
		outgcode((yyvsp[(1) - (8)].lval), &(yyvsp[(2) - (8)].gen), (yyvsp[(4) - (8)].gen).reg, &(yyvsp[(6) - (8)].gen), &(yyvsp[(8) - (8)].gen));
	}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 531 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 535 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 543 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 547 "a.y"
    {
		outgcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), NREG, &(yyvsp[(4) - (6)].gen), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 551 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 555 "a.y"
    {
		outgcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), NREG, &(yyvsp[(4) - (6)].gen), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 559 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 563 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 567 "a.y"
    {
		outcode((yyvsp[(1) - (2)].lval), &(yyvsp[(2) - (2)].gen), NREG, &nullgen);
	}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 574 "a.y"
    {
		outcode((yyvsp[(1) - (2)].lval), &nullgen, NREG, &nullgen);
	}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 578 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &(yyvsp[(2) - (3)].gen), NREG, &nullgen);
	}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 582 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &(yyvsp[(2) - (3)].gen), NREG, &nullgen);
	}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 586 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &nullgen, NREG, &(yyvsp[(3) - (3)].gen));
	}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 590 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &nullgen, NREG, &(yyvsp[(3) - (3)].gen));
	}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 597 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &(yyvsp[(2) - (3)].gen), NREG, &nullgen);
	}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 601 "a.y"
    {
		outcode((yyvsp[(1) - (3)].lval), &(yyvsp[(2) - (3)].gen), NREG, &nullgen);
	}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 608 "a.y"
    {
		outcode((yyvsp[(1) - (2)].lval), &nullgen, NREG, &nullgen);
	}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 615 "a.y"
    {
		outcode((yyvsp[(1) - (4)].lval), &(yyvsp[(2) - (4)].gen), NREG, &(yyvsp[(4) - (4)].gen));
	}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 619 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 623 "a.y"
    {
		outgcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), NREG, &(yyvsp[(6) - (6)].gen), &(yyvsp[(4) - (6)].gen));
	}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 627 "a.y"
    {
		outgcode((yyvsp[(1) - (8)].lval), &(yyvsp[(2) - (8)].gen), (yyvsp[(4) - (8)].lval), &(yyvsp[(8) - (8)].gen), &(yyvsp[(6) - (8)].gen));
	}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 634 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 638 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 642 "a.y"
    {
		outcode((yyvsp[(1) - (6)].lval), &(yyvsp[(2) - (6)].gen), (yyvsp[(4) - (6)].lval), &(yyvsp[(6) - (6)].gen));
	}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 649 "a.y"
    {
		outcode((yyvsp[(1) - (2)].lval), &nullgen, NREG, &nullgen);
	}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 655 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_BRANCH;
		(yyval.gen).offset = (yyvsp[(1) - (4)].lval) + pc;
	}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 661 "a.y"
    {
		(yyval.gen) = nullgen;
		if(pass == 2)
			yyerror("undefined label: %s", (yyvsp[(1) - (2)].sym)->name);
		(yyval.gen).type = D_BRANCH;
		(yyval.gen).sym = (yyvsp[(1) - (2)].sym);
		(yyval.gen).offset = (yyvsp[(2) - (2)].lval);
	}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 670 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_BRANCH;
		(yyval.gen).sym = (yyvsp[(1) - (2)].sym);
		(yyval.gen).offset = (yyvsp[(1) - (2)].sym)->value + (yyvsp[(2) - (2)].lval);
	}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 679 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_REG;
		(yyval.gen).reg = (yyvsp[(1) - (1)].lval);
	}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 691 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_SPR;
		(yyval.gen).offset = (yyvsp[(1) - (1)].lval);
	}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 699 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_CREG;
		(yyval.gen).reg = NREG;	/* whole register */
	}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 707 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_SPR;
		(yyval.gen).offset = (yyvsp[(1) - (1)].lval);
	}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 715 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_MSR;
	}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 722 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_SPR;
		(yyval.gen).offset = (yyvsp[(1) - (1)].lval);
	}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 728 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = (yyvsp[(1) - (4)].lval);
		(yyval.gen).offset = (yyvsp[(3) - (4)].lval);
	}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 737 "a.y"
    {
		if((yyvsp[(3) - (4)].lval) < 0 || (yyvsp[(3) - (4)].lval) > 15)
			yyerror("segment register number out of range");
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_SREG;
		(yyval.gen).reg = (yyvsp[(3) - (4)].lval);
		(yyval.gen).offset = NREG;
	}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 746 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_SREG;
		(yyval.gen).reg = NREG;
		(yyval.gen).offset = (yyvsp[(3) - (4)].lval);
	}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 755 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_FPSCR;
		(yyval.gen).reg = NREG;
	}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 763 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_FPSCR;
		(yyval.gen).reg = (yyvsp[(3) - (4)].lval);
	}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 771 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_FREG;
		(yyval.gen).reg = (yyvsp[(1) - (1)].lval);
	}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 777 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_FREG;
		(yyval.gen).reg = (yyvsp[(3) - (4)].lval);
	}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 785 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_CREG;
		(yyval.gen).reg = (yyvsp[(1) - (1)].lval);
	}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 791 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_CREG;
		(yyval.gen).reg = (yyvsp[(3) - (4)].lval);
	}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 799 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_REG;
		(yyval.gen).reg = (yyvsp[(1) - (1)].lval);
	}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 807 "a.y"
    {
		int mb, me;
		ulong v;

		(yyval.gen) = nullgen;
		(yyval.gen).type = D_CONST;
		mb = (yyvsp[(1) - (3)].lval);
		me = (yyvsp[(3) - (3)].lval);
		if(mb < 0 || mb > 31 || me < 0 || me > 31){
			yyerror("illegal mask start/end value(s)");
			mb = me = 0;
		}
		if(mb <= me)
			v = ((ulong)~0L>>mb) & (~0L<<(31-me));
		else
			v = ~(((ulong)~0L>>(me+1)) & (~0L<<(31-(mb-1))));
		(yyval.gen).offset = v;
	}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 828 "a.y"
    {
		(yyval.gen) = (yyvsp[(2) - (2)].gen);
		(yyval.gen).type = D_CONST;
	}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 833 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_SCONST;
		memcpy((yyval.gen).sval, (yyvsp[(2) - (2)].sval), sizeof((yyval.gen).sval));
	}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 841 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_FCONST;
		(yyval.gen).dval = (yyvsp[(2) - (2)].dval);
	}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 847 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_FCONST;
		(yyval.gen).dval = -(yyvsp[(3) - (3)].dval);
	}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 854 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_CONST;
		(yyval.gen).offset = (yyvsp[(2) - (2)].lval);
	}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 863 "a.y"
    {
		if((yyval.lval) < 0 || (yyval.lval) >= NREG)
			print("register value out of range\n");
		(yyval.lval) = (yyvsp[(3) - (4)].lval);
	}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 871 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_OREG;
		(yyval.gen).reg = (yyvsp[(2) - (3)].lval);
		(yyval.gen).offset = 0;
	}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 878 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_OREG;
		(yyval.gen).reg = (yyvsp[(2) - (5)].lval);
		(yyval.gen).xreg = (yyvsp[(4) - (5)].lval);
		(yyval.gen).offset = 0;
	}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 889 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_OREG;
		(yyval.gen).reg = (yyvsp[(3) - (4)].lval);
		(yyval.gen).offset = (yyvsp[(1) - (4)].lval);
	}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 898 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_OREG;
		(yyval.gen).name = (yyvsp[(3) - (4)].lval);
		(yyval.gen).sym = S;
		(yyval.gen).offset = (yyvsp[(1) - (4)].lval);
	}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 906 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_OREG;
		(yyval.gen).name = (yyvsp[(4) - (5)].lval);
		(yyval.gen).sym = (yyvsp[(1) - (5)].sym);
		(yyval.gen).offset = (yyvsp[(2) - (5)].lval);
	}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 914 "a.y"
    {
		(yyval.gen) = nullgen;
		(yyval.gen).type = D_OREG;
		(yyval.gen).name = D_STATIC;
		(yyval.gen).sym = (yyvsp[(1) - (7)].sym);
		(yyval.gen).offset = (yyvsp[(4) - (7)].lval);
	}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 926 "a.y"
    {
		(yyval.lval) = 0;
	}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 930 "a.y"
    {
		(yyval.lval) = (yyvsp[(2) - (2)].lval);
	}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 934 "a.y"
    {
		(yyval.lval) = -(yyvsp[(2) - (2)].lval);
	}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 946 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (1)].sym)->value;
	}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 950 "a.y"
    {
		(yyval.lval) = -(yyvsp[(2) - (2)].lval);
	}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 954 "a.y"
    {
		(yyval.lval) = (yyvsp[(2) - (2)].lval);
	}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 958 "a.y"
    {
		(yyval.lval) = ~(yyvsp[(2) - (2)].lval);
	}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 962 "a.y"
    {
		(yyval.lval) = (yyvsp[(2) - (3)].lval);
	}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 969 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (3)].lval) + (yyvsp[(3) - (3)].lval);
	}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 973 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (3)].lval) - (yyvsp[(3) - (3)].lval);
	}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 977 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (3)].lval) * (yyvsp[(3) - (3)].lval);
	}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 981 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (3)].lval) / (yyvsp[(3) - (3)].lval);
	}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 985 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (3)].lval) % (yyvsp[(3) - (3)].lval);
	}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 989 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (4)].lval) << (yyvsp[(4) - (4)].lval);
	}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 993 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (4)].lval) >> (yyvsp[(4) - (4)].lval);
	}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 997 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (3)].lval) & (yyvsp[(3) - (3)].lval);
	}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1001 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (3)].lval) ^ (yyvsp[(3) - (3)].lval);
	}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1005 "a.y"
    {
		(yyval.lval) = (yyvsp[(1) - (3)].lval) | (yyvsp[(3) - (3)].lval);
	}
    break;



/* Line 1806 of yacc.c  */
#line 3596 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



