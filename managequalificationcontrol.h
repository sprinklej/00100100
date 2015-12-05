#ifndef MANAGEQUALIFICATIONCONTROL_H
#define MANAGEQUALIFICATIONCONTROL_H

#include "qualificationwindow.h"
class StorageFacade;
class ManageStudentControl;
class ManageRegistrationControl;


using namespace std;

class ManageQualificationControl
{
public:
    ManageQualificationControl(StorageFacade*, Student*, bool);
    ~ManageQualificationControl();
    void createGUI();
    void setQualWin(QualificationWindow*);
    void setManRegCon(ManageRegistrationControl*);
    void setManStudCon(ManageStudentControl*);
    void cancelClicked();
    void updateStudWin();

    //slider
    void trackSlidersTotalVal(int, QSlider *);

private:
    StorageFacade* facade;
    Student* user;
    bool update; // true if updating, false if signing up
    QualificationWindow* qualWin;
    ManageRegistrationControl *manRegCon;
    ManageStudentControl *manStudCon;

    // slider stuff
    int sliderMAX;
    int totalSliderVal;
    int SV2404, SVcplusplus, SV3005, SVDBDesign, SVSelfDir, SVTechWrite, SVUIDeign, SVAlgDesign;
    int SVPresSkill, SVTeamwork, SVExper, SVSWTest, SVUML, SVReqAn, SVReliable, SVComm;
    int SVRespect, SVCreative, SVCrit;

};

#endif // MANAGEQUALIFICATIONCONTROL_H
