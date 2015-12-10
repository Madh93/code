def func1
   puts "func1 at: #{Time.now}"
   sleep(2)
end

def func2
   puts "func2 at: #{Time.now}"
   sleep(2)
end

puts "Started At #{Time.now}"
puts "Waiting 2 seconds"
system("sleep 2");

t1=Thread.new{func1}
t2=Thread.new{func2}
t1.join
t2.join

puts "End at #{Time.now}"