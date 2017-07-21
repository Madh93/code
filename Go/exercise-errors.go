package main

import (
	"fmt"
)

type ErrNegativeSqrt float64

// TODO: Add a "(e ErrNegativeSqrt) Error() string" method.
func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", int(e))
}

func Sqrt(x float64) (z float64, err error) {

	if x < 0 {
		err = ErrNegativeSqrt(x)
		return
	}

	z = 1.0
	for i := 0; i < 10; i++ {
		z0 := z
		z = z0 - ((z0*z0 - x) / (2 * z0))
	}

	return
}

func main() {

	result, err := Sqrt(2)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(result)

	result2, err2 := Sqrt(-2)
	if err2 != nil {
		fmt.Println(err2)
		return
	}
	fmt.Println(result2)
}
