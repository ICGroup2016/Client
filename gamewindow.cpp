#include "gamewindow.h"
#include "ui_GameWindow.h"
#include "gui.h"
#include<QVector>
#include <QDesktopServices>
#include <QUrl>
#include <Qpalette>
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{

    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());
    ui->textEdit->setTextColor(Qt::white);
    ui->statusBar->showMessage(tr("欢迎加入游戏！"),2000);

    ui->statusBar->addPermanentWidget(preparation);
    ui->textEdit_2->setTextColor(Qt::red);
    label[0]=ui->label_1;
    label[1]=ui->label_2;
    label[2]=ui->label_3;
    label[3]=ui->label_4;
    label[4]=ui->label_5;
    label[5]=ui->label_6;
    label[6]=ui->label_7;
    label[7]=ui->label_8;
    label[8]=ui->label_9;
    label[9]=ui->label_10;
    label[10]=ui->label_11;
    label[11]=ui->label_12;
    pushbutton[0]=ui->pushButton_1;
    pushbutton[1]=ui->pushButton_2;
    pushbutton[2]=ui->pushButton_3;
    pushbutton[3]=ui->pushButton_4;
    pushbutton[4]=ui->pushButton_5;
    pushbutton[5]=ui->pushButton_6;
    pushbutton[6]=ui->pushButton_7;
    pushbutton[7]=ui->pushButton_8;
    pushbutton[8]=ui->pushButton_9;
    pushbutton[9]=ui->pushButton_10;
    pushbutton[10]=ui->pushButton_11;
    pushbutton[11]=ui->pushButton_12;
    frame[0]=ui->frame_1;
    frame[1]=ui->frame_2;
    frame[2]=ui->frame_3;
    frame[3]=ui->frame_4;
    frame[4]=ui->frame_5;
    frame[5]=ui->frame_6;
    frame[6]=ui->frame_7;
    frame[7]=ui->frame_8;
    frame[8]=ui->frame_9;
    frame[9]=ui->frame_10;
    frame[10]=ui->frame_11;
    frame[11]=ui->frame_12;
    for(int i=0;i<=11;i++)
    {
        label[i]->setVisible(false);
        pushbutton[i]->setVisible(false);
        live[i]=false;
    }
    ui->pushButton_20->setVisible(false);
    ui->pushButton_23->setVisible(false);
    ui->pushButton_24->setVisible(false);
    connect(ui->actionChakan,&QAction::triggered,this,&GameWindow::on_actionChakan_triggered);
    connect(ui->pushButton,&QPushButton::clicked,this,&GameWindow::on_pushButton_clicked);
    connect(ui->pushButton_13,&QPushButton::clicked,this,&GameWindow::on_pushButton_13_clicked);
    connect(ui->pushButton_15,&QPushButton::clicked,this,&GameWindow::on_pushButton_15_clicked);
//    connect(ui->pushButton_22,&QPushButton::clicked,this,&GameWindow::on_pushButton_22_clicked);
    connect(ui->pushButton_17,&QPushButton::clicked,this,&GameWindow::endturn);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&GameWindow::choose1);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&GameWindow::choose2);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&GameWindow::choose3);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&GameWindow::choose4);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&GameWindow::choose5);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&GameWindow::choose6);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&GameWindow::choose7);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&GameWindow::choose8);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&GameWindow::choose9);
    connect(ui->pushButton_10,&QPushButton::clicked,this,&GameWindow::choose10);
    connect(ui->pushButton_11,&QPushButton::clicked,this,&GameWindow::choose11);
    connect(ui->pushButton_12,&QPushButton::clicked,this,&GameWindow::choose12);

    connect(ui->pushButton_19,&QPushButton::clicked,this,&GameWindow::choose0);
    connect(ui->pushButton_23,&QPushButton::clicked,this,&GameWindow::chooseyes);
    connect(ui->pushButton_24,&QPushButton::clicked,this,&GameWindow::chooseno);
    connect(ui->pushButton_20,&QPushButton::clicked,this,&GameWindow::exploded);
    connect(ui->pushButton_14,&QPushButton::clicked,ui->textEdit_2,&QTextEdit::clear);
}


GameWindow::~GameWindow()
{
    delete ui;
}
void GameWindow::myplayer(int seat,int id)
{
    myseat=seat;
    identity=id;
    ui->label_13->setText(tr("ID:%1").arg(identity));
    ui->label_14->setText(tr("%1号").arg(seat+1));
    frame[seat]->setStyleSheet("background-color: rgb(0, 85, 255)");

}

void GameWindow::addplayer(int seat,int id)
{
    label[seat]->setVisible(true);
    pushbutton[seat]->setVisible(true);
    label[seat]->setText(tr("ID:%1").arg(id));
    live[seat]=true;
}
void GameWindow::on_actionChakan_triggered()
{
    QDesktopServices::openUrl(QUrl("http://baike.baidu.com/link?url=NIp1tudVwrioy0g3GF4QEles_ctV6TEpD_-sQ21huAlzyu7m-g4l1WrnQzhSovRjZpaJ1Zf3hMsrjejzpOESFludN9CZfCfA2F4PPDvXEdYTww_NCJP6unzDD6DiNGGd"));
}
void GameWindow::exploded()
{
    emit explode();
}

void GameWindow::on_pushButton_clicked()
{
    QString str=ui->textEdit->toPlainText();
    emit speak(identity,str);
    ui->textEdit->clear();
}
void GameWindow::on_pushButton_13_clicked()
{
    if(ui->pushButton_13->text()==tr("准备"))
    {
        emit prepared();
        ui->pushButton_13->setText("取消准备");

    }
    else
    {
        emit unprepared();
        ui->pushButton_13->setText("准备");

    }
}


