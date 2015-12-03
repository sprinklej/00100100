//#include "mainwindow.h"
#include "loginwindow.h"
#include "StorageFacade.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // launch the storage facade which controls the whole system
    StorageFacade facade = StorageFacade();
    facade.run();

    // this is the test part
    //test student creation
 /*   Student* testStud = new Student("Bob", "Jones","100100100", true, "TTTTTTTTTTTTTTTTTTTTT", 1,
                                   1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,false,1,1,1,1,
                                   1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 1, 1, 1,1, 1,1);

*/
//    facade.writeUser(testStud);

    //log in
 //   facade.handleLogin("100100100");

    //check
//   User* u = facade.getLoggedInUser();
//qDebug() << u->getID();
//qDebug() << "Works up to here";
//works up to here

    return a.exec();
}
