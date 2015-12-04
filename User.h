#ifndef USER_H
#define USER_H

class Project;
#include <QString>
using namespace std;


class User
{
protected:
    QString IDNum;          //students start with "1", Admins start with "A-Z or a-z"
//    QString userName;
    QString firstName;
    QString lastName;

public:
    // constructor/destructor
    User();
    ~User();
    QString toString();
    virtual bool getPolicy() = 0;
    virtual QList<Project*>* getProjects() = 0;
    QString getID();
    virtual void joinProject(Project*) = 0;
    virtual void initializeProjects() = 0;
};



class Student: public User
{
protected:
    //Qualifications//
    bool att_leader; // : int        -- want to be a leader? yes/no
    QString att_avail; // : text        -- represent availability slots TTFTTTTFTTFT (etc.)
    int att_2404; // : int        -- grade in 2404
    int att_3005; //: int        -- grade in 3005
    int att_coding; //: int        -- self-assessed coding skill (can be made objective)
    int att_dbase; //: int        -- self-assessed database design skill (can be made objective)
    int att_selfDir; //: int        -- self-assessed self-directedness
    int att_writing; //: int     -- self-assessed technical writing skill and grammar (can be made objective)
    int att_UI; //: int        -- self-assessed UI design (can be made objective)
    int att_algorithm; //: int    -- self-assessed algorithms design skill (can be made objective)
    int att_present; //: int    -- self-assessed verbal presentation skill (can be made objective)
    int att_teamwork; //: int    -- self-assessed teamwork skill
    int att_experience; //: int    -- objective experience
    int att_testing; //: int        -- self-assessed software testing skill
    int att_UML; //: int        -- self-assessed UML design skill
    int att_req; //: int        -- self-assessed requirements analysis skill
    int att_reliable; //: int    -- self-assessed reliability trait
    int att_comm; //: int        -- self-assessed communication skill
    int att_respect; //: int    -- self-assessed respectfulness trait
    int att_creative; //: int    -- self-assessed creativity trait
    int att_critic; // : int        -- self-assessed openness to constructive criticism
    bool req_leader;
    int req_2404;
    int req_3005;
    int req_coding;
    int req_dbase;
    int req_selfDir;
    int req_writing;
    int req_UI;
    int req_algorithm;
    int req_present;
    int req_teamwork;
    int req_experience;
    int req_testing;
    int req_UML;
    int req_req;
    int req_reliable;
    int req_comm;
    int req_respect;
    int req_creative;
    int req_critic;



public:
    // constructors/destructor
    Student(QString, QString, QString, int);
    Student(QString, QString, QString, bool, QString, int,
                     int, int, int,  int, int, int, int, int,
                     int, int, int,  int, int, int, int, int,
                     int, int, bool, int, int, int, int,
                     int, int, int,  int, int, int, int,
                     int, int, int,  int, int, int,
                     int, int);
    ~Student();


    //projects
    QList<Project*>* projects;

    // getters
    QString getIDNum();          //students start with "1", Admins start with "A"
    QString getFirstName();
    QString getLastName();
    bool getAtt_leader(); // : int        -- want to be a leader? yes/no
    QString getAtt_avail(); // : text        -- represent availability slots TTFTTTTFTTFT (etc.)
    int getAtt_2404(); // : int        -- grade in 2404
    int getAtt_3005(); //: int        -- grade in 3005
    int getAtt_coding(); //: int        -- self-assessed coding skill (can be made objective)
    int getAtt_dbase(); //: int        -- self-assessed database design skill (can be made objective)
    int getAtt_selfDir(); //: int        -- self-assessed self-directedness
    int getAtt_writing(); //: int     -- self-assessed technical writing skill and grammar (can be made objective)
    int getAtt_UI(); //: int        -- self-assessed UI design (can be made objective)
    int getAtt_algorithm(); //: int    -- self-assessed algorithms design skill (can be made objective)
    int getAtt_present(); //: int    -- self-assessed verbal presentation skill (can be made objective)
    int getAtt_teamwork(); //: int    -- self-assessed teamwork skill
    int getAtt_experience(); //: int    -- objective experience
    int getAtt_testing(); //: int        -- self-assessed software testing skill
    int getAtt_UML(); //: int        -- self-assessed UML design skill
    int getAtt_req(); //: int        -- self-assessed requirements analysis skill
    int getAtt_reliable(); //: int    -- self-assessed reliability trait
    int getAtt_comm(); //: int        -- self-assessed communication skill
    int getAtt_respect(); //: int    -- self-assessed respectfulness trait
    int getAtt_creative(); //: int    -- self-assessed creativity trait
    int getAtt_critic(); // : int        -- self-assessed openness to constructive criticism
    bool getReq_leader();
    int getReq_2404();
    int getReq_3005();
    int getReq_coding();
    int getReq_dbase();
    int getReq_selfDir();
    int getReq_writing();
    int getReq_UI();
    int getReq_algorithm();
    int getReq_present();
    int getReq_teamwork();
    int getReq_experience();
    int getReq_testing();
    int getReq_UML();
    int getReq_req();
    int getReq_reliable();
    int getReq_comm();
    int getReq_respect();
    int getReq_creative();
    int getReq_critic();

    void setFirstName(QString);
    void setLastName(QString);
    void setAtt_leader(bool);
    void setAtt_avail(QString);
    void setAtt_2404(int);
    void setAtt_3005(int);
    void setAtt_coding(int);
    void setAtt_dbase(int);
    void setAtt_selfDir(int);
    void setAtt_writing(int);
    void setAtt_UI(int);
    void setAtt_algorithm(int);
    void setAtt_present(int);
    void setAtt_teamwork(int);
    void setAtt_experience(int);
    void setAtt_testing(int);
    void setAtt_UML(int);
    void setAtt_req(int);
    void setAtt_reliable(int);
    void setAtt_comm(int);
    void setAtt_respect(int);
    void setAtt_creative(int);
    void setAtt_critic(int);
    void setReq_leader(bool);
    void setReq_2404(int);
    void setReq_3005(int);
    void setReq_coding(int);
    void setReq_dbase(int);
    void setReq_selfDir(int);
    void setReq_writing(int);
    void setReq_UI(int);
    void setReq_algorithm(int);
    void setReq_present(int);
    void setReq_teamwork(int);
    void setReq_experience(int);
    void setReq_testing(int);
    void setReq_UML(int);
    void setReq_req(int);
    void setReq_reliable(int);
    void setReq_comm(int);
    void setReq_respect(int);
    void setReq_creative(int);
    void setReq_critic(int);

    bool getPolicy();
    QList<Project*>* getProjects();
    void joinProject(Project*);
    void initializeProjects();

    int getLeaderScore();
    int getCoderScore();
    int getWriterScore();
    int getOverallScore();

};



class Admin : public User
{
protected:
    //list of projects

public:
    // constructor/destructor
    Admin(QString, QString, QString, int);
    Admin(QString, QString, QString);
    ~Admin();

    //QString toString();
    // setters

    // getters
    QString getIDNum();          //students start with "1", Admins start with "A"
    QString getFirstName();
    QString getLastName();

    bool getPolicy();
    QList<Project*>* getProjects();
    void joinProject(Project*);
    void initializeProjects();
};
#endif // USER_H
