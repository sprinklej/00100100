#include "Project.h"

Project::Project(int project_ID, int course_Num, QString p_Title, QString course_Name, QString p_Description /*, QList<Student> * stdnts*/){
    projectID = 123;
    courseNum = 3004;
    pTitle = QString("cuPID");
    courseName = QString("COMP 3004");
    pDescription = QString("Write some UML, then code cuPID!!");
    students = QList<Student>();

}

void Project::addStudent(Student& stdnt){
    students.push_front(stdnt);
}


/////////////// GETTERS
int Project::getProjectID(){return projectID;}
int Project::getCourseNum(){return courseNum;}
QString Project::getPTitle(){return pTitle;}
QString Project::getCourseName(){return courseName;}
QString Project::getPDescription(){return pDescription;}
