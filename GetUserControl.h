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
    GetUserControl(QList<User*>&, StorageFacade*);
    ~GetUserControl();

    bool checkID(QString);
    void getIDs(QList<QString>&);
    void login(User*);
    void registerUser(User*);
    void initializeUsersList();

private:
    QList<User*> allUsers;
    StorageFacade* facade;

};

#endif // GETUSERCONTROL_H
