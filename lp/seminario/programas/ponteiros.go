package main

import "fmt"

func main() {
	// ponteiros, assim como em C, são endereços para um valor na memória
	// são denotados pelo '*' e têm valor zero 'nil'
	var ptr *int
	fmt.Println(ptr)
	
	// o operador '&' gera o endereço de um valor
	i := 10
	ptr = &i
	fmt.Println(ptr)
	
	// o operador '*' dereferencia o ponteiro
	fmt.Println(*ptr)

	// não existe aritmética de ponteiros :(
	// ptr++
}
