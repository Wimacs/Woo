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
#line 1 "myLang.y"


#include <stdio.h>
#include <string.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);
extern char* yytext;


/* Line 371 of yacc.c  */
#line 79 "myLang.tab.c"

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
   by #include "myLang.tab.h".  */
#ifndef YY_YY_MYLANG_TAB_H_INCLUDED
# define YY_YY_MYLANG_TAB_H_INCLUDED
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
     NUMBER = 258,
     INT = 259,
     STR = 260,
     VOID = 261,
     IF = 262,
     ELSE = 263,
     WHILE = 264,
     RETURN = 265,
     CMP = 266,
     STRING = 267,
     ID = 268
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 12 "myLang.y"

	int	     iValue;
	char*	 icontent;
	past	 pAst1, pAst2, pAst3, pAst4;


/* Line 387 of yacc.c  */
#line 142 "myLang.tab.c"
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

#endif /* !YY_YY_MYLANG_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 170 "myLang.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   268

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    27,     2,     2,
      19,    20,    25,    23,    15,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    14,
       2,    16,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    16,    20,    22,
      26,    28,    32,    38,    40,    44,    46,    48,    50,    52,
      57,    61,    66,    70,    72,    76,    79,    81,    83,    85,
      87,    89,    91,    93,    95,    97,   100,   104,   106,   108,
     110,   113,   115,   118,   124,   132,   138,   141,   145,   147,
     149,   153,   160,   162,   166,   168,   172,   176,   178,   182,
     186,   190,   193,   198,   202,   206,   208,   210,   215,   217
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      29,     0,    -1,    30,    -1,    29,    30,    -1,    31,    -1,
      32,    -1,    41,    37,    43,    -1,    41,    33,    14,    -1,
      34,    -1,    33,    15,    34,    -1,    37,    -1,    37,    16,
      54,    -1,    37,    16,    17,    35,    18,    -1,    36,    -1,
      35,    15,    36,    -1,     3,    -1,    12,    -1,    38,    -1,
      13,    -1,    38,    19,    39,    20,    -1,    38,    19,    20,
      -1,    13,    21,    51,    22,    -1,    13,    21,    22,    -1,
      40,    -1,    39,    15,    40,    -1,    41,    13,    -1,     4,
      -1,     5,    -1,     6,    -1,    43,    -1,    47,    -1,    48,
      -1,    49,    -1,    50,    -1,    32,    -1,    44,    45,    -1,
      44,    46,    45,    -1,    17,    -1,    18,    -1,    42,    -1,
      46,    42,    -1,    14,    -1,    51,    14,    -1,     7,    19,
      51,    20,    42,    -1,     7,    19,    51,    20,    42,     8,
      42,    -1,     9,    19,    51,    20,    42,    -1,    10,    14,
      -1,    10,    51,    14,    -1,    52,    -1,    53,    -1,    13,
      16,    52,    -1,    13,    21,    51,    22,    16,    52,    -1,
      54,    -1,    53,    11,    54,    -1,    55,    -1,    54,    23,
      55,    -1,    54,    24,    55,    -1,    56,    -1,    55,    25,
      56,    -1,    55,    26,    56,    -1,    55,    27,    56,    -1,
      24,    56,    -1,    13,    19,    57,    20,    -1,    13,    19,
      20,    -1,    19,    51,    20,    -1,    13,    -1,    36,    -1,
      13,    21,    51,    22,    -1,    51,    -1,    57,    15,    51,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    30,    34,    35,    39,    43,    47,    48,
      52,    53,    54,    58,    59,    63,    64,    68,    72,    73,
      74,    75,    76,    80,    81,    85,    89,    90,    91,    95,
      96,    97,    98,    99,   100,   104,   105,   109,   113,   117,
     118,   122,   123,   127,   128,   132,   136,   137,   141,   145,
     146,   147,   151,   152,   156,   157,   158,   162,   163,   164,
     165,   166,   170,   171,   172,   173,   174,   175,   179,   180
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "INT", "STR", "VOID", "IF",
  "ELSE", "WHILE", "RETURN", "CMP", "STRING", "ID", "';'", "','", "'='",
  "'{'", "'}'", "'('", "')'", "'['", "']'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "$accept", "program", "external_declaration",
  "function_definition", "declaration", "init_declarator_list",
  "init_declarator", "intstr_list", "initializer", "declarator",
  "direct_declarator", "parameter_list", "parameter", "type", "statement",
  "compound_statement", "begin_scope", "end_scope", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "expr", "assign_expr", "cmp_expr", "add_expr",
  "mul_expr", "primary_expr", "expr_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    59,    44,    61,   123,   125,    40,
      41,    91,    93,    43,    45,    42,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    29,    30,    30,    31,    32,    33,    33,
      34,    34,    34,    35,    35,    36,    36,    37,    38,    38,
      38,    38,    38,    39,    39,    40,    41,    41,    41,    42,
      42,    42,    42,    42,    42,    43,    43,    44,    45,    46,
      46,    47,    47,    48,    48,    49,    50,    50,    51,    52,
      52,    52,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    56,    56,    56,    56,    56,    56,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     3,     1,     3,
       1,     3,     5,     1,     3,     1,     1,     1,     1,     4,
       3,     4,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     1,     1,
       2,     1,     2,     5,     7,     5,     2,     3,     1,     1,
       3,     6,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     2,     4,     3,     3,     1,     1,     4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    26,    27,    28,     0,     2,     4,     5,     0,     1,
       3,    18,     0,     8,    10,    17,     0,     7,     0,     0,
      37,     6,     0,     0,    15,    16,    65,     0,    22,     0,
      66,     0,    48,    49,    52,    54,    57,     9,    10,    65,
       0,    11,     0,     0,     0,    41,    38,    34,     0,    39,
      29,    35,     0,    30,    31,    32,    33,     0,    20,     0,
      23,     0,     0,     0,     0,     0,    61,    21,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,    46,
       0,    40,    36,    42,     0,    19,    25,    50,    63,    68,
       0,     0,    64,    53,    55,    56,    58,    59,    60,     0,
       0,    12,     0,     0,    47,    24,     0,    62,    67,    67,
      14,     0,     0,    69,     0,    43,    45,    51,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    47,    12,    13,    75,    30,    38,
      15,    59,    60,    48,    49,    50,    22,    51,    52,    53,
      54,    55,    56,    57,    32,    33,    34,    35,    36,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -61
