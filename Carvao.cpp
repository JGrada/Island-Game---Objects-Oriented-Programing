
#include "Carvao.h"

Recursos* Carvao::duplica() {
    return new Carvao(*this);
}
