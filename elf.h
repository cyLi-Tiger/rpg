#ifndef ELF_H
#define ELF_H
#include "rpgobj.h"
#include "player.h"
#include "monster.h"
#include <QPainter>

class Elf:public Player{
    public:
        int getred(){
            return red;
        }
        void setred(int k){
            red=k;
        }
        int getblue(){
            return blue;
        }
        void setblue(int k){
            blue=k;
        }
        void showelf(QPainter *painter);

    private:
        int red;
        int blue;
};

#endif // ELF_H
