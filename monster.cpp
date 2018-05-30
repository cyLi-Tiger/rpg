#include "monster.h"
#include "icon.h"
#include <iostream>
#include <vector>
#include "world.h"
#include "mw1.h"
using namespace std;
//direction =1,2,3,4 for 上下左右

monster::monster(){

}
monster::~monster(){

}

void monster::move(int direction, int steps){
    switch (direction){
        case 1:
            this->_pos_y -= steps;
            break;
        case 2:
            this->_pos_y += steps;
            break;
        case 3:
            this->_pos_x -= steps;
            break;
        case 4:
            this->_pos_x += steps;
            break;
    }
}


