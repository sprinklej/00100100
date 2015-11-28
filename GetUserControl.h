#ifndef GETUSERCONTROL_H
#define GETUSERCONTROL_H

#include "User.h"
#include "Project.h"
#include "QList"

class GetUserControl{
public:
    GetUserControl(QList<User*>&);
    ~GetUserControl();

    bool checkID(QString);
    void getIDs(QList<QString>&);
    void login(User*);
    void registerUser(User*);
    void initializeUsersList();

private:
    QList<User*> allUsers;

};

#endif // GETUSERCONTROL_H
