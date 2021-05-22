package main

import (
	"fmt"
)

func corrida(id string, c chan string) {
	for i:=0; i<1e9; i++ {

	}
	c <- id
}

func main() {
	c := make(chan string)
	go corrida("Flash", c)
	go corrida("Super Homem", c)
	go corrida("Papaléguas", c)
	prim, seg, ter := <-c, <-c, <-c
	fmt.Printf("Primeiro: %s\nSegundo: %s\nTerceiro: %s\n", prim, seg, ter)
}
