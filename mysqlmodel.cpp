#include "mysqlmodel.h"
#include<QSqlError>
MysqlModel::MysqlModel()
{
    //建立并打开数据库
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("Railway.db");
    database.setUserName("root");
    database.setPassword("sql2019");

    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug() << "Succeed to connect database." ;
    }

    /*"CREATE TABLE UserInfo(\
            NAME TEXT PRIMARY KEY   NOT NULL,\
            PASSWORD   CHAR(20)     NOT NULL\
         );
    */

    /*QSqlQuery sql_query;
    QString insert_sql = "INSERT INTO UserInfo VALUES ('admin','admin');";
    sql_query.prepare(insert_sql);

    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "inserted Wang!";
    }*/
}
void MysqlModel::close()
{
    database.close();
}

