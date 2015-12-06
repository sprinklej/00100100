#include "PPIDManager.h"
#include "manageadmincontrol.h"
#include "QDebug"

/******
 * Note: All sorts are implemented as insertion sort
 * It's straightforward to implement, and quadratic time is not
 * a realstic concern given size of collections
 ******/
PPIDManager::PPIDManager(QList<Student*>& stIn, Project* p, ManageAdminControl* mac){

    manAdminCon = mac;

    students = new QList<Student*>(); // need a new one - PPID destroys the list
    Student* s;
    teams = new QList<Team*>();

    //instead of sorting on leader, we will save time by constructing the list in leader sorted order.
    foreach(s,stIn){
        //push to the front if empty
        if(students->isEmpty()){
            students->push_front(s);
        }else if(s->getAtt_leader()){ //the student wants to be a leader
            for(int i = 0; i<students->size(); ++i){
                //if the next student does not want to be a leader, insert
                if(!students->at(i)->getAtt_leader()){
                    students->insert(i, s);
                    break;
                } else if(compStudentsOnLeader(s, students->at(i))){
                    if(i == 0) students->push_front(s);
                    else students->insert(i, s);
                    break;
                }
            }
        }else{ //student does not want to be a leader
            for(int i = students->size()-1; i >= 0; --i){
                //if the previous student wants to be a leader, insert behind
                if(students->at(i)->getAtt_leader()){
                    students->insert(i+1,s);
                    break;
                } else if(!compStudentsOnLeader(s, students->at(i))){ //else if a better leader, inseert ahead
                    students->insert(i+1, s);
                    break;
                }
            }
        }

    }
    project = p;
    averages = QHash<QString, float>();
    calculateAverages();

    numTeams = students->size() / p->getTeamSize();

    qDebug() << "PPID is starting \n" << numTeams << " teams";

    manAdminCon->setStatus("PPID is starting!");

}


void PPIDManager::runAlgorithm(){

    qDebug() << "Running algorithm";

    ////// TODO - not enough teams
    /*if(numTeams < 4){
        //give an error dialog
        return;
    }*/

    ////// TODO - teams of 2
    /*if(teamsize == 2){
        //run alternative PPID
        return;
    }*/

    //create the teams
    //Note: students arrives pre-sorted on leader
   for(int i = 0; i < numTeams; ++i){
        Team* t = new Team();
        Student* s = students->takeFirst();
        t->addStudent(s);
        teams->push_back(t);
   }

    //Sort the teams from highest to lowest variance
    QList<Team*>* sortedTeams = new QList<Team*>();
    foreach(Team* t, *teams){
        if(sortedTeams->isEmpty()){
            sortedTeams->push_front(t);
        } else if(!compTeamsOnVariance(t, sortedTeams->at(sortedTeams->size()-1), averages)){
            sortedTeams->push_back(t);
        } else{
            for(int i=0; i < sortedTeams->size(); ++i){
                if(compTeamsOnVariance(t, sortedTeams->at(i), averages)){
                    sortedTeams->insert(i, t);
                    break;
                }
            }
        }
    }

    teams->clear();
    foreach(Team*t, *sortedTeams){
        teams->push_back(t);
    }

    // Assign coders
    getCoders();

    // Assign writers
    getWriters();

    while(students->size() >= (teams->size())*3){
        getLeaders();
        getCoders();
        getWriters();
    }

    while(students->size() >= teams->size()){
        getAnyone();
    }

    getAnyone();

   qDebug() << "** PPID DEBUG ********";
   Student* ds;
   Team* dt;
   foreach(dt, *teams){
    qDebug() << "--Team --   Variance: " << dt->getQualVariance(averages);
    QList<Student*> studs = dt->getStudents();
        foreach(ds, studs){
            qDebug() << ds->getFirstName() << "  Leader score: " << ds->getLeaderScore() << " Coder score: " << ds->getCoderScore() << " Writer score: " << ds->getWriterScore();
        }
   }


   return;
}

