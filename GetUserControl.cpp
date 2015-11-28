#include "GetUserControl.h";


GetUserControl::GetUserControl(QList<User*>& uList){
    allUsers = uList;
}

GetUserControl::~GetUserControl(){}

bool GetUserControl::checkID(QString id){

    //query the database for all IDs
    QSqlQuery query;
    query.exec("SELECT id FROM admins UNION SELECT id FROM students;");

    //match the id
     while (query.next()) {
        QString resultID = query.value(0).toString();
        if(resultID == id) return true;
    }

    return false;
}

void GetUserControl::getIDs(Qlist<QString>& list){

    //query the database for all IDs
    QSqlQuery query;
    query.exec("SELECT id FROM admins UNION SELECT id FROM students;");

    //store the id
     while (query.next()) {
        QString resultID = query.value(0).toString();
        list.pushBack(resultID);
    }

}

void GetUserControl::login(User* user){
    if (checkID(user->id)) loggedInUser = user;
    else{
        delete user;
        //give the user a failure message
    }

}

void GetUserControl::registerUser(User* user){
    if!(checkID(user->id)) loggedInUser = user;
    else{
        delete user;
        //give the user an error message
    }

}

//need to construct the list first
void GetUserControl::initializeUsersList(){

    //clean out the list if it exists
    foreach(u, allUsers){
        delete u;
    }
    allUsers.empty();

    //get the student data
    QSqlQuery query;
    query.exec("SELECT * FROM students;");

    //put the students into the collection
     while (query.next()) {
        QString name = query.value(0).toString();
        (...)
        Student* s = new Student(...);
        allUsers.pushBack(s);
    }

    //get the admin data
    QSqlQuery query2;
    query2.exec("SELECT * FROM admins;");

    //put the admins into the collection
    while (query2.next()) {
        QString name = query2.value(0).toString();
        (...)
        Admin* a = new admin(...);
        allUsers.pushBack(a);
    }

}

