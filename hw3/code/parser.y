%{
#include "ParseTree.h"

#include <cstring>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int yylex(void);
//Lex variables for error message
extern char* yytext;
extern int yylex_destroy(void);
extern int token_pos;
extern int charpos;
extern int linenum;

//Redefining yyerror function adding error info. And renew lex
void yyerror(const char *s) {
    printf("%s: invalid expr. \"%s\", at col: %d at line %d\n" , s, yytext, token_pos, linenum);
    yylex_destroy();
    throw 1;
}

//Initiate error message variables after success parsing
extern "C" {
    int yywrap() {
        charpos = 1;
        linenum = 1;
        return 1;
    }
}

//Gets string from Sql_parser class and lex gets it to tokenize.
char* str_str;

int yyparse(void);
int yyparse(void *YYPARSE_PARAM);
#define YYPARSE_PARAM sql_obj

//Checks Grammar and creates Parser Tree.
%}
%union {
    char *str;
    ColType *ct;
    ColDef *cd;
    Value *value;
    std::vector<ColDef> *cds;
    std::vector<Value> *values;
}

%token QUIT_T
%token CREATE_T TABLE_T
%token <str> NAME
%token <str> INT_VAL_T FLOAT_VAL_T CHAR_VAL_T
%token CHAR_T INT_T FLOAT_T
%token INSERT_T INTO_T VALUES_T

%type <cd> base_table_element
%type <cds> base_table_element_list
%type <ct> data_type
%type <cd> column_def
%type <value> atom_value
%type <values> column_value_list

%start sql

%%
sql :
base_table_def
| insert_statement
| QUIT_T {
    exit(0);
}
;

base_table_def :
CREATE_T TABLE_T NAME '(' base_table_element_list ')' {
    string tableName($3);
    SqlCreate* Create = new SqlCreate(tableName, $5);

    Sql** sql = (Sql**)sql_obj;
    *sql = Create;

    delete [] $3;
}
;

base_table_element_list :
base_table_element {
    $$ = new vector<ColDef>;
    $$->push_back(*$1);
    delete $1;
}
| base_table_element_list ',' base_table_element {
    $$ = $1;
    $$->push_back(*$3);
    delete $3;
}
;

base_table_element :
column_def
;

column_def:
NAME data_type {
    $$ = new ColDef($1, $2);

    delete [] $1;
    delete $2;
}
;

data_type:
CHAR_T '(' INT_VAL_T ')'   {
    int len = atoi($3);
    $$ = new ColType(VT_CHAR, len);
}
| INT_T                 { $$ = new ColType(VT_INT, sizeof(int)); }
| FLOAT_T               { $$ = new ColType(VT_FLOAT, sizeof(float)); }
;

// INSERT SQL
insert_statement:
INSERT_T INTO_T NAME VALUES_T '(' column_value_list ')'{
    string tableName($3);
    SqlInsert* Insert = new SqlInsert(tableName, $6);

    Sql** sql = (Sql**)sql_obj;
    *sql = Insert;
    delete[] $3;
}
;

column_value_list:
atom_value {
    $$ = new vector<Value>;
    $$->push_back(*$1);

    delete $1;
}
| column_value_list ',' atom_value {
    $$ = $1;
    $$->push_back(*$3);

    delete $3;
}
;

atom_value:
INT_VAL_T     { $$ = new Value($1, VT_INT); }
| FLOAT_VAL_T { $$ = new Value($1, VT_FLOAT); }
| CHAR_VAL_T  { $$ = new Value($1, VT_CHAR); }
;

%%
