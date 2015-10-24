#ifndef TEAM_H
#define TEAM_H

using namespace std;


class Team
{
protected:
    int projectID;
    int teamID;
    // how do we want to store the teams

public:
    // constructor/destructor
    Team(int project_ID, int team_ID);
    ~Team();

    // setters
    void setProjectID(int project_ID);
    void setTeamID(int teamID);

    // getters
    int getProjectID();
    int getTeamID();
};

#endif // TEAM_H
