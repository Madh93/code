var sys = require('sys')
var exec = require('child_process').exec;
function puts(error, stdout, stderr) { sys.puts(stdout) }
exec("/home/migue/Escritorio/repos/Rpotify/rpotify.sh pause", puts);

// // http://nodejs.org/api.html#_child_processes
// var sys = require('sys')
// var exec = require('child_process').exec;
// var child;

// // executes `pwd`
// child = exec("/home/migue/Escritorio/repos/Rpotify/rpotify.sh now", function (error, stdout, stderr) {
//   sys.print('stdout: ' + stdout);
//   sys.print('stderr: ' + stderr);
//   if (error !== null) {
//     console.log('exec error: ' + error);
//   }
// });