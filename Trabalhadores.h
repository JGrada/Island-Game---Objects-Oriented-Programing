
#ifndef TP_TRABALHADORES_H
#define TP_TRABALHADORES_H

#include <string>
#include <iostream>
using namespace std;

class Trabalhadores {
    int valor_contratacao;
    int dia_inicio;
    string zona;
    int probDemissao;
    static int idStatic;
    int id;


public:
    Trabalhadores(int valor_contratacao, int dia_inicio, string zona, int probDemissao)
        : valor_contratacao(valor_contratacao), dia_inicio(dia_inicio),
            zona(zona), probDemissao(probDemissao), id(idStatic++) {}
    virtual ~Trabalhadores() {};
    virtual string getNome() const = 0;
    virtual string getLetra() const = 0;
    int getValor() const {return valor_contratacao;};
    int getId()  {return id;};
    string getZona() { return zona;};
    virtual int getProb(){};
    virtual Trabalhadores* duplica() = 0;
};

#endif //TP_TRABALHADORES_H
