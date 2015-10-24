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


Student::Student(QString fn, QString ln, QString id, int a1){
    firstName = fn;
    lastName = ln;
    IDNum = id;
    att1=a1;
}

Student::~Student(){}

//////////// GETTERS /////////////////////
QString Student::getIDNum(){return IDNum;}          //students start with "1", Admins start with "A"
QString Student::getUserName(){return userName;}
QString Student::getFirstName(){return firstName;}
QString Student::getLastName(){return lastName;}
int Student::getAtt1(){return att1;}


Admin::Admin(QString fn, QString ln, QString id, int a1){
    firstName = fn;
    lastName = ln;
    IDNum = id;
}

Admin::~Admin(){}

/////////// GETTERS ////////////
QString Admin::getIDNum(){return IDNum;}          //students start with "1", Admins start with "A"
QString Admin::getUserName(){return userName;}
QString Admin::getFirstName(){return firstName;}
QString Admin::getLastName(){return lastName;}
