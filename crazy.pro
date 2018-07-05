#-------------------------------------------------
#
# Project created by QtCreator 2018-06-09T18:18:01
#
#-------------------------------------------------
CONFIG+=resources_big
QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crazy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    container.cpp \
    icon.cpp \
    monster.cpp \
    player.cpp \
    rival.cpp \
    rpgobj.cpp \
    weapon.cpp \
    world.cpp \
    npc.cpp \
    bet_animal.cpp \
    gamemodel.cpp \
    elf.cpp

HEADERS  += mainwindow.h \
    container.h \
    icon.h \
    monster.h \
    player.h \
    rival.h \
    rpgobj.h \
    weapon.h \
    world.h \
    npc.h \
    bet_animal.h \
    gamemodel.h \
    elf.h

FORMS    += mainwindow.ui

RESOURCES += \
    sound.qrc \
    image.qrc
