#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include "hall.h"
#include "login.h"
#include "createroom.h"
#include "gamewindow.h"

class gui :public QObject
{
    Q_OBJECT

public:
    explicit gui(QObject *parent=0);

    void showlogin();

    QPair<QString,int> acquireServer();

    void showHall();

    void warning();

    void addroom(QString,QString);

    void removeroom();

    void enterroomok();

    void hidehall();

    void showgame();//窗口出现
    void addplayer(int seat, int id);//加入玩家
    void myplayer(int seat, int id);//自身信息
    void start(int role);//开始游戏，告知身份
    void getmessage(int seat,QString str);//收取发言并显示
    void myturn();//开始发言
    //delete
    void wolfwakeup();//狼人起床，自带提示
    void wolfsleep();//狼人睡觉
    void prophetwakeup();//预言家起床，自带提示
    void prophetsleep();//预言家睡觉
    void gameover();//游戏结束，自带提示

    void killed(int);//自带发言（...号玩家已死亡）delete int

signals:

    void Newroom(const QPair<QString,int> pair);

    void enterRoom(const QString ip);

    void prepared(int);//准备 int
    void unprepared(int);//取消准备 int
    void goback(int);//返回大厅 int
    void exit(int);//退出游戏 int
    void speak(int,QString);//发言 int
    void endturn();//结束发言

    void choice(int);//选择一个人或弃权（0）delete

private slots:

    void openlogin();

    void showcreateroom();

    void onenewroom(const QPair<QString,int> pair);

    void enterroom(const QString ip);

    void openweb();

    void WArning();

private:

    hall w;

    login l;

    createroom c;

    GameWindow g;
    void gprepared(int id);
    void gunprepared(int id);
    void ggoback(int id);
    void gexit(int id);
    void gspeak(int, QString);
    void gendturn();
    void gchoice(int);

};

#endif // GUI_H
