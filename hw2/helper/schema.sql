CREATE TABLE lineitem (
       l_orderkey INT,
       l_quantity FLOAT,
       l_extendedprice FLOAT,
       l_returnflag CHAR(1),
       l_shipdate CHAR(10)
);

CREATE TABLE orders (
       o_orderkey INT,
       o_custkey INT,
       o_orderdate CHAR(10)
);

CREATE TABLE customer (
       c_custkey INT,
       c_mktsegment CHAR(10)
);
