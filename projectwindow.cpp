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
    //ui->titleField->setText(p->getProjectID());
    //-- we changed the schema to make this an integer key
    //it is now:
    ui->titleField->setText(p->getProjectTitle());
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


        //We are creating new projects with an ID of -1
        //This works because SQL autogenerates the ID
        //We will not be attempting to write the ID of the new project to SQL
        //When we save, SQL will make up the ID at that time.
        //If we update that is a totally different command
        Project* project = new Project("-1", pName, owner->getIDNum(), courseName, courseNum, pDesc, teamSize);
        /********
         * TBD: check if the project title exists in the database
         *******/

        if(edit){
//            Storage::getDB().updateProject(project);
            delete project;
            parentWindow->refresh();
            this->~ProjectWindow();
        } else{
//            Storage::getDB().addProject(project, owner);
            delete project;
            parentWindow->refresh();
            this->~ProjectWindow();
        }
    }
}


