#ifndef MONSTER_H
#define MONSTER_H
#include "rpgobj.h"
#include <QPainter>

class Monster:public Rpgobj{
    public:
        void showmonster(QPainter *painter);
        void showmonsterr(QPainter *painter);
};

#endif // MONSTER_H
