#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QWidget>
#include <QDesktopWidget>
#include <QList>
#include <QDebug>
#include "User.h"

class ManageAdminControl;

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();
    void refresh();
    void setAdmin(Admin* a);
    void setManAdmContrl(ManageAdminControl* mac);
    void addToProjectsBox(QString);

    // project tab
    void setTitle(QString);
    void clearProjectBox();

private slots:
    void on_pushButton_EProj_clicked();

    void on_pushButton_NProj_clicked();

    void on_pushButton_logout1_clicked();

    void on_pushButton_logout2_clicked();

    void on_pushButton_PPID_clicked();

private:
    Ui::AdminWindow *ui;
    Admin* user;
    ManageAdminControl *manAddControl;
    QList<Project *> projectsOwned;

};

#endif // ADMINWINDOW_H
