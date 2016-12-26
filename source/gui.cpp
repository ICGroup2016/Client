#include "gui.h"
#include "createroom.h"
#include "hall.h"
#include "warning.h"
#include "login.h"
#include <QtCore>
#include <QObject>
#include <QDesktopServices>
#include <QUrl>



gui::gui(QObject *parent)
    :QObject(parent)
{
    QObject::connect(&w,&hall::createbutton_clicked,this,&gui::showcreateroom);
    QObject::connect(&c,&createroom::newroom,this,&gui::onenewroom);
    QObject::connect(&w,&hall::enterroom,this,&gui::enterroom);
    QObject::connect(&w,&hall::openlogin,this,&gui::openlogin);
    QObject::connect(&w,&hall::openweb,this,&gui::openweb);
    QObject::connect(&w,&hall::warning,this,&gui::WArning);

    QObject::connect(&g,&GameWindow::prepared,this,&gui::gprepared);
    QObject::connect(&g,&GameWindow::unprepared,this,&gui::gunprepared);
    QObject::connect(&g,&GameWindow::goback,this,&gui::ggoback);
    QObject::connect(&g,&GameWindow::exit,this,&gui::gexit);
    QObject::connect(&g,&GameWindow::endturn,this,&gui::gendturn);
}

QPair<QString,int> gui::acquireServer(){
    return l.getpair();
}

void gui::showHall(){
    w.setup(l.getpair().first,QString::number(l.getpair().second,10));
    w.show();
}

void gui::showlogin(){
    l.exec();
}

void gui::showcreateroom(){
    c.exec();
}

void gui::onenewroom(const QPair<QString, int> pair){
    emit Newroom(pair);
    c.hide();
}

void gui::warning(){
    Warning warning;
    warning.exec();
}

void gui::addroom(QString a, QString b){
    w.addroom(a,b);
}

void gui::removeroom(){
    w.removeall();
}

void gui::enterroom(const QString ip){
    emit enterRoom(ip);
}

void gui::enterroomok(){
    w.hide();
    g.show();
}

void gui::openlogin(){
    w.hide();
    l.reset();
    l.show();
}

void gui::openweb(){
    QDesktopServices::openUrl(QUrl("http://baike.baidu.com/link?url=NIp1tudVwrioy0g3GF4QEles_ctV6TEpD_-sQ21huAlzyu7m-g4l1WrnQzhSovRjZpaJ1Zf3hMsrjejzpOESFludN9CZfCfA2F4PPDvXEdYTww_NCJP6unzDD6DiNGGd"));
}

void gui::hidehall(){
    w.hide();
}

void gui::WArning(){
    warning();
}


void gui::showgame()
{
    g.show();
}

void gui::addplayer(int seat,int id)
{
    g.addplayer(seat-1,id);
}
void gui::myplayer(int seat, int id)
{
    g.myplayer(seat-1,id);
}

void gui::gprepared(int id)
{
    emit prepared(id);
}
void gui::gunprepared(int id)
{
    emit unprepared(id);
}
void gui::ggoback(int id)
{
    emit goback(id);
    w.show();
}
void gui::gexit(int id)
{
    emit exit(id);
}
void gui::start(int role)
{
    g.start(role);
}
void gui::getmessage(int seat, QString str)
{
    g.getmessage(seat,str);
}
void gui::gspeak(int id,QString str)
{
    emit speak(id,str);
}
void gui::myturn()
{
    g.myturn();
}
void gui::gendturn()
{
    emit endturn();
}

void gui::gameover()
{
    g.gameover();
}
void gui::wolfwakeup()
{
    g.wolfwakeup();
}

void gui::wolfsleep()
{
    g.wolfsleep();
}
void gui::gchoice(int seat)
{
    emit choice(seat);
}
void gui::prophetwakeup()
{
    g.prophetwakeup();
}
void gui::prophetsleep()
{
    g.prophetsleep();
}
void gui::killed(int seat)
{
    g.killed(seat);
}
