//
// Created by Rodrigo Alcaide on 18/11/2021.
//
#include "Ilha.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "Zona.h"
#include <iomanip>
#include <random>
#include <algorithm>
#include "Deserto.h"
#include "Pantano.h"
#include "Montanha.h"
#include "Eolico.h"
#include "Floresta.h"
#include "Pastagem.h"
#include "Fundicao.h"
#include "MinaCarvao.h"
#include "MinaFerro.h"
#include "CentralEletrica.h"
#include "Bateria.h"
#include "Edificio.h"
#include "Mineiro.h"
#include "Interface.h"
#include "Eletricidade.h"
#include "Madeira.h"
#include "BarraAco.h"
#include "VigasMadeira.h"


using namespace std;

const int Ilha::MinLinhas = 3;
const int Ilha::MinColunas = 3;
const int Ilha::MaxLinhas = 8;
const int Ilha::MaxColunas = 16;

int Ilha::dia = 1;

int Ilha::getLinhas(){
    return linhas;
}
int Ilha::getColunas(){
    return colunas;
}
int Ilha::getDia(){
    return dia;
}

int Ilha::incrementaDia() {
    dia++;
    diaSave++;
    return dia;
}

vector<string> Ilha::getZonas(int linhas, int colunas){
    vector<string> resultadoZonas;
    resultadoZonas.reserve(linhas * colunas);
    for(int i=0, j=0 ; i < linhas * colunas ; ++i, ++j){
        if(j == 6){
            j = 0;
        }
        resultadoZonas.push_back(Zona::tiposZonas[j]);
    }
    shuffle(resultadoZonas.begin(), resultadoZonas.end(), mt19937(random_device()()));

    return resultadoZonas;
}


Ilha::Ilha (int nlinhas, int ncolunas) :   linhas(nlinhas),  colunas(ncolunas), diaSave(1){
    if (linhas < MinLinhas or linhas > MaxLinhas) {
        linhas = MinLinhas;
    }
    if (colunas < MinColunas or colunas > MaxColunas) {
        colunas = MinColunas;
    }
    int i = 0;
    int j = 0;

    for(auto z : getZonas(linhas, colunas) ){
        if(j == 0) {

            zonas.emplace_back(vector<Zona*>());
        }
        if(z == "dsr"){
            zonas[i].push_back(new Deserto);
        }
        else if(z == "mnt"){
            zonas[i].push_back(new Montanha);
        }
        else if(z == "pas"){
            zonas[i].push_back(new Pastagem);
        }
        else if(z == "flr"){
            zonas[i].push_back(new Floresta);
            Floresta::getRandomArvores();
        }
        else if(z == "pnt"){
            zonas[i].push_back(new Pantano);
        }
        else if(z == "pqE"){
            zonas[i].push_back(new Eolico);

        }
        else {
        }
        ++j;

        if (j == colunas){
            ++i;
            j = 0;

        }
    }
}


void Ilha::DesenharIlha() {

    ostringstream oss;
    ostringstream oss_dia;
    ostringstream oss_edificio;
    ostringstream oss_trabalhadores;
    ostringstream oss_Ntrabalhadores;
    ostringstream oss_trabalhadoresAuxiliares;
    for(auto zona : zonas){
        oss.str("");
        oss.clear();
        oss_edificio.str("");
        oss_edificio.clear();
        oss_trabalhadores.str("");
        oss_trabalhadores.clear();
        oss_Ntrabalhadores.str("");
        oss_Ntrabalhadores.clear();
        for (auto z : zona) {
            oss_trabalhadoresAuxiliares.str("");
            oss_trabalhadoresAuxiliares.clear();
            oss << "-" << left << setw(4) << z->getNome();
            if (z->getEdificio() != nullptr){
                oss_edificio  << "-" << left << setw(4) << z->getEdificio()->getNome();
            }
            else{
                oss_edificio  << "-" << left << setw(4) << " ";
            }

            int i = 0;
            for(auto t : z->getVetorTrabalhadores()){
                oss_trabalhadoresAuxiliares << t->getLetra();
                i++;
                if(i >= 4){
                    break;
                }
            }
            oss_trabalhadores << "-" << left << setw(4) << oss_trabalhadoresAuxiliares.str();
            oss_Ntrabalhadores  << "-" << left << setw(4) << z->getVetorTrabalhadores().size();
        }

        cout << oss.str() << endl;
        cout << oss_edificio.str() << endl;
        cout << oss_trabalhadores.str() << endl;
        cout << oss_Ntrabalhadores.str() << endl;

        for (int i = 0; i < getColunas(); ++i) {
            cout << "-----";
        }
        cout << endl;
    }

}

