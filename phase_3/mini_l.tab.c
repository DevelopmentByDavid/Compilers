/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FUNCTION = 258,
     BEGIN_PARAMS = 259,
     END_PARAMS = 260,
     BEGIN_LOCALS = 261,
     END_LOCALS = 262,
     BEGIN_BODY = 263,
     END_BODY = 264,
     INTEGER = 265,
     ARRAY = 266,
     OF = 267,
     IF = 268,
     THEN = 269,
     ENDIF = 270,
     ELSE = 271,
     WHILE = 272,
     DO = 273,
     BEGINLOOP = 274,
     ENDLOOP = 275,
     CONTINUE = 276,
     READ = 277,
     WRITE = 278,
     AND = 279,
     OR = 280,
     NOT = 281,
     TRUE = 282,
     FALSE = 283,
     RETURN = 284,
     IDENT = 285,
     COLON = 286,
     SEMICOLON = 287,
     COMMA = 288,
     NUMBER = 289,
     ASSIGN = 290,
     NEQ = 291,
     EQ = 292,
     GTE = 293,
     GT = 294,
     LTE = 295,
     LT = 296,
     SUB = 297,
     ADD = 298,
     MOD = 299,
     DIV = 300,
     MULT = 301,
     UMINUS = 302,
     L_SQUARE_BRACKET = 303,
     R_SQUARE_BRACKET = 304,
     L_PAREN = 305,
     R_PAREN = 306
   };
