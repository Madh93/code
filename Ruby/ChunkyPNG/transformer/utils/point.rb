module Transformer
  module Point

    def point(x, y)
      Struct.new(:x, :y).new(x, y)
    end

  end
end