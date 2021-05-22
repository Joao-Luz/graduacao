#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roteador.h"

struct listaRot{

  CelulaR* prim;  //ponteiro para primeira celula da lista
  CelulaR* ult; //ponteiro para ultima celula da lista

};

struct roteador{

  RotLista* conectados; //ponteiro para lista de roteadores conectados diretamente ao roteador
  char* nome; //string com nome do roteador
  char* operadora;  //string com operadora do roteador
  int flag;

};

struct celulaR{

  Rot* roteador;  //tipo roteador dentro da celula
  CelulaR* prox;  //ponteiro para proxima celula
  CelulaR* ant; //ponteiro para celula anterior

};

void insereRot(Rot* roteador, RotLista* lista){
  CelulaR* cel=(CelulaR*)malloc(sizeof(CelulaR)); //aloca dinamicamente o espaço de uma celula
  cel->ant=NULL;
  cel->prox=NULL;

  if(lista->prim==NULL){  //se a lista estiver vazia
    lista->prim=cel;
  }
  else{ //caso contrario
    lista->ult->prox=cel;
    cel->ant=lista->ult;
  }
  lista->ult=cel; //celula posta no final da lista
  cel->roteador=roteador; //celula recebe o roteador do parametro
}

void retiraRot(char* nome, RotLista* lista){
  CelulaR* temp;
  for(temp=lista->prim; strcmp(temp->roteador->nome,nome); temp=temp->prox){  //ciclo procurando roteador com o nome solicitado
    if(temp->prox==NULL){ //caso não encontra, retorna
      return;
    }
  }
  if(temp==lista->prim && temp==lista->ult){  //se a lista possui apenas um elemento
    lista->prim=NULL;
    lista->ult=NULL;
  }

  else if(temp==lista->prim){ //se for o primeiro roteador
    lista->prim=temp->prox;
    temp->prox->ant=NULL;
  }
  else if(temp==lista->ult){  //se for o ultimo
    temp->ant->prox=NULL;
    lista->ult=temp->ant;
  }
  else{ //caso contrario
    temp->ant->prox=temp->prox; //proximo da anterior aponta pra proximo da que sera removida
    temp->prox->ant=temp->ant;  //anterior da proxima da atual aponta para anterior da atual
  }
  free(temp);

}

void liberaRot(Rot* roteador){
  free(roteador->conectados);
  free(roteador->nome);
  free(roteador->operadora);
  free(roteador);
}

void liberaListaRot(RotLista* lista){
  CelulaR* temp=lista->prim;  //utilizado para percorrer toda a lista
  CelulaR* p; //percorre a lista de conectados de cada roteador
  CelulaR* tempProx;  //proxima celula da atual
  CelulaR* pProx; //proxima ceula da atual que percorre as conexoes

  while (temp!=NULL){  //enquanto nao chegar no final da lista
    tempProx=temp->prox;  //avanca uma celula
    p=temp->roteador->conectados->prim; //recebe o valor da primeira celula da lista de conectados do roteador
    while(p!=NULL){ //enquanto nao chegar no final da lista de conexoes
      pProx=p->prox;  //recebe a proxima celula das conexoes
      free(p);
      p=pProx;  //avanca uma celula
    }
    liberaRot(temp->roteador);
    free(temp);
    temp=tempProx;  //avanca uma celula
  }
  free(lista);
}

Rot* iniciaRot(char* nome, char* operadora){
  Rot* roteador=(Rot*)malloc(sizeof(Rot));
  roteador->nome=(char*)malloc((strlen(nome)+1)*sizeof(char));
  roteador->operadora=(char*)malloc((strlen(operadora)+1)*sizeof(char));
  roteador->conectados=iniciaListaRot();
  roteador->flag=0;

  strcpy(roteador->nome, nome);
  strcpy(roteador->operadora, operadora);

  return roteador;
}

RotLista* iniciaListaRot(){
  RotLista* lista=(RotLista*)malloc(sizeof(RotLista));
  lista->prim=NULL;
  lista->ult=NULL;
  return lista;
}

