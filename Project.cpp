#include "Project.h"

Project::Project(QString project_ID, QString course_Num, QString p_Title, QString course_Name, QString p_Description /*, QList<Student> * stdnts*/){
    /*projectID = 123;
    courseNum = 3004;
    pTitle = QString("cuPID");
    courseName = QString("COMP 3004");
    pDescription = QString("Write some UML, then code cuPID!!");*/
    projectID = project_ID;
    courseNum = course_Num;
    pTitle = p_Title;
    courseName = course_Name;
    pDescription = p_Description;

    students = QList<Student>();

}

Project::~Project(){
    //nothing yet
}

void Project::addStudent(Student& stdnt){
    students.push_front(stdnt);
}


/////////////// GETTERS
QString Project::getProjectID(){return projectID;}
QString Project::getCourseNum(){return courseNum;}
QString Project::getPTitle(){return pTitle;}
QString Project::getCourseName(){return courseName;}
QString Project::getPDescription(){return pDescription;}
QList<Student>& Project::getStudentList(){return students;}
