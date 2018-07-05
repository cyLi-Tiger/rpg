#ifndef BULLET_H
#define BULLET_H
#include "rpgobj.h"
class Bullet: public Rpgobj
{
public:
    friend class Player;
    Bullet(){}
    ~Bullet(){}
private:
};
#endif // BULLET_H
