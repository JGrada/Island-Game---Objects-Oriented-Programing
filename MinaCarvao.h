
#ifndef TRABALHOPOO_MINACARVAO_H
#define TRABALHOPOO_MINACARVAO_H
#include "Edificio.h"

class MinaCarvao : public Edificio{
private:
    int probDesabamento;
    int capArmazenamento;
    int custoEvolucao;
    int producao;

public:
    MinaCarvao(int nTrabalhadores, int nivel) : Edificio(nTrabalhadores, nivel),probDesabamento(10), capArmazenamento(100),custoEvolucao(10) {}
    ~MinaCarvao() override {};
    int aumentaNivel() override;
    int getNivel() override;
    int getPreco() override;
    void Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) override;
    string getNome() const override { return "mnC";};
    Edificio* duplica() override;

};


#endif //TRABALHOPOO_MINACARVAO_H
