#ifndef COMPACTADOR_H_
#define COMPACTADOR_H_
#include "arvlista.h"

//"maior" tipo do trabalho, contendo o nome do arquivo passado, o
//tipo (extensao) do arquivo, o arquivo a ser lido, um vetor de inteiros
//para contagem de frequencia, a arvore de huffman e uma tabela para
//guardar os caracteres e seus respectivos codigos
typedef struct comp Comp;

/*Funcao de criacao do compactador
* inputs: uma string com o nome do arquivo e o arquivo
* output: compactador ja inicializado
* pre-condicao: -
* pos-condicao: compactador inicializado, ja com o nome do arquivo,
                a terminacao do arquivo, o proprio arquivo, tabela
                e vetor de frequencias inicializados e arvore de huffman
                apontando para NULL
*/
Comp* criaComp(char* dir, FILE* arquivo);

/*Insere as informacoes obtidas pelo vetor de frequencias em uma lista
* inputs: um vetor de inteiros
* output: uma lista
* pre-condicao: vetor de comprimento minimo 256
* pos-condicao: lista ja inicializada e com as devidas informacoes dos
                caracteres
*/
Lista* converteVetLista(int vet[]);

/*Realiza o algoritmo de Huffman para compactacao
* inputs: uma lista
* output: uma arvore de huffman
* pre-condicao: -
* pos-condicao: arvore de Huffman ja montada e lista com apenas uma celula
*/
Arv* Huffman(Lista* l);

/*Libera o tipo compactador da memoria
* inputs: um compactador
* output: /
* pre-condicao: compactador nao nulo
* pos-condicao: compactador e seus componentes liberados da memoria
*/
void liberaComp(Comp* c);

/*Compacta o arquivo fornecido pelo usuario
* inputs: um compactador e o nome do arquivo fornecido pelo usuario
* output: -
* pre-condicao: compactador nao nulo
* pos-condicao: arquivo fornecido compactado
*/
void compacta(Comp* c, char* dir);

/*Imprime o componente nome do compactador
* inputs: um compactador
* output: -
* pre-condicao: compactador nao nulo
* pos-condicao: campo nome impresso no terminal
*/
void imprimeNome(Comp* c);

/*Imprime a extensao do arquivo fornecido pelo usuario
* inputs: um compactador
* output:-
* pre-condicao: compactador nao nulo
* pos-condicao: campo tipo do impresso no terminal
*/
void imprimeTipo(Comp* c);

/*Imprime os campos do compactador
* inputs: um compactador
* output: -
* pre-condicao: compactador nao nulo
* pos-condicao: campos nome e tipo impressos no terminal, e
                arvore impressa
*/
void imprimeComp(Comp* c);

/*Gera o arquivo de saida com o mesmo nome, alterando a extensao e compactado
* inputs: um compactador
* output: -
* pre-condicao: compactador nao nulo
* pos-condicao: arquivo compactado ja gerado para ser descompactado
*/
void geraArquivoComp(Comp* c);

/*Imprime o arquivo fornecido pelo usuario ja codificado
* inputs: um compactador e um arquivo de saida
* output: -
* pre-condicao: compactador e arquivo nao nulos
* pos-condicao: arquivo foi lido e impresso de maneira comprimida
*/
void imprimeCodificado(Comp* c, FILE* saida);

#endif
