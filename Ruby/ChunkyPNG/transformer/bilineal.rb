require_relative "transformation"

module Transformer
  class Bilineal < Transformation
      
    def initialize(img, factor)
      super(img)
      @factor = factor.to_f
    end

    def create_image
      super { ChunkyPNG::Image.new((@factor*@original.width-1).round,
                                    (@factor*@original.height-1).round) }
    end
    
    def transform
      super do |x|
        # Coordenadas
        cx = ((x / @height)/@factor)
        cy = ((x % @height)/@factor)

        # A,B,C,D
        a = R(@original[cx.floor, cy.ceil])
        b = R(@original[cx.ceil, cy.ceil])
        c = R(@original[cx.floor, cy.floor])
        d = R(@original[cx.ceil, cy.floor])

        p = cx - cx.floor
        q = cy - cy.floor

        color = (c + (d-c)*p + (a-c)*q + (b+c+-a-d)*p*q).to_i

        ChunkyPNG::Color.rgb(color,color,color)
      end
    end
  end
end