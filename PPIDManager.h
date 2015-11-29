#ifndef PPIDMANAGER_H
#define PPIDMANAGER_H

#include "Project.h";
#include "User.h";
#include "Team.h";

class PPIDManager{
public:

    PPIDManager(QList<Student*>&, Project*);
    void createTeams();
    void printSummaryReport();
    void printDetailedReport();
    int match(Team*, Student*);

private:
    QList<Student*> students;
    Project* project;
    QList<Team*> teams;

int numteams;
};

#endif // PPIDMANAGER_H
