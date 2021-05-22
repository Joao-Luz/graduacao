#ifndef PARTITURA_HPP
#define PARTITURA_HPP
#include "Producao.hpp"

class Partitura: public Producao{
private:
    string editora;
    string formacao;
public:
    Partitura(string, string, int, string, string);
    ~Partitura();

    virtual string cabecalho();
    virtual bool operator < (Producao&);
    virtual string csv();
};

#endif