#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "projectwindow.h"
#include"Storage.h"
#include<QDebug>
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
    projectsOwned = QList<Project*>();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::setUser(Admin* s){
    user = s;
    ui->title->setText("Projects available for admin " + s->getIDNum());
    refresh();
}


/********************
 * TBD: this crashes from all triggers other than class constructor
 * *****************/
void AdminWindow::refresh(){

    ui->projectsBox->clear();

    foreach(Project* p, projectsOwned){
        delete p;
    }
    projectsOwned.empty();

    Storage::getDB().getProjects(*user, projectsOwned);

    foreach(Project* p, projectsOwned){
        ui->projectsBox->addItem(p->getProjectID());
    }

}

//create a new project
void AdminWindow::on_pushButton_clicked(){
    ProjectWindow *pWin = new ProjectWindow();
    pWin->setParentWindow(this);
    pWin->setOwner(user);
    pWin->setEdit(false);
    pWin->show();
}

//cancel
void AdminWindow::on_pushButton_4_clicked()
{
    delete this;
}

//edit project
void AdminWindow::on_pushButton_2_clicked()
{
    if(ui->projectsBox->currentText() == ""){
        ui->title->setText("No project selected");
        return;
    }

    Project* projectBeingEdited = 0;
    foreach(Project* p, projectsOwned){
        if(p->getPDescription() == ui->projectsBox->currentText()){
            projectBeingEdited = p;
        }
    }

    if(projectBeingEdited == 0){
        ui->title->setText("Unable to find project");
        return;
    }

    ProjectWindow *pWin = new ProjectWindow();
    pWin->setParentWindow(this);
    pWin->setOwner(user);
    pWin->setEdit(true);
    pWin->setProject(projectBeingEdited);
    pWin->show();
}

void AdminWindow::on_pushButton_5_clicked()
{
    //refresh();
}
