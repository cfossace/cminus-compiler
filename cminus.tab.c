/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 22 "cminus.y" /* yacc.c:339  */

#include <stdio.h>
#include "symtab.h"
#include <stdlib.h>
#include <string.h>

extern char * yytext;
extern int yylex();
extern int row; //count the rows
extern int col; //count the columns
void yyerror (char const *s);
char * concat( char * str1, char * str2);
int JVM = 0;//count the jvm number
int location = 0;//increment the memory location
int scope = 0;//keep track of the scope
int size = 0;//size for arrays--everything else default 0
char * kind;//keep track if function, variable, or array
char * print;//temp string to print out when calling fxns
int params= 0;//keep track of the number of params
int type = 0;//type = INT or VOID (ret type)
int mainFlag;//has the main function been set yet?
int count=0;//count the number of params
int inserted;//if the function has been inserted, flag
int flag =0;//this flag keeps track of strcpy vs strcat for printing, if function has no params
char * compare;//this lets you look at a name, or variable type and compare it
char * string; //this is printed, depending on if the function has variable or not (I, [I)
char save[80]; //this is the final printed string, and is cleared each time a function is called
int refresh;//this is the variable that runs the loop to reset the "save" string
char * blank = " ";//just needed a blank space
int scopeChange = 0;//keep track of changing scope for redeclarations in the symtab
int callFlag = 0;//if a function is called set this flag
int oppFlag = 0;//if an operator is used, set this flag.  Keeps it from having too many args in the call bytecode
int brackFlag= 0;//if a bracket is seen (because it detects an array)
int scanCalled=0;//check if scan is called
int relopsFlag = 0;//flag for relative operators

char * parmName = "notarealname";//must initialize to something

#line 105 "cminus.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif


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
    WHILE = 258,
    INT = 259,
    RET = 260,
    VOID = 261,
    ELSE = 262,
    IF = 263,
    MULT = 264,
    DIV = 265,
    ADD = 266,
    SUB = 267,
    LESS = 268,
    LESSEQ = 269,
    GREAT = 270,
    GREATEQ = 271,
    EQUAL = 272,
    NOTEQ = 273,
    ASSIGN = 274,
    SEMI = 275,
    COMMA = 276,
    LPAR = 277,
    RPAR = 278,
    LBRACK = 279,
    RBRACK = 280,
    LCURLY = 281,
    RCURLY = 282,
    ERROR = 283,
    PRINTF = 284,
    FSTRING = 285,
    DSTRING = 286,
    SCANF = 287,
    AMP = 288,
    NUM = 289,
    ID = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 62 "cminus.y" /* yacc.c:355  */
 
	int intval;
	char * strval;
	

