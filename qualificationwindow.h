#ifndef QUALIFICATIONWINDOW_H
#define QUALIFICATIONWINDOW_H

#include <QDialog>
#include "User.h"
#include "studentwindow.h"
#include <QSlider>

namespace Ui {
class QualificationWindow;
}

class QualificationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QualificationWindow(QWidget *parent = 0);
    ~QualificationWindow();
    void trackSlidersTotalVal(int incomingVal, QSlider *);

    //setters/getters
    int getTotalSliderVal();
    void setTotalSliderVal(int val);
    void setStudent(Student*);
    void setupdate(bool);
    void setStudWind(StudentWindow*);

private slots:
    //void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

    void on_sli2404_valueChanged(int value);

    void on_slicpp_valueChanged(int value);

    void on_sli3005_valueChanged(int value);

    void on_slidb_valueChanged(int value);

    void on_slisd_valueChanged(int value);

    void on_slitw_valueChanged(int value);

    void on_sliui_valueChanged(int value);

    void on_slialg_valueChanged(int value);

    void on_slipres_valueChanged(int value);

    void on_slitw_2_valueChanged(int value);

    void on_slixp_valueChanged(int value);

    void on_slitest_valueChanged(int value);

    void on_sliuml_valueChanged(int value);

    void on_slireq_valueChanged(int value);

    void on_slirel_valueChanged(int value);

    void on_slicomm_valueChanged(int value);

    void on_sliresp_valueChanged(int value);

    void on_slicre_valueChanged(int value);

    void on_slicri_valueChanged(int value);

private:
    Ui::QualificationWindow *ui;
    Student* student;
    bool update;
    StudentWindow* studWin;
    int totalSliderVal;

    int SV2404, SVcplusplus, SV3005, SVDBDesign, SVSelfDir, SVTechWrite, SVUIDeign, SVAlgDesign;
    int SVPresSkill, SVTeamwork, SVExper, SVSWTest, SVUML, SVReqAn, SVReliable, SVComm;
    int SVRespect, SVCreative, SVCrit;
};
#endif // QUALIFICATIONWINDOW_H
