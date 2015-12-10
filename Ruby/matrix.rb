require 'matrix'


class Matrix
  def multiply_by(x)
    map { |n| n * x }
  end
end

m = Matrix[[1,2,3],[4,5,6],[7,8,9]]

puts m.multiply_by 5