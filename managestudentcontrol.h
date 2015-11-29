#ifndef MANAGESTUDENTCONTROL_H
#define MANAGESTUDENTCONTROL_H

class StudentWindow;
#include "studentwindow.h"

//#include "Storage.h"
#include "qualificationwindow.h"
#include "loginwindow.h"
class StorageFacade;

using namespace std;

class ManageStudentControl
{
public:
    ManageStudentControl(StorageFacade*);
    void setStudWind(StudentWindow*);
    void refresh();
    void joinProject(QString currentProj);
    void manageQualifications();
    void logout();

    // set student
    void setStudent(Student*);
    Student* getCurrentUser();

private:
    StudentWindow* studWin;
    Student* user;
    QList<Project*> allProjects;
    QList<Project*> joinedProjects;
    StorageFacade* facade;
};

#endif // MANAGESTUDENTCONTROL_H
