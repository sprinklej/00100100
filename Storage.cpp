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
void Storage::addUser(Student* st){
    QSqlQuery query;
    query.prepare("INSERT INTO users(id, fname, lname, att_leader, att_avail, att_2404, att_3005,"
                  "att_coding, att_dbase, att_selfDir, att_writing, att_UI, att_algorithm,"
                  "att_present, att_teamwork, att_experience, att_testing, att_UML,"
                  "att_req, att_reliable, att_comm, att_respect, att_creative, att_critic,"
                  "req_leader, req_2404, req_3005, req_coding, req_dbase, req_selfDir,"
                  "req_writing, req_UI, req_algorithm, req_present, req_teamwork,"
                  "req_experience, req_testing, req_UML, req_req, req_reliable,"
                  "req_comm, req_respect, req_creative, req_critic"
                  ") VALUES"
                  "(:id, :fname, :lname, :att_leader, :att_avail, :att_2404, :att_3005, "
                  ":att_coding, :att_dbase, :att_selfDir, :att_writing, :att_UI, :att_algorithm,"
                   ":att_present, :att_teamwork, :att_experience, :att_testing, :att_UML,"
                    ":att_req, :att_reliable, :att_comm, :att_respect, :att_creative, :att_critic,"
                   ":req_leader, :req_2404, :req_3005, :req_coding, :req_dbase, :req_selfDir,"
                   ":req_writing, :req_UI, :req_algorithm, :req_present, :req_teamwork,"
                   ":req_experience, :req_testing, :req_UML,:req_req, :req_reliable,"
                   ":req_comm, :req_respect, :req_creative, :req_critic )");

    query.bindValue(":id", st->getIDNum());
    query.bindValue(":fname", st->getFirstName());
    query.bindValue(":lname", st->getLastName());
    query.bindValue(":att_leader", st->getAtt_leader());
    query.bindValue(":att_avail", st->getAtt_avail());
    query.bindValue(":att_2404", st->getAtt_2404());
    query.bindValue(":att_3005", st->getAtt_3005());
    query.bindValue(":att_coding", st->getAtt_coding());
    query.bindValue(":att_dbase", st->getAtt_dbase());
    query.bindValue(":att_selfDir", st->getAtt_selfDir());
    query.bindValue(":att_writing", st->getAtt_writing());
    query.bindValue(":att_UI", st->getAtt_UI());
    query.bindValue(":att_algorithm", st->getAtt_algorithm());
    query.bindValue(":att_present", st->getAtt_present());
    query.bindValue(":att_teamwork", st->getAtt_teamwork());
    query.bindValue(":att_experience", st->getAtt_experience());
    query.bindValue(":att_testing", st->getAtt_testing());
    query.bindValue(":att_UML", st->getAtt_UML());
    query.bindValue(":att_req", st->getAtt_req());
    query.bindValue(":att_reliable", st->getAtt_reliable());
    query.bindValue(":att_comm", st->getAtt_comm());
    query.bindValue(":att_respect", st->getAtt_respect());
    query.bindValue(":att_creative", st->getAtt_creative());
    query.bindValue(":att_critic", st->getAtt_critic());
    query.bindValue(":req_leader", st->getReq_leader());
    query.bindValue(":req_2404", st->getReq_2404());
    query.bindValue(":req_3005", st->getReq_3005());
    query.bindValue(":req_coding", st->getReq_coding());
    query.bindValue(":req_dbase", st->getReq_dbase());
    query.bindValue(":req_selfDir", st->getReq_selfDir());
    query.bindValue(":req_writing", st->getReq_writing());
    query.bindValue(":req_UI", st->getReq_UI());
    query.bindValue(":req_algorithm", st->getReq_algorithm());
    query.bindValue(":req_present", st->getReq_present());
    query.bindValue(":req_teamwork", st->getReq_teamwork());
    query.bindValue(":req_experience", st->getReq_experience());
    query.bindValue(":req_testing", st->getReq_testing());
    query.bindValue(":req_UML", st->getReq_UML());
    query.bindValue(":req_req", st->getReq_req());
    query.bindValue(":req_reliable", st->getReq_reliable());
    query.bindValue(":req_comm", st->getReq_comm());
    query.bindValue(":req_respect", st->getReq_respect());
    query.bindValue(":req_creative", st->getReq_creative());
    query.bindValue(":req_critic",st->getReq_critic());

    bool res = query.exec();
}

void Storage::addUser(Admin* ad){

    QSqlQuery query;
    query.prepare("INSERT INTO users(id, fname, lname) VALUES (:iid, :ifn, :iln)");
    query.bindValue(":iid", ad->getIDNum());
    query.bindValue(":ifn", ad->getFirstName());
    query.bindValue(":iln", ad->getLastName());
    bool res = query.exec();

}

