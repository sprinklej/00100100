#include "GetProjectControl.h";
#include "QDebug"

GetProjectControl::GetProjectControl(QList<Project*>& pList, QList<User*>& uList, QSqlDatabase& db){
    allProjects = pList;
    allUsers = uList;
    database = db;
}

GetProjectControl::~GetProjectControl(){
}

//Note: this function links projects and students, and must be run AFTER the users are retrieved from storage
void GetProjectControl::intitializeProjects(){
    //clear out the existing projects
    Project* p;
    qDeleteAll(allProjects);
    allProjects.clear();
    //also empty the students' projects
    User* u;
    foreach(u, allUsers){
        if(u->getProjects()){
            qDeleteAll(u->getProjects()->begin(), u->getProjects()->end());
            u->getProjects()->clear();
        }
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
        QString ownerID = query.value(1).toString();
        QString courseName = query.value(2).toString();
        QString courseNum = query.value(3).toString();
        QString description = query.value(4).toString();
        int teamSize = query.value(5).toInt();

        newProj = new Project(projectID, ownerID, courseName, courseNum, description, teamSize);

        allProjects.push_back(newProj);
    }

    //now link the projects and students
    QSqlQuery query2;
    query2.exec("SELECT * FROM projectsStudents;");

    while (query2.next()) {
        QString pID = query2.value(0).toString();
        QString sID = query2.value(1).toString();

        Project* p;
        User* u;

        foreach(p, allProjects){
            foreach(u, allUsers){
                if(p->getProjectID() == pID && u->getID() == sID) {
                    //Student* s = dynamic_cast<Student*> u; //safe because we only have Students in the projectsStudents table, but a getcollection is still better
                    //s->projects.pushback(p);
                    u->getProjects()->push_back(p);
                    p->getStudentList().push_back(dynamic_cast<Student*>(u));
                }
            }
        }

    }

}

//not sure we need these....
//void GetProjectControl::prepareStatement(QString sID, QString adminID){}
void GetProjectControl::execute(QList<Project*>& pList){
    pList = allProjects;
}
