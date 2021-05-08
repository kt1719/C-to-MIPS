/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 1 "src/parser.y" /* yacc.c:1909  */

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

#line 60 "src/parser.tab.hpp" /* yacc.c:1909  */

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
#line 17 "src/parser.y" /* yacc.c:1909  */

  Node *expr;
  double number;
  std::string *string;

#line 156 "src/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
