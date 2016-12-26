#ifndef GameWindow_H
#define GameWindow_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include<QPair>
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
    //1：狼人 2：女巫 3：预言家 4：猎人 5：平民
    //0->1\1->2\2->4\3->3\4->1
    void getmessage(int seat,QString str);//0表示上帝
    void myturn();
    void endturn();//可以内部执行，但考虑到倒计时等扩展，写为公有。
    int vote(QVector<int>);
    bool officercandidate();//传递警徽也用vote（），点击自己头像即为撕毁
    bool officerdecide();//警长决定发言方向。询问是否警左，1警左，0警右
    int wolfsturn(QVector<int> player);
    bool medicine();
    int poison(QVector<int> player);
    int prophet(QVector<int> player);//预言家出场，验人结果用字符串告知
    int hunter(QVector<int>);//猎人死亡，发动技能
    //void gameover();
    void showprepared(int);
    ~GameWindow();

signals:
    void speak(int, QString);//回车发送信息待实现
    void prepared();
    void unprepared();
    void goback();
    void explode();//自爆
    void end();//结束发言

private:
    void on_actionChakan_triggered();
    void on_pushButton_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_22_clicked();
    QLabel *preparation=new QLabel(this);
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
    void chooseyes();
    void chooseno();
    void exploded();
};

#endif // GameWindow_H
