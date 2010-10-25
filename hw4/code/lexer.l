%{
#include "ParseTree.h"
#include "y.tab.hh" // Because of header dependency, it must be bottom.

#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

//Redefining yyinput to get from string
int my_yyinput(char *buf, int max_size);
#define YY_INPUT(b, r, ms) (r = my_yyinput(b, ms))
#define YY_NO_UNPUT

//Variables for error message
int token_pos = 0;
int charpos= 1;
int linenum = 1;

//Function called when found a new line in the string
void newLine(void){
    linenum++;
    charpos = 0;
}

extern int yyerror(const char *s);

//Count character number in string before error
void adjust(void){
    token_pos = charpos;
    charpos += yyleng;
}

%}

%option nounput

%%
CREATE { adjust(); return CREATE_T; }
TABLE  { adjust(); return TABLE_T; }

INSERT { adjust(); return INSERT_T; }
INTO   { adjust(); return INTO_T; }
VALUES { adjust(); return VALUES_T; }

CHAR   { adjust(); return CHAR_T; }
FLOAT  { adjust(); return FLOAT_T; }
INT    { adjust(); return INT_T; }

[ \t\r]+ { adjust(); }
[-(),.*+/] { adjust(); return yytext[0]; }

[A-Za-z][A-Za-z0-9_]* {
    yylval.str = new char[strlen(yytext) + 1];
    strcpy(yylval.str, yytext);
    adjust();
    return NAME;
}

\' {
    char buffer[400];
    int i = 0;
    int c;
    while((c = yyinput()) != '\''){
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    yylval.str = new char[strlen(buffer) + 1];
    strcpy(yylval.str , buffer);
    adjust();
    return CHAR_VAL_T;
}

[;] {
    charpos = 1;
    linenum = 1;
    return 0;
}

\n { newLine(); }

\'[^']$ { yyerror("unterminated string");}

[-]?[0-9]+ {
    yylval.str = new char[strlen(yytext) + 1];
    strcpy(yylval.str, yytext);
    adjust();
    return INT_VAL_T;
}

[-]?(([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+)) {
    yylval.str = new char[strlen(yytext) + 1];
    strcpy(yylval.str, yytext);
    adjust();
    return FLOAT_VAL_T;
}

%%
// Gets string from Sql_parser
extern char* str_str;

//Function to redefine yyinput to parse from string
int my_yyinput(char *buf, int max_size) {
    char *sql =  str_str;
    strcpy(buf, sql);
    return strlen(buf);
}

