

StorageFacade::StorageFacade(){
    //create the database connection
    storage = Storage();

    //initialize the controllers
    storeProjectsControl = StoreProjectControl(storage);
    getProjectControl = GetProjectsControl(storage);
    storeUserControl = StoreUserControl(storage);
    getUsersControl = GetUsersControl(storage);

    //initialize the collection classes
    allUsers = QList<User*>();
    allProjects = QList<Project*>;

    //nobody is logged in yet - make sure hte system knows
    loggedInUser = 0;

    //load the projects
    getUsersControl.getUsers(allUsers);
    //gets projects and links with users
    getProjectsControl.getProjects(allProjects, allUsers);

    //system is now set up

}

StorageFacade::~StorageFacade(){
    //free up memory used by dynamic objects
    foreach(allUsers, u){delete u;}
    foreach(allProjects, p){delete p;}

}

void StorageFacade::StorageFacade::run(){
    executing = 1;

    while(executing){
        if(!loggedInUser){
            regMgr = new RegistrationManager();
            //call the necessary functions
            delete regMgr;

        } else if(loggedInUser->getPolicy()){ //true if Student
            stMgr = new StudentManager();
            //call necessary functions
            delete stMgr;

        } else{
            adMgr = new AdminManager();
            // call necessary functions
            delete adMgr;
        }
    }


}

/*
void StorageFacade::handleShutdown(){
    executing = false;
}*/

void StorageFacade::storeProject(Project* p, String sID, String aID, bool newProj){
    storeProjectsControl.store(p, sID, aID, newProj);
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

    forEach(allUsers, u){
        if(u->id == newUser->id){
            delete newUser;
            //give the user an error dialog
            return;
        }
    }

    allUsers.pushBack(newUser);
    loggedInUser = u;
}


