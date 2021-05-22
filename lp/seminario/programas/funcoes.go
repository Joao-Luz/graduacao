package main

import (
	"fmt"
	"strings"
	"errors"
)

// funcones sao definidas pelo nome 'func', seguido de seu nome, parametros e retornos
func multiplicaPorDois(x int) (int) {
	return x*2
}

// multiplos parametros com o mesmo tipo podem ser declarados assim
func multiplicaTres(x, y, z int) (int) {
	return x*y*z
}

// pode ter um numero indefinido de parametros, que sao passados como uma 'slice'
func multiplicaTodos(params ...int) (int) {
	p := 1
	for i := 0; i < len(params); i++ {
		p *= params[i]
	}
	return p
}

// pode ter mais de um retorno
func nomeSobrenome(nomeCompleto string) (string, string) {
	separada := strings.Split(nomeCompleto, " ")
	return separada[0], separada[1]
}

// o que pode ser usado para tratamento de erros
func nomeSobrenomeSeguro(nomeCompleto string) (string, string, error) {
	separada := strings.Split(nomeCompleto, " ")
	if len(separada) < 2 {
		return "", "", errors.New("O nome completo só tem o primeiro nome!")
	}
	return separada[0], separada[1], nil
}

// funções são valores também! Podem ser passadas como parâmetros
func separaNomes(nomeCompleto string, operacao func(string) (string, string)) {
	nome, sobrenome := operacao(nomeCompleto)
	fmt.Printf("Primeiro nome é %s e segundo nome é %s\n", nome, sobrenome)
}

func main() {
	fmt.Println(multiplicaPorDois(10))
	fmt.Println(multiplicaTres(2, 6, 13))
	fmt.Println(multiplicaTodos(1, 2, 3, 4, 5, 6, 7, 8, 9))

	nome, sobrenome := nomeSobrenome("Dale Cooper")
	fmt.Printf("Agente especial %s, %s %s\n", sobrenome, nome, sobrenome)

	nome, sobrenome, err := nomeSobrenomeSeguro("Dale")
	if err != nil {
		fmt.Println(err)
	}

	separaNomes("Dale Cooper", nomeSobrenome)
}