#endif
/* Tokens.  */
#define FUNCTION 258
#define BEGIN_PARAMS 259
#define END_PARAMS 260
#define BEGIN_LOCALS 261
#define END_LOCALS 262
#define BEGIN_BODY 263
#define END_BODY 264
#define INTEGER 265
#define ARRAY 266
#define OF 267
#define IF 268
#define THEN 269
#define ENDIF 270
#define ELSE 271
#define WHILE 272
#define DO 273
#define BEGINLOOP 274
#define ENDLOOP 275
#define CONTINUE 276
#define READ 277
#define WRITE 278
#define AND 279
#define OR 280
#define NOT 281
#define TRUE 282
#define FALSE 283
#define RETURN 284
#define IDENT 285
#define COLON 286
#define SEMICOLON 287
#define COMMA 288
#define NUMBER 289
#define ASSIGN 290
#define NEQ 291
#define EQ 292
#define GTE 293
#define GT 294
#define LTE 295
#define LT 296
#define SUB 297
#define ADD 298
#define MOD 299
#define DIV 300
#define MULT 301
#define UMINUS 302
#define L_SQUARE_BRACKET 303
#define R_SQUARE_BRACKET 304
#define L_PAREN 305
#define R_PAREN 306




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y"

 #include "header.h"
 #include "classes.h"
 
 extern int currLine;
 extern int currPos;
 extern char* yytext;     // defined and maintained in lex.c
 extern int yylex();
 extern void yyerror(char *);
 extern void yyerror(string);


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "mini_l.y"
{
    string *myString;
    int myInt;
    arr_struct *my_arr_struct;
}
/* Line 193 of yacc.c.  */
#line 216 "mini_l.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "mini_l.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    24,    25,    29,    39,
      44,    45,    49,    50,    54,    58,    66,    78,    86,    95,
      99,   103,   105,   108,   111,   112,   116,   119,   120,   124,
     128,   130,   132,   136,   141,   144,   147,   152,   154,   156,
     158,   160,   162,   164,   167,   168,   172,   176,   180,   182,
     183,   184,   188,   192,   196,   199,   204,   206,   208,   212,
     215,   218,   223,   225,   230,   231
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    -1,    55,    54,    -1,     3,
      30,    32,     4,    56,     5,     6,    56,     7,     8,    60,
      32,    59,     9,    -1,    -1,    57,    32,    56,    -1,    30,
      58,    31,    11,    48,    34,    49,    12,    10,    -1,    30,
      58,    31,    10,    -1,    -1,    33,    30,    58,    -1,    -1,
      60,    32,    59,    -1,    73,    35,    67,    -1,    13,    61,
      14,    60,    32,    59,    15,    -1,    13,    61,    14,    60,
      32,    59,    16,    60,    32,    59,    15,    -1,    17,    61,
      19,    60,    32,    59,    20,    -1,    18,    19,    60,    32,
      59,    20,    17,    61,    -1,    22,    73,    74,    -1,    23,
      73,    74,    -1,    21,    -1,    29,    67,    -1,    63,    62,
      -1,    -1,    25,    63,    62,    -1,    65,    64,    -1,    -1,
      24,    65,    64,    -1,    67,    66,    67,    -1,    27,    -1,
      28,    -1,    50,    61,    51,    -1,    26,    67,    66,    67,
      -1,    26,    27,    -1,    26,    28,    -1,    26,    50,    61,
      51,    -1,    37,    -1,    36,    -1,    41,    -1,    39,    -1,
      40,    -1,    38,    -1,    71,    68,    -1,    -1,    43,    71,
      68,    -1,    42,    71,    68,    -1,    67,    33,    69,    -1,
      67,    -1,    -1,    -1,    44,    72,    70,    -1,    45,    72,
      70,    -1,    46,    72,    70,    -1,    72,    70,    -1,    30,
      50,    69,    51,    -1,    34,    -1,    73,    -1,    50,    67,
      51,    -1,    42,    34,    -1,    42,    73,    -1,    42,    50,
      67,    51,    -1,    30,    -1,    30,    48,    67,    49,    -1,
      -1,    33,    73,    74,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   113,   114,   120,   133,   134,   137,   144,
     153,   154,   163,   164,   167,   178,   182,   189,   193,   197,
     201,   205,   209,   215,   222,   225,   231,   238,   241,   246,
     264,   265,   266,   267,   268,   269,   270,   273,   274,   275,
     276,   277,   278,   281,   301,   305,   329,   356,   363,   369,
     375,   379,   385,   391,   399,   418,   437,   448,   457,   462,
     469,   475,   483,   489,   506,   507
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE",
  "FALSE", "RETURN", "IDENT", "COLON", "SEMICOLON", "COMMA", "NUMBER",
  "ASSIGN", "NEQ", "EQ", "GTE", "GT", "LTE", "LT", "SUB", "ADD", "MOD",
  "DIV", "MULT", "UMINUS", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET",
  "L_PAREN", "R_PAREN", "$accept", "program", "functions", "function",
  "declarations", "declaration", "idents", "statements", "statement",
  "bool_expr", "bool_expressions", "relation_and_expr",
  "relation_and_expressions", "relation_expr", "comp", "expression",
  "expression_loop", "expressions", "terms", "multiplicative_expr", "term",
  "var", "vars", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    71,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,    14,     0,     3,     9,     4,
       0,     3,     0,     3,     3,     7,    11,     7,     8,     3,
       3,     1,     2,     2,     0,     3,     2,     0,     3,     3,
       1,     1,     3,     4,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     3,     3,     1,     0,
       0,     3,     3,     3,     2,     4,     1,     1,     3,     2,
       2,     4,     1,     4,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,     0,     1,     4,     0,     6,
      10,     0,     0,     0,     0,     0,     6,    10,     0,     6,
       7,    11,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    62,     0,     0,
       0,     0,    30,    31,    62,    56,     0,     0,     0,    24,
      27,     0,    44,    50,    57,     0,     0,    64,    64,     0,
      22,     0,    12,     0,     8,    34,    35,     0,     0,    49,
      59,     0,    60,     0,     0,     0,     0,    23,     0,    26,
      38,    37,    42,    40,    41,    39,     0,     0,     0,    43,
       0,     0,     0,    54,     0,     0,     0,    19,    20,     0,
       0,     0,     0,    14,     0,     0,    48,     0,     0,    32,
      58,     0,    24,    27,    29,    44,    44,    50,    50,    50,
       0,    12,    64,    63,     5,    12,    36,    33,    49,    55,
      61,    12,    25,    28,    46,    45,    51,    52,    53,    12,
       0,    65,    13,    47,     0,     0,     0,    15,     0,    17,
       0,     0,    18,    12,     0,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    12,    14,   101,   102,    48,
      77,    49,    79,    50,    86,    51,    89,   107,    93,    52,
      53,    54,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -110
