#!/usr/bin/ruby
require 'myOptParse'

options = myOptParse()

out = File.open(options[:output], "w+")

File.open(options[:input]) do |file|
  while line = file.gets
    if rand(100) < options[:ratio]
      l = line.split('|')
      out.write("#{l[0]}|") # o_orderkey int
      out.write("#{l[1]}|") # o_custkey int
      out.write("#{l[4]}") # o_orderdate char(11)
      out.puts()
    end
  end
end
