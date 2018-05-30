#include "player.h"
#include "icon.h"
#include <iostream>
#include <vector>
#include "world.h"
#include "mw1.h"
using namespace std;

//direction =1,2,3,4 for 上下左右
void Player::move(int _x, int _y){
    this->_pos_y += _y;
    this->_pos_x += _x;
}

