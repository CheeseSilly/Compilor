/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "./src/SyntaxPl0.y"

/*
Date: 2024.11.23
Author: CheeseSilly
ALL RIGHTS DESERVED
 */

#include"./head/main.h"

FILE *fi;
FILE *fh;
extern int column;
extern int row;
Node* Root;

extern void yyerror(char const* s);
extern int yylex(void);
int yyrestart();


/* Line 371 of yacc.c  */
#line 89 "SyntaxPl0.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "SyntaxPl0.tab.h".  */
#ifndef YY_YY_SYNTAXPL0_TAB_H_INCLUDED
# define YY_YY_SYNTAXPL0_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER_VAL = 258,
     IDENTIFIER = 259,
     PROCEDURE = 260,
     IF = 261,
     THEN = 262,
     ELSE = 263,
     WHILE = 264,
     DO = 265,
     READ = 266,
     WRITE = 267,
     CALL = 268,
     _BEGIN_ = 269,
     END = 270,
     CONST = 271,
     VAR = 272,
     ODD = 273,
     SL_PAREN = 274,
     SR_PAREN = 275,
     COMMA = 276,
     COLON = 277,
     SEMI = 278,
     DOT = 279,
     PLUS = 280,
     MINUS = 281,
     TIMES = 282,
     DIVIDE = 283,
     ASSIGN = 284,
     EQUAL = 285,
     LESS = 286,
     GREATER = 287,
     NOTEQUAL = 288,
     GREATER_EQUAL = 289,
     LESS_EQUAL = 290,
     LOWER_THAN_ELSE = 291
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 23 "./src/SyntaxPl0.y"

    struct Node* node;


