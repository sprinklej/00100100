#include "SQLContext.h"

//////////
//setpolicy = true if Student
void SQLContext::query(bool update, User* u){
    if(u.setPolicy()){
        if(update){
            strat = UpdateStudentStrategy();
        } else {
            strat = InsertStudentStrategy();
        }
    } else {
        if(update){
            strat = UpdateAdminStrategy();
        } else {
            strat = InsertAdminStrategy();
        }
    }
}

