//
// Created by Rodrigo Alcaide on 23/12/2021.
//

#ifndef TRABALHOPOO_EOLICO_H
#define TRABALHOPOO_EOLICO_H
#include "Zona.h"


class Eolico : public Zona{
private:
    int nrAerogeradores;
public:
    Eolico() : nrAerogeradores(getRandomAerogeradores()){}
    Eolico(Eolico &outro) = default;
    ~Eolico() override {};
    static int getRandomAerogeradores();
    int EfeitoZona() override;
    string getNome() const override {return "pqE";};
    Zona* duplica() override;
};


#endif //TRABALHOPOO_EOLICO_H
