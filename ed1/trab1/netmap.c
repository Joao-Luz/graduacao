#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netmap.h"
#include "roteador.h"
#include "terminal.h"

struct netmap{
  RotLista* listaRot; //lista com todos os roteadores
  TerLista* listaTer; //lista com todos os terminais
  int flag; //flag para impressao no .dot
};

NetMap* iniciaNetMap(){
  NetMap* netmap=(NetMap*)malloc(sizeof(NetMap));
  netmap->listaRot=iniciaListaRot();
  netmap->listaTer=iniciaListaTer();
  netmap->flag=0;
  return netmap;
}

void runNetMap(int argc, char** argv, NetMap* netmap){

  if(argc<=1){  //caso nao tenha enviado arquivo
    escreveLog(4,"erro");
    printf("Digite o diretório de um arquivo input\n");
    exit(0);
  }

  FILE * file=fopen(argv[1], "r");  //abre o arquivo do usuario para leitura

  if(!file){
    escreveLog(3, argv[1]);
    exit(1);
  }

  char command[20], temp1[20], temp2[20]; //strings auxiliares para a leitura do arquivo do usuario

  while (1){  //executa os comandos ate que o laco seja cobrado
    fscanf(file, "%s",command); //le comando
    //compara cada comando com uma string, para saber em qual funcao entrar
    if(!strcmp(command, "CADASTRAROTEADOR")){
      fscanf(file, "%s%s",temp1,temp2);
      cadastraRoteador(temp1, temp2, netmap);
    }

    else if(!strcmp(command, "CADASTRATERMINAL")){
      fscanf(file, "%s%s",temp1,temp2);
      cadastraTerminal(temp1, temp2, netmap);
    }

    else if(!strcmp(command, "REMOVEROTEADOR")){
      fscanf(file, "%s",temp1);
      removeRoteador(temp1, netmap);
    }

    else if(!strcmp(command, "REMOVETERMINAL")){
      fscanf(file, "%s",temp1);
      removeTerminal(temp1, netmap);
    }

    else if(!strcmp(command, "CONECTAROTEADORES")){
      fscanf(file, "%s%s",temp1,temp2);
      conectaRoteadores(temp1, temp2, netmap);
    }

    else if(!strcmp(command, "CONECTATERMINAL")){
      fscanf(file, "%s%s",temp1,temp2);
      conectaTerminal(temp1, temp2, netmap);
    }

    else if(!strcmp(command, "DESCONECTAROTEADORES")){
      fscanf(file, "%s%s",temp1,temp2);
      desconectaRoteadores(temp1, temp2, netmap);
    }

    else if(!strcmp(command, "DESCONECTATERMINAL")){
      fscanf(file, "%s",temp1);
      desconectaTerminal(temp1, netmap);
    }

    else if(!strcmp(command, "FREQUENCIAOPERADORA")){
      fscanf(file, "%s",temp1);
      frequenciaOperadora(temp1, netmap);
    }

    else if(!strcmp(command, "FREQUENCIATERMINAL")){
      fscanf(file, "%s",temp1);
      frequenciaTerminal(temp1, netmap);
    }

    else if(!strcmp(command, "ENVIARPACOTESDADOS")){
      fscanf(file, "%s%s",temp1,temp2);
      enviaDados(temp1, temp2, netmap);
    }

    else if(!strcmp(command, "IMPRIMENETMAP")){
      imprimeNetMap(netmap);
    }

    else if(!strcmp(command, "FIM")){
      break;
    }

    else{
      printf("Comando \"%s\" Nao Existe! Fechando o programa para evitar resultados errados!\n\n", command);
      fclose(file);                   //o programa eh abortado em caso de comando invalido
      liberaNetMap(netmap);
      exit(0);
    }
  }

  printf("Fim\n");
  fclose(file);
}

void cadastraRoteador(char* nome, char* operadora, NetMap* netmap){
  printf("Cadastrando roteador \"%s\"... ", nome);
  Rot* roteador=iniciaRot(nome, operadora); //inicia roteador para envia-lo ja alocado para a lista
  insereRot(roteador, netmap->listaRot);  //insere na lista do netmap
  printf("OK!\n\n");
}

