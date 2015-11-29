#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "projectwindow.h"
#include "Storage.h"
#include <QDebug>

/*

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


// setup the admin window with some info
void AdminWindow::setAdmin(Admin* s)
{
    user = s;
    ui->title->setText("Projects available for admin " + s->getIDNum());
}


// refreshes the list of projects
void AdminWindow::refresh(){

    // clear list of projects
    ui->projectsBox->clear();
    int num = projectsOwned.size();
    for (int i =0; i < num; i++) {
        delete(projectsOwned.takeAt(0));
    }

    // add projects
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


//edit project
void AdminWindow::on_pushButton_2_clicked()
{
    // no projects to edit
    if(ui->projectsBox->currentText() == ""){
        ui->title->setText("No project selected");
        return;
    }

    // create a project object and put the project in it from the QList
    Project* projectBeingEdited = 0;
    foreach(Project* p, projectsOwned){
        if(p->getProjectID() == ui->projectsBox->currentText()){
            projectBeingEdited = p;
        }
    }

    // no project found (probaly error then)
    if(projectBeingEdited == 0){
        ui->title->setText("Unable to find project");
        return;
    }

    // open edit project window
    ProjectWindow *pWin = new ProjectWindow();
    pWin->setParentWindow(this);
    pWin->setOwner(user);
    pWin->setEdit(true);
    pWin->setProject(projectBeingEdited);
    pWin->show();
}

*/
