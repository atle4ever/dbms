#!/usr/bin/ruby
require 'myOptParse'

options = myOptParse()

out = File.open(options[:output], "w+")

File.open(options[:input]) do |file|
  while line = file.gets
    if rand(100) < options[:ratio]
      l = line.split('|')
      out.write("#{l[0]}|") # l_orderkey int
      out.write("#{l[4]}|") # l_quantity float (from int)
      out.write("#{l[5]}|") # l_extendedprice float
      out.write("#{l[8]}|") # l_returnfloat char(2)
      out.write("#{l[10]}") # l_shipdate char(11)
      out.puts()
    end
  end
end
