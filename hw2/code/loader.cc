#include "loader.h"
#include "schema.h"

#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

void load(std::vector<L> &lineitem) {
    std::ifstream ifs("lineitem.tbl", std::ifstream::in);
    if(ifs.fail()) {
        std::cerr << "[Error] Fail to open 'lineitem.tbl'\n";
        exit(-1);
    }

    std::string buf;
    char *tok;

    int l_orderkey;
    float l_quantity;
    float l_extendedprice;
    std::string l_returnflag;
    std::string l_shipdate;

    while(!ifs.eof()) {
        std::getline(ifs, buf, '|');
        l_orderkey = atoi(buf.c_str());

        std::getline(ifs, buf, '|');
        l_quantity = atof(buf.c_str());

        std::getline(ifs, buf, '|');
        l_extendedprice = atof(buf.c_str());

        std::getline(ifs, l_returnflag, '|');

        std::getline(ifs, l_shipdate, '\n');

        lineitem.push_back(L(l_orderkey, l_quantity, l_extendedprice, l_returnflag, l_shipdate));
    }
}

void load(std::vector<O> &orders) {
    std::ifstream ifs("orders.tbl", std::ifstream::in);
    if(ifs.fail()) {
        std::cerr << "[Error] Fail to open 'orders.tbl'\n";
        exit(-1);
    }

    std::string buf;
    char *tok;

    int o_orderkey;
    int o_custkey;
    std::string o_orderdate;

    while(ifs.good()) {
        std::getline(ifs, buf, '|');
        o_orderkey = atoi(buf.c_str());

        std::getline(ifs, buf, '|');
        o_custkey = atoi(buf.c_str());

        std::getline(ifs, o_orderdate, '\n');

        orders.push_back(O(o_orderkey, o_custkey, o_orderdate));
    }
}

void load(std::vector<C> &customer) {
    std::ifstream ifs("customer.tbl", std::ifstream::in);
    if(ifs.fail()) {
        std::cerr << "[Error] Fail to open 'customer.tbl'\n";
        exit(-1);
    }

    std::string buf;
    char *tok;

    int c_custkey;
    std::string c_mktsegment;

    while(ifs.good()) {
        std::getline(ifs, buf, '|');
        c_custkey = atoi(buf.c_str());

        std::getline(ifs, c_mktsegment, '\n');

        customer.push_back(C(c_custkey, c_mktsegment));
    }
}
