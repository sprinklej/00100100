#include "StoreProjectControl.h"

StoreProjectControl::StoreProjectControl(QList<Project*>& plist, QList<User*>& ulist){
    allUsers = ulist;
    allProjects = plist;
}

StoreProjectControl::~StoreProjectControl(){

}

bool StoreProjectControl::store(Project* p, QString oID, QString uID, bool newProj){

}

//call this when a new project is created
bool StoreProjectControl::insertProject(Project* project, QString ownerID){

    QSqlQuery query;
    query.prepare("INSERT INTO projects() VALUES (:pid, :oid, (...) )");

    query.bindValue(":pid", project->projectID);
    query.bindValue(":oid", ownerID);

    bool ret = query.execute;
    return ret;

}

//call this when a project is updated.  The QString is empty is an admin is just updating data fields.
//storageFacade needs to checkID() studentID first
bool StoreProjectControl::updateProject(Project* project, QString studentID){

    if(studentID == ""){
        QSqlQuery query;
        query.prepare("UPDATE projects SET "
                        " "
                        "WHERE projedctID = :pid"
                    );
        query.bindValue(":pid", project->projectID);

        bool ret = query.execute;
        return ret;
    }

    //else
    QSqlQuery query;
    query.prepare("INSERT INTO projectsStudents(projectID, studentID) VALUES(:pid, :sid); ");

    query.bindValue(":pid", project->projectID);
    query.bindValue(":sid", studentID);

    bool ret = query.execute;
    return ret;

}
