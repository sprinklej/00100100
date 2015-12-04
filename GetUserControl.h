#ifndef GETUSERCONTROL_H
#define GETUSERCONTROL_H

#include "User.h"
#include "Project.h"
#include "QList"
#include "QSqlQuery"
#include "QVariant"

class StorageFacade;

class GetUserControl{
public:
    GetUserControl(QList<User*>&, StorageFacade*, QSqlDatabase&);
    ~GetUserControl();

    bool checkID(QString);
    void getIDs(QList<QString>&);
    void login(User*);
    void registerUser(User*);
    void initializeUsersList();
    QList<User*>& getUsers();

private:
    QList<User*> allUsers;
    StorageFacade* facade;
    QSqlDatabase database;

};

#endif // GETUSERCONTROL_H
