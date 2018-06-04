#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include <map>
#include <iostream>
#include <QTextStream>
#include <fstream>
#include <QTimer>

using namespace std;

extern fstream error;
extern bool man;

int MW1::flag = 0;
MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);
    _game.initWorld("/Users/air/desktop/castle.txt");//TODO 应该是输入有效的地图文件
    //以下是对时钟的初始化
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(randommove()));//timeoutslot()为自定义槽
        //时钟事件与randomMove函数绑定
    timer->start(100);
    //timer->setInterval(1000);

  //  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        //设置随机数种子

}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    if(this->_game.getBattle() == 1) flag =2;
    pa->begin(this);
    if(flag == 1){this->_game.show(pa);}
    if(flag == 0)
    {
    QImage image = QImage("/Users/air/Desktop/images_res/background.jpg");
    (*pa).drawImage(rect(),image);
    }  //可以修改 可能可以写一个正方形的函数
       //这儿不能实现flag=1， 不然会显示不出来；

    if(flag == 2)
    {
    QImage image = QImage("/Users/air/Desktop/images_res/battle.jpeg");
    (*pa).drawImage(rect(),image);
    flag = 1;
    this->_game.show(pa);
    }
    pa->end();
    delete pa;
}

//void MW1::randomRival(){
//}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(flag != 0){
        if(e->key() == Qt::Key_A)
        {
            this->_game.handlePlayerMove(-1,0);
        }
        else if(e->key() == Qt::Key_D)
        {
            this->_game.handlePlayerMove(1,0);
        }
        else if(e->key() == Qt::Key_W)
        {
            this->_game.handlePlayerMove(0,-1);
        }
        else if(e->key() == Qt::Key_S)
        {
             this->_game.handlePlayerMove(0,1);
        }
        else if(e->key() == Qt::Key_K)
        {
            this->_game.initWeapon();
            this->_game.setIfweapon(1);
            this->_game.addamount();
        }
        this->repaint();
    }
    if(flag == 0){
        if(e->key() == Qt::Key_1)
        {
           male_choose();
           flag = 1;
           this->repaint();
        }
    }
}

void MW1::randommove(){
    update();
}

void MW1::female_choose(){
     QStringList lines;
     lines.append("player");
     lines.append("5");
     lines.append("5");
     QFile file( "/Users/air/Desktop/map.txt" );
     if ( file.open( QIODevice::WriteOnly ) ) {//只读模式
         QTextStream stream( &file );
         for (auto it = lines.begin(); it != lines.end(); ++it )
         {
             if(it == lines.end())
             {
               stream << *it << "\n";
             }
             else stream << *it << " ";
         }
         file.close();
     }
}

void MW1::male_choose(){
    QStringList lines;
    lines.append("player");
    lines.append("5");
    lines.append("5");
     QFile file( "/Users/air/Desktop/map.txt" );
     if ( file.open( QIODevice::WriteOnly ) ) {//只读模式
         QTextStream stream( &file );
         for (auto it = lines.begin(); it != lines.end(); ++it )
             stream << *it << " ";
         file.close();
     }
}
