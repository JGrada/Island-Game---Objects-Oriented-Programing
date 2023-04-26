
#ifndef TRABALHOPOO_LENHADOR_H
#define TRABALHOPOO_LENHADOR_H
#include "Trabalhadores.h"

class Lenhador : public Trabalhadores{

public:
    Lenhador(int dia_inicio, string zona) :
            Trabalhadores(20,dia_inicio,zona, 0) {}
    ~Lenhador() override {};
    string getNome() const override {return "len";};
    string getLetra() const override {return "L";};
    Trabalhadores* duplica() override;
    int getProb() override;



};


#endif //TRABALHOPOO_LENHADOR_H
