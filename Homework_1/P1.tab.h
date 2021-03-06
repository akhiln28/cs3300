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

#ifndef YY_YY_P1_TAB_H_INCLUDED
# define YY_YY_P1_TAB_H_INCLUDED
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
    SCOLON = 258,
    CLASS = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    LPAREN = 263,
    RPAREN = 264,
    LFPAREN = 265,
    RFPAREN = 266,
    LSPAREN = 267,
    RSPAREN = 268,
    GT = 269,
    LT = 270,
    EQ = 271,
    PLUS = 272,
    MINUS = 273,
    DIV = 274,
    MUL = 275,
    COMMA = 276,
    PUBLIC = 277,
    STATIC = 278,
    VOID = 279,
    MAIN = 280,
    NEW = 281,
    EXTENDS = 282,
    THIS = 283,
    DEFINE = 284,
    TRUE = 285,
    FALSE = 286,
    BOOL = 287,
    AND = 288,
    OR = 289,
    NOT = 290,
    DOT = 291,
    LENGTH = 292,
    SYSTEM = 293,
    INT = 294,
    OTHER = 295,
    IDENTIFIER = 296,
    NUM = 297,
    STRING = 298,
    RETURN = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 148 "P1.y" /* yacc.c:1909  */

	char *str;

#line 103 "P1.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P1_TAB_H_INCLUDED  */
