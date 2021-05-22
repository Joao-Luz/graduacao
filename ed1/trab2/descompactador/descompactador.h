#ifndef DESCOMPACTADOR_H_
#define DESCOMPACTADOR_H_
#include "arvore.h"

/*Tipo estruturado representando o descompactador
  Utilizam-se duas strings, uma para o nome do arquivo e outra para extensao,
  uma arvore que armazenara a arvore de Huffman para descompactacao, o arquivo
  fornecido pelo usuario e UM INTEIRO///////////////////*/
typedef struct descompactador Descomp;

/*Cria tipo estruturado descompactador
* inputs: um arquivo
* output: descompactador ja inicializado na memoria
* pre-condicao: arquivo nao nulo
* pos-condicao: descompactador possui todos os seus campos preenchidos por meio
                da leitura do arquivo
*/
Descomp* criaDescomp(FILE* arquivo);

/*Recupera o nome do arquivo original compactado
* inputs: um arquivo
* output: uma string
* pre-condicao: arquivo nao nulo
* pos-condicao: -
*/
char* recuperaNome(FILE* arquivo);

/*Recupera a extensao do arquivo original antes de ser compactado
* inputs: um arquivo
* output: uma string
* pre-condicao: arquivo nao nulo
* pos-condicao: -
*/
char* recuperaTipo(FILE* arquivo);

/*Recupera a arvore de Huffman que foi usada para a compactacao do arquivo
* inputs: um arquivo
* output: uma arvore
* pre-condicao: arquivo nao nulo
* pos-condicao: arvore enviada agora possui as informacoes utilizadas no compactador
*/
Arv* recuperaHuffman(FILE* arquivo);

/*Recupera o inteiro ignorar contido no arquivo compactado
* inputs: um arquivo
* output: um inteiro
* pre-condicao: arquivo nao nulo
* pos-condicao: -
*/
int recuperaIgnorar(FILE* arquivo);

/*Libera o descompactador da memoria
* inputs: um descompactador
* output: -
* pre-condicao: descompactador nao nulo
* pos-condicao: descompactador e todos os seus componentes alocados sao liberados
                da memoria
*/
void liberaDescomp(Descomp* dc);

/*Descompacta o arquivo fornecido pelo usuario (ja compactado)
* inputs: um descompactador
* output: -
* pre-condicao: descompactador nao nulo
* pos-condicao: o arquivo compactado fornecido pelo usuario eh descompactado
*/
void descompacta(Descomp* dc);

#endif
