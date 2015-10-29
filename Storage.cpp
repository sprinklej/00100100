#include "Storage.h"
#include <iostream>
#include <QDebug>
/*   //Private members that are internal to the Singleton pattern.
    QSqlDatabase database;
    Storage();
    static Storage* instance;*/

Storage::Storage(){
    // load the SQLite driver
    database = QSqlDatabase::addDatabase("QSQLITE");

    //Define and open the cupid file
    QDir curr = QDir::current();
    curr.cdUp();
    QString dbLocation = curr.path() + "/00100100/cupid";
    database.setDatabaseName(dbLocation);
    database.open();

    qDebug() << "Open the database";
}

Storage::~Storage(){
    database.close();
}

Storage& Storage::getDB(){
    static Storage instance;
    return instance;
}

//adds the user's data to Storage
void Storage::addUser(Student& st){
    QString query = QString("INSERT INTO users(id, fname, lname, attribute1) VALUES('");
    query.append(st.getIDNum());
    query.append("','");
    query.append(st.getFirstName());
    query.append("','");
    query.append(st.getLastName());
    query.append("','");
    query.append(st.getAtt_2404());
    query.append("');");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);
}

void Storage::addUser(Admin& ad){
    QString query = QString("INSERT INTO users(id, fname, lname) VALUES('");
    query.append(ad.getIDNum());
    query.append("','");
    query.append(ad.getFirstName());
    query.append("','");
    query.append(ad.getLastName());
    query.append("');");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);
}

//overwrites existing user in Storage
void Storage::updateStudent(Student& st){
    QString query = QString("UPDATE users SET fname = '");
    query.append(st.getFirstName());
    query.append("', lname = '");
    query.append(st.getLastName());
    query.append("', attribute1 = ");
    query.append(st.getAtt_2404());
    query.append(" WHERE id = '");
    query.append(st.getIDNum());
    query.append("';");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);

}

//if the ID is found in Storage, constructs a user and assigns it to the reference
//Return values: 0 = failure
//              -1 = success
bool Storage::getUser(QString s, User** user){

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE id = (:uid)");
    query.bindValue(":uid", s);

    bool res = query.exec();

    if(!res){
        qDebug() << "No data!";
        return 0;
    } else if(query.next()){
        QString id = query.value(0).toString();
        QString fname = query.value(1).toString();
        QString lname = query.value(2).toString();
        //int att1 = query.value(3).toInt();
        bool att_leader = query.value(3).toInt();
        QString att_avail = query.value(4).toString();
        int att_2404 = query.value(5).toInt();
        int att_3005 = query.value(6).toInt();
        int att_coding = query.value(7).toInt();
        int att_dbase = query.value(8).toInt();
        int att_selfDir = query.value(9).toInt();
        int att_writing = query.value(10).toInt();
        int att_UI = query.value(11).toInt();
        int att_algorithm = query.value(12).toInt();
        int att_present = query.value(13).toInt();
        int att_teamwork = query.value(14).toInt();
        int att_experience = query.value(15).toInt();
        int att_testing = query.value(16).toInt();
        int att_UML = query.value(17).toInt();
        int att_req = query.value(18).toInt();
        int att_reliable = query.value(19).toInt();
        int att_comm = query.value(20).toInt();
        int att_respect = query.value(21).toInt();
        int att_creative = query.value(22).toInt();
        int att_critic = query.value(23).toInt();
        bool req_leader = query.value(24).toInt();
        int req_2404 = query.value(25).toInt();
        int req_3005 = query.value(26).toInt();
        int req_coding = query.value(27).toInt();
        int req_dbase = query.value(28).toInt();
        int req_selfDir = query.value(29).toInt();
        int req_writing = query.value(30).toInt();
        int req_UI = query.value(31).toInt();
        int req_algorithm = query.value(32).toInt();
        int req_present = query.value(33).toInt();
        int req_teamwork = query.value(34).toInt();
        int req_experience = query.value(35).toInt();
        int req_testing = query.value(36).toInt();
        int req_UML = query.value(37).toInt();
        int req_req = query.value(38).toInt();
        int req_reliable = query.value(39).toInt();
        int req_comm = query.value(40).toInt();
        int req_respect = query.value(41).toInt();
        int req_creative = query.value(42).toInt();
        int req_critic = query.value(43).toInt();


        qDebug() << "Found:";
        qDebug() << "ID: " << id;
        qDebug() << "fname: " << fname;
        qDebug() << "lname: " << lname;

        if(id.at(0) == '1'){
            //*user = new Student(id, fname, lname, att1);
            *user = new Student(id, fname, lname, att_leader, att_avail, att_2404, att_3005,
                                att_coding, att_dbase, att_selfDir, att_writing, att_UI, att_algorithm,
                                att_present, att_teamwork, att_experience, att_testing, att_UML,
                                att_req, att_reliable, att_comm, att_respect, att_creative, att_critic,
                                req_leader, req_2404, req_3005, req_coding, req_dbase, req_selfDir,
                                req_writing, req_UI, req_algorithm, req_present, req_teamwork,
                                req_experience, req_testing, req_UML,req_req, req_reliable,
                                req_comm, req_respect, req_creative, req_critic);
        } else {
            *user = new Admin(id, fname, lname, 0);
        }
    } else return 0;
    return -1;
}

