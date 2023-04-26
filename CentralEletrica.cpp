//
// Created by Rodrigo Alcaide on 23/12/2021.
//

#include "CentralEletrica.h"
#include "Zona.h"
#include "Ilha.h"

int CentralEletrica::aumentaNivel() {
    nivel++;
    return nivel;
}
int CentralEletrica::getNivel() {
    return nivel;
}



int CentralEletrica::getPreco() {
    int preco = 15;
    return preco;
}



void CentralEletrica::Produz(vector<Zona*> zonas, vector<Trabalhadores*> trabalhadores) {
    float quantMadeira;
    for (auto i: Ilha::getVetorRecursos()) {
        if (i->getNome() == "Madeira") {
            quantMadeira = i->getQuantidade();
            cout << nivel;
        }
    }
    if (quantMadeira >= 1)
        for (auto z: Ilha::getVetorRecursos()) {
            if (z->getNome() == "Eletricidade") {
                for (auto t: trabalhadores) {
                    if (t->getNome() == "oper") {
                        z->aumentaQuantidade(1);
                        for (auto j: Ilha::getVetorRecursos()) {
                            if (j->getNome() == "Madeira") {

                                j->retiraQuantidade(1);


                            } else if (j->getNome() == "Carvao") {
                                j->aumentaQuantidade(1);
                            }

                        }
                    }

                }
            }
        }
    }


Edificio* CentralEletrica::duplica() {
    return new CentralEletrica(*this);
}


