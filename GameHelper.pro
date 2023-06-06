#-------------------------------------------------
#
# Project created by QtCreator 2023-05-02T19:38:12
#
#-------------------------------------------------
include(common.pri)

QT       += core gui xml


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameHelper
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += forms \
                objects \
                widgets

SOURCES += \
        main.cpp \
    widgets/scaledpixmap.cpp \
    xmlparser.cpp \
    processor.cpp \
    forms/fmaddperson.cpp \
    forms/fmaddbattle.cpp \
    forms/fmmainmenu.cpp \
    forms/fmaddspells.cpp \
    forms/fmaddmap.cpp \
    objects/spell.cpp \
    objects/baseobject.cpp \
    forms/baseform.cpp \
    objects/effect.cpp \
    forms/fmaddmoster.cpp \
    objects/item.cpp \
    game/maps/globalmap.cpp \
    game/maps/battle.cpp \
    game/maps/battlefield.cpp \
    game/maps/map.cpp \
    game/actors/monster.cpp \
    game/actors/person.cpp

HEADERS += \
    common.h \
    widgets/scaledpixmap.h \
    xmlparser.h \
    processor.h \
    forms/fmaddperson.h \
    forms/fmaddbattle.h \
    forms/fmmainmenu.h \
    forms/fmaddspells.h \
    forms/fmaddmap.h \
    objects/spell.h \
    objects/baseobject.h \
    forms/baseform.h \
    objects/effect.h \
    forms/fmaddmoster.h \
    objects/item.h \
    game/maps/globalmap.h \
    game/maps/battle.h \
    game/maps/battlefield.h \
    game/maps/map.h \
    game/actors/monster.h \
    game/actors/person.h

FORMS += \
    forms/fmaddperson.ui \
    forms/fmaddbattle.ui \
    forms/fmmainmenu.ui \
    forms/fmaddspells.ui \
    forms/fmaddmap.ui \
    forms/fmaddmoster.ui
