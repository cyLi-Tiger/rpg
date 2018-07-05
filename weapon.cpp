#include "weapon.h"

void Weapon::automove(){
    this->_pos_x++;
    return;
}

void Weapon::autoRivalmove(){
    this->_pos_x--;
    return;
}
