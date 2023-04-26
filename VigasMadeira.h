
#ifndef TRABALHOPOO_VIGASMADEIRA_H
#define TRABALHOPOO_VIGASMADEIRA_H
#include "Recursos.h"

class VigasMadeira : public Recursos{
public:
    VigasMadeira(float precoUnidade) : Recursos(precoUnidade = 2){};
    ~VigasMadeira() override {};
    string getNome() override { return "Vigas de Madeira";};
    Recursos* duplica() override;
};


#endif //TRABALHOPOO_VIGASMADEIRA_H
