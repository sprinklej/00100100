#ifndef USER_H
#define USER_H

#include <string>
#include <QString>
using namespace std;


class User
{
protected:
    QString IDNum;          //students start with "1", Admins start with "A"
    QString firstName;
    QString lastName;

public:
    // constructor/destructor
    User();
    ~User();
    // setters

    QString toString();
    // getters
};



class Student : public User
{
protected:
    //list of attribues
    //list of projects

public:
    // constructor/destructor

    Student(QString, QString, QString, int);
    Student();
    ~Student();

    //string toString();
    // setters

    // getters
};



class Admin : public User
{
protected:
    //list of projects

public:
    // constructor/destructor
    Admin();    
    Admin(QString, QString, QString, int);
    ~Admin();

    //string toString();
    // setters

    // getters
};
#endif // USER_H
