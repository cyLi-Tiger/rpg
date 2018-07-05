#include "player.h"
#include "icon.h"
#include <iostream>
#include <vector>
#include "world.h"
#include "mainwindow.h"
using namespace std;

int Player::HPnum = 8;
int Player::MPnum = 8;
int Player::Money = 8;
//direction =1,2,3,4 for 上下左右
void Player::move(int _x, int _y){
    this->_pos_y += _y;
    this->_pos_x += _x;
    if(_x==1&&_y==0)
    {
        d++;
    }
    else if(_x==-1&&_y==0)
    {
        a++;
    }
    else if(_x==0&&_y==1)
    {
        s++;
    }
    else if(_x==0&&_y==-1)
    {
        w++;
    }
}

