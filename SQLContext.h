#ifndef SQLCONTEXT_H
#define SQLCONTEXT_H

#include "SQLStrategy.h"
#include "User.h"

class SQLContext{
public:
    User* user;
    SQLStorageStrategy* strat;
    bool query(bool, User*);
};



#endif // SQLCONTEXT_H
