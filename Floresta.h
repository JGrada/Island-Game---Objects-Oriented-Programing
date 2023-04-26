
#ifndef TRABALHOPOO_FLORESTA_H
#define TRABALHOPOO_FLORESTA_H
#include "Zona.h"


class Floresta : public Zona{
private:
    int nrArvores;
public:
    Floresta() : nrArvores(getRandomArvores()){}
    Floresta(Floresta &outro) = default;
    ~Floresta() override {};
    static int getRandomArvores();
    int getArvores();
    int ProduzMadeira();
    int EfeitoZona() override;
    string getNome() const override {return "flr";};
    Zona* duplica() override;
};


#endif //TRABALHOPOO_FLORESTA_H
