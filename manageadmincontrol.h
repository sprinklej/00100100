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
    void editProject(QString);
    void newProject();
    void logout();
    void runPPID(QString);

    // project window
    void saveProject(bool, ProjectWindow*, QString, QString, QString, int, QString);

    // setters
    void setAdmin(Admin*);

private:
    AdminWindow* admWin;
    Admin* user;
    QList<Project*> allProjects;
    QList<Project*> ownedProjects;
    StorageFacade* facade;
    Project* projectBeingEdited;
    Project* PPIDProject;
};

#endif // MANAGEADMINCONTROL_H
