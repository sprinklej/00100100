#include "SQLStrategy.h"

UpdateStudentStrategy::UpdateStudentStrategy(){}

bool UpdateStudentStrategy::createQuery(User* u){

    /*
    //Student* s = dynamic_cast<Student*>(u);

    //TODO: Need to write all the queries
    //QSqlQuery query;
    //query.prepare("UPDATE students "
                  "SET fName = :fName "
     //             "WHERE id = :id");
    //query.bindValue(":id", s->getID());
    //query.bindValue(":fName", s->getFname());
    //query.bindValue(":surname", "Simpson");
    //query.exec();

    //qDebug() << "Update the student";*/
    return false;
}

InsertStudentStrategy::InsertStudentStrategy(){}

bool InsertStudentStrategy::createQuery(User* u){
    Student* s = dynamic_cast<Student*>(u);

    QSqlQuery query;
    /*query.prepare("INSERT INTO students()  "
                  "VALUES( "



                  "  ); ");
    query.bindValue(":id", s->id);
    query.bindValue(":forename", "Bart");
    query.bindValue(":surname", "Simpson");
    query.exec();*/

    //qDebug() << "Insert student";
    return false;
}

UpdateAdminStrategy::UpdateAdminStrategy(){}

bool UpdateAdminStrategy::createQuery(User* u){
    Admin* a = dynamic_cast<Admin*>(u);

    //qDebug() << "Update admin";
    return false;
}

InsertAdminStrategy::InsertAdminStrategy(){}

bool InsertAdminStrategy::createQuery(User* u){
    Admin* a = dynamic_cast<Admin*>(u);

    //qDebug() << "Insert admin";
    return false;
}
