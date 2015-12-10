var events = require('events');
var eventEmitter = new events.EventEmitter();

var empezamos = function() {
  console.log('¡Ya empezó el curso!');
}

eventEmitter.on('comenzando', empezamos);

eventEmitter.emit('comenzando');