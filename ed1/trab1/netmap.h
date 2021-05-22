#ifndef NETMAP_H_
#define NETMAP_H_

/*Tipo que define o netmap
Armazena a lista de todos os terminais e a lista de todos os roteadores do netmap
Utiliza-se um ponteiro para lista de roteadores armazenando os roteadores
Utiliza-se um ponteiro para lista de terminais armazenando os terminais
Utiliza-se um inteiro flag para auxiliar na impressao do .dot
*/
typedef struct netmap NetMap;

/*Inicializa as listas internas do tipo NetMap
*inputs: nenhum
*outputs: netmap inicializado
*pre-condicao: nenhuma
*pos-condicao: netmap nao nulo, com as sentinelas das listas de roteador e terminal apontando pra NULL
*/
NetMap* iniciaNetMap();

/*Coordena todas as acoes dadas pelo usuario no netmap
* inputs: argc (tipo int), argv (tipo char**) e o netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: netmap nao nulo
* pos-condicao: nenhuma
*/
void runNetMap(int argc, char** argv, NetMap* netmap);

/*Insere um novo roteador no netmap
* inputs: nome e operadora (tipo char*) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nome, operadora e netmap nao nulos
* pos-condicao: roteador cadastrado na lista do netmap
*/
void cadastraRoteador(char* nome, char* operadora, NetMap* netmap);

/*Insere um novo terminal no netmap
* inputs: nome e local (tipo char*) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nome, local e netmap nao nulos
* pos-condicao: terminal cadastrado na lista do netmap
*/
void cadastraTerminal(char* nome, char* local, NetMap* netmap);

/*Remove roteador do netmap
* inputs: nome (tipo char*) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nome e netmap nao nulos
* pos-condicao: roteador (se presente na lista) removido da lista
*/
void removeRoteador(char* nome, NetMap* netmap);

/*Remove terminal do netmap
* inputs: nome (tipo char*) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nome e netmap nao nulos
* pos-condicao: terminal (se presente na lista) removido da lista
*/
void removeTerminal(char* nome, NetMap* netmap);

/*Conecta dois roteadores
* inputs: dois nomes de roteadores (strings) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nomes e netmap nao nulos
* pos-condicao: caso existam, os roteadores sao conectados em suas listas de conexoes
*/
void conectaRoteadores(char* rot1, char* rot2, NetMap* netmap);

/*Conecta um terminal a um roteador
* inputs: um nome de terminal e um de roteador (strings) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nomes e netmap nao nulos
* pos-condicao: caso existam, o terminal eh conectado ao roteador
*/
void conectaTerminal(char* ter, char* rot, NetMap* netmap);

/*Desconecta dois roteadores
* inputs: dois nomes de roteadores (strings) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nomes e netmap nao nulos
* pos-condicao: caso existam, sao desconectados de suas respectivas listas de conexoes
*/
void desconectaRoteadores(char* rot1, char* rot2, NetMap* netmap);

/*Desconecta um terminal do seu roteador
* inputs: nome do terminal (string) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nome e netmap nao nulos
* pos-condicao: caso exista, terminal desconectado do seu roteador
*/
void desconectaTerminal(char* terminal, NetMap* netmap);

/*Conta o numero de vezes que uma operadora aparece
* inputs: nome da operadora (string) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: operadora e netmap nao nulos
* pos-condicao: frequencia da operadora impressa em saida.txt
*/
void frequenciaOperadora(char* operadora, NetMap* netmap);

/*Conta o numero de vezes que uma localizacao de terminal aparece
* inputs: nome do local (string) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: local e netmap nao nulos
* pos-condicao: frequencia do terminal impressa em saida.txt
*/
void frequenciaTerminal(char* local, NetMap* netmap);

/*Checa a disponibilidade do envio de dados entre dois terminais
* inputs: dois nomes de terminais (strings) e um netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: nomes e netmap nao nulos
* pos-condicao: nenhuma
*/
void enviaDados(char* ter1, char* ter2, NetMap* netmap);

/*Imprime netmap no arquivo saida.dot
* inputs: netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: netmap nao nulo
* pos-condicao: netmap impresso no arquivo saida.dot
*/
void imprimeNetMap(NetMap* netmap);

/*Imprime os possiveis erros durante a execucao do programa
* inputs: inteiro identificador do erro (int) e um nome (string)
* output: nenhum
* pre-condicao: nome nao nulo
* pos-condicao: erro impresso no arquivo log.txt
*/
void escreveLog(int erro, char* nome);

/*Libera o netmap da memoria
* inputs: netmap (tipo NetMap*)
* output: nenhum
* pre-condicao: netmap nao nulo
* pos-condicao: netmap liberado da memoria
*/
void liberaNetMap(NetMap* netmap);

#endif
