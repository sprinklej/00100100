#include "qualificationwindow.h"
#include "ui_qualificationwindow.h"
#include "Storage.h"
#include <QDebug>

QualificationWindow::QualificationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QualificationWindow)
{
    ui->setupUi(this);
}

QualificationWindow::~QualificationWindow()
{
    delete ui;
}

void QualificationWindow::setStudent(Student* st){
    student = st;
}

/*
void QualificationWindow::on_pushButton_ok_clicked()
{
    // get info

    //if no errors write to storage

    //close window
    delete student;
    this->~QualificationWindow();
}

void QualificationWindow::on_pushButton_cancel_clicked()
{
    delete student;
    this->~QualificationWindow();
}
*/


//OK
void QualificationWindow::on_pushButton_2_clicked()
{
    // get info

    //want to be a leader?
    bool att_lead = (ui->checkBox->isChecked());

    //build the availability string
    QString avail = QString("");
    if(ui->checkBox_2->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_3->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_4->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_5->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_6->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_7->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_8->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_9->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_10->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_11->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_12->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_13->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_14->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_15->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_16->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_17->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_18->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_19->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_20->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_21->isChecked()){avail.append("T");}else{avail.append("F");}
    if(ui->checkBox_22->isChecked()){avail.append("T");}else{avail.append("F");}

    //radio button qualifications
    int att_2404 = 0;
    if(ui->rb2404_1->isChecked()) att_2404 = 1;
    else if(ui->rb2404_2->isChecked()) att_2404 = 2;
    else if(ui->rb2404_3->isChecked()) att_2404 = 3;
    else if(ui->rb2404_4->isChecked()) att_2404 = 4;

    int att_3005 = 0;
    if(ui->rb3005_1->isChecked()) att_3005 = 1;
    else if(ui->rb3005_2->isChecked()) att_3005 = 2;
    else if(ui->rb3005_3->isChecked()) att_3005 = 3;
    else if(ui->rb3005_4->isChecked()) att_3005 = 4;

    int att_alg = 0;
    if(ui->rbalg_1->isChecked()) att_alg = 1;
    else if(ui->rbalg_2->isChecked()) att_alg = 2;
    else if(ui->rbalg_3->isChecked()) att_alg = 3;
    else if(ui->rbalg_4->isChecked()) att_alg = 4;

    int att_coding = 0;
    if(ui->rbcoding_1->isChecked()) att_coding = 1;
    else if(ui->rbcoding_2->isChecked()) att_coding = 2;
    else if(ui->rbcoding_3->isChecked()) att_coding = 3;
    else if(ui->rbcoding_4->isChecked()) att_coding = 4;


    int att_comm = 0;
    if(ui->rbcomm_1->isChecked()) att_comm = 1;
    else if(ui->rbcomm_2->isChecked()) att_comm = 2;
    else if(ui->rbcomm_3->isChecked()) att_comm = 3;
    else if(ui->rbcomm_4->isChecked()) att_comm = 4;

    int att_cre = 0;
    if(ui->rbcre_1->isChecked()) att_cre = 1;
    else if(ui->rbcre_2->isChecked()) att_cre = 2;
    else if(ui->rbcre_3->isChecked()) att_cre = 3;
    else if(ui->rbcre_4->isChecked()) att_cre = 4;

    int att_cri = 0;
    if(ui->rbcri_1->isChecked()) att_cri = 1;
    else if(ui->rbcri_2->isChecked()) att_cri = 2;
    else if(ui->rbcri_3->isChecked()) att_cri = 3;
    else if(ui->rbcri_4->isChecked()) att_cri = 4;

    int att_dbase = 0;
    if(ui->rbdbase_1->isChecked()) att_dbase = 1;
    else if(ui->rbdbase_2->isChecked()) att_dbase = 2;
    else if(ui->rbdbase_3->isChecked()) att_dbase = 3;
    else if(ui->rbdbase_4->isChecked()) att_dbase = 4;

    int att_pres = 0;
    if(ui->rbpres_1->isChecked()) att_pres = 1;
    else if(ui->rbpres_2->isChecked()) att_pres = 2;
    else if(ui->rbpres_3->isChecked()) att_pres = 3;
    else if(ui->rbpres_4->isChecked()) att_pres = 4;

    int att_rel = 0;
    if(ui->rbrel_1->isChecked()) att_rel = 1;
    else if(ui->rbrel_2->isChecked()) att_rel = 2;
    else if(ui->rbrel_3->isChecked()) att_rel = 3;
    else if(ui->rbrel_4->isChecked()) att_rel = 4;

    int att_req = 0;
    if(ui->rbreq_1->isChecked()) att_req = 1;
    else if(ui->rbreq_2->isChecked()) att_req = 2;
    else if(ui->rbreq_3->isChecked()) att_req = 3;
    else if(ui->rbreq_4->isChecked()) att_req = 4;

    int att_res = 0;
    if(ui->rbres_1->isChecked()) att_res = 1;
    else if(ui->rbres_2->isChecked()) att_res = 2;
    else if(ui->rbres_3->isChecked()) att_res = 3;
    else if(ui->rbres_4->isChecked()) att_res = 4;


    int att_sd = 0;
    if(ui->rbsd_1->isChecked()) att_sd = 1;
    else if(ui->rbsd_2->isChecked()) att_sd = 2;
    else if(ui->rbsd_3->isChecked()) att_sd = 3;
    else if(ui->rbsd_4->isChecked()) att_sd = 4;

    int att_team = 0;
    if(ui->rbteam_1->isChecked()) att_team = 1;
    else if(ui->rbteam_2->isChecked()) att_team = 2;
    else if(ui->rbteam_3->isChecked()) att_team = 3;
    else if(ui->rbteam_4->isChecked()) att_team = 4;

    int att_test = 0;
    if(ui->rbtest_1->isChecked()) att_test = 1;
    else if(ui->rbtest_2->isChecked()) att_test = 2;
    else if(ui->rbtest_3->isChecked()) att_test = 3;
    else if(ui->rbtest_4->isChecked()) att_test = 4;

    int att_ui = 0;
    if(ui->rbui_1->isChecked()) att_ui = 1;
    else if(ui->rbui_2->isChecked()) att_ui = 2;
    else if(ui->rbui_3->isChecked()) att_ui = 3;
    else if(ui->rbui_4->isChecked()) att_ui = 4;

    int att_uml = 0;
    if(ui->rbuml_1->isChecked()) att_uml = 1;
    else if(ui->rbuml_2->isChecked()) att_uml = 2;
    else if(ui->rbuml_3->isChecked()) att_uml= 3;
    else if(ui->rbuml_4->isChecked()) att_uml = 4;

    int att_wg = 0;
    if(ui->rbwg_1->isChecked()) att_wg = 1;
    else if(ui->rbwg_2->isChecked()) att_wg = 2;
    else if(ui->rbrg_3->isChecked()) att_wg = 3;
    else if(ui->rbwg_4->isChecked()) att_wg = 4;

    int att_writing = 0;
    if(ui->rbwriting_1->isChecked()) att_writing = 1;
    else if(ui->rbwriting_2->isChecked()) att_writing = 2;
    else if(ui->rbwriting_3->isChecked()) att_writing = 3;
    else if(ui->rbwriting_4->isChecked()) att_writing = 4;

    int att_xp = 0;
    if(ui->rbxp_1->isChecked()) att_xp = 1;
    else if(ui->rbxp_2->isChecked()) att_xp = 2;
    else if(ui->rbxp_3->isChecked()) att_xp = 3;
    else if(ui->rbxp_4->isChecked()) att_xp = 4;

    int rq2404 = ui->sli2404->value();
    int req3005 = ui->sli3005->value();
    int reqalg = ui->slialg->value();
    int reqcomm = ui->slicomm->value();
    int reqcpp = ui->slicpp->value();
    int reqcre = ui->slicre->value();
    int reqcri = ui->slicri->value();
    int reqdb = ui->slidb->value();
    int reqpres = ui->slipres->value();
    int reqrel = ui->slirel->value();
    int reqreq = ui->slireq->value();
    int reqresp = ui->sliresp->value();
    int reqsd = ui->slisd->value();
    int reqtest = ui->slitest->value();
    int reqtw = ui->slitw->value(); // tech writing
    int reqtw2 = ui->slitw_2->value(); // teamwork
    int requi = ui->sliui->value();
    int requml = ui->sliuml->value();
    int reqxp = ui->slixp->value();

    student->setAtt_leader(att_lead);
    student->setAtt_avail(avail);
    student->setAtt_2404(att_2404);
    student->setAtt_3005(att_3005);
    student->setAtt_coding(att_coding);
    student->setAtt_dbase(att_dbase);
    student->setAtt_selfDir(att_sd);
    student->setAtt_writing(att_writing);
    student->setAtt_UI(att_ui);
    student->setAtt_algorithm(att_alg);
    student->setAtt_present(att_pres);
    student->setAtt_teamwork(att_team);
    student->setAtt_experience(att_xp);
    student->setAtt_testing(att_test);
    student->setAtt_UML(att_uml);
    student->setAtt_req(att_req);
    student->setAtt_reliable(att_rel);
    student->setAtt_comm(att_comm);
    student->setAtt_respect(att_res);
    student->setAtt_creative(att_cre);
    student->setAtt_critic(att_cri);
    student->setReq_leader(!att_lead);
    student->setReq_2404(rq2404);
    student->setReq_3005(req3005);
    student->setReq_coding(reqcpp);
    student->setReq_dbase(reqdb);
    student->setReq_selfDir(reqsd);
    student->setReq_writing(reqtw);
    student->setReq_UI(requi);
    student->setReq_algorithm(reqalg);
    student->setReq_present(reqpres);
    student->setReq_teamwork(reqtw2);
    student->setReq_experience(reqxp);
    student->setReq_testing(reqtest);
    student->setReq_UML(requml);
    student->setReq_req(reqreq);
    student->setReq_reliable(reqrel);
    student->setReq_comm(reqcomm);
    student->setReq_respect(reqresp);
    student->setReq_creative(reqcre);
    student->setReq_critic(reqcri);

    qDebug() << student->toString();

    //if no errors write to storage
/**************************
 * TBD: check for errors
 **************************/
    Storage::getDB().addUser(student);

    /*Student* testStudent = new Student("z", "z", "100111111", 0, "FFF", 1,
                                                1, 1,1,1,1,1,1,1,
                                                1,1,1,1,1,1,1,1,
                                                1,1,1,1,1,1,1,
                                                1,1,1,1,1,1,1,
                                                1,1,1,1,1,1,
                                                1,1);
    Storage::getDB().addUser(testStudent);*/

    //close window
    delete student;
    this->~QualificationWindow();
}

//CANCEL
void QualificationWindow::on_pushButton_clicked()
{
    delete student;
    this->~QualificationWindow();
}
