#include "loginwindow.h"
#include "ui_loginwindow.h"
using namespace std;

/*
LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->status->setText("");

    // set working directory
    QDir curr = QDir::current(); //get current dir
    curr.cdUp();                 //go up one dir
    QString logoPath = curr.path() + "/00100100/images/logo.png"; //set dir

    // display logo
    QPixmap logo (logoPath);
    ui->label_logo->setPixmap(logo);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


// login to system
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
         this->~LoginWindow();
     }
}

// login as an admin
void LoginWindow::login(Admin* ad){
    //this->hide();
    AdminWindow *adminWin = new AdminWindow();
    adminWin->show();
    adminWin->setAdmin(ad);
    adminWin->refresh();
}

// login as a student
void LoginWindow::login(Student* st){
    //this->hide();
    StudentWindow *studWin = new StudentWindow();
    ManageStudentControl* manStudCon = new ManageStudentControl();
    studWin->show();
    studWin->setManStudContrl(manStudCon);

    manStudCon->setStudWind(studWin);
    manStudCon->setStudent(st);

    studWin->setStudent(st);
    studWin->showUserInfo();
    studWin->refresh();
}


// sign up new student or admin user
void LoginWindow::on_pushButton_signup_clicked()
{
    // show signup window and disables login window
    SignupWindow *signupWin = new SignupWindow;
    signupWin->setModal(true);
    signupWin->exec();
}
*/
