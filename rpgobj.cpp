#include "rpgobj.h"
#include <iostream>
#include <fstream>
#include <QPainter>

extern fstream error;

void Rpgobj::subtractHP(int HP_harm){
    HP_now-=HP_harm;
}

void Rpgobj::subtractMP(int MP_reduction){
    MP_now-=MP_reduction;
}

void Rpgobj::initObj(string type)//第一种
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/TileB.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE1, _icon.getSrcY()*ICON::GRID_SIZE1, _icon.getWidth()*ICON::GRID_SIZE1, _icon.getHeight()*ICON::GRID_SIZE1));
}

void Rpgobj::initbet(string type)
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/Nature.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE2, _icon.getSrcY()*ICON::GRID_SIZE2, _icon.getWidth()*ICON::GRID_SIZE2, _icon.getHeight()*ICON::GRID_SIZE2));
}

void Rpgobj::iniplayer(string type)//第二种
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/player.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE2, _icon.getSrcY()*ICON::GRID_SIZE2, _icon.getWidth()*ICON::GRID_SIZE2, _icon.getHeight()*ICON::GRID_SIZE2));
}

void Rpgobj::inisao(string type)
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/sao.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE3, _icon.getSrcY()*ICON::GRID_SIZE3, _icon.getWidth()*ICON::GRID_SIZE3, _icon.getHeight()*ICON::GRID_SIZE3));
}

void Rpgobj::inibullet(string type)
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/bullet.png");
    this->_pic = all.copy(QRect(_icon.getSrcX(), _icon.getSrcY(), _icon.getWidth(), _icon.getHeight()));
}

void Rpgobj::initprop(string type)
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/Inside_C.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE2, _icon.getSrcY()*ICON::GRID_SIZE2, _icon.getWidth()*ICON::GRID_SIZE2, _icon.getHeight()*ICON::GRID_SIZE2));
}

void Rpgobj::initunnel(string type)
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/tunnel.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE2, _icon.getSrcY()*ICON::GRID_SIZE2, _icon.getWidth()*ICON::GRID_SIZE2, _icon.getHeight()*ICON::GRID_SIZE2));
}

void Rpgobj::ininpc(string type)
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/People1.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE2, _icon.getSrcY()*ICON::GRID_SIZE2, _icon.getWidth()*ICON::GRID_SIZE2, _icon.getHeight()*ICON::GRID_SIZE2));
}

void Rpgobj::inidq(string type)
{
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":/PICS/dq.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE3, _icon.getSrcY()*ICON::GRID_SIZE3, _icon.getWidth()*ICON::GRID_SIZE3, _icon.getHeight()*ICON::GRID_SIZE3));
}
void Rpgobj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE1;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

void Rpgobj::showplayer(QPainter * pa){
    int gSize = 10;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

void Rpgobj::showsao(QPainter * pa){
    int gSize = 1;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

void Rpgobj::showbullet(QPainter * pa){
    int gSize = 1;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

void Rpgobj::showprop(QPainter * pa){
    int gSize = ICON::GRID_SIZE2;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

void Rpgobj::showtunnel(QPainter * pa){
    int gSize = 1;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

void Rpgobj::showdq(QPainter * pa){
    int gSize = 1;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

