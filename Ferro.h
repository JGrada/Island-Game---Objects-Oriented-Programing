
#ifndef TRABALHOPOO_FERRO_H
#define TRABALHOPOO_FERRO_H
#include "Recursos.h"

class Ferro : public Recursos{

public:
    Ferro(float precoUnidade) : Recursos(precoUnidade = 1){};
    ~Ferro() override {};
    string getNome() override { return "Ferro";};
    Recursos* duplica() override;

};


#endif //TRABALHOPOO_FERRO_H
