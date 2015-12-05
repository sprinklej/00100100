#include "manageadmincontrol.h"
#include "managestudentcontrol.h"
#include "StorageFacade.h"
#include "PPIDManager.h"

ManageAdminControl::ManageAdminControl(StorageFacade* f)
{
    facade = f;
    user = (Admin*) facade->getLoggedInUser();
    facade->getProjects(allProjects);
}

void ManageAdminControl::createGUI()
{

    AdminWindow *adWin = new AdminWindow();
    setAdmWind(adWin);
    adWin->setManAdmContrl(this);
    adWin->setAdmin(user);
    adWin->refresh();
    adWin->show();
}

/* --------------------------- setters ------------------------*/
void ManageAdminControl::setAdmWind(AdminWindow* adWin)
{
    admWin = adWin;
}

void ManageAdminControl::setAdmin(Admin* a)
{
    user = a;
}

/* --------------------------- refesh ------------------------*/
void ManageAdminControl::refresh(){
    qDebug() << "refresh admin window";
    // clear list of projects
    admWin->clearProjectBox();

    //clear the qlist
    ownedProjects.clear();

    // add projects
    //Storage::getDB().getProjects(*user, projectsOwned);
    foreach(Project* q, allProjects){
        if(q->getOwnerID() ==  user->getID()){
            ownedProjects.push_back(q);
        }
    }


    foreach(Project* p, ownedProjects){
        admWin->addToProjectsBox(p->getProjectTitle());
    }
}


/* --------------------------- Project Tab ------------------------*/
/* ------------ edit project ------------*/
void ManageAdminControl::editProject(QString pt){
    qDebug() << "edit project";


    // create a project object and put the project in it from the QList
    projectBeingEdited = 0;
    foreach(Project* p, ownedProjects){
        if(p->getProjectTitle() == pt){
            projectBeingEdited = p;
            break;
        }
    }

    // no project found (probaly error then)
    if(projectBeingEdited == 0){
        //ui->title->setText("Unable to find project");
qDebug() <<    "Unable to find project";
        return;
    }

    // open edit project window
    ProjectWindow *pWin = new ProjectWindow();
    pWin->setParent(this);
    pWin->setOwner(user);
    pWin->setEdit(true);
    pWin->setProject(projectBeingEdited);
    pWin->show();
}


/* ------------ new project ------------*/
void ManageAdminControl::newProject(){
    qDebug() << "new project";

    ProjectWindow *pWin = new ProjectWindow();
    pWin->setParent(this);
    pWin->setOwner(user);
    pWin->setEdit(false);
    pWin->show();
}



/* --------------------------- PPID Tab ------------------------*/
void ManageAdminControl::runPPID(QString pt){
    qDebug() << "runPPID";

    // get project
    PPIDProject = 0;
    foreach(Project* p, ownedProjects){
        if(p->getProjectTitle() == pt){
            PPIDProject = p;
            break;
        }
    }

    // no project found (probaly error then)
    if(PPIDProject == 0){
        qDebug() <<    "Unable to find project";
        return;
    }

    // run PPID algorithm on project
    PPIDManager *ppid = new PPIDManager(PPIDProject->getStudentList(), PPIDProject);
    ppid->runAlgorithm();

    // display PPID algorithm results
}



/* --------------------------- project window ------------------------*/
void ManageAdminControl::saveProject(bool newProj, ProjectWindow* source, QString pName, QString courseNum, QString courseName, int teamSize, QString pDesc){
    qDebug() << "save project";


    if(pName == "" || courseNum == "" || courseName == "" || pDesc == "" ){
        //ui->status->setText("Please complete all fields");
    } else {

 qDebug() << "going to make a project";

        //We are creating new projects with an ID of -1
        //This works because SQL autogenerates the ID
        //We will not be attempting to write the ID of the new project to SQL
        //When we save, SQL will autoincrement the ID at that time.
        //If we update that is a totally different command

Project* project = new Project("-1", pName, user->getID(), courseName, courseNum, pDesc, teamSize);

        if(!newProj){
//          UPDATE
            project->setProjectID(projectBeingEdited->getProjectID());
            facade->storeProject(project, "", user->getID(), false);

            //set PRojectBeingEdited to have the updated fields
            projectBeingEdited->setPTitle(project->getProjectTitle());
            projectBeingEdited->setCourseNum(project->getCourseNum());
            projectBeingEdited->setCourseName(project->getCourseName());
            projectBeingEdited->setPDescription(project->getPDescription());

            delete project; //don;t need it anymore, data is all written

            admWin->refresh();
            source->~ProjectWindow();
        } else{
//          INSERT
            //////
            ///TODO: add the project ot the admin gui drop down
            ///
            facade->storeProject(project, "", user->getID(), true);
            //push project to projectsOwned and master projects list
            ownedProjects.push_back(project);

            admWin->refresh();
            source->~ProjectWindow();
        }
    }


}



/* --------------------------- logout ------------------------*/
void ManageAdminControl::logout(){
    qDebug() << "logout";
    admWin->~AdminWindow();
    facade->setLoggedInUser(NULL);
    facade->run();
    delete this;
}
