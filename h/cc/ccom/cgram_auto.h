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
    C_STRING = 258,
    C_ICON = 259,
    C_FCON = 260,
    C_NAME = 261,
    C_TYPENAME = 262,
    C_ANDAND = 263,
    C_OROR = 264,
    C_GOTO = 265,
    C_RETURN = 266,
    C_TYPE = 267,
    C_CLASS = 268,
    C_ASOP = 269,
    C_RELOP = 270,
    C_EQUOP = 271,
    C_DIVOP = 272,
    C_SHIFTOP = 273,
    C_INCOP = 274,
    C_UNOP = 275,
    C_STROP = 276,
    C_STRUCT = 277,
    C_IF = 278,
    C_ELSE = 279,
    C_SWITCH = 280,
    C_BREAK = 281,
    C_CONTINUE = 282,
    C_WHILE = 283,
    C_DO = 284,
    C_FOR = 285,
    C_DEFAULT = 286,
    C_CASE = 287,
    C_SIZEOF = 288,
    C_ALIGNOF = 289,
    C_ENUM = 290,
    C_ELLIPSIS = 291,
    C_QUALIFIER = 292,
    C_FUNSPEC = 293,
    C_ASM = 294,
    NOMATCH = 295,
    C_TYPEOF = 296,
    C_ATTRIBUTE = 297,
    PCC_OFFSETOF = 298,
    GCC_DESIG = 299
  };
#endif
/* Tokens.  */
#define C_STRING 258
#define C_ICON 259
#define C_FCON 260
#define C_NAME 261
#define C_TYPENAME 262
#define C_ANDAND 263
#define C_OROR 264
#define C_GOTO 265
#define C_RETURN 266
#define C_TYPE 267
#define C_CLASS 268
#define C_ASOP 269
#define C_RELOP 270
#define C_EQUOP 271
#define C_DIVOP 272
#define C_SHIFTOP 273
#define C_INCOP 274
#define C_UNOP 275
#define C_STROP 276
#define C_STRUCT 277
#define C_IF 278
#define C_ELSE 279
#define C_SWITCH 280
#define C_BREAK 281
#define C_CONTINUE 282
#define C_WHILE 283
#define C_DO 284
#define C_FOR 285
#define C_DEFAULT 286
#define C_CASE 287
#define C_SIZEOF 288
#define C_ALIGNOF 289
#define C_ENUM 290
#define C_ELLIPSIS 291
#define C_QUALIFIER 292
#define C_FUNSPEC 293
#define C_ASM 294
#define NOMATCH 295
#define C_TYPEOF 296
#define C_ATTRIBUTE 297
#define PCC_OFFSETOF 298
#define GCC_DESIG 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 220 "./cgram.y" /* yacc.c:1909  */

	int intval;
	NODE *nodep;
	struct symtab *symp;
	struct rstack *rp;
	char *strp;

#line 150 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
