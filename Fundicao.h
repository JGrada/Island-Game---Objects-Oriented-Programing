
#ifndef TRABALHOPOO_FUNDICAO_H
#define TRABALHOPOO_FUNDICAO_H
#include "Edificio.h"
#include "Ferro.h"
#include "Carvao.h"

class Fundicao : public Edificio{
private:
    int nBarrasAco;
    int producao;
public:
    Fundicao(int nTrabalhadores, int nivel) : Edificio(nTrabalhadores, nivel), nBarrasAco(0) {}
    ~Fundicao() override {};
    int getProducao(){return producao;};
    string getNome() const override { return "fun";};
    int aumentaNivel() override;
    int getNivel() override;
    int getPreco() override;
    void Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) override;
    Edificio* duplica() override;

};


#endif //TRABALHOPOO_FUNDICAO_H
