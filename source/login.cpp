#include "login.h"
#include "ui_login.h"
#include <QPalette>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    QPalette pll=ui->ip->palette();
    pll.setBrush(QPalette::Base,QBrush(QColor(10,10,40,200)));
    ui->ip->setPalette(pll);
    ui->lineEdit->setPalette(pll);
    ui->port->setPalette(pll);

    ui->pushButton->setStyleSheet("QPushButton{color: rgb(222, 222, 222);font: 75 14pt;border-color: rgb(35, 55, 90);background-color: rgb(40, 60, 100);border-width: 3px;border-style: outset;}"
                                  "QPushButton:hover{background-color: rgb(45,65,110);border-color: rgb(40,60,100);}"
                                  "QPushButton:pressed{font: 75 14pt;border-style: inset;background-color: rgb(45,65,110);border-color: rgb(40,60,100);}");

    ui->pushButton_2->setStyleSheet("QPushButton{color: rgb(222, 222, 222);font: 75 14pt;border-color: rgb(35, 55, 90);background-color: rgb(40, 60, 100);border-width: 3px;border-style: outset;}"
                                  "QPushButton:hover{background-color: rgb(45,65,110);border-color: rgb(40,60,100);}"
                                  "QPushButton:pressed{font: 75 14pt;border-style: inset;background-color: rgb(45,65,110);border-color: rgb(40,60,100);}");

    ui->lineEdit->setStyleSheet("QLineEdit{border-width: 0px;padding-width: 0px;margin-width: 0px;}");

    QPalette pl=ui->label->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(10,10,40,200)));
    ui->label->setPalette(pl);

    ui->lineEdit->hide();

    this->setFixedSize(this->width(), this->height());

    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);


    ui->pushButton->setDefault(1);
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    pair.first=ui->ip->text();
    pair.second=ui->port->text().toInt();

    if(ui->ip->text().size()==0)
        ui->label_3->setText("ip地址不能为空");

    if(ui->port->text().size()==0)
        ui->label_4->setText("port不能为空");

    if((ui->ip->text().size()!=0)&(ui->port->text().size()!=0)){
        this->close();
        emit Login(pair);
    }
}

QPair<QString,int> login::getpair(){
    QPair<QString,int> abc;
    abc.first=pair.first;
    abc.second=pair.second;
    return abc;
}

void login::reset(){
    ui->label_3->setText(" ");
    ui->label_4->setText(" ");

}
