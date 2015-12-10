require_relative "transformation"

module Transformer
  class Negativo < Transformation
      
    def initialize(img)
      super(img)
    end

    def create_image
      super { ChunkyPNG::Image.new(@original.width, @original.height) }
    end
    
    def transform
      super { |x| ChunkyPNG::Color.rgb(255-R(@original[x/@height, x % @height]),
                                      255-G(@original[x/@height, x % @height]),
                                      255-B(@original[x/@height, x % @height])) }
    end
  end
end