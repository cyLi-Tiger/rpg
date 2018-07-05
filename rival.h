#ifndef RIVAL_H
#define RIVAL_H
#include "rpgobj.h"
#include "weapon.h"
class Rival: public Rpgobj
{
public:
    Rival(){}
    ~Rival(){}
    void move();//为了进入battle界面
   // void automove();
    void shortestdis(int x, int y);
    void setstate(bool x){
        state = x ;
    }
    bool getstate(){
        return this->state;
    }
    void autoattack();
    int findminus(int x0, int x3, int x4);
private:
    bool state = 0;
};

#endif // RIVAL_H
