#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QWidget>
#include <QDesktopWidget>
#include "User.h"


namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = 0);
    ~StudentWindow();
    void setUser(Student*);

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentWindow *ui;
    Student* user;
};

#endif // STUDENTWINDOW_H
