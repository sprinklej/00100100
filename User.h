#ifndef USER_H
#define USER_H

#include <string>
using namespace std;


class User
{
protected:
    int IDNum;          //students start with "1", Admins start with "A"
    string firstName;
    string lastName;

public:
    // constructor/destructor
    User();
    ~User();

    // setters

    // getters
};



class Student : public User
{
protected:
    //list of attribues
    //list of projects

public:
    // constructor/destructor
    Student();
    ~Student();

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
    ~Admin();

    // setters

    // getters
};
#endif // USER_H