/* Line 387 of yacc.c  */
#line 173 "SyntaxPl0.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_SYNTAXPL0_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 201 "SyntaxPl0.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    16,    19,    23,
      26,    28,    30,    35,    39,    43,    45,    49,    52,    54,
      58,    62,    64,    66,    69,    75,    77,    79,    83,    88,
      92,    94,    96,    98,   100,   102,   104,   106,   111,   113,
     115,   119,   123,   126,   130,   134,   137,   139,   141,   143,
     145,   147,   149,   154,   161,   165,   169,   172,   175,   177,
     181,   185,   187,   189,   191,   195,   200,   203,   209,   213,
     215,   217,   222,   226,   228,   230,   235,   239,   241
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    24,    -1,    40,    52,    -1,    52,
      -1,    41,    -1,    41,    44,    -1,    41,    50,    -1,    41,
      44,    50,    -1,    44,    50,    -1,    44,    -1,    50,    -1,
      41,    16,    42,    23,    -1,    16,    42,    23,    -1,    42,
      21,    43,    -1,    43,    -1,     4,    30,     3,    -1,    44,
      45,    -1,    45,    -1,    17,    46,    23,    -1,    46,    21,
      47,    -1,    47,    -1,     4,    -1,     4,    48,    -1,    19,
      49,    22,    49,    20,    -1,     3,    -1,     4,    -1,    51,
      39,    23,    -1,    50,    51,    39,    23,    -1,     5,     4,
      23,    -1,    55,    -1,    56,    -1,    60,    -1,    64,    -1,
      65,    -1,    68,    -1,    71,    -1,     4,    19,    54,    20,
      -1,     4,    -1,    61,    -1,    53,    29,    61,    -1,    14,
      57,    15,    -1,    52,    23,    -1,    57,    52,    23,    -1,
      61,    59,    61,    -1,    18,    61,    -1,    30,    -1,    33,
      -1,    31,    -1,    32,    -1,    35,    -1,    34,    -1,     6,
      58,     7,    52,    -1,     6,    58,     7,    52,     8,    52,
      -1,    61,    25,    62,    -1,    61,    26,    62,    -1,    25,
      62,    -1,    26,    62,    -1,    62,    -1,    62,    27,    63,
      -1,    62,    28,    63,    -1,    63,    -1,    53,    -1,     3,
      -1,    19,    61,    20,    -1,     9,    58,    10,    52,    -1,
      13,     4,    -1,    13,     4,    19,    66,    20,    -1,    66,
      21,    67,    -1,    67,    -1,    61,    -1,    11,    19,    69,
      20,    -1,    69,    21,    70,    -1,    70,    -1,    53,    -1,
      12,    19,    72,    20,    -1,    72,    21,    73,    -1,    73,
      -1,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    51,    55,    61,    66,    71,    76,    81,
      86,    91,    97,   102,   108,   113,   119,   126,   131,   138,
     144,   149,   156,   161,   168,   184,   189,   196,   201,   207,
     237,   242,   247,   252,   257,   262,   267,   274,   279,   285,
     291,   299,   306,   311,   318,   323,   329,   334,   339,   344,
     349,   354,   360,   365,   371,   377,   383,   389,   395,   402,
     408,   414,   421,   427,   433,   440,   446,   451,   457,   462,
     468,   473,   479,   484,   490,   497,   503,   508,   514
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_VAL", "IDENTIFIER", "PROCEDURE",
  "IF", "THEN", "ELSE", "WHILE", "DO", "READ", "WRITE", "CALL", "_BEGIN_",
  "END", "CONST", "VAR", "ODD", "SL_PAREN", "SR_PAREN", "COMMA", "COLON",
  "SEMI", "DOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQUAL",
  "LESS", "GREATER", "NOTEQUAL", "GREATER_EQUAL", "LESS_EQUAL",
  "LOWER_THAN_ELSE", "$accept", "Program", "SubPro", "DeclarePart",
  "ConstDec", "ConstDef", "CDefine", "VarDec", "VarObj", "IdentiDef",
  "IdentiObject", "Array", "ArrayIndex", "ProDec", "ProceHead",
  "Statements", "Identifier", "INdex_Index", "AssignStm", "ComplexStm",
  "ComStates", "Condition", "CMP", "CondiStm", "Expr", "Term", "Factor",
  "WhileStm", "CallS", "Ccontent", "CconObj", "ReadS", "Rcontent",
  "RconObj", "WriteS", "Wcontent", "WconObj", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    40,    41,    41,    42,    42,    43,    44,    44,    45,
      46,    46,    47,    47,    48,    49,    49,    50,    50,    51,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      55,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    62,
      62,    62,    63,    63,    63,    64,    65,    65,    66,    66,
      67,    68,    69,    69,    70,    71,    72,    72,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     2,     2,     3,     2,
       1,     1,     4,     3,     3,     1,     3,     2,     1,     3,
       3,     1,     1,     2,     5,     1,     1,     3,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       3,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     6,     3,     3,     2,     2,     1,     3,
       3,     1,     1,     1,     3,     4,     2,     5,     3,     1,
       1,     4,     3,     1,     1,     4,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,    10,    18,    11,     0,     4,
       0,    30,    31,    32,    33,    34,    35,    36,     0,     0,
      63,     0,     0,     0,     0,    62,     0,     0,    58,    61,
       0,     0,     0,    66,     0,     0,     0,     0,    15,    22,
       0,    21,     1,     2,     3,     0,     6,     7,    17,     9,
       0,     0,     0,     0,    39,    29,    45,     0,    56,    57,
       0,     0,     0,    46,    48,    49,    47,    51,    50,     0,
       0,     0,     0,    74,     0,    73,    78,     0,    77,     0,
      42,    41,     0,     0,     0,    13,     0,    23,     0,    19,
       0,     8,     0,    27,    40,    37,    64,    52,    54,    55,
      44,    59,    60,    65,    71,     0,    75,     0,    70,     0,
      69,    43,    16,    14,    25,    26,     0,    20,    12,    28,
       0,    72,    76,    67,     0,     0,    53,    68,     0,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    47,    48,    15,    16,    50,
      51,    97,   126,    17,    18,    19,    35,    63,    21,    22,
      45,    36,    79,    23,    37,    38,    39,    24,    25,   119,
     120,    26,    84,    85,    27,    87,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -20
