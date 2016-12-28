#include "warning.h"
#include "ui_warning.h"
#include <QPalette>

Warning::Warning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warning)
{
    ui->setupUi(this);

    QPalette pll=ui->lineEdit->palette();
    pll.setBrush(QPalette::Base,QBrush(QColor(10,10,40,200)));
    ui->lineEdit->setPalette(pll);

    ui->label->hide();

    ui->pushButton->setStyleSheet("QPushButton{color: rgb(222, 222, 222);font: 75 14pt;border-color: rgb(20, 20, 70);background-color: rgb(30, 30, 90);border-width: 3px;border-style: outset;}"
                                "QPushButton:hover{background-color: rgb(35,35,100);border-color: rgb(25,25,75);}"
                                "QPushButton:pressed{font: 75 14pt;border-style: inset;background-color: rgb(35,35,100);border-color: rgb(25,25,75);}");

    this->setWindowFlags(Qt::FramelessWindowHint);

    this->setFixedSize(this->width(), this->height());

}

Warning::~Warning()
{
    delete ui;
}