void cadastraTerminal(char* nome, char* local, NetMap* netmap){
  printf("Cadastrando terminal \"%s\"... ", nome);
  Ter* terminal=iniciaTer(nome, local); //inicia terminal
  insereTer(terminal, netmap->listaTer); //o envia para a lista do netmap
  printf("OK!\n\n");
}

void removeRoteador(char* nome, NetMap* netmap){
  printf("Removendo roteador \"%s\"... ", nome);
  Rot* roteador=encontraRot(nome, netmap->listaRot);  //encontra roteador a ser removido
  if(!roteador){  //caso nao esteja no netmap
    printf("Nao foi possivel remover roteador \"%s\".\n", nome);
    escreveLog(1, nome);
    return;
  }

  separaTer(nome, netmap->listaTer);  //tira a conexao com o terminal
  removeRot(roteador, netmap->listaRot);  //remove o roteador da lista
  printf("OK!\n\n");
}

void removeTerminal(char* nome, NetMap* netmap){
  printf("Removendo terminal \"%s\"... ", nome);
  Ter* terminal=encontraTer(nome, netmap->listaTer);  //encontra o terminal a ser removido
  if(!terminal){  //caso nao esteja no netmap
    printf("Nao foi possivel remover \"%s\".\n\n", nome);
    escreveLog(2, nome);
    return;
  }
  retiraTer(nome, netmap->listaTer);  //retira o terminal da lista
  printf("OK!\n\n");
}

void conectaRoteadores(char* rot1, char* rot2, NetMap* netmap){
  printf("Conectando roteadores \"%s\" e \"%s\"... ", rot1, rot2);
  Rot* roteador1=encontraRot(rot1, netmap->listaRot); //encontra o primeiro roteador
  if(!roteador1){
    printf("Nao foi possivel cenectar roteador \"%s\".\n", rot1);
    escreveLog(1, rot1);
    return;
  }
  Rot* roteador2=encontraRot(rot2, netmap->listaRot); //encontra o segundo roteador
  if(!roteador2){
    printf("Nao foi possivel conectar roteador \"%s\".\n", rot2);
    escreveLog(1, rot2);
    return;
  } //caso um dos dois nao esteja no netmap, a funcao retorna
  ligaRot(roteador1, roteador2);  //conecta os dois roteadores
  printf("OK!\n\n");
}

void conectaTerminal(char* ter, char* rot, NetMap* netmap){
  printf("Conectando terminal \"%s\" ao roteador \"%s\"... ", ter, rot);
  Rot* roteador=encontraRot(rot, netmap->listaRot); //encontra o terminal a ser conectado
  Ter* terminal=encontraTer(ter, netmap->listaTer); //encontra o roteador a ser conectado
  if(!terminal){
    printf("Nao foi possivel conectar terminal \"%s\".\n", ter);
    escreveLog(2, ter);
    return;
  }
  if(!roteador){
    printf("Nao foi possivel conectar roteador \"%s\".\n", rot);
    escreveLog(1, rot);
    return;
  } //caso um dos dois nao seja encontrado, a funcao retorna
  ligaTer(terminal, roteador);  //conecta o terminal ao roteador
  printf("OK!\n\n");
}

void desconectaRoteadores(char* rot1, char* rot2, NetMap* netmap){
  printf("Desconectando roteadores \"%s\" e \"%s\"... ", rot1, rot2);
  Rot* roteador1=encontraRot(rot1, netmap->listaRot); //procura o primeiro roteador
  if(!roteador1){
    printf("Nao foi possivel desconectar roteador \"%s\".\n\n", rot1);
    escreveLog(1, rot1);
    return;
  }
  Rot* roteador2=encontraRot(rot2, netmap->listaRot); //procura o segundo roteador
  if(!roteador2){
    printf("Nao foi possivel desconectar roteador \"%s\".\n\n", rot2);
    escreveLog(1, rot2);
    return;
  } //caso nao encontre um dos dois, a funcao retorna
  desligaRot(roteador1, roteador2);
  printf("OK!\n\n");
}

void desconectaTerminal(char* terminal, NetMap* netmap){
  printf("Desconectando terminal \"%s\"... ", terminal);
  Ter* ter=encontraTer(terminal, netmap->listaTer); //procura o terminal
  if(!ter){
    printf("Nao foi possivel desconectar terminal \"%s\".\n\n", terminal);
    escreveLog(2, terminal);
    return;
  } //caso nao o encontre, a funcao retorna
  desligaTer(ter);  //desconecta o terminal de seu roteador
  printf("OK!\n\n");
}