void printRotLista(RotLista* lista, FILE * saida){
  CelulaR* temp;  //celula para percorrer a lista

  for(temp=lista->prim; temp!=NULL; temp=temp->prox){ //percorre a lista por completo
    RotLista* conectados=temp->roteador->conectados;  //recebe a lista de conexoes do roteador atual
    CelulaR* temp2=conectados->prim;  //recebe a primeira celula da lista de conexoes do roteador
    if(temp2==NULL){
      fprintf(saida, "%s;\n", temp->roteador->nome);  //imprime roteador sem a conexao
    }
    while(temp2!=NULL){
      fprintf(saida, "%s -- %s;\n", temp->roteador->nome, temp2->roteador->nome); //imprime roteador e a conexao
      temp2=temp2->prox;
    }
  }
}

void ligaRot(Rot* rot1, Rot* rot2){
  insereRot(rot1, rot2->conectados);  //insere um roteador na lista de conexoes do outro
  insereRot(rot2, rot1->conectados);
}

void desligaRot(Rot* rot1, Rot* rot2){
  retiraRot(rot1->nome, rot2->conectados);  //retira o roteador da lista de conectados do outro
  retiraRot(rot2->nome, rot1->conectados);
}

Rot* encontraRot(char* nome, RotLista* lista){
  CelulaR* temp;  //utilizado para percorrer a lista
  for(temp=lista->prim; temp!=NULL && strcmp(temp->roteador->nome,nome); temp=temp->prox);
  if(temp==NULL) return NULL; //percorre a lista ate encontrar, caso nao encontre, retorna NULL
  return temp->roteador;
}

void removeRot(Rot* rot, RotLista* lista){
  RotLista* conectados=rot->conectados; //recebe a lista de conexoes do roteador
  CelulaR* temp=conectados->prim; //recebe a primeira celula da lista de conexoes
  CelulaR* prox;  //proxima celula

  while (temp!=NULL){ //percorre a lista completa
    prox=temp->prox;
    desligaRot(rot, temp->roteador);  //desliga todas as conexoes com o roteador
    temp=prox;
  }
  retiraRot(rot->nome, lista);  //retira o roteador do netmap
  liberaRot(rot);
}

int Operadora(char* operadora, RotLista* lista){
  CelulaR* temp=lista->prim;  //percorre a lista
  int freq=0;
  while(temp!=NULL){  //percorre a lista completa
    if(!strcmp(temp->roteador->operadora, operadora)) freq++; //quando encontra a operadora, acrescenta 1
    temp=temp->prox;
  }
  return freq;  //retorna a frequencia
}

int checaConexao(Rot* rot1, Rot* rot2){////////////////////////////////////////////comenta ai
  if(rot1==rot2){ //se roteadores forem iguais
    return 0;
  }
  int retorno=1;
  rot1->flag=1; //altera flag da celula
  RotLista* lista=rot1->conectados; //recebe lista de conexoes do roteador
  CelulaR* temp=lista->prim;  //recebe a primeira celula das conexoes
  while(temp!=NULL){
    if(temp->roteador==rot2 || !retorno){//caso o roteadores forem iguais ou se ja existe foi encontrada a conexão
      return 0;
    }
    if(!temp->roteador->flag) retorno*=checaConexao(temp->roteador, rot2);//multiplica "retorno" pelo retorno da funcao (caso nao haja conexao, 1, caso contrario, 0)
    temp=temp->prox;
  }
  return retorno;
}

char* recuperaNomeRoteador(Rot* roteador){
  if(roteador==NULL){ //se o roteador for nulo, retorna nulo
    return NULL;
  }
  return roteador->nome;  //retorna o nome do roteador
}

void resetaFlag(RotLista* lista){
  CelulaR* temp;
  for(temp=lista->prim; temp!=NULL; temp=temp->prox)  //percorre a lista completa zerando as flags
    temp->roteador->flag=0;
}
