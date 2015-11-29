#include "SQLStrategy.h"


UpdateStudentStrategy::UpdateStudentStrategy(QSqlDatabase& db){
        database = db;
}

bool UpdateStudentStrategy::createQuery(User* u){

    Student* st = dynamic_cast<Student*>(u);

    database.open();
    QSqlQuery query;
    query.prepare("UPDATE users SET "
                  "fname = :fname,"
                  "lname = :lname,"
                  "att_leader = :att_leader"
                  "att_avail = :att_avail,"
                  "att_2404 = :att_2404,"
                  "att_3005 = :att_3005,"
                  "att_coding = :att_coding,"
                  "att_dbase = :att_dbase,"
                  "att_selfDir = :att_selfDir,"
                  "att_writing = :att_writing,"
                  "att_UI = :att_UI,"
                  "att_algorithm = :att_algorithm,"
                  "att_present = :att_present,"
                  "att_teamwork = :att_teamwork,"
                  "att_experience = :att_experience,"
                  "att_testing = :att_testing,"
                  "att_UML = :att_UML,"
                  "att_req = :att_req,"
                  "att_reliable = :att_reliable,"
                  "att_comm = :att_comm,"
                  "att_respect = :att_respect,"
                  "att_creative = :att_creative,"
                  "att_critic = :att_critic,"
                  "req_leader = :req_leader,"
                  "req_2404 = :req_2404,"
                  "req_3005 = :req_3005,"
                  "req_coding = :req_coding,"
                  "req_dbase = :req_dbase,"
                  "req_selfDir = :req_selfDir,"
                  "req_writing = :req_writing,"
                  "req_UI = :req_UI,"
                  "req_algorithm = :req_algorithm,"
                  "req_present= :req_present,"
                  "req_teamwork = :req_teamwork,"
                  "req_experience = :req_experience,"
                  "req_testing = :req_testing,"
                  "req_UML = :req_UML,"
                  "req_req = :req_req,"
                  "req_reliable = :req_reliable,"
                  "req_comm = :req_comm,"
                  "req_respect = :req_respect,"
                  "req_creative = :req_creative,"
                  "req_critic = :req_critic "
                  "WHERE id = :iid");

    query.bindValue(":fname", st->getFirstName());
    query.bindValue(":lname", st->getLastName());
    query.bindValue(":att_leader", st->getAtt_leader());
    query.bindValue(":att_avail", st->getAtt_avail());
    query.bindValue(":att_2404", st->getAtt_2404());
    query.bindValue(":att_3005", st->getAtt_3005());
    query.bindValue(":att_coding", st->getAtt_coding());
    query.bindValue(":att_dbase", st->getAtt_dbase());
    query.bindValue(":att_selfDir", st->getAtt_selfDir());
    query.bindValue(":att_writing", st->getAtt_writing());
    query.bindValue(":att_UI", st->getAtt_UI());
    query.bindValue(":att_algorithm", st->getAtt_algorithm());
    query.bindValue(":att_present", st->getAtt_present());
    query.bindValue(":att_teamwork", st->getAtt_teamwork());
    query.bindValue(":att_experience", st->getAtt_experience());
    query.bindValue(":att_testing", st->getAtt_testing());
    query.bindValue(":att_UML", st->getAtt_UML());
    query.bindValue(":att_req", st->getAtt_req());
    query.bindValue(":att_reliable", st->getAtt_reliable());
    query.bindValue(":att_comm", st->getAtt_comm());
    query.bindValue(":att_respect", st->getAtt_respect());
    query.bindValue(":att_creative", st->getAtt_creative());
    query.bindValue(":att_critic", st->getAtt_critic());
    query.bindValue(":req_leader", st->getReq_leader());
    query.bindValue(":req_2404", st->getReq_2404());
    query.bindValue(":req_3005", st->getReq_3005());
    query.bindValue(":req_coding", st->getReq_coding());
    query.bindValue(":req_dbase", st->getReq_dbase());
    query.bindValue(":req_selfDir", st->getReq_selfDir());
    query.bindValue(":req_writing", st->getReq_writing());
    query.bindValue(":req_UI", st->getReq_UI());
    query.bindValue(":req_algorithm", st->getReq_algorithm());
    query.bindValue(":req_present", st->getReq_present());
    query.bindValue(":req_teamwork", st->getReq_teamwork());
    query.bindValue(":req_experience", st->getReq_experience());
    query.bindValue(":req_testing", st->getReq_testing());
    query.bindValue(":req_UML", st->getReq_UML());
    query.bindValue(":req_req", st->getReq_req());
    query.bindValue(":req_reliable", st->getReq_reliable());
    query.bindValue(":req_comm", st->getReq_comm());
    query.bindValue(":req_respect", st->getReq_respect());
    query.bindValue(":req_creative", st->getReq_creative());
    query.bindValue(":req_critic",st->getReq_critic());
    query.bindValue(":iid", st->getIDNum());

    bool res = query.exec();
    qDebug() << query.lastError();
    return res;
}

InsertStudentStrategy::InsertStudentStrategy(QSqlDatabase& db){
    database = db;
}

