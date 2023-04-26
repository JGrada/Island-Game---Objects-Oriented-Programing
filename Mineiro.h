
#ifndef TRABALHOPOO_MINEIRO_H
#define TRABALHOPOO_MINEIRO_H
#include <iostream>
#include "Trabalhadores.h"

class Mineiro : public Trabalhadores{

public:
    Mineiro(int dia_inicio, string zona) :
           Trabalhadores( 10, dia_inicio,zona, 10){}
    ~Mineiro() override {};
    string getNome() const override {return "miner";};
    string getLetra() const override {return "M";};
    Trabalhadores* duplica() override;
    int getProb() override;

};


#endif //TRABALHOPOO_MINEIRO_H
