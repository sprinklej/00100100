#ifndef MANAGEPPIDRESULTSCONTROL_H
#define MANAGEPPIDRESULTSCONTROL_H

// Included to read/display files and errors
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "ppidresultswindow.h"
#include <QDir>

using namespace std;


class ManagePPIDResultsControl
{
public:
    ManagePPIDResultsControl();
    ~ManagePPIDResultsControl();
    void setResWin(PPIDResultsWindow*);
    void saveToFile();
    void showReport(QString fileName, int flag);
    void createGUI();

private:
    PPIDResultsWindow *ppidResWin;
};

#endif // MANAGEPPIDRESULTSCONTROL_H
