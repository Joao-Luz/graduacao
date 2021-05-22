#ifndef ARVLISTA_H_
#define ARVLISTA_H_
#include "bitmap.h"

/*
Tipo que define a lista, mais especificamente a sentinela
que sera utilizada para armazenar as informacoes do arquivo
Utilizam-se dois ponteiros para celula, um prim para a inicial
e um ult para a ultima da lista
*/
typedef struct lista Lista;

/*
Tipo que define a arvore binaria, esta que permite a execucao
do algoritmo de Huffman
Utilizam-se dois ponteiros para arvore, uma para cada filho (direia e esquerda),
um unsigned char a ser armazenado e um inteiro para contar a frequencia deste no
arquivo fornecido pelo usuario
*/
typedef struct arv Arv;

/*Inicia uma sentinela, alocando-a dinamicamente
* inputs: -
* output: ponteiro para lista inicializado
* pre-condicao: -
* pos-condicao: sentinela nao nula, com seus dois ponteiros para NULL
*/
Lista* criaLista();

/*Funcao de insercao na lista
* inputs: uma lista e uma estrutura do tipo arvore a ser inserida
* output: -
* pre-condicao: lista nao nula
* pos-condicao: a arvore passada como parametro eh inserida no inicio da lista
*/
void insereLista(Lista* l, Arv* a);

/*Funcao de liberacao da memoria (da lista e seus componentes)
* inputs: uma lista
* output: -
* pre-condicao: lista nao nula
* pos-condicao: todas as arvores contidas na lista e a propria lista sao liberadas da memoria
*/
void liberaLista(Lista* l);

/*Funcao para ordenar a lista de forma crescente
* inputs: uma lista
* output: -
* pre-condicao: lista nao nula
* pos-condicao: a lista passada agora esta ordenada de forma crescente de acordo
                com as frequencias de cada arvore
*/
void ordenaLista(Lista* l);

/*Funcao de impressao da lista (AUXILIAR)
* inputs: uma lista
* output: -
* pre-condicao: lista nao nula
* pos-condicao: o unsigned char e a frequencia de cada arvore sao impressas no terminal
*/
void imprimeLista(Lista* l);

/*Funcao de insercao na lista, ja em ordem crescente
* inputs: uma lista e uma arvore
* output: -
* pre-condicao: lista nao nula
* pos-condicao: arvore do parametro inserida na lista na posicao devida para o
                algoritmo de Huffman ser executado posteriomente
*/
void insereOrdenado(Lista* l, Arv* a);

/*Funcao de remocao da primeira arvore da lista
* inputs: uma lista
* output: a primeira arvore da lista, que foi retirada
* pre-condicao:lista nao nula
* pos-condicao: lista agora sem seu primeiro componente
*/
Arv* retiraListaPrim(Lista* l);

/*Cria uma arvore vazia
* inputs: -
* output: NULL (arvore)
* pre-condicao: -
* pos-condicao: -
*/
Arv* criaArvVazia();

/*Funcao de criacao de uma arvore
* inputs: um unsigned char, um inteiro para o contador da frequencia e dois
          ponteiros para arvore, um pra esquerda outro direita
* output: arvore inicializada com os parametros passados para a funcao
* pre-condicao: -
* pos-condicao: a arvore eh caracterizada pelos parametros
*/
Arv* criaArv(unsigned char c, int f, Arv* e, Arv* d);

/*Funcao recursiva para liberar a arvore da memoria
* inputs: uma arvore
* output: NULL (arvore)
* pre-condicao: -
* pos-condicao: arvore, todos seus filhos e suas respectivas caracteriscas
                sao liberados da memoria
*/
Arv* liberaArvore(Arv* a);

/*Funcao de impressao da arvore
* inputs: uma arvore
* output: -
* pre-condicao: -
* pos-condicao: arvore e todos os seus filhos tem seu unsigned char (em valor
                ASCII) e sua frequencia impressos
*/
void imprimeArv(Arv* a);

/*Retorna a frequencia do unsigned char presente na arvore
* inputs: uma arvore
* output: inteiro representando o numero de aparicoes do unsigned char
* pre-condicao: -
* pos-condicao: caso arvore nula, retorna 0, no contrario retorna a frequencia
*/
int retornaFreqArv(Arv* a);

/*Retorna o tamanho da lista
* inputs: uma lista
* output: um inteiro representando o numero de celulas na lista
* pre-condicao: lista nao nula
* pos-condicao: -
*/
int tamLista(Lista* l);

/*Funcao de verificacao de arvore, para checar se eh ou nao folha
* inputs: uma arvore
* output: um inteiro logico
* pre-condicao: arvore nao nula
* pos-condicao: retorna 1 caso seja folha, 0 caso contrario
*/
int folha(Arv* a);

/*Funcao recursiva para a codificacao dos caracteres da arvore de Huffman
* inputs: uma arvore e uma matriz de unsigned chars
* output: -
* pre-condicao: -
* pos-condicao: todas as folhas da arvore sao codificadas para a compressao
*/
void percorreArvHuffman(Arv* a, unsigned char vet[][256]);

/*Funcao de impressao da arvore de Huffman, com os caracteres codificados
* inputs: uma arvore e um arquivo
* output: -
* pre-condicao: arquivo nao nulo
* pos-condicao: arvore impressa com seus caracteres e codificacoes
*/
void imprimeHuffman(Arv* a, FILE* saida);

/*Funcao de impressao de um bitmap no arquivo para auxiliar o descompactador
* inputs: um bitmap e um arquivo
* output: -
* pre-condicao: arquivo nao nulo
* pos-condicao: bitmap impresso no arquivo fornecido
*/
void salvaArquivo(bitmap bm, FILE* saida);

/*Funcao que checa o tamanho do bitmap
* inputs: um bitmap e um arquivo
* output: -
* pre-condicao: arquivo nao nulo
* pos-condicao: -
*/
void checaBitmap(bitmap* bm, FILE* saida);

/*
* inputs: uma arvore e uma matriz de unsigned char
* output: a quantidade de bits a serem lidos no ultimo byte do arquivo
* pre-condicao: -
* pos-condicao: -
*/
int calculaIgnorar(Arv* a, unsigned char vet[][256]);

#endif
