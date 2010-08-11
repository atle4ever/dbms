#include <iostream>
#include <vector>

#include "ParseTree.h"
#include "Executor.h"

using namespace std;

int main() {
    Executor e;

    Sql *sql;

    // CREATE TABLE test (a INT, b float, c CHAR(20);
    vector<ColDef> cds;
    ColType ct(V_INT, 4);
    ColDef cd("a", ct);
    cds.push_back(cd);

    ct = ColType(V_FLOAT, 4);
    cd = ColDef("b", ct);
    cds.push_back(cd);

    ct = ColType(V_CHAR, 21);
    cd = ColDef("c", ct);
    cds.push_back(cd);

    sql = new SqlCreate("test", cds);
    e.process(sql);

    // INSERT INTO test VALUES (1, 2.0, "3");
    vector<Value *> values;
    values.push_back(new IntValue(1));
    values.push_back(new FloatValue(2.0));
    values.push_back(new CharValue("3"));

    sql = new SqlInsert("test", values);
    e.process(sql);

    // Print all rows of tables
    e.print();

    return 0;
}
