#ifndef MANAGESTUDENTCONTROL_H
#define MANAGESTUDENTCONTROL_H

class StudentWindow;
#include "studentwindow.h"

using namespace std;

class ManageStudentControl
{
public:
    ManageStudentControl();
    void setStudWind(StudentWindow*);
    void joinProject();

private:
    StudentWindow* studWin;
};

#endif // MANAGESTUDENTCONTROL_H
