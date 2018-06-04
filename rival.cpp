#include "rival.h"
#include<stdlib.h>
#include <math.h>
#define Random(x) (rand() % x) //通过取余取得指定范围的随机数

void Rival::move()
{
   int dis = 25;
   setPosX(Random(dis));
   setPosY(Random(dis));
   return;
}
void Rival::shortestdis(int x, int y)
{
    int x0=(_pos_x-x)*(_pos_x-x)+(_pos_y-y)*(_pos_y-y);
    //int x1=(_pos_x+1-x)*(_pos_x+1-x)+(_pos_y-y)*(_pos_y-y);
    //int x2=(_pos_x-1-x)*(_pos_x-1-x)+(_pos_y-y)*(_pos_y-y);
    int x3=(_pos_x-x)*(_pos_x-x)+(_pos_y+1-y)*(_pos_y+1-y);
    int x4=(_pos_x-x)*(_pos_x-x)+(_pos_y-1-y)*(_pos_y-1-y);
    int tmp=findminus(x0,x3,x4);
    //if(tmp==x1) _pos_x+=1;
    //if(tmp==x2) _pos_x-=1;
    if(tmp==x3) _pos_y+=1;
    if(tmp==x4) _pos_y-=1;
    return;
}

int Rival::findminus(int x0, int x3, int x4)
{
    int tmp=x0;
    //if(x1<x0) tmp=x1;
    //if(x2<x0) tmp=x2;
    if(x3<x0) tmp=x3;
    if(x4<x0) tmp=x4;
    return tmp;
}





/*void Rival::automove(){
    int dis=5;
    int tmp = Random(dis);
    switch (tmp)
    {
    case 1:
        this->_pos_x+=1;
        break;
    case 2:
        this->_pos_x-=1;
        break;
    case 3:
        this->_pos_y+=1;
        break;
    case 4:
        this->_pos_y-=1;
        break;
    default:
        break;
    }
    return;
}*/
