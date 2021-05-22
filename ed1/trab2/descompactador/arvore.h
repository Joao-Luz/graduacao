#ifndef ARVORE_H_ //////////descodifica
#define ARVORE_H_

/*Estrutura arvore que armazenara um caracter
  Utilizam-se dois ponteiros, um pra filho a esquerda, outro para
  filho a direita, configurando o tipo estruturado*/
typedef struct arvore Arv;

/*Cria uma arvore vazia
* inputs: -
* output: NULL (arvore)
* pre-condicao: -
* pos-condicao: -
*/
Arv* criaVazia();

/*Cria uma arvore ja com suas caracteristicas
* inputs: um unsigned char e duas arvores
* output: uma arvore
* pre-condicao: -
* pos-condicao: arvore retornada possui os atributos passados como parametro
*/
Arv* criaArv(unsigned char c, Arv* e, Arv* d);

/*Libera uma arvore e todos os seus filhos
* inputs: uma arvore
* output: -
* pre-condicao: -
* pos-condicao: arvore liberada da memoria
*/
void liberaArv(Arv* a);

/*Cria a arvore de Huffman lida no arquivo de entrada (compactado)
* inputs: um arquivo
* output: uma arvore (de Huffman)
* pre-condicao: arquivo nao nulo
* pos-condicao: arvore retornada possui as caracteristicas da arvore de Huffman
                utilizada na compactacao
*/
Arv* criaHuffman(FILE* arquivo);

/*Verifica se a arvore do parametro eh folha
* inputs: uma arvore
* output: um inteiro logico
* pre-condicao: arvore nao nula
* pos-condicao: retorna 1 caso seja folha, zero caso contrario
*/
int folha(Arv* a);

/*Imprime uma arvore e seus filhos
* inputs: uma arvore
* output: -
* pre-condicao: -
* pos-condicao: arvore impressa no terminal
*/
void imprimeArv(Arv* a);

/*Descodifica o arquivo compactado fornecido pelo usuario e gera o arquivo descompactado
* inputs: dois arquivos, uma arvore e um inteiro
* output: -
* pre-condicao: arquivos e arvore nao nulos
* pos-condicao: o arquivo "entrada" (arquivo compactado) eh descompactado e eh gerado um arquivo descompactado
*/
void descodifica(FILE* entrada, Arv* aOrg, int ignorar, FILE* saida);

#endif
