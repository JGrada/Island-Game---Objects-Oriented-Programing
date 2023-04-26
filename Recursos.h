
#ifndef TRABALHOPOO_RECURSOS_H
#define TRABALHOPOO_RECURSOS_H
#include <string>
using namespace std;

class Recursos {
private:
    float precoUnidade;
    float quantidade = 0;

public:
    static float saldo;

    Recursos(float precoUnidade) : precoUnidade(precoUnidade){};
    virtual ~Recursos() {};
    virtual string getNome() = 0;
    float getQuantidade();
    float retiraQuantidade(float valor);
    float aumentaQuantidade(float valor);
    int getPreco() {return precoUnidade;};
    static float ajustaSaldo(float valor_recebido);
    static float aumentaSaldo(float valor_recebido);
    virtual Recursos* duplica() = 0;




};


#endif //TRABALHOPOO_RECURSOS_H
