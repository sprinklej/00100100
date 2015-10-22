#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T15:13:18
#
#-------------------------------------------------

QT       += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMP3004
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Team.cpp \
    Project.cpp \
    User.cpp

HEADERS  += mainwindow.h \
    Storage.h \
    User.h \
    Team.h \
    Project.h

FORMS    += mainwindow.ui
