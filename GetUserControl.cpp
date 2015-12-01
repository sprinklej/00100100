#include "GetUserControl.h"
#include "StorageFacade.h"


GetUserControl::GetUserControl(QList<User*>& uList, StorageFacade* f, QSqlDatabase& db){
    allUsers = uList; // doesnt do what you think its doing the allUsers list still comes out empty
    facade = f;
    database = db;
}

GetUserControl::~GetUserControl(){}

bool GetUserControl::checkID(QString id){

    //query the database for all IDs
    database.open();
    QSqlQuery query;
    query.exec("SELECT id FROM admins UNION SELECT id FROM students;");

    //match the id
     while (query.next()) {
        QString resultID = query.value(0).toString();
        if(resultID == id) return true;
    }

    return false;
}

void GetUserControl::getIDs(QList<QString>& list){

    //query the database for all IDs
    database.open();
    QSqlQuery query;
    query.exec("SELECT id FROM admins UNION SELECT id FROM students;");

    //store the id
     while (query.next()) {
        QString resultID = query.value(0).toString();
        list.push_back(resultID);
    }

}

void GetUserControl::login(User* user){
    if (checkID(user->getID())){
        facade->setLoggedInUser(user);
    } else{
        delete user;
        facade->setLoggedInUser(0);
        //give the user a failure message
    }

}

void GetUserControl::registerUser(User* user){
    if(!checkID(user->getID())) facade->setLoggedInUser(user);
    else{
        delete user;
        facade->setLoggedInUser(0);
        //give the user an error message
    }

}

//need to construct the list first
void GetUserControl::initializeUsersList(){

    User* u;
    //clean out the list if it exists
    //foreach(u, allUsers){
    //    delete u;
    //}
    qDeleteAll(allUsers);
    allUsers.clear();

    //get the student data
    database.open();
    QSqlQuery query;
    query.exec("SELECT * FROM students;");

    //put the students into the collection
    Student* s;

     while (query.next()) {
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

         qDebug() << "Found:";
         qDebug() << "ID: " << id;
         qDebug() << "fname: " << fname;
         qDebug() << "lname: " << lname;

         s = new Student(fname, lname, id, att_leader, att_avail, att_2404, att_3005,
                             att_coding, att_dbase, att_selfDir, att_writing, att_UI, att_algorithm,
                             att_present, att_teamwork, att_experience, att_testing, att_UML,
                             att_req, att_reliable, att_comm, att_respect, att_creative, att_critic,
                             req_leader, req_2404, req_3005, req_coding, req_dbase, req_selfDir,
                             req_writing, req_UI, req_algorithm, req_present, req_teamwork,
                             req_experience, req_testing, req_UML,req_req, req_reliable,
                             req_comm, req_respect, req_creative, req_critic);

        allUsers.push_back(s);
    }

    //get the admin data
    QSqlQuery query2;
    query2.exec("SELECT * FROM admins;");

    Admin* a;

    //put the admins into the collection
    while (query2.next()) {
        QString id = query2.value(0).toString();
        QString fname = query2.value(1).toString();
        QString lname = query2.value(2).toString();
        a = new Admin(fname, lname, id);
        allUsers.push_back(a);
    }


    // add all users to the facades allUser list
    facade->setAllUsers(allUsers);
}

