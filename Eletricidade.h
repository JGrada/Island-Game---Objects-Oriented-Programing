
#ifndef TRABALHOPOO_ELETRICIDADE_H
#define TRABALHOPOO_ELETRICIDADE_H
#include "Recursos.h"

class Eletricidade : public Recursos{
public:
    Eletricidade(float precoUnidade) : Recursos(1.5){};
    string getNome() override { return "Eletricidade";};
    ~Eletricidade() override {};
    Recursos* duplica() override;

};


#endif //TRABALHOPOO_ELETRICIDADE_H
