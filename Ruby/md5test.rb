require 'digest'

start_time = Time.now
c = 0
m = 10000000

while c < m
  n0 = rand(9999999999)
  n1 = rand(9999999999)
  nn = Digest::MD5.hexdigest(n0.to_s << n1.to_s)
  c += 1
end

puts "Ruby version: #{RUBY_VERSION}"
puts "Execution time (seconds): #{Time.now - start_time}"
