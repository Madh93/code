#! /usr/bin/env ruby

# NAME          : Http Test
# DESCRIPTION   : Download binary file over HTTP
# AUTHOR        : Madh93 (Miguel Hernandez)
# VERSION       : 0.0.1
# LICENSE       : GNU General Public License v3
# USAGE         : ruby http_test.rb

require 'open-uri'
require 'net/http'
require 'rest-client'

URL = 'http://download.openbricks.org/sample/H264/big_buck_bunny_480p_H264_AAC_25fps_1800K.MP4'

# 1: OpenURI library
def http_test_1
  File.open('http_test_3.mp4', 'wb') do |f|
    f.write open(URL).read
  end
end

# 2: Net/HTTP library
def http_test_2
  File.open('http_test_2.mp4', 'wb') do |f|
    f.write Net::HTTP.get(URI.parse(URL))
  end
end

# 3: Rest Client library
def http_test_3
  File.open('http_test_3.mp4', 'wb') do |f|
    f.write RestClient.get(URL)
  end
end

# 4: Net/HTTP through http segments
def http_test_4
  Net::HTTP.start('download.openbricks.org') do |http|
    f = File.open('http_test_4.mp4', 'wb')
    begin
      http.request_get('/sample/H2645/big_buck_bunny_480p_H264_AAC_25fps_1800K.MP4') do |resp|
        resp.read_body do |segment|
          f.write segment
        end
      end
    ensure
      f.close
    end
  end
end

http_test_1
http_test_2
http_test_3
http_test_4

# CONCLUSION
# 1,2,3 -> good: easy and short, bad: reads file into **memory** before writing it to disk
# 4 -> good: read http segments, bad: ugly
