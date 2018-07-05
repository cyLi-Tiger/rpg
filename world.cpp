#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <fstream>
#include <iostream>
#include <QImage>
#include <QPainter>
#include <map>
#include "container.h"
#include<stdlib.h>
#include <math.h>
#include <QTime>

#define Random(x) (rand() % x)
using namespace std;
extern fstream write;
extern fstream error;
int World::rivalFlag=0;
int World::flagg = 0;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    fstream map;
    string icon_name;
    int x,y;
    map.open(mapFile.c_str(),ios::in);
    if(map.is_open()){
        map>>icon_name>>x>>y;
        this->_player.iniplayer("s1");
        this->_player.setPosX(x);
        this->_player.setPosY(y);  //首先初始化玩家信息
        map.close();
        _player.setHP_now(200);
        _player.setMP_now(200);
        _monster.setHP_now(200);
    }
    Bet_animal tmp;
    tmp.setPosX(2);
    for(int i=0;i<4;i++){
        tmp.setPosY(15*i+5);
        this->_betanimals.push_back(tmp);
    }

}

void World::moving(){
    int x=_monster.getPosX();
    int y=_monster.getPosY();
    int _x=_player.getPosX()*10;
    int _y=_player.getPosY()*10;
    double sinn=((int)fabs(y-_y*10)*100)/sqrt((x-_x*10)*(x-_x*10)+(y-_y*10)*(y-_y*10))/100.000;
    double coss=((int)fabs(x-_x*10)*100)/sqrt((x-_x*10)*(x-_x*10)+(y-_y*10)*(y-_y*10))/100.000;
    if(x+80>=_x+24&&y+80>=_y+24)
    {
        _monster.setPosX(x-3*coss);
        _monster.setPosY(y-3*sinn);
    }
    else if(x+80>=_x+24&&y+80<=_y+24)
    {
        _monster.setPosX(x-3*coss);
        _monster.setPosY(y+3*sinn);
    }
    else if(x+80<=_x+24&&y+80<=_y+24)
    {
        _monster.setPosX(x+3*coss);
        _monster.setPosY(y+3*sinn);
    }
    else if(x+80<=_x+24&&y+80>=_y+24)
    {
        _monster.setPosX(x+3*coss);
        _monster.setPosY(y-3*sinn);
    }
}

void World::showblood(QPainter *painter){

    double sumhp=200;
    double width1 = _player.getHP_now()/sumhp;
    double width2 = _player.getMP_now()/sumhp;
    double width3 = _monster.getHP_now()/sumhp;
    if(_player.getHP_now()>0)
    {   (*painter).setBrush(Qt::black);
        (*painter).drawRect(_player.getPosX()*10, _player.getPosY()*10-20,48,10);
        (*painter).drawRect(_player.getPosX()*10, _player.getPosY()*10-10,48,10);
        (*painter).setBrush(Qt::red);
        (*painter).drawRect(_player.getPosX()*10, _player.getPosY()*10-20,width1*48,10);
        (*painter).setBrush(Qt::blue);
        (*painter).drawRect(_player.getPosX()*10, _player.getPosY()*10-10,width2*48,10);
    }
    if(_monster.getHP_now()>0)
    {
        (*painter).setBrush(Qt::black);
        (*painter).drawRect(_monster.getPosX(), _monster.getPosY()-20,150,10);
        (*painter).setBrush(Qt::red);
        (*painter).drawRect(_monster.getPosX(), _monster.getPosY()-20,width3*150,10);
    }
    else
        pass=true;
}

void World::showdq(QPainter *painter){
    if(dq%25==0)
        _dq.inidq("dq2");
    else if(dq%25==1)
        _dq.inidq("dq2");
    else if(dq%25==2)
        _dq.inidq("dq3");
    else if(dq%25==3)
        _dq.inidq("dq4");
    else if(dq%25==4)
        _dq.inidq("dq5");
    else if(dq%25==5)
        _dq.inidq("dq6");
    else if(dq%25==6)
        _dq.inidq("dq7");
    else if(dq%25==7)
        _dq.inidq("dq8");
    else if(dq%25==8)
        _dq.inidq("dq9");
    else if(dq%25==9)
        _dq.inidq("dq10");
    else if(dq%25==10)
        _dq.inidq("dq11");
    else if(dq%25==11)
        _dq.inidq("dq12");
    else if(dq%25==12)
        _dq.inidq("dq13");
    else if(dq%25==13)
        _dq.inidq("dq14");
    else if(dq%25==14)
        _dq.inidq("dq15");
    else if(dq%25==15)
        _dq.inidq("dq16");
    else if(dq%25==16)
        _dq.inidq("dq17");
    else if(dq%25==17)
        _dq.inidq("dq18");
    else if(dq%25==18)
        _dq.inidq("dq19");
    else if(dq%25==19)
        _dq.inidq("dq20");
    else if(dq%25==20)
        _dq.inidq("dq21");
    else if(dq%25==21)
        _dq.inidq("dq22");
    else if(dq%25==22)
        _dq.inidq("dq23");
    else if(dq%25==23)
        _dq.inidq("dq24");
    else if(dq%25==24)
        _dq.inidq("dq25");
    if(dq==25)
    ifshowdq=false;
    if(ifshowdq==true)
    _dq.showdq(painter);
}