void PPIDManager::getLeaders(){
    ////////// Assign a leader

    QList<Student*>* sortedStudents = new QList<Student*>();

    foreach(Student* ss, *students){
        if(sortedStudents->isEmpty()){
            sortedStudents->push_front(ss);
        } else if(!compStudentsOnLeader(ss, sortedStudents->at(sortedStudents->size()-1))){
            sortedStudents->push_back(ss);
        } else{
            for(int i=0; i < sortedStudents->size(); ++i){
                if(compStudentsOnLeader(ss, sortedStudents->at(i))){
                    sortedStudents->insert(i, ss);
                    break;
                }
            }
        }
    }

    students->clear();
    foreach(Student* s, *sortedStudents){
        students->push_back(s);
    }

    //Have to reverse the list
    for(int i = 0; i < (teams->size()/2); i++) teams->swap(i,teams->size()-(1+i));

    //Now assign the best fit coder to each team
    foreach(Team* t, *teams){
        float bestmatch = 0.0;
        Student* bestStudent = students->at(0);
        int bsIndex = 0;

        for(int i = 0; i < teams->size() && i < students->size(); ++i){ //not a mistake - we only want to assign the best coders right now
            float m = t->match(students->at(i), averages);
            if(m > bestmatch){
                bestmatch = m;
                bestStudent = students->at(i);
                bsIndex = i;
            }
        }
        t->addStudent(bestStudent);
        students->removeAt(bsIndex);
    }

    qDebug() << "coders assigned";
}

void PPIDManager::getCoders(){
    ////////// Assign a coder


    QList<Student*>* sortedStudents = new QList<Student*>();

    foreach(Student* ss, *students){
        if(sortedStudents->isEmpty()){
            sortedStudents->push_front(ss);
        } else if(!compStudentsOnCoding(ss, sortedStudents->at(sortedStudents->size()-1))){
            sortedStudents->push_back(ss);
        } else{
            for(int i=0; i < sortedStudents->size(); ++i){
                if(compStudentsOnCoding(ss, sortedStudents->at(i))){
                    sortedStudents->insert(i, ss);
                    break;
                }
            }
        }
    }

    students->clear();
    foreach(Student* s, *sortedStudents){
        students->push_back(s);
    }

    //Have to reverse the list
    for(int i = 0; i < (teams->size()/2); i++) teams->swap(i,teams->size()-(1+i));

    //Now assign the best fit coder to each team
    foreach(Team* t, *teams){
        float bestmatch = 0.0;
        Student* bestStudent = students->at(0);
        int bsIndex = 0;

        for(int i = 0; i < teams->size() && i < students->size(); ++i){ //not a mistake - we only want to assign the best coders right now
            float m = t->match(students->at(i), averages);
            if(m > bestmatch){
                bestmatch = m;
                bestStudent = students->at(i);
                bsIndex = i;
            }
        }
        t->addStudent(bestStudent);
        students->removeAt(bsIndex);
    }

    qDebug() << "coders assigned";
}

