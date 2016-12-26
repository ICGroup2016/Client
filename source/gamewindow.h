#ifndef GameWindow_H
#define GameWindow_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    void addplayer(int,int);
    void myplayer(int,int);//信息初始化：玩家本人的id与座位号
    void start(int role);//role: 0村民、1女巫、2猎人、3预言家、4狼人
    void getmessage(int seat,QString str);//0表示上帝
    void myturn();
    void endturn();//可以内部执行，但考虑到倒计时等扩展，写为公有。
    void wolfwakeup();
    void wolfsleep();
    void prophetwakeup();//预言家起床
    void prophetsleep();
    //void witchwakeup(QString);
    //void witchsleep();
    void killed(int);
    void gameover();
    ~GameWindow();

signals:
    void speak(int, QString);//回车发送信息待实现
    void prepared(int);
    void unprepared(int);
    void goback(int);
    void exit(int);
    void end();//结束发言
    void choice(int);
private:
    void on_actionChakan_triggered();
    void on_pushButton_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    Ui::GameWindow *ui;
    QLabel *label[12];
    QPushButton *pushbutton[12];
    QFrame *frame[12];
    int identity,myseat;
    bool live[12];
    void choose1();
    void choose2();
    void choose3();
    void choose4();
    void choose5();
    void choose6();
    void choose7();
    void choose8();
    void choose9();
    void choose10();
    void choose11();
    void choose12();
    void choose0();//选择不杀、不毒、不开枪、不票
};

#endif // GameWindow_H
