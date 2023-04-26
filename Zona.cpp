#include "Zona.h"
#include "Trabalhadores.h"
#include "Edificio.h"
#include <vector>
#include <string>
#include <sstream>
#include "Mineiro.h"
#include "Lenhador.h"
#include "Operario.h"
#include "CentralEletrica.h"
#include "Bateria.h"
#include "Fundicao.h"
#include "MinaCarvao.h"
#include "MinaFerro.h"
#include "Recursos.h"
#include "BarraAco.h"
#include "VigasMadeira.h"
#include "EdificioX.h"
#include <algorithm>
#include <vector>


#include "Ilha.h"
#include "Eletricidade.h"
#include "Madeira.h"

using namespace std;


const vector<string> Zona::tiposZonas = {"mnt", "dsr", "pas", "flr", "pnt", "pqE"};

int Zona::getNtrabalhadores(){
    return getVetorTrabalhadores().size();
}
Edificio* Zona::getEdificio(){
    return edificio;
}

vector<Trabalhadores*> Zona::getVetorTrabalhadores() const{
    vector<Trabalhadores*> VecT;
    for(auto i : trabalhadores)
        VecT.push_back(i);
    return VecT;
}

void Zona::getInfo(){
    cout << getNome() << "\n";
    cout << edificio->getNome() << "\n";
    cout << edificio->getEstado() << "\n";
    for(auto i : trabalhadores)
    {
        cout << i->getNome() << "\n";
    }


}

void Zona::AdicionaTrabalhadores(string tipo){
    if(tipo == "miner"){
        trabalhadores.push_back(new Mineiro(1, getNome()));
        Recursos::ajustaSaldo(10);


    }
    else if(tipo == "len"){
        trabalhadores.push_back(new Lenhador(1, getNome()));
        Recursos::ajustaSaldo(20);
        ;

    }
    else if(tipo == "oper"){
        trabalhadores.push_back(new Operario(1, getNome()));
        Recursos::ajustaSaldo(15);


    }
    else{
        cout << "Cysco insere um trabalhador da cantina" << endl;
    }

}
void Zona::AdicionaEdificios(string n) {
    if(n == "elec"){
        edificio = new CentralEletrica( trabalhadores.size(), 1);
        Recursos::ajustaSaldo(getEdificio()->getPreco());
    }
    else if(n == "bat"){
        edificio = new Bateria( trabalhadores.size(), 1);
        Recursos::ajustaSaldo(getEdificio()->getPreco());
    }
    else if(n == "fun"){
        edificio = new Fundicao( trabalhadores.size(), 1);
        if (getNome()== "mnt"){
            Recursos::ajustaSaldo(getEdificio()->getPreco()*2);
        }
        else{
            Recursos::ajustaSaldo(getEdificio()->getPreco());
        }

        cout << Recursos::saldo << " cyscos\n";
    }
    else if(n == "mnC"){
        edificio = new MinaCarvao( trabalhadores.size(), 1);
        Recursos::ajustaSaldo(getEdificio()->getPreco());
    }
    else if(n == "mnF"){
        edificio = new MinaFerro( trabalhadores.size(), 1);
        Recursos::ajustaSaldo(getEdificio()->getPreco());
    }else if(n == "edX"){
        edificio = new EdificioX ( trabalhadores.size(), 1);
        Recursos::ajustaSaldo(getEdificio()->getPreco());
    }
    else{
        cout << "Edificio invalido" << endl;
    }
}

void Zona::AdicionaEdificiosDebEd(string n) {
    if(n == "elec"){
        edificio = new CentralEletrica( trabalhadores.size(), 1);

    }
    else if(n == "bat"){
        edificio = new Bateria( trabalhadores.size(), 1);

    }
    else if(n == "fun"){
        edificio = new Fundicao( trabalhadores.size(), 1);

    }
    else if(n == "mnC"){
        edificio = new MinaCarvao( trabalhadores.size(), 1);

    }
    else if(n == "mnF"){
        edificio = new MinaFerro( trabalhadores.size(), 1);

    }else if(n == "edX"){
        edificio = new EdificioX ( trabalhadores.size(), 1);

    }
    else{
        cout << "Insira um edificio valido" << endl;
    }
}

void Zona::PushTrabalhador(Trabalhadores *trabalhador) {
        trabalhadores.push_back(trabalhador);

};

void Zona::ApagaTrabalhadores(int id) {

    auto it = trabalhadores.cbegin();
    while(it < trabalhadores.cend()){
        if ((*it)->getId() == id){
            trabalhadores.erase(it);
        } else
            ++it;
    }
}

void Zona::ApagaEdificio() {
    delete edificio;
    edificio = nullptr;
}

Zona::~Zona() {
    for(auto t : trabalhadores){
        cout << "Apagou o trabalhador: " << t->getNome() << endl;
        delete t;
    }
}

Zona::Zona(Zona &outro){
    if(outro.getEdificio() != nullptr)
    {
        edificio = outro.getEdificio()->duplica();
    }
    else{
        edificio = nullptr;
    }
    for(auto t : outro.trabalhadores)
        trabalhadores.push_back(t->duplica());
}








