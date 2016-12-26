#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T10:03:07
#
#-------------------------------------------------

QT       += core gui network widgets

TARGET = werewolf
TEMPLATE = app


SOURCES += main.cpp\
        hall.cpp \
    warning.cpp \
    createroom.cpp \
    login.cpp \
    gui.cpp \
    gamewindow.cpp \
    dialog.cpp \
    message.cpp \
    tcpsock.cpp

HEADERS  += hall.h \
    warning.h \
    createroom.h \
    login.h \
    gui.h \
    gamewindow.h \
    dialog.h \
    message.h \
    tcpsock.h

FORMS    += hall.ui \
    warning.ui \
    createroom.ui \
    login.ui \
    gamewindow.ui \
    dialog.ui

RESOURCES += \
    myresource.qrc \
    image.qrc

RC_FILE  += myico.rc
