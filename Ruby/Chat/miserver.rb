require "socket"

# server = TCPServer.open("localhost",2121)
# loop {
# 	client = server.accept
# 	msg = client.gets.chomp
# 	puts msg
# 	client.close
# }

class Servidor

	def initialize(ip,port)
		@servidor = TCPServer.open(ip,port)
		@conexiones = {}
		@usuarios = {}
		@conexiones[:usuarios] = @usuarios
		iniciar
	end

	def iniciar
		loop {
			Thread.start(@servidor.accept) do |cliente|
				nick = cliente.gets.chomp.to_sym
				@conexiones[:usuarios].each do |nick_, cliente_|
					if nick == nick_ || cliente == cliente_
						cliente.puts "El nick: #{nick} ya está en uso!"
						Thread.kill self
					end 
				end
				@conexiones[:usuarios][nick] = cliente
				cliente.puts "Bienvenido al chat Ruby :)"
				escuchar(nick,cliente)
			end
		}.join
	end

	def escuchar(nick, cliente)
		loop{
			msg = cliente.gets.chomp
			@conexiones[:usuarios].each do |nick_,cliente_|
				cliente_.puts "#{nick.to_s}: #{msg}" unless cliente_ == cliente
			end
		}
	end

end



Servidor.new("127.0.0.1",2121)