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
void Storage::addUser(User*){




}

//overwrites existing user in Storage
void Storage::updateStudent(Student*){}

//if the ID is found in Storage, constructs a user and assigns the pointer to it
void Storage::getUser(QString s, User* uptr){
    QString query = QString("SELECT * FROM users WHERE id ='");
    query.append(s);
    query.append("';");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);

    if(!res) qDebug() << "No data!"; else
    if(result.next()){
        QString id = result.value(0).toString();
        QString fname = result.value(1).toString();
        QString lname = result.value(2).toString();
        int att1 = result.value(3).toInt();

        qDebug() << "Found:";
        qDebug() << "ID: " << id;
        qDebug() << "fname: " << fname;
        qDebug() << "lname: " << lname;

        if(id.at(0) == '1'){
            uptr = new Student(id, fname, lname, att1);
        } else {
            uptr = new Admin(id, fname, lname, 0);
        }
    }
    else uptr = 0;
}

void Storage::addProject(Project*, Admin*){} //adds the project to Storage, with the Admin as owner

void Storage::updateProject(Project*){} //overwrites an existing Project in Storage

void Storage::joinProject(Project*, Student*){} // establishes the Project-Student relationship

void Storage::getProjects(Admin*, QList<Project>*){} // Constructs all Projects owned by the Admin and adds to the QList

void Storage::getRegisteredStudents(Project*, QList<Student>*){} // Constructs all Students who have registered with the Project and adds to the QList


