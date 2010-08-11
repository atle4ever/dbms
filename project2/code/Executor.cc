#include <cstdlib>

#include "Executor.h"
#include "ParseTree.h"

using namespace std;

void Executor::process(Sql *s) {
    switch(s->getType()){
    case SQL_CREATE :
        create((SqlCreate*)s);
        break;

    case SQL_INSERT :
        insert((SqlInsert*)s);
        break;

    default:
        cerr << "Error: Invalid sql" << endl;
        exit(-1);
    }
}

void Executor::create(SqlCreate *s) {
    // TODO
}

void Executor::insert(SqlInsert *s) {
    // TODO
}

void Executor::print() {
    // TODO
}
