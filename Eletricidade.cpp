
#include "Eletricidade.h"

Recursos* Eletricidade::duplica() {
    return new Eletricidade(*this);
}