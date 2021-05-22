package main

import "fmt"

func main() {

	i := 0
	for i < 10 {
		i += 2
	}

	for {
		fmt.Println("Vou ficar aqui para sempre!")
	}


	for j := 0; j < 10; j++ {
		fmt.Println(j)
	}

	if i > 0 {
		fmt.Println("Maior que zero")
	} else if i == 0 {
		fmt.Println("Zero")
	} else {
		fmt.Println("O que?")
	}
}
