
#include "BarraAco.h"


Recursos* BarraAco::duplica() {
    return new BarraAco(*this);
}