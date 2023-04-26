
#include "Edificio.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Ilha.h"
using namespace std;

bool Edificio::getEstado() {
    if(Edificio::estado == 0)
        cout << "Edificio desligado \n";
    else
        cout << "Edificio ligado \n";

}

int Edificio::getNtrabalhadores() {
    return nTrabalhadores;
}

int Edificio::getNivel() {
    return nivel;
}

bool Edificio::Liga() {
    Edificio::estado = true;
}

bool Edificio::Desliga() {
    Edificio::estado = false;

}




