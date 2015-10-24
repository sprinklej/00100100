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
    dbLocation.append(QDir::separator()).append("COMP3004").append(QDir::separator()).append("cupid");
    dbLocation = QDir::toNativeSeparators(dbLocation);
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

//if the ID is found in Storage, constructs a user and assigns it to the reference
//Return values: 0 = failure
//              -1 = success
bool Storage::getUser(QString s, User& user){
    QString query = QString("SELECT * FROM users WHERE id ='");
    query.append(s);
    query.append("';");
    qDebug() << query.toUtf8().constData();

    QSqlQuery result;
    bool res = result.exec(query);

    if(!res){
        qDebug() << "No data!";
        return 0;
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
    } else return 0;
    return -1;
}

//adds the project to Storage, with the Admin as owner
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
}

//overwrites an existing Project in Storage
void Storage::updateProject(Project& pr){
    QString query = QString("UPDATE projects SET courseName = '");
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
    bool res = result.exec(query);

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
void Storage::getProjects(Admin& ad, QList<Project>& pl){
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

        Project newProj = Project(projectID, ad.getIDNum(), courseName, courseNum, description);
        pl.push_back(newProj);
    }

    foreach(Project p, pl){
        getRegisteredStudents(p, p.getStudentList());
    }


}

// Constructs all Students who have registered with the Project and adds to the QList
void Storage::getRegisteredStudents(Project& pr, QList<Student>& sl){
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

        Student newUser = Student(id, fname, lname, att1);
        sl.push_back(newUser);
    }

}


