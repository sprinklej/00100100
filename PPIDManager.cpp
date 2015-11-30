#include "PPIDManager.h";

//////////////////////////CLASS IS NOT COMPLETE
/// //////////////////////FEEL FREE TO COMMENT OUT
///
PPIDManager::PPIDManager(QList<Student*>& stIn, Project* p){
    students = new QList<Student*>(); // need a new one - PPID destroys the list
    Student* s;
    foreach(s,stIn){
        students.push_back(s);
    }
    project = p;
    averages = QHash<QString, float>();

    //1. Calculate the number of teams numTeams
    //2. Make a QList<Team*> of Teams
    numTeams = p->getNumTeams();


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
        att_2404 += s->att_2404;
        att_3005 += s->att_3005;
        att_coding += s->att_coding;
        att_dbase += s->att_dbase;
        att_selfDir += s->att_selfDir;
        att_writing += s->att_writing;
        att_UI += s->att_UI;
        att_algorithm += s->att_algorithm;
        att_present += s->att_present;
        att_teamwork += s->att_teamwork;
        att_experience += s->att_experience;
        att_testing += s->att_testing;
        att_UML += s->att_UML;
        att_req += s->att_req;
        att_reliable += s->att_reliable;
        att_comm += s->att_comm;
        att_respect += s->att_respect;
        att_creative += s->att_creative;
        att_critic += s->att_critic;
        req_leader += s->req_leader;
        req_2404 += s->req_2404;
        req_3005 += s->req_3005;
        req_coding += s->req_coding;
        req_dbase += s->req_dbase;
        req_selfDir += s->req_selfDir;
        req_writing += s->req_writing;
        req_UI += s->req_UI;
        req_algorithm += s->req_algorithm;
        req_present += s->req_present;
        req_teamwork += s->req_teamwork;
        req_experience += s->req_experience;
        req_testing += s->req_testing;
        req_UML += s->req_UML;
        req_req += s->req_req;
        req_reliable += s->req_reliable;
        req_comm += s->req_comm;
        req_respect += s->req_respect;
        req_creative += s->req_creative;
        req_critic  += s->req_critic;
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

void PPIDManager::RunAlgorithm(){

    if(numTeams < students.Size() *2){
        //give an error dialog
        return;
    }

    if(numTeams < students.Size() *3){
        //run alternative PPID
        return;
    }

    // IN CTOR:
    //1. Calculate the number of teams numTeams
    //2. Make a QList<Student*> of Teams
    //3. Sort students on the basis of leaderScore()
    //TODO: implement a compLeader(Student*, Student*) function
    std::sort(students.begin(), students.end(), compStudentsOnLeader);

    /*4. For each student in students:
    - if leader - true:
        - create a new team
        - push the team to teams
        - remove s
        - push s to teams
        - if teams.size = numteams, break*/
    Student* s;
    int pos = 0;
    foreach(s, students){
        if(s->getAtt_Ldr()){
            Team* t = new Team();
            t << s;
            students.removeAt(pos--);
            teams << t;
        }
        if(teams.Size() <= numTeams) break;
        pos++;
    }


    /*5.  If teams.size < numteams:
    For each student in students:
        - create a new team
        - push the team to teams
        - remove s
        - push s to teams
        - if teams.size = numteams, break*/

    pos = 0;
    while(teams.Size() < numTeams){
        foreach(s, students){
            Team* t = new Team();
            t << s;
            students.removeAt(pos--);
            teams << t;
        }
        pos++;
    }

    //- We now have all the teams and all the leaders

    /*Two ways to do this:
    6a. Sort the teams from highest to lowest variance
    6b. Sort the teams from weakest to strongest*/
    std::sort(teams.begin(), teams.end(), compTeamsOnVariance);

    //7.  Sort students on coderscore
    std::sort(students.begin(), students.end(), compStudentsOnCoding);

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

    bestMatchScore = 0;
    bestStudent = students.at(0);

    foreach(t, Teams){
        foreach(s, students){
            int m = match(s, t);
            if(m > bestMatchScore){
                bestMatchScore = m;
                bestStudent = s;
            }
        students.remove(bestStudent);
        t << bestStudent;
    }

    /*Two ways to do this:
    9a. Sort the teams from highest to lowest variance
    9b. Sort the teams from weakest to strongest	*/
    std::sort(teams.begin(), teams.end(), compTeamsOnVariance);

    //10.  Sort students on presenterscore
    std::sort(students.begin(), students.end(), compStudentsOnWriting);

    /*		let bestmatch = match(team, student(0))
            let beststudent = student(0)
                    For student from 0 to numteams
                    if int m = match(team, student(n)) < bestmatch
                    bestmatch = m
                    beststudent = student(n)

                Remove beststudent from students
                push beststudent to team*/

    bestMatchScore = 0;
    bestStudent = students.at(0);

    foreach(t, Teams){
        foreach(s, students){
            int m = match(s, t);
            if(m > bestMatchScore){
                bestMatchScore = m;
                bestStudent = s;
            }
        students.remove(bestStudent);
        t << bestStudent;
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
            students.remove(bestStudent);
            t << bestStudent;
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
            students.remove(bestStudent);
            t << bestStudent;
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
            students.remove(bestStudent);
            t << bestStudent;
            }
        }

    }

    //assign any leftover students

    while(students.size() > 0){
        std::sort(teams.begin(), teams.end(), compTeamsOnVariance);
            foreach(t, Teams){
            if(students->size() == 0) {return;}
            foreach(s, students){
                if(students->size() == 0) {return;}
                int m = match(s, t);
                if(m > bestMatchScore){
                    bestMatchScore = m;
                    bestStudent = s;
                }
            students.remove(bestStudent);
            t << bestStudent;
            }
        }
    }

    return;
}



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
*/
    printf("PPID SUMMARY REPORT\n");
    printf("Project: %s\n", project->getTitle());
    printf("Class: %s %s\n", project->getCourseNumber(), project->getCourseDescription());
    printf("..................................................................................\n");
    int n = 0;
    Team* t;
    Student* s;
    foreach(t, teams){
        n++;
        printf("Team %d: \n", n);
        foreach(s, teams->getStudents()){
            if()

        }

    }

}

