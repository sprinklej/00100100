#ifndef MANAGEREGISTRATIONCONTROL_H
#define MANAGEREGISTRATIONCONTROL_H

//#include "User.h"
#include <QDialog>
#include "loginwindow.h"
class StorageFacade;

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

    //signup
    void signup();
    void createNewUser(QString, QString, QString, bool);
    void setSignupWin(SignupWindow*);

private:
//Ui::SignupWindow *ui;
    LoginWindow* logWin;
    SignupWindow* signupWin;
    StorageFacade* facade;
};

#endif
