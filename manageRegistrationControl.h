#ifndef MANAGEREGISTRATIONCONTROL_H
#define MANAGEREGISTRATIONCONTROL_H

//#include "User.h"
#include <QDialog>
#include "loginwindow.h"
#include "managequalificationcontrol.h"
class StorageFacade;
//class ManageStudentControl;
//class ManageRegistrationControl;


using namespace std;

class ManageRegistrationControl
{
public:
    ManageRegistrationControl(StorageFacade *f);
    ~ManageRegistrationControl();

    void createGUI();
    void login(QString);
    void loginSuccess();
    void loginFailure(QString);
    void setLogWind(LoginWindow*);
    void setStatus(QString);

    //signup
    void signup();
    void createNewUser(QString, QString, QString, bool);
    void setSignupWin(SignupWindow*);
    void getQualifictaions(Student *);

private:
//Ui::SignupWindow *ui;
    LoginWindow* logWin;
    SignupWindow* signupWin;
    StorageFacade* facade;
};

#endif
