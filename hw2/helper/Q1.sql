select
    l_returnflag,
    sum(l_quantity) as sum_qty,
    avg(l_extendedprice) as sum_base_price,
    count(*)
from
    lineitem
where
    l_shipdate <= '1997-09-02'
group by
    l_returnflag
;
