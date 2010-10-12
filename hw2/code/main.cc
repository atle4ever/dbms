#include "queries.h"
#include "loader.h"
#include "schema.h"

#include <vector>


int main() {
    // Hard-structured tables
    std::vector<L> lineitem;
    std::vector<O> orders;
    std::vector<C> customer;

    // Insert rows into each table
    load(lineitem);
    load(orders);
    load(customer);

    // Process queries
    q1(lineitem);
    q2(lineitem, orders, customer);
    q3(lineitem, orders);

    return 0;
}
