#include "StoreUserControl.h";

StoreUserControl::StoreUserControl(QList<Project*>& pList, QList<User*>& uList){
    allUsers = uList;
    allProjects = pList;
    context = SQLContext();
    //make the strategy pointer explicitly null
    context.strat = 0;
}

StoreUserControl::~StoreUserControl(){

}

void StoreUserControl::store(bool exists, User* user){
    createQuery(exists, user);

}

QSqlQuery StoreUserControl::createQuery(bool exists, User* user){
    bool isStudent = user->getPolicy();

    if(context.strat) delete context.strat;

    if(exists && isStudent){
        context.strat = new UpdateStudentStrategy();//user);
    } else if(exists && !isStudent){
        context.strat = new UpdateAdminStrategy();//user);
    } else if(!exists && isStudent){
        context.strat = new InsertStudentStrategy();//user);
    } else{
        context.strat = new InsertAdminStrategy();//user);
    }

    context.strat->createQuery(user);
    //query.exec();
}

/*
bool StoreUserControl::run(QSqlQuery query){
    context.strat->createQuery();
}*/

