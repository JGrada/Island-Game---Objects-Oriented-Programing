
#include "VigasMadeira.h"

Recursos* VigasMadeira::duplica() {
    return new VigasMadeira(*this);
}