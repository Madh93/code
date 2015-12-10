require_relative "transformation"

module Transformer
  class EspejoHorizontal < Transformation
      
    def initialize(img)
      super(img)
    end

    def create_image
      super { ChunkyPNG::Image.new(@original.width, @original.height) }
    end
    
    def transform
      super { |x| @original[@width - (x/@height) - 1, x % @height] }
    end
  end
end