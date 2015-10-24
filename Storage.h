#ifndef STORAGE_H
#define STORAGE_H

#include "Project.h"
#include "User.h"
#include <QList>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include <QVariant>
using namespace std;


class Storage{

public:
    //singleton instance
    static Storage& getDB();/*{
        static Storage instance;
        return instance;
    }*/

    void addUser(Student&); //adds the user's data to Storage
    void addUser(Admin&);
    void updateStudent(Student&); //overwrites existing user in Storage
    void getUser(QString, User&);  //if the ID is found in Storage, constructs a user and assigns the pointer to it
    void addProject(Project&, Admin&); //adds the project to Storage, with the Admin as owner
    void updateProject(Project&); //overwrites an existing Project in Storage
    void joinProject(Project&, Student&); // establishes the Project-Student relationship
    void getProjects(Admin&, QList<Project>&); // Constructs all Projects owned by the Admin and adds to the QList
    void getRegisteredStudents(Project&, QList<Student>&); // Constructs all Students who have registered with the Project and adds to the QList


private:
    //Private members that are internal to the Singleton pattern.
    QSqlDatabase database;
    Storage();
    //static Storage* instance;
};

#endif // STORAGE_H
