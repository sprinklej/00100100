#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QList>
#include "User.h"


using namespace std;


class Project
{
protected:
    QString projectID;
    QString courseNum;
    QString ownerID;
    QString courseName;
    QString pDescription;
    int teamSize;
    QList<Student*> students;
    //teams - not sure if we need this one or if the Team object will only exist after the PPID has run

public:
    // constructor/destructor
    //Project(int project_ID, int course_Num, QString p_Title, QString course_Name, QString p_Description, QList<Student> * stdnts);
    //     Project* newProj = new Project(projectID, ad.getIDNum(), courseName, courseNum, description, teamSize);
    Project(QString project_ID, QString own, QString course_Name, QString course_Num, QString p_Description, int ts);
    ~Project();

    // setters
    void setCourseNum(QString course_Num);
    void setPTitle(QString p_Title);
    void setPDescription(QString p_Description);
    void addStudent(Student*);

    // getters
    QString getProjectID();
    QString getCourseNum();
    QString getCourseName();
    QString getPDescription();
    int getTeamSize();
    QList<Student*>& getStudentList();
};


#endif // PROJECT_H
