
#include "EdificioX.h"
#include "Zona.h"
#include "Ilha.h"

int EdificioX::aumentaNivel() {
    nivel++;
    return nivel;
}

int EdificioX::getNivel() {
    return nivel;
}

void EdificioX::Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) {
    float quantMadeira;
    for (auto i: Ilha::getVetorRecursos()) {
        if (i->getNome() == "Madeira") {
            quantMadeira = i->getQuantidade();
        }

    }


    if (quantMadeira >= 2) {
        for (auto k: Ilha::getVetorRecursos()) {
            if (k->getNome() == "Vigas de Madeira") {
                for (auto t: trabalhadores) {
                    if (t->getNome() == "len") {
                        k->aumentaQuantidade(1);
                        for (auto j: Ilha::getVetorRecursos()) {
                            if (j->getNome() == "Madeira") {
                                j->retiraQuantidade(2);
                            }
                        }
                    }


                }
            }
        }
    }
}


int EdificioX::getPreco() {
    int preco = 10;
    return preco;
}

Edificio* EdificioX::duplica() {
    return new EdificioX(*this);
}
