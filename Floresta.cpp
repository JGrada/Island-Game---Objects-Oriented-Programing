
#include "Floresta.h"
#include "Ilha.h"
#include <algorithm>
#include <chrono>
#include <random>


int Floresta::getRandomArvores() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 p(seed);
    uniform_int_distribution<int> distribution(20, 40);
    int nrRandomArvores = distribution(p);

    return nrRandomArvores;
}

int Floresta::EfeitoZona() {

    if(!getEdificio()){
        if(Ilha::getDia()%2 != 0) {
            if (nrArvores <= 100) {
                nrArvores+= 1;
            }
        }
    }

    else{
        nrArvores-=1;
    }

    return nrArvores;
}
Zona* Floresta::duplica() {
    return new Floresta(*this);
}

