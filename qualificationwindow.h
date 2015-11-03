#ifndef QUALIFICATIONWINDOW_H
#define QUALIFICATIONWINDOW_H

#include <QDialog>
#include "User.h"
#include "studentwindow.h"

namespace Ui {
class QualificationWindow;
}

class QualificationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QualificationWindow(QWidget *parent = 0);
    ~QualificationWindow();
    void setStudent(Student*);
    void setupdate(bool);
    void setStudWind(StudentWindow*);

private slots:
    //void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::QualificationWindow *ui;
    Student* student;
    bool update;
    StudentWindow* studWin;
    //void on_pushButton_ok_clicked();
    //void on_pushButton_cancel_clicked();

};
#endif // QUALIFICATIONWINDOW_H
