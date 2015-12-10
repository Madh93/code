require_relative "transformation"

module Transformer
  class VecinoProximo < Transformation
      
    def initialize(img, factor)
      super(img)
      @factor = factor.to_f
    end

    def create_image
      super { ChunkyPNG::Image.new((@factor*@original.width-1).round,
                                    (@factor*@original.height-1).round) }
    end
    
    def transform
      super { |x| @original[((x/@height)/@factor).round,
                                    ((x % @height)/@factor).round] }
    end
  end
end