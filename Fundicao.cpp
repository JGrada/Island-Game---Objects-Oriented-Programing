
#include "Zona.h"
#include "Fundicao.h"
#include "Ilha.h"

int Fundicao::aumentaNivel() {
    nivel++;
}

int Fundicao::getNivel() {
    return nivel;
}


int Fundicao::getPreco() {
    int preco = 10;
    return preco;
}

void Fundicao::Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) {
    Edificio *mnf = nullptr;
    Edificio *elec = nullptr;

    float quantFerro, quantCarvao;
    for (auto i: Ilha::getVetorRecursos()) {
        if (i->getNome() == "Ferro") {
            quantFerro = i->getQuantidade();
        } else if (i->getNome() == "Carvao") {
            quantCarvao = i->getQuantidade();
        }
    }


    if (quantFerro >= 1.5 and quantCarvao >= 0.5) {

        for (auto z: zonas) {
            if(z->getEdificio() == nullptr)
                continue;
            if (z->getEdificio()->getNome() == "mnF") {
                mnf = z->getEdificio();
            }
            else if(z->getEdificio()->getNome() == "elec" or z->getEdificio()->getNome() == "mnC"  )
            {
                elec = z->getEdificio();
            }
        }

        if(mnf == nullptr or elec == nullptr)
            return;

        auto it = trabalhadores.begin();

        while (it != trabalhadores.end()) {
            if ((*it)->getNome() == "oper") {
                break;
            }
        }
        if(it==trabalhadores.end())
            return;

        for (auto k: Ilha::getVetorRecursos()) {
            if (k->getNome() == "Barra de Aco") {
                k->aumentaQuantidade(1);

            }else if (k->getNome() == "Ferro") {
                k->retiraQuantidade(1.5);
            }
            else if (k->getNome() == "Carvao") {
                k->retiraQuantidade(0.5);
            }
        }
    } else{
        cout << "Nao é possivel construir barras de aco";
    }
}

Edificio* Fundicao::duplica() {
    return new Fundicao(*this);
}









