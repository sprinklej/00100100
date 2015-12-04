#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QWidget>
#include <QDesktopWidget>
#include "User.h"
//#include "Project.h"

class ManageStudentControl;


namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = 0);
    ~StudentWindow();
    void refresh();

    // setters
    void setStudent(Student*);
    void setManStudContrl(ManageStudentControl*);

    // set statuses
    void setStatus2(QString string); // status at bottom of projects tab
    void setAllProjListWidget(QString string);
    void setJoinedProjListWidget(QString string);
    void showUserInfo();
    // showUserInfo helpers
    QString codingString(int num);
    QString experienceString(int num);
    QString agreeString(int num);
    void clearLists();

private slots:
    void on_pushButton_manQual_clicked();
    void on_pushButton_joinProject_clicked();

    void on_pushButton_Logout1_clicked();

    void on_pushButton_Logout2_clicked();

private:
    Ui::StudentWindow *ui;
    Student* user;
    ManageStudentControl *manStudControl;
};

#endif // STUDENTWINDOW_H
