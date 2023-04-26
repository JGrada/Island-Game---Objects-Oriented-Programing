
#include <string>
#include <sstream>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <fstream>
#include "Trabalhadores.h"
#include "Zona.h"
#include "Interface.h"
#include "Comandos.h"
#include "Edificio.h"
#include <random>
#include <algorithm>

using namespace std;

const vector<string> Interface::tiposEdificios = {"mnF", "mnC", "elec", "bat",  "edX", "fun"};

const vector<string> Interface::tiposEdificiosLevelUp = {"mnF", "mnC"};

const vector<string> Interface::tiposTrabalhadores = {"O", "L", "M"};

const vector<string> Interface::tiposRecursos = {"Ferro", "Carvao", "Madeira", "BarradeAco", "VigasdeMadeira", "Eletricidade"};


Interface::Interface(Ilha *il, map<string,Ilha*> &m) : il(il), m(m)
{

}

void Interface::validaComandos(string linha) {
    string comando, aux, aux2, param1, param2, param3;
    int param1int, param2int, param3int;
    float param1float, param2float, param3float;


    istringstream iss(linha);
    istringstream iss2(linha);
    iss >> aux;
    iss2 >> aux2;
    if (aux == "exec") {
        ifstream file;
        iss >> param1;
        file.open(param1);
        if (!file) {
            cout << "Ficheiro nao existente";
        }
        else {
            string ch;

            while (getline(file,ch)) {
                validaComandos(ch);

            }

        }
        file.close();

    }
    else if (aux == "cons") {
        int i;
        iss >> param1 >> param2int >> param3int;
        for (i = 0; i < 6; i++)
            if (tiposEdificios[i] == param1) {
                break;
            }
        if (i == 6) {
            cout << " Inseriu um edificio inexistente" << endl;
            return;
        }
        if (iss) {
            if(param2int >= 0 and param2int < il->getLinhas() and param3int >= 0 and param3int < il->getColunas())
                il->zonas[param2int][param3int]->AdicionaEdificios(param1);
            else{
                cout << "Inseriu coordenadas invalidas" << endl;
            }


        }
    }
    else if (aux == "level"){
        int i;
        iss >> param1 >> param2int >> param3int;
        for(i=0; i<2; i++)
            if(tiposEdificiosLevelUp[i] == param1)
            {
                break;
            }

        if (iss) {
            if (param2int >= 0 and param2int < il->getLinhas() and param3int >= 0 and param3int < il->getColunas()) {
                il->zonas[param2int][param3int]->getEdificio()->aumentaNivel();
            } else {
                cout << "Inseriu coordenadas invalidas" << endl;
            }
        }
    }

    else if (aux == "liga") {
        iss >> param1int >> param2int;

        if (param1int >= 0 and param1int < il->getLinhas() and param2int >= 0 and param2int < il->getColunas()) {
            if (iss) {
                il->zonas[param1int][param2int]->getEdificio()->Liga();
                cout << il->zonas[param1int][param2int]->getEdificio()->getEstado() << endl;
            } else {
                cout << "Inseriu coordenadas invalidas" << endl;
            }
        }
    }

    else if (aux == "des") {
        iss >> param1int >> param2int;
        if (param1int >= 0 and param1int < il->getLinhas() and param2int >= 0 and param2int < il->getColunas()) {
            if (iss) {
                il->zonas[param1int][param2int]->getEdificio()->Desliga();
                cout << il->zonas[param1int][param2int]->getEdificio()->getEstado() << endl;
            } else {
                cout << "Inseriu coordenadas invalidas" << endl;
            }
        }
    }
    else if (aux == "move") {
        bool flag = false;
        iss >> param1int >> param2int >> param3int;

        if (iss) {
            if (param2int >= 0 and param2int < il->getLinhas() and param3int >= 0 and param3int < il->getColunas()) {
                for (int i = 0; i < il->getLinhas(); i++) {
                    for (int j = 0; j < il->getColunas(); j++) {
                        for (auto t: il->zonas[i][j]->getVetorTrabalhadores()) {
                            if (param1int == t->getId()) {
                                il->zonas[param2int][param3int]->PushTrabalhador(t);
                                il->zonas[i][j]->ApagaTrabalhadores(t->getId());
                                flag = true;
                                break;
                            }
                        }
                        if (flag)
                            break;
                    }
                    if (flag)
                        break;
                }
            }
            else{
                cout << "Inseriu coordenadas invalidas" << endl;
            }
        }
    }


    else if (aux == "vende" || aux2 == "vende") {
        iss >> param1 >> param2float;
        iss2 >> param1int >> param2int;
        for(int i=0; i<6; i++)
            if(tiposRecursos[i] == param1)
            {
                break;
            }
        if (!iss2) {
            Ilha::vendeRecursos(param2float, param1);
            if(param1 == "Ferro" || param1 == "Carvao" || param1 == "Madeira"){
                Recursos::aumentaSaldo(param2float);
            }
            else if(param1 == "Eletricidade"){
                Recursos::aumentaSaldo(param2float * 1.5);
            }
            else if(param1 == "BarradeAco" || param1 == "VigasdeMadeira"){
                Recursos::aumentaSaldo(param2float * 2);
            }
            else{
                cout << "Insira um material válido" << endl;
            }
            cout << Recursos::saldo << endl;
        }

        else if(iss2) {
            if (param1int >= 0 and param1int < il->getLinhas() and param2int >= 0 and param2int < il->getColunas()) {
                if (il->zonas[param1int][param2int]->getEdificio()->getNome() == "elec") {
                    il->zonas[param1int][param2int]->ApagaEdificio();
                    Recursos::aumentaSaldo(15);
                } else if (il->zonas[param1int][param2int]->getEdificio()->getNome() == "fun") {
                    il->zonas[param1int][param2int]->ApagaEdificio();
                    Recursos::aumentaSaldo(10);
                } else if (il->zonas[param1int][param2int]->getEdificio()->getNome() == "bat") {
                    il->zonas[param1int][param2int]->ApagaEdificio();
                    Recursos::aumentaSaldo(10);
                }

            }

            else{
                cout << "Inseriu coordenadas invalidas" << endl;
                }
            }

        cout << Recursos::saldo << endl;
    }
    else if (aux == "cont") {
        iss >> param1;
        vector<Zona*> escolhePastagem;
        int x;
        if (iss) {
            for (auto &i: il->zonas) {
                for (auto &j: i) {
                    if(j->getNome() == "pas")
                    {
                        escolhePastagem.push_back(j);

                    }
                }
            }
            shuffle(escolhePastagem.begin(), escolhePastagem.end(), mt19937(random_device()()));
            escolhePastagem[0]->AdicionaTrabalhadores(param1);
        }
    }
    else if (aux == "list") {
        iss >> param1int >> param2int;
        if (param1int >= 0 and param1int < il->getLinhas() and param2int >= 0 and param2int < il->getColunas()) {
            if (iss.str() == aux) {
                cout << "Dia:" << il->getDia() << endl;
                il->zonas[param1int][param2int]->getInfo();

            } else if (iss) {
                il->zonas[param1int][param2int]->getInfo();
            }
        }
    }

    else if (aux == "next") {
        il->incrementaDia();
        il->Anoitecer();
        il->Amanhecer();
        il->MostraRecursos();
    }
    else if (aux == "save") {
        iss >> param1;
        if (iss) {
            m[param1] = new Ilha(*il);
        }
    }
    else if (aux == "load") {
        iss >> param1;
        if (iss) {
            for(auto save : m){
                if(save.first == param1){
                    *il = *save.second;
                    break;
                }
            }
        }
    }
    else if (aux == "apaga") {
        iss >> param1;
        if (iss) {
            m.erase(param1);
        }
    }
    else if (aux == "debcash") {
        iss >> param1 >>param2int;
        if (iss) {
            if(param1 == "+"){
                Recursos::aumentaSaldo(param2int);
                cout << Recursos::saldo << endl;
            }
            else if(param1 == "-"){
                Recursos::ajustaSaldo(param2int);
                cout << Recursos::saldo << endl;
            }
            else{
                cout << "Tem de ser o sinal + ou -" << endl;
            }
        }
    }
    else if (aux == "debed") {
        iss >> param1 >> param2int >> param3int;
        if (iss) {
            if(param2int >= 0 and param2int < il->getLinhas() and param3int >= 0 and param3int < il->getColunas()){
                il->zonas[param2int][param3int]->AdicionaEdificiosDebEd(param1);
            }
            else{
                cout << "Inseriu coordenadas invalidas" << endl;
            }
        }
    }
    else if (aux == "debkill") {
        iss >> param1int;
        if (iss) {
            for(int i=0; i<il->getLinhas(); i++) {
                for (int j = 0; j < il->getColunas(); j++) {
                    for (auto t: il->zonas[i][j]->getVetorTrabalhadores()) {
                        if (param1int == t->getId()) {
                            il->zonas[i][j]->ApagaTrabalhadores(t->getId());
                            cout << "trabalhador apagado" << endl;
                        }
                    }
                }
            }
        }
    }
}



string Interface::LeFicheiro() {

    ifstream file;
    file.open("comandfile.txt");
    if (!file) {
        cout << "Ficheiro asdasfdf não existente";
    }
    else {
        string ch;

        while (getline(file,ch)) {
            cout << ch;
        }

    }
    file.close();
    return "str";
}





