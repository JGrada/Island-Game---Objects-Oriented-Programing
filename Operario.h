#ifndef TRABALHOPOO_OPERARIO_H
#define TRABALHOPOO_OPERARIO_H
#include "Trabalhadores.h"

class Operario : public Trabalhadores{

public:
    Operario(int dia_inicio, string zona) :
            Trabalhadores(15, dia_inicio, zona, 5) {}
    ~Operario() override {};
    string getNome() const override {return "oper";};
    string getLetra() const override {return "O";};
    Trabalhadores* duplica() override;
    int getProb() override;


};


#endif //TRABALHOPOO_OPERARIO_H
