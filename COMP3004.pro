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
    Team.cpp \
    Project.cpp \
    User.cpp \
    loginwindow.cpp \
    Storage.cpp \
    studentwindow.cpp \
    adminwindow.cpp \
    signupwindow.cpp \
    qualificationwindow.cpp \
    projectwindow.cpp \
    managestudentcontrol.cpp

HEADERS  += \
    Storage.h \
    User.h \
    Team.h \
    Project.h \
    loginwindow.h \
    studentwindow.h \
    adminwindow.h \
    signupwindow.h \
    qualificationwindow.h \
    projectwindow.h \
    managestudentcontrol.h

FORMS    += \
    loginwindow.ui \
    studentwindow.ui \
    adminwindow.ui \
    signupwindow.ui \
    qualificationwindow.ui \
    projectwindow.ui
