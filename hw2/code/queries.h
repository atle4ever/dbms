// -*- C++ -*-

class L;
class O;
class C;

#include <vector>

// Query 1
// select
//     l_returnflag,
//     sum(l_quantity) as sum_qty,
//     avg(l_extendedprice) as sum_base_price,
//     count(*)
// from
//     lineitem
// where
//     l_shipdate <= '1997-09-02'
// group by
//     l_returnflag
// ;
void q1(std::vector<L> &lineitem);

// select
//     l_orderkey,
//     sum(l_extendedprice) as sum_base_price
// from
//     customer,
//     orders,
//     lineitem
// where
//    (c_mktsegment = 'BUILDING' or c_mktsegment = 'FURNITURE')
//     and c_custkey = o_custkey
//     and l_orderkey = o_orderkey
// group by
//     l_orderkey
// order by
//     sum_base_price desc,
//     l_orderkey
// limit
//     10
// ;
void q2(std::vector<L> &lineitem, std::vector<O> &ordres, std::vector<C> &customer);

// select
//     o_orderdate
// from
//     orders
// where
//     o_orderdate >= '1993-07-01'
//     and exists (
//         select
//             *
//         from
//             lineitem
//         where
//             l_orderkey = o_orderkey
//             and l_returnflag = 'N'
//     )
// order by
//     o_orderdate
// limit
//     10
// ;
void q3(std::vector<L> &lineitem, std::vector<O> &ordres);
