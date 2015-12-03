#include "managestudentcontrol.h"
#include <iostream>
#include <QDebug>
#include "StorageFacade.h"
using namespace std;

ManageStudentControl::ManageStudentControl(StorageFacade* f)
{
    facade = f;
    user = (Student*) facade->getLoggedInUser();

}


/* --------------------------- run function ------------------------*/
void ManageStudentControl::createGUI()
{
    StudentWindow *studWin = new StudentWindow();
    setStudWind(studWin);
    studWin->setManStudContrl(this);
    studWin->setStudent(user);
    studWin->showUserInfo();
    studWin->refresh();
    studWin->show();
}

/* --------------------------- setters ------------------------*/
void ManageStudentControl::setStudWind(StudentWindow* stWin) // probably not needed anymore
{
    studWin = stWin;
}

void ManageStudentControl::setStudent(Student* s)
{
    user = s;
}

void ManageStudentControl::setJoinedProjects(QList<Project*> JPs)
{
    joinedProjects = JPs;
}

/* --------------------------- getters ------------------------*/
Student* ManageStudentControl::getCurrentUser()
{
    return user;
}



/* --------------------------- Project Tab ------------------------*/
// refresh the list of projects/joined projects
void ManageStudentControl::refresh()
{
    //Storage::getDB().getAllProjects(allProjects);
    facade->getProjects(allProjects);

    foreach(Project* p, allProjects){

        // add to list of all projects
        studWin->setAllProjListWidget(p->getProjectID());

        // add to list of already joined projects
        foreach(Student* s, p->getStudentList()){
            if(s->getIDNum() == user->getIDNum()){
                qDebug() << "joined a project";
                joinedProjects.push_back(p);
                studWin->setJoinedProjListWidget(p->getProjectID());
            }
        }
    }
}



// join a project
void ManageStudentControl::joinProject(QString currentProj)
{
    QString st= "";
    //clear any status text
    studWin->setStatus2(st);

    // join the project
    foreach(Project* p, allProjects){
        if(p->getProjectID() == currentProj){
            if(!joinedProjects.contains(p)){ //Joined projects is not being populated!
                joinedProjects.push_back(p);
                studWin->setJoinedProjListWidget(p->getProjectID());
                facade->storeProject(p, "", user->getID(), false);
                studWin->setStatus2("Project joined!");
            } else {
                studWin->setStatus2("You have already joined this project!");
            }
        }
    }
    return;
}







/* --------------------------- Profile Tab ------------------------* /
// edit a students qualifications
void ManageStudentControl::manageQualifications()
{
    // create qual window
    QualificationWindow* qualWin = new QualificationWindow();
    qualWin->setStudent(user);
    qualWin->setupdate(true);
    qualWin->setStudWind(studWin);
    // opens new window and disables current window
    qualWin->setModal(true);
    qualWin->exec();
}


*/
/* --------------------------- logout ------------------------*/
void ManageStudentControl::logout()
{
    studWin->~StudentWindow();
    facade->run();
    delete this;

}

