#ifndef PPIDMANAGER_H
#define PPIDMANAGER_H

#include "Project.h";
#include "User.h";
#include "Team.h";
#include <algorithm>
#include "math.h"
#include "QHash"

class PPIDManager{
public:
    PPIDManager(QList<Student*>&, Project*);
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
    bool compStudentsOnLeader(Student*, Student*); //TODO
    bool compTeamsOnVariance(Team*, Team*);
    bool compStudentsOnCoding(Student*, Student*);
    bool compStudentsOnWriting(Student*, Student*);
    bool compStudentsOverall(Student*, Student*);

    float bestMatchScore = 0;
    Student* bestStudent = 0;
    float match(Team*, Student*);
};

#endif // PPIDMANAGER_H
