#include "GetProjectControl.h";

GetProjectControl::GetProjectControl(QList<Project*>& pList, QList<User*>& uList){
    allProjects = pList;
    allUsers = uList;
}

GetProjectControl::~GetProjectControl(){
}

//Note: this function links projects and students, and must be run AFTER the users are retrieved from storage
void GetProjectControl::intitializeProjects(){
    //clear out the existing projects
    foreach(p, allProjects){delete p;}
    allProjects.empty();
    //also empty the students' projects
    foreach(u, allUsers){
        if(u->getPolicy()){
            //this would be better with a getProject collection method on the User superclass - just sayin'
            //Student* s = dynamic_cast<Student*> u;
            u->getProjects()->empty();
        }
    }

    //now go get the projects...
    QSqlQuery query;
    query.exec("SELECT * FROM projects;");

    //query.exec();

    qDebug() << "query executed";

    while(query.next()){
        QString projectID = query.value(0).toString();
        QString courseName = query.value(2).toString();
        QString courseNum = query.value(3).toString();
        QString description = query.value(4).toString();
        int teamSize = query.value(5).toInt();

        Project* newProj = new Project(projectID, ad.getIDNum(), courseName, courseNum, description, teamSize);

        pl.push_back(newProj);

    //now link the projects and students
    QSqlQuery query2;
    query2.exec("SELECT * FROM projectsStudents;");

    while (query2.next()) {
        QString pID = query2.value(0).toString();
        QString sID = query2.value(1).toString();

        foreach(p, allProjects){
            foreach(u, allUsers){
                if(p->projectID == pID && u->id == sID) {
                    //Student* s = dynamic_cast<Student*> u; //safe because we only have Students in the projectsStudents table, but a getcollection is still better
                    //s->projects.pushback(p);
                    u->getProjects()->push_back(p);
                    p->students.pushback(dynamic_cast<Student*> u);
                }
            }
        }

    }

}

//not sure we need these....
//void GetProjectControl::prepareStatement(QString sID, QString adminID){}
//void GetProjectControl::execute(Qlist<Project*>& pList){}
