class Animal

	attr_accessor :edad
	attr_reader :patas

	def initialize edad, patas
		@edad = edad 
		@patas = patas
	end

	def ruido
		puts "Hace ruido"
	end

	def come
		puts "come comida"
	end
end


class Perro < Animal

	@@total=0

	attr_accessor :nombre, :total

	def initialize nombre, edad
		super(edad,4)
		@nombre = nombre
		@@total+=1
	end

	def ruido
		puts "Ladra"
	end
end


a = Perro.new("Cookie",8)
print "Mi perro #{a.nombre} tiene #{a.patas} patas y #{a.edad} anyos. "
a.ruido

#puts a.public_methods

class A

	attr_reader :a,:b,:c

	def initialize tipo

		@a,@b,@c = nil
		puts self.class
		puts tipo

		if tipo == Animal
			puts "iguales"
		end

		case tipo
			when Perro then uno
		end
	end

	def uno
		puts 1
	end
	def dos
		puts 2
	end
	def tres
		puts 3
	end
end

abc = A.new a
#puts abc.a.nil?
puts abc.class
