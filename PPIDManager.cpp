#include "PPIDManager.h";



PPIDManager::PPIDManager(QList<Student*>& studs, Project* p){

    students = studs;
    project = p;
    teams = QList<Team*>();


    //calculate numteams;
}

void PPIDManager::createTeams(){

}

void PPIDManager::printSummaryReport(){

}

void PPIDManager::printDetailedReport(){

}

int PPIDManager::match(Team* t, Student* s){

}

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
