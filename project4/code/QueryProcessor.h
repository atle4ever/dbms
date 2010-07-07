#include "QueryPlan.h"

class QueryProcessor {
 public:
    void process(Sql *sql);

 private:
    void create(SqlCreate *sql);
    void insert(SqlInsert *sql);
};
