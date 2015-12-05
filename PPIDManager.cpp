#include "PPIDManager.h"
#include "QDebug"

/******
 * Note: All sorts are implemented as insertion sort
 * It's straightforward to implement, and quadratic time is not
 * a realstic concern given size of collections
 ******/

PPIDManager::PPIDManager(QList<Student*>& stIn, Project* p){
    students = QList<Student*>(); // need a new one - PPID destroys the list
    Student* s;
    teams = new QList<Team*>();
    //instead of sorting on leader, we will construct the list in leader sorted order.
    foreach(s,stIn){
        //push to the front if empty
        if(students.isEmpty()){
            students.push_front(s);
        }else if(s->getAtt_leader()){ //the student wants to be a leader
            for(int i = 0; i<students.size(); ++i){
                //if the next student does not want to be a leader, insert
                if(!students.at(i)->getAtt_leader()){
                    students.insert(i, s);
                    break;
                } else if(compStudentsOnLeader(s, students.at(i))){
                    if(i == 0) students.push_front(s);
                    else students.insert(i, s);
                    break;
                }
            }
        }else{ //student does not want to be a leader
            for(int i = students.size()-1; i >= 0; --i){
                //if the previous student wants to be a leader, insert behind
                if(students.at(i)->getAtt_leader()){
                    students.insert(i+1,s);
                    break;
                } else if(!compStudentsOnLeader(s, students.at(i))){ //else if a better leader, inseert ahead
                    students.insert(i+1, s);
                    break;
                }
            }
        }

    }
    project = p;
    averages = QHash<QString, float>();
    calculateAverages();

    //1. Calculate the number of teams numTeams
    //2. Make a QList<Team*> of Teams
    numTeams = students.size() / p->getTeamSize();

}


