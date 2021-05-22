#include "ArtigoJr.hpp"

ArtigoJr::ArtigoJr(string titulo, string idioma, string cidade, int qtd_pags, string data, string issn): Producao(titulo, "", idioma, cidade, qtd_pags, 9){
    this->data = parseDate(data, DATE_FORMAT_PT_BR_SHORT);
    this->issn = issn;
}

ArtigoJr::~ArtigoJr(){}

/* Metodo que retorna a string que contem as informacoes de uma producao em formato csv. No caso, reorna uma string no seguinte formato:
 "<Titulo>;<Idioma>;<Cidade>;<Data>;<ISSN>;<Paginas>"*/
string ArtigoJr::csv(){
    stringstream stream;
    stream << titulo << ";" << idioma << ";" << cidade << ";" << formatDate(data, DATE_FORMAT_PT_BR_SHORT) << ";" << issn << ";" << _int_string(qtd_pags);
    return stream.str();
}

/* Metodo que retorna a string cabecalho. */
string ArtigoJr::cabecalho(){
    return "Titulo;Idioma;Cidade;Data;ISSN;Paginas";
}

/* Operador de comparacao de uma producao com outra de mesmo subtipo. */
bool ArtigoJr::operator < (Producao& o){
    ArtigoJr& prod = (ArtigoJr&)o;
    int cmp = titulo.compare(prod.titulo);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = idioma.compare(prod.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = cidade.compare(prod.cidade);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = difftime(data, prod.data);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = issn.compare(prod.issn);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = qtd_pags - prod.qtd_pags;
    if(cmp<0) return true; else return false;
}