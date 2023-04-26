
#ifndef TP_INTERFACE_H
#define TP_INTERFACE_H

#include <vector>
#include "Comandos.h"
#include "Zona.h"
#include "Ilha.h"
#include <map>

class Interface {
private:
    string comando;
    Ilha *il;
    map<string,Ilha*> &m;

public:
    Interface(Ilha *il, map<string,Ilha*> &m);
    void validaComandos(string linha);
    const static vector<string> tiposTrabalhadores;
    static vector<string> getTrabalhadoresValidos();
    const static vector<string> tiposEdificios;
    const static vector<string> tiposEdificiosLevelUp;
    const static vector<string> tiposRecursos;

    static vector<string> getEdificiosValidos();
    string LeFicheiro();


};

#endif //TRABALHOPOO_INTERFACE_H
