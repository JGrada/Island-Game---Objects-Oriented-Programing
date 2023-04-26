
#include "Madeira.h"


Recursos* Madeira::duplica() {
    return new Madeira(*this);
}