#ifndef TERMINAL_H_
#define TERMINAL_H_

/*Tipo que define a lista duplamente encadeada com sentinela
Serao armazenados todos os terminais pertencentes ao netmap*/
typedef struct listaTer TerLista;

/*Tipo onde serao armazenados os atributos dos terminais
  Utiliza-se ponteiros pra char para armazenar o nome e a localizacao
  Utiliza-se ponteiro pra roteador para armazenar a conexao do terminal
*/
typedef struct terminal Ter;

/*Tipo onde armazena-se as informacoes de um terminal
  Apresenta tambem ponteiro para terminal anterior e posterior
  para navegacao na lista duplamente encadeada
*/
typedef struct celulaT CelulaT;

/*Inicia a sentinela da lista duplamente encadeada
* inputs: nenhum
* output: tipo lista de terminais ja inicializada
* pre-condicao: nenhuma
* pos-condicao: sentinelas do retorno foram inicializadas e apontam para NULL
*/
TerLista* iniciaListaTer();

/*Insere um novo terminal no final da lista de terminais
* inputs: um terminal (tipo Ter*) e uma lista de terminais (tipo TerLista*)
* output: nenhum
* pre-condicao: terminal e lista nao nulos
* pos-condicao: lista contem o terminal conectado na ultima posicao
*/
void insereTer(Ter* terminal, TerLista* lista);

/*Retira um terminal da lista de terminais (caso esteja contido nesta)
* inputs: uma string com o nome do terminal a ser retirado e a lista de
terminais (tipo TerLista*)
* output: caso encontre o terminal, retorna 1, no contrario retorna 0
* pre-condicao: lista e nome nao nulos
* pos-condicao: terminal com o nome especificado, se estava presente na lista,
eh removido e seu espaco alocado eh liberado
*/
int retiraTer(char* nome, TerLista* lista);

/*Libera o espaco alocado dinamicamente pelo terminal
* inputs: termial (tipo Ter*)
* output: nenhum
* pre-condicao: terminal, nome e local nao nulos
* pos-condicao: terminal liberado da memoria
*/
void liberaTer(Ter* terminal);

/*Libera o espaco alocado dinamicamente pela lista de terminais e seus terminais
nela contidos
* inputs: lista de terminais (tipo TerLista*)
* output: nenhum
* pre-condicao: lista nao nula
* pos-condicao: lista e seus componentes liberados da memoria
*/
void liberaListaTer(TerLista* lista);

/*Inicializa um terminal
* inputs: um nome e uma localizacao (ambos strings)
* output: terminal ja inicializado
* pre-condicao: strings nao nulas
* pos-condicao: terminal com nome "nome" e local "local"
*/
Ter* iniciaTer(char* nome, char* local);

/*Imprime a lista de terminais
* inputs: lista de terminais (tipo TerLista*) e arquivo de saida (tipo FILE*)
* output: os terminais e suas respectivas conexoes (caso houverem) no .dot
* pre-condicao: lista e arquivo nao nulos
* pos-condicao: impressao dos terminais e suas conexoes (caso houverem) no
formato .dot
*/
void printTerLista(TerLista* lista, FILE * saida);

/*Conecta um terminal em um roteador
* inputs: um terminal (tipo Ter*) e um roteador (tipo Rot*)
* output: nenhum
* pre-condicao: terminal nao nulo
* pos-condicao: terminal conectado com o roteador especificado
*/
void ligaTer(Ter* terminal, Rot* roteador);

/*Remove a conexao entre terminal e roteador
* inputs: um terminal (tipo Ter*)
* output: nenhum
* pre-condicao: terminal nao nulo
* pos-condicao: terminal sem conexao
*/
void desligaTer(Ter* terminal);

/*Busca um terminal especifico na lista de terminais
* inputs: lista de terminais (tipo TerLista*) e o nome do terminal (string)
* output: terminal pedido
* pre-condicao: lista e nome nao nulos
* pos-condicao: nenhuma
*/
Ter* encontraTer(char* nome, TerLista* lista);

/*Conta e retorna o numero de vezes que um mesmo local aparece na lista
* inputs: uma lista de terminais (tipo TerLista*) e um local (string)
* output: frequencia do terminal
* pre-condicao: lista e local nao nulos
* pos-condicao: nenhuma
*/
int Terminal(char* local, TerLista* lista);

/*Confere a existencia ou nao de conexao entre dois terminais
* inputs: dois terminais (tipo Ter*)
* output: um inteiro, indicando se há conexao entre dois terminais ter1 e ter2 (0 se existe, 1 se nao existe)
* pre-condicao: terminais nao nulos
* pos-condicao: nenhuma
*/
int checaConexaoTer(Ter* ter1, Ter* ter2);

/*Desconecta os terminais ligados ao roteador removido
* inputs: uma string "roteador" e uma lista de terminais
* output: nenhum
* pre-condicao: lista nao nula
* pos-condicao: terminais conectados ao roteador de nome "roteador" possuem ponteiro "conectado" igual a NULL
*/
void separaTer(char* roteador, TerLista* lista);


#endif
