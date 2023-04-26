
#ifndef TRABALHOPOO_CARVAO_H
#define TRABALHOPOO_CARVAO_H
#include "Recursos.h"

class Carvao : public Recursos{

public:
    Carvao(float precoUnidade) : Recursos(precoUnidade = 1){};
    ~Carvao() override {};
    string getNome() override { return "Carvao";};
    Recursos* duplica() override;

};


#endif //TRABALHOPOO_CARVAO_H
