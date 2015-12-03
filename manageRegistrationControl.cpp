#include "manageRegistrationControl.h"
#include "signupwindow.h"
#include "qualificationwindow.h"
#include "ui_qualificationwindow.h"
#include "Storage.h"

ManageRegistrationControl::ManageRegistrationControl()
{
//ui(new Ui::SignupWindow);

//ui->setupUi(this);
//ui->status->setText("");

    // set working directory
    QDir curr = QDir::current(); //get current dir
    curr.cdUp();                 //go up one dir
    QString logoPath = curr.path() + "/00100100/images/logo.png"; //set dir

    // display logo
    QPixmap logo (logoPath);
//ui->label_logo->setPixmap(logo);
}

ManageRegistrationControl::~ManageRegistrationControl()
{
//delete ui;
}

void ManageRegistrationControl::login(Admin* ad){
   /* AdminWindow *adminWin = new AdminWindow();
    adminWin->show();
    adminWin->setAdmin(ad);
    adminWin->refresh();
    */
}

void ManageRegistrationControl::login(Student* st){
   /* StudentWindow *studWin = new StudentWindow();
    ManageStudentControl* manStudCon = new ManageStudentControl();
    studWin->show();
    studWin->setManStudContrl(manStudCon);

    manStudCon->setStudWind(studWin);
    manStudCon->setStudent(st);

    studWin->setStudent(st);
    studWin->showUserInfo();
    studWin->refresh();
    */
}


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
