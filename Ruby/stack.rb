

class Stack

	def initialize (size)
		@size_ = size
		@top_ = -1
		@stack_ = Array.new(@size_)
	end

	def push (dato)
		if !full
			@top_+=1
			@stack_[@top_] = dato
		else
			abort "Pila llena!"
		end
	end

	def pop
		if !empty
			dato = @stack_[@top_]
			@top_-=1
			dato
		else
			abort "Pila vacia!"
		end
	end

	def top
		if !empty
			@stack_[top_]
		else
			abort "Pila vacia!"
		end
	end

	def empty
		@top_ == -1
	end

	def full
		@top_ >= @size_ - 1
	end

	def show
		for x in (0..@top_)
			print "#{@stack_[x]}, "
		end
		puts
	end
end

pila = Stack.new(10)
pila.push 'a'
pila.push 'b'
pila.push 2.4
pila.push 6
pila.show
pila.pop
pila.pop
pila.push 'z'
pila.show
