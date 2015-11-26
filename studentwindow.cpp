#include "studentwindow.h"
#include "ui_studentwindow.h"
//#include "Storage.h"
//#include "qualificationwindow.h"
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



/* --------------------------- setters ------------------------*/
void StudentWindow::setStudent(Student* s)
{
    user = s;
}

void StudentWindow::setManStudContrl(ManageStudentControl* msc)
{
    manStudControl = msc;
}



/* --------------------------- update GUI elements ------------------------*/
/* ------------ Project Tab ------------*/
void StudentWindow::setStatus2(QString string)
{
    ui->status2->setText(string);
    return;
}

void StudentWindow::setAllProjListWidget(QString string)
{
    ui->allProjlistWidget->addItem(string);
    return;
}

void StudentWindow::setJoinedProjListWidget(QString string)
{
    ui->joinedProjlistWidget->addItem(string);
    return;
}


/* ------------ Profile Tab ------------*/
// show all the students info
// This function looks big but there is no "work" being done
// all it is doing is displaying variables to the user
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

    // ui->techWriting->setText(user->getAtt_);   ??
    // ui->techAndGramm->setText(user->getAtt_);   ??
    // which one does the one below belong to???????
    // int getAtt_writing(); // int -- self-assessed technical writing skill and grammar (can be made objective)
}

/* -------- helper functions --------*/
// Just format variables
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



/* --------------------------- Project Tab ------------------------*/
// refresh projects
void StudentWindow::refresh(){
    manStudControl->refresh();
}


//join project
void StudentWindow::on_pushButton_joinProject_clicked()
{
    if (ui->allProjlistWidget->currentItem() != NULL){ // if it is NULL then no item is selected yet
        manStudControl->joinProject(ui->allProjlistWidget->currentItem()->text());
    }
}



/* --------------------------- Profile Tab ------------------------*/
//manage qualifications clicked
void StudentWindow::on_pushButton_manQual_clicked()
{

    manStudControl->manageQualifications();
}



/* --------------------------- logout ------------------------*/
void StudentWindow::on_pushButton_Logout1_clicked()
{
    manStudControl->logout();
}

void StudentWindow::on_pushButton_Logout2_clicked()
{
    manStudControl->logout();
}
