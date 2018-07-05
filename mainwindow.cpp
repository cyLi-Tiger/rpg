#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "icon.h"
#include <map>
#include <iostream>
#include <QTextStream>
#include <fstream>
#include <QTimer>
#include <cmath>
#include <QPainter>
#include <QTimer>
#include <QSound>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <math.h>

using namespace std;

extern fstream error;
extern bool man;

// -------全局遍历-------//
#define CHESS_ONE_SOUND ":/res/sound/chessone.wav"
#define WIN_SOUND ":/res/sound/win.wav"
#define LOSE_SOUND ":/res/sound/lose.wav"

const int kBoardMargin = 100; // 棋盘边缘空隙
const int kRadius = 30; // 棋子半径
const int kMarkSize = 12; // 落子标记边长
const int kBlockSize = 100; // 格子的大小
const int kPosDelta = 30; // 鼠标点击的模糊距离上限

const int kAIDelay = 700; // AI下棋的思考时间

// -------------------- //

int MainWindow::showdialog=0;
//int MainWindow::change=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    _game.initWorld("C:\\Users\\lenovo\\Desktop\\crazyA\\crazyA\\world.txt");//TODO 应该是输入有效的地图文件
    //以下是对时钟的初始化
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updatetun()));//timeoutslot()为自定义槽
        //时钟事件与randomMove函数绑定
    timer->start(10);

    QTimer *timerbullet = new QTimer(this);
    connect(timerbullet,SIGNAL(timeout()),this,SLOT(updatebullet()));//timeoutslot()为自定义槽
    timerbullet->start(1);

    QTimer *timermonster = new QTimer(this);
    connect(timermonster,SIGNAL(timeout()),this,SLOT(updatemonster()));//timeoutslot()为自定义槽
    timermonster->start(100);

    QTimer *timerhurt = new QTimer(this);
    connect(timerhurt,SIGNAL(timeout()),this,SLOT(hurt()));//timeoutslot()为自定义槽
    timerhurt->start(1000);

    QTimer *timersao = new QTimer(this);
    connect(timersao,SIGNAL(timeout()),this,SLOT(updatesao()));//timeoutslot()为自定义槽
    timersao->start(100);
    
    QTimer *timerheal = new QTimer(this);
    connect(timerheal,SIGNAL(timeout()),this,SLOT(heal()));//timeoutslot()为自定义槽
    timerheal->start(100);

    QTimer *timerdq = new QTimer(this);
    connect(timerdq,SIGNAL(timeout()),this,SLOT(updatedq()));//timeoutslot()为自定义槽
    timerdq->start(100);
    
    setFixedSize(1000,650);

    //三子棋
    setMouseTracking(true);
    QAction *actionPVE = new QAction("Person VS Computer", this);
    connect(actionPVE, SIGNAL(triggered()), this, SLOT(initPVEGame()));
    // 开始游戏
    initGame();
}

