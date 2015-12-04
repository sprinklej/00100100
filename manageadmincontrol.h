#ifndef MANAGEADMINCONTROL_H
#define MANAGEADMINCONTROL_H

#include "adminwindow.h"
#include "projectwindow.h"
class StorageFacade;

using namespace std;

class ManageAdminControl
{
public:
    ManageAdminControl(StorageFacade*);
    void setAdmWind(AdminWindow*);
    void createGUI();
    void refresh();
    void editProject();
    void newProject();
    void logout();
    void runPPID();

    // project window
    void saveProject();

    // setters
    void setAdmin(Admin*);

private:
    AdminWindow* admWin;
    Admin* user;
    QList<Project*> allProjects;
    QList<Project*> joinedProjects;
    StorageFacade* facade;
};

#endif // MANAGEADMINCONTROL_H