//TODO:
//Need to handle cases where number of students < num teams * 3
//TODO:
//Need an exception for when there are too few Students given team size
void PPIDManager::runAlgorithm(){

    /*if(numTeams > students.size() *2){
        //give an error dialog
        return;
    }

    if(numTeams > students.size() *3){
        //run alternative PPID
        return;
    }*/

    // IN CTOR:
    //1. Calculate the number of teams numTeams
    //2. Make a QList<Student*> of Teams
    //3. Sort students on the basis of leaderScore()

    //create the teams
    //Note: students arrives pre-sorted on leader.
   for(int i = 0; i < numTeams; ++i){
        Team* t = new Team();
        Student* s = students.takeFirst();
        t->addStudent(s);
        teams->push_back(t);
   }

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

    delete teams;
    teams = sortedTeams;

    //std::sort(teams.begin(), teams.end(), compTeamsOnVariance);

    //7.  Sort students on coderscore
    //std::sort(students.begin(), students.end(), compStudentsOnCoding);

    //Now assign the best fit coder to each team
    /*8.  For each team in teams:
            let bestmatch = match(team, student(0))
            let beststudent = student(0)

                For student from 0 to numteams
                    if int m = match(team, student(n)) < bestmatch
                    bestmatch = m
                    beststudent = student(n)

                Remove beststudent from students
                push beststudent to team*/

    //need to write the removeAt properly
    /*foreach(t, Teams){
        foreach(s, students){
            int m = match(s, t);
            if(m > bestMatchScore){
                bestMatchScore = m;
                bestStudent = s;
            }
        students.remove(bestStudent);
        t << bestStudent;
        }
    }*/

    /*Two ways to do this:
    9a. Sort the teams from highest to lowest variance
    9b. Sort the teams from weakest to strongest	*/
    //std::sort(teams.begin(), teams.end(), compTeamsOnVariance);

    //10.  Sort students on presenterscore
    //std::sort(students.begin(), students.end(), compStudentsOnWriting);

    /*		let bestmatch = match(team, student(0))
            let beststudent = student(0)
                    For student from 0 to numteams
                    if int m = match(team, student(n)) < bestmatch
                    bestmatch = m
                    beststudent = student(n)

                Remove beststudent from students
                push beststudent to team*/

/*    bestMatchScore = 0;
    bestStudent = students.at(0);

    foreach(t, Teams){
        foreach(s, students){
            int m = match(s, t);
            if(m > bestMatchScore){
                bestMatchScore = m;
                bestStudent = s;
            }
            //students.remove(bestStudent);
            QList<Student*>::iterator it = students.begin();
            while (it != students.end()) {
              if ((*it)==bestStudent)
                it = students.erase(it);
              else
                ++it;
            }

        t->addStudent(bestStudent);
        }
    }

    while(teams->size >= students->size){
    //add more leaders
        std::sort(teams.begin(), teams.end(), compTeamsOnVariance);
        std::sort(students.begin(), students.end(), compStudentsOnLeader);

        bestMatchScore = 0;
        bestStudent = students.at(0);

        foreach(t, Teams){
            foreach(s, students){
                int m = match(s, t);
                if(m > bestMatchScore){
                    bestMatchScore = m;
                    bestStudent = s;
                }
            //students.remove(bestStudent);
                QList<Student*>::iterator it = students.begin();
                while (it != students.end()) {
                  if ((*it)==bestStudent)
                    it = students.erase(it);
                  else
                    ++it;
                }

            t->addStudent(bestStudent);
            }
        }
    //add more coders
        std::sort(teams.begin(), teams.end(), compTeamsOnVariance);
        std::sort(students.begin(), students.end(), compStudentsOnCoder);

        bestMatchScore = 0;
        bestStudent = students.at(0);

        foreach(t, Teams){
            foreach(s, students){
                int m = match(s, t);
                if(m > bestMatchScore){
                    bestMatchScore = m;
                    bestStudent = s;
                }
            //students.remove(bestStudent);
                QList<Student*>::iterator it = students.begin();
                while (it != students.end()) {
                  if ((*it)==bestStudent)
                    it = students.erase(it);
                  else
                    ++it;
                }

            t->addStudent(bestStudent);
            }
        }
    //add more writers
        std::sort(teams.begin(), teams.end(), compTeamsOnVariance);
        std::sort(students.begin(), students.end(), compStudentsOnWriter);

        bestMatchScore = 0;
        bestStudent = students.at(0);

        foreach(t, Teams){
            foreach(s, students){
                int m = match(s, t);
                if(m > bestMatchScore){
                    bestMatchScore = m;
                    bestStudent = s;
                }
            //students.remove(bestStudent);
                QList<Student*>::iterator it = students.begin();
                while (it != students.end()) {
                  if ((*it)==bestStudent)
                    it = students.erase(it);
                  else
                    ++it;
                }

            t->addStudent(bestStudent);
            }
        }

    }

    //assign any leftover students

    while(students.size() > 0){
        std::sort(teams.begin(), teams.end(), compTeamsOnVariance);
            foreach(t, Teams){
            if(students.size() == 0) {return;}
            foreach(s, students){
                if(students->size() == 0) {return;}
                int m = match(s, t);
                if(m > bestMatchScore){
                    bestMatchScore = m;
                    bestStudent = s;
                }
            //students.remove(bestStudent);
                QList<Student*>::iterator it = students.begin();
                while (it != students.end()) {
                  if ((*it)==bestStudent)
                    it = students.erase(it);
                  else
                    ++it;
                }

            t->addStudent(bestStudent);
            }
        }
    }*/

   qDebug() << "** PPID DEBUG ********";
   Student* ds;
   Team* dt;
   foreach(dt, *teams){
    qDebug() << "--Team --   Variance: " << dt->getQualVariance(averages);
    /*QList<Student*> studs = dt->getStudents();
        foreach(ds, studs){
            qDebug() << ds->getFirstName() << " Wants to be leader:" << ds->getAtt_leader() << "  Leader score: " << ds->getLeaderScore();
        }*/
   }


    return;
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
    foreach(s, students){
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

    att_2404 /= students.size();
    att_3005 /= students.size();
    att_coding /= students.size();
    att_dbase /= students.size();
    att_selfDir /= students.size();
    att_writing /= students.size();
    att_UI /= students.size();
    att_algorithm /= students.size();
    att_present /= students.size();
    att_teamwork /= students.size();
    att_experience /= students.size();
    att_testing /= students.size();
    att_UML /= students.size();
    att_req /= students.size();
    att_reliable /= students.size();
    att_comm /= students.size();
    att_respect /= students.size();
    att_creative /= students.size();
    att_critic /= students.size();
    req_leader /= students.size();
    req_2404 /= students.size();
    req_3005 /= students.size();
    req_coding /= students.size();
    req_dbase /= students.size();
    req_selfDir /= students.size();
    req_writing /= students.size();
    req_UI /= students.size();
    req_algorithm /= students.size();
    req_present /= students.size();
    req_teamwork /= students.size();
    req_experience /= students.size();
    req_testing /= students.size();
    req_UML /= students.size();
    req_req /= students.size();
    req_reliable /= students.size();
    req_comm /= students.size();
    req_respect /= students.size();
    req_creative /= students.size();
    req_critic  /= students.size();

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





//TODO
void PPIDManager::printSummaryReport(){
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
* /
    //printf("PPID SUMMARY REPORT\n");
    //printf("Project: %s\n", project->getTitle());
    //printf("Class: %s %s\n", project->getCourseNumber(), project->getCourseDescription());
    //printf("..................................................................................\n");
    int n = 0;
    Team* t;
    Student* s;
    foreach(t, teams){
        n++;
        //printf("Team %d: \n", n);
        foreach(s, t->getStudents()){
           // if()

        }

    }
*/
}

//TODO
void PPIDManager::printDetailedReport(){
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

