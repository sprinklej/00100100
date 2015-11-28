#include "StoreProjectControl.h"
#include "QVariant"
#include "QDebug"

StoreProjectControl::StoreProjectControl(QList<Project*>& plist, QList<User*>& ulist){
    allUsers = ulist;
    allProjects = plist;
}

StoreProjectControl::~StoreProjectControl(){

}

bool StoreProjectControl::store(Project* p, QString oID, QString sID, bool newProj){
    if(oID == "" && sID == "") return false;

    //This is an Admin creating a new project
    //INSERT into projects
    if(sID == ""){
        return insertProject(p, oID);
    }

    //This is an Admin modifying an existing project
    // UPDATE projects
    if(newProj){
        return updateProject(p, "");
    }

    //This is a Student joining an existing Project
    //INSERT into projectsStudents
    return updateProject(p, sID);

}

//call this when a new project is created
bool StoreProjectControl::insertProject(Project* pr, QString own){

    QSqlQuery query;
    query.prepare("INSERT INTO projects(projectID, owner, courseName, courseNum, description, teamSize)"
                  "VALUES (:ipr, :iow, :icn, :icnm, :ides, :its)");
    query.bindValue(":ipr", pr->getProjectID());
    query.bindValue(":iow", own);//->getIDNum());
    query.bindValue(":icn", pr->getCourseName());
    query.bindValue(":icnm", pr->getCourseNum());
    query.bindValue(":ides", pr->getPDescription());
    query.bindValue(":ides", pr->getTeamSize());
    bool res = query.exec();
    return res;

}

//call this when a project is updated.  The QString is empty is an admin is just updating data fields.
//storageFacade needs to checkID() studentID first
bool StoreProjectControl::updateProject(Project* pr, QString studentID){

    if(studentID == ""){
        QSqlQuery query;
        query.prepare("UPDATE projects SET "
                      "courseName = :icn, courseNum = :icnm, description = :ides, teamSize = :its "
                      "WHERE projectID = :ipr");
        //query.bindValue(":iow", own.getIDNum());
        query.bindValue(":icn", pr->getCourseName());
        query.bindValue(":icnm", pr->getCourseNum());
        query.bindValue(":ides", pr->getPDescription());
        query.bindValue(":ipr", pr->getProjectID());
        query.bindValue(":its", pr->getTeamSize());
        bool res = query.exec();
        qDebug() << query.lastError();
        return res;
    }

    //else
    QSqlQuery query;
    query.prepare("INSERT INTO projectsStudents(userID, projectID) VALUES(:iu, :ip)");
    query.bindValue(":iu", st->getIDNum());
    query.bindValue(":ip", pr->getProjectID());
    bool res = query.exec();
    return res;

}
