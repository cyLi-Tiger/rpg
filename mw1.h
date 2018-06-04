#ifndef MW1_H
#define MW1_H

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
namespace Ui {
class MW1;
}


class MW1 : public QMainWindow{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    void female_choose();
    void male_choose();
protected slots:
    void randommove();//响应时钟事件的函数
private:
    Ui::MW1 *ui;
    World _game;
    vector<Rpgobj> obj;
    //obj.reserve(3);//可能会是报错点
    QTimer *timer;
    static int flag;
        //时钟，控制玩家移动频率
};


#endif // MW1_H
