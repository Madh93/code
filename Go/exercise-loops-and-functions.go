package main

import (
	"fmt"
)

// TODO: Add a "Sqrt(x float64) float64" method.
func Sqrt(x float64) float64 {
	var z float64 = 1.0

	for i := 0; i < 10; i++ {
		z0 := z
		z = z0 - ((z0*z0 - x) / (2 * z0))
	}

	return z
}

func main() {
	fmt.Println(Sqrt(2))
}
