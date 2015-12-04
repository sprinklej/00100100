#include "manageadmincontrol.h"
#include "managestudentcontrol.h"
#include "StorageFacade.h"

ManageAdminControl::ManageAdminControl(StorageFacade* f)
{
    facade = f;
    user = (Admin*) facade->getLoggedInUser();
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

    /*
        // clear list of projects
        ui->projectsBox->clear();
        int num = projectsOwned.size();
        for (int i =0; i < num; i++) {
            delete(projectsOwned.takeAt(0));
        }

        // add projects
        Storage::getDB().getProjects(*user, projectsOwned);
        foreach(Project* p, projectsOwned){
            ui->projectsBox->addItem(p->getProjectID());
        } */
}


/* --------------------------- Project Tab ------------------------*/
/* ------------ edit project ------------*/
void ManageAdminControl::editProject(){
    qDebug() << "edit project";

/*
    // create a project object and put the project in it from the QList
    Project* projectBeingEdited = 0;
    foreach(Project* p, projectsOwned){
        if(p->getProjectID() == ui->projectsBox->currentText()){
            projectBeingEdited = p;
        }
    }

    // no project found (probaly error then)
    if(projectBeingEdited == 0){
        ui->title->setText("Unable to find project");
        return;
    }

    // open edit project window
    ProjectWindow *pWin = new ProjectWindow();
    pWin->setParentWindow(this);
    pWin->setOwner(user);
    pWin->setEdit(true);
    pWin->setProject(projectBeingEdited);
    pWin->show(); */
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
void ManageAdminControl::runPPID(){
    qDebug() << "runPPID";
}



/* --------------------------- project window ------------------------*/
void ManageAdminControl::saveProject(){
    qDebug() << "save project";
    /*
    QString pName = ui->titleField->text();
    QString courseNum = ui->numField->text();
    QString courseName = ui->nameField->text();
    int teamSize = ui->teamSizeBox->value();
    QString pDesc = ui->descField->toPlainText();

    if(pName == "" || courseNum == "" || courseName == "" || pDesc == "" ){
        ui->status->setText("Please complete all fields");
    } else {


        //We are creating new projects with an ID of -1
        //This works because SQL autogenerates the ID
        //We will not be attempting to write the ID of the new project to SQL
        //When we save, SQL will make up the ID at that time.
        //If we update that is a totally different command
        Project* project = new Project("-1", pName, owner->getIDNum(), courseName, courseNum, pDesc, teamSize);
        /********
         * TBD: check if the project title exists in the database
         *******/
/*
        if(edit){
//            Storage::getDB().updateProject(project);
            delete project;
            parent->refresh();
            this->~ProjectWindow();
        } else{
//            Storage::getDB().addProject(project, owner);
            delete project;
            parent->refresh();
            this->~ProjectWindow();
        }
    }
*/

}



/* --------------------------- logout ------------------------*/
void ManageAdminControl::logout(){
    qDebug() << "logout";
    admWin->~AdminWindow();
    facade->setLoggedInUser(NULL);
    facade->run();
    delete this;
}
