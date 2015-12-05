#include "Team.h"
#include "QDebug"

Team::Team(int project_ID, int team_ID)
{
;
}

Team::Team()
{
;
}

void Team::addStudent(Student* s){
   students.push_back(s);
}

float Team::square(float base){
    return(pow(base,2.0));
}

float Team::getQualVariance(QHash<QString, float>& avgs){
    //temporary summing variables
    float temp_att_2404 = 0;
    float temp_att_3005 = 0;
    float temp_att_coding = 0;
    float temp_att_dbase = 0;
    float temp_att_selfDir = 0;
    float temp_att_writing = 0;
    float temp_att_UI = 0;
    float temp_att_algorithm = 0;
    float temp_att_present = 0;
    float temp_att_teamwork = 0;
    float temp_att_experience = 0;
    float temp_att_testing = 0;
    float temp_att_UML = 0;
    float temp_att_req = 0;
    float temp_att_reliable = 0;
    float temp_att_comm = 0;
    float temp_att_respect = 0;
    float temp_att_creative = 0;
    float temp_att_critic = 0;

    float ret = 0;

    //for each student in team:
    // find the difference between each qaulification and the class average
    // square it
    // add it to the temporary summing variable
    Student* s;
    foreach(s, students){
        temp_att_2404 += square((float)s->getAtt_2404() - (float)avgs["att_2404"]);
        temp_att_3005 += square((float)s->getAtt_3005() - (float)avgs["att_3005"]);
        temp_att_coding += square((float)s->getAtt_coding() - (float)avgs["att_coding"]);
        temp_att_dbase += square((float)s->getAtt_dbase() - (float)avgs["att_dbase"]);
        temp_att_selfDir += square((float)s->getAtt_selfDir() - (float)avgs["att_selfDir"]);
        temp_att_writing += square((float)s->getAtt_writing() - (float)avgs["att_writing"]);
        temp_att_UI += square((float)s->getAtt_UI() - (float)avgs["att_UI"]);
        temp_att_algorithm += square((float)s->getAtt_algorithm() - (float)avgs["att_algorithm"]);
        temp_att_present += square((float)s->getAtt_present() - (float)avgs["att_present"]);
        temp_att_teamwork += square((float)s->getAtt_teamwork() - (float)avgs["att_teamwork"]);
        temp_att_experience += square((float)s->getAtt_experience() - (float)avgs["att_experience"]);
        temp_att_testing += square((float)s->getAtt_testing() - (float)avgs["att_testing"]);
        temp_att_UML += square((float)s->getAtt_UML() - (float)avgs["att_UML"]);
        temp_att_req += square((float)s->getAtt_req() - (float)avgs["att_req"]);
        temp_att_reliable += square((float)s->getAtt_reliable() - (float)avgs["att_reliable"]);
        temp_att_comm += square((float)s->getAtt_comm() - (float)avgs["att_comm"]);
        temp_att_respect += square((float)s->getAtt_respect() - (float)avgs["att_respect"]);
        temp_att_creative += square((float)s->getAtt_creative() - (float)avgs["att_creative"]);
        temp_att_critic += square((float)s->getAtt_critic() - (float)avgs["att_critic"]);
    }

    //divide the summing variables by number of students:
    //this provides a view on how much the team so far deviates from
    //the average value of the population, for each qualification
    temp_att_2404 /= students.size();
    temp_att_3005 /= students.size();
    temp_att_coding /= students.size();
    temp_att_dbase /= students.size();
    temp_att_selfDir /= students.size();
    temp_att_writing /= students.size();
    temp_att_UI /= students.size();
    temp_att_algorithm /= students.size();
    temp_att_present /= students.size();
    temp_att_teamwork /= students.size();
    temp_att_experience /= students.size();
    temp_att_testing /= students.size();
    temp_att_UML /= students.size();
    temp_att_req /= students.size();
    temp_att_reliable /= students.size();
    temp_att_comm /= students.size();
    temp_att_respect /= students.size();
    temp_att_creative /= students.size();
    temp_att_critic /= students.size();

    //finally, return the total of the deviations
    return temp_att_2404 + temp_att_3005 + temp_att_coding + temp_att_dbase + temp_att_selfDir + temp_att_writing + temp_att_UI + temp_att_algorithm + temp_att_present + temp_att_teamwork + temp_att_experience + temp_att_testing + temp_att_UML + temp_att_req + temp_att_reliable + temp_att_comm + temp_att_respect + temp_att_creative + temp_att_critic;

}


