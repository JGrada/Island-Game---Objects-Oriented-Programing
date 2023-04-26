
#ifndef TRABALHOPOO_MONTANHA_H
#define TRABALHOPOO_MONTANHA_H
#include "Zona.h"


class Montanha : public Zona{
public:
    Montanha() {}
    Montanha(Montanha &outro) = default;
    ~Montanha() override {};
    int EfeitoZona() override;
    int alteraPreco();
    string getNome() const override {return "mnt";};
    Zona* duplica() override;
};


#endif //TRABALHOPOO_MONTANHA_H
