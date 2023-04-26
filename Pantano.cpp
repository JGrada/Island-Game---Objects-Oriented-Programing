#include "Pantano.h"
#include "Ilha.h"



int Pantano::EfeitoZona() {
    for(auto i : getVetorTrabalhadores()){
        if (Ilha::getDia() == 10 or Ilha::getDia() == 20 or Ilha::getDia() == 30){
            ApagaTrabalhadores(i->getId());
            ApagaEdificio();
        }
    }

}

Zona* Pantano::duplica() {
    return new Pantano(*this);
}
