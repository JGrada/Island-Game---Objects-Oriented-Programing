//
// Created by Rodrigo Alcaide on 23/12/2021.
//

#include "MinaCarvao.h"
#include "Zona.h"
#include "Ilha.h"

int MinaCarvao::aumentaNivel() {
    nivel++;
    return nivel;
}

int MinaCarvao::getNivel() {
    return nivel;
}



int MinaCarvao::getPreco() {
    int preco = 10;
    return preco;
}

void MinaCarvao::Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) {

        for(auto i : Ilha::getVetorRecursos())
        {
            if(i->getNome() == "Carvao") {
                for (auto t: trabalhadores) {
                    if(t->getNome() == "miner") {
                        if (MinaCarvao::nivel == 1) {
                            i->aumentaQuantidade(2);
                        } else if (MinaCarvao::nivel == 2) {
                            i->aumentaQuantidade(3);
                        } else if (MinaCarvao::nivel == 3) {
                            i->aumentaQuantidade(4);
                        } else if (MinaCarvao::nivel == 4) {
                            i->aumentaQuantidade(5);
                        } else if (MinaCarvao::nivel == 5) {
                            i->aumentaQuantidade(6);
                        }
                    }
                }
            }
            else if(i->getNome() == "Madeira") {
                for (auto t: trabalhadores) {
                    if (t->getNome() == "miner")
                        i->aumentaQuantidade(2);
                }
            }

        }
}

Edificio* MinaCarvao::duplica() {
    return new MinaCarvao(*this);
}