#line 184 "cminus.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 199 "cminus.tab.c" /* yacc.c:358  */

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
# elif ! defined YYSIZE_T
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

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    84,    88,    89,    92,    93,    96,   119,
     137,   158,   180,   211,   211,   179,   223,   252,   252,   222,
     265,   266,   269,   270,   273,   297,   315,   337,   357,   357,
     360,   361,   364,   365,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   379,   386,   386,   386,   386,   386,   386,
     389,   389,   389,   389,   389,   389,   392,   393,   396,   396,
     399,   422,   422,   442,   442,   452,   453,   456,   457,   458,
     459,   460,   461,   464,   465,   468,   469,   472,   473,   476,
     477,   480,   481,   482,   484,   484,   488,   510,   513,   510,
     526,   527,   530,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "INT", "RET", "VOID", "ELSE",
  "IF", "MULT", "DIV", "ADD", "SUB", "LESS", "LESSEQ", "GREAT", "GREATEQ",
  "EQUAL", "NOTEQ", "ASSIGN", "SEMI", "COMMA", "LPAR", "RPAR", "LBRACK",
  "RBRACK", "LCURLY", "RCURLY", "ERROR", "PRINTF", "FSTRING", "DSTRING",
  "SCANF", "AMP", "NUM", "ID", "$accept", "program", "$@1",
  "declarationlist", "declaration", "vardeclaration", "fundeclaration",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "parameters", "paramslist",
  "param", "compoundstmt", "$@8", "localdeclarations", "stmtlist", "stmt",
  "callstmt", "selectionstmt", "@9", "@10", "$@11", "$@12", "$@13",
  "iterationstmt", "@14", "@15", "$@16", "$@17", "$@18", "returnstmt",
  "printstmt", "$@19", "scanstmt", "assignstmt", "$@20", "$@21",
  "expression", "relop", "addexpression", "addop", "term", "mulop",
  "factor", "$@22", "call", "$@23", "$@24", "args", "arglist", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -88

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -136,     6,    18,  -136,   -25,   -20,    18,  -136,  -136,  -136,
     -11,    26,  -136,  -136,  -136,     1,  -136,  -136,    28,    45,
      41,    45,    47,    38,    49,  -136,    22,  -136,    63,  -136,
      65,    62,    66,    68,    48,  -136,    69,  -136,    70,    71,
    -136,    49,  -136,  -136,  -136,  -136,    61,    61,  -136,  -136,
    -136,  -136,    51,    53,    54,  -136,    -1,    -8,     9,  -136,
     -17,    72,  -136,  -136,  -136,    75,     8,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,    78,  -136,  -136,   -14,
    -136,    36,    79,    64,    30,  -136,  -136,  -136,    81,    73,
      82,    76,    83,  -136,    85,    86,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   -14,   -14,  -136,  -136,
     -14,  -136,    80,    87,   -14,   -14,   -14,  -136,  -136,   -14,
      52,    30,  -136,   -14,    90,    84,    92,    88,  -136,  -136,
      93,   -14,    91,    95,   -14,    89,  -136,    96,    97,   -14,
    -136,  -136,  -136,    98,    99,   -14,  -136,  -136,   100,    39,
     105,   106,   107,  -136,  -136,  -136,  -136,  -136,    39,   112,
    -136,  -136,    39,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     5,     6,     7,
       0,     0,     4,     8,    12,     0,     9,    16,     0,     0,
       0,     0,     0,     0,    21,    13,    20,    23,     0,    17,
       0,    24,    25,     0,     0,    10,     0,    11,     0,     0,
      14,     0,    22,    18,    26,    27,     0,     0,    28,    15,
      19,    31,    33,     0,     0,    30,     0,     0,     0,    50,
       0,     0,    42,    29,    58,     0,    61,    35,    32,    41,
      36,    37,    38,    39,    40,    34,     0,    51,    56,     0,
      83,    86,     0,    66,    74,    78,    82,    44,     0,     0,
       0,     0,     0,    43,     0,     0,    84,    57,    75,    76,
      68,    67,    69,    70,    72,    71,     0,     0,    79,    80,
       0,    45,     0,     0,     0,     0,    91,    52,    81,     0,
      65,    73,    77,     0,     0,     0,     0,     0,    93,    88,
      90,     0,     0,     0,     0,     0,    62,     0,     0,     0,
      53,    85,    46,     0,     0,     0,    89,    92,     0,     0,
       0,     0,     0,    54,    47,    59,    60,    64,     0,     0,
      55,    48,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,   122,    77,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,   109,  -136,   101,    23,  -136,  -136,  -136,
    -135,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   -78,  -136,    25,  -136,    27,  -136,    29,  -136,   -56,
    -136,  -136,  -136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    19,    33,    46,
      21,    36,    47,    25,    26,    27,    67,    51,    52,    56,
      68,    69,    70,   111,   123,   149,   159,   162,    71,    77,
      94,   131,   148,   158,    72,    73,    88,    74,    75,    90,
      91,    82,   106,    83,   107,    84,   110,    85,   119,    86,
      92,   138,   129,   130
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    95,    59,    78,    60,    79,     3,    61,    79,    13,
      10,    14,    13,    15,   154,    11,    15,    80,    81,    62,
      80,    81,     4,   160,     5,    48,    63,   163,    64,    16,
     -87,    65,   -63,    18,    66,    20,   126,   127,   128,   108,
     109,   132,    59,    34,    60,   133,    16,    61,    17,    23,
      18,    24,    23,   140,    41,    53,   143,    54,   -87,    62,
      96,   147,    22,    98,    99,    48,    28,   152,    64,    49,
      50,    65,    30,    31,    66,    98,    99,   100,   101,   102,
     103,   104,   105,    35,    32,    37,    38,    48,    57,    58,
      39,    40,    43,    76,    87,    44,    45,    89,    93,    97,
     115,   114,    76,   112,   113,   116,    76,   117,   125,   118,
     124,   134,   136,   137,   139,   145,   141,   135,   142,   161,
     146,   150,   151,   153,   144,   155,   156,   157,    12,    55,
      29,   120,     0,     0,   121,    42,     0,     0,     0,   122
};

