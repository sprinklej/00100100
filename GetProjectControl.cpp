#include "GetProjectControl.h";
#include "StorageFacade.h"

#include "QDebug"

GetProjectControl::GetProjectControl(StorageFacade* f, QList<Project*>& pList, QList<User*>& uList, QSqlDatabase& db){
    facade = f;
    allProjects = pList;
    //allUsers = uList;
    database = db;
}

GetProjectControl::~GetProjectControl(){
}

void GetProjectControl::setUsers(QList<User*>& uList){
     allUsers = uList;
}

//Note: this function links projects and students, and must be run AFTER the users are retrieved from storage
void GetProjectControl::intitializeProjects(){
    //clear out the existing projects
    Project* p;
    qDeleteAll(allProjects);
    allProjects.clear();
    //also empty the students' projects
    User* u;
qDebug() <<  "start of getProejcts -- here arethe users";
    foreach(u, allUsers){
qDebug() <<  u->getID();
        //if(u->getProjects()){
        //    qDeleteAll(u->getProjects()->begin(), u->getProjects()->end());
        //    u->getProjects()->clear();
        //}
    }

    //now go get the projects...
    database.open();
    QSqlQuery query;
    query.exec("SELECT * FROM projects;");

    //query.exec();

    qDebug() << "query executed";

    Project* newProj;

    while(query.next()){
        QString projectID = query.value(0).toString();
        QString projectTitle = query.value(1).toString();
        QString ownerID = query.value(2).toString();
        QString courseName = query.value(3).toString();
        QString courseNum = query.value(4).toString();
        QString description = query.value(5).toString();
        int teamSize = query.value(6).toInt();

        newProj = new Project(projectID, projectTitle, ownerID, courseName, courseNum, description, teamSize);
qDebug() << "Found: " << newProj->getProjectTitle();
        allProjects.push_back(newProj);
    }

    //now link the projects and students
    QSqlQuery query2;
    query2.exec("SELECT * FROM projectsStudents;");

    while (query2.next()) {
        QString sID = query2.value(0).toString();
        QString pID = query2.value(1).toString();

        Project* p;
        User* u;

        foreach(p, allProjects){
            foreach(u, allUsers){

                if(p->getProjectID() == pID && u->getID() == sID) {


                    if(!u->getProjects()){
                        u->initializeProjects();
                    }

                    Student* s = dynamic_cast<Student*>(u);

                    ///TODO////////////
                    ///Adding proejcts to a student's collection is where the problem is.
                    ///This approach just isnt working
                    ///I have spent too long on this and need to move on to the PPID and other functions
                    ///If we have time, I suggest getting back to it and making a third collection class in
                    ///repository, which just links <Qsyring><Qstring> pairs of student and project ids
                    //s->projects->push_back((Project* const&)p);


                    //(dynamic_cast<Student*>(u))->Student::getProjects()->push_back(p);
                    //u->joinProject(p);
                    p->getStudentList().push_back(s);
                }
            }
        }

    }

    facade->setAllProjects(allProjects);

}

//not sure we need these....
//void GetProjectControl::prepareStatement(QString sID, QString adminID){}
void GetProjectControl::execute(QList<Project*>& pList){
    pList = allProjects;
}
