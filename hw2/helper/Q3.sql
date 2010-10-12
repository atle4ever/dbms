select
    o_orderdate
from
    orders
where
    o_orderdate >= '1993-07-01'
    and exists (
        select
            *
        from
            lineitem
        where
            l_orderkey = o_orderkey
            and l_returnflag = 'N'
    )
order by
    o_orderdate
limit
    10
;
