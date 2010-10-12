select
    l_orderkey,
    sum(l_extendedprice) as sum_base_price
from
    customer,
    orders,
    lineitem
where
   (c_mktsegment = 'BUILDING' or c_mktsegment = 'FURNITURE')
    and c_custkey = o_custkey
    and l_orderkey = o_orderkey
group by
    l_orderkey
order by
    sum_base_price desc,
    l_orderkey
limit
    10
;