MainWindow::~MainWindow()
{
    //delete ui;
    if (game)
    {
        delete game;
        game = nullptr;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    if(flag==-1)
    {
        if(e->button()==Qt::LeftButton)
        {
            if(e->globalX()<=1050&&e->globalX()>=880&&e->globalY()<=770&&e->globalY()>=705)
            {
                setflag(0);
                update();
            }
            if(e->pos().x()>=400&&e->pos().x()<=500&&e->pos().y()>=400&&pos().y()<=550)
            {
                setflag(-2);
                update();
            }
        }
    }
    if(flag==2||flag==4)
    {
        if(e->button()==Qt::LeftButton)
        {
            _game.setfire(1);
            update();
            int x=e->pos().x();
            int y=e->pos().y();
            int _x=_game._player.getPosX();
            int _y=_game._player.getPosY();
            double k=((int)(y-_y*10)*100/(x-_x*10))/100.000;
            kk=k;
            tmp=tiktok;
            m=_x;
            n=_y;
            sinn=((int)fabs(y-_y*10)*100)/sqrt((x-_x*10)*(x-_x*10)+(y-_y*10)*(y-_y*10))/100.000;
            coss=((int)fabs(x-_x*10)*100)/sqrt((x-_x*10)*(x-_x*10)+(y-_y*10)*(y-_y*10))/100.000;
            if(x>=_x*10)
            {
                way=1;
                _game.setfire(1);
            }
            else
            {
                way=-1;
                _game.setfire(1);
            }
        }

    }

}

void MainWindow::heal(){
    if(_game.getturn()==true)
    {
        if(_game._player.getHP_now()<200)
        _game._player.setHP_now(_game._player.getHP_now()+1);
        if(_game._player.getMP_now()<200)
        _game._player.setMP_now(_game._player.getMP_now()+1);
        update();
    }
}

void MainWindow::updatedq(){
    _game.setdq(_game.getdq()+1);
    update();
}

void MainWindow::updatesao(){
    _game.setsao(_game.getsao()+1);
    update();
}

void MainWindow::updatemonster(){
    _game.moving();
    update();
}

void MainWindow::updatetun(){
    _game.settun(_game.gettun()+1);
    update();
}

void MainWindow::updatebullet(){
    tiktok++;
    update();
}

void MainWindow::hurt(){
    if(ifhurt==true)
    {
        if(dis(_game._player.getPosX()*10+24,_game._monster.getPosX()+80,_game._player.getPosY()*10+24,_game._monster.getPosY()+80)<=200&&_game._player.getHP_now()>0&&_game._monster.getHP_now()>0)
        {
            _game._player.setHP_now(_game._player.getHP_now()-_game._player.getnormal_skill());
        }
        if(ifbullethurt==true)
        {
            if(dis(_game._bullet.getPosX(),_game._monster.getPosX()+80,_game._bullet.getPosY(),_game._monster.getPosY()+80)<=200&&_game._monster.getHP_now()>0)
            {
                _game._monster.setHP_now(_game._monster.getHP_now()-_game._player.getnormal_skill());
            }
        }
        if(_game._monster.getHP_now()<=0)
            _game.setpass(true);
    }
    update();
}

void MainWindow::paintEvent(QPaintEvent *e){
    heal();
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    if(flag == -2)
    {
        QImage image = QImage(":/PICS/family.png");
        (*pa).drawImage(rect(),image);
    }
    if(flag == -1)
    {
        QImage image = QImage(":/PICS/cover.png");
        (*pa).drawImage(rect(),image);
        QImage img1= QImage(":/PICS/start.png");
        (*pa).drawImage(430,480,img1);
        QImage img2= QImage(":/PICS/Peggy.png");
        (*pa).drawImage(450,400,img2);
    }
    if(flag == 0)
    {
        if(showdialog==0){
            QImage image= QImage(":/PICS/castle3.jpg");
            (*pa).drawImage(rect(),image);
        }
        if(showdialog==1){
            QImage image= QImage(":/PICS/dragon2.jpg");
            (*pa).drawImage(rect(),image);
        }
        if(showdialog==2){
            QImage image= QImage(":/PICS/king2.jpg");
            (*pa).drawImage(rect(),image);
        }
        if(showdialog==3){
            QImage image= QImage(":/PICS/courage2.jpg");
            (*pa).drawImage(rect(),image);
        }
        if(showdialog==4){
            QImage image= QImage(":/PICS/wisdom2.jpg");
            (*pa).drawImage(rect(),image);
        }
        if(showdialog==5){
            QImage image= QImage(":/PICS/lucky2.jpg");
            (*pa).drawImage(rect(),image);
        }
        if(showdialog==6){
            QImage image= QImage(":/PICS/questionplace.jpg");
            (*pa).drawImage(rect(),image);
            QImage ima1= QImage(":/PICS/in.jpg");
            (*pa).drawImage(0,480,ima1);
        }
        if(showdialog==7)
        {
            flag = 1;
        }
    }

    if(flag==1)//显示npc的地方（进入三个游戏）
    {
        QImage ima = QImage(":/PICS/npcplace.jpg");
        (*pa).drawImage(rect(),ima);
        _game._npc.ininpc("grandma");
        _game._npc.setPosX(760);
        _game._npc.setPosY(450);
        _game._npc.showtunnel(pa);
        _game.show(pa);
        QPainter painter(this);
        painter.setPen(Qt::white);
        painter.drawText(750, 520, QStringLiteral("商人"));

        _game._npc.ininpc("boss1");
        _game._npc.setPosX(30);
        _game._npc.setPosY(450);
        _game._npc.showtunnel(pa);
        _game.show(pa);
        painter.setPen(Qt::white);
        painter.drawText(20, 520, QStringLiteral("智慧长老"));

        _game._npc.ininpc("boss2");
        _game._npc.setPosX(760);
        _game._npc.setPosY(530);
        _game._npc.showtunnel(pa);
        _game.show(pa);
        painter.setPen(Qt::white);
        painter.drawText(750, 600, QStringLiteral("幸运长老"));

        _game._npc.ininpc("boss3");
        _game._npc.setPosX(30);
        _game._npc.setPosY(530);
        _game._npc.showtunnel(pa);
        _game.show(pa);
        painter.setPen(Qt::white);
        painter.drawText(20, 600, QStringLiteral("武力长老"));

        if(_game.ifclose()==1)//靠近商人
        {
                QImage img1= QImage(":/PICS/merchant.jpg");
                (*pa).drawImage(0,450,img1);
                QImage img2= QImage(":/PICS/Actor3.png");
                (*pa).drawImage(800,330,img2);
        }
        if(_game.ifclose()==2)//靠近智慧长老
        {
                QImage img1= QImage(":/PICS/wis.jpg");
                (*pa).drawImage(0,450,img1);
                QImage img2= QImage(":/PICS/Actor2.png");
                (*pa).drawImage(800,330,img2);

        }
        if(_game.ifclose()==3)//靠近幸运长老
        {
                QImage img1= QImage(":/PICS/luck.jpg");
                (*pa).drawImage(0,450,img1);
                QImage img2= QImage(":/PICS/Actor4.png");
                (*pa).drawImage(800,330,img2);

        }
        if(_game.ifclose()==4)//靠近武力长老
        {
                QImage img1= QImage(":/PICS/worrior.jpg");
                (*pa).drawImage(0,450,img1);
                QImage img2= QImage(":/PICS/Actor5.png");
                (*pa).drawImage(800,330,img2);
     //           showdialog=8;
        }
        if( _game.getChess()==1 )//show Chess(sanziqi)
        {
            QImage image = QImage(":/PICS/black.jpg");
            (*pa).drawImage(rect(),image);
            Sanziqi(pa);
        }
        if(_game.getbetflag() == 1 )//show race(bet)
        {
            QImage image = QImage(":/PICS/track.png");
            (*pa).drawImage(rect(),image);
            if(_game.getifBet()==0)
            {
                 QImage image = QImage(":/PICS/bet.jpg");
                 (*pa).drawImage(0,470,image);
            }
            else if(_game.getifBet() == 1) _game.showBet(pa);
            if(_game.getifWin() == 1)
            {
                 change1=true;
                 QString str;
                 str = "You";
                 QMessageBox::StandardButton btnValue = QMessageBox::information(this, "congratulations", str + " win!");
                 if (btnValue == QMessageBox::Ok)
                 {
                     Player::addMoney();
                     _game.setifWin(0);
                     _game.setbetwinNum(0);
                 }
            }
           if(_game.getifWin() == 2)
           {
                 change1=false;
                 QString str;
                 str = "You";
                 QMessageBox::StandardButton btnValue = QMessageBox::information(this, "congratulations", str + " lose!");
                 if (btnValue == QMessageBox::Ok)
                 {
                       _game.setifWin(0);
                       _game.setbetwinNum(0);
                 }
           }
        }
        if(_game.getBag() == 1)//show bag
        {
            QImage image = QImage(":/PICS/bagbackground.png");
            (*pa).drawImage(rect(),image);
            if(_game.getifshop() == 1)
            {
                QImage image = QImage(":/PICS/bagbackground.png");
                (*pa).drawImage(rect(),image);
                QImage ima1 = QImage(":/PICS/shop.jpg");
                (*pa).drawImage(0,480,ima1);
            }
            _game.showBag(pa);
        }
        if(change1==1 && change2==1 && change3==1)
        {
            _game._tunnel.setPosX(770);
            _game._tunnel.setPosY(500);
            _game.showtunnel(pa);
            if( (_game.ifclose()==5 ) && (_game.getpass()==true) )
            {
                flag=3;
                _game._player.setPosX(8);
                _game._player.setPosY(20);
                return;
            }
        }
    }

    if(_game.getflyWin() == 1 && flag == 2)//原本是battle场景
    {
        _game.setturn(false);
        ifhurt=true;
        if(ifinimonster == true)
        {
            _game._monster.setPosX(600);
            _game._monster.setPosY(400);
            ifinimonster = false;
        }
        QImage image = QImage(":/PICS/p0.jpg");
        (*pa).drawImage(rect(),image);
        if(_game._player.getHP_now()>0)
        _game.show(pa);
        if(_game._monster.getHP_now()>0)
        _game._monster.showmonster(pa);
        if(_game.getifshowsao()==true){
            _game.showsao(pa);
        }
        _game.showblood(pa);
        _game._tunnel.setPosX(770);
        _game._tunnel.setPosY(500);
        _game.showtunnel(pa);
        if(_game._player.getPosX()>=75&&_game._player.getPosX()<=77&&_game._player.getPosY()>=49&&_game._player.getPosY()<=52&&_game.getpass()==true)
        {
            if(_game.getpass()==true)
            flag=3;
            _game._player.setPosX(6);
            _game._player.setPosY(20);
            return;
        }

        if(_game.getfire()==1)
        {
            ifbullethurt=true;
            int p=tiktok;
            if(way==1)
            {
                if(kk>=0)
                {
                    _game._bullet.setPosX(m*10+20*coss*(p-tmp));
                    _game._bullet.setPosY(n*10+20*sinn*(p-tmp));
                }
                else
                {
                    _game._bullet.setPosX(m*10+20*coss*(p-tmp));
                    _game._bullet.setPosY(n*10-20*sinn*(p-tmp));
                }
            }
            else
            {
                if(kk>=0)
                {
                    _game._bullet.setPosX(m*10-20*coss*(p-tmp));
                    _game._bullet.setPosY(n*10-20*sinn*(p-tmp));
                }
                else
                {
                    _game._bullet.setPosX(m*10-20*coss*(p-tmp));
                    _game._bullet.setPosY(n*10+20*sinn*(p-tmp));
                }
            }
            _game.showbullet(pa);
            if(p-tmp==10)
            {
                _game.setfire(0);
                ifbullethurt =false;
            }
        }
        if(_game.getturn()==true)
        {
            _game._elf.setPosX(_game._player.getPosX());
            _game._elf.setPosY(_game._player.getPosY());
            _game._elf.showelf(pa);
        }
        if(_game._monster.getHP_now()<=0)
        {
            change2=true;
            QString str;
            str = "You";
            QMessageBox::StandardButton btnValue = QMessageBox::information(this, "congratulations", str + " win!");
            if (btnValue == QMessageBox::Ok)
            {
                _game._monster.setHP_now(200);
                _game.setflyWin(0);
                flag =1;
            }
        }
        if(_game._player.getHP_now()<=0)
        {
            change2=false;
            QString str;
            str = "You";
            QMessageBox::StandardButton btnValue = QMessageBox::information(this, "congratulations", str + " lose!");
            if (btnValue == QMessageBox::Ok)
            {
                _game._monster.setHP_now(200);
                _game.setflyWin(0);
                flag = 1;
            }
        }
    }

    if(flag == 3)//跟奶奶交谈的场景
    {
        _game.setturn(false);
        QImage image = QImage(":/PICS/pavement.png");
        (*pa).drawImage(rect(),image);

        _game._tunnel.setPosX(50);
        _game._tunnel.setPosY(200);
        _game.showtunnel(pa);

        _game._npc.ininpc("grandma");
        _game._npc.setPosX(770);
        _game._npc.setPosY(200);
        _game._npc.showtunnel(pa);
        _game.show(pa);

        if(_game.ifclose()==7)//靠近奶奶
        {
            if(showdialog==7)
            {
                QImage img1= QImage(":/PICS/granny1.jpg");
                (*pa).drawImage(0,480,img1);
                QImage img2= QImage(":/PICS/granny.png");
                (*pa).drawImage(770,400,img2);
            }
            if(showdialog==8)
            {
                 QImage img1= QImage(":/PICS/granny2.jpg");
                 (*pa).drawImage(0,480,img1);
                 QImage img2= QImage(":/PICS/me.png");
                 (*pa).drawImage(770,400,img2);
             }
            if(showdialog==9)
            {
                 QImage img1= QImage(":/PICS/granny3.jpg");
                 (*pa).drawImage(0,480,img1);
                 QImage img2= QImage(":/PICS/granny.png");
                 (*pa).drawImage(770,400,img2);
             }
         }
        if(showdialog==10)
        {
            _game._tunnell.setPosX(900);
            _game._tunnell.setPosY(200);
            _game.showtunnell(pa);
        }
        if(_game.ifclose() == 8)//进入下一个页面（final boss）
        {
            flag=4;
            _game._player.setPosX(6);
            _game._player.setPosY(20);
            _game._monster.setHP_now(200);
            _game._player.setHP_now(200);
            _game._player.setMP_now(200);
            update();
        }

        if(_game.ifclose()==6 )//回到试炼场的场景
        {
            flag=1;
            _game._player.setPosX(72);
            _game._player.setPosY(50);
            update();
        }
        ifinimonster=true;
    }
    if(flag==4)
    {
        ifhurt=true;

        if(ifinimonster == true)
        {
            _game._monster.setPosX(600);
            _game._monster.setPosY(400);
            ifinimonster = false;
        }
        QImage image = QImage(":/PICS/background.png");
        (*pa).drawImage(rect(),image);
        if(_game._player.getHP_now()>0)
        _game.show(pa);
        if(_game._monster.getHP_now()>0)
        _game._monster.showmonsterr(pa);
        if(_game.getifshowsao()==true){
            _game.showsao(pa);
        }
        if(_game.getturn()==true)
        {
            _game._elf.setPosX(_game._player.getPosX()*10-100);
            _game._elf.setPosY(_game._player.getPosY()*10-50);
            _game._elf.showelf(pa);
            update();
        }
        _game.showblood(pa);

        if(_game.getfire()==1)
        {
            ifbullethurt=true;
            int p=tiktok;
            if(way==1)
            {
                if(kk>=0)
                {
                    _game._bullet.setPosX(m*10+20*coss*(p-tmp));
                    _game._bullet.setPosY(n*10+20*sinn*(p-tmp));
                }
                else
                {
                    _game._bullet.setPosX(m*10+20*coss*(p-tmp));
                    _game._bullet.setPosY(n*10-20*sinn*(p-tmp));
                }
            }
            else
            {
                if(kk>=0)
                {
                    _game._bullet.setPosX(m*10-20*coss*(p-tmp));
                    _game._bullet.setPosY(n*10-20*sinn*(p-tmp));
                }
                else
                {
                    _game._bullet.setPosX(m*10-20*coss*(p-tmp));
                    _game._bullet.setPosY(n*10+20*sinn*(p-tmp));
                }
            }
            _game.showbullet(pa);
            if(p-tmp==10)
            {
                _game.setfire(0);
                ifbullethurt =false;
            }
        }
        if(_game._monster.getHP_now()<=100&&showoncedq==false)
        {
            _game._player.setHP_now(_game._player.getHP_now()-100);
            _game._dq.setPosX(_game._player.getPosX()*10-80);
            _game._dq.setPosY(_game._player.getPosY()*10-80);
            _game.setdq(0);
            _game.setifshowdq(true);
            showoncedq=true;
        }
        if(_game._monster.getHP_now()<=0)
        {
            _game._tunnel.setPosX(200);
            _game._tunnel.setPosY(200);
            _game.showtunnel(pa);
            if(_game.ifclose()==9)
            {
                flag=1;
                _game._player.setPosX(73);
                _game._player.setPosY(50);
            }
        }
        _game.showdq(pa);
        update();
    }
    pa->end();
    delete pa;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_9)
    {
        _game.setsave(1);
    }
    /*if(e->key()==Qt::Key_7)
    {
        flag=4;
        update();
    }*/
    if(flag==1)
    {
        if(e->key() == Qt::Key_R )
        {
            this->_game.setbetflag(1);
        }

        if(e->key() == Qt::Key_C)
        {
            if(_game.getChess()==0)
                _game.setChess(1);
            else _game.setChess(0);
        }
        if(e->key() ==Qt::Key_F)
        {
            _game.setflyWin(1);
            flag=2;
        }
        if(e->key() == Qt::Key_G)
        {
            if(_game.getBag()==0)
            _game.setBag(1);
            else _game.setBag(0);
            if(_game.getifshop()==0) _game.setifshop(1);
            else if(_game.getifshop() == 1) _game.setifshop(0);
        }
        if(e->key()==Qt::Key_1)
        {
           _game.setbetwinNum(1);
           _game.setifBet(1);
        }
        if(e->key()==Qt::Key_2)
        {
           _game.setbetwinNum(2);
           _game.setifBet(1);
        }
        if(e->key()==Qt::Key_3)
        {
           _game.setbetwinNum(3);
           _game.setifBet(1);
        }
        if(e->key()==Qt::Key_4)
        {
           _game.setbetwinNum(4);
           _game.setifBet(1);
        }
    }

    if(e->key() == Qt::Key_0)
    {
        flag = -1;
        this->update();
    }

    if(e->key() == Qt::Key_B)
    {
        if(_game.getBag()==0)
            _game.setBag(1);
        else _game.setBag(0);
    }
    if(_game.getBag()==1)// 在
    {
        if(e->key() == Qt::Key_H)
        {
            Player::subHPNum();
            if(_game._player.getHP_now()<200)
            {
                _game._player.setHP_now(_game._player.getHP_now()+50);
                update();
            }
        }
        if(e->key() == Qt::Key_J)
        {
            Player::subMPNum();
            if(_game._player.getMP_now()<200)
            {
                _game._player.setMP_now(_game._player.getMP_now()+30);
                update();
            }
        }
        if(e->key() == Qt::Key_5) {Player::addHPNum();Player::subMoney();}
        if(e->key() == Qt::Key_6) {Player::addMPNum();Player::subMoney();}
    }
    if(flag >0){

        if(e->key() == Qt::Key_A)
        {
            this->_game.handlePlayerMove(-1,0);
            this->_game.setflagg(2);
            this->update();
        }
        else if(e->key() == Qt::Key_D)
        {
            this->_game.handlePlayerMove(1,0);
            this->_game.setflagg(4);
            this->update();
        }
        else if(e->key() == Qt::Key_W)
        {
            this->_game.handlePlayerMove(0,-1);
            this->_game.setflagg(1);
            this->update();
        }
        else if(e->key() == Qt::Key_S)
        {
             this->_game.handlePlayerMove(0,1);
            this->_game.setflagg(3);
             this->update();
        }
        else if(e->key() == Qt::Key_K)
        {
            this->_game.initWeapon();
            this->_game.setIfweapon(1);
            this->_game.addamount();
        }
        this->update();
    }
    if(e->key() == Qt::Key_P){
        showdialog++;
    }
    if(flag ==2||flag ==4 )
    {
        if(e->key() == Qt::Key_M){
            if(_game._player.getMP_now()-50>=0)
            {
                _game._saoo.setPosX(_game._player.getPosX()*10+100);
                _game._saoo.setPosY(_game._player.getPosY()*10);
                _game._sao.setPosX(_game._monster.getPosX());
                _game._sao.setPosY(_game._monster.getPosY());
                if(_game._monster.getHP_now()-50>=0)
                _game._monster.setHP_now(_game._monster.getHP_now()-50);
                if(_game._player.getMP_now()-50>=0)
                _game._player.setMP_now(_game._player.getMP_now()-50);
                _game.setsao(0);
                _game.setifshowsao(true);
                if(_game._player.getMP_now()<50)
                _game.setifshowsao(false);
                update();
            }
        }
        if(e->key() == Qt::Key_N)
        {
            if(_game._player.getMP_now()-20>=0)
            {
                _game._player.setMP_now(_game._player.getMP_now()-20);
                if(_game.getflagg()==1)
                {
                    _game._player.setPosX(_game._player.getPosX());
                    _game._player.setPosY(_game._player.getPosY()-20);
                }
                else if(_game.getflagg()==2)
                {
                    _game._player.setPosX(_game._player.getPosX()-20);
                    _game._player.setPosY(_game._player.getPosY());
                }
                else if(_game.getflagg()==3)
                {
                    _game._player.setPosX(_game._player.getPosX());
                    _game._player.setPosY(_game._player.getPosY()+20);
                }
                else if(_game.getflagg()==4)
                {
                    _game._player.setPosX(_game._player.getPosX()+20);
                    _game._player.setPosY(_game._player.getPosY());
                }
            }
        }
    }
    if(flag==4)
    {
        if(e->key() == Qt::Key_T)
        {
            _game.setturn(true);
            if(_game._player.getMP_now()-80>=0)
            _game._player.setMP_now(_game._player.getMP_now()-80);
            update();
        }
    }
}

