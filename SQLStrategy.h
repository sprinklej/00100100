#ifndef SQLSTRATEGY_H
#define SQLSTRATEGY_H

#include "User.h"
#include "QSqlQuery"
#include <QVariant>
#include "QDebug"
#include <QSqlError>


//#include "QDebug"


class SQLStorageStrategy{
public:
    virtual bool createQuery(bool, User*);

};

class InsertStudentStrategy : public SQLStorageStrategy{
public:
    InsertStudentStrategy();
    bool createQuery(User*);
};

class UpdateStudentStrategy : public SQLStorageStrategy{
public:
    UpdateStudentStrategy();
    bool createQuery(User*);
};

class InsertAdminStrategy : public SQLStorageStrategy{
public:
    InsertAdminStrategy();
    bool createQuery(User*);
};

class UpdateAdminStrategy : public SQLStorageStrategy{
public:
    UpdateAdminStrategy();
    bool createQuery(User*);
};



#endif // SQLSTRATEGY_H
