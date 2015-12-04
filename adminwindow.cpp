#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "projectwindow.h"
#include "Storage.h"
#include <QDebug>
#include "manageadmincontrol.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    // open window in middle of screen
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()
                    )
                );
}


AdminWindow::~AdminWindow()
{
    delete ui;
}


/* --------------------------- refresh ------------------------*/
void AdminWindow::refresh(){
    manAddControl->refresh();
}


/* --------------------------- update GUI elements ------------------------*/
/* ------------ Project Tab ------------*/
void AdminWindow::setTitle(QString string){
    ui->title->setText(string);
}

void AdminWindow::clearProjectBox(){
    ui->projectsBox->clear();
}


/* --------------------------- setters ------------------------*/
void AdminWindow::setAdmin(Admin* a)
{
    user = a;
    setTitle("Projects available for admin " + user->getIDNum());
}

void AdminWindow::setManAdmContrl(ManageAdminControl* mac)
{
    manAddControl = mac;
}



/* --------------------------- Project Tab ------------------------*/
void AdminWindow::on_pushButton_EProj_clicked() // edit project clicked
{
    // no projects to edit
     if(ui->projectsBox->currentText() == ""){
        setTitle("No project selected");
     } else {
        manAddControl->editProject();
     }
}

void AdminWindow::on_pushButton_NProj_clicked() // new project clicked
{
    manAddControl->newProject();
}



/* --------------------------- PPID Tab ------------------------*/
void AdminWindow::on_pushButton_PPID_clicked()
{
    manAddControl->runPPID();
}



/* --------------------------- logout ------------------------*/
void AdminWindow::on_pushButton_logout1_clicked()
{
    manAddControl->logout();
}

void AdminWindow::on_pushButton_logout2_clicked()
{
    manAddControl->logout();
}



