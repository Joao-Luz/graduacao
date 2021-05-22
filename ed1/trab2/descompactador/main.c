#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descompactador.h"

int main(int argc, char* argv[]){
  if(argc<=1){
    printf("Digite o nome de um arquivo a ser descompactado!\n");
    exit(0);
  }

  char* tipo;
  tipo=strrchr(argv[1], '.');
   if(strcmp(tipo, ".comp")){
     printf("Arquivo requisitado deve ter terminacao \".comp\"\n");
     exit(0);
   }

  FILE* entrada=fopen(argv[1], "rb");

  if(entrada==NULL){
    printf("Arquivo \"%s\" nao existe!\n", argv[1]);
  }

  Descomp* dc=criaDescomp(entrada);
  descompacta(dc);
  printf("OK!\n");
  liberaDescomp(dc);
  fclose(entrada);
}
