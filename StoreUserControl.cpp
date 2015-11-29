#include "StoreUserControl.h";

StoreUserControl::StoreUserControl(QList<Project*>& pList, QList<User*>& uList, QSqlDatabase& db){
    allUsers = uList;
    allProjects = pList;
    database = db;
    context = new SQLContext(database);
    //make the strategy pointer explicitly null
    context->strat = 0;
}

StoreUserControl::~StoreUserControl(){
    delete context;
}

void StoreUserControl::store(bool exists, User* user){
    createQuery(exists, user);

}

QSqlQuery StoreUserControl::createQuery(bool exists, User* user){
    bool isStudent = user->getPolicy();

    if(context->strat) delete context->strat;

    if(exists && isStudent){
        context->strat = new UpdateStudentStrategy(database);//user);
    } else if(exists && !isStudent){
        context->strat = new UpdateAdminStrategy(database);//user);
    } else if(!exists && isStudent){
        context->strat = new InsertStudentStrategy(database);//user);
    } else{
        context->strat = new InsertAdminStrategy(database);//user);
    }

    context->strat->createQuery(user);
    //query.exec();
}

/*
bool StoreUserControl::run(QSqlQuery query){
    context.strat->createQuery();
}*/

