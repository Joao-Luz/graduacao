package main

import "fmt"

func main() {
	// mapas mapeiam chaves a valores, como uma tabela hash
	// deve ser informado o tipo da chave bem como do elemento, que é passado para make()
	uni := make([string]string)
	uni["Ufes"] = "Espírito Santo"
	uni["USP"] = "São Paulo"
	uni["Ufal"] = "Alagoas"
	
	fmt.Println()
}