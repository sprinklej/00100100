#include "User.h"
#include "Project.h"

User::User()
{
;
}

User::~User(){}

QString User::toString(){
    QString ret = "User: ";
    ret.append(firstName);
    ret.append(" ");
    ret.append(lastName);
    ret.append(" ");
    ret.append(IDNum);
    return ret;
}

QString User::getID(){return IDNum;}


Student::Student(QString fn, QString ln, QString id, int a1 ){ // what is int a1 for?
    firstName = fn;
    lastName = ln;
    IDNum = id;

    projects = new QList<Project*>();

    att_leader = false;
    att_avail = QString("FFFFFFFFFFFFFFFFFFFFF");
    att_2404 = 0;
    att_3005 = 0;
    att_coding = 0;
    att_dbase = 0;
    att_selfDir = 0;
    att_writing = 0;
    att_UI = 0;
    att_algorithm = 0;
    att_present = 0;
    att_teamwork = 0;
    att_experience = 0;
    att_testing = 0;
    att_UML = 0;
    att_req = 0;
    att_reliable = 0;
    att_comm = 0;
    att_respect = 0;
    att_creative = 0;
    att_critic = 0;
    req_leader = 0;
    req_2404 = 0;
    req_3005 = 0;
    req_coding = 0;
    req_dbase = 0;
    req_selfDir = 0;
    req_writing = 0;
    req_UI = 0;
    req_algorithm = 0;
    req_present = 0;
    req_teamwork = 0;
    req_experience = 0;
    req_testing = 0;
    req_UML = 0;
    req_req = 0;
    req_reliable = 0;
    req_comm = 0;
    req_respect = 0;
    req_creative = 0;
    req_critic = 0;

}

Student::Student(QString fn, QString ln, QString id, bool cld, QString cav, int c2404,
                 int c3005, int ccod, int cdb, int csd, int cwr, int cui, int cal, int cpr,
                 int ctw, int cxp, int ctst, int cuml, int creq, int crel, int ccom, int cres,
                 int ccre, int ccri, bool crld, int cr2404, int cr3005, int crcod, int crdb,
                 int crsd, int crwr, int crui, int cral, int crpr, int crtw, int crxp,
                 int crtst, int cruml, int crreq, int crrel, int crcom, int crres,
                 int crcre, int crcri){
    firstName = fn;
    lastName = ln;
    IDNum = id;

    att_leader = cld; // : int        -- want to be a leader? yes/no
    att_avail = cav; // : text        -- represent availability slots TTFTTTTFTTFT (etc.)
    att_2404 = c2404; // : int        -- grade in 2404
    att_3005 = c3005; //: int        -- grade in 3005
    att_coding = ccod; //: int        -- self-assessed coding skill (can be made objective)
    att_dbase = cdb; //: int        -- self-assessed database design skill (can be made objective)
    att_selfDir = csd; //: int        -- self-assessed self-directedness
    att_writing = cwr; //: int     -- self-assessed technical writing skill and grammar (can be made objective)
    att_UI = cui; //: int        -- self-assessed UI design (can be made objective)
    att_algorithm = cal; //: int    -- self-assessed algorithms design skill (can be made objective)
    att_present = cpr; //: int    -- self-assessed verbal presentation skill (can be made objective)
    att_teamwork = ctw; //: int    -- self-assessed teamwork skill
    att_experience = cxp; //: int    -- objective experience
    att_testing = ctst; //: int        -- self-assessed software testing skill
    att_UML = cuml; //: int        -- self-assessed UML design skill
    att_req = creq; //: int        -- self-assessed requirements analysis skill
    att_reliable = crel; //: int    -- self-assessed reliability trait
    att_comm = ccom; //: int        -- self-assessed communication skill
    att_respect = cres; //: int    -- self-assessed respectfulness trait
    att_creative = ccre; //: int    -- self-assessed creativity trait
    att_critic = ccri; // : int        -- self-assessed openness to constructive criticism
    req_leader = crld;
    req_2404 = cr2404;
    req_3005 = cr3005;
    req_coding = crcod;
    req_dbase = crdb;
    req_selfDir = crsd;
    req_writing = crwr;
    req_UI = crui;
    req_algorithm = cral;
    req_present = crpr;
    req_teamwork = crtw;
    req_experience = crxp;
    req_testing = crtst;
    req_UML = cruml;
    req_req = crreq;
    req_reliable = crrel;
    req_comm = crcom;
    req_respect = crres;
    req_creative = crcre;
    req_critic = crcri;

}

Student::~Student(){}

//////////// GETTERS /////////////////////
QString Student::getIDNum(){return IDNum;}          //students start with "1", Admins start with "A"
//QString Student::getUserName(){return userName;}
QString Student::getFirstName(){return firstName;}
QString Student::getLastName(){return lastName;}
//int Student::getAtt1(){return att1;}

