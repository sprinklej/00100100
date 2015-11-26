#ifndef MANAGESTUDENTCONTROL_H
#define MANAGESTUDENTCONTROL_H

class StudentWindow;
#include "studentwindow.h"

#include "Storage.h"
#include "qualificationwindow.h"

using namespace std;

class ManageStudentControl
{
public:
    ManageStudentControl();
    void setStudWind(StudentWindow*);
    void refresh();
    void joinProject(QString currentProj);
    void manageQualifications();

    // set student
    void setStudent(Student*);

private:
    StudentWindow* studWin;
    Student* user;
    QList<Project*> allProjects;
    QList<Project*> joinedProjects;
};

#endif // MANAGESTUDENTCONTROL_H
