

#include "Bateria.h"
#include "Zona.h"
int Bateria::aumentaNivel() {
    nivel++;
    return nivel;
}

int Bateria::getNivel() {
    return nivel;
}


int Bateria::getPreco() {
    int preco = 10;
    return preco;
}

void Bateria::Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) {

}

Edificio* Bateria::duplica() {
    return new Bateria(*this);
}