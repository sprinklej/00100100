#include "signupwindow.h"
#include "ui_signupwindow.h"
//#include "qualificationwindow.h"
#include "manageRegistrationControl.h"

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

/* --------------------------- setter ------------------------*/
void SignupWindow::setParent(ManageRegistrationControl * mrc)
{
    parent = mrc;
}

/* --------------------------- update GUI elements ------------------------*/
void SignupWindow::on_radioButton_student_clicked()
{
    ui->label_ID->setText("Student ID # ");
}

void SignupWindow::on_radioButton_admin_clicked()
{
    ui->label_ID->setText("Email address");
}


/* --------------------------- click ok ------------------------*/
void SignupWindow::on_pushButton_ok_clicked()
{
    int flag = 1;
    bool radio;

    // highlight text fields not filled in
    if (ui->lineEdit_firstname->text() == "") {
        ui->label_FN->setStyleSheet("QLabel {color:red}");
        flag = 0;
    }
    if (ui->lineEdit_lastname->text() == "") {
        ui->label_LN->setStyleSheet("QLabel {color:red}");
        flag = 0;
    }
    if (ui->lineEdit_ID->text() == "") {
        ui->label_ID->setStyleSheet("QLabel {color:red}");
        flag = 0;
    }

    // do actual work
    if (flag) {
        if(ui->radioButton_student->isChecked()){
            radio = true;
        } else {
            radio = false;
        }

        parent->createNewUser(ui->lineEdit_firstname->text(),ui->lineEdit_lastname->text(),
                              ui->lineEdit_ID->text(), radio);
    }
}


/* --------------------------- click cancel ------------------------*/
void SignupWindow::on_pushButton_cancel_clicked()
{
    this->~SignupWindow();
}


void SignupWindow::getQualifications(Student* st){
    /*
    this->hide();
    QualificationWindow* qualWin = new QualificationWindow();
    qualWin->setStudent(st);
    qualWin->show();
    */
}


