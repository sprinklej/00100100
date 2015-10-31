#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "qualificationwindow.h"

SignupWindow::SignupWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupWindow)
{
    ui->setupUi(this);
}

SignupWindow::~SignupWindow()
{
    delete ui;
}

void SignupWindow::on_radioButton_student_clicked()
{
    ui->label_ID->setText("Student ID # ");
}

void SignupWindow::on_radioButton_admin_clicked()
{
    ui->label_ID->setText("Email address");
}

void SignupWindow::on_pushButton_ok_clicked()
{
    // get user info
    QString firstName, lastName, ID;
    firstName = ui->lineEdit_firstname->text();
    lastName = ui->lineEdit_lastname->text();
    ID = ui->lineEdit_ID->text();

    //validate userinput

    // add user info to database
    if(ui->radioButton_student->isChecked()){
        Student* st = new Student(firstName, lastName, ID, 1);
        getQualifications(st);

    } else if(ui->radioButton_admin->isChecked()) {
        Admin(firstName, lastName, ID, 1); // why extra argument?
        // create admin account
    }

    //if no errors close window
    this->~SignupWindow();
}

void SignupWindow::on_pushButton_cancel_clicked()
{
    this->~SignupWindow();
}

void SignupWindow::getQualifications(Student* st){
    this->hide();
    QualificationWindow* qualWin = new QualificationWindow();
    qualWin->setStudent(st);
    qualWin->show();
}
