
#ifndef TRABALHOPOO_PANTANO_H
#define TRABALHOPOO_PANTANO_H
#include "Zona.h"


class Pantano : public Zona{
public:
    Pantano() {}
    Pantano(Pantano &outro) = default;
    ~Pantano() override {};
    void diaDemissao();
    int EfeitoZona() override;
    string getNome() const override {return "pnt";};
    Zona* duplica() override;
};


#endif //TRABALHOPOO_PANTANO_H
