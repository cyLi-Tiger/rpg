#include "icon.h"
#include<iostream>
#include <fstream>

extern fstream error;

int ICON::GRID_SIZE1 = 32;
int ICON::GRID_SIZE2 = 48;
int ICON::GRID_SIZE3 = 192;

pair<string,ICON> pairArray[] =//定义符号名字，截取图像
{
    make_pair("player",ICON("player",1,13, 1,2)),
    make_pair("rival",ICON("rival",8,12,1,2)),
    make_pair("stone",ICON("stone",4,9, 1,1)),
    make_pair("flower",ICON("flower",3,6, 1,1)),
    make_pair("ground",ICON("ground",5,0, 1,1)),
    make_pair("plant",ICON("plant",4,6, 1,1)),
    make_pair("grave",ICON("grave",6,9, 1,1)),
    make_pair("weapon",ICON("weapon",5,11,1,1)),

    make_pair("a1",ICON("a1",6,5,1,1)),
    make_pair("a2",ICON("a2",7,5,1,1)),
    make_pair("a3",ICON("a3",8,5,1,1)),
    make_pair("d1",ICON("d1",6,6,1,1)),
    make_pair("d2",ICON("d2",7,6,1,1)),
    make_pair("d3",ICON("d3",8,6,1,1)),
    make_pair("w1",ICON("w1",6,7,1,1)),
    make_pair("w2",ICON("w2",7,7,1,1)),
    make_pair("w3",ICON("w3",8,7,1,1)),
    make_pair("s1",ICON("s1",6,4,1,1)),
    make_pair("s2",ICON("s2",7,4,1,1)),
    make_pair("s3",ICON("s3",8,4,1,1)),

    make_pair("mon1",ICON("mon1",0,0,1,1)),
    make_pair("mon2",ICON("mon2",1,0,1,1)),
    make_pair("mon3",ICON("mon3",2,0,1,1)),
    make_pair("mon4",ICON("mon4",3,0,1,1)),
    make_pair("mon5",ICON("mon5",4,0,1,1)),
    make_pair("mon6",ICON("mon6",0,1,1,1)),
    make_pair("mon7",ICON("mon7",1,1,1,1)),
    make_pair("mon8",ICON("mon8",2,1,1,1)),
    make_pair("mon9",ICON("mon9",3,1,1,1)),
    make_pair("mon10",ICON("mon10",4,1,1,1)),
    make_pair("mon11",ICON("mon11",0,2,1,1)),
    make_pair("mon12",ICON("mon12",1,2,1,1)),
    make_pair("mon13",ICON("mon13",2,2,1,1)),
    make_pair("mon14",ICON("mon14",3,2,1,1)),
    make_pair("mon15",ICON("mon15",4,2,1,1)),
    make_pair("mon16",ICON("mon16",0,3,1,1)),
    make_pair("mon17",ICON("mon17",1,3,1,1)),
    make_pair("mon18",ICON("mon18",2,3,1,1)),
    make_pair("mon19",ICON("mon19",3,3,1,1)),
    make_pair("mon20",ICON("mon20",4,3,1,1)),
    make_pair("mon21",ICON("mon21",0,4,1,1)),
    make_pair("mon22",ICON("mon22",1,4,1,1)),
    make_pair("mon23",ICON("mon23",2,4,1,1)),
    make_pair("mon24",ICON("mon24",3,4,1,1)),
    make_pair("mon25",ICON("mon25",4,4,1,1)),

    make_pair("bullet",ICON("bullet",454,116,54,45)),

    make_pair("blue",ICON("blue",6,12,1,1)),
    make_pair("red",ICON("red",7,12,1,1)),

    make_pair("bet1",ICON("bet1",0,6,1,1)),
    make_pair("bet2",ICON("bet2",1,6,1,1)),
    make_pair("bet3",ICON("bet3",2,6,1,1)),

    make_pair("HP",ICON("HP",7,12,1,1)),
    make_pair("MP",ICON("MP",6,12,1,1)),
    make_pair("money",ICON("money",1,12,1,1)),

    make_pair("tun1",ICON("tun1",0,3,1,1)),
    make_pair("tun2",ICON("tun2",1,3,1,1)),
    make_pair("tun3",ICON("tun3",2,3,1,1)),
    make_pair("tun4",ICON("tun4",3,3,1,1)),
    make_pair("tun5",ICON("tun5",4,3,1,1)),
    make_pair("tun6",ICON("tun6",5,3,1,1)),

    make_pair("dq1",ICON("dq1",0,0,1,1)),
    make_pair("dq2",ICON("dq2",1,0,1,1)),
    make_pair("dq3",ICON("dq3",2,0,1,1)),
    make_pair("dq4",ICON("dq4",3,0,1,1)),
    make_pair("dq5",ICON("dq5",4,0,1,1)),
    make_pair("dq6",ICON("dq6",0,1,1,1)),
    make_pair("dq7",ICON("dq7",1,1,1,1)),
    make_pair("dq8",ICON("dq8",2,1,1,1)),
    make_pair("dq9",ICON("dq9",3,1,1,1)),
    make_pair("dq10",ICON("dq10",4,1,1,1)),
    make_pair("dq11",ICON("dq11",0,2,1,1)),
    make_pair("dq12",ICON("dq12",1,2,1,1)),
    make_pair("dq13",ICON("dq13",2,2,1,1)),
    make_pair("dq14",ICON("dq14",3,2,1,1)),
    make_pair("dq15",ICON("dq15",4,2,1,1)),
    make_pair("dq16",ICON("dq16",0,3,1,1)),
    make_pair("dq17",ICON("dq17",1,3,1,1)),
    make_pair("dq18",ICON("dq18",2,3,1,1)),
    make_pair("dq19",ICON("dq19",3,3,1,1)),
    make_pair("dq20",ICON("dq20",4,3,1,1)),
    make_pair("dq21",ICON("dq21",0,4,1,1)),
    make_pair("dq22",ICON("dq22",1,4,1,1)),
    make_pair("dq23",ICON("dq23",2,4,1,1)),
    make_pair("dq24",ICON("dq24",3,4,1,1)),
    make_pair("dq25",ICON("dq25",4,4,1,1)),

    make_pair("grandma",ICON("grandma",9,4,1,1)),
    make_pair("boss1",ICON("boss1",1,4,1,1)),
    make_pair("boss2",ICON("boss2",1,0,1,1)),
    make_pair("boss3",ICON("boss3",4,0,1,1))
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
        error.open("C:\\Users\\lenovo\\Desktop\\crazyA\\crazyA\\error.txt",ios::app);
        error<<"Error:invalid ICON type!!!"<<endl;
        error.close();
       return ICON();
    }
    else{
        return kv->second;
    }
}
