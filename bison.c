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
#line 2 "mini_l.y" /* yacc.c:339  */

    #include "header.h"
    //  void yyerror(const char *msg);
    extern int currLine;
    extern int currPos;

#line 73 "mini_l.tab.c" /* yacc.c:339  */

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
#line 9 "mini_l.y" /* yacc.c:355  */

    string *myType;

#line 169 "mini_l.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINI_L_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "mini_l.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    92,    92,    95,    96,    99,   102,   103,   106,   107,
     108,   111,   112,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   126,   127,   130,   131,   134,   135,   136,   137,
     138,   139,   140,   141,   144,   145,   146,   147,   148,   149,
     152,   153,   154,   157,   158,   161,   162,   163,   164,   167,
     168,   169,   170,   171,   172,   173,   176,   177,   179,   180,
     183,   183
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
  "L_PAREN", "R_PAREN", "\";\"", "$accept", "program", "functions",
  "function", "declarations", "declaration", "statements", "statement",
  "bool_expr", "relation_and_expr", "relation_expr", "comp", "expression",
  "expressions", "multiplicative_expr", "term", "var", "vars", "epsilon", YY_NULLPTR
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
     305,   306,   307
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,     2,   -65,     8,   -65,     1,   -65,   -19,   -65,   -65,
      36,   -16,    51,    19,    31,   -65,    27,    84,    42,   -16,
     -65,    12,   -11,   -11,    47,   -65,    -6,    -6,    15,    45,
     -65,    40,    75,   -65,   109,   -65,    87,    89,   -65,   -65,
     -28,   -65,    41,    28,   112,    97,   103,   114,    53,    43,
     -65,   111,    84,    95,   -65,   -65,   -65,    90,   -65,    15,
      84,    15,   -16,    85,   -65,   -65,    28,   114,    15,   -65,
      90,   -65,    82,   108,    86,   -65,    84,   -11,   -11,   -65,
     -65,   -65,   -65,   -65,   -65,    15,    15,    15,    15,    15,
      15,    84,   115,    -6,   105,    94,   -65,   -65,   124,   145,
     107,    15,   110,   113,   -65,    90,   -65,    83,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   139,   143,   -65,   -65,
     155,   153,   -65,   -65,   -65,   -65,   -65,   -65,    84,   -65,
     -11,   157,   -65,   151,   -65,    84,   -65,   135,   159,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      60,     0,    61,     0,     2,    60,     4,     0,     1,     3,
       0,    60,     0,     0,     0,     7,     0,    60,     0,    60,
      10,     0,     0,     0,     0,    20,    60,    60,     0,    56,
       8,     0,     0,    12,     0,     6,     0,     0,    27,    28,
      56,    50,     0,    60,     0,    22,    24,     0,    40,    45,
      51,     0,    60,     0,    18,    59,    19,    60,    21,     0,
      60,     0,    60,     0,    31,    32,    60,     0,     0,    53,
      60,    54,     0,     0,     0,    44,    60,     0,     0,    35,
      34,    39,    37,    38,    36,     0,     0,     0,     0,     0,
       0,    60,     0,    60,     0,     0,    11,    13,     0,     0,
       0,     0,     0,     0,    29,    60,    52,     0,    23,    25,
      26,    41,    42,    46,    47,    48,     0,     0,    58,    57,
       0,     0,    33,    30,    49,    55,    43,    14,    60,    16,
       0,     0,     9,     0,    17,    60,    15,     0,     0,     5
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   164,   -65,   -14,   -65,   -49,   -65,   -22,    93,
      96,   104,    24,   -64,    17,   -60,   -17,   -25,     7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    14,    30,    31,    44,    45,
      46,    85,    47,    74,    48,    49,    50,    54,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    51,    56,    92,     1,    35,   103,     6,     8,    53,
      53,    96,     6,    10,    12,    37,    38,    39,    15,    40,
      59,    72,    68,    41,    29,    71,    15,   107,   113,   114,
     115,    42,     7,    55,    55,    32,     2,    20,    21,    43,
      11,   126,   116,    32,   100,    40,     2,    34,    98,    41,
      75,    18,    58,     2,    37,    38,    39,    42,    40,    32,
      36,    67,    41,    19,    75,    57,    52,    73,   118,    15,
      42,    29,    60,    75,    32,    69,    53,    75,    43,   133,
       2,    94,    16,    95,    17,    97,   137,    88,    89,    90,
      73,    70,   102,    59,    94,    86,    87,    22,   127,   128,
      55,    23,    24,   111,   112,    25,    26,    27,   134,   110,
      61,    32,    75,    28,    29,    62,    64,    65,    32,    40,
      40,    63,    77,    41,    41,   123,    76,    78,    93,    94,
      91,    42,    42,   104,    99,   117,     2,   106,   105,    66,
      57,   105,     2,   119,    79,    80,    81,    82,    83,    84,
      79,    80,    81,    82,    83,    84,   120,   121,   122,   129,
     130,   124,   131,   132,   125,   135,   136,   138,   139,     9,
     108,   101,     0,     0,   109
};

