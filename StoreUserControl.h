#ifndef STOREUSERCONTROL_H
#define STOREUSERCONTROL_H

#include "User.h"
#include "Project.h"
#include "SQLContext.h"
#include "QSqlQuery"

class StoreUserControl{
public:
    StoreUserControl(QList<Project*>&, QList<User*>&);
    ~StoreUserControl();

    /////Operations
    void store(User*);
    void createQuery(bool, User*);
    bool run(QSqlQuery);

private:
    QList<User*> allUsers;
    QList<Project*> allProjects;

    ///// Associations
    SQLContext context;


};


#endif // STOREUSERCONTROL_H
