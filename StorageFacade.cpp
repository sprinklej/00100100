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
    executing = 1;

// for testing the student / admin managers only
QString uID = "100542806";  // student
//QString uID = "soma";     // admin
handleLogin(uID);           // log a user in

    while(executing){
        if(!loggedInUser){
qDebug() << "Nobody logged in ... create a registrationmanager";
            regMgr = new ManageRegistrationControl();
            //call the necessary functions          
            delete regMgr;
        } else if(loggedInUser->getPolicy()){ //true if Student
qDebug() << "Student logged in ... create a studentmanager";
            stMgr = new ManageStudentControl(this);
            stMgr->createGUI();
//cant delete the stMgr object here, because as soon as stMgr->createGUI() returns
//then the object is deleted, meaning you cant call any other stMgr commands
//delete stMgr;
qDebug() << "test to see when stMgr gets deleted";
        } else{
            adMgr = new ManageAdminControl();
qDebug() << "Admin logged in ... create an adminmanager";
            // call necessary functions
            delete adMgr;
        }
executing = 0;
    }


}

/*
void StorageFacade::handleShutdown(){
    executing = false;
}*/

void StorageFacade::storeProject(Project* p, QString sID, QString aID, bool newProj){
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

void StorageFacade::handleLogin(QString uID){
    User* u;
    foreach(u, allUsers){
        if(uID == u->getID()){
            //exists = true;
            loggedInUser = u;
        }
    }

    if(!loggedInUser){
        //give the user an error dialog
    }

}

void StorageFacade::handleRegister(User* newUser){

    User* u;
    foreach(u, allUsers){
        if(u->getID() == newUser->getID()){
            delete newUser;
            //give the user an error dialog
            return;
        }
    }

    allUsers.push_back(newUser);
    loggedInUser = u;
}

void StorageFacade::setLoggedInUser(User*u){loggedInUser = u;}


