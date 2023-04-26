#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include "Operario.h"

Trabalhadores* Operario::duplica() {
    return new Operario(*this);
}


int Operario::getProb() {
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
