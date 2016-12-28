#include "hall.h"
#include "login.h"
#include <QApplication>
#include "gui.h"
#include "core.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<Message>();
    Core core;
    return a.exec();
}
