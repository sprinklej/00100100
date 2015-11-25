#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QWidget>
#include <QDesktopWidget>
#include "User.h"
#include "Project.h"

#include "managestudentcontrol.h"
//class ManageStudentControl;


namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = 0);
    ~StudentWindow();
    //void setUser(Student*);
    void setUser();
    void refresh();
    void showUserInfo();
    QString codingString(int num);
    QString experienceString(int num);
    QString agreeString(int num);

    // set student
    void setStudent(Student*);

    // status at bottom of projects tab
    void setStatus2(QString string);

private slots:
    //void on_pushButton_5_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_manQual_clicked();

    void on_pushButton_joinProject_clicked();

private:
    Ui::StudentWindow *ui;
    Student* user;
    QList<Project*> allProjects;
    QList<Project*> joinedProjects;
};

#endif // STUDENTWINDOW_H
