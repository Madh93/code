require "chunky_png"
require_relative "utils/rgb"

module Transformer
  class Transformation
      
    include Rgb
    
    def initialize(img)
      @original = img
      @image, @width, @height = nil
    end

    def create_image
      @image = yield
      @width = @image.width
      @height = @image.height
    end
    
    def transform
      create_image
      size = @width*@height
      
      (0...size).each do |x|
        @image[x/@height, x % @height] = yield x
      end
      
      @image
    end
  end
end