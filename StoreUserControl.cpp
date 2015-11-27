#include "StoreUserControl.h";

StoreUserControl::StoreUserControl(QList<Project*>& pList, QList<User*>& uList){
    allUsers = uList;
    allProjects = pList;
    context = SQLContext();
    //make the strategy pointer explicitly null
    context.strategy = 0;
}

StoreUserControl::~StoreUserControl(){

}

SqlQuery StoreUserControl::createQuery(bool exists, User* user){
    bool isStudent = user->providePolicy();

    if(context.strategy) delete context.strategy;

    if(exists && isStudent){
        context.strategy = new updateStudentStrategy(user);
    } else if(exists && !isStudent){
        context.strategy = new updateAdminStrategy(user);
    } else if(!exists && isStudent){
        context.strategy = new insertStudentStrategy(user);
    } else{
        context.strategy = new insertAdminStrategy(user);
    }

}

bool StoreUserControl::run(QSqlQuery query){
    context.strategy->execute();
}

