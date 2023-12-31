/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    stop = 258,
    EQ = 259,
    NE = 260,
    LE = 261,
    GE = 262,
    LS = 263,
    RS = 264,
    ANDAND = 265,
    OROR = 266,
    IDENT = 267,
    NUMBER = 268,
    UNUMBER = 269,
    DEFINED = 270,
    STRING = 271,
    WSPACE = 272,
    CMNT = 273,
    UMINUS = 274
  };
#endif
/* Tokens.  */
#define stop 258
#define EQ 259
#define NE 260
#define LE 261
#define GE 262
#define LS 263
#define RS 264
#define ANDAND 265
#define OROR 266
#define IDENT 267
#define NUMBER 268
#define UNUMBER 269
#define DEFINED 270
#define STRING 271
#define WSPACE 272
#define CMNT 273
#define UMINUS 274

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 106 "./cpy.y" /* yacc.c:1909  */

	struct nd node;

#line 96 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE cpp_yylval;

int cpp_yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
