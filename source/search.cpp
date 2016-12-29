#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&search::startsearch);
}

search::~search()
{
    delete ui;
}
void search::startsearch()
{
    QString str=ui->lineEdit->text();
    emit findfor(str);
}
