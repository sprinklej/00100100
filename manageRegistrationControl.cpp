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

void ManageRegistrationControl::setSignupWin(SignupWindow* suw)
{
    signupWin = suw;
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
    //logWin->setStatus("you clicked signup!");
    // show signup window and disables login window
    SignupWindow *signupWin = new SignupWindow;
    setSignupWin(signupWin);
    signupWin->setParent(this);
    signupWin->setModal(true);
    signupWin->exec();
}

/* ------------ create new user ------------*/
// bool radio: student = true, admin = false
void ManageRegistrationControl::createNewUser(QString fName, QString lName, QString ID, bool radio)
{
    if (radio) { // create student
        Student * st = new Student(fName, lName, ID, 1);
        //getQualifications(st);
    } else { // create admin
        Admin* ad = new Admin(fName, lName, ID, 1);
    }

    // save user info!!!

    // destroy signup
    signupWin->~SignupWindow();
    setSignupWin(NULL);
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
