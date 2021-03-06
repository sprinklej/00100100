#ifndef STORAGEFACADE_H
#define STORAGEFACADE_H

/*replace these with headers once written*/
#include "manageadmincontrol.h"
#include "managestudentcontrol.h"
#include "manageRegistrationControl.h"
#include "managequalificationcontrol.h"

#include "StoreProjectControl.h"
#include "GetProjectControl.h"
#include "StoreUserControl.h"
#include "GetUserControl.h"

#include "Storage.h"
#include "User.h"


class StorageFacade{
public:
    // operations
    StorageFacade();
    ~StorageFacade();
    void run();
    void storeProject(Project*, QString, QString, bool);
    void writeUser(User*);
    void getProjects(QList<Project*>&);
    void getUserIDs(QList<QString>&);
    void handleLogin(ManageRegistrationControl *, QString);
    void handleRegister(User*);
    void handleLogout();
    void setLoggedInUser(User*);

    // setters
    void setAllUsers(QList<User*>);
    void setAllProjects(QList<Project*>);

    // getters
    User* getLoggedInUser();

    // attributes and relationships
    //void setDB(QSqlDatabase&);

private:
    // relationships to subsystem
    StoreProjectControl* storeProjectControl;
    GetProjectControl* getProjectControl;
    StoreUserControl* storeUserControl;
    GetUserControl* getUserControl;

    //other subsystems
    ManageAdminControl* adMgr;
    ManageStudentControl* stMgr;
    ManageRegistrationControl* regMgr;

    //internal data
    User* loggedInUser;
    QList<User*> allUsers;
    QList<Project*> allProjects;
    bool executing;

    Storage* storage;
    QSqlDatabase database;

};


#endif // STORAGEFACADE_H
