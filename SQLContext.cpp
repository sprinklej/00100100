#include "SQLContext.h"

//////////
//setpolicy = true if Student
bool SQLContext::query(bool update, User* u){
    if(u->getPolicy()){
        if(update){
            strat = new UpdateStudentStrategy();
        } else {
            strat = new InsertStudentStrategy();
        }
    } else {
        if(update){
            strat = new UpdateAdminStrategy();
        } else {
            strat = new InsertAdminStrategy();
        }
    }
    return strat->createQuery(u);
}

