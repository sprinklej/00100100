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
#include "Storage.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

    void login(Admin*);
    void login(Student*);

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();

private:
    Ui::LoginWindow *ui;

};

#endif // LOGINWINDOW_H
