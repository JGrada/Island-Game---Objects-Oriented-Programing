
#include "Zona.h"
#include "Pastagem.h"


int Pastagem::EfeitoZona() {

}

Zona* Pastagem::duplica() {
    return new Pastagem(*this);
}
