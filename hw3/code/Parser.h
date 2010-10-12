// -*- C++ -*-

#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>

class Sql;


extern int yyparse(void *YYPARSE_PARAM);
extern char* str_str;

class Parser {
private:
    char* sql_s;
    Sql* Sql_tree_ptr;

public:
    Parser() { Sql_tree_ptr = NULL;}
    ~Parser(){}

    void get_lex_string(std::string sql_statement);
    Sql* Sql_process(std::string sql_statement);
};

#endif // __PARSER_H__
