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
    void signup();
    void setLogWind(LoginWindow*);


//explicit SignupWindow(QWidget *parent = 0);
    void on_radioButton_student_clicked();
    void on_radioButton_admin_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_signup_clicked();
    void getQualifications(Student*);

private:
//Ui::SignupWindow *ui;
    LoginWindow* logWin;
    StorageFacade* facade;

};

#endif
