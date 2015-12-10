x = 0

10.times.map do |i|
  Thread.new do
    puts "before (#{ i }): #{ x }"
    x += 1
    puts "after (#{ i }): #{ x }"
  end
end.each(&:join)

puts "\ntotal: #{ x }"