static const yytype_int16 yypact[] =
{
      17,    -6,    27,  -110,    17,     0,  -110,  -110,    67,    22,
      40,    79,    60,    64,    65,    92,    22,    40,     4,    22,
    -110,  -110,  -110,    51,    93,    88,    94,    52,    57,    98,
     -17,   -17,   104,  -110,    96,    96,    35,    80,    95,    97,
     119,     8,  -110,  -110,    12,  -110,   -11,   -17,   116,   106,
     109,    76,     3,   -42,  -110,   115,    57,   102,   102,    35,
    -110,    35,    57,    35,  -110,  -110,  -110,   -17,    76,    35,
    -110,    35,  -110,    85,    68,    57,   -17,  -110,   -17,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,    35,    35,    35,  -110,
      35,    35,    35,  -110,    57,   105,    96,  -110,  -110,    87,
      90,   131,   110,  -110,    99,    35,   108,   100,   101,  -110,
    -110,   111,   106,   109,  -110,     3,     3,   -42,   -42,   -42,
     112,    57,   102,  -110,  -110,    57,  -110,  -110,    35,  -110,
    -110,    57,  -110,  -110,  -110,  -110,  -110,  -110,  -110,    57,
     125,  -110,  -110,  -110,    48,   126,   130,  -110,    57,  -110,
     -17,   117,  -110,    57,   133,  -110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,   149,  -110,    24,  -110,   137,  -109,   -27,   -26,
      43,    81,    45,    78,    91,   -10,   -25,    32,   -63,     1,
      -9,   -28,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    38,    90,    91,    92,    55,    57,    58,    98,    41,
      42,    43,   140,    44,    22,    23,   142,    45,    72,    37,
       1,    73,   144,    70,     5,    46,    60,     6,    39,    95,
     145,    68,     8,    47,    39,    65,    66,    74,    44,    71,
      20,   104,    45,    24,   154,    87,    88,    39,   111,    99,
      46,   100,    10,   103,   136,   137,   138,    74,    67,   106,
      61,   108,    69,   147,   148,    44,    39,   120,   122,    45,
      30,     9,   141,    13,    31,    32,   114,    46,    33,    34,
      35,   117,   118,   119,    15,    59,    36,    37,   115,   116,
     134,   135,    16,    39,    17,   127,    18,    39,    19,    25,
      26,    29,    28,    39,    80,    81,    82,    83,    84,    85,
      40,    39,    80,    81,    82,    83,    84,    85,   106,   110,
      39,   151,    27,    56,   152,    39,    37,    62,    61,    64,
      75,    76,    63,    78,    94,    96,   109,   121,   110,   123,
     124,   128,   125,   131,   139,   146,   149,   150,   155,   153,
     126,   129,   130,     7,    21,   132,   113,   112,   133,   105,
     143
};