bool Student::getAtt_leader() {return att_leader  ;}
QString Student::getAtt_avail() {return att_avail  ;}
int Student::getAtt_2404() {return att_2404  ;}
int Student::getAtt_3005() {return att_3005  ;}
int Student::getAtt_coding() {return att_coding  ;}
int Student::getAtt_dbase() {return att_dbase  ;}
int Student::getAtt_selfDir() {return att_selfDir  ;}
int Student::getAtt_writing() {return att_writing  ;}
int Student::getAtt_UI() {return att_UI  ;}
int Student::getAtt_algorithm() {return att_algorithm  ;}
int Student::getAtt_present() {return att_present  ;}
int Student::getAtt_teamwork() {return att_teamwork  ;}
int Student::getAtt_experience() {return att_experience  ;}
int Student::getAtt_testing() {return att_testing  ;}
int Student::getAtt_UML() {return att_UML  ;}
int Student::getAtt_req() {return att_req  ;}
int Student::getAtt_reliable() {return att_reliable  ;}
int Student::getAtt_comm() {return att_comm  ;}
int Student::getAtt_respect() {return att_respect  ;}
int Student::getAtt_creative() {return att_creative  ;}
int Student::getAtt_critic() {return  att_critic ;}
bool Student::getReq_leader() {return req_leader  ;}
int Student::getReq_2404() {return req_2404  ;}
int Student::getReq_3005() {return req_3005  ;}
int Student::getReq_coding() {return req_coding  ;}
int Student::getReq_dbase() {return req_dbase  ;}
int Student::getReq_selfDir() {return req_selfDir  ;}
int Student::getReq_writing() {return req_writing  ;}
int Student::getReq_UI() {return req_UI  ;}
int Student::getReq_algorithm() {return  req_algorithm ;}
int Student::getReq_present() {return req_present  ;}
int Student::getReq_teamwork() {return req_teamwork  ;}
int Student::getReq_experience() {return req_experience  ;}
int Student::getReq_testing() {return req_testing  ;}
int Student::getReq_UML() {return req_UML  ;}
int Student::getReq_req() {return req_req  ;}
int Student::getReq_reliable() {return req_reliable  ;}
int Student::getReq_comm() {return req_comm  ;}
int Student::getReq_respect() {return req_respect  ;}
int Student::getReq_creative() {return  req_creative ;}
int Student::getReq_critic() {return req_critic  ;}

/////////// SETTERS ////////

void Student::setFirstName(QString s){firstName = s;}
void Student::setLastName(QString s){lastName = s;}

void Student::setAtt_leader(bool a){att_leader = a;}
void Student::setAtt_avail(QString a){att_avail = a;}
void Student::setAtt_2404(int a){att_2404 = a;}
void Student::setAtt_3005(int a){att_3005 = a;}
void Student::setAtt_coding(int a){ att_coding = a;}
void Student::setAtt_dbase(int a){ att_dbase = a;}
void Student::setAtt_selfDir(int a){ att_selfDir = a;}
void Student::setAtt_writing(int a){ att_writing = a;}
void Student::setAtt_UI(int a){ att_UI = a;}
void Student::setAtt_algorithm(int a){ att_algorithm = a;}
void Student::setAtt_present(int a){ att_present = a;}
void Student::setAtt_teamwork(int a){ att_teamwork = a;}
void Student::setAtt_experience(int a){att_experience = a;}
void Student::setAtt_testing(int a){ att_testing = a;}
void Student::setAtt_UML(int a){ att_UML = a;}
void Student::setAtt_req(int a){ att_req = a;}
void Student::setAtt_reliable(int a){att_reliable = a;}
void Student::setAtt_comm(int a){ att_comm = a;}
void Student::setAtt_respect(int a){att_respect = a;}
void Student::setAtt_creative(int a){ att_creative = a;}
void Student::setAtt_critic(int a){att_critic = a;}
void Student::setReq_leader(bool a){ req_leader = a;}
void Student::setReq_2404(int a){ req_2404 = a;}
void Student::setReq_3005(int a){req_3005 = a;}
void Student::setReq_coding(int a){req_coding = a;}
void Student::setReq_dbase(int a){req_dbase = a;}
void Student::setReq_selfDir(int a){ req_selfDir = a;}
void Student::setReq_writing(int a){ req_writing = a;}
void Student::setReq_UI(int a){req_UI = a;}
void Student::setReq_algorithm(int a){ req_algorithm = a;}
void Student::setReq_present(int a){req_present = a;}
void Student::setReq_teamwork(int a){ req_teamwork = a;}
void Student::setReq_experience(int a){req_experience = a;}
void Student::setReq_testing(int a){ req_testing = a;}
void Student::setReq_UML(int a){ req_UML = a;}
void Student::setReq_req(int a){ req_req = a;}
void Student::setReq_reliable(int a){ req_reliable = a;}
void Student::setReq_comm(int a){ req_comm = a;}
void Student::setReq_respect(int a){ req_respect = a;}
void Student::setReq_creative(int a){req_creative = a;}
void Student::setReq_critic(int a){req_critic = a;}

bool Student::getPolicy(){return true;}
QList<Project*>* Student::getProjects(){return projects;}


Admin::Admin(QString fn, QString ln, QString id, int a1){
    firstName = fn;
    lastName = ln;
    IDNum = id;
}

Admin::~Admin(){}

/////////// GETTERS ////////////
QString Admin::getIDNum(){return IDNum;}          //students start with "1", Admins start with "A"
//QString Admin::getUserName(){return userName;}
QString Admin::getFirstName(){return firstName;}
QString Admin::getLastName(){return lastName;}

bool Admin::getPolicy(){return false;}
QList<Project*>* Admin::getProjects(){return 0;}