bool InsertStudentStrategy::createQuery(User* u){
    Student* st = dynamic_cast<Student*>(u);

    database.open();
    QSqlQuery query;
    query.prepare("INSERT INTO users(id, fname, lname, att_leader, att_avail, att_2404, att_3005,"
                  "att_coding, att_dbase, att_selfDir, att_writing, att_UI, att_algorithm,"
                  "att_present, att_teamwork, att_experience, att_testing, att_UML,"
                  "att_req, att_reliable, att_comm, att_respect, att_creative, att_critic,"
                  "req_leader, req_2404, req_3005, req_coding, req_dbase, req_selfDir,"
                  "req_writing, req_UI, req_algorithm, req_present, req_teamwork,"
                  "req_experience, req_testing, req_UML, req_req, req_reliable,"
                  "req_comm, req_respect, req_creative, req_critic"
                  ") VALUES"
                  "(:id, :fname, :lname, :att_leader, :att_avail, :att_2404, :att_3005, "
                  ":att_coding, :att_dbase, :att_selfDir, :att_writing, :att_UI, :att_algorithm,"
                   ":att_present, :att_teamwork, :att_experience, :att_testing, :att_UML,"
                    ":att_req, :att_reliable, :att_comm, :att_respect, :att_creative, :att_critic,"
                   ":req_leader, :req_2404, :req_3005, :req_coding, :req_dbase, :req_selfDir,"
                   ":req_writing, :req_UI, :req_algorithm, :req_present, :req_teamwork,"
                   ":req_experience, :req_testing, :req_UML,:req_req, :req_reliable,"
                   ":req_comm, :req_respect, :req_creative, :req_critic )");

    query.bindValue(":id", st->getIDNum());
    query.bindValue(":fname", st->getFirstName());
    query.bindValue(":lname", st->getLastName());
    query.bindValue(":att_leader", st->getAtt_leader());
    query.bindValue(":att_avail", st->getAtt_avail());
    query.bindValue(":att_2404", st->getAtt_2404());
    query.bindValue(":att_3005", st->getAtt_3005());
    query.bindValue(":att_coding", st->getAtt_coding());
    query.bindValue(":att_dbase", st->getAtt_dbase());
    query.bindValue(":att_selfDir", st->getAtt_selfDir());
    query.bindValue(":att_writing", st->getAtt_writing());
    query.bindValue(":att_UI", st->getAtt_UI());
    query.bindValue(":att_algorithm", st->getAtt_algorithm());
    query.bindValue(":att_present", st->getAtt_present());
    query.bindValue(":att_teamwork", st->getAtt_teamwork());
    query.bindValue(":att_experience", st->getAtt_experience());
    query.bindValue(":att_testing", st->getAtt_testing());
    query.bindValue(":att_UML", st->getAtt_UML());
    query.bindValue(":att_req", st->getAtt_req());
    query.bindValue(":att_reliable", st->getAtt_reliable());
    query.bindValue(":att_comm", st->getAtt_comm());
    query.bindValue(":att_respect", st->getAtt_respect());
    query.bindValue(":att_creative", st->getAtt_creative());
    query.bindValue(":att_critic", st->getAtt_critic());
    query.bindValue(":req_leader", st->getReq_leader());
    query.bindValue(":req_2404", st->getReq_2404());
    query.bindValue(":req_3005", st->getReq_3005());
    query.bindValue(":req_coding", st->getReq_coding());
    query.bindValue(":req_dbase", st->getReq_dbase());
    query.bindValue(":req_selfDir", st->getReq_selfDir());
    query.bindValue(":req_writing", st->getReq_writing());
    query.bindValue(":req_UI", st->getReq_UI());
    query.bindValue(":req_algorithm", st->getReq_algorithm());
    query.bindValue(":req_present", st->getReq_present());
    query.bindValue(":req_teamwork", st->getReq_teamwork());
    query.bindValue(":req_experience", st->getReq_experience());
    query.bindValue(":req_testing", st->getReq_testing());
    query.bindValue(":req_UML", st->getReq_UML());
    query.bindValue(":req_req", st->getReq_req());
    query.bindValue(":req_reliable", st->getReq_reliable());
    query.bindValue(":req_comm", st->getReq_comm());
    query.bindValue(":req_respect", st->getReq_respect());
    query.bindValue(":req_creative", st->getReq_creative());
    query.bindValue(":req_critic",st->getReq_critic());

    bool res = query.exec();
    return res;
}

UpdateAdminStrategy::UpdateAdminStrategy(QSqlDatabase& db){
        database = db;
}

bool UpdateAdminStrategy::createQuery(User* u){
    Admin* ad = dynamic_cast<Admin*>(u);

    database.open();
    QSqlQuery query;
    query.prepare("INSERT INTO users(id, fname, lname) VALUES (:iid, :ifn, :iln)");
    query.bindValue(":iid", ad->getIDNum());
    query.bindValue(":ifn", ad->getFirstName());
    query.bindValue(":iln", ad->getLastName());
    bool res = query.exec();

    return res;
}

InsertAdminStrategy::InsertAdminStrategy(QSqlDatabase& db){
        database = db;
}

//not written yet
bool InsertAdminStrategy::createQuery(User* u){
    Admin* a = dynamic_cast<Admin*>(u);

    //qDebug() << "Insert admin";
    return false;
}
