#include "manageadmincontrol.h"
#include "managestudentcontrol.h"

ManageAdminControl::ManageAdminControl(StorageFacade* f)
{
    int x = 0;
}

void ManageAdminControl::createGUI()
{

    AdminWindow *studWin = new AdminWindow();
    //setStudWind(studWin);
    studWin->setManAdmContrl(this);
    studWin->setAdmin(user);
    //studWin->showUserInfo();
    studWin->refresh();
    studWin->show();
}

/* --------------------------- setters ------------------------*/
void ManageAdminControl::setAdmWind(AdminWindow* adWin) // probably not needed anymore
{
    admWin = adWin;
}

void ManageAdminControl::setAdmin(Admin* a)
{
    user = a;
}


/*
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
*/
