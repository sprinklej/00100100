#ifndef GETPROJECTCONTROL_H
#define GETPROJECTCONTROL_H

#include "User.h"
#include "Project.h"
#include "QList"
#include "QSqlQuery"

class GetProjectControl{
public:
    GetProjectControl(QList<Project*>&, QList<User*>&);
    ~GetProjectControl();

    void prepareStatement(QString, QString);
    void execute(QList<Project*>&);
    void intitializeProjects();

private:
    QList<Project*> allProjects;
    QList<User*> allUsers;
};

#endif // GETPROJECTCONTROL_H
