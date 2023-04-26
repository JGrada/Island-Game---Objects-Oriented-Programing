
#include "MinaFerro.h"
#include "Zona.h"
#include "Ilha.h"
int MinaFerro::aumentaNivel() {
    nivel++;
    return nivel;
}

int MinaFerro::getPreco() {
    int preco = 10;
    return preco;
}

void MinaFerro::Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) {
    for(auto i : Ilha::getVetorRecursos())
    {
        if(i->getNome() == "Ferro") {
            for (auto t: trabalhadores) {
                if(t->getNome() == "miner") {
                    if (MinaFerro::nivel == 1) {
                        i->aumentaQuantidade(2);
                    } else if (MinaFerro::nivel == 2) {
                        i->aumentaQuantidade(3);
                    } else if (MinaFerro::nivel == 3) {
                        i->aumentaQuantidade(4);
                    } else if (MinaFerro::nivel == 4) {
                        i->aumentaQuantidade(5);
                    } else if (MinaFerro::nivel == 5) {
                        i->aumentaQuantidade(6);
                    }
                }
            }
        }
    }
}

int MinaFerro::getNivel() {
    return nivel;
}

Edificio* MinaFerro::duplica() {
    return new MinaFerro(*this);
}