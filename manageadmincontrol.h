#ifndef MANAGEADMINCONTROL_H
#define MANAGEADMINCONTROL_H

#include "adminwindow.h"
#include "studentwindow.h"

class StorageFacade;

using namespace std;

class ManageAdminControl
{
public:
    ManageAdminControl(StorageFacade*);
    void createGUI();

private:
    StudentWindow* studWin;
    Admin* user;
    QList<Project*> allProjects;
    QList<Project*> joinedProjects;
    StorageFacade* facade;
};

#endif // MANAGEADMINCONTROL_H
