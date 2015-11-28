#include "StorageFacade.h"

StorageFacade::StorageFacade(){
    //create the database connection
    storage = Storage();

    //initialize the collection classes
    allUsers = QList<User*>();
    allProjects = QList<Project*>();

    //initialize the controllers
    storeProjectControl = new StoreProjectControl(allProjects, allUsers);
    getProjectControl = new GetProjectControl(allProjects, allUsers);
    storeUserControl = new StoreUserControl(allProjects, allUsers);
    getUserControl = new GetUserControl(allUsers);


    //nobody is logged in yet - make sure hte system knows
    loggedInUser = 0;

    //load the projects
    getUserControl->initializeUsersList();
    //gets projects and links with users
    getProjectControl->intitializeProjects();

    //system is now set up

}

StorageFacade::~StorageFacade(){
    //free up memory used by dynamic objects
    qDeleteAll(allUsers); //foreach(u, allUsers){delete u;}
    qDeleteAll(allProjects); //foreach(p, allProjects){delete p;}

    delete storeProjectControl;
    delete getProjectControl;
    delete storeUserControl;
    delete getUserControl;

}

void StorageFacade::StorageFacade::run(){
    executing = 1;

    while(executing){
        if(!loggedInUser){
            regMgr = new ManageRegistrationControl();
            //call the necessary functions
            delete regMgr;

        } else if(loggedInUser->getPolicy()){ //true if Student
            stMgr = new ManageStudentControl();
            //call necessary functions
            delete stMgr;

        } else{
            adMgr = new ManageAdminControl();
            // call necessary functions
            delete adMgr;
        }
    }


}

/*
void StorageFacade::handleShutdown(){
    executing = false;
}*/

void StorageFacade::storeProject(Project* p, QString sID, QString aID, bool newProj){
    storeProjectControl.store(p, sID, aID, newProj);
}

void StorageFacade::writeUser(User* u){
    storeUserControl.store(u);
}

//need to figure this out better
void StorageFacade::getProjects(QList<Project*>& p){
    return allProjects;
    getProjectControl.getProjects(p);
}

//need to figure this out better
void StorageFacade::getUserIDs(QList<QString>& u){
    return allUsers;
    //getUsersControl.getUserIDs(u);

}

void StorageFacade::handleLogin(QString uID){

    forEach(allUsers, u){
        if(uID == u->id){
            exists = true;
            loggedInUser = u;
        }
    }

    if(!loggedInUser){
        //give the user an error dialog
    }

}

void StorageFacade::handleRegister(User* newUser){

    forEach(u, allUsers){
        if(u->id == newUser->id){
            delete newUser;
            //give the user an error dialog
            return;
        }
    }

    allUsers.pushBack(newUser);
    loggedInUser = u;
}


