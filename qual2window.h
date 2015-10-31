#ifndef QUAL2WINDOW_H
#define QUAL2WINDOW_H

#include <QDialog>
#include "User.h"

namespace Ui {
class Qual2Window;
}

class Qual2Window : public QDialog
{
    Q_OBJECT

public:
    explicit Qual2Window(QWidget *parent = 0);
    ~Qual2Window();
    void setStudent(Student*);

private:
    Ui::Qual2Window *ui;
    Student* student;
};

#endif // QUAL2WINDOW_H
