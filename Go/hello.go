package main

import "fmt"

func separator() {
	fmt.Println("-------------------------")
}

func max(a, b int) int {
	if (a >= b) {
		return a
	} else {
		return b
	}
}

func swap(x, y *int) {
	var aux int = *x
	*x = *y
	*y = aux
}

func saludar() {
	fmt.Println("Hola amigo!")
}

func main() {
	fmt.Println("Hello, World!")
	// var i, j int

	const Length int = 20
	const Width int = 10

	// Only visible to the local file
	const localFileConstant string = "Constant Value with limited scope"

	// Exportable constant
	const GlobalConstant string = "Everyone can use this"

	fmt.Println("The area is:", Length*Width)

	var name string = "Migue"
	surname := "Hernandez"

	fmt.Println("Mi nombre es:", name)
	fmt.Println("Mi apellido es:", surname)

	// if (Length == 20) {
	// 	fmt.Println("Dentro de if")
	// }
	//
	// numbers := [6]int{1, 2, 3, 5}
	// for i, x := range numbers {
	// 	fmt.Printf("value of x = %d at %d\n", x, i)
	// }
	//
	// for a := 0; a < 2; a++ {
	// 	fmt.Printf("value of a: %d\n", a)
	// }

	var a, b int = 9, 3
	fmt.Printf("Maximo entre %d y %d es: %d\n", a, b, max(a, b));
	saludar()

	fmt.Println("Longitud de mi nombre:", len(name))

	separator()

	var num int
	var pnum *int
	pnum = &num

	num = 5

	if (pnum != nil) {
		fmt.Println(*pnum)
	}

	fmt.Println("Num valor:", num)
	fmt.Println("Num direccion:", &num)
	fmt.Println("PNum direccion:", pnum)
	fmt.Println("PNum valor:", *pnum)

	separator()

	var datos = [4]int{6, 5, 8, 9}
	// var pdatos [4]*int
	// pdatos[0] = &datos[0]
	var ptr *int
	var pptr **int
	ptr = &datos[0]
	pptr = &ptr

	fmt.Println(*ptr)
	fmt.Println(**pptr)

	separator()

	var num1, num2 int = 3, 8
	fmt.Printf("Num1: %d Num2: %d\n", num1, num2)
	swap(&num1, &num2)
	fmt.Printf("Num1: %d Num2: %d\n", num1, num2)





















}
