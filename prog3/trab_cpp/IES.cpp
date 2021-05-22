#include "IES.hpp"


IES::IES(string nome, string sigla){
    this->nome = nome;
    this->sigla = sigla;
}

IES::~IES(){
}

/* Metodo que adiciona um novo programa aos programas vinculados a uma IES, checando se a PPG ja esta cadastrada na IES. */
void IES::addPrograma(PPG* ppg){
    string codigo = ppg->getCodigo();
    if(programas.find(codigo) == programas.end()) programas.insert({codigo, ppg});
}

string IES::getSigla(){
    return sigla;
}

string IES::getNome(){
    return nome;
}

//Sobrescrita do operador << para a IES. Imprime a sigla seguida do nome da IES, da seguinte forma:
//"<sigla> (<nome>)"
ostream& operator << (ostream& out, IES& ies){
    out << ies.getSigla() << " (" << ies.getNome() << ")";
    return out;
}

/* Sobrescrita do operador > para a IES. Compara primeiro a sigla da IES e em seguida seu nome. */
bool IES::operator > (IES& ies){
    return this->sigla + this->nome > ies.sigla + ies.nome;
}

/* Sobrescrita do operador < para a IES. Compara primeiro a sigla da IES e em seguida seu nome. */
bool IES::operator < (IES& ies){
    if(this->sigla != ies.sigla) return this->sigla < ies.sigla;
    else return this->nome < ies.nome;
}

//Funcao auxiliar para a ordenacao de PPGs.
bool _ordena_ppg_Nome(PPG* ppg1, PPG* ppg2){
    return stringCompare(ppg1->getNome(), ppg2->getNome());
}

/* Metodo para imprimir as informacoes das PPGs relacionadas a IES, em ordem alfabetica da seguinte forma:
   - <nome_ppg>: <qtd_producoes_ppg> producoes */
void IES::imprimeInfo(){
    vector<PPG*>temp;
    for(auto iter : programas) temp.push_back(iter.second);
    sort(temp.begin(), temp.end(), _ordena_ppg_Nome);

    for(auto iter : temp) cout << "\t- " << iter->getNome() << ": " << iter->getQtdProd() << " producoes" << endl;
}