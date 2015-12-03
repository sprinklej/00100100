#ifndef MANAGESTUDENTCONTROL_H
#define MANAGESTUDENTCONTROL_H

#include "qualificationwindow.h"
#include "studentwindow.h"
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
    void createGUI();

    // setters
    void setStudent(Student*);
    void setJoinedProjects(QList<Project*>);

    // getters
    Student* getCurrentUser();

private:
    StudentWindow* studWin;
    Student* user;
    QList<Project*> allProjects;
    QList<Project*> joinedProjects;
    StorageFacade* facade;
};

#endif // MANAGESTUDENTCONTROL_H