void World::showsao(QPainter *painter){
    _saoo.inisao("mon1");
    if(sao%25==0)
        _sao.inisao("mon2");
    else if(sao%25==1)
        _sao.inisao("mon2");
    else if(sao%25==2)
        _sao.inisao("mon3");
    else if(sao%25==3)
        _sao.inisao("mon4");
    else if(sao%25==4)
        _sao.inisao("mon5");
    else if(sao%25==5)
        _sao.inisao("mon6");
    else if(sao%25==6)
        _sao.inisao("mon7");
    else if(sao%25==7)
        _sao.inisao("mon8");
    else if(sao%25==8)
        _sao.inisao("mon9");
    else if(sao%25==9)
        _sao.inisao("mon10");
    else if(sao%25==10)
        _sao.inisao("mon11");
    else if(sao%25==12)
        _sao.inisao("mon13");
    else if(sao%25==13)
        _sao.inisao("mon14");
    else if(sao%25==14)
        _sao.inisao("mon15");
    else if(sao%25==15)
        _sao.inisao("mon16");
    else if(sao%25==16)
        _sao.inisao("mon17");
    else if(sao%25==17)
        _sao.inisao("mon18");
    else if(sao%25==18)
        _sao.inisao("mon19");
    else if(sao%25==19)
        _sao.inisao("mon20");
    else if(sao%25==20)
        _sao.inisao("mon21");
    else if(sao%25==21)
        _sao.inisao("mon22");
    else if(sao%25==22)
        _sao.inisao("mon23");
    else if(sao%25==23)
        _sao.inisao("mon24");
    else if(sao%25==24)
        _sao.inisao("mon25");
    if(sao==25)
    {
        ifshowsao=false;
    }
    _sao.showsao(painter);
    _saoo.showsao(painter);
}

void World::showbullet(QPainter *painter){
    if(fire==1)
    {
        _bullet.inibullet("bullet");
        _bullet.showbullet(painter);
    }

}

void World::showtunnell(QPainter *painter){
    if(tun%6==0)
        _tunnell.initunnel("tun1");
    else if(tun%6==1)
        _tunnell.initunnel("tun2");
    else if(tun%6==2)
        _tunnell.initunnel("tun3");
    else if(tun%6==3)
        _tunnell.initunnel("tun4");
    else if(tun%6==4)
        _tunnell.initunnel("tun5");
    else if(tun%6==5)
        _tunnell.initunnel("tun6");
    _tunnell.showtunnel(painter);
}

void World::showtunnel(QPainter *painter){
    if(tun%6==0)
        _tunnel.initunnel("tun1");
    else if(tun%6==1)
        _tunnel.initunnel("tun2");
    else if(tun%6==2)
        _tunnel.initunnel("tun3");
    else if(tun%6==3)
        _tunnel.initunnel("tun4");
    else if(tun%6==4)
        _tunnel.initunnel("tun5");
    else if(tun%6==5)
        _tunnel.initunnel("tun6");
    _tunnel.showtunnel(painter);
}

