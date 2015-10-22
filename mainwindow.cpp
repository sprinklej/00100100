#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStyle>
#include <QDesktopWidget>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                this->size(),
                qApp->desktop()->availableGeometry()
                )
            );

}

MainWindow::~MainWindow()
{
    delete ui;
}
