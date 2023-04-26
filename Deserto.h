
#ifndef TRABALHOPOO_DESERTO_H
#define TRABALHOPOO_DESERTO_H
#include "Zona.h"


class Deserto : public Zona{
public:
    Deserto() {}
    Deserto(Deserto &outro) = default;
    ~Deserto() override {};
    int condicoesMinas();
    int EfeitoZona() override;
    string getNome() const override {return "dsr";};
    Zona* duplica() override;
};


#endif //TRABALHOPOO_DESERTO_H
