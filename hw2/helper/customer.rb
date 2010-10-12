#!/usr/bin/ruby
require 'myOptParse'

options = myOptParse()

out = File.open(options[:output], "w+")

File.open(options[:input]) do |file|
  while line = file.gets
    if rand(100) < options[:ratio]
      l = line.split('|')
      out.write("#{l[0]}|") # c_custkey int
      out.write("#{l[6]}") # c_mktsegment char(11)
      out.puts()
    end
  end
end
