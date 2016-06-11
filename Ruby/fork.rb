pid = fork
if pid  # pid is not nil, we are in the parent process
  puts "Parent process, child pid is #{pid}"
  puts `ps -ef | grep #{pid}`
  sleep 5
  puts "Parent process finishes"
else   # pid is nil, we are in the child process
  puts "Child process, pid is nil"
  sleep 2
  puts "Child process finishes"
end

