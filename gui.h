#ifndef GUI_H
#define GUI_H
#include "gamewindow.h"
#include<QObject>
#include<QString>
#include<QVector>
#include<QPair>
//部分提示词已包含在程序中

class gui:public QObject
{
    Q_OBJECT
public:
    gui();
    void showgame();//窗口出现
    void flush(QVector<QPair<int,int>>,int);//加入玩家:改为接受列表
    void myplayer(int seat, int id);//自身信息
    void role(int role);//开始游戏，告知身份
    void showmessage(int seat,QString str);//收取发言并显示
    void myturn();//开始发言

    int decide(QVector<int>,bool);//选警长和投票通用，本来这两个就没区别吧
    bool choose();
    void endturn();//自爆时强制结束对话


signals:
    void ready();//准备
    void cancel();//取消准备
    void quit();//返回大厅
    void speak(QString);//发言
    void endspeaking();//结束发言
    void explode();//自爆
private:
    GameWindow g;
    void gprepared();
    void gunprepared();
    void ggoback();

    void gspeak(QString);
    void gendturn();
    void gchoice(int);
    void gexplode();
};

/*bool officercandidate();//传递警徽也用vote（），点击自己头像即为撕毁
bool officerdecide();
int wolfsturn(QVector<int>);//自带提示“你要杀谁？”
bool medicine();
int poison(QVector<int> player);//选择是、否
int prophet(QVector<int> player);//预言家出场，验人结果用字符串告知
int hunter(QVector<int>);//猎人死亡，发动技能
*/
//void gameover();
//void runforpolice();
//killed已删除，直接发一句话就够了
#endif // GUI_H