void PPIDManager::getWriters(){
    ////////// Addign a writer

    //7.  Sort students on writer score

   QList<Student*>* sortedStudents = new QList<Student*>();

    foreach(Student* ss, *students){
        if(sortedStudents->isEmpty()){
            sortedStudents->push_front(ss);
        } else if(!compStudentsOnWriting(ss, sortedStudents->at(sortedStudents->size()-1))){
            sortedStudents->push_back(ss);
        } else{
            for(int i=0; i < sortedStudents->size(); ++i){
                if(compStudentsOnWriting(ss, sortedStudents->at(i))){
                    sortedStudents->insert(i, ss);
                    break;
                }
            }
        }
    }

    students->clear();
    foreach(Student* s, *sortedStudents){
        students->push_back(s);
    }

    //sort the teams on variance
    //6a. Sort the teams from highest to lowest variance
    QList<Team*>* sortedTeams = new QList<Team*>();
    foreach(Team* t, *teams){
        if(sortedTeams->isEmpty()){
            sortedTeams->push_front(t);
        } else if(!compTeamsOnVariance(t, sortedTeams->at(sortedTeams->size()-1), averages)){
            sortedTeams->push_back(t);
        } else{
            for(int i=0; i < sortedTeams->size(); ++i){
                if(compTeamsOnVariance(t, sortedTeams->at(i), averages)){
                    sortedTeams->insert(i, t);
                    break;
                }
            }
        }
    }

    teams->clear();
    foreach(Team*t, *sortedTeams){
        teams->push_back(t);
    }

    //Have to reverse the list
    for(int i = 0; i < (teams->size()/2); i++) teams->swap(i,teams->size()-(1+i));



    //Now assign the best fit writer to each team
    foreach(Team* t, *teams){
        float bestmatch = 0.0;
        if(students->isEmpty()) break;
        Student* bestStudent = students->at(0);
        int bsIndex = 0;

        for(int i = 0; i < teams->size() && i < students->size(); ++i){ //not a mistake - we only want to assign the best writers right now
            float m = t->match(students->at(i), averages);
            if(m > bestmatch){
                bestmatch = m;
                bestStudent = students->at(i);
                bsIndex = i;
            }
        }
        t->addStudent(bestStudent);
        students->removeAt(bsIndex);
    }

    qDebug() << "writers assigned";
}
void PPIDManager::getAnyone(){
    ////////// Addign a writer

    //7.  Sort students on total score

   QList<Student*>* sortedStudents = new QList<Student*>();

    foreach(Student* ss, *students){
        if(sortedStudents->isEmpty()){
            sortedStudents->push_front(ss);
        } else if(!compStudentsOverall(ss, sortedStudents->at(sortedStudents->size()-1))){
            sortedStudents->push_back(ss);
        } else{
            for(int i=0; i < sortedStudents->size(); ++i){
                if(compStudentsOverall(ss, sortedStudents->at(i))){
                    sortedStudents->insert(i, ss);
                    break;
                }
            }
        }
    }

    students->clear();
    foreach(Student* s, *sortedStudents){
        students->push_back(s);
    }

    //sort the teams on variance
    //6a. Sort the teams from highest to lowest variance
    QList<Team*>* sortedTeams = new QList<Team*>();
    foreach(Team* t, *teams){
        if(sortedTeams->isEmpty()){
            sortedTeams->push_front(t);
        } else if(!compTeamsOnVariance(t, sortedTeams->at(sortedTeams->size()-1), averages)){
            sortedTeams->push_back(t);
        } else{
            for(int i=0; i < sortedTeams->size(); ++i){
                if(compTeamsOnVariance(t, sortedTeams->at(i), averages)){
                    sortedTeams->insert(i, t);
                    break;
                }
            }
        }
    }

    teams->clear();
    foreach(Team*t, *sortedTeams){
        teams->push_back(t);
    }

    //Have to reverse the list
    for(int i = 0; i < (teams->size()/2); i++) teams->swap(i,teams->size()-(1+i));

    //Now assign the best fit to each team
    foreach(Team* t, *teams){
        float bestmatch = 0.0;
        if(students->isEmpty()) break;
        Student* bestStudent = students->at(0);
        int bsIndex = 0;

        for(int i = 0; i < students->size(); ++i){
            float m = t->match(students->at(i), averages);
            if(m > bestmatch){
                bestmatch = m;
                bestStudent = students->at(i);
                bsIndex = i;
            }
        }
        t->addStudent(bestStudent);
        students->removeAt(bsIndex);
    }

    qDebug() << "leftovers assigned";

}



