#ifndef ANAL_HPP
#define ANAL_HPP
#include "Producao.hpp"

class Anal: public Producao{
private:
    string evento;
    friend class comparadorAnal;
public:
    Anal(string, string, string, string, int, string);
    Anal() = default;
    ~Anal();

    virtual bool operator < (Producao&);
    virtual string csv();
    virtual string cabecalho();
};


#endif