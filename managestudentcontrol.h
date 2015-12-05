#ifndef MANAGESTUDENTCONTROL_H
#define MANAGESTUDENTCONTROL_H

#include "studentwindow.h"
#include "managequalificationcontrol.h"
class StorageFacade;

using namespace std;

class ManageStudentControl
{
public:
    ManageStudentControl(StorageFacade*);
    void setStudWind(StudentWindow*);
    void refresh();
    void joinProject(QString currentProj);
    void manageQuals();
    void logout();
    void createGUI();
    void updateUserInfo();

    // setters
    void setStudent(Student*);

    // getters
    Student* getCurrentUser();

private:
    StudentWindow* studWin;
    Student* user;
    QList<Project*> allProjects;
    QList<Project*> joinedProjects; // remove?
    StorageFacade* facade;
};

#endif // MANAGESTUDENTCONTROL_H
