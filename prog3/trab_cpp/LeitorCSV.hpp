#ifndef LEITOR_CSV
#define LEITOR_CSV
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Tokenizer.h"

using namespace std;
using namespace cpp_util;

class LeitorCSV{
private:
    ifstream* arquivo;
    vector<string> cabecalho;
    vector<string> atual;
    
public:
    LeitorCSV(ifstream*);
    LeitorCSV();
    ~LeitorCSV();
    string getColuna(int);
    string getColuna(string);
    bool acabou();
    void next();
    void setArquivo(ifstream*);
};


#endif