void GameWindow::on_pushButton_15_clicked()
{
    emit goback();
    close();
}

void GameWindow::start(int role)
{
    ui->pushButton_13->setVisible(false);
    ui->pushButton_15->setVisible(false);
    ui->pushButton_22->setVisible(false);

    if(role==5)
    {
        ui->pushButton_19->setText(tr("弃票"));
        ui->label_15->setText(tr("平民"));
        ui->label_16->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/farmer.ico")));
    }
    else if(role==3)

    {
        ui->pushButton_19->setText(tr("弃票"));
        ui->label_15->setText(tr("预言家"));
        ui->label_16->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/crystal_ball.ico")));
    }
    else if(role==2)
    {
        ui->pushButton_19->setText(tr("不毒/弃票"));
        ui->label_15->setText(tr("女巫"));
        ui->label_16->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/witch.ico")));
    }
    else if(role==4)
    {
        ui->pushButton_19->setText(tr("空枪/弃票"));
        ui->label_15->setText(tr("猎人"));
        ui->label_16->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/gun.ico")));
    }
    else
    {
        ui->pushButton_19->setText(tr("弃票"));
        ui->pushButton_20->setVisible(true);
        ui->label_15->setText(tr("狼人"));
        ui->label_16->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/myico.ico")));
    }
     ui->pushButton_19->setEnabled(false);
}
void GameWindow::getmessage(int seat,QString str)
{
    if(seat!=-1)
    ui->textEdit_2->append(tr("%1号玩家：").arg(seat+1));//换行未考虑
    ui->textEdit_2->append(str);//文本颜色暂不能改
//发言者边框高亮待写
//文本我再慢慢调
}
void GameWindow::myturn()
{
    ui->textEdit->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_17->setEnabled(true);
    ui->textEdit_2->append(tr("轮到你了："));
}
void GameWindow::endturn()
{
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_17->setEnabled(false);
    ui->textEdit_2->append(tr("发言结束。"));
    emit end();
}
int GameWindow::wolfsturn(QVector<int> player)
{
    ui->textEdit_2->append(tr("请选择你要杀的人："));
    ui->textEdit->setEnabled(true);
    ui->pushButton->setEnabled(true);
    QVector<int>::iterator i;
    for(i=player.begin();i!=player.end();i++)
    {
        pushbutton[*i]->setEnabled(true);
        live[*i]=true;
    }
    return QApplication::exec()-1;
}


void GameWindow::choose1()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(1);
}
void GameWindow::choose2()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(2);
}
void GameWindow::choose3()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(3);
}
void GameWindow::choose4()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(4);
}
void GameWindow::choose5()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(5);
}
void GameWindow::choose6()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(6);
}
void GameWindow::choose7()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(7);
}
void GameWindow::choose8()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(8);
}
void GameWindow::choose9()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(9);
}
void GameWindow::choose10()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(10);
}
void GameWindow::choose11()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(11);
}
void GameWindow::choose12()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(12);
}
void GameWindow::choose0()
{
    for(int i=0;i<=11;i++){
        pushbutton[i]->setEnabled(false);
        live[i]=false;
    }
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
    QApplication::exit(0);
}
void GameWindow::chooseyes()
{
    ui->pushButton_23->setVisible(false);
    ui->pushButton_24->setVisible(false);
    QApplication::exit(true);
}
void GameWindow::chooseno()
{
    ui->pushButton_23->setVisible(false);
    ui->pushButton_24->setVisible(false);
    QApplication::exit(false);
}

bool GameWindow::officercandidate()
{
   ui->pushButton_23->setVisible(true);
   ui->pushButton_24->setVisible(true);
   return QApplication::exec();
}

/*void GameWindow::gameover()
{
    ui->textEdit_2->append(tr("游戏结束。"));

    ui->pushButton_13->setVisible(true);
    ui->pushButton_15->setVisible(true);
    ui->pushButton_22->setVisible(true);

    ui->pushButton->setEnabled(false);
    ui->pushButton_17->setEnabled(false);
    ui->textEdit->setEnabled(false);
}*/
int GameWindow::vote(QVector<int> player)
{
    QVector<int>::iterator i;
    for(i=player.begin();i!=player.end();i++)
    {
        pushbutton[*i]->setEnabled(true);
        live[*i]=true;
    }
    return QApplication::exec()-1;
}
bool GameWindow::medicine()
{
    ui->pushButton_23->setVisible(true);
    ui->pushButton_24->setVisible(true);
    return QApplication::exec();
}
int GameWindow::poison(QVector<int> player)
{
    ui->pushButton_19->setEnabled(true);

    QVector<int>::iterator i;
    for(i=player.begin();i!=player.end();i++)
    {
        pushbutton[*i]->setEnabled(true);
        live[*i]=true;
    }
    return QApplication::exec()-1;
}
int GameWindow::prophet(QVector<int> player)
{
    QVector<int>::iterator i;
    for(i=player.begin();i!=player.end();i++)
    {
        pushbutton[*i]->setEnabled(true);
        live[*i]=true;
    }
    return QApplication::exec()-1;
}
int GameWindow::hunter(QVector<int> player)
{
    ui->pushButton_19->setEnabled(true);

    QVector<int>::iterator i;
    for(i=player.begin();i!=player.end();i++)
    {
        pushbutton[*i]->setEnabled(true);
        live[*i]=true;
    }
    return QApplication::exec()-1;
}
bool GameWindow::officerdecide()
{
    ui->pushButton_23->setVisible(true);
    ui->pushButton_24->setVisible(true);
    return QApplication::exec();
}
void GameWindow::showprepared(int prepared)
{
    preparation->setText(tr("已有%1人准备了").arg(prepared));
}
