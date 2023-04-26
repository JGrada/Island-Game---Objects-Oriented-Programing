#include <iostream>
using namespace std;
#include "Ilha.h"
#include "Comandos.h"
#include "Interface.h"
#include "Trabalhadores.h"
#include "Edificio.h"
#include "Recursos.h"
#include "Floresta.h"
#include "Zona.h"
#include <map>

int main() {

    int saldo;
    int linhas, colunas;
    string nome;
    map<string,Ilha*> m;


    cout << "Pretende que existam quantas linhas?" << endl;
    cin >> linhas;

    cout << "Pretende que existam quantas colunas?" << endl;
    cin >> colunas;

    Ilha ilha1(linhas, colunas);


    cout << "Dia: " << ilha1.getDia() << endl;
    string comando;
    Interface validacao(&ilha1, m);

        do {
            cout << "Introduza um comando: " << endl;
            getline(cin, comando);
            validacao.validaComandos(comando);
            ilha1.DesenharIlha();
            cout << "Dia: " << ilha1.getDia() << endl;
        } while (comando != "fim");

    ilha1.DesenharIlha();

    Interface Fich(&ilha1, m);
    Fich.LeFicheiro();
    ilha1.DesenharIlha();


    return 0;

}
