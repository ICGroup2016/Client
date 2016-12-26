#include "gui.h"
#include<gamewindow.h>
gui::gui()
{
    QObject::connect(&g,&GameWindow::prepared,this,&gui::gprepared);
    QObject::connect(&g,&GameWindow::unprepared,this,&gui::gunprepared);
    QObject::connect(&g,&GameWindow::goback,this,&gui::ggoback);
    QObject::connect(&g,&GameWindow::endturn,this,&gui::gendturn);
    QObject::connect(&g,&GameWindow::explode,this,&gui::gexplode);
}
void gui::showgame()
{
    g.show();
}

void gui::flush(QVector<QPair<int, int> > vect, int prepared)
{
    QVector<QPair<int,int>>::iterator i;
    for(i=vect.begin();i!=vect.end();i++){
    g.addplayer(i->first,i->second);}
    g.showprepared(prepared);
}
void gui::myplayer(int seat, int id)
{
    g.myplayer(seat,id);
}

void gui::gprepared()
{
    emit ready();
}
void gui::gunprepared()
{
    emit cancel();
}
void gui::ggoback()
{
    emit quit();
}

void gui::role(int role)
{
    g.start(role);
}
void gui::showmessage(int seat, QString str)
{
    g.getmessage(seat,str);
}
void gui::gspeak(QString str)
{
    emit speak(str);
}
void gui::myturn()
{
    g.myturn();
}
void gui::gendturn()
{
    emit endspeaking();
}

/*void gui::gameover()
{
    g.gameover();
}*/
/*int gui::wolfsturn(QVector<int> player)
{
    return g.wolfsturn(player);
}*/
int gui::decide(QVector<int> player,bool choose0)
{
    if(choose0==false)
    return g.vote(player);
    else
    return g.poison(player);
}


bool gui::choose()
{
    return g.officercandidate();
}
/*bool gui::medicine()
{
    return g.medicine();
}
int gui::poison(QVector<int> player)
{
    return g.poison(player);
}
int gui::prophet(QVector<int> player)
{
    return g.prophet(player);
}
int gui::hunter(QVector<int> player)
{
    return g.hunter(player);
}
bool gui::officerdecide()
{
    return g.officerdecide();
}*/
void gui::gexplode()
{
    emit explode();
}
void gui::endturn()
{
    g.endturn();
}
