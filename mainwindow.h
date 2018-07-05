#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include "rpgobj.h"
#include "world.h"
#include "player.h"
#include <QTime>
#include <QTimer>
#include <cmath>
#include <gamemodel.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *e);

    // 监听鼠标移动情况，方便落子
    void mouseMoveEvent(QMouseEvent *event);
    // 实际落子
    void mouseReleaseEvent(QMouseEvent *event);
    int dis(int a,int b,int c,int d){
        int k=sqrt((a-b)*(a-b)+(d-c)*(d-c));
        return k;
    }
    void setflag(int k){
        flag=k;
    }

    void Sanziqi(QPainter *painter);

protected slots:
    //void randommove();//响应时钟事件的函数
    void updatetun();
    void updatebullet();
    void updatemonster();
    void hurt();
    void updatesao();
    void heal();
    void updatedq();
    
    // 三子棋
    void chessOneByPerson(); // 人执行
    void chessOneByAI();// AI下棋;
    void initPVEGame();

private:
    //Ui::MainWindow *ui;
    World _game;
    vector<Rpgobj> obj;
    //obj.reserve(3);//可能会是报错点
    int flag=-1;
        //时钟，控制玩家移动频率
    int tiktok=0;
    double kk;
    int tmp;
    int way=0;
    int m,n;
    double sinn,coss;
    bool ifinimonster = true;
    bool ifhurt =false;
    bool ifbullethurt =true;
    static int showdialog;
    bool change1=0;
    bool change2=0;
    bool change3=0;

    //game_三子棋
    GameModel *game; // 游戏指针
    GameType game_type; // 存储游戏类型
    int clickPosRow, clickPosCol; // 存储将点击的位置
    void initGame();
    void checkGame(int y, int x);
    bool showoncedq=false;

};

#endif // MAINWINDOW_H
