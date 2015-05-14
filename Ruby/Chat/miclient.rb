require "socket"

# server = TCPSocket.open("localhost",2121)
# server.puts "hola desde cliente?"
# server.close

class Cliente

	def initialize(servidor)
		@servidor = servidor
		@respuesta = nil
		@solictud = nil
		recibir
		enviar
		@respuesta.join
		@solicitud.join
	end

	def recibir
		@respuesta = Thread.new do
			loop{
				msg = @servidor.gets.chomp
				puts msg
			}
		end
	end

	def enviar
		print "Introduzca su nick: "
		@solicitud = Thread.new do
			loop{
				msg = $stdin.gets.chomp
				@servidor.puts msg
			}
		end
	end

end

servidor = TCPSocket.open("localhost",2121)
cliente = Cliente.new(servidor)