static const yytype_int16 yypact[] =
{
     105,   -61,   -61,   -61,    34,   -61,   -61,   -61,     8,   -61,
     -61,    24,    -5,   -61,    19,    52,    84,   -61,     8,    88,
     -61,   -61,    13,     9,   -61,   -61,    25,   116,   -61,    30,
     -61,    37,   -61,    66,    75,    97,   -61,   -61,    64,    48,
       0,    75,    65,    73,   101,   -61,   -61,   -61,     8,   -61,
     -61,   -61,    13,   -61,   -61,   -61,   -61,    81,   -61,    40,
     -61,    89,   116,   114,   116,    96,   -61,   -61,   118,   118,
     118,    30,    30,    30,   116,    50,   -61,   116,   116,   -61,
     104,   -61,   -61,   -61,   105,   -61,   -61,   -61,   -61,   -61,
      74,   110,   -61,    75,    97,    97,   -61,   -61,   -61,   117,
       0,   -61,   121,   123,   -61,   -61,   116,   -61,   120,   -61,
     -61,    69,    69,   -61,   116,   136,   -61,   -61,    69,   -61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   143,   -61,    53,   -61,   130,   -61,   -34,   141,
     -61,   -61,    67,     1,   -48,   138,   -61,    98,   -61,   -61,
     -61,   -61,   -61,   -16,   -60,   -61,   -12,    76,   -21,   -61
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      31,     8,    87,    24,    81,     8,    76,    41,    66,    17,
      18,    65,    25,     1,     2,     3,    24,     1,     2,     3,
      42,    11,    43,    44,    61,    25,    26,    45,    80,    58,
      20,    46,    27,    24,     9,    19,    20,    29,     1,     2,
       3,    62,    25,    39,    63,    16,    64,    89,    91,    27,
      96,    97,    98,     7,   117,    84,    93,     7,    99,    67,
      85,   102,   103,   115,   116,   100,   110,    63,   101,    74,
     119,    23,    24,     1,     2,     3,    42,    68,    43,    44,
      19,    25,    26,    45,    77,    61,    20,    24,    27,   106,
     113,    24,    78,    29,   107,    83,    25,    26,    69,    70,
      25,    39,    86,    27,    24,    40,    28,    27,    29,     1,
       2,     3,    29,    25,    26,    79,    92,    24,   104,    24,
      27,    24,    71,    72,    73,    29,    25,    26,    25,    26,
      25,    39,   108,    27,    88,    27,   114,    27,    29,   109,
      29,   111,    29,   112,   118,    94,    95,    10,    37,    14,
      82,   105,    21
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      16,     0,    62,     3,    52,     4,    40,    19,    29,    14,
      15,    27,    12,     4,     5,     6,     3,     4,     5,     6,
       7,    13,     9,    10,    23,    12,    13,    14,    44,    20,
      17,    18,    19,     3,     0,    16,    17,    24,     4,     5,
       6,    16,    12,    13,    19,    21,    21,    63,    64,    19,
      71,    72,    73,     0,   114,    15,    68,     4,    74,    22,
      20,    77,    78,   111,   112,    15,   100,    19,    18,    21,
     118,    19,     3,     4,     5,     6,     7,    11,     9,    10,
      16,    12,    13,    14,    19,    84,    17,     3,    19,    15,
     106,     3,    19,    24,    20,    14,    12,    13,    23,    24,
      12,    13,    13,    19,     3,    17,    22,    19,    24,     4,
       5,     6,    24,    12,    13,    14,    20,     3,    14,     3,
      19,     3,    25,    26,    27,    24,    12,    13,    12,    13,
      12,    13,    22,    19,    20,    19,    16,    19,    24,    22,
      24,    20,    24,    20,     8,    69,    70,     4,    18,     8,
      52,    84,    14
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,    29,    30,    31,    32,    41,     0,
      30,    13,    33,    34,    37,    38,    21,    14,    15,    16,
      17,    43,    44,    19,     3,    12,    13,    19,    22,    24,
      36,    51,    52,    53,    54,    55,    56,    34,    37,    13,
      17,    54,     7,     9,    10,    14,    18,    32,    41,    42,
      43,    45,    46,    47,    48,    49,    50,    51,    20,    39,
      40,    41,    16,    19,    21,    51,    56,    22,    11,    23,
      24,    25,    26,    27,    21,    35,    36,    19,    19,    14,
      51,    42,    45,    14,    15,    20,    13,    52,    20,    51,
      57,    51,    20,    54,    55,    55,    56,    56,    56,    51,
      15,    18,    51,    51,    14,    40,    15,    20,    22,    22,
      36,    20,    20,    51,    16,    42,    42,    52,     8,    42
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
#line 29 "myLang.y"
    { (yyval.pAst1) = newList(NULL,(yyvsp[(1) - (1)].pAst1)); strcpy((yyval.pAst1)->nodeName,"program"); astRoot=(yyval.pAst1); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 30 "myLang.y"
    { (yyval.pAst1) = newList((yyvsp[(1) - (2)].pAst1),(yyvsp[(2) - (2)].pAst1));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 34 "myLang.y"
    { (yyval.pAst1) = (yyvsp[(1) - (1)].pAst1); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 35 "myLang.y"
    { (yyval.pAst1) = (yyvsp[(1) - (1)].pAst1); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 39 "myLang.y"
    { (yyval.pAst1) = newDecl("funcDef", (yyvsp[(1) - (3)].pAst2)->ivalue, ".", (yyvsp[(2) - (3)].pAst2), (yyvsp[(3) - (3)].pAst2)); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 43 "myLang.y"
    { (yyval.pAst1) = newDecl("decl", (yyvsp[(1) - (3)].pAst2)->ivalue, ".", (yyvsp[(1) - (3)].pAst2), (yyvsp[(2) - (3)].pAst1)); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 47 "myLang.y"
    { (yyval.pAst1) = newList(NULL,(yyvsp[(1) - (1)].pAst1)); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 48 "myLang.y"
    { (yyval.pAst1) = newList((yyvsp[(1) - (3)].pAst1), (yyvsp[(3) - (3)].pAst1)); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 52 "myLang.y"
    { (yyval.pAst1) = (yyvsp[(1) - (1)].pAst2); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 53 "myLang.y"
    { (yyval.pAst1) = newDecl("varInitDecl", 0, "=", (yyvsp[(1) - (3)].pAst2), (yyvsp[(3) - (3)].pAst4)); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 54 "myLang.y"
    { (yyval.pAst1) = newDecl("arrayInitDecl", 1, "=", (yyvsp[(1) - (5)].pAst2), (yyvsp[(4) - (5)].pAst1)); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 58 "myLang.y"
    { (yyval.pAst1) = newList(NULL,(yyvsp[(1) - (1)].pAst2)); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 59 "myLang.y"
    { (yyval.pAst1) = newList((yyvsp[(1) - (3)].pAst1), (yyvsp[(3) - (3)].pAst2)); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 63 "myLang.y"
    { (yyval.pAst2) = newNum((yyvsp[(1) - (1)].iValue)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 64 "myLang.y"
    { (yyval.pAst2) = newStr(STRING, (yyvsp[(1) - (1)].icontent)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 68 "myLang.y"
    { (yyval.pAst2) = (yyvsp[(1) - (1)].pAst2); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 72 "myLang.y"
    { (yyval.pAst2) = newDecl("varDecl", ID, (yyvsp[(1) - (1)].icontent), NULL, NULL); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 73 "myLang.y"
    { (yyval.pAst2) = newDecl("funcDecl", (yyvsp[(1) - (4)].pAst2)->ivalue, (yyvsp[(1) - (4)].pAst2)->nodeName, (yyvsp[(1) - (4)].pAst2), (yyvsp[(3) - (4)].pAst2)); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 74 "myLang.y"
    { (yyval.pAst2) = newDecl("funcDecl", (yyvsp[(1) - (3)].pAst2)->ivalue, (yyvsp[(1) - (3)].pAst2)->nodeName, (yyvsp[(1) - (3)].pAst2), NULL); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 75 "myLang.y"
    { past temp= newId(ID, (yyvsp[(1) - (4)].icontent)); (yyval.pAst2) = newDecl("arrayDecl", ID, temp->nodeName, (yyvsp[(3) - (4)].pAst4), NULL); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 76 "myLang.y"
    { past temp= newId(ID, (yyvsp[(1) - (3)].icontent)); (yyval.pAst2) = newDecl("arrayDecl", ID, temp->nodeName, NULL, NULL); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 80 "myLang.y"
    { (yyval.pAst2) = newList(NULL,(yyvsp[(1) - (1)].pAst2)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 81 "myLang.y"
    { (yyval.pAst2) = newList((yyvsp[(1) - (3)].pAst2), (yyvsp[(3) - (3)].pAst2)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 85 "myLang.y"
    { past temp= newId(ID, (yyvsp[(2) - (2)].icontent)); (yyval.pAst2) = newPara(temp->nodeName, (yyvsp[(1) - (2)].pAst2)); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 89 "myLang.y"
    { (yyval.pAst2) = newType((yyvsp[(1) - (1)].iValue)); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 90 "myLang.y"
    { (yyval.pAst2) = newType((yyvsp[(1) - (1)].iValue)); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 91 "myLang.y"
    { (yyval.pAst2) = newType((yyvsp[(1) - (1)].iValue)); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 95 "myLang.y"
    { (yyval.pAst2) = (yyvsp[(1) - (1)].pAst2); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 96 "myLang.y"
    { (yyval.pAst2) = (yyvsp[(1) - (1)].pAst3); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 97 "myLang.y"
    { (yyval.pAst2) = (yyvsp[(1) - (1)].pAst3); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 98 "myLang.y"
    { (yyval.pAst2) = (yyvsp[(1) - (1)].pAst3); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 99 "myLang.y"
    { (yyval.pAst2) = (yyvsp[(1) - (1)].pAst3); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 100 "myLang.y"
    { (yyval.pAst2) = (yyvsp[(1) - (1)].pAst1); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 104 "myLang.y"
    { (yyval.pAst2) = NULL; }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 105 "myLang.y"
    { (yyval.pAst2) = newStmt("compStmt", 0, (yyvsp[(2) - (3)].pAst3), NULL); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 109 "myLang.y"
    {}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 113 "myLang.y"
    {}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 117 "myLang.y"
    { (yyval.pAst3) = newList(NULL,(yyvsp[(1) - (1)].pAst2)); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 118 "myLang.y"
    { (yyval.pAst3) = newList((yyvsp[(1) - (2)].pAst3), (yyvsp[(2) - (2)].pAst2)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 122 "myLang.y"
    {}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 123 "myLang.y"
    { (yyval.pAst3) = (yyvsp[(1) - (2)].pAst4); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 127 "myLang.y"
    { (yyval.pAst3) = newStmt("ifStmt", (yyvsp[(1) - (5)].iValue), (yyvsp[(3) - (5)].pAst4), (yyvsp[(5) - (5)].pAst2)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 128 "myLang.y"
    { past temp1 = newStmt("elseStmt",(yyvsp[(6) - (7)].iValue),NULL,(yyvsp[(7) - (7)].pAst2)); past temp2 = newStmt("ifStmt",(yyvsp[(1) - (7)].iValue),(yyvsp[(3) - (7)].pAst4),(yyvsp[(5) - (7)].pAst2)); (yyval.pAst3) = newStmt("if_elseStmt", (yyvsp[(1) - (7)].iValue), temp2, temp1); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 132 "myLang.y"
    { (yyval.pAst3) = newStmt("whileStmt", (yyvsp[(1) - (5)].iValue), (yyvsp[(3) - (5)].pAst4), (yyvsp[(5) - (5)].pAst2)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 136 "myLang.y"
    { (yyval.pAst3) = newStmt("returnStmt", (yyvsp[(1) - (2)].iValue), NULL, NULL); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 137 "myLang.y"
    { (yyval.pAst3) = newStmt("returnStmt", (yyvsp[(1) - (3)].iValue), NULL, (yyvsp[(2) - (3)].pAst4)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 141 "myLang.y"
    { (yyval.pAst4) = (yyvsp[(1) - (1)].pAst4); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 145 "myLang.y"
    { (yyval.pAst4) = (yyvsp[(1) - (1)].pAst4); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 146 "myLang.y"
    { past temp = newId(ID, (yyvsp[(1) - (3)].icontent)); strcpy(temp->nodeType,"idRef");(yyval.pAst4) = newExpr('=', temp, (yyvsp[(3) - (3)].pAst4)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 147 "myLang.y"
    { past temp = newId(ID, (yyvsp[(1) - (6)].icontent)); strcpy(temp->nodeType,"idRef");(yyval.pAst4) = newExtend("expr", '=', temp, (yyvsp[(3) - (6)].pAst4), (yyvsp[(6) - (6)].pAst4)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 151 "myLang.y"
    { (yyval.pAst4) = (yyvsp[(1) - (1)].pAst4); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 152 "myLang.y"
    { (yyval.pAst4) = newExpr((yyvsp[(2) - (3)].iValue), (yyvsp[(1) - (3)].pAst4), (yyvsp[(3) - (3)].pAst4)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 156 "myLang.y"
    { (yyval.pAst4) = (yyvsp[(1) - (1)].pAst4); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 157 "myLang.y"
    { (yyval.pAst4) = newExpr('+', (yyvsp[(1) - (3)].pAst4), (yyvsp[(3) - (3)].pAst4)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 158 "myLang.y"
    { (yyval.pAst4) = newExpr('-', (yyvsp[(1) - (3)].pAst4), (yyvsp[(3) - (3)].pAst4)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 162 "myLang.y"
    { (yyval.pAst4) = (yyvsp[(1) - (1)].pAst4); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 163 "myLang.y"
    { (yyval.pAst4) = newExpr('*', (yyvsp[(1) - (3)].pAst4), (yyvsp[(3) - (3)].pAst4)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 164 "myLang.y"
    { (yyval.pAst4) = newExpr('/', (yyvsp[(1) - (3)].pAst4), (yyvsp[(3) - (3)].pAst4)); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 165 "myLang.y"
    { (yyval.pAst4) = newExpr('%', (yyvsp[(1) - (3)].pAst4), (yyvsp[(3) - (3)].pAst4)); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 166 "myLang.y"
    { (yyval.pAst4) = newExpr('-', NULL, (yyvsp[(2) - (2)].pAst4)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 170 "myLang.y"
    { past temp = newId(ID, (yyvsp[(1) - (4)].icontent)); strcpy(temp->nodeType,"idRef");(yyval.pAst4) = newRef("funcRef", temp, (yyvsp[(3) - (4)].pAst4)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 171 "myLang.y"
    { past temp = newId(ID, (yyvsp[(1) - (3)].icontent)); strcpy(temp->nodeType,"idRef");(yyval.pAst4) = newRef("funcRef", temp, NULL); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 172 "myLang.y"
    { (yyval.pAst4) = (yyvsp[(2) - (3)].pAst4); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 173 "myLang.y"
    { (yyval.pAst4) = newId(ID, (yyvsp[(1) - (1)].icontent)); strcpy((yyval.pAst4)->nodeType,"idRef");}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 174 "myLang.y"
    { (yyval.pAst4) = (yyvsp[(1) - (1)].pAst2); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 175 "myLang.y"
    { past temp = newId(ID, (yyvsp[(1) - (4)].icontent)); strcpy(temp->nodeType,"idRef");(yyval.pAst4) = newRef("arrayRef", temp, (yyvsp[(3) - (4)].pAst4)); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 179 "myLang.y"
    { (yyval.pAst4) = newList(NULL,(yyvsp[(1) - (1)].pAst4)); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 180 "myLang.y"
    { (yyval.pAst4) = newList((yyvsp[(1) - (3)].pAst4), (yyvsp[(3) - (3)].pAst4)); }
    break;


/* Line 1792 of yacc.c  */
#line 1878 "myLang.tab.c"
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
#line 182 "myLang.y"


void yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
}
