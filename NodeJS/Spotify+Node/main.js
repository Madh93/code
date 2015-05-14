var spawn   = require('child_process').spawn;
var sys = require('sys')
var exec   = require('child_process').exec;
var express = require('express');
var app     = express();

//app.use(express.static(__dirname));

// app.get('/colorsRequest', function(req, res) {
//   var command = spawn(__dirname + '/run.sh', [ req.query.color || '' ]);
//   //var command = spawn('/home/migue/Escritorio/repos/Rpotify/rpotify.sh pause', [ req.query.color || '' ]);
//   var output  = [];

//   command.stdout.on('data', function(chunk) {
//     output.push(chunk);
//   }); 

//   command.on('close', function(code) {
//     if (code === 0)
//       res.send(Buffer.concat(output));
//     else
//       res.send(500); // when the script fails, generate a Server Error HTTP response
//   });
// });


app.get('/pausar', function(req,res){
  function puts(error, stdout, stderr) { sys.puts(stdout) }
  exec("/home/migue/Escritorio/repos/Rpotify/rpotify.sh pause", puts);
});

app.get('/siguiente', function(req,res){
  function puts(error, stdout, stderr) { sys.puts(stdout) }
  exec("/home/migue/Escritorio/repos/Rpotify/rpotify.sh next", puts);
});

app.get('/anterior', function(req,res){
  function puts(error, stdout, stderr) { sys.puts(stdout) }
  exec("/home/migue/Escritorio/repos/Rpotify/rpotify.sh prev", puts);
});

app.listen(3000);