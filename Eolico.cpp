
#include "Eolico.h"
#include "Ilha.h"
#include <algorithm>
#include <chrono>
#include <random>

int Eolico::getRandomAerogeradores() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 p(seed);
    uniform_int_distribution<int> distribution(0, 10);
    int nrRandomAerogeradores = distribution(p);

    return nrRandomAerogeradores;
}

int Eolico::EfeitoZona() {
    for(auto i : getVetorTrabalhadores()){
        if (i->getNome() == "len") {
            nrAerogeradores++;
        }
        if (Ilha::getDia() == 5 or Ilha::getDia() == 10 or Ilha::getDia() == 15 or Ilha::getDia() == 20){
            ApagaTrabalhadores(i->getId());
            ApagaEdificio();
            nrAerogeradores--;
        }
    }
    cout << "Numero de Aerogeradores restantes: " <<nrAerogeradores << endl;
}

Zona* Eolico::duplica() {
    return new Eolico(*this);
}