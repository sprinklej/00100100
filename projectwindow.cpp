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
    // highlight text fields not filled in
    if (ui->titleField->text() == "") {
        ui->label_PT->setStyleSheet("QLabel {color:red}");
    }
    if (ui->numField->text() == "") {
        ui->label_CNUM ->setStyleSheet("QLabel {color:red}");
    }
    if (ui->nameField->text() == "") {
        ui->label_CNAM->setStyleSheet("QLabel {color:red}");
    }
    if (ui->descField->toPlainText() == "") {
        ui->label_PD->setStyleSheet("QLabel {color:red}");
    }

    QString pName = ui->titleField->text();
    QString courseNum = ui->numField->text();
    QString courseName = ui->nameField->text();
    int teamSize = ui->teamSizeBox->value();
    QString pDesc = ui->descField->toPlainText();
    if(pName == "" || courseNum == "" || courseName == "" || pDesc == "" ){
        ui->status->setText("Please complete all fields");
    } else {
        parent->saveProject(!edit, this, pName, courseNum, courseName, teamSize, pDesc);
    }
}


