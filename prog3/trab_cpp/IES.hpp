#ifndef IES_HPP
#define IES_HPP
#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include "PPG.hpp"
#include <iostream>
#include "StringUtils.h"

using namespace std;
using namespace cpp_util;

class PPG;

class IES{
private:    
    string nome;
    string sigla;
    unordered_map<string, PPG*> programas;

public:
    IES(string, string);
    ~IES();
    void addPrograma(PPG* ppg);
    friend ostream& operator << (ostream&, IES&);
    bool operator > (IES&);
    bool operator < (IES&);
    void imprimeInfo();

    string getSigla();
    string getNome();
};



#endif