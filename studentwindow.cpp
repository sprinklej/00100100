#include "studentwindow.h"
#include "ui_studentwindow.h"
#include"Storage.h"
#include"qualificationwindow.h"
#include<QDebug>


StudentWindow::StudentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
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

StudentWindow::~StudentWindow()
{
    delete ui;
}



void StudentWindow::setUser(Student* s){
    user = s;
    ui->lineEdit->setText(user->getFirstName());
    ui->lineEdit_2->setText(user->getLastName());

    allProjects = QList<Project*>();
    joinedProjects = QList<Project*>();

    refresh();
}

void StudentWindow::refresh(){
    Storage::getDB().getAllProjects(allProjects);

    foreach(Project* p, allProjects){
        ui->allProjlistWidget->addItem(p->getProjectID());
        ui->cbAllProjects->addItem(p->getProjectID());
        foreach(Student* s, p->getStudentList()){
            if(s->getIDNum() == user->getIDNum()){
                joinedProjects.push_back(p);
                ui->joinedProjlistWidget->addItem(p->getProjectID());

            }
        }
    }
}

//join project
void StudentWindow::on_pushButton_4_clicked(){
    if(ui->cbAllProjects->currentText() != ""){
        foreach(Project* p, allProjects){
            if(p->getProjectID() == ui->cbAllProjects->currentText()){
                if(!joinedProjects.contains(p)){
                    joinedProjects.push_back(p);
                    ui->joinedProjlistWidget->addItem(p->getProjectID());
                    Storage::getDB().joinProject(p, user);
                } else{
                    ui->status2->setText("You have already joined this project!");
                }
            }
        }
    }
}


void StudentWindow::on_pushButton_3_clicked()
{

}


//cancel button clicked
void StudentWindow::on_pushButton_5_clicked()
{
    this->~StudentWindow();
}

//manage qualifications clicked
void StudentWindow::on_pushButton_6_clicked()
{
    QString fn = ui->lineEdit->text();
    QString ln = ui->lineEdit_2->text();
    if(fn != "" && ln != ""){
        user->setFirstName(fn);
        user->setLastName(ln);
        this->hide();
        QualificationWindow* qualWin = new QualificationWindow();
        qualWin->setStudent(user);
        qualWin->setupdate(true);
        qualWin->show();

        this->~StudentWindow();
    } else{
        ui->status->setText("Cannot set names to blank.");
    }
}

//save button clicked
void StudentWindow::on_pushButton_clicked()
{
    QString fn = ui->lineEdit->text();
    QString ln = ui->lineEdit_2->text();
    if(fn != "" && ln != ""){
        user->setFirstName(fn);
        user->setLastName(ln);
        Storage::getDB().updateStudent(user);


        qDebug() << "Write: " << user->toString();

        qDebug() <<":fname" << user->getFirstName();
        qDebug() <<":lname" << user->getLastName();
        qDebug() <<":att_leader" << user->getAtt_leader();
        qDebug() <<":att_avail" << user->getAtt_avail();
        qDebug() <<":att_2404" << user->getAtt_2404();
        qDebug() <<":att_3005" << user->getAtt_3005();
        qDebug() <<":att_coding" << user->getAtt_coding();
        qDebug() <<":att_dbase" << user->getAtt_dbase();
        qDebug() <<":att_selfDir" << user->getAtt_selfDir();
        qDebug() <<":att_writing" << user->getAtt_writing();
        qDebug() <<":att_UI" << user->getAtt_UI();
        qDebug() <<":att_algorithm" << user->getAtt_algorithm();
        qDebug() <<":att_present" << user->getAtt_present();
        qDebug() <<":att_teamwork" << user->getAtt_teamwork();
        qDebug() <<":att_experience" << user->getAtt_experience();
        qDebug() <<":att_testing" << user->getAtt_testing();
        qDebug() <<":att_UML" << user->getAtt_UML();
        qDebug() <<":att_req" << user->getAtt_req();
        qDebug() <<":att_reliable" << user->getAtt_reliable();
        qDebug() <<":att_comm" << user->getAtt_comm();
        qDebug() <<":att_respect" << user->getAtt_respect();
        qDebug() <<":att_creative" << user->getAtt_creative();
        qDebug() <<":att_critic" << user->getAtt_critic();
        qDebug() <<":req_leader" << user->getReq_leader();
        qDebug() <<":req_2404" << user->getReq_2404();
        qDebug() <<":req_3005" << user->getReq_3005();
        qDebug() <<":req_coding" << user->getReq_coding();
        qDebug() <<":req_dbase" << user->getReq_dbase();
        qDebug() <<":req_selfDir" << user->getReq_selfDir();
        qDebug() <<":req_writing" << user->getReq_writing();
        qDebug() <<":req_UI" << user->getReq_UI();
        qDebug() <<":req_algorithm" << user->getReq_algorithm();
        qDebug() <<":req_present" << user->getReq_present();
        qDebug() <<":req_teamwork" << user->getReq_teamwork();
        qDebug() <<":req_experience" << user->getReq_experience();
        qDebug() <<":req_testing" << user->getReq_testing();
        qDebug() <<":req_UML" << user->getReq_UML();
        qDebug() <<":req_req" << user->getReq_req();
        qDebug() <<":req_reliable" << user->getReq_reliable();
        qDebug() <<":req_comm" << user->getReq_comm();
        qDebug() <<":req_respect" << user->getReq_respect();
        qDebug() <<":req_creative" << user->getReq_creative();
        qDebug() <<":req_critic" << user->getReq_critic();
        qDebug() <<":iid" << user->getIDNum();

        this->~StudentWindow();
    } else{
        ui->status->setText("Cannot set names to blank.");
    }


}


void StudentWindow::on_pushButton_2_clicked()
{
    this->~StudentWindow();
}
