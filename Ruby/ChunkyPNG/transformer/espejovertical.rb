require_relative "transformation"

module Transformer
  class EspejoVertical < Transformation
      
    def initialize(img)
      super(img)
    end

    def create_image
      super { ChunkyPNG::Image.new(@original.width, @original.height) }
    end
    
    def transform
      super { |x| @original[(x/@height), @height - (x % @height) - 1] }
    end
  end
end