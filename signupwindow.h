#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>
//#include "Storage.h"
#include "User.h"

class ManageRegistrationControl;


namespace Ui {
class SignupWindow;
}

class SignupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignupWindow(QWidget *parent = 0);
    ~SignupWindow();
    // setter
    void setParent(ManageRegistrationControl *);

private slots:
    void on_radioButton_student_clicked();

    void on_radioButton_admin_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

    void getQualifications(Student*);

private:
    Ui::SignupWindow *ui;
    ManageRegistrationControl * parent;
};

#endif // SIGNUPWINDOW_H
