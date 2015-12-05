#include "Project.h"

//Project::Project(QString project_ID, QString course_Num, QString course_Name, QString p_Description, int ts /*, QList<Student> * stdnts*/){
Project::Project(QString project_ID, QString ptitle, QString own, QString course_Name, QString course_Num, QString p_Description, int ts){
    projectID = project_ID;
    projectTitle = ptitle;
    ownerID = own;
    courseNum = course_Num;
    courseName = course_Name;
    pDescription = p_Description;
    teamSize = ts;
    students = QList<Student*>();
}

Project::~Project(){
/*    foreach(Student* s, students){
        delete s;
    }*/
}

void Project::addStudent(Student* stdnt){
    students.push_front(stdnt);
}


/////////////// GETTERS
QString Project::getProjectID(){return projectID;}
QString Project::getProjectTitle(){return projectTitle;}
QString Project::getCourseNum(){return courseNum;}
QString Project::getCourseName(){return courseName;}
QString Project::getPDescription(){return pDescription;}
QList<Student*>& Project::getStudentList(){return students;}
int Project::getTeamSize(){return teamSize;}
QString Project::getOwnerID(){return ownerID;}

//////Setters
void Project::setPTitle(QString pt){projectTitle = pt;}
void Project::setProjectID(QString p_ID){projectID = p_ID;}
void Project::setCourseName(QString cN){courseName = cN;}
void Project::setCourseNum(QString cN){courseNum = cN;}
void Project::setPDescription(QString pd){pDescription = pd;}
