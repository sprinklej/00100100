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

private:
    Ui::QualificationWindow *ui;
    Student* student;
};

#endif // QUALIFICATIONWINDOW_H
