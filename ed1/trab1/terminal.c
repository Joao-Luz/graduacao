#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roteador.h"
#include "terminal.h"

struct terminal{

  Rot* conectado; //roteador conectado
  char* nome; //nome do terminal
  char* local;  //localizacao do terminal

};

struct listaTer{

  CelulaT* prim;  //ponteiro pra primeira celula
  CelulaT* ult;   //ponteiro para ultima celula

};


struct celulaT{

  Ter* terminal;  //ponteiro para terminal
  CelulaT* prox;  //proxima celula
  CelulaT* ant;   //celula anterior

};

void insereTer(Ter* terminal, TerLista* lista){

  CelulaT* cel=(CelulaT*)malloc(sizeof(CelulaT)); //aloca a celula dinamicamente
  cel->ant=NULL;
  cel->prox=NULL;

  if(lista->prim==NULL){  //se a lista estiver vazia
    lista->prim=cel;
  }
  else{ //caso contrario
    lista->ult->prox=cel;
    cel->ant=lista->ult;
  }
  lista->ult=cel; //acrescentada no final da lista
  cel->terminal=terminal; //nova celula recebe o terminal do parametro
}

int retiraTer(char* nome, TerLista* lista){
  CelulaT* temp;  //celula para percorrer a lista

  for(temp=lista->prim; strcmp(temp->terminal->nome,nome); temp=temp->prox){  //percorre ate encontrar
    if(temp->prox==NULL){ //caso contrario, retorna 0
      return 0;
    }
  }
  if(temp==lista->prim && temp==lista->ult){  //se a lista tiver apenas um elemento
    lista->prim=NULL;
    lista->ult=NULL;
  }

  else if(temp==lista->prim){ //se for o primeiro elemento
    lista->prim=temp->prox;
    temp->prox->ant=NULL;
  }
  else if(temp==lista->ult){  //se for o ultimo elemento
    temp->ant->prox=NULL;
    lista->ult=temp->ant;
  }
  else{
    temp->ant->prox=temp->prox; //proxima da anterior recebe proxima da atual
    temp->prox->ant=temp->ant;  //anterior da proxima recebe anterior da atual
  }

  liberaTer(temp->terminal);
  free(temp);
  return 1;
}

void liberaTer(Ter* terminal){

  free(terminal->nome);
  free(terminal->local);
  free(terminal);
}

void liberaListaTer(TerLista* lista){
  CelulaT *temp=lista->prim, *prox;

  while(temp!=NULL){
    prox=temp->prox;
    free(temp->terminal->nome);
    free(temp->terminal->local);
    free(temp->terminal);
    free(temp);
    temp=prox;
  }
  free(lista);
}

Ter* iniciaTer(char* nome, char* local){
  Ter* terminal=(Ter*)malloc(sizeof(Ter));
  terminal->nome=(char*)malloc((strlen(nome)+1)*sizeof(char));
  terminal->local=(char*)malloc((strlen(local)+1)*sizeof(char));
  terminal->conectado=NULL;

  strcpy(terminal->nome, nome);
  strcpy(terminal->local, local);

  return terminal;
}

TerLista* iniciaListaTer(){

  TerLista* lista=(TerLista*)malloc(sizeof(TerLista));
  lista->prim=NULL;
  lista->ult=NULL;
  return lista;
}

void printTerLista(TerLista* lista, FILE *saida){

  CelulaT* temp;  //celula para percorrer a lista
  char* roteador; //aramazena nome de um roteador

  for(temp=lista->prim; temp!=NULL; temp=temp->prox){ //percorre a lista completa
    roteador= recuperaNomeRoteador(temp->terminal->conectado);  //recebe nome do roteador conectado ao terminal
    if(roteador){ //imprime terminal e sua conexao (se houver)
      fprintf(saida, "%s -- %s;\n",temp->terminal->nome, roteador);
    }
    else fprintf(saida, "%s;\n", temp->terminal->nome); //imprime assim se nao houver conexao
  }
}

void ligaTer(Ter* terminal, Rot* roteador){
  terminal->conectado=roteador; //liga o terminal ao roteador
}

Ter* encontraTer(char* nome, TerLista* lista){
  CelulaT* temp;  //percorre a lista
  for(temp=lista->prim; temp!=NULL && strcmp(temp->terminal->nome,nome); temp=temp->prox);  //percorre a lista ate encontrar o terminal
  if(temp==NULL) return NULL; //caso nao encontre, retorna NULL
  return temp->terminal;  //se encontrar, o retorna
}

int Terminal(char* local, TerLista* lista){
  CelulaT* temp=lista->prim;  //percorre a lista
  int freq=0;
  while(temp!=NULL){  //percorre a lista ate o final
    if(!strcmp(temp->terminal->local, local)) freq++; //caso encontre terminal com mesma localizacao, acrescenta 1 a variavel
    temp=temp->prox;
  }
  return freq;
}

void desligaTer(Ter* terminal){
  terminal->conectado=NULL; //retira conexao com terminal
}

int checaConexaoTer(Ter* ter1, Ter* ter2){//funcao auxiliar para a chamada da funcao "checaConexao"
  if(ter1->conectado==NULL || ter2->conectado==NULL) return 1;  //verifica se algum dos terminais aponta para NULL
  return checaConexao(ter1->conectado, ter2->conectado);  //chama a funcao "checaConexao" do "roteador.h"
}

void separaTer(char* roteador, TerLista* lista){
  char* nomeConectado;  //recebe o nome do roteador
  CelulaT* temp;
  for(temp=lista->prim; temp!=NULL; temp=temp->prox){ //percorre a lista completa de terminais
    nomeConectado=recuperaNomeRoteador(temp->terminal->conectado);
    if(nomeConectado!=NULL && !strcmp(nomeConectado, roteador)) desligaTer(temp->terminal);//caso encontre um terminal ligado ao roteador de nome "roteador", desconecta esse terminal
  }
}
