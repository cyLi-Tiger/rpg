#ifndef MONSTER_H
#define MONSTER_H
#include <icon.h>
#include "rpgobj.h"
#include <map>

class monster: public Rpgobj
{
public:
    monster();
    ~monster();
    void move(int direction, int steps=1);
    //direction =1,2,3,4 for 上下左右
};

#endif // MONSTER_H
