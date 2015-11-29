#ifndef GETPROJECTCONTROL_H
#define GETPROJECTCONTROL_H

#include "User.h"
#include "Project.h"
#include "QList"
#include "QSqlQuery"

class GetProjectControl{
public:
    GetProjectControl(QList<Project*>&, QList<User*>&, QSqlDatabase&);
    ~GetProjectControl();

    void prepareStatement(QString, QString);
    void execute(QList<Project*>&);
    void intitializeProjects();

private:
    QList<Project*> allProjects;
    QList<User*> allUsers;
    QSqlDatabase database;
};

#endif // GETPROJECTCONTROL_H
