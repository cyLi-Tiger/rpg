#include "monster.h"
#include <QPainter>
#include <QImage>


void Monster::showmonster(QPainter *painter){
    QImage image = QImage(":/PICS/Ghost.png");
    painter->drawImage(getPosX(),getPosY(),image);
}

void Monster::showmonsterr(QPainter *painter){
    QImage image = QImage(":/PICS/darklord.png");
    painter->drawImage(getPosX(),getPosY(),image);
}
