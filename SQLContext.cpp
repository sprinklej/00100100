#include "SQLContext.h"

SQLContext::SQLContext(QSqlDatabase& db){
    database = db;
}

//////////
//setpolicy = true if Student
bool SQLContext::query(bool update, User* u){
    if(u->getPolicy()){
        if(update){
            strat = new UpdateStudentStrategy(database);
        } else {
            strat = new InsertStudentStrategy(database);
        }
    } else {
        if(update){
            strat = new UpdateAdminStrategy(database);
        } else {
            strat = new InsertAdminStrategy(database);
        }
    }
    return strat->createQuery(u);
}

