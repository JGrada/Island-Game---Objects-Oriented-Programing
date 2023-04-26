//
// Created by Rodrigo Alcaide on 23/12/2021.
//

#ifndef TRABALHOPOO_BATERIA_H
#define TRABALHOPOO_BATERIA_H
#include "Edificio.h"
#include "Ilha.h"

class Bateria : public Edificio{
private:
    int capArmazenamento;
    int custoConstrucao;
    int nivelMaximo;
    int custoEvolucao;
    int producao;
public:
    Bateria(int nTrabalhadores, int nivel) :
            Edificio(nTrabalhadores, nivel),capArmazenamento(100), custoConstrucao(10), nivelMaximo(5), custoEvolucao(5){};
    ~Bateria() override {};
    string getNome() const override { return "bat";};
    int aumentaNivel() override;
    int getNivel() override;
    int getPreco() override;
    void Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) override;
    Edificio* duplica() override;

};


#endif //TRABALHOPOO_BATERIA_H
