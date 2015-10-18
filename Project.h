#ifndef PROJECT_H
#define PROJECT_H

#include <string.h>

class Project
{
protected:
    int projectID;
    string pTitle;
    int courseNum;
    string courseName;
    string pDescription;
    //list of students
    //teams - not sure if we need this one

public:
    Project(); // default constructor
    ~Project(); // destructor
};

#endif // PROJECT_H