static const yytype_uint8 yycheck[] =
{
      28,    28,    44,    45,    46,    31,    34,    35,    58,    26,
      27,    28,   121,    30,    10,    11,   125,    34,    46,    30,
       3,    47,   131,    34,    30,    42,    36,     0,    56,    56,
     139,    41,    32,    50,    62,    27,    28,    47,    30,    50,
      16,    67,    34,    19,   153,    42,    43,    75,    75,    59,
      42,    61,    30,    63,   117,   118,   119,    67,    50,    69,
      48,    71,    50,    15,    16,    30,    94,    94,    96,    34,
      13,     4,   122,    33,    17,    18,    86,    42,    21,    22,
      23,    90,    91,    92,     5,    50,    29,    30,    87,    88,
     115,   116,    32,   121,    30,   105,    31,   125,     6,    48,
       7,    49,     8,   131,    36,    37,    38,    39,    40,    41,
      12,   139,    36,    37,    38,    39,    40,    41,   128,    51,
     148,   148,    34,    19,   150,   153,    30,    32,    48,    10,
      14,    25,    35,    24,    19,    33,    51,    32,    51,    49,
       9,    33,    32,    32,    32,    20,    20,    17,    15,    32,
      51,    51,    51,     4,    17,   112,    78,    76,   113,    68,
     128
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    54,    55,    30,     0,    54,    32,     4,
      30,    56,    57,    33,    58,     5,    32,    30,    31,     6,
      56,    58,    10,    11,    56,    48,     7,    34,     8,    49,
      13,    17,    18,    21,    22,    23,    29,    30,    60,    73,
      12,    26,    27,    28,    30,    34,    42,    50,    61,    63,
      65,    67,    71,    72,    73,    61,    19,    73,    73,    50,
      67,    48,    32,    35,    10,    27,    28,    50,    67,    50,
      34,    50,    73,    61,    67,    14,    25,    62,    24,    64,
      36,    37,    38,    39,    40,    41,    66,    42,    43,    68,
      44,    45,    46,    70,    19,    60,    33,    74,    74,    67,
      67,    59,    60,    67,    61,    66,    67,    69,    67,    51,
      51,    60,    63,    65,    67,    71,    71,    72,    72,    72,
      60,    32,    73,    49,     9,    32,    51,    67,    33,    51,
      51,    32,    62,    64,    68,    68,    70,    70,    70,    32,
      59,    74,    59,    69,    59,    59,    20,    15,    16,    20,
      17,    60,    61,    32,    59,    15
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
#line 107 "mini_l.y"
    {
                            /*printf("program -> functions\n");*/
                            print();
                        ;}
    break;

  case 3:
#line 113 "mini_l.y"
    {/*printf("functions -> epsilon\n");*/;}
    break;

  case 4:
#line 115 "mini_l.y"
    {
                        // /*printf("functions -> function functions\n");*/
                        ;}
    break;

  case 5:
#line 122 "mini_l.y"
    {
                            /*printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS
                            BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY\n");*/
                            // funcName($2);
                            if (addTable(*((yyvsp[(2) - (14)].myString)))) {
                                // genCode( "func " + *($2));
                                func(*((yyvsp[(2) - (14)].myString)));
                            };
                        ;}
    break;

  case 6:
#line 133 "mini_l.y"
    {/*printf("declarations -> epsilon\n");*/;}
    break;

  case 7:
#line 134 "mini_l.y"
    {/*printf("declarations -> declaration SEMICOLON declarations\n");*/;}
    break;

  case 8:
#line 138 "mini_l.y"
    {
                            /*printf("delcaration -> IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");*/
                            if (addTable(*((yyvsp[(1) - (9)].myString)))) {
                                genCode(". [] " + *((yyvsp[(1) - (9)].myString)) + ", " + *((yyvsp[(6) - (9)].myString)));
                            };
                        ;}
    break;

  case 9:
#line 145 "mini_l.y"
    {
                            /*printf("declaration -> IDENT idents COLON INTEGER\n");*/
                            if (addTable(*((yyvsp[(1) - (4)].myString)))) {
                                genCode(". " + *((yyvsp[(1) - (4)].myString)));
                            };
                        ;}
    break;

  case 10:
#line 153 "mini_l.y"
    {/*printf("idents -> epsilon\n");*/;}
    break;

  case 11:
#line 155 "mini_l.y"
    {
                            /*printf("idents -> COMMA IDENT idents\n");*/
                            if (addTable(*((yyvsp[(2) - (3)].myString)))) {
                                genCode(". " + *((yyvsp[(2) - (3)].myString)));
                            };
                        ;}
    break;

  case 12:
#line 163 "mini_l.y"
    {/*printf("statements -> epsilon\n");*/;}
    break;

  case 13:
#line 164 "mini_l.y"
    {/*printf("statements -> statement SEMICOLON statements\n");*/;}
    break;

  case 14:
#line 168 "mini_l.y"
    {
                            /*printf("statement -> var ASSIGN expression\n");*/
                            if (exist(*((yyvsp[(1) - (3)].myString))) && exist(*((yyvsp[(3) - (3)].myString)))) {             //if both variables exist, then simple assign statement
                                genCode("= " + *((yyvsp[(1) - (3)].myString)) + ", " + *((yyvsp[(3) - (3)].myString)));
                            }
                            //  else if (!exist(*($3))) {                     //if $3 !exist, then it's a piece of code & $1 is dest
                            //     string code = *($3);
                            //     genCode(code.insert(1, " " + *($1)));
                            // }
                        ;}
    break;

  case 15:
#line 179 "mini_l.y"
    {
                            /*printf("statement -> IF bool_expr THEN statement SEMICOLON statements ENDIF\n");*/ 
                        ;}
    break;

  case 16:
#line 183 "mini_l.y"
    {
                            /*
                                printf("statement -> IF bool_expr THEN statement 
                                SEMICOLON statements ELSE statement SEMICOLON statements ENDIF\n");
                            */
                        ;}
    break;

  case 17:
#line 190 "mini_l.y"
    {
                            /*printf("statement -> WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP\n");*/
                        ;}
    break;

  case 18:
#line 194 "mini_l.y"
    {
                            /*printf("statement -> DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr\n");*/ 
                        ;}
    break;

  case 19:
#line 198 "mini_l.y"
    {
                            /*printf("statement ->  READ var vars\n");*/
                        ;}
    break;

  case 20:
#line 202 "mini_l.y"
    {
                            /*printf("statement -> WRITE var vars\n");*/
                        ;}
    break;

  case 21:
#line 206 "mini_l.y"
    {
                            /*printf("statement -> CONTINUE\n");*/
                        ;}
    break;

  case 22:
#line 210 "mini_l.y"
    {
                            /*printf("statement -> RETURN expression\n");*/
                        ;}
    break;

  case 23:
#line 216 "mini_l.y"
    {
                            /*printf("bool_expr -> relation_and_expr bool_expressions\n");*/
                        ;}
    break;

  case 24:
#line 222 "mini_l.y"
    {
                            /*printf("bool_expressions -> epsilon\n");*/
                        ;}
    break;

  case 25:
#line 226 "mini_l.y"
    {
                            /*printf("bool_expressions -> OR relation_and_expr bool_expressions\n");*/
                        ;}
    break;

  case 26:
#line 232 "mini_l.y"
    {
                                /*printf("relation_and_expr -> relation_expr relation_and_expressions\n");*/
                            ;}
    break;

  case 27:
#line 238 "mini_l.y"
    {
                                    /*printf("relation_and_expressions -> epsilon\n");*/
                                ;}
    break;

  case 28:
#line 242 "mini_l.y"
    {
                                    /*printf("relation_and_expressions -> AND relation_expr relation_and_expressions\n");*/
                                ;}
    break;

  case 29:
#line 247 "mini_l.y"
    {
                                    /*printf("relation_expr -> expression comp expression\n");*/
                                    //MISTAKE _EQ IS == NOT AN ASSIGNMENT!!!!!!!!!!!
                                    // switch ($2) {
                                    //     case _EQ: 
                                    //         if (exist(*($1)) && exist(*($3))) {
                                    //             genCode("=" + *($1) + ", " + *($3));
                                    //         } else {
                                    //             cerr << "Variable does not exist" << endl;
                                    //         }
                                    //         break;
                                    //     default: 
                                    //     //do nothing
                                    //         break;
                                    // }
                                        
                                ;}
    break;

  case 30:
#line 264 "mini_l.y"
    {/*printf("relation_expr -> TRUE\n");*/;}
    break;

  case 31:
#line 265 "mini_l.y"
    {/*printf("relation_expr -> FALSE\n");*/;}
    break;

  case 32:
#line 266 "mini_l.y"
    {/*printf("relation_expr -> L_PAREN bool_expr R_PAREN\n");*/;}
    break;

  case 33:
#line 267 "mini_l.y"
    {/*printf("relation_expr -> NOT expression comp expression\n");*/;}
    break;

  case 34:
#line 268 "mini_l.y"
    {/*printf("relation_expr -> NOT TRUE\n");*/;}
    break;

  case 35:
#line 269 "mini_l.y"
    {/*printf("relation_expr -> NOT FALSE\n");*/;}
    break;

  case 36:
#line 270 "mini_l.y"
    {/*printf("relation_expr -> NOT L_PAREN bool_expr R_PAREN\n");*/;}
    break;

  case 37:
#line 273 "mini_l.y"
    {/*printf("comp -> EQ\n");*/ (yyval.myInt) = _EQ;;}
    break;

  case 38:
#line 274 "mini_l.y"
    {/*printf("comp -> NEQ\n");*/ (yyval.myInt) =_NEQ;;}
    break;

  case 39:
#line 275 "mini_l.y"
    {/*printf("comp -> LT\n");*/ (yyval.myInt) = _LT;;}
    break;

  case 40:
#line 276 "mini_l.y"
    {/*printf("comp -> GT\n");*/ (yyval.myInt) = _GT;;}
    break;

  case 41:
#line 277 "mini_l.y"
    {/*printf("comp -> LTE\n");*/ (yyval.myInt) = _LTE;;}
    break;

  case 42:
#line 278 "mini_l.y"
    {/*printf("comp -> GTE\n");*/ (yyval.myInt) = _GTE;;}
    break;

  case 43:
#line 282 "mini_l.y"
    {
                            /*printf("expression -> multiplicative_expr expression_loop\n");*/

                            if (((yyvsp[(2) - (2)].myString))->compare("") != 0) {   //if an expression loop exists
                                //local vars
                                string code = *((yyvsp[(2) - (2)].myString));

                                //only applies to local code
                                code.insert(1, ", " + *((yyvsp[(1) - (2)].myString)));

                                //"return" code
                                (yyval.myString) = new string(code);
                            } else {                        //if expression loop does not exist; i.e. just a number
                                (yyval.myString) = (yyvsp[(1) - (2)].myString);
                            }
                        ;}
    break;

  case 44:
#line 301 "mini_l.y"
    {
                            /*printf("expression_loop -> epsilon\n");*/
                            (yyval.myString) = new string("");
                        ;}
    break;

  case 45:
#line 306 "mini_l.y"
    {
                            /*printf("expression_loop -> ADD multiplicative_expr expression_loop\n");*/

                            //declare base string to "return"
                            string base = (string) "+" +  (string) ", ";

                            if (((yyvsp[(3) - (3)].myString))->compare("") != 0) {   //expression loop is not epsilon
                                //store addition result into generated temp
                                string temp = newTemp();
                                //code returned by the loop that is NOT empty
                                string code = *((yyvsp[(3) - (3)].myString));
                                //need to add current $2 and $3 together and store in generated temp
                                code.insert(1, " " + temp + ", " + *((yyvsp[(2) - (3)].myString)));
                                //generate code
                                genCode(code);
                                //now "return" the base + temp
                                //value of expression generated above is in the generated temp
                                (yyval.myString) = new string(base + temp);
                            } else {                        //expression loop is epsilon
                                //"return" base + $2
                                (yyval.myString) = new string(base + *((yyvsp[(2) - (3)].myString)));
                            }
                        ;}
    break;

  case 46:
#line 330 "mini_l.y"
    {
                            /*printf("expression_loop -> SUB  multiplicative_expr expression_loop\n");*/

                            //declare base string to "return"
                            string base = (string) "-" +  (string) ", ";

                            if (((yyvsp[(3) - (3)].myString))->compare("") != 0) {   //expression loop is not epsilon
                                //store addition result into generated temp
                                string temp = newTemp();
                                //code returned by the loop that is NOT empty
                                string code = *((yyvsp[(3) - (3)].myString));
                                //need to add current $2 and $3 together and store in generated temp
                                code.insert(1, " " + temp + ", " + *((yyvsp[(2) - (3)].myString)));
                                //generate code
                                genCode(code);
                                //now "return" the base + temp
                                //value of expression generated above is in the generated temp
                                (yyval.myString) = new string(base + temp);
                            } else {                        //expression loop is epsilon
                                //"return" base + $2
                                (yyval.myString) = new string(base + *((yyvsp[(2) - (3)].myString)));
                            }
                        ;}
    break;

  case 47:
#line 357 "mini_l.y"
    {
                            /*printf("expressions -> expression COMMA expressions\n");*/

                            //not sure if this is right
                            (yyval.myString) = (yyvsp[(1) - (3)].myString);
                        ;}
    break;

  case 48:
#line 364 "mini_l.y"
    {
                            /*printf("expressions -> expression\n");*/
                            (yyval.myString) = (yyvsp[(1) - (1)].myString);
                        ;}
    break;

  case 49:
#line 369 "mini_l.y"
    {
                            /*printf("expressions -> epsilon\n");*/
                        ;}
    break;

  case 50:
#line 375 "mini_l.y"
    {
                            /*printf("terms -> epsilon\n");*/
                            (yyval.myString) = new string("");
                        ;}
    break;

  case 51:
#line 380 "mini_l.y"
    {
                            /*printf("terms -> MOD term terms\n");*/
                            string temp = (string) "%" + (string) ", " + *((yyvsp[(2) - (3)].myString));
                            (yyval.myString) = new string(temp);
                        ;}
    break;

  case 52:
#line 386 "mini_l.y"
    {
                            /*printf("terms -> DIV term terms\n");*/
                            string temp = (string) "/" + (string) ", " + *((yyvsp[(2) - (3)].myString));
                            (yyval.myString) = new string(temp);
                        ;}
    break;

  case 53:
#line 392 "mini_l.y"
    {
                            /*printf("terms -> MULT term terms\n");*/
                            string temp = (string) "*" + (string) ", " + *((yyvsp[(2) - (3)].myString));
                            (yyval.myString) = new string(temp);
                        ;}
    break;

  case 54:
#line 400 "mini_l.y"
    {
                                    /*printf("multiplicative_expr -> term terms\n");*/

                                    if (((yyvsp[(2) - (2)].myString))->compare("") != 0) {
                                        //local var
                                        string code = *((yyvsp[(2) - (2)].myString));

                                        //inserting code
                                        code.insert(1, ", " + *((yyvsp[(1) - (2)].myString)));

                                        //"return" statement
                                        (yyval.myString) = new string(code);
                                    } else {
                                        (yyval.myString) = (yyvsp[(1) - (2)].myString);
                                    }
                                ;}
    break;

  case 55:
#line 419 "mini_l.y"
    {
                            /*printf("term -> IDENT L_PAREN expressions R_PAREN\n");*/

                            /*
                                []= dst, index, src	
                            */

                            //temp is dest
                            string temp = newTemp();
                            //base string setup; source is $1; index is $3
                            string base = "[]= " + temp + ", " + *((yyvsp[(3) - (4)].myString)) + ", " + *((yyvsp[(1) - (4)].myString));
                            //generate code
                            genCode(base);
                            //"return" temp b/c it now stores the array value
                            (yyval.myString) = new string(temp);

                            undeclared(*((yyvsp[(1) - (4)].myString)));    
                        ;}
    break;

  case 56:
#line 438 "mini_l.y"
    {
                            /*printf("term -> NUMBER\n");*/

                            //generate temp
                            string temp = newTemp();
                            //generate the code to store $1 into temp
                            genCode("= " + temp + ", " + *((yyvsp[(1) - (1)].myString)));
                            //"return" temp b/c it now stores the number
                            (yyval.myString) = new string(temp);
                        ;}
    break;

  case 57:
#line 449 "mini_l.y"
    {
                            /*printf("term -> var\n");*/
                            if (!exist(*((yyvsp[(1) - (1)].myString)))) {        //if $1 isn't just an identifier
                                    
                            } else {
                                (yyval.myString) = (yyvsp[(1) - (1)].myString);
                            }
                        ;}
    break;

  case 58:
#line 458 "mini_l.y"
    {
                            /*printf("term -> L_PAREN expression R_PAREN\n");*/
                            (yyval.myString) = (yyvsp[(2) - (3)].myString);
                        ;}
    break;

  case 59:
#line 463 "mini_l.y"
    {
                            /*printf("term -> SUB NUMBER\n");*/

                            //have to static cast cause compiler optimizes to char* or something
                            (yyval.myString) = new string( (string) "-" + *((yyvsp[(2) - (2)].myString)) );
                        ;}
    break;

  case 60:
#line 470 "mini_l.y"
    {
                            /*printf("term -> SUB var\n");*/

                             (yyval.myString) = new string( (string) "-" + *((yyvsp[(2) - (2)].myString)) );
                        ;}
    break;

  case 61:
#line 476 "mini_l.y"
    {
                            /*printf("term -> SUB L_PAREN expression R_PAREN\n");*/

                             (yyval.myString) = new string( (string) "-" + *((yyvsp[(3) - (4)].myString)) );
                        ;}
    break;

  case 62:
#line 484 "mini_l.y"
    {
                            /*printf("var -> IDENT\n");*/
                            (yyval.myString) = (yyvsp[(1) - (1)].myString);
                            undeclared(*((yyvsp[(1) - (1)].myString)));
                        ;}
    break;

  case 63:
#line 490 "mini_l.y"
    {
                            /*printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");*/ 

                            //temp is dest
                            string temp = newTemp();
                            //base string setup; source is $1; index is $3
                            string base = temp + ", " + *((yyvsp[(1) - (4)].myString)) + ", " + *((yyvsp[(3) - (4)].myString));
                            //generate code
                            genCode(base);
                            //"return" temp b/c it now stores the array value
                            (yyval.myString) = new string(temp);

                            undeclared(*((yyvsp[(1) - (4)].myString)));
                        ;}
    break;

  case 64:
#line 506 "mini_l.y"
    {/*printf("vars -> epsilon\n");*/;}
    break;

  case 65:
#line 508 "mini_l.y"
    {
                        /*printf("vars -> COMMA var vars \n");*/
                        (yyval.myString) = (yyvsp[(2) - (3)].myString);
                    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2132 "mini_l.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 514 "mini_l.y"



void yyerror( string s ) {  // error handler routine
  extern int  yylineno;    // defined and maintained in lex.c
  extern char* yytext;     // defined and maintained in lex.c
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << currLine << " column " << currPos << endl;
  exit( 1 );
}

void yyerror( char* s ) { yyerror( string(s) ); }

