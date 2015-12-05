#ifndef PPIDMANAGER_H
#define PPIDMANAGER_H

#include "Project.h"
#include "User.h"
#include "Team.h"
#include <algorithm>
#include "math.h"
#include "QHash"

class ManageAdminControl;

class PPIDManager{
public:
    PPIDManager(QList<Student*>&, Project*, ManageAdminControl*);
    ~PPIDManager();
    void printSummaryReport();
    void printDetailedReport();

private:
    void runAlgorithm();

    void calculateAverages();
    QList<Student*> students;
    Project* project;
    QList<Team*> teams;
    int numTeams;

    QHash<QString, float> averages;
    bool compStudentsOnLeader(Student*, Student*);
    bool compTeamsOnVariance(Team*, Team*, QHash<QString, float>&);
    bool compTeamsOnLookingForVariance(Team*, Team*);
    bool compStudentsOnCoding(Student*, Student*);
    bool compStudentsOnWriting(Student*, Student*);
    bool compStudentsOverall(Student*, Student*);

    void sortStudentsOnLeader();
    void sortStudentsOnCoder();
    void sortStudentsOnWriter();
    void sortStudentsOverall();
    void sortTeamsOnVariance();

    float bestMatchScore;
    Student* bestStudent;
    float match(Team*, Student*);

    //admin managers
    ManageAdminControl* manAdminCon;
};

#endif // PPIDMANAGER_H
