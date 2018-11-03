/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y" /* yacc.c:339  */

 #include <stdio.h>
 #include <stdlib.h>
 #include "header.h"
 
 extern int currLine;
 extern int currPos;
 extern char* yytext;     // defined and maintained in lex.c
 extern int yylex();
 extern void yyerror(char *);
 extern void yyerror(string);

#line 79 "mini_l.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mini_l.tab.h".  */
#ifndef YY_YY_MINI_L_TAB_H_INCLUDED
# define YY_YY_MINI_L_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "mini_l.y" /* yacc.c:355  */

    char *char_pointer;

#line 175 "mini_l.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINI_L_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 192 "mini_l.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   105,   105,   108,   109,   112,   116,   117,   120,   121,
     124,   125,   128,   129,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   143,   146,   147,   150,   153,   154,   156,
     157,   158,   159,   160,   161,   162,   163,   166,   167,   168,
     169,   170,   171,   174,   177,   178,   179,   183,   184,   185,
     188,   189,   190,   191,   194,   197,   198,   199,   200,   201,
     202,   203,   206,   207,   210,   211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "var", "vars", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,   149,  -110,    24,  -110,   137,  -109,   -27,   -26,
      43,    81,    45,    78,    91,   -10,   -25,    32,   -63,     1,
      -9,   -28,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    12,    14,   101,   102,    48,
      77,    49,    79,    50,    86,    51,    89,   107,    93,    52,
      53,    54,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
                  (unsigned long) yystacksize));

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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 105 "mini_l.y" /* yacc.c:1651  */
    {printf("program -> functions\n");}
#line 1378 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 3:
#line 108 "mini_l.y" /* yacc.c:1651  */
    {printf("functions -> epsilon\n");}
#line 1384 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 4:
#line 109 "mini_l.y" /* yacc.c:1651  */
    {printf("functions -> function functions\n");}
