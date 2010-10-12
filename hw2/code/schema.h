// -*- C++ -*-

#include <string>
#include <iostream>

struct L {
    L(int l_ok, float l_q, float l_ep, std::string l_rf, std::string l_sd)
        : l_orderkey(l_ok), l_quantity(l_q), l_extendedprice(l_ep),
          l_returnflag(l_rf), l_shipdate(l_sd) {}

    void print() const {
        std::cout << l_orderkey << ' ';
        std::cout << l_quantity << ' ';
        std::cout << l_extendedprice << ' ';
        std::cout << l_returnflag << ' ';
        std::cout << l_shipdate << '\n';
    }

    int l_orderkey;
    float l_quantity;
    float l_extendedprice;
    std::string l_returnflag;
    std::string l_shipdate;
};

struct O {
    O(int o_ok, int o_ck, std::string o_od) : o_orderkey(o_ok), o_custkey(o_ck),
                                              o_orderdate(o_od) {}

    void print() const {
        std::cout << o_orderkey << ' ';
        std::cout << o_custkey << ' ';
        std::cout << o_orderdate << '\n';
    }

    int o_orderkey;
    int o_custkey;
    std::string o_orderdate;
};

struct C {
    C(int c_ck, std::string c_ms) : c_custkey(c_ck), c_mktsegment(c_ms) {}

    void print() const {
        std::cout << c_custkey << ' ';
        std::cout << c_mktsegment << '\n';
    }

    int c_custkey;
    std::string c_mktsegment;
};
