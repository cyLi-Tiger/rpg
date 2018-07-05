#include "elf.h"
#include <QPainter>
#include <QImage>

void Elf::showelf(QPainter *painter)
{
    QImage image = QImage(":/PICS/elf.png");
    painter->drawImage(getPosX(),getPosY(),image);
}
