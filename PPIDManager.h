#ifndef PPIDMANAGER_H
#define PPIDMANAGER_H

#include "Project.h"
#include "User.h"
#include "Team.h"
#include <algorithm>
#include "math.h"
#include "QHash"

#include "ppidresultswindow.h"

class ManageAdminControl;

class PPIDManager{
public:
    PPIDManager(QList<Student*>&, Project*, ManageAdminControl*);
    ~PPIDManager();

    void runAlgorithm();

    QString printSummaryReport();
    QString printDetailedReport();
    void displayReports();
    int getNumteams();

private:

    void calculateAverages();
    QList<Student*>* students;
    Project* project;
    QList<Team*>* teams;
    int numTeams;

    QHash<QString, float> averages;
    bool compStudentsOnLeader(Student*, Student*);
    bool compTeamsOnVariance(Team*, Team*, QHash<QString, float>&);
    bool compTeamsOnLookingForVariance(Team*, Team*);
    bool compStudentsOnCoding(Student*, Student*);
    bool compStudentsOnWriting(Student*, Student*);
    bool compStudentsOverall(Student*, Student*);

    void sortTeamsOnVariance();

    float bestMatchScore;
    Student* bestStudent;
    float match(Team*, Student*);

    void getLeaders();
    void getCoders();
    void getWriters();
    void getAnyone();

    //admin managers
    ManageAdminControl* manAdminCon;
};

#endif // PPIDMANAGER_H
