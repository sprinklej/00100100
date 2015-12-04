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


/* --------------------------- GUI function ------------------------*/
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
void ManageStudentControl::setStudWind(StudentWindow* stWin)
{
    studWin = stWin;
}

void ManageStudentControl::setStudent(Student* s)
{
    user = s;
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
/*
    foreach(Project* p, allProjects){

        // add to list of all projects
        studWin->setAllProjListWidget(p->getProjectTitle());

        // add to list of already joined projects
        foreach(Student* s, p->getStudentList()){
            qDebug() << "test";
            if(s->getIDNum() == user->getIDNum()){
                qDebug() << "joined a project";
                joinedProjects.push_back(p);
                studWin->setJoinedProjListWidget(p->getProjectTitle());
            }
        }
    }*/
    studWin->clearLists();

    foreach(Project* p, allProjects){
        studWin->setAllProjListWidget(p->getProjectTitle());
        if(p->getStudentList().contains(user)){
            joinedProjects.push_back(p);
            studWin->setJoinedProjListWidget(p->getProjectTitle());
        }
    }

}



// join a project
void ManageStudentControl::joinProject(QString currentProj)
{
    QString st= "";
    //clear any status text
    studWin->setStatus2(st);

    /*Must do three things:
    1. Add the project to the student's collection
    2. Add the student to the project's collection
    3. Update the project in storage
    */

    //Add the student
    foreach(Project* p, allProjects){
        if(p->getProjectTitle() == currentProj){
            if(!joinedProjects.contains(p)){ //Joined projects is not being populated!
                joinedProjects.push_back(p);
qDebug() << "push project " << p->getProjectTitle() << " to joinedprojects";
               // user->joinProject(p);  //This is crashing
qDebug() << "push project " << p->getProjectTitle() << " to " << user->getFirstName() << "'s projects";

                p->addStudent(user);
qDebug() << "push student " << user->getFirstName() << " to project " << p->getProjectTitle();
                studWin->setJoinedProjListWidget(p->getProjectTitle());
                facade->storeProject(p, "", user->getID(), false);
                studWin->setStatus2("Project joined!");

            } else {
                studWin->setStatus2("You have already joined this project!");
            }
        }
    }

    //Add the project

    refresh();

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
    facade->setLoggedInUser(NULL);
    facade->run();
    delete this;

}

