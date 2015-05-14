


class Perro

	attr_reader :nombre
	attr_accessor :edad

	private

		@nombre
		@edad

	public

		def initialize (nombre, edad)
			@nombre = nombre
			@edad = edad
		end

end


Cookie = Perro.new("Cookie",10)

puts Cookie.edad
Cookie.edad+=1
puts Cookie.edad