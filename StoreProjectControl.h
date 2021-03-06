#ifndef STOREPROJECTCONTROL_H
#define STOREPROJECTCONTROL_H

#include "User.h"
#include "Project.h"
#include "QSqlQuery"
#include "QSqlError"

class StoreProjectControl{
public:
    StoreProjectControl(QList<Project*>&, QList<User*>&, QSqlDatabase&);
    StoreProjectControl();
    ~StoreProjectControl();

    ////Operations
    bool store(Project*, QString, QString, bool);
    bool insertProject(Project*, QString); //owner's ID
    bool updateProject(Project*, QString); //student's ID

private:
    QList<Project*> allProjects;
    QList<User*> allUsers;
    QSqlDatabase database;

};

#endif // STOREPROJECTCONTROL_H