#line 1390 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 5:
#line 113 "mini_l.y" /* yacc.c:1651  */
    {printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY\n");}
#line 1396 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 6:
#line 116 "mini_l.y" /* yacc.c:1651  */
    {printf("declarations -> epsilon\n");}
#line 1402 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 7:
#line 117 "mini_l.y" /* yacc.c:1651  */
    {printf("declarations -> declaration SEMICOLON declarations\n");}
#line 1408 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 8:
#line 120 "mini_l.y" /* yacc.c:1651  */
    {printf("statements -> IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
#line 1414 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 9:
#line 121 "mini_l.y" /* yacc.c:1651  */
    {printf("statements -> IDENT idents COLON INTEGER\n");}
#line 1420 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 10:
#line 124 "mini_l.y" /* yacc.c:1651  */
    {printf("idents -> epsilon\n");}
#line 1426 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 11:
#line 125 "mini_l.y" /* yacc.c:1651  */
    {printf("idents -> COMMA IDENT idents\n");}
#line 1432 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 12:
#line 128 "mini_l.y" /* yacc.c:1651  */
    {printf("statements -> epsilon\n");}
#line 1438 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 13:
#line 129 "mini_l.y" /* yacc.c:1651  */
    {printf("statements -> statement SEMICOLON statements\n");}
#line 1444 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 14:
#line 132 "mini_l.y" /* yacc.c:1651  */
    {printf("statement -> var ASSIGN expression\n");}
#line 1450 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 15:
#line 133 "mini_l.y" /* yacc.c:1651  */
    {printf("statement -> IF bool_expr THEN statement SEMICOLON statements ENDIF\n"); }
#line 1456 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 16:
#line 134 "mini_l.y" /* yacc.c:1651  */
    {printf("statement -> IF bool_expr THEN statement SEMICOLON statements ELSE statement SEMICOLON statements ENDIF\n");}
#line 1462 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 17:
#line 135 "mini_l.y" /* yacc.c:1651  */
    {printf("statement -> WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP\n");}
#line 1468 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 18:
#line 136 "mini_l.y" /* yacc.c:1651  */
    {printf("statement -> DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr\n"); }
#line 1474 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 19:
#line 137 "mini_l.y" /* yacc.c:1651  */
    {printf("statement ->  READ var vars\n"); }
#line 1480 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 20:
#line 138 "mini_l.y" /* yacc.c:1651  */
    {printf("statement -> WRITE var vars\n");}
#line 1486 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 21:
#line 139 "mini_l.y" /* yacc.c:1651  */
    {printf("statement -> CONTINUE\n");}
#line 1492 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 22:
#line 140 "mini_l.y" /* yacc.c:1651  */
    {printf("statement -> RETURN expression\n");}
#line 1498 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 23:
#line 143 "mini_l.y" /* yacc.c:1651  */
    {printf("bool_expr -> relation_and_expr bool_expressions\n");}
#line 1504 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 24:
#line 146 "mini_l.y" /* yacc.c:1651  */
    {printf("bool_expressions -> epsilon\n");}
#line 1510 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 25:
#line 147 "mini_l.y" /* yacc.c:1651  */
    {printf("bool_expressions -> OR relation_and_expr bool_expressions\n");}
#line 1516 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 26:
#line 150 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_and_expr -> relation_expr relation_and_expressions\n");}
#line 1522 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 27:
#line 153 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_and_expressions -> epsilon\n");}
#line 1528 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 28:
#line 154 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_and_expressions -> AND relation_expr relation_and_expressions\n");}
#line 1534 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 29:
#line 156 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_expr -> expression comp expression\n");}
#line 1540 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 30:
#line 157 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_expr -> TRUE\n");}
#line 1546 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 31:
#line 158 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_expr -> FALSE\n");}
#line 1552 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 32:
#line 159 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_expr -> L_PAREN bool_expr R_PAREN\n");}
#line 1558 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 33:
#line 160 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_expr -> NOT expression comp expression\n");}
#line 1564 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 34:
#line 161 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_expr -> NOT TRUE\n");}
#line 1570 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 35:
#line 162 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_expr -> NOT FALSE\n");}
#line 1576 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 36:
#line 163 "mini_l.y" /* yacc.c:1651  */
    {printf("relation_expr -> NOT L_PAREN bool_expr R_PAREN\n");}
#line 1582 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 37:
#line 166 "mini_l.y" /* yacc.c:1651  */
    {printf("comp -> EQ\n");}
#line 1588 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 38:
#line 167 "mini_l.y" /* yacc.c:1651  */
    {printf("comp -> NEQ\n");}
#line 1594 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 39:
#line 168 "mini_l.y" /* yacc.c:1651  */
    {printf("comp -> LT\n");}
#line 1600 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 40:
#line 169 "mini_l.y" /* yacc.c:1651  */
    {printf("comp -> GT\n");}
#line 1606 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 41:
#line 170 "mini_l.y" /* yacc.c:1651  */
    {printf("comp -> LTE\n");}
#line 1612 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 42:
#line 171 "mini_l.y" /* yacc.c:1651  */
    {printf("comp -> GTE\n");}
#line 1618 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 43:
#line 174 "mini_l.y" /* yacc.c:1651  */
    {printf("expression -> multiplicative_expr expression_loop\n");}
#line 1624 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 44:
#line 177 "mini_l.y" /* yacc.c:1651  */
    {printf("expression_loop -> epsilon\n");}
#line 1630 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 45:
#line 178 "mini_l.y" /* yacc.c:1651  */
    {printf("expression_loop -> ADD multiplicative_expr expression_loop\n");}
#line 1636 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 46:
#line 179 "mini_l.y" /* yacc.c:1651  */
    {printf("expression_loop -> SUB  multiplicative_expr expression_loop\n");}
#line 1642 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 47:
#line 183 "mini_l.y" /* yacc.c:1651  */
    {printf("expressions -> expression COMMA expressions\n");}
#line 1648 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 48:
#line 184 "mini_l.y" /* yacc.c:1651  */
    {printf("expressions -> expression\n");}
#line 1654 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 49:
#line 185 "mini_l.y" /* yacc.c:1651  */
    {printf("expressions -> epsilon\n");}
#line 1660 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 50:
#line 188 "mini_l.y" /* yacc.c:1651  */
    {printf("terms -> epsilon\n");}
#line 1666 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 51:
#line 189 "mini_l.y" /* yacc.c:1651  */
    {printf("terms -> MOD term terms\n");}
#line 1672 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 52:
#line 190 "mini_l.y" /* yacc.c:1651  */
    {printf("terms -> DIV term terms\n");}
#line 1678 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 53:
#line 191 "mini_l.y" /* yacc.c:1651  */
    {printf("terms -> MULT term terms\n");}
#line 1684 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 54:
#line 194 "mini_l.y" /* yacc.c:1651  */
    {printf("multiplicative_expr -> term terms\n");}
#line 1690 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 55:
#line 197 "mini_l.y" /* yacc.c:1651  */
    {printf("term -> IDENT L_PAREN expressions R_PAREN\n");}
#line 1696 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 56:
#line 198 "mini_l.y" /* yacc.c:1651  */
    {printf("term -> NUMBER\n");}
#line 1702 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 57:
#line 199 "mini_l.y" /* yacc.c:1651  */
    {printf("term -> var\n");}
#line 1708 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 58:
#line 200 "mini_l.y" /* yacc.c:1651  */
    {printf("term -> L_PAREN expression R_PAREN\n");}
#line 1714 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 59:
#line 201 "mini_l.y" /* yacc.c:1651  */
    {printf("term -> SUB NUMBER\n");}
#line 1720 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 60:
#line 202 "mini_l.y" /* yacc.c:1651  */
    {printf("term -> SUB var\n");}
#line 1726 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 61:
#line 203 "mini_l.y" /* yacc.c:1651  */
    {printf("term -> SUB L_PAREN expression R_PAREN\n");}
#line 1732 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 62:
#line 206 "mini_l.y" /* yacc.c:1651  */
    {printf("var -> IDENT\n");}
#line 1738 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 63:
#line 207 "mini_l.y" /* yacc.c:1651  */
    {printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
#line 1744 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 64:
#line 210 "mini_l.y" /* yacc.c:1651  */
    {printf("vars -> epsilon\n");}
#line 1750 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 65:
#line 211 "mini_l.y" /* yacc.c:1651  */
    {printf("vars -> COMMA var vars \n");}
#line 1756 "mini_l.tab.c" /* yacc.c:1651  */
    break;


#line 1760 "mini_l.tab.c" /* yacc.c:1651  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 214 "mini_l.y" /* yacc.c:1910  */



void yyerror( string s ) {  // error handler routine
  extern int  yylineno;    // defined and maintained in lex.c
  extern char* yytext;     // defined and maintained in lex.c
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << currLine << " column " << currPos << endl;
  exit( 1 );
}

void yyerror( char* s ) { yyerror( string(s) ); }
