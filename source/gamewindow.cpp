#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gui.h"
#include <QDesktopServices>
#include <QUrl>
#include <QPalette>
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{

    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());
    ui->textEdit->setTextColor(Qt::white);

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
    connect(ui->pushButton,&QPushButton::clicked,this,&GameWindow::on_pushButton_clicked);
    connect(ui->pushButton_13,&QPushButton::clicked,this,&GameWindow::on_pushButton_13_clicked);
    connect(ui->pushButton_15,&QPushButton::clicked,this,&GameWindow::on_pushButton_15_clicked);
    connect(ui->pushButton_16,&QPushButton::clicked,this,&GameWindow::on_pushButton_16_clicked);
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
    connect(ui->pushButton_23,&QPushButton::clicked,this,&GameWindow::choose0);
    connect(ui->pushButton_19,&QPushButton::clicked,this,&GameWindow::choose0);
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
        emit prepared(identity);
        ui->pushButton_13->setText("取消准备");

    }
    else
    {
        emit unprepared(identity);
        ui->pushButton_13->setText("准备");

    }
}


void GameWindow::on_pushButton_15_clicked()
{
    emit goback(identity);
    close();
}
void GameWindow::on_pushButton_16_clicked()
{
    emit exit(identity);
    close();

}
void GameWindow::start(int role)
{
    ui->pushButton_13->setVisible(false);
    ui->pushButton_15->setVisible(false);
    ui->pushButton_16->setVisible(false);
    ui->pushButton_23->setVisible(true);
    if(role==0)
    {
        ui->pushButton_19->setVisible(false);
        ui->label_15->setText(tr("平民"));
    }
    else if(role==3)

    {
        ui->pushButton_19->setVisible(false);
        ui->label_15->setText(tr("预言家"));
    }
    else if(role==1)
    {
        ui->pushButton_19->setText(tr("不毒"));
        ui->label_15->setText(tr("女巫"));
    }
    else if(role==2)
    {
        ui->pushButton_19->setText(tr("空枪"));
        ui->label_15->setText(tr("猎人"));
    }
    else
    {
        ui->pushButton_19->setText(tr("空刀"));
        ui->pushButton_20->setVisible(true);
        ui->label_15->setText(tr("狼人"));
    }
}//图标暂不可用
void GameWindow::getmessage(int seat, QString str)
{
    if(seat!=0)
    ui->textEdit_2->append(tr("%1号玩家：").arg(seat));//换行未考虑
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
void GameWindow::wolfwakeup()
{
    ui->textEdit_2->append(tr("请选择你要杀的人："));
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(live[i]);
    }
    ui->textEdit->setEnabled(true);
    ui->pushButton->setEnabled(true);
}

void GameWindow::wolfsleep()
{
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
}
void GameWindow::choose1()
{
    emit choice(1);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose2()
{
    emit choice(2);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose3()
{
    emit choice(3);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose4()
{
    emit choice(4);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose5()
{
    emit choice(5);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose6()
{
    emit choice(6);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose7()
{
    emit choice(7);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose8()
{
    emit choice(8);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose9()
{
    emit choice(9);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose10()
{
    emit choice(10);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose11()
{
    emit choice(11);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose12()
{
    emit choice(12);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::choose0()
{
    emit choice(0);
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::prophetwakeup()
{
    ui->textEdit_2->append(tr("请选择你要验的人："));

    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(live[i]);
    }
}
void GameWindow::prophetsleep()
{
    for(int i=0;i<=11;i++)
    {
        pushbutton[i]->setEnabled(false);
    }
}
void GameWindow::killed(int seat)
{
    live[seat-1]=false;
    //头像变化待实现
    ui->textEdit_2->append(tr("%1号玩家已死亡").arg(seat-1));
}
void GameWindow::gameover()
{
    ui->textEdit_2->append(tr("游戏结束。"));

    ui->pushButton_13->setVisible(true);
    ui->pushButton_15->setVisible(true);
    ui->pushButton_16->setVisible(true);
    ui->pushButton_23->setVisible(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_17->setEnabled(false);
    ui->textEdit->setEnabled(false);
}
