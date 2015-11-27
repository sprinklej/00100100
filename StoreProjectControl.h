#ifndef STOREPROJECTCONTROL_H
#define STOREPROJECTCONTROL_H

#include "User.h";
#include "Project.h";

class StoreProjectControl{
public:
    StoreProjectControl(QList<Project*>&, QList<User*>&);
    ~StoreProjectControl();

    ////Operations
    bool insertProject(Project*, QString); //owner's ID
    bool updateProject(Project*, QString); //student's ID

private:
    QList<Project*> allProjects;

};

#endif // STOREPROJECTCONTROL_H
