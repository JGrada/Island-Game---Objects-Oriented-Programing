
#include "Lenhador.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include "Zona.h"


Trabalhadores* Lenhador::duplica() {
    return new Lenhador(*this);
}

int Lenhador::getProb() {
    int f;
    vector<int> Prob;
    {
        srand((unsigned)time(0));
        int i;
        i = (rand()%100);
        if(i >= 0 and i<=5)
        {


        }

    }

}

