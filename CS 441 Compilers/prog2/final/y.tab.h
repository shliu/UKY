/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     DOUBLE = 259,
     VARIABLE = 260,
     WHILE = 261,
     IF = 262,
     PRINT = 263,
     DO = 264,
     UNTIL = 265,
     REPEAT = 266,
     DECLAREINT = 267,
     BEGINSCOPE = 268,
     ENDSCOPE = 269,
     IFX = 270,
     ELSE = 271,
     NE = 272,
     EQ = 273,
     LE = 274,
     GE = 275,
     UMINUS = 276
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define DOUBLE 259
#define VARIABLE 260
#define WHILE 261
#define IF 262
#define PRINT 263
#define DO 264
#define UNTIL 265
#define REPEAT 266
#define DECLAREINT 267
#define BEGINSCOPE 268
#define ENDSCOPE 269
#define IFX 270
#define ELSE 271
#define NE 272
#define EQ 273
#define LE 274
#define GE 275
#define UMINUS 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 22 "calc3.y"

    int iValue;                 /* integer value */
    double dValue;              /* double value */
    char * sName;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */



/* Line 2068 of yacc.c  */
#line 101 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


