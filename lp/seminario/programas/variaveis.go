package main

import (
	"fmt"
)

func main() {
	// variaveis sao definidas como var ou const
	// e sao acompanhadas de um tipo
	var inteiro int = 1
	const floatConstante float32 = 3.14
	fmt.Println(inteiro, floatConstante)

	// caso nao seja fornecido um valor, ela recebe o valor zero do tipo
	var outroInteiro int
	var string string
	fmt.Println(outroInteiro)
	fmt.Println(string)

	// o tipo pode ser inferido pelo valor que é passado
	var inferido = 10
	var outroInferido = "bola"
	fmt.Printf("%T %T\n", inferido, outroInferido)

	// uma variavel tambem pode ser inferida usando o operador ':='
	// aqui, 'var' fica omitido
	ultimoInteiro := 5
	ultimaString := "carro"
	fmt.Println(ultimoInteiro, ultimaString)
}
