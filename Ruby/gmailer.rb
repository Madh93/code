#! /usr/bin/env ruby

# NAME          : gmailer.rb
# DESCRIPTION   : Check and notify new gmails
# AUTHOR        : Madh93 (Miguel Hernandez)
# VERSION       : 0.0.1
# LICENSE       : GNU General Public License v3
# USAGE         : ruby gmailer.rb XML [OPTION]

require 'nokogiri'

class Gmailer
  
  def initialize(xml)
    @xml = Nokogiri::XML(xml)
    @mails = @xml.xpath('//xmlns:entry')
  end

  def count
    @xml.xpath('//xmlns:fullcount').children
  end

  def read(n)
    name = @mails.xpath('//xmlns:name')[n].children.to_s
    title = @mails.xpath('//xmlns:title')[n+1].children.to_s
    "#{name.gsub(';',"")};#{title.gsub(';',"")}"
  end
end


# Main
case ARGV[1]
when "-c", "--count"
  puts Gmailer.new(ARGV[0]).count
when "-r", "--read"
  puts Gmailer.new(ARGV[0]).read(ARGV[2].to_i)
end