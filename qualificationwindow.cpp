#include "qualificationwindow.h"
#include "ui_qualificationwindow.h"

QualificationWindow::QualificationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QualificationWindow)
{
    ui->setupUi(this);
}

QualificationWindow::~QualificationWindow()
{
    delete ui;
}

void QualificationWindow::setStudent(Student* st){
    student = st;
}
