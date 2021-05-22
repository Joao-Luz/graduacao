#include "Partitura.hpp"

Partitura::Partitura(string natureza, string cidade, int qtd_pags, string editora, string formacao): Producao("", natureza, "", cidade, qtd_pags, 28){
    this->editora = editora;
    this->formacao = formacao;
}

Partitura::~Partitura(){}

/* Metodo que retorna a string que contem as informacoes de uma producao em formato csv. No caso, reorna uma string no seguinte formato:
 "<Natureza>;<Editora>;<Cidade>;<Formacao>;<Paginas>"*/
string Partitura::csv(){
    stringstream stream;
    stream << natureza << ";" << editora << ";" << cidade << ";" << formacao << ";" << _int_string(qtd_pags);
    return stream.str();
}

/* Metodo que retorna a string cabecalho. */
string Partitura::cabecalho(){
    return "Natureza;Editora;Cidade;Formacao;Paginas";
}

/* Operador de comparacao de uma producao com outra de mesmo subtipo. */
bool Partitura::operator < (Producao& o){
    Partitura& prod = (Partitura&)o;
    int cmp = natureza.compare(prod.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = editora.compare(prod.editora);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = cidade.compare(prod.cidade);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = formacao.compare(prod.formacao);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = qtd_pags - prod.qtd_pags;
    if(cmp<0) return true; else return false;
}