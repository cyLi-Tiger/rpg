#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <fstream>
#include <iostream>
#include <QImage>
#include <QPainter>
#include <map>
#include<stdlib.h>
#include <math.h>
#define Random(x) (rand() % x)
using namespace std;
extern fstream write;
extern fstream error;
int World::rivalFlag=0;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    fstream map;
    string icon_name;
    int x,y;
    map.open(mapFile.c_str(),ios::in);
    if(map.is_open()){
        map>>icon_name>>x>>y;
        this->_player.initObj(icon_name);
        this->_player.setPosX(x);
        this->_player.setPosY(y);  //首先初始化玩家信息

        map>>icon_name;
        while(icon_name!="EOF"){
            Rpgobj obj;
            map>>x>>y;
            obj.initObj(icon_name);
            obj.setPosX(x);
            obj.setPosY(y);      //初始化其余画面信息
            this->_objs.push_back(obj);
            map>>icon_name;
        }

        map.close();
    }
    else{   //出现错误记入错误日志中
        error.open("/Users/air/desktop/error.txt",ios::out);
        error<<"Error:cannot open map file!!!";
        error.close();
    }
    this->_rival.initObj("rival");
    this->_rival.setPosX(10);
    this->_rival.setPosY(10);
    w1.initObj("weapon");
    w2.initObj("weapon");
    w3.initObj("weapon");
}

void World::show(QPainter * painter){
    if(battle == 0)
    {
        vector<Rpgobj>::iterator it;
        for(it=this->_objs.begin();it!=this->_objs.end();++it)
        {
            (*it).show(painter);
        }
        this->_player.show(painter);

        for(int i=0;i<15;i++){
            if(_rival.getPosX()==_player.getPosX() && _rival.getPosY()==_player.getPosY()){
                setBattle(1);
                _rival.setPosX(20);
                _rival.setPosY(10);
                break;
            }
            else _rival.move();
        }
        return;
    }
    if(battle == 1) {
        _rival.shortestdis(_player.getPosX(),_player.getPosY());
        this->_player.show(painter);
        this->_rival.show(painter);
        if(getIfweapon() == 1)
        {
            vector<Weapon>::iterator it = this->_weapons.begin()+1;
            //int Flag=0;
            for(int i=1;i<getamount();i++)
            {
                (*it).automove();
                //判断weapon消失条件
                if((*it).getPosX()>24)
                {
                    (*it).setstate(0);
                   // Flag++;
                }
                //是否显示weapon
                if((*it).getstate() == 1)
                {
                    (*it).show(painter);
                }
                it++;
            }
            //for(int i=0;i<Flag;i++) subamount();
            //to be polished vector的插入。
        }    
        rivalWeapon(painter);
        return;
    }

}
void World::rivalWeapon(QPainter *painter)
{
    if(rivalFlag == 0)
    {
        w1.setPosX(_rival.getPosX());
        w1.setPosY(_rival.getPosY()+1);
        w1.show(painter);
        rivalFlag = 1;
    }
    else if(rivalFlag == 1)
    {
        w1.autoRivalmove();
        w1.show(painter);
        w2.setPosX(_rival.getPosX());
        w2.setPosY(_rival.getPosY()+1);
        w2.show(painter);
        rivalFlag = 2;
    }
    else if(rivalFlag == 2)
    {
        w1.autoRivalmove();
        w2.autoRivalmove();
        w1.show(painter);
        w2.show(painter);
        w3.setPosX(_rival.getPosX());
        w3.setPosY(_rival.getPosY()+1);
        w3.show(painter);
        rivalFlag = 3;
    }
    else if(rivalFlag == 3)
    {
        w1.autoRivalmove();
        w2.autoRivalmove();
        w3.autoRivalmove();
        if(w1.getPosX()<0) {w1.setPosX(_rival.getPosX());w1.setPosY(_rival.getPosY()+1);}
        if(w2.getPosX()<0) {w2.setPosX(_rival.getPosX());w2.setPosY(_rival.getPosY()+1);}
        if(w3.getPosX()<0) {w3.setPosX(_rival.getPosX());w3.setPosY(_rival.getPosY()+1);}
        w1.show(painter);
        w2.show(painter);
        w3.show(painter);
    }
}

void World::initWeapon()
{
    Weapon wea;
    wea.initObj("weapon");
    wea.setPosX(_player.getPosX());
    wea.setPosY(_player.getPosY()+1);
    wea.setstate(1);
    this->_weapons.push_back(wea);
}

void World::handlePlayerMove(int _x, int _y){//direction =1,2,3,4 for 上下左右
       this ->_player.move(_x, _y);
       return;
}


















/*void World::save(){
    write.open("C:\\Users\\123213\\Desktop\\map.txt",ios::trunc);
    write<<_player.getObjType()<<" "<<_player.getPosX()<<" "<<_player.getPosY()<<endl;
    vector<RPGObj>::iterator it = _objs.begin();
    for(;it!=_objs.end();++it){
        write<<(*it).getPosX()<<" "<<(*it).getPosY()<<endl;
    }
    vector<monster>::iterator itt = _monsters.begin();
    for(;itt!=_monsters.end();++itt){
        write<<(*itt).getPosX()<<" "<<(*itt).getPosY()<<endl;
    }
    write.close();
}*/
