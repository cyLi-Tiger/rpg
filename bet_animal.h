#ifndef BET_ANIMAL_H
#define BET_ANIMAL_H
#include "rpgobj.h"
#include <iostream>
using namespace std;

class Bet_animal: public Rpgobj
{
public:
    Bet_animal(){}
    ~Bet_animal(){}
    void automove();
    int getstate()
    {
        return this->state;
    }
    int addstate()
    {
        this->state++;
    }
private:
    int state = 0;
};

#endif // BET_ANIMAL_H
