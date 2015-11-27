#include "SQLStrategy.h"


bool UpdateStudentStrategy::createQuery(User* u){
    Student* s = dynamic_cast<Student*> u;

/////////////////TODO: Need to write all the queries
    QSqlQuery query;
    query.prepare("UPDATE students "
                  "SET fName = :fName "



                  "WHERE id = :id");
    query.bindValue(":id", s->id);
    query.bindValue(":fName", s->fName);
    query.bindValue(":surname", "Simpson");
    query.exec();

}

bool InsertStudentStrategy::createQuery(User* u){
    Student* s = dynamic_cast<Student*> u;

        QSqlQuery query;
    query.prepare("INSERT INTO students()  "
                  "VALUES( "



                  "  ); ");
    query.bindValue(":id", s->id);
    query.bindValue(":forename", "Bart");
    query.bindValue(":surname", "Simpson");
    query.exec();

}

bool UpdateAdminStrategy::createQuery(User* u){
    Admin* a = dynamic_cast<Admin*> u;
}

bool InsertAdminStrategy::createQuery(User* u){
    Admin* a = dynamic_cast<Admin*> u;
}
