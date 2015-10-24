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
    QString dbLocation(QDir::home().path());
    dbLocation.append(QDir::separator()).append("cupid");
    dbLocation = QDir::toNativeSeparators(dbLocation);
    database.setDatabaseName(dbLocation);
    database.open();

    qDebug() << "Open the database";
}

/*Storage::~Storage(){

}*/

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
    query.append(st.getAtt1());
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
    query.append(st.getAtt1());
    query.append(" WHERE id = '");
    query.append(st.getIDNum());
    query.append("';");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);

}

//if the ID is found in Storage, constructs a user and assigns the pointer to it
void Storage::getUser(QString s, User& user){
    QString query = QString("SELECT * FROM users WHERE id ='");
    query.append(s);
    query.append("';");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);

    if(!res){
        qDebug() << "No data!";
        //uptr = 0;
    } else if(result.next()){
        QString id = result.value(0).toString();
        QString fname = result.value(1).toString();
        QString lname = result.value(2).toString();
        int att1 = result.value(3).toInt();

        qDebug() << "Found:";
        qDebug() << "ID: " << id;
        qDebug() << "fname: " << fname;
        qDebug() << "lname: " << lname;

        if(id.at(0) == '1'){
            user = Student(id, fname, lname, att1);

        } else {
            user = Admin(id, fname, lname, 0);
        }
    }

}

void Storage::addProject(Project& pr, Admin& own){
    QString query = QString("INSERT INTO projects(projectID, owner, courseName, courseNum, description) VALUES(");
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
    bool res = result.exec(query);

} //adds the project to Storage, with the Admin as owner

void Storage::updateProject(Project&){} //overwrites an existing Project in Storage

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

void Storage::getProjects(Admin&, QList<Project>&){} // Constructs all Projects owned by the Admin and adds to the QList

void Storage::getRegisteredStudents(Project&, QList<Student>&){} // Constructs all Students who have registered with the Project and adds to the QList


