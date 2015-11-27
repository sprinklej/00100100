#ifndef STORAGEFACADE_H
#define STORAGEFACADE_H

/*replace these with headers once written*/
class AdminManager;
class StudentManager;
class RegistrationManager;

class StoreProjectControl;
class GetProjectsControl;
class StoreUserControl;
class GetUsersControl;

class Storage;
#include "User.h";

class StorageFacade{
public:
    // operations
    StorageFacade();
    ~StorageFacade();
    void run();
    void storeProject(Project*, String, String, bool);
    void writeUser(User*);
    void getProjects(QList<Project*>&);
    void getUserIDs(QList<QString>&);
    void handleLogin(User*);
    void handleRegister(User*);
    void handleLogout();

    // attributes and relationships


private:
    // relationships to subsystem
    StoreProjectControl storeProjectsControl;
    GetProjectsControl getProjectControl;
    StoreUserControl storeUserControl;
    GetUsersControl getUsersControl;

    //other subsystems
    AdminManager* adMgr;
    StudentManager* stMgr;
    RegistrationManager* rgMgr;

    //internal data
    User* loggedInUser;
    QList<User*> allUsers;
    QList<Project*> allProjects;
    bool executing;

    static Storage storage;

};


#endif // STORAGEFACADE_H
