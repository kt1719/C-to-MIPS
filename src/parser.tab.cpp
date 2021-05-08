/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

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
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y" /* yacc.c:355  */

  #include "ast.hpp"
  #include <cassert>

  extern Node *g_root; // A way of getting the AST out


  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  extern int yylex(void);
  extern int yyparse();
  extern FILE *yyin;
  void yyerror(const char *);

#line 113 "src/parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_WHILE = 258,
    T_FOR = 259,
    T_IF = 260,
    T_ELSE = 261,
    T_INT = 262,
    T_VOID = 263,
    T_ENUM = 264,
    T_RETURN = 265,
    T_BREAK = 266,
    T_CONTINUE = 267,
    T_SWITCH = 268,
    T_CASE = 269,
    T_DEFAULT = 270,
    GOTO = 271,
    T_DO = 272,
    T_ADDEQUAL = 273,
    T_DIVIDEEQUAL = 274,
    T_MODEQUAL = 275,
    T_SUBEQUAL = 276,
    T_MULTEQUAL = 277,
    T_LEFTEQUAL = 278,
    T_RIGHTEQUAL = 279,
    T_ANDEQUAL = 280,
    T_XOREQUAL = 281,
    T_OREQUAL = 282,
    T_SHIFTRIGHT = 283,
    T_SHIFTLEFT = 284,
    T_LESSTHAN = 285,
    T_GREATERTHAN = 286,
    T_GREATERTHANEQUAL = 287,
    T_LESSTHANEQUAL = 288,
    T_STRUCT = 289,
    T_UNION = 290,
    T_OR = 291,
    T_AND = 292,
    T_NOT = 293,
    T_MODULO = 294,
    T_EQUAL = 295,
    T_ASSIGN = 296,
    T_NOTEQUAL = 297,
    T_INVERT = 298,
    T_AND_OP = 299,
    T_OR_OP = 300,
    T_CONST = 301,
    T_VOLATILE = 302,
    T_MULTIPLY = 303,
    T_DIV = 304,
    T_ADD = 305,
    T_SUB = 306,
    T_XOR = 307,
    INC_OP = 308,
    DEC_OP = 309,
    T_EXTERN = 310,
    T_TYPEDEF = 311,
    T_STATIC = 312,
    T_ELLIPSIS = 313,
    T_LBRACKET = 314,
    T_RBRACKET = 315,
    L_SQRBRACKET = 316,
    R_SQRBRACKET = 317,
    T_LCURLY = 318,
    T_RCURLY = 319,
    T_SEMICOLON = 320,
    T_COMMA = 321,
    T_COLON = 322,
    T_QUESTION = 323,
    T_PERIOD = 324,
    T_UNSIGNED = 325,
    T_CHAR = 326,
    T_SIZEOF = 327,
    T_FLOAT = 328,
    T_DOUBLE = 329,
    T_NUM = 330,
    T_VARIABLE = 331,
    T_CHARVAL = 332
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "src/parser.y" /* yacc.c:355  */

  Node *expr;
  double number;
  std::string *string;

