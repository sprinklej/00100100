#include "projectwindow.h"
#include "ui_projectwindow.h"
//#include "Storage.h"
#include "QDebug"
#include "manageadmincontrol.h"

ProjectWindow::ProjectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectWindow)
{
    ui->setupUi(this);
    edit = false;
    project = 0;
}

ProjectWindow::~ProjectWindow()
{
    delete ui;    
}

void ProjectWindow::setEdit(bool b){
    edit = b;
}

void ProjectWindow::setOwner(Admin* ad){
    owner = ad;
}

void ProjectWindow::setProject(Project* p){
    project = p;
    //ui->titleField->setText(p->getProjectID());
    //-- we changed the schema to make this an integer key
    //it is now:
    ui->titleField->setText(p->getProjectTitle());
    ui->nameField->setText(p->getCourseName());
    ui->numField->setText(p->getCourseNum());
    ui->descField->setText(p->getPDescription());
    ui->teamSizeBox->setValue(p->getTeamSize());
}

void ProjectWindow::setParent(ManageAdminControl* par){
    parent = par;
}

void ProjectWindow::on_cancelButton_clicked()
{
    this->~ProjectWindow();
}

void ProjectWindow::on_saveButton_clicked()
{
    parent->saveProject();
}


