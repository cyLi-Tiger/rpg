#ifndef CONTAINER_H
#define CONTAINER_H

#include "rpgobj.h"
class Container:public Rpgobj
{
public:
    Container(){}
    int getnum(){
        return num;
    }
    void setnum(int n){
        num=n;
    }
    void addnum(){
        num++;
    }
    void subnum(){
        num--;
    }
    friend class World;
private:
    static int num;
    bool canuse=true;
};

#endif // CONTAINER_H
