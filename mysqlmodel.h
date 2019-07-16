#ifndef MYSQLMODEL_H
#define MYSQLMODEL_H

#include <QObject>

#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include"log.h"
class MysqlModel : public QObject
{
    Q_OBJECT
public:
    MysqlModel();
    MysqlModel(const MysqlModel&) = delete;  //阻止拷贝
    MysqlModel & operator = (const MysqlModel&) = delete; //阻止赋值

    bool SqlRequest(const QString& request, QSqlQuery &sql_query);
private:
    QString hostName;
    QString dbName;
    QString userName;
    QString password;
    QSqlDatabase dbconn;
    Log log;
};

#endif // MYSQLMODEL_H