static const yytype_int16 yycheck[] =
{
      56,    79,     3,    20,     5,    22,     0,     8,    22,    20,
      35,    22,    20,    24,   149,    35,    24,    34,    35,    20,
      34,    35,     4,   158,     6,    26,    27,   162,    29,    20,
      22,    32,    24,    24,    35,    34,   114,   115,   116,     9,
      10,   119,     3,    21,     5,   123,    20,     8,    22,     4,
      24,     6,     4,   131,     6,     4,   134,     6,    22,    20,
      24,   139,    34,    11,    12,    26,    25,   145,    29,    46,
      47,    32,    25,    35,    35,    11,    12,    13,    14,    15,
      16,    17,    18,    20,    35,    20,    24,    26,    35,    35,
      24,    23,    23,   149,    22,    25,    25,    22,    20,    20,
      24,    19,   158,    22,    31,    22,   162,    22,    21,    23,
      30,    21,    20,    25,    21,    19,    25,    33,    23,     7,
      23,    23,    23,    23,    35,    20,    20,    20,     6,    52,
      21,   106,    -1,    -1,   107,    34,    -1,    -1,    -1,   110
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,     0,     4,     6,    39,    40,    41,    42,
      35,    35,    40,    20,    22,    24,    20,    22,    24,    43,
      34,    46,    34,     4,     6,    49,    50,    51,    25,    49,
      25,    35,    35,    44,    21,    20,    47,    20,    24,    24,
      23,     6,    51,    23,    25,    25,    45,    48,    26,    52,
      52,    53,    54,     4,     6,    41,    55,    35,    35,     3,
       5,     8,    20,    27,    29,    32,    35,    52,    56,    57,
      58,    64,    70,    71,    73,    74,    85,    65,    20,    22,
      34,    35,    77,    79,    81,    83,    85,    22,    72,    22,
      75,    76,    86,    20,    66,    77,    24,    20,    11,    12,
      13,    14,    15,    16,    17,    18,    78,    80,     9,    10,
      82,    59,    22,    31,    19,    24,    22,    22,    23,    84,
      79,    81,    83,    60,    30,    21,    77,    77,    77,    88,
      89,    67,    77,    77,    21,    33,    20,    25,    87,    21,
      77,    25,    23,    77,    35,    19,    23,    77,    68,    61,
      23,    23,    77,    23,    56,    20,    20,    20,    69,    62,
      56,     7,    63,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    38,    37,    39,    39,    40,    40,    41,    41,
      41,    41,    43,    44,    45,    42,    46,    47,    48,    42,
      49,    49,    50,    50,    51,    51,    51,    51,    53,    52,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    59,    60,    61,    62,    63,    58,
      65,    66,    67,    68,    69,    64,    70,    70,    72,    71,
      73,    75,    74,    76,    74,    77,    77,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    83,    84,    83,    83,    86,    87,    85,
      88,    88,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     3,     3,
       6,     6,     0,     0,     0,     9,     0,     0,     0,     9,
       1,     1,     3,     1,     2,     2,     4,     4,     0,     5,
       2,     0,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,    10,     2,     3,     0,     8,
       8,     0,     5,     0,     8,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     0,     5,     1,     0,     0,     6,
       1,     0,     3,     1
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
  unsigned long int yylno = yyrline[yyrule];
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
#line 84 "cminus.y" /* yacc.c:1646  */
    {genBegin(); }
#line 1393 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 84 "cminus.y" /* yacc.c:1646  */
    { {if (mainFlag!=1){printf("Semantic Error: No Main function at row = %d\tcol = %d.\n", row, col);}}genConstruct();if(count!= 0)
{printGlobArr(); genRet();} genEnd();}
#line 1400 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 97 "cminus.y" /* yacc.c:1646  */
    {
				
				if(st_lookup((yyvsp[-1].strval), "variable", INT, scope) ==-1){
					st_insert((yyvsp[-1].strval),location, JVM, scope, "variable", size, INT, params); 
				if(scope == 0)
				{
				genVar(scope, (yyvsp[-1].strval), jvm_lookup((yyvsp[-1].strval), "variable",INT, scope));
				}
					
				JVM++; location++;scopeChange=0;}
					
				
				else if(st_lookup((yyvsp[-1].strval), "variable", INT, scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two variables %s of different  RETURN types. The return of %s is VOID\n", row, col, (yyvsp[-1].strval), (yyvsp[-1].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[-1].strval), "variable", INT, scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d.Can't have two names %s of different types. %s is an array\n", row, col,(yyvsp[-1].strval), (yyvsp[-1].strval));}
				else if (st_lookup((yyvsp[-1].strval), "variable",INT, scope) ==-4) {if((scopeChange ==1)&&(strcmp(parmName, (yyvsp[-1].strval))!= 0)){st_insert((yyvsp[-1].strval),location, JVM, scope, "variable", size, INT, params); JVM++; location++;scopeChange = 0;changeTwice ((yyvsp[-1].strval));}
	
}
else {                         printf("Semantic Error: row = %d\tcol = %d. Can't redeclare name %s in current scope.\n", row, col, (yyvsp[-1].strval));}}
#line 1427 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 120 "cminus.y" /* yacc.c:1646  */
    {
				if(st_lookup((yyvsp[-1].strval), "variable", VOID, scope) ==-1){
				
					printf("Semantic Error: row = %d\tcol = %d. Can't have variable %s of type VOID\n",row, col, (yyvsp[-1].strval));
				}
				
				else if(st_lookup((yyvsp[-1].strval), "variable", VOID, scope) >=0)
				{
				
				printf("Semantic Error: row = %d\tcol = %d. Can't have two variables %s of different  RETURN types. Already exists with return INT\n", row, col, (yyvsp[-1].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[-1].strval), "variable", INT, scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d.Can't have two names %s of different types. %s is a variable\n",row, col, (yyvsp[-1].strval), (yyvsp[-1].strval));}
				else if (st_lookup((yyvsp[-1].strval), "variable", returnType((yyvsp[-1].strval)), scope) ==-4) {printf("Semantic Error: row = %d\tcol = %d. Can't redeclare variable in same scope\n",row, col);}
	else {printf("Semantic Error:row = %d\tcol = %d. Variable %s has already been declared\n",row, col,(yyvsp[-1].strval)); 
				}
}
#line 1449 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 139 "cminus.y" /* yacc.c:1646  */
    {if (st_lookup((yyvsp[-4].strval), "array", INT, scope) ==-1) 
					{	
				 
					st_insert((yyvsp[-4].strval),location, JVM, scope, "array", (yyvsp[-2].intval), INT, params); genArr(scope, (yyvsp[-4].strval), (yyvsp[-2].intval), jvm_lookup((yyvsp[-4].strval), "array",INT, scope));JVM++; location++;scopeChange = 0; if(scope ==0) {count = count + 1 ;}			
					
				}
				else if(st_lookup((yyvsp[-4].strval), "array", returnType((yyvsp[-4].strval)),scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two arrays %s of different RETURN types. Already exists with return type VOID\n",row, col, (yyvsp[-4].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[-4].strval), "array", returnType((yyvsp[-4].strval)), scope) ==-3){
				printf("Semantic Error: row = %d\tcol = %d.Can't have two names %s of different types.  %s is a variable\n",row, col, (yyvsp[-4].strval),(yyvsp[-4].strval));}
				else if (st_lookup((yyvsp[-4].strval), "array", returnType((yyvsp[-4].strval)),scope) ==-4) {if(scopeChange ==1) {st_insert((yyvsp[-4].strval),location, JVM, scope, "variable", size, INT, params); JVM++; location++;scopeChange = 1;changeTwice((yyvsp[-4].strval));} else{printf("Semantic Error: row = %d\tcol = %d. Can't redeclare name %s in current scope.\n", row, col, (yyvsp[-4].strval));}}
				else
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't redeclare name %s in current scope.\n", row, col, (yyvsp[-4].strval));	
				}
			}
#line 1472 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "cminus.y" /* yacc.c:1646  */
    {if (st_lookup((yyvsp[-4].strval), "array", VOID, scope) ==-1) 
				{
				printf("Semantic Error:row = %d\tcol = %d. Can't have array %s of type VOID\n",row, col, (yyvsp[-4].strval));
				}
				else if(st_lookup((yyvsp[-4].strval), "array", VOID,scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two arrays %s of different RETURN types. The return type of %s is %d\n",row, col, (yyvsp[-4].strval), (yyvsp[-4].strval), returnType((yyvsp[-4].strval)));
				}
				else if (st_lookup((yyvsp[-4].strval), "array", VOID, scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s is a variable\n",row, col, (yyvsp[-4].strval),(yyvsp[-4].strval));}
				else if (st_lookup((yyvsp[-4].strval), "array", VOID,scope) ==-4) {printf("Semantic Error: row = %d\tcol = %d.Can't redeclare array in same scope\n",row,col);}
				else
				{
				printf("Semantic Error: row = %d\tcol = %d.Array %s has already been declared\n",row, col, (yyvsp[-4].strval)); 
				}
			}
#line 1493 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 180 "cminus.y" /* yacc.c:1646  */
    { 	scanCalled = 0;parmName = (yyvsp[-1].strval);
				inserted = 0;
				if (mainFlag ==1)
				{printf("Semantic Error: row = %d\tcol = %d.Cannot insert function %s after main",row, col, (yyvsp[-1].strval));
				} 
				else{  
					if(st_lookup((yyvsp[-1].strval), "function", INT, scope) ==-1) 						{		
						if(strcmp((yyvsp[-1].strval), "main") ==0) 
							{
								printf("Semantic Error: row = %d\tcol = %d. Cannot assign main type int\n", row, col);
							}
					else {JVM = 0;}
					type = INT;
					if (strcmp((yyvsp[-1].strval), "main") !=0)
					{ params = 0; 
					  st_insert((yyvsp[-1].strval),location, JVM, scope, "function", size, type, params); inserted = 1;
					} 
					if(mainFlag==1)
					{ /*Don't do anything*/   }
					else{printf(";>> FUNCTION %s <<\n", (yyvsp[-1].strval));printf(".method static %s(",(yyvsp[-1].strval));location++; params = 0;/*reset the value of params*/ }
					}		        
					else if(st_lookup((yyvsp[-1].strval), "function", INT, scope) ==-2)					{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two functions %s of different RETURN types. Already exists as type VOID\n", row, col, (yyvsp[-1].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[-1].strval), "function", returnType((yyvsp[-1].strval)), scope) ==-3){printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s is a function\n",row, col, (yyvsp[-1].strval),(yyvsp[-1].strval));}
		else if (st_lookup((yyvsp[-1].strval), "function", returnType((yyvsp[-1].strval)),scope) ==-4){printf("Semantic Error: row = %d\tcol = %d. Can't redeclare function in same scope\n", row, col);}

				else {
				printf("Semantic Error: row = %d\tcol = %d. Function %s already in scope\n",row, col, (yyvsp[-1].strval)); }
			}
}
#line 1529 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 211 "cminus.y" /* yacc.c:1646  */
    {if(mainFlag!=1){st_update((yyvsp[-3].strval), params);}}
#line 1535 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 211 "cminus.y" /* yacc.c:1646  */
    {if((inserted ==1)&& (mainFlag!=1))
					{
					printf(")");
					if(returnType((yyvsp[-5].strval)) == INT)
					{printf("I\n"); }
					else{	printf("V\n");
					}
				 genFunc();					
					} }
#line 1549 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 219 "cminus.y" /* yacc.c:1646  */
    {  printf("ireturn\n");
  printf(".end method\n\n");}
#line 1556 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 223 "cminus.y" /* yacc.c:1646  */
    { 	scanCalled = 0;  parmName=(yyvsp[-1].strval);inserted = 0;
				if (mainFlag ==1)
				{printf("Semantic Error: row = %d\tcol = %d. Cannot insert function %s after main\n", row, col, (yyvsp[-1].strval));
				} 
				else{  
				if(st_lookup((yyvsp[-1].strval), "function", VOID, scope) ==-1) {		
					if(strcmp((yyvsp[-1].strval), "main") ==0) {
					
					mainFlag = 1;	JVM = 1;			
					}
					else {JVM = 0;}
					type = VOID;
					params = 0;
					st_insert((yyvsp[-1].strval),location, JVM, scope, "function", size, type, params); inserted = 1; if(mainFlag==1)
	{genMain();}else{printf(";>> FUNCTION %s <<\n", (yyvsp[-1].strval));printf(".method static %s(",(yyvsp[-1].strval));location++; params = 0;/*reset the value of params*/ }
					}			        
				else if(st_lookup((yyvsp[-1].strval), "function", VOID, scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two functions %s of different RETURN types. Already exists of type INT\n",row, col, (yyvsp[-1].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[-1].strval), "function", VOID, scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s is a function\n", row, col, (yyvsp[-1].strval),(yyvsp[-1].strval));}
		else if (st_lookup((yyvsp[-1].strval), "function", VOID,scope) ==-4) {printf("Semantic Error: row = %d\tcol = %d.Can't redeclare function in same scope\n", row , col);}

				else {
				printf("Semantic Error:row = %d\tcol = %d. Function %s already in scope\n",row, col, (yyvsp[-1].strval)); 	
					}
			}
}
#line 1590 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 252 "cminus.y" /* yacc.c:1646  */
    {if(mainFlag!=1){st_update((yyvsp[-3].strval), params);}}
#line 1596 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 252 "cminus.y" /* yacc.c:1646  */
    {if((inserted ==1)&& (mainFlag!=1))
					{
					printf(")");
					if(returnType((yyvsp[-5].strval)) == INT)
					{printf("I\n"); }
					else{	printf("V\n");
					}
				 genFunc();					
					} /*genFunc();*/}
#line 1610 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 260 "cminus.y" /* yacc.c:1646  */
    {genRet();}
#line 1616 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 274 "cminus.y" /* yacc.c:1646  */
    {
			if (st_lookup((yyvsp[0].strval), "variable", INT, scope) ==-1)                  {parmName=(yyvsp[0].strval);
				params++;
				scope++; scopeChange = 1;
			st_insert((yyvsp[0].strval),location, JVM, scope, "variable", size, INT, params);printf("I"); JVM++; location++; scope--; 

			}
			else if(st_lookup((yyvsp[0].strval), "variable", returnType((yyvsp[0].strval)), scope) ==-2)				{
				printf(" Semantic Error: row = %d\tcol = %d. Variable %s was declared with a different RETURN type. The return type of %s is VOID\n",row, col, (yyvsp[0].strval), (yyvsp[0].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[0].strval), "variable", returnType((yyvsp[0].strval)), scope)==-3)
				
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s was already declared as a variable\n",row, col, (yyvsp[0].strval),(yyvsp[0].strval));}
		
					
			else {  printf("I"); 
				params++;
				scope++;scopeChange = 1;
			st_insert((yyvsp[0].strval),location, JVM, scope, "variable", size, INT, params); JVM++; location++; scope--;parmName=(yyvsp[0].strval);changeTwice((yyvsp[0].strval));
				}
		}
#line 1642 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 298 "cminus.y" /* yacc.c:1646  */
    {
			if (st_lookup((yyvsp[0].strval), "variable",VOID, scope) ==-1)                  	{
				printf("Semantic Error: row = %d\tcol = %d. Can't have variable %s of type VOID\n",row, col, (yyvsp[0].strval));	
			}

			
			else if(st_lookup((yyvsp[0].strval), "variable", VOID, scope) ==-2)			{	printf("Semantic Error: row = %d\tcol = %d. Variable %s was declared with a different RETURN type. The return type of %s is INT", row, col, (yyvsp[0].strval), (yyvsp[0].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[0].strval), "variable", VOID, scope)==-3)
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s was already declared as a variable\n",row, col, (yyvsp[0].strval),(yyvsp[0].strval));}		
			else {
				
				printf("Semantic Error: row = %d\tcol = %d. Param Variable %s already declared\n",row, col, (yyvsp[0].strval)); 
				}
			
		}
#line 1663 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 316 "cminus.y" /* yacc.c:1646  */
    {if (st_lookup((yyvsp[-2].strval), "array", INT, scope) ==-1) 
			{
				parmName=(yyvsp[-2].strval);
				params++; scope++;scopeChange = 1;
				st_insert((yyvsp[-2].strval),location, JVM, scope, "array", size, INT, params); printf("[I");JVM++; location++; scope--;
		        }
			else if(st_lookup((yyvsp[-2].strval), "array", returnType((yyvsp[-2].strval)),scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Array %s was declared with a different RETURN type. Already delcared type VOID\n", row, col, (yyvsp[-2].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[-2].strval), "array", returnType((yyvsp[-2].strval)),scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s is was declared as an array\n", row, col, (yyvsp[-2].strval),(yyvsp[-2].strval));}		
			
			else {   printf("[I");
				 params++;
				 scope++;scopeChange = 1; 
				st_insert((yyvsp[-2].strval),location, JVM, scope, "array", size, INT, params); JVM++; location++; scope--;changeTwice((yyvsp[-2].strval));
			parmName=(yyvsp[-2].strval);}
			
		}
#line 1688 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 338 "cminus.y" /* yacc.c:1646  */
    {if (st_lookup((yyvsp[-2].strval), "array", VOID, scope) ==-1) 
			{
				printf("Semantic Error: row = %d\tcol = %d. Can't have array %s of type VOID\n",row, col,(yyvsp[-2].strval));						}
			
			else if(st_lookup((yyvsp[-2].strval), "array", VOID,scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Array %s was declared with a different RETURN type. Already returns type INT\n", row, col, (yyvsp[-2].strval));//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup((yyvsp[-2].strval), "array", VOID,scope) ==-3)
				{printf("Can't have two names %s of different types.  %s is was declared as an array\n", (yyvsp[-2].strval),(yyvsp[-2].strval));}	
			

			else {
				printf("Semantic Error: row = %d\tcol = %d. Param Array %s already declared\n",row, col,(yyvsp[-2].strval)); 
			}
		}
#line 1709 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 357 "cminus.y" /* yacc.c:1646  */
    {scope++;scopeChange = 1;}
#line 1715 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 357 "cminus.y" /* yacc.c:1646  */
    {scope--;scopeChange = 1;}
#line 1721 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 386 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = genLabel();}
#line 1727 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 386 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = genLabel();}
#line 1733 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 386 "cminus.y" /* yacc.c:1646  */
    {if(relopsFlag ==1){printf("%s\n", (yyvsp[-3].strval));}else{printf("ifeq %s\n", (yyvsp[-3].strval));}relopsFlag = 0;}
#line 1739 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 386 "cminus.y" /* yacc.c:1646  */
    {printf("goto %s\n",(yyvsp[-4].strval)); }
#line 1745 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 386 "cminus.y" /* yacc.c:1646  */
    {printf("%s:\n", (yyvsp[-7].strval));}
#line 1751 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 386 "cminus.y" /* yacc.c:1646  */
    {printf("%s:\n", (yyvsp[-8].strval));}
#line 1757 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 389 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = genLabel();}
#line 1763 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 389 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = genLabel();}
#line 1769 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 389 "cminus.y" /* yacc.c:1646  */
    {printf("%s:\n",(yyvsp[-2].strval));}
#line 1775 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 389 "cminus.y" /* yacc.c:1646  */
    {if(relopsFlag ==1){printf("%s\n",(yyvsp[-3].strval));}else{printf("ldc 0\nif_icmple %s\n", (yyvsp[-3].strval));}}
#line 1781 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 389 "cminus.y" /* yacc.c:1646  */
    {relopsFlag = 0;}
#line 1787 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 389 "cminus.y" /* yacc.c:1646  */
    {printf("goto %s\n",(yyvsp[-8].strval)); printf("%s:\n", (yyvsp[-7].strval));}
#line 1793 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 396 "cminus.y" /* yacc.c:1646  */
    {genBeginPrint();}
#line 1799 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 396 "cminus.y" /* yacc.c:1646  */
    {genEndPrint();}
#line 1805 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 400 "cminus.y" /* yacc.c:1646  */
    {if (st_lookup((yyvsp[-2].strval), "variable", INT,scope) ==-1)
	 			{
				printf("Semantic Error:row = %d\tcol = %d.  Scan Variable %s not previously declared\n",row, col, (yyvsp[-2].strval));
				} 
else if(st_lookup((yyvsp[-2].strval), "variable", INT,scope) ==-2)
				{
				//this probably won't happen but
			printf("Semantic Error: row = %d\tcol = %d. Variable was declared of type VOID. Abort Operation.\n",row, col);
				}
				else if (st_lookup((yyvsp[-2].strval), "variable", INT,scope) ==-3)
				//this won't happen either
{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s was already declared as an array or function\n", row, col, (yyvsp[-2].strval),(yyvsp[-2].strval));}
				else{
				/*It worked*/if(scanCalled ==0){printf("new java/util/Scanner\ndup\ngetstatic java/lang/System/in Ljava/io/InputStream;\ninvokenonvirtual java/util/Scanner/<init>(Ljava/io/InputStream;)V\nastore 1\n");}scanNow(1);scanCalled =1;;if(returnScope((yyvsp[-2].strval)) ==0)
					{printf("putstatic Main/%s I\n", (yyvsp[-2].strval));}
					else{
					printf("istore %d\n",jvm_lookup((yyvsp[-2].strval), "variable",INT, scope));}
				}				
				}
#line 1829 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 422 "cminus.y" /* yacc.c:1646  */
    {
			if (st_lookup((yyvsp[0].strval), "variable", INT, scope) ==-1) {
				printf("Semantic Error:row = %d\tcol = %d. Exp Variable %s not previously declared\n",row, col, (yyvsp[0].strval));  
				}
				else {/*genLoadVar(scope,jvm_lookup($1, "variable",INT, scope), $1);*/}}
#line 1839 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 428 "cminus.y" /* yacc.c:1646  */
    {
			if (st_lookup((yyvsp[-4].strval), "variable", INT,scope) ==-1) {
				printf("Semantic Error:row = %d\tcol = %d. Exp Variable %s not previously declared\n",row, col, (yyvsp[-4].strval)); 
				} 
			else if(st_lookup((yyvsp[-4].strval), "variable", INT,scope) ==-2)
			 {printf("Semantic Error: row = %d\tcol = %d. Mismatched return type\n", row, col);}

			else if (st_lookup((yyvsp[-4].strval), "variable", INT,scope) ==-3) 
			{printf("Semantic Error: row = %d\tcol = %d. Mismatched type \n", row, col);}
                           else {if(returnScope((yyvsp[-4].strval)) ==0)
					{printf("putstatic Main/%s I\n", (yyvsp[-4].strval));}
					else{
					printf("istore %d\n",jvm_lookup((yyvsp[-4].strval), "variable",INT, scope));}}
}
#line 1858 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 442 "cminus.y" /* yacc.c:1646  */
    {if (st_lookup((yyvsp[0].strval), "array", INT, scope) ==-1) {
	printf("Semantic Error: row = %d\tcol = %d.Exp Array %s not previously declared\n",row, col, (yyvsp[0].strval)); }else {genLoadArr(returnScope((yyvsp[0].strval)),jvm_lookup((yyvsp[0].strval), "array",INT, returnScope((yyvsp[0].strval))), (yyvsp[0].strval));}}
#line 1865 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 444 "cminus.y" /* yacc.c:1646  */
    {if (st_lookup((yyvsp[-7].strval), "array", INT,scope) ==-1) {
	printf("Semantic Error: row = %d\tcol = %d.Exp Array %s not previously declared\n",row, col, (yyvsp[-7].strval)); }  else if (st_lookup((yyvsp[-7].strval), "array", INT,scope) ==-2) {printf("Semantic Error: row = %d\tcol = %d.Mismatched return type\n", row,col);}else if (st_lookup((yyvsp[-7].strval), "array", INT,scope) ==-3) {printf("Semantic Error:row = %d\tcol = %d. Mismatched type \n",row, col);}
			else { 
					printf("iastore\n");
					}
}
#line 1876 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 452 "cminus.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);  printf("%s", (yyvsp[-1].strval));}
#line 1882 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 453 "cminus.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1888 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 456 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = "if_icmpgt ";relopsFlag = 1;}
#line 1894 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 457 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = "if_icmpge ";relopsFlag = 1;}
#line 1900 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 458 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = "if_icmple ";relopsFlag = 1;}
#line 1906 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 459 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = "if_icmplt ";relopsFlag = 1;}
#line 1912 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 460 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = "if_icmpeq ";relopsFlag = 1;}
#line 1918 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 461 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = "if_icmpne ";relopsFlag = 1;}
#line 1924 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 464 "cminus.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);printf("%s\n", (yyvsp[-1].strval));}
#line 1930 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 465 "cminus.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval); }
#line 1936 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 468 "cminus.y" /* yacc.c:1646  */
    {oppFlag = 1;(yyval.strval) = "iadd"; }
#line 1942 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 469 "cminus.y" /* yacc.c:1646  */
    {oppFlag = 1;(yyval.strval) = "isub"; }
#line 1948 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 472 "cminus.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);printf("%s\n", (yyvsp[-1].strval));}
#line 1954 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 473 "cminus.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval); }
#line 1960 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 476 "cminus.y" /* yacc.c:1646  */
    {oppFlag = 1;(yyval.strval) = "imul"; }
#line 1966 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 477 "cminus.y" /* yacc.c:1646  */
    {oppFlag = 1;(yyval.strval) = "idiv"; }
#line 1972 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 482 "cminus.y" /* yacc.c:1646  */
    {genLoadConst((yyvsp[0].intval));if ((callFlag ==1)&&(brackFlag==0) ){  if ((flag == 0)){strcpy(save, print);flag = 1;}
			else{}}}
#line 1979 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 484 "cminus.y" /* yacc.c:1646  */
    {brackFlag = 1;if (st_lookup((yyvsp[-1].strval), "array", INT, scope) ==-1) {
	printf("Semantic Error: row = %d\tcol = %d.Factor Array %s not previously declared\n",row, col, (yyvsp[-1].strval)); 
				}else {print = "[I";genLoadArr(returnScope((yyvsp[-1].strval)),jvm_lookup((yyvsp[-1].strval), "array",INT, returnScope((yyvsp[-1].strval))), (yyvsp[-1].strval)); }}
#line 1987 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 486 "cminus.y" /* yacc.c:1646  */
    {brackFlag = 0;printf("iaload\n");}
#line 1993 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 489 "cminus.y" /* yacc.c:1646  */
    {  if (nameUsed((yyvsp[0].strval)) ==-1) {
			printf("Semantic Factor Error:  row = %d\tcol = %d. %s not previously declared \n",row, col, (yyvsp[0].strval));
			} 
                     
			else{ 
                   	     string = returnKind((yyvsp[0].strval));
			     if(strcmp(string, "variable") ==0)
				{
				print = "I"; 
				if ((mainFlag !=0)||(returnTwice((yyvsp[0].strval))==0)){genLoadVar(returnScope((yyvsp[0].strval)), jvm_lookup((yyvsp[0].strval), "variable", INT, returnScope((yyvsp[0].strval))),(yyvsp[0].strval));} 
				else {genLoadVar( scope, jvm_lookup((yyvsp[0].strval), "variable", INT, returnScope((yyvsp[0].strval))),(yyvsp[0].strval));}}
			      else
			      {   
				print = "[I";
				genLoadArr(returnScope((yyvsp[0].strval)), jvm_lookup((yyvsp[0].strval), "variable", INT, returnScope((yyvsp[0].strval))),(yyvsp[0].strval));
                              }  
		        if ((flag == 0) && (oppFlag ==0)){strcpy(save, print);flag = 1;}
			else{if(oppFlag ==0){strcat(save, print);}}
	  	}}
#line 2017 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 510 "cminus.y" /* yacc.c:1646  */
    {callFlag=1;flag=0;oppFlag = 0;for(refresh = 0; refresh < 80;refresh++)
				{strcpy(save, blank); }
				}
#line 2025 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 513 "cminus.y" /* yacc.c:1646  */
    {if (st_lookup((yyvsp[-3].strval), "function", type, scope) ==-1) 
	    		{
			printf("Semantic Error: Function %s not previously declared\n",(yyvsp[-3].strval)); }		
		/*else if(returnType($1) !=type){
			if(returnType($1)==261){compare = "VOID";} else {compare = "INT"; }
			printf("Semantic Error:  Function %s is already declared of type %s ", $1, compare );
	}      */else if(returnKind((yyvsp[-3].strval))!="function"){printf("Semantic Error: row = %d\tcol = %d. Function %s not previously declared\n",row, col, (yyvsp[-3].strval)); }else{printf("invokestatic Main/%s(",(yyvsp[-3].strval));
	if(flag ==1){printf("%s", save);}}}
#line 2038 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 522 "cminus.y" /* yacc.c:1646  */
    {scopeChange=1;if(returnType((yyvsp[-5].strval))==INT){printf(")I\n");} else{printf(")V\n");}callFlag=0;}
#line 2044 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 526 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = (yyvsp[0].strval); }
#line 2050 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 530 "cminus.y" /* yacc.c:1646  */
    {(yyval.strval) = concat(concat((yyvsp[-2].strval), ","),(yyvsp[-2].strval)); }
#line 2056 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 531 "cminus.y" /* yacc.c:1646  */
    { oppFlag = 0;(yyval.strval) = (yyvsp[0].strval); }
#line 2062 "cminus.tab.c" /* yacc.c:1646  */
    break;


#line 2066 "cminus.tab.c" /* yacc.c:1646  */
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
#line 534 "cminus.y" /* yacc.c:1906  */

void yyerror (char const *s)  /* Called by yyparse on error */
{
  printf("Error: syntax error at row = %d\tcol = %d. Got: %s\t\n", row, col,yytext);
  printf ("%s\n", s);
}

char * concat( char * str1, char * str2) {

 char *str3;
 str3 = (char *)calloc(strlen(str1) + strlen(str2) + 1,
 sizeof(char));
 strcpy(str3, str1);
 strcat(str3, str2);

 return str3;
}