void PPIDManager::calculateAverages(){
    float att_2404 = 0;
    float att_3005 = 0;
    float att_coding = 0;
    float att_dbase = 0;
    float att_selfDir = 0;
    float att_writing = 0;
    float att_UI = 0;
    float att_algorithm = 0;
    float att_present = 0;
    float att_teamwork = 0;
    float att_experience = 0;
    float att_testing = 0;
    float att_UML = 0;
    float att_req = 0;
    float att_reliable = 0;
    float att_comm = 0;
    float att_respect = 0;
    float att_creative = 0;
    float att_critic = 0;
    float req_leader = 0;
    float req_2404 = 0;
    float req_3005 = 0;
    float req_coding = 0;
    float req_dbase = 0;
    float req_selfDir = 0;
    float req_writing = 0;
    float req_UI = 0;
    float req_algorithm = 0;
    float req_present = 0;
    float req_teamwork = 0;
    float req_experience = 0;
    float req_testing = 0;
    float req_UML = 0;
    float req_req = 0;
    float req_reliable = 0;
    float req_comm = 0;
    float req_respect = 0;
    float req_creative = 0;
    float req_critic  = 0;

    Student* s;
    foreach(s, *students){
        att_2404 += s->getAtt_2404();
        att_3005 += s->getAtt_3005();
        att_coding += s->getAtt_coding();
        att_dbase += s->getAtt_dbase();
        att_selfDir += s->getAtt_selfDir();
        att_writing += s->getAtt_writing();
        att_UI += s->getAtt_UI();
        att_algorithm += s->getAtt_algorithm();
        att_present += s->getAtt_present();
        att_teamwork += s->getAtt_teamwork();
        att_experience += s->getAtt_experience();
        att_testing += s->getAtt_testing();
        att_UML += s->getAtt_UML();
        att_req += s->getAtt_req();
        att_reliable += s->getAtt_reliable();
        att_comm += s->getAtt_comm();
        att_respect += s->getAtt_respect();
        att_creative += s->getAtt_creative();
        att_critic += s->getAtt_critic();
        req_leader += s->getReq_leader();
        req_2404 += s->getReq_2404();
        req_3005 += s->getReq_3005();
        req_coding += s->getReq_coding();
        req_dbase += s->getReq_dbase();
        req_selfDir += s->getReq_selfDir();
        req_writing += s->getReq_writing();
        req_UI += s->getReq_UI();
        req_algorithm += s->getReq_algorithm();
        req_present += s->getReq_present();
        req_teamwork += s->getReq_teamwork();
        req_experience += s->getReq_experience();
        req_testing += s->getReq_testing();
        req_UML += s->getReq_UML();
        req_req += s->getReq_req();
        req_reliable += s->getReq_reliable();
        req_comm += s->getReq_comm();
        req_respect += s->getReq_respect();
        req_creative += s->getReq_creative();
        req_critic  += s->getReq_critic();
    }

    att_2404 /= students->size();
    att_3005 /= students->size();
    att_coding /= students->size();
    att_dbase /= students->size();
    att_selfDir /= students->size();
    att_writing /= students->size();
    att_UI /= students->size();
    att_algorithm /= students->size();
    att_present /= students->size();
    att_teamwork /= students->size();
    att_experience /= students->size();
    att_testing /= students->size();
    att_UML /= students->size();
    att_req /= students->size();
    att_reliable /= students->size();
    att_comm /= students->size();
    att_respect /= students->size();
    att_creative /= students->size();
    att_critic /= students->size();
    req_leader /= students->size();
    req_2404 /= students->size();
    req_3005 /= students->size();
    req_coding /= students->size();
    req_dbase /= students->size();
    req_selfDir /= students->size();
    req_writing /= students->size();
    req_UI /= students->size();
    req_algorithm /= students->size();
    req_present /= students->size();
    req_teamwork /= students->size();
    req_experience /= students->size();
    req_testing /= students->size();
    req_UML /= students->size();
    req_req /= students->size();
    req_reliable /= students->size();
    req_comm /= students->size();
    req_respect /= students->size();
    req_creative /= students->size();
    req_critic  /= students->size();

    averages["att_2404"] = att_2404;
    averages["att_3005"] =  att_3005;
    averages["att_coding"] = att_coding;
    averages["att_dbase"] = att_dbase;
    averages["att_selfDir"] = att_selfDir;
    averages["att_writing"] = att_writing;
    averages["att_UI"] = att_UI;
    averages["att_algorithm"] = att_algorithm;
    averages["att_present"] = att_present;
    averages["att_teamwork"] = att_teamwork;
    averages["att_experience"] = att_experience;
    averages["att_testing"] = att_testing;
    averages["att_UML"] = att_UML;
    averages["att_req"] = att_req;
    averages["att_reliable"] = att_reliable;
    averages["att_comm"] = att_comm;
    averages["att_respect"] = att_respect;
    averages["att_creative"] = att_creative;
    averages["att_critic"] = att_critic;
    averages["req_leader"] = req_leader;
    averages["req_2404"] = req_2404;
    averages["req_3005"] = req_3005;
    averages["req_coding"] = req_coding;
    averages["req_dbase"] = req_dbase;
    averages["req_selfDir"] = req_selfDir;
    averages["req_writing"] = req_writing;
    averages["req_UI"] = req_UI;
    averages["req_algorithm"] = req_algorithm;
    averages["req_present"] = req_present;
    averages["req_teamwork"] = req_teamwork;
    averages["req_experience"] = req_experience;
    averages["req_testing"] = req_testing;
    averages["req_UML"] = req_UML;
    averages["req_req"] = req_req;
    averages["req_reliable"] = req_reliable;
    averages["req_comm"] = req_comm;
    averages["req_respect"] = req_respect;
    averages["req_creative"] = req_creative;
    averages["req_critic"] =  req_critic;

}

