module Transformer
  module Rgb
    
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
end