#ifndef PLAYER_H
#define PLAYER_H
#include "rpgobj.h"

class Player: public Rpgobj
{
public:
    Player(){}
    ~Player(){}
    void move(int _x, int _y=1);
        //direction =1,2,3,4 for 上下左右
};

#endif // PLAYER_H
