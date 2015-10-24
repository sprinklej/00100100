#include "studentwindow.h"
#include "ui_studentwindow.h"


StudentWindow::StudentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);

    // open window in middle of screen
    this->setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                this->size(),
                qApp->desktop()->availableGeometry()
                )
            );
}

StudentWindow::~StudentWindow()
{
    delete ui;
}