void MainWindow::Sanziqi(QPainter *painter)
{

    // 绘制棋盘
    (*painter).setRenderHint(QPainter::Antialiasing, true); // 抗锯齿
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);           // 设置画笔为黄色
    (*painter).setPen(pen);                // 设置画笔
    for (int i = 1; i < kBoardSizeNum ; i++)
    {
        (*painter).drawLine(kBoardMargin + kBlockSize * i, kBoardMargin, kBoardMargin + kBlockSize * i, size().height() - kBoardMargin);
        (*painter).drawLine(kBoardMargin, kBoardMargin + kBlockSize * i, size().width() - kBoardMargin, kBoardMargin + kBlockSize * i);
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    // 绘制落子标记(防止鼠标出框越界)
    if (clickPosRow > 0 && clickPosRow < kBoardSizeNum &&
        clickPosCol > 0 && clickPosCol < kBoardSizeNum &&
        game->gameMapVec[clickPosRow][clickPosCol] == 0)
    {
        if (game->playerFlag)
            brush.setColor(Qt::white);
        else
            brush.setColor(Qt::black);
        (*painter).setBrush(brush);
        (*painter).drawRect(kBoardMargin + kBlockSize * clickPosCol - kMarkSize / 2, kBoardMargin + kBlockSize * clickPosRow - kMarkSize / 2, kMarkSize, kMarkSize);
    }

    // 绘制棋子
    for (int i = 0; i < kBoardSizeNum; i++)
        for (int j = 0; j < kBoardSizeNum; j++)
        {
            if (game->gameMapVec[i][j] == 1)
            {
                brush.setColor(Qt::green);
                (*painter).setBrush(brush);
                (*painter).drawEllipse(kBoardMargin + kBlockSize * j - kRadius, kBoardMargin + kBlockSize * i - kRadius, kRadius * 2, kRadius * 2);
            }
            else if (game->gameMapVec[i][j] == -1)
            {
                brush.setColor(Qt::red);
                (*painter).setBrush(brush);
                (*painter).drawEllipse(kBoardMargin + kBlockSize * j - 2*kRadius, kBoardMargin + kBlockSize * i - kRadius, kRadius * 4, kRadius * 2);
            }
        }
    // 判断输赢
    if (clickPosRow > 0 && clickPosRow < kBoardSizeNum &&
        clickPosCol > 0 && clickPosCol < kBoardSizeNum &&
        (game->gameMapVec[clickPosRow][clickPosCol] == 1 ||
            game->gameMapVec[clickPosRow][clickPosCol] == -1))
    {
        if (game->isWin(clickPosRow, clickPosCol) && game->gameStatus == PLAYING)
        {
            qDebug() << "win";
            game->gameStatus = WIN;
            QString str;
            str = "You";
             QMessageBox::StandardButton btnValue;
            if (game->gameMapVec[clickPosRow][clickPosCol] == 1)
            {
                Player::addMoney();
                change3=true;
                btnValue = QMessageBox::information(this, "congratulations", str + " win!");
            }
            else if (game->gameMapVec[clickPosRow][clickPosCol] == -1)
            {
                change3=false;
                btnValue = QMessageBox::information(this, "congratulations", str + " lose!");
            }

            // 重置游戏状态，否则容易死循环
            if (btnValue == QMessageBox::Ok)
            {
                _game.setChess(0);
                game->startGame(game_type);
                game->gameStatus = PLAYING;
            }
        }
    }
}

