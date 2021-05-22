#ifndef TRADUCAO_HPP
#define TRADUCAO_HPP
#include "Producao.hpp"

class Traducao: public Producao{
private:
    string editora;
    string idioma_traducao;
public:
    Traducao(string, string, string, string, int, string, string);
    ~Traducao();

    virtual string cabecalho();
    virtual bool operator < (Producao&);
    virtual string csv();
};

#endif