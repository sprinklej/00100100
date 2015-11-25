#include "managestudentcontrol.h"
#include <iostream>
#include <QDebug>
using namespace std;

ManageStudentControl::ManageStudentControl()
{
    studWin = NULL;
}

void ManageStudentControl::setStudWind(StudentWindow* stWin)
{
    studWin = stWin;
}


// Control for a student joining a project
void ManageStudentControl::joinProject()
{
    qDebug() << "join project control!";

    // do work here


    // send update to studentWindow
    QString st= "Manage Student Control - test";
    studWin->setStatus2(st);
    return;
}
