#ifndef MANAGEQUALIFICATIONCONTROL_H
#define MANAGEQUALIFICATIONCONTROL_H

#include "qualificationwindow.h"
class StorageFacade;

using namespace std;

class ManageQualificationControl
{
public:
    ManageQualificationControl(StorageFacade* f);
    ~ManageQualificationControl();
    void createGUI();

private:
    StorageFacade * facade;
};

#endif // MANAGEQUALIFICATIONCONTROL_H
