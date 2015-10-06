class Complex2

  def initialize
    @a=0
    @b=0
  end

  def initialize(x,y)
    @a=x
    @b=y
  end

  def suma(x)
    res = Complex.new()
    res.a= @a+y.a
    res.b= @b+x.b
    return res
  end

end


complex1 = Complex2.new(1,2)
puts complex1.@x
# complex3 = Complex2.new()
# complex2 = Complex2.new(3,4)

# puts res=complex1.suma(complex2)