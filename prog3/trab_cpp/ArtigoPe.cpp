#include "ArtigoPe.hpp"

ArtigoPe::ArtigoPe(string natureza, string idioma, string cidade, int qtd_pags, string editora, int volume, int fasciculo, int serie, string issn): Producao("", natureza, idioma, cidade, qtd_pags, 25){
    this->editora = editora;
    this->volume = volume;
    this->fasciculo = fasciculo;
    this->serie = serie;
    this->issn = issn;
}

ArtigoPe::~ArtigoPe(){}

/* Metodo que retorna a string que contem as informacoes de uma producao em formato csv. No caso, reorna uma string no seguinte formato:
 "<Natureza>;<Idioma>;<Editora>;<Cidade>;<Volume>;<Fasciculo>;<Serie>;<ISSN>;<Paginas>"*/
string ArtigoPe::csv(){
    stringstream stream;
    stream << natureza << ";" << idioma << ";" << editora << ";" << cidade << ";" << _int_string(volume) << ";" << _int_string(fasciculo) << ";" << _int_string(serie) << ";" << issn << ";" << _int_string(qtd_pags);
    return stream.str();
}

/* Metodo que retorna a string cabecalho. */
string ArtigoPe::cabecalho(){
    return "Natureza;Idioma;Editora;Cidade;Volume;Fasciculo;Serie;ISSN;Paginas";
}

/* Operador de comparacao de uma producao com outra de mesmo subtipo. */
bool ArtigoPe::operator < (Producao& o){
    ArtigoPe& prod = (ArtigoPe&)o;
    int cmp = natureza.compare(prod.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = idioma.compare(prod.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = editora.compare(prod.editora);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = cidade.compare(prod.cidade);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = volume - prod.volume;
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = fasciculo - prod.fasciculo;
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = serie - prod.serie;
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = issn.compare(prod.issn);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = qtd_pags - prod.qtd_pags;
    if(cmp<0) return true; else return false;

    
}