void frequenciaOperadora(char* operadora, NetMap* netmap){
  printf("Gerando frequencia da operadora \"%s\"... ", operadora);
  int freq=Operadora(operadora, netmap->listaRot);  //recebe a frequencia da operadora

  FILE * saida=fopen("./saida.txt", "a+");  //abre o arquivo saida.txt

  fprintf(saida, "FREQUENCIAOPERADORA %s: %d\n", operadora, freq);  //imprime a frequencia no arquivo
  fclose(saida);  //fecha o arquivo
  printf("OK!\n\n");
}

void frequenciaTerminal(char* local, NetMap* netmap){
  printf("Gerando frequencia do local \"%s\"... ", local);
  int freq=Terminal(local, netmap->listaTer); //recebe a frequencia da localizacao dos terminais

  FILE * saida=fopen("./saida.txt", "a+");  //abre o arquivo saida.txt

  fprintf(saida, "FREQUENCIATERMINAL %s: %d\n", local, freq); //imprime a frequencia no arquivo

  fclose(saida);  //fecha o arquivo
  printf("OK!\n\n");
}

void enviaDados(char* ter1, char* ter2, NetMap* netmap){
  printf("Enviando dados de \"%s\" para \"%s\"... ", ter1, ter2);
  Ter* terminal1=encontraTer(ter1, netmap->listaTer); //procura o primeiro terminal
  if(!terminal1){
    printf("Nao foi possivel enviar dados de \"%s\" para \"%s\".\n", ter1, ter2);
    escreveLog(2, ter1);
    return;
  }
  Ter* terminal2=encontraTer(ter2, netmap->listaTer); //procura o segundo terminal
  if(!terminal2){
    printf("Nao foi possivel enviar dados de \"%s\" para \"%s\".\n", ter1, ter2);
    escreveLog(2, ter2);
    return;
  } //caso um dos dois nao seja encontrado, a funcao retorna
  FILE * saida=fopen("./saida.txt", "a+");  //abre o saida.txt
  //checa a conexao entre os terminais e imprime no arquivo conforme o modelo
  if(!checaConexaoTer(terminal1, terminal2)) fprintf(saida, "ENVIARPACOTESDADOS %s %s: SIM\n",ter1, ter2);
  else fprintf(saida, "ENVIARPACOTESDADOS %s %s: NAO\n",ter1, ter2);

  resetaFlag(netmap->listaRot); //reseta as flags dos roteadores

  fclose(saida);
  printf("OK!\n\n");
}

void imprimeNetMap(NetMap* netmap){
  printf("Imprimindo NetMap... ");
  FILE * saida=fopen("./saida.dot", "a+");  //abre o arquivo saida.dot

  if(netmap->flag)fprintf(saida, "//intermediario\n\n");  //caso a flag do netmap seja maior que 0, imprime quebras de linhas entre os netmaps
  fprintf(saida, "strict graph {\n");                     //imprime o netmap conforme o graphviz
  printTerLista(netmap->listaTer, saida);
  printRotLista(netmap->listaRot, saida);
  fprintf(saida, "}\n");

  fclose(saida);    //fecha o arquivo
  netmap->flag=1;   //altera a flag do netmap para 1
  printf("OK!\n\n");
}

void escreveLog(int erro, char* nome){
  FILE * logfile=fopen("./log.txt", "a+");  //abre o arquivo log.txt para impressao de erros

  if(erro==1)  fprintf(logfile,"Erro: Terminal %s inexistente no NetMap\n", nome);  //caso nao encontre o terminal
  if(erro==2)  fprintf(logfile,"Erro: Roteador %s inexistente no NetMap\n", nome);  //caso nao encontre o roteador
  if(erro==3)  fprintf(logfile,"Erro: I/O, nao foi possivel abrir o arquivo \"%s\"\n", nome); //caso nao consiga abrir o arquivo do usuario
  if(erro==4)  fprintf(logfile,"Erro: I/O, indique arquivo de input\n");  //caso o usuario nao forneca um arquivo

  fclose(logfile);
}

void liberaNetMap(NetMap* netmap){
  liberaListaRot(netmap->listaRot);
  liberaListaTer(netmap->listaTer);
  free(netmap);
}
