#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QWidget>
#include <QDesktopWidget>
#include"User.h"



namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();
    void setUser(Admin*);

private:
    Ui::AdminWindow *ui;
    Admin* user;
};

#endif // ADMINWINDOW_H
