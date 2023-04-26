#include "Montanha.h"

int Montanha::EfeitoZona() {}

Zona* Montanha::duplica() {
    return new Montanha(*this);
}