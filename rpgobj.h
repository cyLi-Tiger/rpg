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
    void show(QPainter * painter);

    void showinfo();

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void subtractHP(int HP_harm);
    void subtractMP(int MP_reduction);

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}

    int getHP_now() const{return this->HP_now;}
    int getMP_now() const{return this->MP_now;}
    int getatk() const{return this->atk;}
    int getHP_max() const{return this->HP_max;}
    int getMP_max() const{return this->MP_max;}
    int getHP_recover() const{return this->HP_recover;}
    int getMP_recover() const {return this->MP_recover;}

    int getnormal_skill() const{return this->normal_skill;}//normal skill指的是该攻击造成的伤害
    int getmaster_skill() const{return this->master_skill;}
    int getultimate_skill() const{return this->ultimate_skill;}
    int getheal_skill() const{return this->heal_skill;}
    int getms_MP_reduction() const{return this->ms_MP_reduction;}
    int getus_MP_reduction() const{return this->us_MP_reduction;}
    int geths_MP_reduction() const{return this->hs_MP_reduction;}
    string getObjType() const{return this->_icon.getTypeName();}//返回类名
protected:
    QImage _pic;
    int _pos_x = 0, _pos_y= 0;//该物体在游戏中当前位置（左上角坐标）
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息

    // the basic information of the role
    int HP_now;
    int HP_max;//HP

    int MP_now;
    int MP_max;//MP
    int atk;//ATTACK

    int HP_recover;
    int MP_recover;

    //the skill of the role;
    int normal_skill;
    int master_skill;
    int ms_MP_reduction;
    int ultimate_skill;//the skill can kill the rival;
    int us_MP_reduction;
    int heal_skill;//the skill can help the player add the HP;
    int hs_MP_reduction;

    //Container con;
    //Elf elf;
};

#endif // RPGOBJ_H
