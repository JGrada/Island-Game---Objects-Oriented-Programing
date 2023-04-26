
#ifndef TRABALHOPOO_MINAFERRO_H
#define TRABALHOPOO_MINAFERRO_H
#include "Edificio.h"

class MinaFerro : public Edificio{
private:
    int probDesabamento;
    int capArmazenamento;
    int custoEvolucao;
    int producao;
public:
    MinaFerro(int nTrabalhadores, int nivel) : Edificio(nTrabalhadores, nivel), probDesabamento(15), capArmazenamento(100),custoEvolucao(5) {}
    ~MinaFerro() override {};
    int aumentaNivel() override;
    int getNivel() override;
    int getPreco() override;
    void Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) override;
    string getNome() const override { return "mnF";};
    Edificio* duplica() override;

};


#endif //TRABALHOPOO_MINAFERRO_H
