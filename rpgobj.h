#ifndef RPGOBJ_H
#define RPGOBJ_H
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>
using namespace std;

class Rpgobj
{
public:
    Rpgobj(){}
    void initObj(string type);
    void iniplayer(string type);
    void inisao(string type);
    void inibullet(string type);
    void initbet(string type);
    void initprop(string type);
    void initunnel(string type);
    void ininpc(string type);
    void inidq(string type);

    void show(QPainter * painter);
    void showplayer(QPainter *painter);
    void showsao(QPainter *painter);
    void showbullet(QPainter *painter);
    void showprop(QPainter *painter);
    void showtunnel(QPainter *painter);
    void showdq(QPainter *painter);

    void showinfo(QPainter *painter);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void subtractHP(int HP_harm);
    void subtractMP(int MP_reduction);

    int getPosX() {return this->_pos_x;}
    int getPosY() {return this->_pos_y;}
    int getHeight() {return this->_icon.getHeight();}
    int getWidth() {return this->_icon.getWidth();}

    int getHP_now() const{return this->HP_now;}
    int getMP_now() const{return this->MP_now;}
    int getHP_max() const{return this->HP_max;}
    int getMP_max() const{return this->MP_max;}
    int getHP_recover() const{return this->HP_recover;}
    int getMP_recover() const {return this->MP_recover;}

    void setHP_now(int k){
        HP_now=k;
    }
    void setMP_now(int k){
        MP_now=k;
    }

    int getnormal_skill() const{return this->normal_skill;}//normal skill指的是该攻击造成的伤害
    int getmaster_skill() const{return this->master_skill;}
    int getheal_skill() const{return this->heal_skill;}
    string getObjType() const{return this->_icon.getTypeName();}//返回类名
protected:
    QImage _pic;
    int _pos_x = 0, _pos_y= 0;//该物体在游戏中当前位置（左上角坐标）
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息

    // the basic information of the role
    int HP_now;
    int HP_max=200;//HP

    int MP_now;
    int MP_max=200;//MP

    int HP_recover;
    int MP_recover;

    int normal_skill=20;
    int master_skill=50;
    int ultimate_skill;//the skill can kill the rival;
    int heal_skill;//the skill can help the player add the HP;

    //Container con;
    //Elf elf;
};

#endif // RPGOBJ_H
