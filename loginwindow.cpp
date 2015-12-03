#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "manageRegistrationControl.h"
using namespace std;

#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->status->setText("");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


/* --------------------------- setters ------------------------*/
void LoginWindow::setRegManContrl(ManageRegistrationControl* mrc)
{
    manRegControl = mrc;
}



/* --------------------------- update GUI elements ------------------------*/
void LoginWindow::showLogo(QPixmap logo)
{
    ui->label_logo->setPixmap(logo);
}

void LoginWindow::setStatus(QString string)
{
    ui->status->setText(string);
}



/* --------------------------- login ------------------------*/
void LoginWindow::on_pushButton_login_clicked()
{
    // check if text was entered
    if (ui->lineEdit_username->text() == ""){
        ui->status->setText("Enter username");
    } else {
        ui->status->setText("");

        // get username from text box
        QString userName;
        userName = ui->lineEdit_username->text();
        // login
        manRegControl->login(userName);
    }
}



/* --------------------------- signup ------------------------*/
void LoginWindow::on_pushButton_signup_clicked()
{
    manRegControl->signup();
    // show signup window and disables login window
    /*
    SignupWindow *signupWin = new SignupWindow;
    signupWin->setModal(true);
    signupWin->exec(); */
}



