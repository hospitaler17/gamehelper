#-------------------------------------------------
#
# Project created by QtCreator 2023-05-02T19:38:12
#
#-------------------------------------------------

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
                objects

SOURCES += \
        main.cpp \
    objects/person.cpp \
    xmlparser.cpp \
    processor.cpp \
    objects/battle.cpp \
    forms/fmaddperson.cpp \
    forms/fmaddbattle.cpp \
    forms/fmmainmenu.cpp \
    forms/fmaddspells.cpp \
    forms/fmaddmap.cpp \
    objects/map.cpp \
    objects/spell.cpp \
    objects/baseobject.cpp \
    forms/baseform.cpp

HEADERS += \
    objects/person.h \
    common.h \
    xmlparser.h \
    processor.h \
    objects/battle.h \
    forms/fmaddperson.h \
    forms/fmaddbattle.h \
    forms/fmmainmenu.h \
    forms/fmaddspells.h \
    forms/fmaddmap.h \
    objects/map.h \
    objects/spell.h \
    objects/baseobject.h \
    forms/baseform.h

FORMS += \
    forms/fmaddperson.ui \
    forms/fmaddbattle.ui \
    forms/fmmainmenu.ui \
    forms/fmaddspells.ui \
    forms/fmaddmap.ui
