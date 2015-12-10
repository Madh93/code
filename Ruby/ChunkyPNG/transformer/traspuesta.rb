require_relative "transformation"

module Transformer
  class Traspuesta < Transformation
      
    def initialize(img)
      super(img)
    end

    def create_image
      super { ChunkyPNG::Image.new(@original.height, @original.width) }
    end
    
    def transform
      super { |x| @original[x % @height, x / @height] }
    end
  end
end