//#include "mainwindow.h"
#include "loginwindow.h"
#include "StorageFacade.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //LoginWindow login;
    //login.show();

    StorageFacade facade = StorageFacade();
    facade.run();

    return a.exec();
}
