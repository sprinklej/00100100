#include <QString>
#include <QDir>
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

     // check login against Database
     User* currentUser = 0;
     Storage::getDB().getUser(userName, currentUser);
     //cout << currentUser->toString();

     // logged in window
     if (userName != "test") // replace with a better condition, once DB is connected
     {
        this->hide();
        MainWindow *w = new MainWindow;
        w->show();
     } else {
         ui->status->setText("Username does not exist.");
     }
}

void LoginWindow::on_pushButton_signup_clicked()
{
    ;
}
