
#include <iostream>
#include "Recursos.h"

float Recursos::saldo = 1000;



float Recursos::retiraQuantidade(float valor) {
    quantidade -= valor;
    return quantidade;
}

float Recursos::aumentaQuantidade(float valor) {
    quantidade += valor;
    return quantidade;
}

float Recursos::getQuantidade() {
    return quantidade;
}
float Recursos::ajustaSaldo(float valor_recebido){
    saldo = saldo - valor_recebido;
    cout << "Saldo apos operacao: " << saldo << " cyscos" << endl;
    return saldo;
}

float Recursos::aumentaSaldo(float valor_recebido){
    saldo = saldo + valor_recebido;
    cout << "Saldo apos operacao: " << saldo << " cyscos" << endl;
    return saldo;
}



