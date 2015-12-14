require_relative "transformation"
require_relative "utils/math"

module Transformer
  class Rotacion < Transformation
      
    def initialize(img, angle)
      super(img)
      @angle = Math.to_radians(angle)
      @coord = nil
    end

    def create_image
      super do

        a = t_directa(0, 0)
        b = t_directa(@original.width-1,0)
        c = t_directa(@original.width-1, @original.height-1)
        d = t_directa(0,@original.height-1)

        @coord = point([a.x,b.x,c.x,d.x].min,
                      [a.y,b.y,c.y,d.y].min)

        ChunkyPNG::Image.new((a.x-c.x-1).round.abs,(b.y-d.y-1).round.abs)
      end
    end
    
    def transform
      super do |x|

        cx = ((x / @height))
        cy = ((x % @height))

        p = t_indirecta(cx + @coord.x, cy + @coord.y)
        
        @original[p.x.to_i, p.y.to_i]
      end
    end

    def t_directa(x, y)
      point(x * Math.cos(@angle) - y * Math.sin(@angle),
            x * Math.sin(@angle) + y * Math.cos(@angle))
    end

    def t_indirecta(x, y)
      point(x * Math.cos(@angle) + y * Math.sin(@angle),
            -x * Math.sin(@angle) + y * Math.cos(@angle))
    end

  end
end