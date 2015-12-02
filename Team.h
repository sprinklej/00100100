#ifndef TEAM_H
#define TEAM_H

#include "math.h"
#include "QHash"
#include "User.h"
#include "Project.h"

using namespace std;


class Team
{
protected:
    int projectID;
    int teamID;
    // how do we want to store the teams
    QList<Student*> students; //like this is fine


public:
    // constructor/destructor
    Team(int project_ID, int team_ID);
    Team();
    ~Team();

    // setters
    void setProjectID(int project_ID);
    void setTeamID(int teamID);

    // getters
    int getProjectID();
    int getTeamID();
    QList<Student*>& getStudents();

    //utility functions
    float square(float);
    float getQualVariance(QHash<QString, float>&);
    float getLFVariance();
    float Team::getScheduleMatch();
    float match(Student*, QHash<QString, float>&);
};

#endif // TEAM_H
