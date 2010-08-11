#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__

#include <vector>

#include "Table.h"
#include "ParseTree.h"

class Executor {
public:
    void process(Sql *s);
    void print();

private:
    void create(SqlCreate *s);
    void insert(SqlInsert *s);

    std::vector<Table*> tableList;
};

#endif // __EXECUTOR_H__
