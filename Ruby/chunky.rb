require 'chunky_png'

# https://msdn.microsoft.com/es-es/library/windows/desktop/dd390989%28v=vs.85%29.aspx
# http://www.rinkydinkelectronics.com/calc_rgb565.php
# http://www.rubydoc.info/gems/chunky_png/ChunkyPNG/Color#rgb-instance_method

# c = 4294967295
# dec = (R(c) << 24) + (G(c) << 16) + (B(c) << 8) + A(c)
# puts dec
# puts R(c)
# puts ChunkyPNG::Color.from_hex("0x000000ff")
# puts ChunkyPNG::Color.rgb(255,255,255)
# puts ChunkyPNG::Color.rgba(255,255,255,255)

#PATH = "~/Escritorio/"
PATH = ""

module RGBUtils
    
    MAX = 4294967295
    
    def R(c)
      (c & 0xff000000) >> 24
    end
    
    def G(c)
      (c & 0x00ff0000) >> 16
    end
    
    def B(c)
      (c & 0x0000ff00) >> 8
    end
    
    def A(c)
      (c & 0x000000ff)
    end
end    

module Transformer

    class Transformer
        
        include RGBUtils
        
        def initialize(img)
            @original = img
            @image = ChunkyPNG::Image.new(img.width, img.height)
            @width = img.width
            @height = img.width
        end
        
        def transform
            size = @width*@height
            
            (0...size).each do |x|
                @image[x/@height,x%@height] = yield x
            end
            
            @image
        end
    end
    
    class EspejoVertical < Transformer
        
        def initialize(img)
            super(img)
        end
        
        def transform
            super { |x| @original[@width - (x/@height) - 1, x%@height] }
        end
    end
    
    class EspejoHorizontal < Transformer
        
        def initialize(img)
            super(img)
        end
        
        def transform
            super { |x| @original[(x/@height), @height - (x%@height) - 1] }
        end
    end
    
    class Negativo < Transformer
        
        def initialize(img)
            super(img)
        end
        
        def transform
            super { |x| ChunkyPNG::Color.rgb(255-R(@original[x/@height, x%@height]),
                                            255-G(@original[x/@height, x%@height]),
                                            255-B(@original[x/@height, x%@height])) }
        end
    end    
end


#Abrir imagen
image = ChunkyPNG::Image.from_file("#{PATH}shin.png")


image2 = Transformer::Negativo.new(image).transform
image2.save("#{PATH}shin2.png")