void MainWindow::initGame()
{
    // 初始化游戏模型
    game = new GameModel;
    initPVEGame();
}

void MainWindow::initPVEGame()
{
    game_type = BOT;
    game->gameStatus = PLAYING;
    game->startGame(game_type);
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(_game.getChess() == 1)
    {
        // 通过鼠标的hover确定落子的标记
        int x = event->x();
        int y = event->y();

        // 棋盘边缘不能落子
        if (x >= kBoardMargin + kBlockSize / 2 &&
                x < size().width() - kBoardMargin &&
                y >= kBoardMargin + kBlockSize / 2 &&
                y < size().height()- kBoardMargin)
        {
            // 获取最近的左上角的点
            int col = x / kBlockSize;
            int row = y / kBlockSize;

            int leftTopPosX = kBoardMargin + kBlockSize * col;
            int leftTopPosY = kBoardMargin + kBlockSize * row;

            // 根据距离算出合适的点击位置,一共四个点，根据半径距离选最近的
            clickPosRow = -1; // 初始化最终的值
            clickPosCol = -1;
            int len = 0; // 计算完后取整就可以了

            // 确定一个误差在范围内的点，且只可能确定一个出来
            len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));
            if (len < kPosDelta)
            {
                clickPosRow = row;
                clickPosCol = col;
            }
            len = sqrt((x - leftTopPosX - kBlockSize) * (x - leftTopPosX - kBlockSize) + (y - leftTopPosY) * (y - leftTopPosY));
            if (len < kPosDelta)
            {
                clickPosRow = row;
                clickPosCol = col + 1;
            }
            len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY - kBlockSize) * (y - leftTopPosY - kBlockSize));
            if (len < kPosDelta)
            {
                clickPosRow = row + 1;
                clickPosCol = col;
            }
            len = sqrt((x - leftTopPosX - kBlockSize) * (x - leftTopPosX - kBlockSize) + (y - leftTopPosY - kBlockSize) * (y - leftTopPosY - kBlockSize));
            if (len < kPosDelta)
            {
                clickPosRow = row + 1;
                clickPosCol = col + 1;
            }
            // 存了坐标后也要重绘
            update();
        }
    }
    if(_game.getChess() == 0)
    {
        mousePressEvent(event);
    }
}


void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

    if(_game.getChess() == 1)
    {
        // 人下棋，并且不能抢机器的棋
        chessOneByPerson();
        // 如果是人机模式，需要调用AI下棋
        if (!game->playerFlag)
        {
            // 用定时器做一个延迟
            QTimer::singleShot(kAIDelay, this, SLOT(chessOneByAI()));
        }
    }
    if(_game.getChess() == 0)
    {
        mousePressEvent(event);
    }
}

void MainWindow::chessOneByPerson()
{
    // 根据当前存储的坐标下子
    // 只有有效点击才下子，并且该处没有子
    if (clickPosRow != -1 && clickPosCol != -1 && game->gameMapVec[clickPosRow][clickPosCol] == 0)
    {
        game->actionByPerson(clickPosRow, clickPosCol);
        //QSound::play(CHESS_ONE_SOUND);

        // 重绘
        update();
    }
}

void MainWindow::chessOneByAI()
{
    game->actionByAI(clickPosRow, clickPosCol);
 //   QSound::play(("/Users/air/Desktop/Thomas Newman-Por Una Cabeza.mp3"));
    QSound::play(CHESS_ONE_SOUND);
    update();
}



