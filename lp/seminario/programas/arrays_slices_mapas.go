package main

import "fmt"

func main() {
	// arrays são coleções de elementos do mesmo tipo e de tamanho fixo
	var arrInt [10]int
	for i := 0; i < len(arrInt); i++ {
		arrInt[i] = i*i
	}
	fmt.Println(arrInt)

	// slices são cabeçalhos para arays dinâmicos e são criadas com a função make
	// deve-se passar o tamanho e a capacidade da slice, mas se fornecido apenas um
	sliceInt := make([]int, 10)
	// a slice tem tamanho e capacidade iguais
	for i := 0; i < len(sliceInt); i++ {
		sliceInt[i] = i*i
	}
	fmt.Println(sliceInt)

	// slices podem ser criadas a partir de outras de uma forma intuitiva
	novaSlice := sliceInt[2:7]
	fmt.Println(novaSlice)

	// inserir elementos é fácil com append(), que retorna uma nova slice
	novaSlice = append(sliceInt, 100, 121, 144)
	fmt.Println(sliceInt)
	fmt.Println(novaSlice)

	// iterar sobre esses elementos é comodo com range
	for i, v := range novaSlice {
		fmt.Printf("%d^2 = %d\n", i, v)
	}
	
	// mapas mapeiam chaves a valores, como uma tabela hash
	// deve ser informado o tipo da chave bem como do elemento, que é passado para make()
	uni := make(map[string]string)
	uni["Ufes"] = "Espírito Santo"
	uni["USP"] = "São Paulo"
	uni["Ufal"] = "Alagoas"
	
	fmt.Println(uni["USP"])

}