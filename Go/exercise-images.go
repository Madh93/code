package main

import (
	"golang.org/x/tour/pic"
	"image"
	"image/color"
)

type Image struct {
	Width  int
	Height int
	Color  uint8
}

func (img *Image) Bounds() image.Rectangle {
	return image.Rect(0, 0, img.Width, img.Height)
}

func (img *Image) ColorModel() color.Model {
	return color.RGBAModel
}

func (img *Image) At(x, y int) color.Color {
	return color.RGBA{img.Color, img.Color, 255, 255}
}

func main() {
	m := Image{Width: 100, Height: 100, Color: 127}
	pic.ShowImage(&m)
}