//overwrites existing user in Storage
void Storage::updateStudent(Student* st){

    QSqlQuery query;
    query.prepare("UPDATE users SET "
                  "fname = :fname,"
                  "lname = :lname,"
                  "att_leader = :att_leader"
                  "att_avail = :att_avail,"
                  "att_2404 = :att_2404,"
                  "att_3005 = :att_3005,"
                  "att_coding = :att_coding,"
                  "att_dbase = :att_dbase,"
                  "att_selfDir = :att_selfDir,"
                  "att_writing = :att_writing,"
                  "att_UI = :att_UI,"
                  "att_algorithm = :att_algorithm,"
                  "att_present = :att_present,"
                  "att_teamwork = :att_teamwork,"
                  "att_experience = :att_experience,"
                  "att_testing = :att_testing,"
                  "att_UML = :att_UML,"
                  "att_req = :att_req,"
                  "att_reliable = :att_reliable,"
                  "att_comm = :att_comm,"
                  "att_respect = :att_respect,"
                  "att_creative = :att_creative,"
                  "att_critic = :att_critic,"
                  "req_leader = :req_leader,"
                  "req_2404 = :req_2404,"
                  "req_3005 = :req_3005,"
                  "req_coding = :req_coding,"
                  "req_dbase = :req_dbase,"
                  "req_selfDir = :req_selfDir,"
                  "req_writing = :req_writing,"
                  "req_UI = :req_UI,"
                  "req_algorithm = :req_algorithm,"
                  "req_present= :req_present,"
                  "req_teamwork = :req_teamwork,"
                  "req_experience = :req_experience,"
                  "req_testing = :req_testing,"
                  "req_UML = :req_UML,"
                  "req_req = :req_req,"
                  "req_reliable = :req_reliable,"
                  "req_comm = :req_comm,"
                  "req_respect = :req_respect,"
                  "req_creative = :req_creative,"
                  "req_critic = :req_critic "
                  "WHERE id = :iid");

    query.bindValue(":fname", st->getFirstName());
    query.bindValue(":lname", st->getLastName());
    query.bindValue(":att_leader", st->getAtt_leader());
    query.bindValue(":att_avail", st->getAtt_avail());
    query.bindValue(":att_2404", st->getAtt_2404());
    query.bindValue(":att_3005", st->getAtt_3005());
    query.bindValue(":att_coding", st->getAtt_coding());
    query.bindValue(":att_dbase", st->getAtt_dbase());
    query.bindValue(":att_selfDir", st->getAtt_selfDir());
    query.bindValue(":att_writing", st->getAtt_writing());
    query.bindValue(":att_UI", st->getAtt_UI());
    query.bindValue(":att_algorithm", st->getAtt_algorithm());
    query.bindValue(":att_present", st->getAtt_present());
    query.bindValue(":att_teamwork", st->getAtt_teamwork());
    query.bindValue(":att_experience", st->getAtt_experience());
    query.bindValue(":att_testing", st->getAtt_testing());
    query.bindValue(":att_UML", st->getAtt_UML());
    query.bindValue(":att_req", st->getAtt_req());
    query.bindValue(":att_reliable", st->getAtt_reliable());
    query.bindValue(":att_comm", st->getAtt_comm());
    query.bindValue(":att_respect", st->getAtt_respect());
    query.bindValue(":att_creative", st->getAtt_creative());
    query.bindValue(":att_critic", st->getAtt_critic());
    query.bindValue(":req_leader", st->getReq_leader());
    query.bindValue(":req_2404", st->getReq_2404());
    query.bindValue(":req_3005", st->getReq_3005());
    query.bindValue(":req_coding", st->getReq_coding());
    query.bindValue(":req_dbase", st->getReq_dbase());
    query.bindValue(":req_selfDir", st->getReq_selfDir());
    query.bindValue(":req_writing", st->getReq_writing());
    query.bindValue(":req_UI", st->getReq_UI());
    query.bindValue(":req_algorithm", st->getReq_algorithm());
    query.bindValue(":req_present", st->getReq_present());
    query.bindValue(":req_teamwork", st->getReq_teamwork());
    query.bindValue(":req_experience", st->getReq_experience());
    query.bindValue(":req_testing", st->getReq_testing());
    query.bindValue(":req_UML", st->getReq_UML());
    query.bindValue(":req_req", st->getReq_req());
    query.bindValue(":req_reliable", st->getReq_reliable());
    query.bindValue(":req_comm", st->getReq_comm());
    query.bindValue(":req_respect", st->getReq_respect());
    query.bindValue(":req_creative", st->getReq_creative());
    query.bindValue(":req_critic",st->getReq_critic());
    query.bindValue(":iid", st->getIDNum());

    bool res = query.exec();
    qDebug() << query.lastError();


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
            *user = new Student(fname, lname, id, att_leader, att_avail, att_2404, att_3005,
                                att_coding, att_dbase, att_selfDir, att_writing, att_UI, att_algorithm,
                                att_present, att_teamwork, att_experience, att_testing, att_UML,
                                att_req, att_reliable, att_comm, att_respect, att_creative, att_critic,
                                req_leader, req_2404, req_3005, req_coding, req_dbase, req_selfDir,
                                req_writing, req_UI, req_algorithm, req_present, req_teamwork,
                                req_experience, req_testing, req_UML,req_req, req_reliable,
                                req_comm, req_respect, req_creative, req_critic);
        } else {
            *user = new Admin(fname, lname, id, 0);
        }
    } else return 0;
    return -1;
}

