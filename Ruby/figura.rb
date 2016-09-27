# class Figura
class Figura
  attr_accessor :lado
  def initialize
    @lado = 10
  end

  def perimetro
    puts 'Pero que figura?'
  end
end

# class Cuadrado
class Cuadrado < Figura
  def perimetro
    puts @lado * 4
  end
end

# class Triangulo
class Triangulo < Figura
  def perimetro
    puts @lado * 3
  end
end

Cuadrado.new.perimetro
Triangulo.new.perimetro
