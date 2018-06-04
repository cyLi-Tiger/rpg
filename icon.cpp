#include "icon.h"
#include<iostream>
#include <fstream>

extern fstream error;

int ICON::GRID_SIZE = 32;


pair<string,ICON> pairArray[] =//定义符号名字，截取图像
{
    make_pair("player",ICON("player",1,13, 1,2)),
    make_pair("rival",ICON("rival",8,12,1,2)),
    make_pair("stone",ICON("stone",4,9, 1,1)),
    make_pair("flower",ICON("flower",3,6, 1,1)),
    make_pair("ground",ICON("ground",5,0, 1,1)),
    make_pair("plant",ICON("plant",4,6, 1,1)),
    make_pair("grave",ICON("grave",6,9, 1,1)),
    make_pair("weapon",ICON("weapon",5,11,1,1))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){
        error.open("/Users/air/desktop/error.txt",ios::app);
        error<<"Error:invalid ICON type!!!"<<endl;
        error.close();
       return ICON();
    }
    else{
        return kv->second;
    }
}
