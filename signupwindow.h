#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>

namespace Ui {
class SignupWindow;
}

class SignupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignupWindow(QWidget *parent = 0);
    ~SignupWindow();

private:
    Ui::SignupWindow *ui;
};

#endif // SIGNUPWINDOW_H
