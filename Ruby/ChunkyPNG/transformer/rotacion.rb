require_relative "transformation"
require_relative "utils/math"

module Transformer
  class Rotacion < Transformation
      
    def initialize(img, angle)
      super(img)
      @angle = Math.to_radians(angle)
    end

    def create_image
      super do
        w = @original.width * Math.cos(@angle) - @original.height * Math.sin(@angle)
        h = @original.width * Math.sin(@angle) + @original.height * Math.cos(@angle)
        ChunkyPNG::Image.new(w.round.abs, h.round.abs)
      end
    end
    
    def transform
      super do |x|

        cx = ((x / @height))
        cy = ((x % @height))

        large =  [@width,@height].max - 1
        puts @height


        # 90
        if (cx == 199) && (cy == 319)
          puts  @height-1 - (cx * Math.cos(@angle) + cy * Math.sin(@angle)).round.abs
          puts   (-cx * Math.sin(@angle) + cy * Math.cos(@angle)).round.abs
        end

        # 180
        # if (cx == 319) && (cy == 199)
        #   puts  @width-1 - (cx * Math.cos(@angle) + cy * Math.sin(@angle)).round.abs
        #   puts  @height-1 -(-cx * Math.sin(@angle) + cy * Math.cos(@angle)).round.abs
        # end

        # 270 width=200
        # if (cx == 199) && (cy == 319)
        #   puts  (cx * Math.cos(@angle) + cy * Math.sin(@angle)).round.abs
        #   puts  @width-1- (-cx * Math.sin(@angle) + cy * Math.cos(@angle)).round.abs
        # end

        #puts (cx * Math.cos(@angle) + cy * Math.sin(@angle)).round.abs
        #puts (-cx * Math.sin(@angle) + cy * Math.cos(@angle)).round.abs
        @original[@height-1 -(cx * Math.cos(@angle) + cy * Math.sin(@angle)).round.abs,
                  (-cx * Math.sin(@angle) + cy * Math.cos(@angle)).round.abs]


        #ChunkyPNG::Color.rgb(0,0,0)
      end
    end
  end
end