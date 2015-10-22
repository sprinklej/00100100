#include <QString>
#include "loginwindow.h"
#include "ui_loginwindow.h"


using namespace std;

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

void LoginWindow::on_pushButton_login_clicked()
{
     QString userName;
     userName = ui->lineEdit_username->text();

     // check against  Database here

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
