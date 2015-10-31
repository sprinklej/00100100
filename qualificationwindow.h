#ifndef QUALIFICATIONWINDOW_H
#define QUALIFICATIONWINDOW_H

#include <QDialog>
#include "User.h"

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

private slots:
    //void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::QualificationWindow *ui;
    Student* student;
    //void on_pushButton_ok_clicked();
    //void on_pushButton_cancel_clicked();

};
#endif // QUALIFICATIONWINDOW_H