static const yytype_int16 yypact[] =
{
      67,   -16,     5,     8,     8,    16,    24,    65,   115,    70,
      87,   112,    89,   115,    12,    19,   -20,   109,    67,   -20,
      88,   -20,   -20,   -20,   -20,   -20,   -20,   -20,    36,    93,
     -20,    36,    36,    18,    18,   -20,   111,    76,     4,   -20,
     110,   121,    36,   113,   108,    81,   103,     2,   -20,   116,
      33,   -20,   -20,   -20,   -20,    70,    19,   109,   -20,   109,
      67,   114,    36,   118,    22,   -20,    22,    39,     4,     4,
     115,    18,    18,   -20,   -20,   -20,   -20,   -20,   -20,    36,
      18,    18,   115,   -20,    37,   -20,    22,    68,   -20,    36,
     -20,   -20,   117,   131,    70,   -20,    94,   -20,    87,   -20,
      45,   109,   119,   -20,    22,   -20,   -20,   128,     4,     4,
      22,   -20,   -20,   -20,   -20,   121,   -20,    36,    22,    79,
     -20,   -20,   -20,   -20,   -20,   -20,   122,   -20,   -20,   -20,
     115,   -20,   -20,   -20,    36,    94,   -20,   -20,   123,   -20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -20,   -20,   -11,   -20,   -20,    84,    47,   132,    -5,   -20,
      49,   -20,    10,   -10,   -15,    -7,     0,   -20,   -20,   -20,
     -20,   144,   -20,   -20,   -12,   -19,    23,   -20,   -20,   -20,
      15,   -20,   -20,    35,   -20,   -20,    34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    44,    60,    28,    57,    59,    54,    61,    20,    29,
      58,    30,     1,    20,    68,    69,    64,     2,    20,    66,
      67,    30,     1,    94,     2,    95,    31,    32,    55,    10,
      86,    80,    81,    33,    34,    41,    10,    32,    92,    30,
       1,    83,    60,    42,    60,    20,   101,    71,    72,   102,
     104,    58,   108,   109,    98,    32,    99,   114,   115,   106,
      20,    33,    34,   107,    71,    72,    94,   110,   128,    43,
      20,     1,     2,     3,    46,   113,     4,   118,     5,     6,
       7,     8,    20,     9,    10,     1,    60,     3,   116,   117,
       4,    49,     5,     6,     7,     8,    91,   124,   125,   133,
     134,    71,    72,   111,   112,    86,    73,    74,    75,    76,
      77,    78,    52,    53,     2,    83,    65,    62,    70,     1,
      82,     3,   118,   136,     4,     1,     5,     6,     7,     8,
      20,    90,    89,    93,   122,    96,   130,   103,   105,   100,
     121,   123,   129,   139,   135,   138,    56,   127,    40,   137,
     131,   132
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-20)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
       0,     8,    17,    19,    14,    15,    13,    18,     8,     4,
      15,     3,     4,    13,    33,    34,    28,     5,    18,    31,
      32,     3,     4,    21,     5,    23,    18,    19,    16,    17,
      42,    27,    28,    25,    26,    19,    17,    19,    45,     3,
       4,    41,    57,    19,    59,    45,    56,    25,    26,    60,
      62,    56,    71,    72,    21,    19,    23,    20,    21,    20,
      60,    25,    26,    70,    25,    26,    21,    79,    23,     4,
      70,     4,     5,     6,     4,    82,     9,    89,    11,    12,
      13,    14,    82,    16,    17,     4,   101,     6,    20,    21,
       9,     4,    11,    12,    13,    14,    15,     3,     4,    20,
      21,    25,    26,    80,    81,   117,    30,    31,    32,    33,
      34,    35,     0,    24,     5,   115,    23,    29,     7,     4,
      10,     6,   134,   130,     9,     4,    11,    12,    13,    14,
     130,    23,    19,    30,     3,    19,     8,    23,    20,    55,
      23,    94,    23,    20,    22,   135,    14,    98,     4,   134,
     115,   117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     9,    11,    12,    13,    14,    16,
      17,    38,    39,    40,    41,    44,    45,    50,    51,    52,
      53,    55,    56,    60,    64,    65,    68,    71,    19,     4,
       3,    18,    19,    25,    26,    53,    58,    61,    62,    63,
      58,    19,    19,     4,    52,    57,     4,    42,    43,     4,
      46,    47,     0,    24,    52,    16,    44,    50,    45,    50,
      51,    39,    29,    54,    61,    23,    61,    61,    62,    62,
       7,    25,    26,    30,    31,    32,    33,    34,    35,    59,
      27,    28,    10,    53,    69,    70,    61,    72,    73,    19,
      23,    15,    52,    30,    21,    23,    19,    48,    21,    23,
      42,    50,    39,    23,    61,    20,    20,    52,    62,    62,
      61,    63,    63,    52,    20,    21,    20,    21,    61,    66,
      67,    23,     3,    43,     3,     4,    49,    47,    23,    23,
       8,    70,    73,    20,    21,    22,    52,    67,    49,    20
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
/* Line 1792 of yacc.c  */
#line 45 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Program -> SubPro DOT\n");  
                fprintf(fh,"Program -> SubPro DOT\n");
                (yyval.node)=createNode("Program","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));Root=(yyval.node);  
                  }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 51 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"SubPro -> DeclarePart Statement\n");  
                fprintf(fh,"SubPro -> DeclarePart Statement\n");
                (yyval.node)=createNode("SubPro","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 55 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"SubPro -> Statement\n");  
                fprintf(fh,"SubPro -> Statement\n");
                (yyval.node)=createNode("SubPro","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));  
            }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 61 "./src/SyntaxPl0.y"
    {
                  fprintf(fi,"DeclarePart -> ConstDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec\n");
                  (yyval.node)=createNode("DeclarePart","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 66 "./src/SyntaxPl0.y"
    {
                  fprintf(fi,"DeclarePart -> ConstDec VarDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec\n");
                  (yyval.node)=createNode("DeclarePart","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
            }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 71 "./src/SyntaxPl0.y"
    {
                  fprintf(fi,"DeclarePart -> ConstDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec ProDec\n");
                  (yyval.node)=createNode("DeclarePart","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
            }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 76 "./src/SyntaxPl0.y"
    {
                  fprintf(fi,"DeclarePart -> ConstDec VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec ProDec\n");
                  (yyval.node)=createNode("DeclarePart","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
            }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 81 "./src/SyntaxPl0.y"
    {
                  fprintf(fi,"DeclarePart -> VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> VarDec ProDec\n");
                  (yyval.node)=createNode("DeclarePart","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
            }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 86 "./src/SyntaxPl0.y"
    {
                  fprintf(fi,"DeclarePart -> VarDec\n");
                  fprintf(fh,"DeclarePart -> VarDec\n");
                  (yyval.node)=createNode("DeclarePart","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 91 "./src/SyntaxPl0.y"
    {
                  fprintf(fi,"DeclarePart -> ProDec\n");
                  fprintf(fh,"DeclarePart -> ProDec\n");
                  (yyval.node)=createNode("DeclarePart","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 97 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ConstDec -> ConstDec const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> ConstDec const ConstDef SEMI\n");
                (yyval.node)=createNode("ConstDec","");addNode(4, (yyval.node), (yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
                  }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 102 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ConstDec -> const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> const ConstDef SEMI\n");
                (yyval.node)=createNode("ConstDec","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                  }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 108 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ConstDef -> ConstDef , CDefine\n"); 
                fprintf(fh,"ConstDef -> ConstDef , CDefine\n");
                (yyval.node)=createNode("ConstDef","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                 }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 113 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ConstDef -> CDefine\n"); 
                fprintf(fh,"ConstDef -> CDefine\n");
                (yyval.node)=createNode("ConstDef","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 119 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CDefine -> IDENTIFIER = INTEGER_VAL\n");
                fprintf(fh,"CDefine -> IDENTIFIER = INTEGER_VAL\n");
                (yyval.node)=createNode("CDefine","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 126 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"VarDec -> VarDec VarObj\n");
                fprintf(fh,"VarDec -> VarDec VarObj\n");
                (yyval.node)=createNode("VarDec","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
                }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 131 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"VarDec -> VarObj\n");
                fprintf(fh,"VarDec -> VarObj\n");
                (yyval.node)=createNode("VarDec","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                
            }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 138 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"VarObj -> var IdentiDef SEMI\n"); 
                fprintf(fh,"VarObj -> var IdentiDef SEMI\n");
                (yyval.node)=createNode("VarObj","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                 }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 144 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"IdentiDef -> IdentiDef , IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiDef , IdentiObject\n"); 
                (yyval.node)=createNode("IdentiDef","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
            }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 149 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"IdentiDef -> IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiObject\n"); 
                (yyval.node)=createNode("IdentiDef","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 156 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"IdentiObject -> IDENTIFIER\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER\n");
                (yyval.node)=createNode("IdentiObject","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 161 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"IdentiObject -> IDENTIFIER Array\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER Array\n");
                (yyval.node)=createNode("IdentiObject","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
            }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 168 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Array -> SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN\n");
                fprintf(fh,"Array -> SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN\n");
                (yyval.node)=createNode("Array","");addNode(5, (yyval.node), (yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));
            }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 184 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ArrayIndex -> INTEGER_VAL\n");
                fprintf(fh,"ArrayIndex -> INTEGER_VAL\n");
                (yyval.node)=createNode("ArrayIndex","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 189 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ArrayIndex -> IDENTIFIER\n");
                fprintf(fh,"ArrayIndex -> IDENTIFIER\n");
                (yyval.node)=createNode("ArrayIndex","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 196 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ProDec -> ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProceHead SubPro SEMI\n"); 
                (yyval.node)=createNode("ProDec","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
            }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 201 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
                (yyval.node)=createNode("ProDec","");addNode(4, (yyval.node), (yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
            }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 207 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ProceHead -> procedure IDENTIFIER SEMI\n");
                fprintf(fh,"ProceHead -> procedure IDENTIFIER SEMI\n");
                (yyval.node)=createNode("ProceHead","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
            }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 237 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Statements -> AssignStm \n");
                fprintf(fh,"Statements -> AssignStm \n");
                (yyval.node)=createNode("Statements","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 242 "./src/SyntaxPl0.y"
    { 
                fprintf(fi,"Statements -> ComplexStm\n");
                fprintf(fh,"Statements -> ComplexStm\n");
                (yyval.node)=createNode("Statements","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 247 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Statements -> CondiStm\n"); 
                fprintf(fh,"Statements -> CondiStm\n");
                (yyval.node)=createNode("Statements","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 252 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Statements -> WhileStm \n");
                fprintf(fh,"Statements -> WhileStm \n");
                (yyval.node)=createNode("Statements","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 257 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Statements -> CallS \n");
                fprintf(fh,"Statements -> CallS \n");
                (yyval.node)=createNode("Statements","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 262 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Statements -> ReadS \n"); 
                fprintf(fh,"Statements -> ReadS \n");
                (yyval.node)=createNode("Statements","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 267 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Statements -> WriteS \n");
                fprintf(fh,"Statements -> WriteS \n");
                (yyval.node)=createNode("Statements","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 274 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Identifier -> IDENTIFIER SL_PAREN INdex_Index SR_PAREN\n");
                fprintf(fh,"Identifier -> IDENTIFIER SL_PAREN INdex_Index SR_PAREN\n");
                (yyval.node)=createNode("Identifier","");addNode(4, (yyval.node), (yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
            }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 279 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Identifier -> IDENTIFIER\n");
                fprintf(fh,"Identifier -> IDENTIFIER\n");
                (yyval.node)=createNode("Identifier","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 285 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"INdex_Index -> Expr\n");
                fprintf(fh,"INdex_Index -> Expr\n");
                (yyval.node)=createNode("INdex_Index","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 291 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN Expr\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN Expr\n");
                (yyval.node)=createNode("AssignStm","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
            }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 299 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ComplexStm -> _BEGIN_ ComStates END\n"); 
                fprintf(fh,"ComplexStm -> _BEGIN_ ComStates END\n"); 
                (yyval.node)=createNode("ComplexStm","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 306 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ComStates -> Statement SEMI\n");
                fprintf(fh,"ComStates -> Statement SEMI\n");
                (yyval.node)=createNode("ComStates","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
                 }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 311 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ComStates ->ComStates  Statement SEMI\n");
                fprintf(fh,"ComStates ->ComStates  Statement SEMI\n");
                (yyval.node)=createNode("ComStates","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 318 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Condition -> Expr CMP Expr\n");
                fprintf(fh,"Condition -> Expr CMP Expr\n");
                (yyval.node)=createNode("Condition","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 323 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Condition -> ODD Expr\n");
                fprintf(fh,"Condition -> ODD Expr\n");
                (yyval.node)=createNode("Condition","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
              }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 329 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CMP -> EQUAL\n"); 
                fprintf(fh,"CMP -> EQUAL\n"); 
                (yyval.node)=createNode("CMP","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
             }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 334 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CMP -> NOTEQUAL\n");
                fprintf(fh,"CMP -> NOTEQUAL\n");
                (yyval.node)=createNode("CMP","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
              }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 339 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CMP -> LESS\n"); 
                fprintf(fh,"CMP -> LESS\n");
                (yyval.node)=createNode("CMP","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 344 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CMP -> GREATER\n");
                fprintf(fh,"CMP -> GREATER\n");
                (yyval.node)=createNode("CMP","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
              }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 349 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CMP -> LESS_EQUAL\n"); 
                fprintf(fh,"CMP -> LESS_EQUAL\n"); 
                (yyval.node)=createNode("CMP","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
             }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 354 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CMP -> GREATER_EQUAL\n");  
                fprintf(fh,"CMP -> GREATER_EQUAL\n");
                (yyval.node)=createNode("CMP","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
            }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 360 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CondiStm -> IF Condition THEN Statement\n"); 
                fprintf(fh,"CondiStm -> IF Condition THEN Statement\n"); 
                (yyval.node)=createNode("CondiStm","");addNode(4, (yyval.node), (yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
                 }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 365 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                fprintf(fh,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                (yyval.node)=createNode("CondiStm","");addNode(6, (yyval.node), (yyvsp[(1) - (6)].node),(yyvsp[(2) - (6)].node),(yyvsp[(3) - (6)].node),(yyvsp[(4) - (6)].node),(yyvsp[(5) - (6)].node),(yyvsp[(6) - (6)].node));
                  }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 371 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"Expr -> Expr PLUS Term\n"); 
                fprintf(fh,"Expr -> Expr PLUS Term\n");
                (yyval.node)=createNode("Expr","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 377 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"Expr -> Expr MINUS Term\n");
                fprintf(fh,"Expr -> Expr MINUS Term\n");
                (yyval.node)=createNode("Expr","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                  }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 383 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"Expr -> PLUS Term\n");  
                fprintf(fh,"Expr -> PLUS Term\n"); 
                (yyval.node)=createNode("Expr","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
                }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 389 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"Expr -> MINUS Term\n"); 
                fprintf(fh,"Expr -> MINUS Term\n");
                (yyval.node)=createNode("Expr","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
                 }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 395 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"Expr -> Term\n"); 
                fprintf(fh,"Expr -> Term\n");
                (yyval.node)=createNode("Expr","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 402 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"Term -> Term TIMES Factor\n"); 
                fprintf(fh,"Term -> Term TIMES Factor\n");
                (yyval.node)=createNode("Term","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                 }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 408 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"Term -> Term DIVIDE Factor\n"); 
                fprintf(fh,"Term -> Term DIVIDE Factor\n");
                (yyval.node)=createNode("Term","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                 }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 414 "./src/SyntaxPl0.y"
    {
                
                fprintf(fi,"Term -> Factor\n"); 
                fprintf(fh,"Term -> Factor\n"); 
                (yyval.node)=createNode("Term","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 421 "./src/SyntaxPl0.y"
    {
                // $$=$1;
                fprintf(fi,"Factor -> Identifier\n"); 
                fprintf(fh,"Factor -> Identifier\n");
                (yyval.node)=createNode("Factor","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 427 "./src/SyntaxPl0.y"
    {
                //$$=$1;
                fprintf(fi,"Factor -> INTEGER_VAL\n"); 
                fprintf(fh,"Factor -> INTEGER_VAL\n");
                (yyval.node)=createNode("Factor","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 433 "./src/SyntaxPl0.y"
    {
                //$$=$2;
                fprintf(fi,"Factor -> SL_PAREN Expr SR_PAREN\n");
                fprintf(fh,"Factor -> SL_PAREN Expr SR_PAREN\n");
                (yyval.node)=createNode("Factor","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                  }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 440 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"WhileStm -> WHILE Condition DO Statement\n"); 
                fprintf(fh,"WhileStm -> WHILE Condition DO Statement\n");
                (yyval.node)=createNode("WhileStm","");addNode(4, (yyval.node), (yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
            }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 446 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n");  
                fprintf(fh,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n"); 
                (yyval.node)=createNode("CallS","");addNode(2, (yyval.node), (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
            }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 451 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CallS -> call SL_PAREN Ccontent SR_PAREN\n");  
                fprintf(fh,"CallS -> call SL_PAREN Ccontent SR_PAREN\n"); 
                (yyval.node)=createNode("CallS","");addNode(5, (yyval.node), (yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));
            }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 457 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Ccontent -> Ccontent COMMA CconObj\n"); 
                fprintf(fh,"Ccontent -> Ccontent COMMA CconObj\n");
                (yyval.node)=createNode("Ccontent","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                 }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 462 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Ccontent -> CconObj\n"); 
                fprintf(fh,"Ccontent -> CconObj\n");
                (yyval.node)=createNode("Ccontent","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 468 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"CconObj -> Expr\n");
                fprintf(fh,"CconObj -> Expr\n");
                (yyval.node)=createNode("CconObj","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 473 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"ReadS -> read SL_PAREN Rcontent SR_PAREN\n");
                fprintf(fh,"ReadS -> read SL_PAREN Rcontent SR_PAREN\n");
                (yyval.node)=createNode("ReadS","");addNode(4, (yyval.node), (yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
                  }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 479 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Rcontent -> Rcontent COMMA RconObj\n"); 
                fprintf(fh,"Rcontent -> Rcontent COMMA RconObj\n");
                (yyval.node)=createNode("Rcontent","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                 }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 484 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Rcontent -> RconObj\n"); 
                fprintf(fh,"Rcontent -> RconObj\n");
                (yyval.node)=createNode("Rcontent","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 490 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"RconObj -> Identifier\n");
                fprintf(fh,"RconObj -> Identifier\n");
                (yyval.node)=createNode("RconObj","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 497 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                fprintf(fh,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                (yyval.node)=createNode("WriteS","");addNode(4, (yyval.node), (yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
                  }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 503 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Wcontent -> Wcontent COMMA WconObj\n"); 
                fprintf(fh,"Wcontent -> Wcontent COMMA WconObj\n");
                (yyval.node)=createNode("Wcontent","");addNode(3, (yyval.node), (yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                 }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 508 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"Wcontent -> WconObj\n"); 
                fprintf(fh,"Wcontent -> WconObj\n");
                (yyval.node)=createNode("Wcontent","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 514 "./src/SyntaxPl0.y"
    {
                fprintf(fi,"WconObj -> Expr\n");
                fprintf(fh,"WconObj -> Expr\n");
                (yyval.node)=createNode("WconObj","");addNode(1, (yyval.node), (yyvsp[(1) - (1)].node));
                }
    break;


/* Line 1792 of yacc.c  */
#line 2302 "SyntaxPl0.tab.c"
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


/* Line 2055 of yacc.c  */
#line 521 "./src/SyntaxPl0.y"


int main(int argc, char** argv)
{
    FILE* f = fopen(argv[1], "r");
    fi = fopen("./output/SynOutput.txt", "w+");
    fh = fopen("./output/helperOutput.txt", "w+");
    yyparse();
    printTree(Root,0);
    return 0;
}

void yyerror(char const* s)
{
    printf("%s,(%d,%d)\n",s,row,column);
    return;
}