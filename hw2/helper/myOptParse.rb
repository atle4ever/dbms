#!/usr/bin/ruby
require 'optparse'

def myOptParse
  options = { }

  opt_parser = OptionParser.new do |opts|
    opts.banner = "Usage: this.rb [options]"
    opts.on("-i", "--input FILE", "Input file (contain packed data)") do |file|
      options[:input] = file
    end

    opts.on("-o", "--output FILE", "Output file (contain sql query).", "If not exist, make new file") do |file|
      options[:output] = file
    end

    opts.on("-r", "--ratio [N]", Integer, "Ratio of selected rows") do |n|
      options[:ratio] = n
    end

    opts.separator ""
    opts.separator "Common options:"

    opts.on_tail("-h", "--help", "Show this message") do
      puts opts
      exit
    end
  end

  begin
    opt_parser.parse!
  rescue OptionParser::ParseError => e
    puts e
    puts opt_parser
    exit
  end

  if(options[:input] == nil)
    puts "missing option: -i, --input FILE"
    puts opt_parser
    exit
  end

  if(options[:output] == nil)
    puts "missing option: -o, --output FILE"
    puts opt_parser
    exit
  end

  if(options[:ratio] == nil)
    options[:ratio] = 1;
  elsif(options[:ratio] < 1)
    puts"Invalid number. Ratio must be larger or equal than 1."
    puts opt_parser
    exit
  end

  options
end
