
#include "Ferro.h"


Recursos* Ferro::duplica() {
    return new Ferro(*this);
}