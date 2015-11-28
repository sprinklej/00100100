#ifndef STOREPROJECTCONTROL_H
#define STOREPROJECTCONTROL_H

#include "User.h"
#include "Project.h"
#include "QSqlQuery"

class StoreProjectControl{
public:
    StoreProjectControl(QList<Project*>&, QList<User*>&);
    StoreProjectControl();
    ~StoreProjectControl();

    ////Operations
    bool store(Project*, QString, QString, bool);
    bool insertProject(Project*, QString); //owner's ID
    bool updateProject(Project*, QString); //student's ID

private:
    QList<Project*> allProjects;
    QList<User*> allUsers;

};

#endif // STOREPROJECTCONTROL_H
