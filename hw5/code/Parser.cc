#include "Parser.h"
#include "ParseTree.h"

#include <string>
#include <cstring>


//Assign string str_str which is used in Lex to tokenize
void Parser::get_lex_string(std::string sql_statement) {
    char* temp = new char[strlen(sql_statement.c_str())+1];
    strcpy(temp, sql_statement.c_str());
    str_str = temp;
}

//Call yyparse to check grammar, create Parse Tree and returns created Parse Tree
Sql* Parser::Sql_process(std::string sql_statement) {
    get_lex_string(sql_statement);
    yyparse((void*)&Sql_tree_ptr);
    return Sql_tree_ptr;
}
