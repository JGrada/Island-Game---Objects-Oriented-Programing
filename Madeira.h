
#ifndef TRABALHOPOO_MADEIRA_H
#define TRABALHOPOO_MADEIRA_H
#include "Recursos.h"

class Madeira : public Recursos{
public:
    Madeira(float precoUnidade) : Recursos(precoUnidade = 1){};
    ~Madeira() override {};
    string getNome() override { return "Madeira";};
    Recursos* duplica() override;
};


#endif //TRABALHOPOO_MADEIRA_H