static const yytype_int16 yycheck[] =
{
      17,    23,    27,    52,     3,    19,    70,     0,     0,    26,
      27,    60,     5,    32,    30,    26,    27,    28,    11,    30,
      48,    43,    50,    34,    30,    42,    19,    76,    88,    89,
      90,    42,    30,    26,    27,    52,    52,    10,    11,    50,
       4,   105,    91,    60,    66,    30,    52,     5,    62,    34,
      43,    32,    28,    52,    26,    27,    28,    42,    30,    76,
      48,    37,    34,    32,    57,    50,    19,    43,    93,    62,
      42,    30,    32,    66,    91,    34,    93,    70,    50,   128,
      52,    57,    31,    59,    33,    61,   135,    44,    45,    46,
      66,    50,    68,    48,    70,    42,    43,    13,    15,    16,
      93,    17,    18,    86,    87,    21,    22,    23,   130,    85,
      35,   128,   105,    29,    30,     6,    27,    28,   135,    30,
      30,    34,    25,    34,    34,   101,    14,    24,    33,   105,
      19,    42,    42,    51,    49,    20,    52,    51,    33,    50,
      50,    33,    52,    49,    36,    37,    38,    39,    40,    41,
      36,    37,    38,    39,    40,    41,    32,    12,    51,    20,
      17,    51,     7,    10,    51,     8,    15,    32,     9,     5,
      77,    67,    -1,    -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    54,    55,    56,    71,    30,     0,    55,
      32,     4,    30,    57,    58,    71,    31,    33,    32,    32,
      10,    11,    13,    17,    18,    21,    22,    23,    29,    30,
      59,    60,    69,    71,     5,    57,    48,    26,    27,    28,
      30,    34,    42,    50,    61,    62,    63,    65,    67,    68,
      69,    61,    19,    69,    70,    71,    70,    50,    65,    48,
      32,    35,     6,    34,    27,    28,    50,    65,    50,    34,
      50,    69,    61,    65,    66,    71,    14,    25,    24,    36,
      37,    38,    39,    40,    41,    64,    42,    43,    44,    45,
      46,    19,    59,    33,    65,    65,    59,    65,    57,    49,
      61,    64,    65,    66,    51,    33,    51,    59,    62,    63,
      65,    67,    67,    68,    68,    68,    59,    20,    70,    49,
      32,    12,    51,    65,    51,    51,    66,    15,    16,    20,
      17,     7,    10,    59,    61,     8,    15,    59,    32,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    57,    57,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,    15,     3,     1,     3,     8,
       3,     3,     1,     3,     5,     7,     5,     6,     2,     2,
       1,     2,     1,     3,     1,     3,     3,     1,     1,     3,
       4,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     1,     3,     3,     3,     4,
       1,     1,     3,     2,     2,     4,     1,     4,     3,     1,
       0,     1
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
#line 92 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) =  "program -> functions";}
#line 1364 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 3:
#line 95 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "function -> functions";}
#line 1370 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 4:
#line 96 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "function -> epsilon";}
#line 1376 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 5:
#line 99 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "function -> long rule";}
#line 1382 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 6:
#line 102 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "declarations -> declaration SEMICOLON declarations";}
#line 1388 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 7:
#line 103 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "declarations -> epsilon";}
#line 1394 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 8:
#line 106 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statements -> IDENT COMMA statements";}
#line 1400 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 9:
#line 107 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statements -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER";}
#line 1406 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 10:
#line 108 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statements -> IDENT COLON INTEGER";}
#line 1412 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 11:
#line 111 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statements -> statement SEMICOLON statements";}
#line 1418 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 12:
#line 112 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statements -> epsilon";}
#line 1424 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 13:
#line 115 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement -> var ASSIGN expression";}
#line 1430 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 14:
#line 116 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement -> IF bool_expr THEN statements ENDIF";}
#line 1436 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 15:
#line 117 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement -> IF bool_expr THEN statements ELSE statements ENDIF";}
#line 1442 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 16:
#line 118 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement -> WHILE bool_expr BEGINLOOP statements ENDLOOP";}
#line 1448 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 17:
#line 119 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_expr";}
#line 1454 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 18:
#line 120 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement ->  READ vars";}
#line 1460 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 19:
#line 121 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement -> WRITE vars";}
#line 1466 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 20:
#line 122 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement -> CONTINUE";}
#line 1472 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 21:
#line 123 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "statement -> RETURN expression";}
#line 1478 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 22:
#line 126 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "bool_expr -> relation_and_expr";}
#line 1484 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 23:
#line 127 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "bool_expr -> relation_and_expr OR relation_and_expr";}
#line 1490 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 24:
#line 130 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_and_expr -> relation_expr";}
#line 1496 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 25:
#line 131 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_and_expr -> relation_expr AND relation_expr";}
#line 1502 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 26:
#line 134 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_expr -> expression comp expression";}
#line 1508 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 27:
#line 135 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_expr -> TRUE";}
#line 1514 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 28:
#line 136 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_expr -> FALSE";}
#line 1520 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 29:
#line 137 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_expr -> L_PAREN bool_expr R_PAREN";}
#line 1526 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 30:
#line 138 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_expr -> NOT expression comp expression";}
#line 1532 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 31:
#line 139 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_expr -> NOT TRUE";}
#line 1538 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 32:
#line 140 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_expr -> NOT FALSE";}
#line 1544 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 33:
#line 141 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "relation_expr -> NOT L_PAREN bool_expr R_PAREN";}
#line 1550 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 34:
#line 144 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "comp -> EQ";}
#line 1556 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 35:
#line 145 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "comp -> NEQ";}
#line 1562 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 36:
#line 146 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "comp -> LT";}
#line 1568 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 37:
#line 147 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "comp -> GT";}
#line 1574 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 38:
#line 148 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "comp -> LTE";}
#line 1580 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 39:
#line 149 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "comp -> GTE";}
#line 1586 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 40:
#line 152 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "expression -> multiplicative_expr";}
#line 1592 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 41:
#line 153 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "expression -> multiplicative_expr SUB multiplicative_expr";}
#line 1598 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 42:
#line 154 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "expression -> multiplicative_expr ADD multiplicative_expr";}
#line 1604 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 43:
#line 157 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "expressions -> expression COMMA expressions";}
#line 1610 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 44:
#line 158 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "expressions -> epsilon";}
#line 1616 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 45:
#line 161 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "multiplicative_expr -> term";}
#line 1622 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 46:
#line 162 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "multiplicative_expr -> term MOD term";}
#line 1628 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 47:
#line 163 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "multiplicative_expr -> term DIV term";}
#line 1634 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 48:
#line 164 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "multiplicative_expr -> term MULT term";}
#line 1640 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 49:
#line 167 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "term -> IDENT L_PAREN expression R_PAREN";}
#line 1646 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 50:
#line 168 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "term -> NUMBER";}
#line 1652 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 51:
#line 169 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "term -> var";}
#line 1658 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 52:
#line 170 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "term -> L_PAREN expressions R_PAREN";}
#line 1664 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 53:
#line 171 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "term -> SUB NUMBER";}
#line 1670 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 54:
#line 172 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "term -> SUB var";}
#line 1676 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 55:
#line 173 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "term -> SUB L_PAREN expressions R_PAREN";}
#line 1682 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 56:
#line 176 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "var -> IDENT";}
#line 1688 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 57:
#line 177 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET";}
#line 1694 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 58:
#line 179 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "vars -> var COMMA vars";}
#line 1700 "mini_l.tab.c" /* yacc.c:1651  */
    break;

  case 59:
#line 180 "mini_l.y" /* yacc.c:1651  */
    {(yyval.myType) = "vars -> epsilon";}
#line 1706 "mini_l.tab.c" /* yacc.c:1651  */
    break;


#line 1710 "mini_l.tab.c" /* yacc.c:1651  */
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
#line 185 "mini_l.y" /* yacc.c:1910  */


int main(int argc, char **argv) {
    // extern char* yytext;    //defined and maintained in lex.c
    // if (argc > 1) {
    //     yyin = fopen(argv[1], "r");
    //     if (yyin == NULL){
    //         printf("syntax: %s filename\n", argv[0]);
    //     }//end if
    // }//end if
    yyparse(); // Calls yylex() for tokens.
    // //where do I get s from?
    // cerr << "ERROR:" + s + " at symbol " + yytext + " on line ";
    return 0;
}

// int yyerror(char *s) {
//     return yyerror(string(s));
// }
