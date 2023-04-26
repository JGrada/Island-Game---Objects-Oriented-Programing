
#include "Mineiro.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

Trabalhadores* Mineiro::duplica() {
    return new Mineiro(*this);
}

int Mineiro::getProb() {
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

