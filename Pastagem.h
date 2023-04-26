//
// Created by Rodrigo Alcaide on 23/12/2021.
//

#ifndef TRABALHOPOO_PASTAGEM_H
#define TRABALHOPOO_PASTAGEM_H
#include "Zona.h"


class Pastagem : public Zona{
public:
    Pastagem() {}
    Pastagem(Pastagem &outro) = default;
    int EfeitoZona() override;
    int getProbabilidadeDemissao();
    string getNome() const override {return "pas";};
    Zona* duplica() override;
};


#endif //TRABALHOPOO_PASTAGEM_H