void Ilha::Amanhecer() {

   for(auto i: zonas)
   {
       for(auto z : i)
       {
           z->EfeitoZona();
       }
   }
}

void Ilha::Anoitecer() {

    for(auto i : zonas){
        for(auto z : i){
            if(z->getEdificio() != nullptr){
                z->getEdificio()->Produz(getZonasAdjacentes(z), z->getVetorTrabalhadores());
            }
        }
    }

}

void Ilha::MostraRecursos()
{
    cout << "Quantidade de carvao: " <<getVetorRecursos()[0]->getQuantidade() << endl ;
    cout << "Quantidade de eletricidade: " << getVetorRecursos()[1]->getQuantidade() << endl;
    cout << "Quantidade de ferro: " << getVetorRecursos()[2]->getQuantidade() << endl;
    cout << "Quantidade de madeira: " << getVetorRecursos()[3]->getQuantidade() << endl;
    cout << "Quantidade de barras de aco: " << getVetorRecursos()[4]->getQuantidade() << endl;
    cout << "Quantidade de Vigas de Madeira: " << getVetorRecursos()[5]->getQuantidade() << endl;

}

vector<Recursos *> Ilha::getVetorRecursos() {
    return recursos;
}
vector<Recursos*> Ilha::recursos={new Carvao(1), new Eletricidade(1.5), new Ferro(1),
                                  new Madeira(1), new BarraAco(1), new VigasMadeira(2)};

void Ilha::vendeRecursos(float quantia, string tipoRecurso) {
    for(auto r : getVetorRecursos()){
        if(r->getNome() == tipoRecurso){
            r->retiraQuantidade(quantia);
        }
    }

}


vector<Zona*> Ilha::getZonasAdjacentes(Zona* zonaAtual) {
    int i,j;
    bool state = false;
    vector<Zona*> zonasAdjacentes;
    for(i=0 ; i < linhas; i++){
        for (j = 0; j < colunas ; j++) {
            if (zonas[i][j] == zonaAtual){
                if(i > 0) {
                    zonasAdjacentes.push_back(zonas[i - 1][j]);
                }
                if(j > 0) {
                    zonasAdjacentes.push_back(zonas[i][j - 1]);
                }
                if(i < linhas - 1) {
                    zonasAdjacentes.push_back(zonas[i + 1 ][j]);
                }
                if(j < colunas - 1) {
                    zonasAdjacentes.push_back(zonas[i][j + 1]);
                }
                state = true;
                break;
            }

        }
        if(state == true)
            break;
    }

    return zonasAdjacentes;

}

Ilha::Ilha(Ilha &outro) {
    *this = outro;
}

Ilha &Ilha::operator = (const Ilha &outro){
    if(this == &outro){
        return *this;
    }
    for(auto z : zonas)
        for (auto l : z)
            delete l;
    zonas.clear();
    linhas = outro.linhas;
    colunas = outro.colunas;
    diaSave = outro.diaSave;
    int i=0;
    for (auto z : outro.zonas) {
        zonas.emplace_back(vector<Zona *>()) ;


        for (auto r : z) {
            zonas[i].push_back(r->duplica());
        }
        ++i;
    }
    return *this;
}



Ilha::~Ilha() {
    for(auto i : zonas){
        for(auto z: i){
            cout << "O cysco apagou a Zona: " << z->getNome() << endl;
            delete z;
        }

    }

    for(auto r : recursos){
        cout << "O cysco apagou o recurso: " << r->getNome() << endl;
        delete r;
    }
}

vector<Recursos *> Ilha::getVetorRecursosSave() {
    int i = 0;
    for(auto r : getVetorRecursos()){
        if(r->getNome() == "Carvao"){
            recursosSave.push_back(r->duplica());
        }
        else if(r->getNome() == "Ferro"){
            recursosSave.push_back(r->duplica());
        }
        else if(r->getNome() == "Madeira"){
            recursosSave.push_back(r->duplica());
        }
        else if(r->getNome() == "Barra de Aco"){
            recursosSave.push_back(r->duplica());
        }
        else if(r->getNome() == "Vigas de Madeira"){
            recursosSave.push_back(r->duplica());
        }
        else if(r->getNome() == "Eletricidade"){
            recursosSave.push_back(r->duplica());
        }

    }
    return recursosSave;
}









