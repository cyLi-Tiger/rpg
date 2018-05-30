#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include "player.h"
#include<QTime>
#include<QTimer>
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
//protected slots:
  //  void randomMove();//响应时钟事件的函数
private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer;
    static int flag;
        //时钟，控制玩家移动频率
};


#endif // MW1_H
