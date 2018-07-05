#include "bet_animal.h"
#include<stdlib.h>
#include <math.h>
#define Random(x) (rand() % x) //通过取余取得指定范围的随机数

void Bet_animal::automove()
{
    int dis = 5;
    this->_pos_x = this->_pos_x + Random(dis);
    return;
}
