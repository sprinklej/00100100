#include "projectwindow.h"
#include "ui_projectwindow.h"
#include "Storage.h"
#include "QDebug"
#include "adminwindow.h"

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
    ui->titleField->setText(p->getProjectID());
    ui->nameField->setText(p->getCourseName());
    ui->numField->setText(p->getCourseNum());
    ui->descField->setText(p->getPDescription());
    ui->teamSizeBox->setValue(p->getTeamSize());
}

void ProjectWindow::setParentWindow(AdminWindow* par){
    parentWindow = par;
}

void ProjectWindow::on_cancelButton_clicked()
{
    this->~ProjectWindow();
}

void ProjectWindow::on_saveButton_clicked()
{
    QString pName = ui->titleField->text();
    QString courseNum = ui->numField->text();
    QString courseName = ui->nameField->text();
    int teamSize = ui->teamSizeBox->value();
    QString pDesc = ui->descField->toPlainText();

    if(pName == "" || courseNum == "" || courseName == "" || pDesc == "" ){
        ui->status->setText("Please complete all fields");
    } else {

        Project* project = new Project(pName, owner->getIDNum(), courseName, courseNum, pDesc, teamSize);
        /********
         * TBD: check if the project title exists in the database
         *******/

        if(edit){
            Storage::getDB().updateProject(project);
            delete project;
            parentWindow->refresh();
            this->~ProjectWindow();
        } else{
            Storage::getDB().addProject(project, owner);
            delete project;
            parentWindow->refresh();
            this->~ProjectWindow();
        }
    }
}
