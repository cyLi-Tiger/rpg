#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include <math.h>
#include "player.h"
#include "rival.h"
#include "container.h"
#include "weapon.h"
#include "npc.h"
#include "monster.h"
#include "bet_animal.h"
#include "elf.h"
class World
{
public:
    friend class MainWindow;
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
    void initContainer();
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void showbullet(QPainter *painter);
    void showtunnel(QPainter *painter);
    void showtunnell(QPainter *painter);
    void showmonster(QPainter *painter);
    void showblood(QPainter *painter);
    void showsao(QPainter *painter);
    void showdq(QPainter *painter);
    void moving();
    void handlePlayerMove(int _x, int _y);
    void rivalWeapon(QPainter *painter);
    int getsave()
    {
        return save;
    }
    void setsave(int k)
    {
        save=k;
    }
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

    void showheal();
    void showheal1();

    int getflagg(){
        return flagg;
    }
    void setflagg(int k){
        flagg=k;
    }
    void settun(int k){
        tun=k;
    }
    int gettun(){
        return tun;
    }
    void setfire(int k){
        fire=k;
    }
    int getfire(){
        return fire;
    }
    int getsao(){
        return sao;
    }
    void setsao(int k){
        sao=k;
    }
    bool getifshowsao()
    {
        return ifshowsao;
    }
    void setifshowsao( bool k){
        ifshowsao=k;
    }
    bool getpass(){
        return pass;
    }
    void setpass(bool k){
        pass=k;
    }

    int ifclose()
    {
        return _npc.ifnpcclose(_player.getPosX()*10,_player.getPosY()*10);
    }

    bool getBag()
    {
        return bag;
    }
    void setBag(int k)
    {
        bag=k;
    }

    void setChess(bool x){
        chess = x;
    }
    bool getChess(){
        return this->chess;
    }
    void setbetflag(bool x){
        betflag = x;
    }
    bool getbetflag(){
        return betflag;
    }
    void setbetwinNum(int x){
        betwinNum = x;
    }
    int getbetwinNum(){
        return betwinNum;
    }
    bool getturn(){
        return turn;
    }
    void setturn(bool k){
        turn=k;
    }
    int getdq(){
        return dq;
    }
    void setdq(int k){
        dq=k;
    }
    bool getifshowdq(){
        return ifshowdq;
    }
    void setifshowdq(bool k){
        ifshowdq=k;
    }
    void setifBet(bool x)
    {
        ifBet=x;
    }
    bool getifBet()
    {
        return this->ifBet;
    }
    void setifWin(int x)
    {
        ifwin = x;
    }
    int getifWin()
    {
        return this->ifwin;
    }
    void setflyWin(bool x)
    {
        flyWin = x;
    }
    bool getflyWin()
    {
        return this->flyWin;
    }
    void setifshop(bool x)
    {
        ifshop = x;
    }
    bool getifshop()
    {
        return this->ifshop;
    }

    void showBag(QPainter *painter);
    void showBet(QPainter *painter);
private:
    Weapon w1,w2,w3;
    vector<Weapon> _weapons;
    vector<Rpgobj> _objs;
    //红药和蓝药
    vector<Rpgobj> _HPprops;
    vector<Rpgobj> _MPprops;
    vector<Rpgobj> _Moneyprops;

    vector<Container> _containers;
    vector<Bet_animal> _betanimals;
    Player _player;
    Rival _rival;
    bool ifBet = 0;
    bool ifshop = 0;
    int ifwin = 0;
    bool betflag=0;
    bool bag=0;
    bool chess=0;
    bool flyWin=0;
    int betwinNum = 0;

    int weapon_amount=0;
    bool battle = 0;
    bool ifweapon = 0;
    Container con;
    static int rivalFlag;
    int save = 0;
    static int flagg;
    Rpgobj _bullet;
    Rpgobj _tunnel;
    Rpgobj _tunnell;
    //Rpgobj _npc;
    Rpgobj _sao;
    Rpgobj _saoo;
    Monster _monster;
    int tun=1;
    int fire=0;
    int sao;
    bool ifshowsao=false;
    bool pass = false;
    Npc _npc;
    Elf _elf;
    bool turn=false;
    Rpgobj _dq;
    int dq=0;
    bool ifshowdq=false;
};

#endif // WORLD_H
