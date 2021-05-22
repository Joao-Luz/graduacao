#include "Outro.hpp"

Outro::Outro(string natureza, string idioma, string cidade, int qtd_pags, string editora): Producao("", natureza, idioma, cidade, qtd_pags, 10){
    this->editora = editora;
}

Outro::~Outro(){}

/* Metodo que retorna a string que contem as informacoes de uma producao em formato csv. No caso, reorna uma string no seguinte formato:
 "<Natureza>;<Idioma>;<Editora>;<Cidade>;<Paginas>"*/
string Outro::csv(){
    stringstream stream;
    stream << natureza << ";" << idioma << ";" << editora << ";" << cidade << ";" << _int_string(qtd_pags);
    return stream.str();
}

/* Metodo que retorna a string cabecalho. */
string Outro::cabecalho(){
    return "Natureza;Idioma;Editora;Cidade;Paginas";
}

/* Operador de comparacao de uma producao com outra de mesmo subtipo. */
bool Outro::operator < (Producao& o){
    Outro& prod = (Outro&)o;
    int cmp = natureza.compare(prod.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = idioma.compare(prod.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = editora.compare(prod.editora);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = cidade.compare(prod.cidade);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = qtd_pags - prod.qtd_pags;
    if(cmp<0) return true; else return false;
}