//adds the project to Storage, with the Admin as owner
void Storage::addProject(Project* pr, Admin* own){

    QSqlQuery query;
    query.prepare("INSERT INTO projects(projectID, owner, courseName, courseNum, description)"
                  "VALUES (:ipr, :iow, :icn, :icnm, :ides)");
    query.bindValue(":ipr", pr->getProjectID());
    query.bindValue(":iow", own->getIDNum());
    query.bindValue(":icn", pr->getCourseName());
    query.bindValue(":icnm", pr->getCourseNum());
    query.bindValue(":ides", pr->getPDescription());
    bool res = query.exec();

}

//overwrites an existing Project in Storage
void Storage::updateProject(Project* pr){

    QSqlQuery query;
    query.prepare("UPDATE projects SET "
                  "courseName = :icn, courseNum = :icnm, description = :ides "
                  "WHERE projectID = :ipr");
    //query.bindValue(":iow", own.getIDNum());
    query.bindValue(":icn", pr->getCourseName());
    query.bindValue(":icnm", pr->getCourseNum());
    query.bindValue(":ides", pr->getPDescription());
    query.bindValue(":ipr", pr->getProjectID());
    bool res = query.exec();
    qDebug() << query.lastError();

}

 // establishes the Project-Student relationship
void Storage::joinProject(Project& pr, Student& st){

    QSqlQuery query;
    query.prepare("INSERT INTO projectsStudents(userID, projectID) VALUES(:iu, :ip)");
    query.bindValue(":iu", st.getIDNum());
    query.bindValue(":ip", pr.getProjectID());
    bool res = query.exec();

}

// Constructs all Projects owned by the Admin and adds to the QList
void Storage::getProjects(Admin& ad, QList<Project*>& pl){

    QSqlQuery query;
    query.prepare("SELECT * FROM projects WHERE owner = :io");
    query.bindValue(":io", ad.getIDNum());
    bool res = query.exec();

    qDebug() << "query executed";

    while(query.next()){
        QString projectID = query.value(0).toString();
        QString courseName = query.value(2).toString();
        QString courseNum = query.value(3).toString();
        QString description = query.value(4).toString();
        int teamSize = query.value(5).toInt();

        Project* newProj = new Project(projectID, ad.getIDNum(), courseName, courseNum, description, teamSize);

        qDebug() << "create project " << newProj->getProjectID();
        pl.push_back(newProj);
        qDebug() << "pushed ";
    }

    /*foreach(Project* p, pl){
        getRegisteredStudents(*p, p->getStudentList());
    }*/


}

// Constructs all Students who have registered with the Project and adds to the QList
void Storage::getRegisteredStudents(Project& pr, QList<Student*>& sl){

    QSqlQuery query;
    query.prepare("SELECT * FROM projectsStudents JOIN users WHERE projectID = :pid");
    query.bindValue(":pid", pr.getProjectID());
    bool res = query.exec();

    while(query.next()){
        QString id = query.value(0).toString();
        QString fname = query.value(1).toString();
        QString lname = query.value(2).toString();
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

       Student* newUser = new Student(id, fname, lname, att_leader, att_avail, att_2404, att_3005,
                            att_coding, att_dbase, att_selfDir, att_writing, att_UI, att_algorithm,
                            att_present, att_teamwork, att_experience, att_testing, att_UML,
                            att_req, att_reliable, att_comm, att_respect, att_creative, att_critic,
                            req_leader, req_2404, req_3005, req_coding, req_dbase, req_selfDir,
                            req_writing, req_UI, req_algorithm, req_present, req_teamwork,
                            req_experience, req_testing, req_UML,req_req, req_reliable,
                            req_comm, req_respect, req_creative, req_critic);

        sl.push_back(newUser);
    }

}


