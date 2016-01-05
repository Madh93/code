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

        width = [a,b,c,d].map{ |e| e.x.abs}.max.round
        height = [a,b,c,d].map{ |e| e.y.abs}.max.round

        # ChunkyPNG::Image.new((a.x-c.x-1).round.abs,(b.y-d.y-1).round.abs)
        ChunkyPNG::Image.new(width, height)
      end
    end
    
    def transform
      super do |x|

        cx = ((x / @height))
        cy = ((x % @height))

        p = t_indirecta(cx + @coord.x, cy + @coord.y)
        
        # Comprobar e interpolar

        if valid?(p.x.round,p.y.round)
          @original[p.x.round, p.y.round]
        else
          ChunkyPNG::Color.rgb(255,255,255)
        end

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

    def valid?(x, y)
      x.between?(0,@original.width-1) && y.between?(0,@original.height-1)
    end

  end
end