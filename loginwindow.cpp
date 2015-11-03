#include <QString>
#include <QDir>
#include <QDebug>
#include <iostream>
#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "User.h"
#include "Storage.h"
using namespace std;


LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->status->setText("");

    // set working directory
    QDir curr = QDir::current();
    curr.cdUp();
    QString logoPath = curr.path() + "/00100100/images/logo.png";
    //ui->status->setText(logoPath);
    //QDir::setCurrent(QCoreApplication::applicationDirPath());
    //ui->status->setText(QDir::currentPath());

    // display logo
    QPixmap logo (logoPath);
    ui->label_logo->setPixmap(logo);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
     // get username from text box
     QString userName;
     userName = ui->lineEdit_username->text();

     User* currentUser = 0;

     // check login against Database
     bool found = Storage::getDB().getUser(userName, &currentUser);

     if(!found){
         ui->status->setText("Username does not exist.");
     } else {
         if (userName.at(0) == '1') {
            login((Student*)currentUser);
         } else{
            login((Admin*)currentUser);
         }
     }


}

void LoginWindow::login(Admin* ad){
    this->hide();
    AdminWindow *adminWin = new AdminWindow();
    adminWin->setUser(ad);
    adminWin->show();
}

void LoginWindow::login(Student* st){
    this->hide();
    StudentWindow *studWin = new StudentWindow();
    //studWin->setUser(st);
    studWin->setStudent(st);
    studWin->show();
}

void LoginWindow::on_pushButton_signup_clicked()
{
    // show signup window and disables login window
    SignupWindow *signupWin = new SignupWindow;
    signupWin->setModal(true);
    signupWin->exec();
}
