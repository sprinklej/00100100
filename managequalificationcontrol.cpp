#include "managequalificationcontrol.h"
#include "managestudentcontrol.h"
#include "manageRegistrationControl.h"
#include "StorageFacade.h"


ManageQualificationControl::ManageQualificationControl(StorageFacade* f, Student* s, bool up)
{
    facade = f;
    user = s;
    update = up; // true if updating, false if signing up

    manRegCon = NULL;
    manStudCon = NULL;

    //slider control
    sliderMAX = 40;
    totalSliderVal = 0;
}

ManageQualificationControl::~ManageQualificationControl()
{
}



/* --------------------------- GUI function ------------------------*/
void ManageQualificationControl::createGUI()
{
    QualificationWindow* qualWin = new QualificationWindow();
    setQualWin(qualWin);
    qualWin->setStudent(user);
    qualWin->setManQualCon(this);
    qualWin->setStorageFacade(facade);
    qualWin->setupdate(update);

    if (update) { // update
        // opens new window and disables current window
        qualWin->setModal(true);
        qualWin->exec();
    } else { // signup
           qualWin->show();
    }
}



/* --------------------------- setters ------------------------*/
void ManageQualificationControl::setQualWin(QualificationWindow* qw)
{
    qualWin = qw;
}

void ManageQualificationControl::setManRegCon(ManageRegistrationControl* mrc) {
    manRegCon = mrc;
}

void ManageQualificationControl::setManStudCon(ManageStudentControl* msc){
    manStudCon = msc;
}



/* --------------------------- slider ------------------------*/
void ManageQualificationControl::trackSlidersTotalVal(int incomingVal, QSlider * curSlider)
{
    int totalVal = totalSliderVal;
    totalVal += incomingVal; //totalVal += incomingVal;

    if (totalVal > sliderMAX) {
        int dif = totalVal - sliderMAX;
        qualWin->setSlider(curSlider, curSlider->sliderPosition() - dif);
        totalVal -= dif;
    }
    totalSliderVal = totalVal;
}



/* --------------------------- cancel clicked ------------------------*/
void ManageQualificationControl::cancelClicked()
{
    if(manRegCon != NULL) {
        delete user;
        manRegCon->setStatus("New user NOT created");
    }
}

/* --------------------------- send update to student window ------------------------*/
void ManageQualificationControl::updateStudWin(){
    manStudCon->updateUserInfo();
}

