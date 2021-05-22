#ifndef ROTEADOR_H_ ///////////////////////////////////comentar checaConexao
#define ROTEADOR_H_

/*Tipo que define a lista
  Estrutura interna do tipo deve ser definida na implementação do TAD.
*/
typedef struct listaRot RotLista;

/**/
typedef struct roteador Rot;

/**/
typedef struct celulaR CelulaR;

/*Inicia a sentinela de uma lista de roteadores
* inputs: nenhum
* output: sentinela inicializada
* pre-condicao: nenhum
* pos-condicao: sentinela do retorno foi inicializada e aponta para NULL
*/
RotLista* iniciaListaRot();

/*insere um roteador na primeira posicao da lista
* inputs: um roteador (tipo Rot) e uma lista de roteadores (do tipo ListaRot)
* output: nenhum
* pre-condicao: roteador e lista nao nulos
* pos-condicao: roteador na ultima posicao da lista
*/
void insereRot(Rot* roteador, RotLista* lista);

/*remove um roteador da lista de roteadores (caso esteja contida)
* inputs: o nome do roteador a ser removido (uma string) e a lista de roteadores de onde ele sera removido (tipo RotLista)
* output: nenhum
* pre-condicao: lista nao nula
* pos-condicao: lista nao contem o roteador de nome "nome"
*/
void retiraRot(char* nome, RotLista* lista);

/*libera a memoria alocada para o roteador
* inputs: um roteador (tipo Rot)
* output: nenhum
* pre-condicao: roteador nao nulo
* pos-condicao: memoria alocada pelo roteador liberada
*/
void liberaRot(Rot* roteador);

/*libera a memoria alocada pela lista de roteadores
* inputs: uma lista de roteadores (tipo RotLista)
* output: nenhum
* pre-condicao: lista nao nula
* pos-condicao: memoria alocada pela lista liberada
*/
void liberaListaRot(RotLista* lista);

/*inicia um roteador
* inputs: um nome (tipo string) e uma operadora (tipo string)
* output: roteador (tipo Rot) inicializado
* pre-condicao: strings nao nulas
* pos-condicao: roteador inicializado com nome "nome" e operadora "operadora", flag=0 e uma lista de roteadores inicializada
*/
Rot* iniciaRot(char* nome, char* operadora);

/*imprime os roteadores e suas conexoes no arquivo .dot
* inputs: uma lista de roteadores (tipo RotLista) e um arquivo de saida
* output: as conexoes entre roteadores no arquivo .dot
* pre-condicao: lista e arquivo "saida" no nulos
* pos-condicao: conexoes do roteador impressos no arquivo de formato .dot
*/
void printRotLista(RotLista* lista, FILE * saida);

/*cria uma ligacao entre dois roteadores
* inputs: dois roteadores (tipo Rot)
* output: nenhum
* pre-condicao: roteadores nao nulos
* pos-condicao: cada roteador inserido na lista de conectados do outro
*/
void ligaRot(Rot* rot1, Rot* rot2);

/*desfaz uma conexao entre roteadores
* inputs: dois roteadores (tipo Rot)
* output: nenhum
* pre-condicao: roteadores nao nulos
* pos-condicao: roteadores fora das listas de conectados do outro
*/
void desligaRot(Rot* rot1, Rot* rot2);

/*encontra o roteador de nome "nome" na lista de roteadores
* inputs: um nome de roteador (uma string) e uma lista de roteadores
* output: um roteador (tipo Rot)
* pre-condicao: lista e nome nao nulos
* pos-condicao: nenhuma
*/
Rot* encontraRot(char* nome, RotLista* lista);

/*gera a frequencia da operadora "operadora" na lista
* inputs: uma operadora (string) e uma lista
* output: um inteiro representando o numero de roteadores da operadora na lista
* pre-condicao: lista e string nao nulas
* pos-condicao: nenhuma
*/
int Operadora(char* operadora, RotLista* lista);

/*checa a exitencia de conexao entre dois roteadores
* inputs: dois roteadores (tipo Rot)
* output: um inteiro (0 se existe conexao entre rot1 e rot2, 1 se nao houver)
* pre-condicao: roteadores nao nulos
* pos-condicao: nenhuma
*/
int checaConexao(Rot* rot1, Rot* rot2);

/*remove um roteador da lista, removendo suas conexoes com outros desconectaRoteadores
* inputs: um roteador (tipo Rot) e uma lista de roteadores
* output: nenhum
* pre-condicao: roteador e lista nao nulos
* pos-condicao: roteador fora da lista de roteadores e fora de todas as listas de conexao dos outros roteadores
*/
void removeRot(Rot* rot, RotLista* lista);

/*recupera o nome de um roteador
* inputs: um roteador (tipo Rot)
* output: o nome do roteador (uma string)
* pre-condicao: roteador nao nulo
* pos-condicao: nenhum
*/
char* recuperaNomeRoteador(Rot* roteador);

/*torna os valores das flags de todos os roteadores na lista igual a 0
* inputs: uma lista de roteadores
* output: nenhum
* pre-condicao: lista nao nula
* pos-condicao: todas as flags dos roteadores da lista sao igual a 0
*/
void resetaFlag(RotLista* lista);


#endif