//This function is similar to the qualification variance criterion
//Except the calculation is:
// - for each student, square (the student's looking for) - (team average score) for each qualification
float Team::getLFVariance(){

    //temporary summing variables
    float temp_att_2404 = 0;
    float temp_att_3005 = 0;
    float temp_att_coding = 0;
    float temp_att_dbase = 0;
    float temp_att_selfDir = 0;
    float temp_att_writing = 0;
    float temp_att_UI = 0;
    float temp_att_algorithm = 0;
    float temp_att_present = 0;
    float temp_att_teamwork = 0;
    float temp_att_experience = 0;
    float temp_att_testing = 0;
    float temp_att_UML = 0;
    float temp_att_req = 0;
    float temp_att_reliable = 0;
    float temp_att_comm = 0;
    float temp_att_respect = 0;
    float temp_att_creative = 0;
    float temp_att_critic = 0;

    float temp_req_2404 = 0;
    float temp_req_3005 = 0;
    float temp_req_coding = 0;
    float temp_req_dbase = 0;
    float temp_req_selfDir = 0;
    float temp_req_writing = 0;
    float temp_req_UI = 0;
    float temp_req_algorithm = 0;
    float temp_req_present = 0;
    float temp_req_teamwork = 0;
    float temp_req_experience = 0;
    float temp_req_testing = 0;
    float temp_req_UML = 0;
    float temp_req_req = 0;
    float temp_req_reliable = 0;
    float temp_req_comm = 0;
    float temp_req_respect = 0;
    float temp_req_creative = 0;
    float temp_req_critic = 0;

    //first find the mean of all qualifications on the team
    Student* s;
    foreach(s, students){
        temp_att_2404 += s->getAtt_2404();
        temp_att_3005 += s->getAtt_3005();
        temp_att_coding += s->getAtt_coding();
        temp_att_dbase += s->getAtt_dbase();
        temp_att_selfDir += s->getAtt_selfDir();
        temp_att_writing += s->getAtt_writing();
        temp_att_UI += s->getAtt_UI();
        temp_att_algorithm += s->getAtt_algorithm();
        temp_att_present += s->getAtt_present();
        temp_att_teamwork += s->getAtt_teamwork();
        temp_att_experience += s->getAtt_experience();
        temp_att_testing += s->getAtt_testing();
        temp_att_UML += s->getAtt_UML();
        temp_att_req += s->getAtt_req();
        temp_att_reliable += s->getAtt_reliable();
        temp_att_comm += s->getAtt_comm();
        temp_att_respect += s->getAtt_respect();
        temp_att_creative += s->getAtt_creative();
        temp_att_critic += s->getAtt_critic();
    }

    temp_att_2404 /= students.size();
    temp_att_3005 /= students.size();
    temp_att_coding /= students.size();
    temp_att_dbase /= students.size();
    temp_att_selfDir /= students.size();
    temp_att_writing /= students.size();
    temp_att_UI /= students.size();
    temp_att_algorithm /= students.size();
    temp_att_present /= students.size();
    temp_att_teamwork /= students.size();
    temp_att_experience /= students.size();
    temp_att_testing /= students.size();
    temp_att_UML /= students.size();
    temp_att_req /= students.size();
    temp_att_reliable /= students.size();
    temp_att_comm /= students.size();
    temp_att_respect /= students.size();
    temp_att_creative /= students.size();
    temp_att_critic /= students.size();

    //now we find the variance between looking for and average
    foreach(s, students){
        temp_req_2404 += square((float)s->getReq_2404() - (float)temp_att_2404);
        temp_req_3005 += square((float)s->getReq_3005() - (float)temp_att_3005);
        temp_req_coding += square((float)s->getReq_coding() - (float)temp_att_coding);
        temp_req_dbase += square((float)s->getReq_dbase() - (float)temp_att_dbase);
        temp_req_selfDir += square((float)s->getReq_selfDir() - (float)temp_att_selfDir );
        temp_req_writing += square((float)s->getReq_writing() - (float)temp_att_writing);
        temp_req_UI += square((float)s->getReq_UI() - (float)temp_att_UI);
        temp_req_algorithm += square((float)s->getReq_algorithm() - (float)temp_att_algorithm);
        temp_req_present += square((float)s->getReq_present() - (float)temp_att_present);
        temp_req_teamwork += square((float)s->getReq_teamwork() - (float)temp_att_teamwork);
        temp_req_experience += square((float)s->getReq_experience() - (float)temp_att_experience);
        temp_req_testing += square((float)s->getReq_testing() - (float)temp_att_testing);
        temp_req_UML += square((float)s->getReq_UML() - (float)temp_att_UML);
        temp_req_req += square((float)s->getReq_req() - (float)temp_att_req);
        temp_req_reliable += square((float)s->getReq_reliable() - (float)temp_att_reliable);
        temp_req_comm += square((float)s->getReq_comm() - (float)temp_att_comm);
        temp_req_respect += square((float)s->getReq_respect() - (float)temp_att_respect);
        temp_req_creative += square((float)s->getReq_creative() - (float)temp_att_creative);
        temp_req_critic += square((float)s->getReq_critic() - (float)temp_att_critic);
    }

    //now we find the average over the team
    temp_req_2404 /= students.size();
    temp_req_3005 /= students.size();
    temp_req_coding /= students.size();
    temp_req_dbase /= students.size();
    temp_req_selfDir /= students.size();
    temp_req_writing /= students.size();
    temp_req_UI /= students.size();
    temp_req_algorithm /= students.size();
    temp_req_present /= students.size();
    temp_req_teamwork /= students.size();
    temp_req_experience /= students.size();
    temp_req_testing /= students.size();
    temp_req_UML /= students.size();
    temp_req_req /= students.size();
    temp_req_reliable /= students.size();
    temp_req_comm /= students.size();
    temp_req_respect /= students.size();
    temp_req_creative /= students.size();
    temp_req_critic /= students.size();


    //finally, return the total of the deviations
    return temp_req_2404 + temp_req_3005 + temp_req_coding + temp_req_dbase + temp_req_selfDir + temp_req_writing + temp_req_UI + temp_req_algorithm + temp_req_present + temp_req_teamwork + temp_req_experience + temp_req_testing + temp_req_UML + temp_req_req + temp_req_reliable + temp_req_comm + temp_req_respect + temp_req_creative + temp_req_critic;

}

//This is the match that is the trickiest to do.
//We will return the number of time slots where all team members are available, divided by 21
float Team::getScheduleMatch(){
    float tot = 21.0;
    //count from 0 to 20
    for(int i = 0; i < 21; ++i){
        foreach(Student* s, students){
            qDebug() << s->getAtt_avail();
            if(s->getAtt_avail().at(i) == 'F'){
                tot -= 1.0;
                break;
            }
        }
    }
    return tot / 21.0;
}

float Team::match(Student* s, QHash<QString, float>& avgs){
    students.push_back(s);
    qDebug() << "Match: push";
    float ret = 0.0;
    //note: these still need scaling factors
    float i1 = getQualVariance(avgs);
    qDebug() << "Match: qalvar";
    float i2 = getLFVariance();
    qDebug() << "Match: lfvar";
    float i3 = getScheduleMatch();
    qDebug() << "Match: sched";
    //ret += 1/getQualVariance(avgs) + 1/getLFVariance() + getScheduleMatch();
    ret = i1 + i2 + i3;
    qDebug() << "Match: values";
    students.pop_back();
    qDebug() << "Match: pop";
    return ret;
}

QList<Student*>& Team::getStudents(){return students;}
