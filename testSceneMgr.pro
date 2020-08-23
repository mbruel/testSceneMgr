#-------------------------------------------------
#
# Project created by QtCreator 2016-09-16T23:47:45
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testSceneMgr
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Element.cpp \
    LinkElement.cpp \
    graphics/ComplexItem.cpp \
    graphics/LinkNMItem.cpp \
    DeleteElementAction.cpp

HEADERS  += mainwindow.h \
    Element.h \
    LinkElement.h \
    graphics/ComplexItem.h \
    graphics/LinkNMItem.h \
    graphics/GraphicItem.h \
    DeleteElementAction.h

FORMS    += mainwindow.ui
