#ifndef MANAGEREGISTRATIONCONTROL_H
#define MANAGEREGISTRATIONCONTROL_H

#include "User.h"
#include <QDialog>


class ManageRegistrationControl
{
public:
    ManageRegistrationControl();

    ~ManageRegistrationControl();

    void login(Admin*);
    void login(Student*);
//explicit SignupWindow(QWidget *parent = 0);

    void on_radioButton_student_clicked();
    void on_radioButton_admin_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_signup_clicked();
    void getQualifications(Student*);

private:
//Ui::SignupWindow *ui;

};

#endif
