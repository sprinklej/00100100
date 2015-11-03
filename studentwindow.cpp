#include "studentwindow.h"
#include "ui_studentwindow.h"
#include "Storage.h"
#include "qualificationwindow.h"
#include <QDebug>


// create and setup window
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

    // clear text
    ui->status2->setText("");
}


//destructor
StudentWindow::~StudentWindow()
{
    delete ui;
}


// setter
void StudentWindow::setStudent(Student* s)
{
    user = s;
}



/* --------------------------- Project Tab ------------------------*/
// refresh projects
void StudentWindow::refresh(){
    Storage::getDB().getAllProjects(allProjects);

    foreach(Project* p, allProjects){
        // add to list of all projects
        ui->allProjlistWidget->addItem(p->getProjectID());

        // add to list of already joined projects
        foreach(Student* s, p->getStudentList()){
            if(s->getIDNum() == user->getIDNum()){
                joinedProjects.push_back(p);
                ui->joinedProjlistWidget->addItem(p->getProjectID());
            }
        }
    }

}


//join project
void StudentWindow::on_pushButton_joinProject_clicked()
{
    //clear any status text
    ui->status2->setText("");

    // get project from list
    QString currentProj;
    currentProj =  ui->allProjlistWidget->currentItem()->text();

    // join project
    foreach(Project* p, allProjects){
        if(p->getProjectID() == currentProj){
            if(!joinedProjects.contains(p)){
                joinedProjects.push_back(p);
                ui->joinedProjlistWidget->addItem(p->getProjectID());
                Storage::getDB().joinProject(p, user);
                ui->status2->setText("Project joined!");
            } else {
                ui->status2->setText("You have already joined this project!");
            }
        }
    }
}



/* --------------------------- Profile Tab ------------------------*/
// set the student info
void StudentWindow::setUser(){

    ui->lineEdit->setText(user->getFirstName());
    ui->lineEdit_2->setText(user->getLastName());

    allProjects = QList<Project*>();
    joinedProjects = QList<Project*>();

}


//cancel button clicked
void StudentWindow::on_pushButton_5_clicked()
{
    this->~StudentWindow();
}


//manage qualifications clicked
void StudentWindow::on_pushButton_manQual_clicked()
{
    QString fn = ui->lineEdit->text();
    QString ln = ui->lineEdit_2->text();

    qDebug() << user->getFirstName();


    if(fn != "" && ln != ""){
        user->setFirstName(fn);
        user->setLastName(ln);

       // this->hide();
        QualificationWindow* qualWin = new QualificationWindow();
        qualWin->setStudent(user);
        qualWin->setupdate(true);
        qualWin->setStudWind(this);
        // opens new window and disables current window
        qualWin->setModal(true);
        qualWin->exec();
    } else {
        ui->status->setText("Cannot set names to blank.");
    }

}


void StudentWindow::showUserInfo()
{
    ui->firstName->setText(user->getFirstName());
    ui->lastName->setText(user->getLastName());

    if (user->getAtt_leader() == false) {
        ui->leader->setText("False");
    } else {
        ui->leader->setText("True");
    }

    // coding strings
    ui->grade2404->setText(codingString(user->getAtt_2404()));
    ui->grade3005->setText(codingString(user->getAtt_3005()));

    // experience strings
    ui->cplusplus->setText(experienceString(user->getAtt_coding()));
    ui->dbDesign->setText(experienceString(user->getAtt_dbase()));

    //agree strings
    ui->selfDirected->setText(agreeString(user->getAtt_selfDir()));
    ui->uiDesign->setText(agreeString(user->getAtt_UI()));
    ui->algorithmDesign->setText(agreeString(user->getAtt_algorithm()));
    ui->presentationSkills->setText(agreeString(user->getAtt_present()));
    ui->teamwork->setText(agreeString(user->getAtt_teamwork()));
    ui->softWareTest->setText(agreeString(user->getAtt_testing()));
    ui->umlDesign->setText(agreeString(user->getAtt_UML()));
    ui->reqAnalysis->setText(agreeString(user->getAtt_req()));
    ui->reliable->setText(agreeString(user->getAtt_reliable()));

    ui->commSkills->setText(agreeString(user->getAtt_comm()));
    ui->respectful->setText(agreeString(user->getAtt_respect()));
    ui->creative->setText(agreeString(user->getAtt_creative()));
    ui->constructCrit->setText(agreeString(user->getAtt_critic()));

    // work experience
    QString expString;
    if (user->getAtt_experience() == 0) {
        expString = "None";
    } else if(user->getAtt_experience() == 1) {
        expString = "Summer";
    } else if(user->getAtt_experience() == 2) {
        expString = "Co-op";
    } else if(user->getAtt_experience() == 3) {
        expString = "Part time";
    } else if(user->getAtt_experience() == 4) {
        expString = "full time";
    }
    ui->workExper->setText(expString);
}

    // ui->techWriting->setText(user->getAtt_);   ??
    // ui->techAndGramm->setText(user->getAtt_);   ??
    // which one does the one below belong to???????
    //int getAtt_writing(); //: int -- self-assessed technical writing skill and grammar (can be made objective)



QString StudentWindow::codingString(int num)
{
    QString text;
    if (num == 0) {
        text = "F or N/A";
    } else if(num == 1) {
        text = "D- to D+";
    } else if(num == 2) {
        text = "C- to C+";
    } else if(num == 3) {
        text = "B- to B+";
    } else if(num == 4) {
        text = "A- to A+";
    }
    return text;
}

QString StudentWindow::experienceString(int num)
{
    QString text;
    if (num == 0) {
        text = "None";
    } else if(num == 1) {
        text = "Academic only";
    } else if(num == 2) {
        text = "Academic and personal projects";
    } else if(num == 3) {
        text = "Co-op or summer employment";
    } else if(num == 4) {
        text = "Professional";
    }
    return text;
}

QString StudentWindow::agreeString(int num)
{
    QString text;
    if (num == 0) {
        text = "Strongly Disagree";
    } else if(num == 1) {
        text = "Disagree";
    } else if(num == 2) {
        text = "Neutral";
    } else if(num == 3) {
        text = "Agree";
    } else if(num == 4) {
        text = "Strongly Agree";
    }
    return text;
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

        //this->~StudentWindow();
    } else{
        ui->status->setText("Cannot set names to blank.");
    }
}



