#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "gui.h"
#include "tcpsock.h"
#include "message.h"
enum Position{LOGIN,HALL,ROOM,GAME};
class Core : public QObject
{
    Q_OBJECT
public:
    explicit Core(QObject *parent = 0);
signals:

private:
    int id;
    int roomid;
    gui G;
    TcpSock *socket;
    QThread *thread;
    Position pos;
    void connectToServer();
    void sendEmptyMessage(int,int,int,int);
    void onNetworkError();
    void handleMessage(Message);
    void genFeedback(Message);
    void flushRoom(QVector<int>);
    void flushPlayer(QVector<int>);

    void Newroom(const int number);
    void enterRoom(const int id);
    void ready();//准备
    void cancel();//取消准备
    void quit();//返回大厅
    void speak(QString);//发言
    void endspeaking();//结束发言
    void explode();//自爆
};

#endif // CORE_H
