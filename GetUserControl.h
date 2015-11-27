#ifndef GETUSERCONTROL_H
#define GETUSERCONTROL_H

#include "User.h";
#include "Project.h";

class GetUserControl{
public:
    GetUsersControl(Qlist<User*>&);
    ~GetUsersControl();

    bool checkID(QString);
    void getIDs(Qlist<QString>&);
    void login(User*);
    void registerUser(User*);
    void initializeUsersList();

private:
    QList<User*> allUsers;

};

#endif // GETUSERCONTROL_H
