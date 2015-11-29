#ifndef SQLCONTEXT_H
#define SQLCONTEXT_H

#include "SQLStrategy.h"
#include "User.h"

class SQLContext{
public:
    SQLContext(QSqlDatabase&);
    User* user;
    SQLStorageStrategy* strat;
    bool query(bool, User*);


private:
    QSqlDatabase database;
};



#endif // SQLCONTEXT_H