#line 209 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1027

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   332

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    45,    46,    47,    50,    51,    52,    53,
      54,    55,    56,    60,    61,    64,    65,    66,    67,    68,
      69,    70,    73,    74,    75,    76,    77,    78,    81,    84,
      85,    86,    87,    90,    91,    92,    95,    96,    97,   100,
     101,   102,   103,   104,   107,   108,   109,   114,   115,   118,
     119,   122,   123,   126,   127,   130,   131,   134,   135,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     151,   152,   167,   168,   171,   174,   175,   179,   180,   181,
     182,   183,   184,   191,   192,   195,   196,   197,   200,   201,
     202,   203,   204,   205,   206,   240,   241,   242,   245,   246,
     249,   250,   253,   254,   258,   261,   262,   263,   264,   265,
     266,   267,   281,   282,   285,   286,   289,   290,   293,   294,
     317,   318,   319,   323,   324,   327,   328,   329,   330,   331,
     332,   335,   336,   337,   340,   341,   342,   343,   346,   347,
     350,   351,   354,   355,   359,   360,   361,   364,   365,   366,
     367,   368,   371,   372,   373,   374,   375,   378,   379,   382,
     383,   386,   387,   388,   389,   395
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_WHILE", "T_FOR", "T_IF", "T_ELSE",
  "T_INT", "T_VOID", "T_ENUM", "T_RETURN", "T_BREAK", "T_CONTINUE",
  "T_SWITCH", "T_CASE", "T_DEFAULT", "GOTO", "T_DO", "T_ADDEQUAL",
  "T_DIVIDEEQUAL", "T_MODEQUAL", "T_SUBEQUAL", "T_MULTEQUAL",
  "T_LEFTEQUAL", "T_RIGHTEQUAL", "T_ANDEQUAL", "T_XOREQUAL", "T_OREQUAL",
  "T_SHIFTRIGHT", "T_SHIFTLEFT", "T_LESSTHAN", "T_GREATERTHAN",
  "T_GREATERTHANEQUAL", "T_LESSTHANEQUAL", "T_STRUCT", "T_UNION", "T_OR",
  "T_AND", "T_NOT", "T_MODULO", "T_EQUAL", "T_ASSIGN", "T_NOTEQUAL",
  "T_INVERT", "T_AND_OP", "T_OR_OP", "T_CONST", "T_VOLATILE", "T_MULTIPLY",
  "T_DIV", "T_ADD", "T_SUB", "T_XOR", "INC_OP", "DEC_OP", "T_EXTERN",
  "T_TYPEDEF", "T_STATIC", "T_ELLIPSIS", "T_LBRACKET", "T_RBRACKET",
  "L_SQRBRACKET", "R_SQRBRACKET", "T_LCURLY", "T_RCURLY", "T_SEMICOLON",
  "T_COMMA", "T_COLON", "T_QUESTION", "T_PERIOD", "T_UNSIGNED", "T_CHAR",
  "T_SIZEOF", "T_FLOAT", "T_DOUBLE", "T_NUM", "T_VARIABLE", "T_CHARVAL",
  "$accept", "PRIM_EXPR", "POSTFIX_EXPR", "ARG_EXPR_LIST", "UNARY_EXPR",
  "UNARY_OP", "CAST_EXPR", "MULT_EXPR", "ADD_EXPR", "SHIFT_EXPR",
  "COMPARISON_EXPR", "EQUAL_EXPR", "AND_EXPR", "XOR_EXPR",
  "INCLUSIVE_OR_EXPR", "LOGIC_AND_EXPR", "LOGIC_OR_EXPR", "CONDITION_EXPR",
  "ASSIGN_OP", "ASSIGN_EXPR", "EXPR", "CONST_EXPR", "DECLARATION",
  "DECLARATION_SPE", "INITIALISE_DECLARATOR", "STORAGE_CLASS_SPE",
  "TYPE_SPE", "ENUM_SPECIFIER", "ENUM_LIST", "ENUMERATOR",
  "TYPE_QUALIFIER", "DECLARATOR", "DIRECT_DECL", "PARAM_TYPE_LIST",
  "PARAM_LIST", "PARAM_DECLARATION", "T_VARIABLE_LIST", "VARIABLE_STORE",
  "VARIABLE_STORE_LIST", "STATEMENT", "LABELED_STATEMENT",
  "COMPOUND_STATEMENT", "DECLARATION_LIST", "STATEMENT_LIST",
  "EXPR_STATEMENT", "SELECT_STATEMENT", "ITERATION_STATEMENT",
  "JUMP_STATEMENT", "TRANSLATION_UNIT", "EXTERN_DECL", "FUNCT_DEF", "ROOT", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     642,  -129,  -129,   -54,  -129,  -129,  -129,  -129,  -129,   -52,
    -129,  -129,  -129,  -129,  -129,  -129,   -49,   439,   439,  -129,
     439,   188,   -44,   642,  -129,  -129,    23,   -18,    -2,     9,
    -129,    40,   686,  -129,  -129,  -129,   262,  -129,   -49,  -129,
     188,   664,   780,  -129,  -129,    33,    18,  -129,   -18,  -129,
    -129,   800,  -129,   188,    19,    36,    43,   830,    49,    54,
      91,   930,    87,    84,   562,  -129,  -129,  -129,  -129,  -129,
    -129,   930,   930,   930,  -129,  -129,   950,  -129,    90,  -129,
    -129,   -22,   270,   930,  -129,     5,    35,    81,    61,    30,
     127,   114,   131,   126,   -32,  -129,  -129,    46,  -129,  -129,
    -129,   337,   412,  -129,  -129,  -129,  -129,   130,  -129,  -129,
    -129,  -129,   -52,   112,   107,  -129,   -20,  -129,  -129,    62,
    -129,   113,   930,  -129,   -18,    37,   800,  -129,  -129,  -129,
     930,   610,   930,  -129,    52,  -129,  -129,   930,   109,   562,
     116,   171,    62,    62,   -10,   140,    62,   562,   850,   930,
     103,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,   930,  -129,   930,   930,   930,   930,
     930,   930,   930,   930,   930,   930,   930,   930,   930,   930,
     930,   930,   930,   930,   930,  -129,   930,  -129,   487,  -129,
    -129,  -129,  -129,   721,  -129,   106,  -129,  -129,  -129,  -129,
    -129,    42,    -3,   880,   880,     0,  -129,     2,   562,  -129,
    -129,   124,  -129,   125,   129,  -129,  -129,   132,   120,   -48,
    -129,  -129,  -129,  -129,  -129,     5,     5,    35,    35,    81,
      81,    81,    81,    61,    61,    30,   127,   127,   131,   126,
      55,  -129,  -129,  -129,  -129,  -129,  -129,   750,   562,   930,
     900,   562,   562,  -129,   930,  -129,  -129,  -129,   930,  -129,
     930,  -129,  -129,  -129,    13,   562,    17,   181,  -129,   -11,
    -129,  -129,   562,  -129,   562,   562,   135,  -129,  -129,  -129,
    -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    91,    88,     0,   102,   103,    86,    85,    87,     0,
      92,    89,    90,    93,   105,   160,     0,    77,    79,    94,
      81,     0,   104,   165,   157,   159,     0,     0,    97,     0,
      75,     0,    83,    78,    80,    82,     0,   138,     0,   164,
       0,     0,     0,   158,     1,   100,     0,    98,     0,   106,
      76,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    27,    26,    23,    24,
      25,     0,     0,     0,   134,   142,     0,     3,     2,     4,
       6,    15,    28,     0,    29,    33,    36,    39,    44,    47,
      49,    51,    53,    55,    57,    70,    72,     0,   140,   125,
     126,     0,     0,   127,   128,   129,   130,    83,   139,   163,
     111,   118,   117,     0,   112,   114,     0,   108,     2,    28,
      74,     0,     0,    95,     0,     0,     0,   120,    84,   161,
       0,     0,     0,   155,     0,   154,   153,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    59,    11,    12,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,     0,   136,     0,   135,
     141,   116,   109,     0,   110,     0,   107,   101,    99,    96,
     123,     0,     0,     0,     0,     0,   156,     0,     0,   133,
     152,     0,     5,     6,     0,   131,     8,     0,    13,     0,
      10,    71,    32,    30,    31,    34,    35,    38,    37,    40,
      41,    43,    42,    45,    46,    48,    50,    52,    54,    56,
       0,    73,   137,   113,   115,   119,   121,     0,     0,     0,
       0,     0,     0,   132,     0,    20,    21,     9,     0,     7,
       0,   122,   124,   147,     0,     0,     0,   144,   146,     0,
      14,    58,     0,   149,     0,     0,     0,   151,   150,   145,
     148
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,    57,  -129,   -51,   -42,  -129,   -78,   -17,   -16,   -76,
      -9,    24,   -19,  -129,    22,    38,  -129,   -41,  -129,    -6,
      14,   -55,    12,     8,  -129,  -129,    75,  -129,   158,    99,
    -129,    -5,  -129,  -129,  -129,    31,  -129,  -124,  -129,   -43,
    -129,    11,     6,   136,  -128,  -129,  -129,  -129,  -129,   202,
    -129,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    80,    81,   217,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   164,    96,
      97,   121,    37,    38,    31,    17,    18,    19,    46,    47,
      20,    21,    22,   113,   114,   115,   116,   128,   201,    98,
      99,   100,    40,   102,   103,   104,   105,   106,    23,    24,
      25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     119,   120,   200,   204,    29,   165,   138,     9,    16,    27,
       9,    32,    15,   183,   259,    41,    30,    42,   186,   119,
     120,   141,    28,    44,    14,    33,    34,    14,    35,   142,
     143,    16,    39,   107,   146,    15,   184,   148,    53,   149,
     194,   119,   101,    52,   166,   127,   195,   150,   276,   112,
     212,   109,   108,   167,   168,   186,   186,   248,    45,   190,
     251,    48,   252,   186,   129,   108,   186,   197,   186,    49,
     177,   134,   178,   272,   122,   249,   250,   274,   130,   186,
     119,   120,   123,   186,   124,   169,   170,   144,   222,   223,
     224,   173,   174,   175,   176,   131,   209,   229,   230,   231,
     232,   199,   132,   124,   215,    50,   246,   191,   247,   171,
     172,   185,   186,   108,   135,   162,   163,   206,   186,   136,
     127,   186,   260,   262,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   218,   203,   202,   190,   205,     1,     2,     3,
     137,   207,   225,   226,   139,   227,   228,   147,   221,   144,
     140,   236,   237,   219,   179,   253,   180,   181,   233,   234,
     182,    51,   192,   193,   211,   196,   208,    65,    66,   220,
     241,   210,   245,    67,   254,   255,   258,   275,    68,   256,
      69,    70,   257,    71,    72,     1,     2,     3,   240,    73,
     280,   112,   213,   235,   238,   263,   125,   270,   267,   268,
      10,    11,    76,    12,    13,    77,   118,    79,   119,   271,
     214,   239,   273,   198,   244,    43,     0,     0,     0,   277,
       0,   278,   279,     0,     4,     5,     0,   188,     0,     0,
       0,   127,     0,     6,     7,     8,     0,     0,     0,     0,
       0,    36,   218,     0,     0,     0,     0,     0,    10,    11,
       0,    12,    13,   264,   266,    54,    55,    56,   269,     1,
       2,     3,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,    65,
      66,     0,     0,     0,     0,    67,     0,     0,     4,     5,
      68,   161,    69,    70,     0,    71,    72,     6,     7,     8,
       0,    73,     0,   162,   163,    36,    74,    75,     0,     0,
       0,     0,    10,    11,    76,    12,    13,    77,    78,    79,
      54,    55,    56,     0,     1,     2,     3,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,     0,     0,     0,     0,
      67,     0,     0,     4,     5,    68,     0,    69,    70,     0,
      71,    72,     6,     7,     8,     0,    73,     0,     0,     0,
      36,   187,    75,     0,     0,     0,     0,    10,    11,    76,
      12,    13,    77,    78,    79,    54,    55,    56,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,    65,
      66,     0,     0,     0,     0,    67,     0,     0,     0,     0,
      68,     0,    69,    70,     0,    71,    72,     0,     0,     0,
       0,    73,     0,     0,     0,    36,   189,    75,     0,     0,
       0,     0,     0,     0,    76,     4,     5,    77,    78,    79,
      54,    55,    56,     0,     6,     7,     8,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,    10,
      11,     0,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,     0,     0,     0,     0,
      67,     0,     0,     0,     0,    68,     0,    69,    70,     0,
      71,    72,     0,     0,     0,     0,    73,     0,     0,     0,
      36,   242,    75,     0,     0,     0,     0,     0,     0,    76,
       0,     0,    77,    78,    79,    54,    55,    56,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,     0,     0,     0,     0,    67,     0,     0,     0,     0,
      68,     0,    69,    70,     0,    71,    72,     1,     2,     3,
       0,    73,     0,     0,     0,    36,     0,    75,     0,     0,
       0,     0,     0,     0,    76,     0,     0,    77,    78,    79,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     1,
       2,     3,     0,    67,     0,     0,     4,     5,    68,     0,
      69,    70,     0,    71,    72,     6,     7,     8,     0,    73,
       0,     1,     2,     3,     0,    75,     0,     0,     0,     0,
      10,    11,    76,    12,    13,    77,   118,    79,     4,     5,
       0,     0,     0,     1,     2,     3,     0,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,    10,    11,     0,    12,    13,     0,    14,     6,
       7,     8,     0,     0,   110,     0,     0,    51,     1,     2,
       3,     0,     4,     5,    10,    11,     0,    12,    13,     0,
     111,     6,     7,     8,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,    10,    11,     0,    12,
      13,     0,     0,     0,     0,     0,     0,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,   243,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
       0,    10,    11,    67,    12,    13,     0,     0,    68,     0,
      69,    70,     0,    71,    72,     0,     0,     0,     0,    73,
       0,     0,     0,   126,   261,     0,     0,    65,    66,     0,
       0,     0,    76,    67,     0,    77,   118,    79,    68,     0,
      69,    70,     0,    71,    72,     0,     0,    65,    66,    73,
       0,     0,   117,    67,     0,     0,     0,     0,    68,     0,
      69,    70,    76,    71,    72,    77,   118,    79,     0,    73,
       0,     0,     0,   126,     0,     0,     0,    65,    66,     0,
       0,     0,    76,    67,     0,    77,   118,    79,    68,     0,
      69,    70,     0,    71,    72,     0,     0,    65,    66,    73,
       0,     0,     0,    67,     0,   133,     0,     0,    68,     0,
      69,    70,    76,    71,    72,    77,   118,    79,     0,    73,
     216,     0,     0,     0,     0,     0,     0,    65,    66,     0,
       0,     0,    76,    67,     0,    77,   118,    79,    68,     0,
      69,    70,     0,    71,    72,     0,     0,    65,    66,    73,
       0,     0,     0,    67,     0,    75,     0,     0,    68,     0,
      69,    70,    76,    71,    72,    77,   118,    79,     0,    73,
     265,     0,     0,     0,     0,     0,     0,    65,    66,     0,
       0,     0,    76,    67,     0,    77,   118,    79,    68,     0,
      69,    70,     0,    71,    72,     0,     0,    65,    66,    73,
       0,     0,     0,    67,     0,     0,     0,     0,    68,     0,
      69,    70,    76,    71,    72,    77,   118,    79,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,    77,   118,    79
};

