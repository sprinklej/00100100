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
    virtual bool createQuery(User*) = 0;

protected:
    QSqlDatabase database;

};

class InsertStudentStrategy : public SQLStorageStrategy{
public:
    InsertStudentStrategy(QSqlDatabase&);
    bool createQuery(User*);
};

class UpdateStudentStrategy : public SQLStorageStrategy{
public:
    UpdateStudentStrategy(QSqlDatabase&);
    bool createQuery(User*);
};

class InsertAdminStrategy : public SQLStorageStrategy{
public:
    InsertAdminStrategy(QSqlDatabase&);
    bool createQuery(User*);
};

class UpdateAdminStrategy : public SQLStorageStrategy{
public:
    UpdateAdminStrategy(QSqlDatabase&);
    bool createQuery(User*);
};



#endif // SQLSTRATEGY_H
