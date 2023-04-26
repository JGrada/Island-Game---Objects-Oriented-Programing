//
// Created by Rodrigo Alcaide on 18/11/2021.
//

#ifndef TP_ILHA_H
#define TP_ILHA_H


#include <sstream>
#include <string>
#include <vector>
#include "Zona.h"
using namespace std;

class Ilha {
private:
    static const int MinLinhas;
    static const int MinColunas;
    static const int MaxLinhas;
    static const int MaxColunas;
    static vector<Recursos *> recursos;
    vector<Recursos *> recursosSave;

    int linhas;
    int colunas;
    static int dia;
    int diaSave;

public:
    Ilha(int nlinhas, int ncolunas);
    virtual ~Ilha();
    static int getDia();
    int getDiaSave();
    int incrementaDia();
    int getLinhas ();
    int getColunas();
    void Amanhecer();
    void Anoitecer();
    Ilha &operator = (const Ilha &outro);
    Ilha(Ilha &outro);
    vector<vector<Zona*>> zonas;
    const static vector<string> tiposZonas;
    vector<string> getZonas(int linhas, int colunas);
    static vector<Recursos *> getVetorRecursos();
    vector<Recursos *> getVetorRecursosSave();
    void DesenharIlha();
    vector<Zona*> getZonasAdjacentes(Zona* zonaAtual);
    static void vendeRecursos(float quantia, string tipoRecurso);
    void MostraRecursos();
};



#endif //TRABALHOPOO_ILHA_H
