var crypto = require('crypto');

start_time = new Date();
var c = 0;
var m = 10000000;

while (c < m) {
  var n0 = Math.floor(Math.random() * 9999999999);
  var n1 = Math.floor(Math.random() * 9999999999);
  var nn = crypto.createHash('md5').update(n0.toString()+n1.toString()).digest("hex");
  c++;
}

console.log("Node version: " + process.version);
console.log("Execution time (seconds): " + ((new Date() - start_time)/1000);
