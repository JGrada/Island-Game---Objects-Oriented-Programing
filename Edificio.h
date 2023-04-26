#ifndef TP_EDIFICIO_H
#define TP_EDIFICIO_H
#include <vector>
#include "Trabalhadores.h"
#include <string>
using namespace std;

class Zona;
class Edificio {
private:
    bool estado;
    int nTrabalhadores;
    int preco;
    int diaConstrucao;
protected:
    int nivel;
public:

    Edificio(int nTrabalhadores, int nivel) : estado(false), nTrabalhadores(nTrabalhadores), nivel(nivel){}
    virtual ~Edificio() {};
    virtual string getNome() const = 0;
    string getAsString() const;
    bool getEstado();
    int getNtrabalhadores();
    virtual int getNivel() = 0;
    virtual int aumentaNivel() = 0;
    bool Liga();
    bool Desliga();
    virtual int getPreco() = 0;
    virtual void Produz(vector<Zona *> zonas, vector<Trabalhadores*> trabalhadores) = 0;
    virtual Edificio* duplica() = 0;

};

#endif //TP_EDIFICIO_H
