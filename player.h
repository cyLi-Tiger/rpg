#ifndef PLAYER_H
#define PLAYER_H
#include "rpgobj.h"
#include <iostream>

using namespace std;
class Player: public Rpgobj
{
public:
    Player(){}
    ~Player(){}
    void move(int _x, int _y=1);
        //direction =1,2,3,4 for 上下左右
    void setstate(bool x){
        state = x ;
    }
    bool getstate(){
        return this->state;
    }
    void showstate(){cout<<"玩家已死亡"<<endl;}
    int getw(){
        return w;
    }
    int geta(){
        return a;
    }
    int gets(){
        return s;
    }
    int getd(){
        return d;
    }
    static int getHPNum(){
        return HPnum;
    }
    static void addHPNum(){
        if(Money>0) HPnum++;
    }
    static void subHPNum(){
        if(HPnum>0) HPnum--;
    }
    static int getMPNum(){
        return MPnum;
    }
    static void addMPNum(){
        if(Money>0) MPnum++;
    }
    static void subMPNum(){
        if(MPnum>0) MPnum--;
    }
    static int getMoney(){
        return Money;
    }
    static void addMoney(){
        Money++;
    }
    static void subMoney(){
        if(Money>0) Money--;
    }

private:
    bool state = 1;
    static int HPnum , MPnum ,Money;//药水的数量
//    bool showstate =true;
    int w=0,a=0,s=0,d=0;
};

#endif // PLAYER_H