void PPIDManager::displayReports(){
    QString sumReport = printSummaryReport();
    QString detReport = printDetailedReport();
    PPIDResultsWindow* ppidResWin = new PPIDResultsWindow();
    ppidResWin->setResults(sumReport, detReport);

    // opens new window and disables current window
    ppidResWin->setModal(true);
    ppidResWin->exec();
    //ppidResWin->show();
}


/*
PPID SUMMARY REPORT
Project:
  Class:
..................................................................................
Team n:
  Leader - Student Name ......... 100234512
   Coder - Student Name ......... 100674556
  Writer - Student Name ......... 100345234
   Other - Student Name ......... 100345233
..................................................................................
*/
QString PPIDManager::printSummaryReport(){
    QString sumString = "";
    sumString = "PPID SUMMARY REPORT\n";
    sumString = sumString + "Project: " + project->getProjectTitle() + "\n";
    sumString = sumString + "Class: " + project->getCourseNum() + " " + project->getPDescription() + "\n";

    int tCntr = 1;
    int sCntr;
    Team* t;
    Student* s;
    QString temp;
    foreach(t, *teams){
        sCntr = 0;
        temp = QString::number(tCntr);
        sumString = sumString + "..................................................................................\n";
        sumString = sumString + "Team: " + temp + "\n";
        tCntr++;

        foreach(s, t->getStudents()){
            if(sCntr == 0) {
                sumString = sumString + "  Leader\t";
            } else if (sCntr == 1){
                sumString = sumString + "  Coder\t";
            } else if (sCntr == 2){
                sumString = sumString + "  Writer\t";
            } else if (sCntr >= 3){
                sumString = sumString + "  Member\t";
            }

            // figure out how many tabs to use
            temp = s->getFirstName() + " " + s->getLastName();
            if (temp.length() < 12) {
                temp = "\t\t";
            } else {
                temp = "\t";
            }

            sumString = sumString + s->getFirstName() + " " + s->getLastName();
            sumString = sumString + temp + s->getIDNum() + "\n";
            sCntr++;
        }
    }

    sumString = sumString + "..................................................................................\n";
    return sumString;
}



