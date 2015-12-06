#include "StorageFacade.h"

StorageFacade::StorageFacade(){
    //create the database connection

    qDebug() << "Create storage...";
    storage = new Storage(this);
    database = storage->getDatabase();

    //initialize the collection classes
    allUsers = QList<User*>();
    allProjects = QList<Project*>();

    //initialize the controllers
    qDebug() << "Create storeproject controller.";
    storeProjectControl = new StoreProjectControl(allProjects, allUsers, database);
    qDebug() << "Create getproject control...";
    getProjectControl = new GetProjectControl(this, allProjects, allUsers, database);
    qDebug() << "Create store user control";
    storeUserControl = new StoreUserControl(allProjects, allUsers, database);
    qDebug() << "Create get user control...";
    getUserControl = new GetUserControl(allUsers, this, database);


    //nobody is logged in yet - make sure hte system knows
    loggedInUser = 0;

    //load the projects
    getUserControl->initializeUsersList();
    getProjectControl->setUsers(getUserControl->getUsers());
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

    delete storage;

}

// setter
void StorageFacade::setAllUsers(QList<User*> usrs) {
    allUsers = usrs;
}

void StorageFacade::setAllProjects(QList<Project*> prjcts) {
    allProjects = prjcts;
}

// getter
User* StorageFacade::getLoggedInUser() {
    return loggedInUser;
}

/*
void StorageFacade::setDB(QSqlDatabase& db){
    database = db;
}*/

void StorageFacade::run(){
    qDebug() << "HANDLE LOGIN PASS";

    if(!loggedInUser){
        qDebug() << "Nobody logged in ...";
        regMgr = new ManageRegistrationControl(this);
        regMgr->createGUI();
    } else if(loggedInUser->getPolicy()){   // true if Student
        qDebug() << "Student logged in ...";
        stMgr = new ManageStudentControl(this);
        stMgr->createGUI();
    } else {                                // else must be an admin user
        qDebug() << "Admin logged in ...";
        getProjectControl->intitializeProjects();
        adMgr = new ManageAdminControl(this);
        adMgr->createGUI();
    }
}

/*
void StorageFacade::handleShutdown(){
    executing = false;
}*/

void StorageFacade::storeProject(Project* p, QString sID, QString aID, bool newProj){
    if(newProj){
        allProjects.push_back(p);
    }
    storeProjectControl->store(p, sID, aID, newProj);

}

void StorageFacade::writeUser(User* u){
    bool newUser = getUserControl->checkID(u->getID());
    storeUserControl->store(newUser, u);
}

//need to figure this out better
void StorageFacade::getProjects(QList<Project*>& p){
    //return allProjects;
    getProjectControl->execute(p);
}

//need to figure this out better
void StorageFacade::getUserIDs(QList<QString>& u){
    //return allUsers;
    getUserControl->getIDs(u);

}

void StorageFacade::handleLogin(ManageRegistrationControl *manRegCon, QString uID){
    // make sure no one is logged in
    loggedInUser = NULL;

    User* u;
    foreach(u, allUsers){
        if(uID == u->getID()){
            //exists = true;
            loggedInUser = u;
            qDebug() << "Logged in user " << loggedInUser->getID();
        }
    }

    if(loggedInUser){   // successful login
        manRegCon->loginSuccess();
    } else {            // give the user an error dialog
        manRegCon->loginFailure("Username does not exist");
    }
}

void StorageFacade::handleRegister(User* newUser){

    User* u;
    foreach(u, allUsers){
        if(u->getID() == newUser->getID()){
            //delete newUser;
            regMgr->setStatus("User NOT created, user already exists");
            return;
        }
    }

    allUsers.push_back(newUser);
    writeUser(newUser);
    regMgr->setStatus("New user created");
}

void StorageFacade::setLoggedInUser(User*u){loggedInUser = u;}


