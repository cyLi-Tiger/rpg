#ifndef NPC_H
#define NPC_H
#include "rpgobj.h"
#include "player.h"

class Npc:public Rpgobj
{
public:
    Npc(){}
    int ifnpcclose(int _x,int _y);
    ~Npc(){}

};

#endif // NPC_H
