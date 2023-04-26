
#ifndef TRABALHOPOO_EDIFICIOX_H
#define TRABALHOPOO_EDIFICIOX_H


#include "Edificio.h"
#include "Ferro.h"
#include "Carvao.h"
#include "Madeira.h"

class EdificioX : public Edificio{
private:
    int nVigasMadeira;
    int producao;
public:
    EdificioX(int nTrabalhadores, int nivel) : Edificio(nTrabalhadores, nivel), nVigasMadeira(0) {}
    ~EdificioX() override {};
    int getProducao(){ return producao;};
    string getNome() const override { return "edX";};
    int aumentaNivel() override;
    int getNivel() override;
    int getPreco() override;
    void Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) override;
    Edificio* duplica() override;



};


#endif //TRABALHOPOO_EDIFICIOX_H
