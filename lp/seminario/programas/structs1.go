package main

import "fmt"

// structs, assim como em C, são coleções de campos
type Pokemon struct {
	nome string
	tipo string
	hp, atk, def int
}

func main() {
	// são declarados levando em consideração a ordem dos campos
	pikachu := Pokemon{"Pikachu", "Elétrico", 120, 200, 160}
	// ou com os campos explícitos (campos omitidos recebem valor zero)
	blastoise := Pokemon{nome: "Blastoise", hp: 240, def: 200}

	// campos são acessados por '.'
	fmt.Println(pikachu.nome, "possui", pikachu.hp, "pontos de HP")
	fmt.Println(blastoise.nome, "é do tipo", blastoise.tipo, "com", blastoise.atk, "pontos de ataque")

	// ponteiros para structs têm seus elementos acessados por '.', diferente de '->' em C
	charmander := &Pokemon{"Charmander", "Fogo", 100, 140, 120}
	fmt.Printf("%T\n", charmander)
	fmt.Println(charmander.nome, "é do tipo", charmander.tipo)

}
