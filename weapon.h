#ifndef WEAPON_H
#define WEAPON_H
#include "rpgobj.h"
class Weapon: public Rpgobj
{
public:
    Weapon(){}
    void automove();
    void autoRivalmove();
    void setstate(bool a)
    {
        state=a;
    }
    bool getstate(){
        return this->state;
    }

private:
    bool state = 0;
};

#endif // WEAPON_H
