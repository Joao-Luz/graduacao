#include "LeitorCSV.hpp"
#include <iostream>

/* Construtor da classe LeitorCSV. Inicia lendo a primeira linha do arquivo csv passado como parametro.
Atribui o cabecalho do aquivo ao cabecalho do objeto e le a primeira linha de informacoes do aquivo. */
LeitorCSV::LeitorCSV(ifstream* arquivo){
    this->arquivo = arquivo;
    string linha;
    Tokenizer toke(linha, ';');
    getline(*arquivo, linha);
    this->cabecalho = toke.remaining();
    getline(*arquivo, linha);
    Tokenizer toke2(linha, ';');
    this->atual = toke2.remaining();
}

LeitorCSV::~LeitorCSV(){
    if(arquivo != nullptr) delete arquivo;
}

/* Metodo que retorna a string da coluna 'index' da linha atual do leitor.
Caso a coluna nao exista, lanca "Coluna nao existente." */
string LeitorCSV::getColuna(int index){
    if(index < atual.size()) return atual[index];
    throw "Coluna nao existente";
}

/* Metodo que retorna a string da coluna "coluna" da linha atual do leitor.
Caso a coluna nao exista, lanca "Coluna nao existente." */
string LeitorCSV::getColuna(string coluna){
    int index = 0;
    for(auto iter : cabecalho){
        if(coluna == iter) return atual[index];
        index ++;
    }
    throw "Coluna nao existente";
}

/* Metodo que retorna se o leitor ja chegou ao final do arquivo de leitura. */
bool LeitorCSV::acabou(){
    return arquivo->eof();
}

/* Metodo que avanca a leitura do leitor para a proxima linha do aquivo csv. */
void LeitorCSV::next(){
    string linha;
    getline(*arquivo, linha);
    Tokenizer toke(linha, ';');
    atual.clear();
    atual = toke.remaining();
}