//The purpose of this function is to determine the variance of two teams'
//qualifications vs. the average of the population, then funding the sum
//over all qualifications.
//It will identify either a large negative difference or a large positive difference as being undesirable
//This is done by squaring the difference.
//For example, Team1Q1 = 3.1 Q1classAvg = 2.5 T1Q2 = 0.3 Q2CAvg = 1.6
// = (3.1 - 2.5)^2 + (0.3-1.6)^2
//This accomplishes two things:
//  - It provides an absolute value
//  - It prioritizes large differences
//For this last reason, it is preferred to a stright up absolute value
QString PPIDManager::printDetailedReport(){
    QString detString = "";
    detString = "PPID DETAILED REPORT\n";
    detString = detString + "Project: " + project->getProjectTitle() + "\n";
    detString = detString + "Class: " + project->getCourseNum() + " "+ project->getPDescription() + "\n";

    int tCntr = 1;
    QString num;
    Team* t;
    QString temp;
    foreach(t, *teams){
        num = QString::number(tCntr);
        detString = detString + "..................................................................................\n";
        detString= detString + "Team: " + num + "\n";
        temp = QString::number(t->getQualVariance(averages));
        detString= detString + "Qual Variance:\t" + temp +"\n";
        temp = QString::number(t->getLFVariance());
        detString= detString + "Looking For Variance:\t" + temp +"\n";
        temp = QString::number(t->getScheduleMatch());
        detString= detString + "Schedule Match:\t" + temp +"\n";

        //Q1 = 3.1 Q1classAvg = 2.5 T1Q2 = 0.3 Q2CAvg = 1.6
        // = (3.1 - 2.5)^2 + (0.3-1.6)^2

        tCntr++;
    }

    detString = detString + "..................................................................................\n";
    return detString;
}
bool PPIDManager::compTeamsOnVariance(Team* t1, Team* t2, QHash<QString, float>& avgs){
    return(t1->getQualVariance(avgs) <= t2->getQualVariance(avgs));
}


bool PPIDManager::compTeamsOnLookingForVariance(Team* t1, Team* t2){
    //return(t1->getLFQualVariance() <= t2->getLFQualVariance());
}


//These functions will check if s1 <= s2 and are used by the sort algorithm
bool PPIDManager::compStudentsOnLeader(Student* s1, Student* s2){
    return(s1->getLeaderScore() >= s2->getLeaderScore());
}

bool PPIDManager::compStudentsOnCoding(Student* s1, Student* s2){
    return(s1->getCoderScore() >= s2->getCoderScore());
}

bool PPIDManager::compStudentsOnWriting(Student* s1, Student* s2){
    return(s1->getWriterScore() >= s2->getWriterScore());
}

bool PPIDManager::compStudentsOverall(Student* s1, Student* s2){
    return(s1->getOverallScore() >= s2->getOverallScore());
}



void PPIDManager::sortStudentsOnLeader(){}
void PPIDManager::sortStudentsOnCoder(){}
void PPIDManager::sortStudentsOnWriter(){}
void PPIDManager::sortStudentsOverall(){}

void PPIDManager::sortTeamsOnVariance(){
    //6a. Sort the teams from highest to lowest variance
    QList<Team*>* sortedTeams = new QList<Team*>();
    foreach(Team* t, *teams){
        if(sortedTeams->isEmpty()){
            sortedTeams->push_front(t);
        } else if(!compTeamsOnVariance(t, sortedTeams->at(sortedTeams->size()-1),averages)){
            sortedTeams->push_back(t);
        } else{
            for(int i=0; i < sortedTeams->size(); ++i){
                if(compTeamsOnVariance(t, sortedTeams->at(i),averages)){
                    sortedTeams->insert(i, t);
                    break;
                }
            }
        }
    }
    delete teams;
    teams = sortedTeams;
}

float PPIDManager::match(Team* team, Student* stud){
    float ret = team->match(stud, averages);
    return ret;
}


