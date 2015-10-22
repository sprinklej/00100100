#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <QList>
#include "User.h"
using namespace std;


class Project
{
protected:
    int projectID;
    int courseNum;
    string pTitle;
    string courseName;
    string pDescription;
    QList<Student> students;
    //teams - not sure if we need this one or if the Team object will only exist after the PPID has run

public:
    // constructor/destructor
    Project(int project_ID, int course_Num, string p_Title, string course_Name, string p_Description, QList<Student> * stdnts);
    ~Project();

    // setters
    void setCourseNum(int course_Num);
    void setPTitle(string p_Title);
    void setPDescription(string p_Description);
    void addStudent(Student * stdnt);

    // getters
    int getProjectID();
    int getcourseNUm();
    string getPTitle();
    string getCourseName();
    string getPDescription();
    QList * getStudentList();  //is this right - return a pointer to the Qlist?

};
#endif // PROJECT_H
