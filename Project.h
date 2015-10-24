#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QList>
#include "User.h"
using namespace std;


class Project
{
protected:
    int projectID;
    int courseNum;
    QString pTitle;
    QString courseName;
    QString pDescription;
    QList<Student> students;
    //teams - not sure if we need this one or if the Team object will only exist after the PPID has run

public:
    // constructor/destructor
    //Project(int project_ID, int course_Num, QString p_Title, QString course_Name, QString p_Description, QList<Student> * stdnts);
    Project(int project_ID, int course_Num, QString p_Title, QString course_Name, QString p_Description);
    ~Project();

    // setters
    void setCourseNum(int course_Num);
    void setPTitle(QString p_Title);
    void setPDescription(QString p_Description);
    void addStudent(Student&);

    // getters
    int getProjectID();
    int getCourseNum();
    QString getPTitle();
    QString getCourseName();
    QString getPDescription();
    QList<Student> * getStudentList();  //is this right - return a pointer to the Qlist?
};


#endif // PROJECT_H
