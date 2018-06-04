#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"
#include "rival.h"
#include "weapon.h"
class World
{
public:
    World(){}
    ~World(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void initWeapon();
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void handlePlayerMove(int _x, int _y);
    void rivalWeapon(QPainter *painter);
    void setBattle(bool a){
        battle = a;
    }
    bool getBattle(){
        return this->battle;
    }

    void setIfweapon(bool a){
        ifweapon = a;
    }
    bool getIfweapon(){
        return this->ifweapon;
    }
    void addamount()
    {
        weapon_amount++;
    }
    void subamount()
    {
        weapon_amount--;
    }
    int getamount(){
        return this->weapon_amount;
    }

   // void save();

private:
    Weapon w1,w2,w3;
    vector<Weapon> _weapons;
    vector<Rpgobj> _objs;
    Player _player;
    Rival _rival;
    int weapon_amount=0;
    bool battle = 0;
    bool ifweapon = 0;
    static int rivalFlag;
};

#endif // WORLD_H
