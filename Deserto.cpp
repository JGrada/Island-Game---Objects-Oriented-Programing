

#include "Deserto.h"
#include "Edificio.h"
#include "MinaCarvao.h"
#include "MinaFerro.h"
#include "Ilha.h"

int Deserto::EfeitoZona() {

}

Zona* Deserto::duplica() {
    return new Deserto(*this);
}