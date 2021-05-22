#ifndef OUTRO_HPP
#define OUTRO_HPP
#include "Producao.hpp"

class Outro: public Producao{
private:
    string editora;
public:
    Outro(string, string, string, int, string);
    ~Outro();

    virtual string cabecalho();
    virtual bool operator < (Producao&);
    virtual string csv();
};

#endif