static const yytype_int16 yycheck[] =
{
      42,    42,   126,   131,     9,    83,    61,    59,     0,    63,
      59,    16,     0,    45,    62,    59,    65,    61,    66,    61,
      61,    64,    76,     0,    76,    17,    18,    76,    20,    71,
      72,    23,    21,    38,    76,    23,    68,    59,    32,    61,
      60,    83,    36,    32,    39,    51,    66,    69,    59,    41,
      60,    40,    40,    48,    49,    66,    66,    60,    76,   102,
      60,    63,    60,    66,    53,    53,    66,   122,    66,    60,
      40,    57,    42,    60,    41,   203,   204,    60,    59,    66,
     122,   122,    64,    66,    66,    50,    51,    73,   166,   167,
     168,    30,    31,    32,    33,    59,   139,   173,   174,   175,
     176,    64,    59,    66,   147,    65,    64,   112,    66,    28,
      29,    65,    66,   101,    65,    53,    54,    65,    66,    65,
     126,    66,    67,   247,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   148,   131,   130,   188,   132,     7,     8,     9,
      59,   137,   169,   170,    67,   171,   172,    67,   164,   145,
      76,   180,   181,   149,    37,   208,    52,    36,   177,   178,
      44,    41,    60,    66,     3,    62,    67,    37,    38,    76,
     186,    65,    76,    43,    60,    60,    66,     6,    48,    60,
      50,    51,    60,    53,    54,     7,     8,     9,   184,    59,
      65,   193,   145,   179,   182,   248,    48,   258,   251,   252,
      70,    71,    72,    73,    74,    75,    76,    77,   260,   260,
     145,   183,   265,   124,   193,    23,    -1,    -1,    -1,   272,
      -1,   274,   275,    -1,    46,    47,    -1,   101,    -1,    -1,
      -1,   247,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,   258,    -1,    -1,    -1,    -1,    -1,    70,    71,
      -1,    73,    74,   249,   250,     3,     4,     5,   254,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      48,    41,    50,    51,    -1,    53,    54,    55,    56,    57,
      -1,    59,    -1,    53,    54,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46,    47,    48,    -1,    50,    51,    -1,
      53,    54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    -1,    53,    54,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    46,    47,    75,    76,    77,
       3,     4,     5,    -1,    55,    56,    57,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    70,
      71,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,
      53,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    75,    76,    77,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    -1,    53,    54,     7,     8,     9,
      -1,    59,    -1,    -1,    -1,    63,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,     7,
       8,     9,    -1,    43,    -1,    -1,    46,    47,    48,    -1,
      50,    51,    -1,    53,    54,    55,    56,    57,    -1,    59,
      -1,     7,     8,     9,    -1,    65,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    46,    47,
      -1,    -1,    -1,     7,     8,     9,    -1,    55,    56,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    70,    71,    -1,    73,    74,    -1,    76,    55,
      56,    57,    -1,    -1,    60,    -1,    -1,    41,     7,     8,
       9,    -1,    46,    47,    70,    71,    -1,    73,    74,    -1,
      76,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    70,    71,    43,    73,    74,    -1,    -1,    48,    -1,
      50,    51,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    63,    64,    -1,    -1,    37,    38,    -1,
      -1,    -1,    72,    43,    -1,    75,    76,    77,    48,    -1,
      50,    51,    -1,    53,    54,    -1,    -1,    37,    38,    59,
      -1,    -1,    62,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    72,    53,    54,    75,    76,    77,    -1,    59,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    72,    43,    -1,    75,    76,    77,    48,    -1,
      50,    51,    -1,    53,    54,    -1,    -1,    37,    38,    59,
      -1,    -1,    -1,    43,    -1,    65,    -1,    -1,    48,    -1,
      50,    51,    72,    53,    54,    75,    76,    77,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    72,    43,    -1,    75,    76,    77,    48,    -1,
      50,    51,    -1,    53,    54,    -1,    -1,    37,    38,    59,
      -1,    -1,    -1,    43,    -1,    65,    -1,    -1,    48,    -1,
      50,    51,    72,    53,    54,    75,    76,    77,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    72,    43,    -1,    75,    76,    77,    48,    -1,
      50,    51,    -1,    53,    54,    -1,    -1,    37,    38,    59,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    72,    53,    54,    75,    76,    77,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    75,    76,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    46,    47,    55,    56,    57,    59,
      70,    71,    73,    74,    76,   100,   101,   103,   104,   105,
     108,   109,   110,   126,   127,   128,   129,    63,    76,   109,
      65,   102,   109,   101,   101,   101,    63,   100,   101,   119,
     120,    59,    61,   127,     0,    76,   106,   107,    63,    60,
      65,    41,   119,   120,     3,     4,     5,    10,    11,    12,
      13,    14,    15,    16,    17,    37,    38,    43,    48,    50,
      51,    53,    54,    59,    64,    65,    72,    75,    76,    77,
      79,    80,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    97,    98,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   109,   100,   119,
      60,    76,   101,   111,   112,   113,   114,    62,    76,    82,
      95,    99,    41,    64,    66,   106,    63,    97,   115,   119,
      59,    59,    59,    65,    98,    65,    65,    59,    99,    67,
      76,   117,    82,    82,    98,    59,    82,    67,    59,    61,
      69,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    41,    53,    54,    96,    84,    39,    48,    49,    50,
      51,    28,    29,    30,    31,    32,    33,    40,    42,    37,
      52,    36,    44,    45,    68,    65,    66,    64,   121,    64,
     117,   109,    60,    66,    60,    66,    62,    99,   107,    64,
     115,   116,    98,   100,   122,    98,    65,    98,    67,   117,
      65,     3,    60,    79,   104,   117,    60,    81,    97,    98,
      76,    97,    84,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    87,    88,    88,    89,    90,    90,    92,    93,
      98,    97,    64,    58,   113,    76,    64,    66,    60,   122,
     122,    60,    60,   117,    60,    60,    60,    60,    66,    62,
      67,    64,   115,   117,    98,    60,    98,   117,   117,    98,
      81,    95,    60,   117,    60,     6,    59,   117,   117,   117,
      65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    84,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    87,    88,
      88,    88,    88,    88,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    99,   100,   100,   101,   101,   101,
     101,   101,   101,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   116,   116,   117,   117,   117,   117,   117,
     117,   118,   118,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   123,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   128,   128,   128,   128,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     2,     2,     1,     3,     1,     2,     2,     2,     2,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     4,     3,     4,
       4,     3,     1,     3,     1,     3,     2,     1,     1,     3,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     4,     3,     3,     2,     1
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
#line 44 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new VariableName(*(yyvsp[0].string));}
#line 1677 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 45 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Number((yyvsp[0].number));}
#line 1683 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 46 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CharName(*(yyvsp[0].string));}
#line 1689 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 47 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);}
#line 1695 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 50 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1701 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 51 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new array_identifier((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1707 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 52 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_decl((yyvsp[-2].expr));}
#line 1713 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 53 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new function_decl((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1719 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 55 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new unaryExpr((yyvsp[-1].expr),*(yyvsp[0].string));}
#line 1725 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 56 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new unaryExpr((yyvsp[-1].expr),*(yyvsp[0].string));}
#line 1731 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Variable((yyvsp[0].expr));}
#line 1737 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 61 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new param_list(new Variable((yyvsp[-2].expr)),(yyvsp[0].expr));}
#line 1743 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 64 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1749 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 65 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new unaryOp(*(yyvsp[-1].string),(yyvsp[0].expr));}
#line 1755 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 66 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new unaryExpr(*(yyvsp[-1].string),(yyvsp[0].expr));}
#line 1761 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 67 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new unaryExpr(*(yyvsp[-1].string),(yyvsp[0].expr));}
#line 1767 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 68 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new sizeofsmtg{(yyvsp[0].expr)};}
#line 1773 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 69 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new sizeofsmtg{(yyvsp[-1].expr)};}
#line 1779 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 70 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new sizeofsmtg{(yyvsp[-1].expr)};}
#line 1785 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 73 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 1791 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 74 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 1797 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 75 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 1803 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1809 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 77 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 1815 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 78 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 1821 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1827 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 84 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1833 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 85 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new multOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1839 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 86 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new divOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1845 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 87 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new modOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1851 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 90 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1857 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 91 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new addOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1863 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 92 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new subOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1869 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 95 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1875 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 96 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new leftShiftOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1881 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 97 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new rightShiftOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1887 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 100 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1893 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 101 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new lessThan((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1899 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 102 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new greaterThan((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1905 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 103 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new lessEqualThan((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1911 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 104 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new greaterEqualThan((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1917 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 107 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1923 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 108 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new equal((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1929 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 109 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new notEqual((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1935 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 114 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1941 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new andOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1947 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 118 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1953 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 119 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new xorOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1959 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 122 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1965 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 123 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new orOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1971 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 126 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1977 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 127 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalAnd((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1983 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 130 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1989 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 131 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalOr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1995 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 134 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2001 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 135 "src/parser.y" /* yacc.c:1646  */
    {std::cout << "expr ? expr : condition" <<std::endl;}
#line 2007 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 138 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2013 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 139 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2019 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 140 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2025 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 141 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 2031 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 142 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2037 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 143 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2043 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 144 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2049 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 145 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2055 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 146 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2061 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 147 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2067 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 148 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string);}
#line 2073 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 151 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2079 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 152 "src/parser.y" /* yacc.c:1646  */
    {
          if (*(yyvsp[-1].string) == "="){ (yyval.expr) = new assignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "+="){ (yyval.expr) = new addAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "/="){ (yyval.expr) = new divAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "%="){ (yyval.expr) = new modAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "-="){ (yyval.expr) = new subAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "*="){ (yyval.expr) = new multAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "<<="){ (yyval.expr) = new leftshiftAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == ">>="){ (yyval.expr) = new rightshiftAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "&="){ (yyval.expr) = new andAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "^="){ (yyval.expr) = new exclOrAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          else if (*(yyvsp[-1].string) == "|="){ (yyval.expr) = new inclOrAssignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
          }
#line 2097 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 167 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2103 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 168 "src/parser.y" /* yacc.c:1646  */
    {std::cout << "||finally an expression" <<std::endl;}
#line 2109 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2115 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 174 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Variable((yyvsp[-1].expr));}
#line 2121 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Variable((yyvsp[-2].expr),(yyvsp[-1].expr));}
#line 2127 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 181 "src/parser.y" /* yacc.c:1646  */
    {  (yyval.expr) = (yyvsp[0].expr);}
#line 2133 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { }
#line 2139 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2145 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new assignOp((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2151 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 200 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new voidType(*(yyvsp[0].string));}
#line 2157 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new charType(*(yyvsp[0].string));}
#line 2163 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 202 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr)= new floatType(*(yyvsp[0].string));}
#line 2169 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 203 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new intType(*(yyvsp[0].string));}
#line 2175 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new unsignedType(*(yyvsp[0].string));}
#line 2181 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 205 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new doubleType(*(yyvsp[0].string));}
#line 2187 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 240 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new enum_Spe((yyvsp[-1].expr));}
#line 2193 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 241 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new enum_Spe(*(yyvsp[-3].string),(yyvsp[-1].expr));}
#line 2199 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 242 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new enum_Spe(*(yyvsp[0].string));}
#line 2205 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 245 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new enum_List((yyvsp[0].expr));}
#line 2211 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 246 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new enum_List((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2217 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 249 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Enumerator(*(yyvsp[0].string));}
#line 2223 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 250 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Enumerator(*(yyvsp[-2].string),(yyvsp[0].expr));}
#line 2229 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 258 "src/parser.y" /* yacc.c:1646  */
    {  (yyval.expr) = (yyvsp[0].expr);}
#line 2235 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 261 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new VariableName(*(yyvsp[0].string)); }
#line 2241 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);}
#line 2247 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new array_declaration((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 2253 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 264 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new array_declaration((yyvsp[-2].expr));}
#line 2259 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_decl((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 2265 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 266 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_decl((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 2271 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 267 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_decl((yyvsp[-2].expr));}
#line 2277 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].expr);}
#line 2283 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 282 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[-2].expr);}
#line 2289 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new param_list((yyvsp[0].expr));}
#line 2295 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 286 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new param_list((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2301 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Variable((yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2307 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 290 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Variable((yyvsp[0].expr));}
#line 2313 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 293 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new VariableName(*(yyvsp[0].string));}
#line 2319 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new variableList((yyvsp[-2].expr),new VariableName(*(yyvsp[0].string)));}
#line 2325 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2331 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);}
#line 2337 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-2].expr);}
#line 2343 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new variableStoreList((yyvsp[0].expr));}
#line 2349 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { new variableStoreList((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2355 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2361 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 328 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2367 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 329 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2373 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 330 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2379 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2385 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2391 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 335 "src/parser.y" /* yacc.c:1646  */
    {std::cout << "||LABALLED STATEMENT" <<std::endl;}
#line 2397 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 336 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)= new switchstmntcase((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2403 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)= new switchdefault((yyvsp[0].expr));}
#line 2409 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 340 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_stmnt();}
#line 2415 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 341 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_stmnt((yyvsp[-1].expr));}
#line 2421 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 342 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_stmnt((yyvsp[-1].expr));}
#line 2427 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_stmnt((yyvsp[-2].expr), (yyvsp[-1].expr));}
#line 2433 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 346 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)= new declarationlist((yyvsp[0].expr));}
#line 2439 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 347 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)= new declarationlist((yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2445 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 350 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr)= new stmntlist((yyvsp[0].expr));}
#line 2451 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 351 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr)= new stmntlist((yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2457 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 354 "src/parser.y" /* yacc.c:1646  */
    {std::cout << "||expr statement" <<std::endl;}
#line 2463 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 355 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);}
#line 2469 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 359 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ifstate((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2475 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 360 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new if_Elsestate((yyvsp[-4].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2481 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 361 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new switchstmnt((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2487 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new whilestmnt((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2493 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 366 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new forloop((yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2499 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 367 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new forloop((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2505 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new forloop((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2511 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 372 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Continue();}
#line 2517 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 373 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new Break();}
#line 2523 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 374 "src/parser.y" /* yacc.c:1646  */
    {}
#line 2529 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 375 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)= new return_stmnt((yyvsp[-1].expr));}
#line 2535 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 378 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new listthg((yyvsp[0].expr));}
#line 2541 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 379 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new listthg((yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2547 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 382 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2553 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 383 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2559 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 386 "src/parser.y" /* yacc.c:1646  */
    {  (yyval.expr) = new function_def((yyvsp[-3].expr), (yyvsp[-2].expr),(yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2565 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 387 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_def((yyvsp[-2].expr), (yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2571 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 388 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_def((yyvsp[-2].expr), (yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2577 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 389 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new function_def((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2583 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 395 "src/parser.y" /* yacc.c:1646  */
    { g_root = new top((yyvsp[0].expr));}
#line 2589 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2593 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 397 "src/parser.y" /* yacc.c:1906  */


Node *g_root; // Definition of variable (to match declaration earlier)

Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
