#include "manageRegistrationControl.h"
#include "signupwindow.h"

#include <QDebug>
#include "StorageFacade.h"
using namespace std;

ManageRegistrationControl::ManageRegistrationControl(StorageFacade* f)
{
    facade = f;
}

ManageRegistrationControl::~ManageRegistrationControl()
{
}


/* --------------------------- GUI function ------------------------*/
void ManageRegistrationControl::createGUI()
{
    // set working directory
    QDir curr = QDir::current(); //get current dir
    curr.cdUp();                 //go up one dir
    QString logoPath = curr.path() + "/00100100/images/logo.png"; //set dir

    // create loginWindow object
    LoginWindow *logWin = new LoginWindow();
    setLogWind(logWin);
    logWin->setRegManContrl(this);

    // display logo
    QPixmap logo (logoPath);
    logWin->showLogo(logo);

    // show window
    logWin->show();
}



/* --------------------------- setters ------------------------*/
void ManageRegistrationControl::setLogWind(LoginWindow* lWin)
{
    logWin = lWin;
}



/* --------------------------- login ------------------------*/
void ManageRegistrationControl::login(QString uID) {
    facade->handleLogin(this, uID);
}

void ManageRegistrationControl::loginSuccess() {
    logWin->setStatus("");
    logWin->~LoginWindow();
    facade->run();
    delete this;
}

void ManageRegistrationControl::loginFailure(QString string) {
    logWin->setStatus(string);
}



/* --------------------------- signup ------------------------*/
void ManageRegistrationControl::signup()
{
    logWin->setStatus("you clicked signup!");
}





/* --------------------------- needed? ------------------------*/
void ManageRegistrationControl::on_radioButton_admin_clicked()
{
//ui->label_ID->setText("Email address");
}

void ManageRegistrationControl::on_radioButton_student_clicked()
{
//ui->label_ID->setText("Student ID # ");
}

void ManageRegistrationControl::on_pushButton_cancel_clicked()
{
//this->~SignupWindow();
}

void ManageRegistrationControl::on_pushButton_signup_clicked()
{
    // show signup window and disables login window
    SignupWindow *signupWin = new SignupWindow;
    signupWin->setModal(true);
    signupWin->exec();
}

/*
void ManageRegistrationControl::getQualifictaions(Student *st)
{
    this->hide();
    QualificationWindow* qualWin = new QualificationWindow();
    qualWin->setStudent(st);
    qualWin->show();
}
*/
