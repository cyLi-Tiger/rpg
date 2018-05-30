#include "rpgobj.h"
#include <iostream>
#include <fstream>
extern fstream error;

void Rpgobj::subtractHP(int HP_harm){
    HP_now-=HP_harm;
}

void Rpgobj::subtractMP(int MP_reduction){
    MP_now-=MP_reduction;
}

void Rpgobj::initObj(string type)
{
    /*if (type.compare("player")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else{
        //TODO 应由专门的错误日志文件记录
        error.open("/Users/air/desktop/error.txt",ios::app);
        error<<"Error:invalid ICON type!!!"<<endl;
        error.close();
        return;
    }*/
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load("/Users/air/Desktop/RPG/TileB.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void Rpgobj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

void Rpgobj::showinfo()
{
}