//adds the project to Storage, with the Admin as owner
void Storage::addProject(Project& pr, Admin& own){
    /*QString query = QString("INSERT INTO projects(projectID, owner, courseName, courseNum, description) VALUES(");
    query.append(pr.getProjectID());
    query.append(",'");
    query.append(own.getIDNum());
    query.append("','");
    query.append(pr.getCourseNum());
    query.append("','");
    query.append(pr.getPDescription());
    query.append("');");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);*/

    QSqlQuery query;
    query.prepare("INSERT INTO projects(projectID, owner, courseName, courseNum, description)"
                  "VALUES (:ipr, :iow, :icn, :icnm, :ides)");
    query.bindValue(":ipr", pr.getProjectID());
    query.bindValue(":iow", own.getIDNum());
    query.bindValue(":icn", pr.getCourseName());
    query.bindValue(":icnm", pr.getCourseNum());
    query.bindValue(":ides", pr.getPDescription());
    bool res = query.exec();

}

//overwrites an existing Project in Storage
void Storage::updateProject(Project& pr){
    /*QString query = QString("UPDATE projects SET courseName = '");
    query.append(pr.getCourseName());
    query.append("', courseNum = '");
    query.append(pr.getCourseNum());
    query.append("', description = '");
    query.append(pr.getPDescription());
    query.append("' WHERE projectID = '");
    query.append(pr.getProjectID());
    query.append("';");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);*/

    QSqlQuery query;
    query.prepare("UPDATE projects SET "
                  "courseName = :icn, courseNum :icnm, description = :ides "
                  "WHERE projectID = :ipr");
    //query.bindValue(":iow", own.getIDNum());
    query.bindValue(":icn", pr.getCourseName());
    query.bindValue(":icnm", pr.getCourseNum());
    query.bindValue(":ides", pr.getPDescription());
    query.bindValue(":ipr", pr.getProjectID());
    bool res = query.exec();

}

 // establishes the Project-Student relationship
void Storage::joinProject(Project& pr, Student& st){
    QString query = QString("INSERT INTO projectsStudents(userID, projectID) VALUES('");
    query.append(pr.getProjectID());
    query.append("','");
    query.append(st.getIDNum());
    query.append("');");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);
}

// Constructs all Projects owned by the Admin and adds to the QList
void Storage::getProjects(Admin& ad, QList<Project*>& pl){
    QString query = QString("SELECT * FROM projects WHERE owner ='");
    query.append(ad.getIDNum());
    query.append("';");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);

    while(result.next()){
        QString projectID = result.value(0).toString();
        QString courseName = result.value(2).toString();
        QString courseNum = result.value(3).toString();
        QString description = result.value(4).toString();

        Project* newProj = new Project(projectID, ad.getIDNum(), courseName, courseNum, description);
        pl.push_back(newProj);
    }

    foreach(Project* p, pl){
        getRegisteredStudents(*p, p->getStudentList());
    }


}

// Constructs all Students who have registered with the Project and adds to the QList
void Storage::getRegisteredStudents(Project& pr, QList<Student*>& sl){
    QString query = QString("SELECT * FROM projectsStudents JOIN users WHERE projectID ='");
    query.append(pr.getProjectID());
    query.append("';");
    qDebug() << query.toUtf8().constData();

    /*
    results:
    0: projectsStudents.userID
    1: projectID
    2: users.id
    3: fname
    4: lname
    5: attribute1
    */
    QSqlQuery result;
    bool res = result.exec(query);

    while(result.next()){
        QString id = result.value(2).toString();
        QString fname = result.value(3).toString();
        QString lname = result.value(4).toString();
        int att1 = result.value(5).toInt();

        Student* newUser = new Student(id, fname, lname, att1);
        sl.push_back(newUser);
    }

}


