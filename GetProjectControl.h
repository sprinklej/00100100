#ifndef GETPROJECTCONTROL_H
#define GETPROJECTCONTROL_H

#include "User.h";
#include "Project.h";

class GetProjectControl{
public:
    GetProjectControl(QList<Project*>&, QList<User*>&);
    ~GetProjectControl();

    void prepareStatement(QString, QString);
    void execute(Qlist<Project*>&);
    void intitializeProjects();

private:
    QList<Project*> allProjects;
    QList<User*> allUsers;
};

#endif // GETPROJECTCONTROL_H
