
#ifndef TP_ZONA_H
#define TP_ZONA_H


#include <string>
#include "Edificio.h"
#include "Recursos.h"
#include "Trabalhadores.h"
#include <vector>
using namespace std;

class Zona {
private:


    int numTrabalhadores;
    vector<Trabalhadores*> trabalhadores;
    Edificio *edificio;

public:

    Zona() : edificio(nullptr) {}
    virtual ~Zona();
    Zona(Zona &outro);
    const static vector<string> tiposZonas;
    virtual string getNome() const = 0;
    vector<Trabalhadores*> getVetorTrabalhadores() const;
    Edificio* getEdificio();
    void AdicionaTrabalhadores(string tipo);
    void ApagaTrabalhadores(int id);
    void PushTrabalhador(Trabalhadores *trabalhador);
    void MoveTrabalhadores(int id, int l, int c);
    void AdicionaEdificios(string n);
    void AdicionaEdificiosDebEd(string n);
    void ApagaEdificio();
    int getNtrabalhadores();
    void desenharZona();
    virtual int EfeitoZona() = 0;
    void getInfo();
    virtual Zona* duplica() = 0;



};

#endif //TP_ZONA_H
