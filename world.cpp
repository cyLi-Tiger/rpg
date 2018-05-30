#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <fstream>
#include <iostream>
using namespace std;
extern fstream write;
extern fstream error;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    fstream map;
    string icon_name;
    int x,y;
    map.open(mapFile.c_str(),ios::in);
    if(map.is_open()){
        map>>icon_name>>x>>y;
        this->_player.initObj(icon_name);
        this->_player.setPosX(5);
        this->_player.setPosY(5);  //首先初始化玩家信息

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
}

void World::show(QPainter * painter){
    vector<Rpgobj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();++it){
        (*it).show(painter);
    }
    //this->_player.show(painter);
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
