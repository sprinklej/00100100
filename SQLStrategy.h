#ifndef SQLSTRATEGY_H
#define SQLSTRATEGY_H

#include "User.h"


class SQLStorageStrategy{
public:
    virtual bool createQuery(bool, User*);

};

class InsertStudentStrategy : public SQLStorageStrategy{
public:
    bool createQuery(User*);
};

class UpdateStudentStrategy : public SQLStorageStrategy{
public:
    bool createQuery(User*);
};

class InsertAdminStrategy : public SQLStorageStrategy{
public:
    bool createQuery(User*);
};

class UpdateAdminStrategy : public SQLStorageStrategy{
public:
    bool createQuery(User*);
};



#endif // SQLSTRATEGY_H
