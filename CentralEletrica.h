//
// Created by Rodrigo Alcaide on 23/12/2021.
//

#ifndef TRABALHOPOO_CENTRALELETRICA_H
#define TRABALHOPOO_CENTRALELETRICA_H
#include "Edificio.h"

class CentralEletrica : public Edificio{
    int capArmazenamento;
    int custoConstrucao;
    int producao;
public:
    CentralEletrica(int nTrabalhadores, int nivel)
        :Edificio(nTrabalhadores, nivel), capArmazenamento(100), custoConstrucao(15) {}
    ~CentralEletrica() override {};
    string getNome() const override { return "elec";};
    int aumentaNivel() override;
    int getNivel() override;
    int getPreco() override;
    void Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) override;
    Edificio* duplica() override;
};


#endif //TRABALHOPOO_CENTRALELETRICA_H
