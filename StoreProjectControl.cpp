#include "StoreProjectControl.h"
#include "QVariant"
#include "QDebug"

StoreProjectControl::StoreProjectControl(QList<Project*>& plist, QList<User*>& ulist, QSqlDatabase& db){
    allUsers = ulist;
    allProjects = plist;
    database = db;
}

StoreProjectControl::~StoreProjectControl(){

}

bool StoreProjectControl::store(Project* p, QString sID, QString oID, bool newProj){

    qDebug() << "Storecontrol::store -" << p->getProjectTitle() << oID << sID << newProj;

    if(oID == "" && sID == "") return false;

    //This is an Admin modifying an existing project
    // UPDATE projects
    if(!newProj){

        return updateProject(p, "");
    }

    //This is an Admin creating a new project
    //INSERT into projects
    if(sID == "" && newProj){
        return insertProject(p, oID);
    }



    //This is a Student joining an existing Project
    //INSERT into projectsStudents
    return updateProject(p, sID);

}

//call this when a new project is created
bool StoreProjectControl::insertProject(Project* pr, QString own){

    database.open();
    QSqlQuery query;
    query.prepare("INSERT INTO projects(projectDesc, owner, courseName, courseNum, description, teamSize)"
                  "VALUES (:ipd, :iow, :icn, :icnm, :ides, :its)");
    //query.bindValue(":ipr", pr->getProjectID());
    query.bindValue(":ipd", pr->getProjectTitle());
    query.bindValue(":iow", own);//->getIDNum());
    query.bindValue(":icn", pr->getCourseName());
    query.bindValue(":icnm", pr->getCourseNum());
    query.bindValue(":ides", pr->getPDescription());
    query.bindValue(":its", pr->getTeamSize());
    bool res = query.exec();
    qDebug() << query.lastError();
    return res;

}

//call this when a project is updated.  The QString is empty is an admin is just updating data fields.
//storageFacade needs to checkID() studentID first
bool StoreProjectControl::updateProject(Project* pr, QString studentID){
    database.open();
    if(studentID == ""){



        QSqlQuery query;
        query.prepare("UPDATE projects SET "
                      "projectDesc = :pd, courseName = :icn, courseNum = :icnm, description = :ides, teamSize = :its "
                      "WHERE projectID = :ipr");
        query.bindValue(":pd", pr->getProjectTitle());
        query.bindValue(":icn", pr->getCourseName());
        query.bindValue(":icnm", pr->getCourseNum());
        query.bindValue(":ides", pr->getPDescription());
        query.bindValue(":its", pr->getTeamSize());
        query.bindValue(":ipr", pr->getProjectID());


        qDebug() << query.lastQuery();
                qDebug() << pr->getProjectID();
        bool res = query.exec();
        qDebug() << "Update a project";

        qDebug() << query.lastError();
        return res;
    }

    //else
    QSqlQuery query;
    query.prepare("INSERT INTO projectsStudents(userID, projectID) VALUES(:iu, :ip)");
    query.bindValue(":iu", studentID);//st->getIDNum());
    query.bindValue(":ip", pr->getProjectID());
    bool res = query.exec();
    return res;

}
