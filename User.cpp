#include "User.h"

User::User()
{
;
}

User::~User(){}

QString User::toString(){
    QString ret = "User: ";
    ret.append(firstName);
    ret.append(" ");
    ret.append(lastName);
    ret.append(" ");
    ret.append(IDNum);
    return ret;
}

Student::Student()
{
;
}

Student::Student(QString fn, QString ln, QString id, int a1){
    firstName = fn;
    lastName = ln;
    IDNum = id;
}


Admin::Admin()
{
;
}

Admin::Admin(QString fn, QString ln, QString id, int a1){
    firstName = fn;
    lastName = ln;
    IDNum = id;
}

