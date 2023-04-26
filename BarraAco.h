
#ifndef TRABALHOPOO_BARRAACO_H
#define TRABALHOPOO_BARRAACO_H
#include "Recursos.h"

class BarraAco : public Recursos{
public:
    BarraAco(float precoUnidade) : Recursos(precoUnidade = 2){};
    ~BarraAco() override{};
    string getNome() override { return "Barra de Aco";};
    Recursos* duplica() override;
};


#endif //TRABALHOPOO_BARRAACO_H
