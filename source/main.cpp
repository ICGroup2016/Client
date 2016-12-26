#include "hall.h"
#include "login.h"
#include <QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gui b;
    b.showlogin();
    b.warning();
    b.addroom("gking","3/8");
    b.showHall();
    b.addroom("gking301","3/80");
/*
    b.showgame();
    b.myplayer(4,1234);
    b.addplayer(2,5678);
    b.addplayer(4,1234);
    b.addplayer(5,2333);
    b.start(1);
    b.getmessage(0,"天黑请闭眼");
    b.getmessage(1,"我是预言家");
    b.myturn();
    b.gameover();*/

    return a.exec();
}
