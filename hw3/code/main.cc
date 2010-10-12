#include "Parser.h"
#include "ParseTree.h"
#include "y.tab.hh" // Because of header dependency, it must be bottom.

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    // Uncomment for debugging of parser
    // extern int yydebug;
    // yydebug = 1;

    Sql* sql;
    Parser parser;
    string query;

    while(true) {
        query.clear();
        string line;
        while(true) {
            if(line.empty()) {
                cout << "=> ";
            } else {
                cout << "-> ";
            }
            getline(cin, line);
            query += line;
            if(*(line.rbegin()) == ';') break;
            query += "\n";
        }

        if(query.compare("quit;") == 0) {
            break;
        }

        try {
            sql = parser.Sql_process(query);

            //==----------------------------------------------------------------
            //== TODO: Create table, or insert row



            //==----------------------------------------------------------------

            delete sql;
            delete[] str_str;
        } catch(int a) {
            cerr << "error ocurred\n";
        }
    }

    //==------------------------------------------------------------------------
    //== TODO: Print all tables



    //==------------------------------------------------------------------------

    return 0;
}
