require_relative "transformer/version"
require_relative "transformer/espejovertical"
require_relative "transformer/espejohorizontal"
require_relative "transformer/traspuesta"
require_relative "transformer/negativo"
require_relative "transformer/vecinoproximo"
require_relative "transformer/bilineal"
require_relative "transformer/rotacion"

PATH = "img/"
NAME = "bogart"



image = ChunkyPNG::Image.from_file("#{PATH}#{NAME}.png")

# image2 = Transformer::Bilineal.new(image,2.0).transform
image2 = Transformer::Rotacion.new(image,90).transform
image2.save("#{PATH}#{NAME}2.png")