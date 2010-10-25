
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     CREATE_T = 258,
     TABLE_T = 259,
     NAME = 260,
     INT_VAL_T = 261,
     FLOAT_VAL_T = 262,
     CHAR_VAL_T = 263,
     CHAR_T = 264,
     INT_T = 265,
     FLOAT_T = 266,
     INSERT_T = 267,
     INTO_T = 268,
     VALUES_T = 269,
     EQ_T = 270,
     NEQ_T = 271,
     GT_T = 272,
     GEQ_T = 273,
     LT_T = 274,
     LEQ_T = 275,
     AND_T = 276,
     SELECT_T = 277,
     FROM_T = 278,
     WHERE_T = 279
   };
#endif
/* Tokens.  */
#define CREATE_T 258
#define TABLE_T 259
#define NAME 260
#define INT_VAL_T 261
#define FLOAT_VAL_T 262
#define CHAR_VAL_T 263
#define CHAR_T 264
#define INT_T 265
#define FLOAT_T 266
#define INSERT_T 267
#define INTO_T 268
#define VALUES_T 269
#define EQ_T 270
#define NEQ_T 271
#define GT_T 272
#define GEQ_T 273
#define LT_T 274
#define LEQ_T 275
#define AND_T 276
#define SELECT_T 277
#define FROM_T 278
#define WHERE_T 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 46 "parser.y"

    char *str;
    ColType *ct;
    ColDef *cd;
    Value *value;
    std::vector<ColDef> *cds;
    std::vector<Value> *values;
    std::vector<std::string> *strs;

    ColRef *cr;
    ScalarExp *se;
    CmpPred* cp;
    std::vector<CmpPred> *cps;
    CmpPred::CmpOp co;
    std::vector<ColRef> *crs;



/* Line 1676 of yacc.c  */
#line 119 "y.tab.hh"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

