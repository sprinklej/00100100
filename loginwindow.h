#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QString>
#include <QDir>
#include <QDebug>
#include <iostream>

#include "studentwindow.h"
#include "adminwindow.h"
#include "signupwindow.h"
#include "User.h"
//#include "Storage.h"

class ManageRegistrationControl;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

    void showLogo(QPixmap logo);
    void setStatus(QString);

    // setter
    void setRegManContrl(ManageRegistrationControl*);

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();

private:
    Ui::LoginWindow *ui;
    ManageRegistrationControl *manRegControl;
};

#endif // LOGINWINDOW_H