void PPIDManager::printDetailedReport(){
}


/*


PPID Manager(QList<Student*>& students, Project* p){

Note: the PPID destroys the students list


Need:
  - function to sort a QList by leaderscore
  - add a getLeaderscore() to Student
  - add a getCoderScore() to Student
  - int match(team*, student*)








11. if numTeams * 3 >= students (remember we have already removed numTeams * 3) do 12-15

12.
    Two ways to do this:
    12a. Sort the teams from highest to lowest variance
    12b. Sort the teams from weakest to strongest

    13.  Sort students on coderscore

    14.  For each team in teams:
            let bestmatch = match(team, student(0))
            let beststudent = student(0)

                For student from 0 to numteams
                    if int m = match(team, student(n)) < bestmatch
                    bestmatch = m
                    beststudent = student(n)

                Remove beststudent from students
                push beststudent to team

    15 Repeat 6-11

16.  numTeams *3 is now < students

17.  While students is not empty repeat 18, 19

18.  Two ways to do this:
    18a. Sort the teams from highest to lowest variance
    18b. Sort the teams from weakest to strongest

19.  For each team in teams:
        let bestmatch = match(team, student(0))
        let beststudent = student(0)

            For student from 0 to numteams
                if int m = match(team, student(n)) < bestmatch
                bestmatch = m
                beststudent = student(n)

            Remove beststudent from students
            push beststudent to team

20.  PPID is finished.  Print one of:

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

==================================================================================

PPID DETAILED REPORT
Project:
  Class:
..................................................................................

Team n:
  Leader - Student Name ......... 100234512
   Coder - Student Name ......... 100674556
  Writer - Student Name ......... 100345234
   Other - Student Name ......... 100345233

..................................................................................

Availability:
          ||Sun     ||Mon     ||Tue     ||Wed     ||Thur    ||Fri     ||Sat     ||
          ||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||
100234512 ||1 |  |  || 1|  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||
100674556 ||1 |  |  || 1|  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||
100345234 ||  |1 |  ||  | 1| 1||  |  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||
100345233 ||  |  |1 ||  |  | 1||  |  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||

Total availability overlap index: n (60%)
..................................................................................

Qualifications:
          ||Leader           ||Coder            ||Writer           ||
          ||L1|L2|L3|L4|L5|L6||C1|C2|C3|C4|C5|C6||W1|W2|W3|W4|W5|W6||
100234512 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100674556 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100345234 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100345233 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
.....................................................................
    Total ||                 ||                 ||                 ||
Class Avg ||                 ||                 ||                 ||
 Variance ||                 ||                 ||                 ||

Total Qualification index: n
..................................................................................

Looking for:
          ||Leader           ||Coder            ||Writer           ||
          ||L1|L2|L3|L4|L5|L6||C1|C2|C3|C4|C5|C6||W1|W2|W3|W4|W5|W6||
100234512 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100674556 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100345234 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100345233 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
.....................................................................
TotLooking||                 ||                 ||                 ||
 TotFound ||                 ||                 ||                 ||
 Variance ||                 ||                 ||                 ||

Total (Looking for - found) index: n
..................................................................................
 Availability Index :
Qualification Index :
  Looking for Index :

FINAL SCORE:
..................................................................................

/*


/*

PPID Manager Class in Pseudocode



Note: the PPID destroys the students list

Start:
calculate and save the mean value of each qualification

Need:
  - function to sort a QList by leaderscore
  - add a getLeaderscore() to Student
  - add a getCoderScore() to Student
  - int match(team*, student*)
  - void printSummary(Qlist<Team*>)
  - void printDetailed(Qlist<Team*>)

1. Calculate the number of teams numTeams
2. Make a QList<Student*> of Teams
3. Sort students on the basis of leaderScore()
4. For each student in students:
    - if leader - true:
        - create a new team
        - push the team to teams
        - remove s
        - push s to teams
        - if teams.size = numteams, break
5.  If teams.size < numteams:
    For each student in students:
        - create a new team
        - push the team to teams
        - remove s
        - push s to teams
        - if teams.size = numteams, break

- We now have all the teams and all the leaders

Two ways to do this:
6a. Sort the teams from highest to lowest variance
6b. Sort the teams from weakest to strongest

7.  Sort students on coderscore

8.  For each team in teams:
            let bestmatch = match(team, student(0))
            let beststudent = student(0)

                For student from 0 to numteams
                    if int m = match(team, student(n)) < bestmatch
                    bestmatch = m
                    beststudent = student(n)

                Remove beststudent from students
                push beststudent to team

Two ways to do this:
9a. Sort the teams from highest to lowest variance
9b. Sort the teams from weakest to strongest

10.  Sort students on presenterscore
            let bestmatch = match(team, student(0))
            let beststudent = student(0)

                For student from 0 to numteams
                    if int m = match(team, student(n)) < bestmatch
                    bestmatch = m
                    beststudent = student(n)

                Remove beststudent from students
                push beststudent to team

11. if numTeams * 3 >= students (remember we have already removed numTeams * 3) do 12-15

12.
    Two ways to do this:
    12a. Sort the teams from highest to lowest variance
    12b. Sort the teams from weakest to strongest

    13.  Sort students on coderscore

    14.  For each team in teams:
            let bestmatch = match(team, student(0))
            let beststudent = student(0)

                For student from 0 to numteams
                    if int m = match(team, student(n)) < bestmatch
                    bestmatch = m
                    beststudent = student(n)

                Remove beststudent from students
                push beststudent to team

    15 Repeat 6-11

16.  numTeams *3 is now < students

17.  While students is not empty repeat 18, 19

18.  Two ways to do this:
    18a. Sort the teams from highest to lowest variance
    18b. Sort the teams from weakest to strongest

19.  For each team in teams:
        let bestmatch = match(team, student(0))
        let beststudent = student(0)

            For student from 0 to numteams
                if int m = match(team, student(n)) < bestmatch
                bestmatch = m
                beststudent = student(n)

            Remove beststudent from students
            push beststudent to team

20.  PPID is finished.  Print one of:

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

==================================================================================

PPID DETAILED REPORT
Project:
  Class:
..................................................................................

Team n:
  Leader - Student Name ......... 100234512
   Coder - Student Name ......... 100674556
  Writer - Student Name ......... 100345234
   Other - Student Name ......... 100345233

..................................................................................

Availability:
          ||Sun     ||Mon     ||Tue     ||Wed     ||Thur    ||Fri     ||Sat     ||
          ||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||AM|PM|Ev||
100234512 ||1 |  |  || 1|  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||
100674556 ||1 |  |  || 1|  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||
100345234 ||  |1 |  ||  | 1| 1||  |  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||
100345233 ||  |  |1 ||  |  | 1||  |  |  ||  |  |  ||  |  |  ||  |  |  ||  |  |  ||

Total availability overlap index: n (60%)
..................................................................................

Qualifications:
          ||Leader           ||Coder            ||Writer           ||
          ||L1|L2|L3|L4|L5|L6||C1|C2|C3|C4|C5|C6||W1|W2|W3|W4|W5|W6||
100234512 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100674556 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100345234 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100345233 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
.....................................................................
    Total ||                 ||                 ||                 ||
Class Avg ||                 ||                 ||                 ||
 Variance ||                 ||                 ||                 ||

Total Qualification index: n
..................................................................................

Looking for:
          ||Leader           ||Coder            ||Writer           ||
          ||L1|L2|L3|L4|L5|L6||C1|C2|C3|C4|C5|C6||W1|W2|W3|W4|W5|W6||
100234512 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100674556 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100345234 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
100345233 ||  |  |  |  |  |  ||  |  |  |  |  |  ||  |  |  |  |  |  ||
.....................................................................
TotLooking||                 ||                 ||                 ||
 TotFound ||                 ||                 ||                 ||
 Variance ||                 ||                 ||                 ||

Total (Looking for - found) index: n
..................................................................................
 Availability Index :
Qualification Index :
  Looking for Index :

FINAL SCORE:
..................................................................................


}




*/