void World::show(QPainter * painter){
    fstream map;
    map.open("C:\\Users\\lenovo\\Desktop\\crazyA\\crazyA\\world.txt",ios::out);
    if(map.is_open())
    {
    if(save==0)
    map<<"player"<<" "<<50<<" "<<55<<endl;
    else
    map<<"player"<<" "<<_player.getPosX()<<" "<<_player.getPosY()<<endl;
    }
    if(flagg==1)
    {
        if(_player.getw()%3==0)
        _player.iniplayer("w1");
        else if(_player.getw()%3==1)
        _player.iniplayer("w2");
        else if(_player.getw()%3==2)
        _player.iniplayer("w3");
    }
    else if(flagg==2)
    {
        if(_player.geta()%3==0)
        _player.iniplayer("a1");
        else if(_player.geta()%3==1)
        _player.iniplayer("a2");
        else if(_player.geta()%3==2)
        _player.iniplayer("a3");
    }
    else if(flagg==3)
    {
        if(_player.gets()%3==0)
        _player.iniplayer("s1");
        else if(_player.gets()%3==1)
        _player.iniplayer("s2");
        else if(_player.gets()%3==2)
        _player.iniplayer("s3");
    }
    else if(flagg==4)
    {
        if(_player.getd()%3==0)
        _player.iniplayer("d1");
        else if(_player.getd()%3==1)
        _player.iniplayer("d2");
        else if(_player.getd()%3==2)
        _player.iniplayer("d3");
    }
    _player.showplayer(painter);
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

void World::initContainer(){
    Container cons;
    cons.initObj("heal");
    cons.setPosX(100);
    cons.setPosY(100);
    this->_containers.push_back(cons);
}

void World::handlePlayerMove(int _x, int _y){  //direction =1,2,3,4 for 上下左右

    _player.move(_x,_y);
}

void World::showheal()
{
    if((_player.getPosX()+1==w1.getPosX())&&(_player.getPosY()+1==w1.getPosY()))
    {
        if(con.getnum()-1>0){
            _containers[con.getnum()].canuse=false;
            con.num--;
        }
        else if(con.getnum()==0)
            _player.showstate();
    }
    if((_player.getPosX()+1==w2.getPosX()) && (_player.getPosY()+1==w2.getPosY()))
    {
        if(con.getnum()-1>0){
            _containers[con.getnum()].canuse=false;
            con.num--;
        }
       else if(con.getnum()==0)
           _player.showstate();
    }
    if( (_player.getPosX()+1==w3.getPosX()) && (_player.getPosY()+1==w3.getPosY()))
    {
        if(con.getnum()-1>0){
            _containers[con.getnum()].canuse=false;
            con.num--;
        }
        else if(con.getnum()==0)
           _player.showstate();
    }
}

void World::showBet(QPainter *painter)
{
    vector<Bet_animal>::iterator it = this->_betanimals.begin();
        for(int i=0; i<4 ; ++it , i++)
        {
            (*it).automove();
            if(i==1)
            {
                for(int j=0;j<3;j++)
                {
                    (*it).automove();
                }
            }
            if((*it).getPosX()>86) //判断胜利条件
            {
                setbetflag(0);
                vector<Bet_animal>::iterator itt= this->_betanimals.begin();
                for(; itt != this->_betanimals.end(); ++itt) (*itt).setPosX(2);
                if(i+1 == getbetwinNum()) setifWin(1);
                else  setifWin(2);
                setifBet(0);
                return ;
            }
            int tmp = (*it).getstate() % 3;
            switch (tmp) {
            case 0:
               (*it).initbet("bet1");
                break;
            case 1:
               (*it).initbet("bet2");
                break;
            case 2:
               (*it).initbet("bet3");
                break;
            default:
                break;
            }
            (*it).addstate();
            (*it).showplayer(painter);
        }
        return ;
}

void World::showBag(QPainter *painter)
{
    Rpgobj tmp;
    tmp.initprop("HP");
    tmp.setPosY(13);
    for(int i=0;i<_player.getHPNum();i++){
        tmp.setPosX(10.5*i+12.5);
        this->_HPprops.push_back(tmp);
    }
    tmp.initprop("MP");
    tmp.setPosY(26);
    for(int i=0;i<_player.getMPNum();i++){
        tmp.setPosX(10.5*i+12.5);
        this->_MPprops.push_back(tmp);
    }
    tmp.initprop("money");
    tmp.setPosY(39);
    for(int i=0;i<_player.getMoney();i++){
        tmp.setPosX(10.5*i+12.5);
        this->_Moneyprops.push_back(tmp);
    }
    vector<Rpgobj>::iterator it;
    int i=0;
    for(it=this->_HPprops.begin();i<_player.getHPNum();i++,++it){
        if(it!=this->_HPprops.end()) (*it).showplayer(painter);
        else break;
    }
    for(it=this->_MPprops.begin(),i=0;i<_player.getMPNum();i++,++it){
        if(it!=this->_MPprops.end()) (*it).showplayer(painter);
        else break;
    }
    for(it=this->_Moneyprops.begin(),i=0;i<_player.getMoney();i++,++it){
        if(it!=this->_Moneyprops.end()) (*it).showplayer(painter);
        else break;
    }
    //_HPprops.clear();
    //_MPprops.clear();
}
