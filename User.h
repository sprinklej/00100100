#ifndef USER_H
#define USER_H

#include <string.h>

class User
{
protected:
    int IDNum;          //students start with "1", Admins start with "A"
    string firstName;
    string lastName;

public:
    User(); // default constructor
    ~User(); // destructor
};



class Student : public User
{
private:
    //list of attribues
    //list of projects

public:
    Student();
    ~Student();
};



class Admin : public User
{
private:
    //list of projects

public:
    Admin();
    ~Admin();
};
#endif // USER_H
