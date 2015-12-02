#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QWidget>
#include <QDesktopWidget>
#include <QList>
#include <QDebug>
#include "User.h"
#include "Project.h"

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
    void setAdmin(Admin* s);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminWindow *ui;
    Admin* user;
    QList<Project *> projectsOwned;

};

#endif // ADMINWINDOW_H
