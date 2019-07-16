#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include "mainwindow.h"
//#include "mysqlmodel.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    MainWindow* w = new MainWindow;

    QSqlQuery sql_query;
    QString insert_sql = "select PASSWORD from UserInfo WHERE NAME = ?;";
    sql_query.prepare(insert_sql);

    sql_query.addBindValue(ui->userlineEdit->text());

    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("用户名不存在"));

    }else{
        while(sql_query.next())
        {
            QString psw = sql_query.value(0).toString();
            if(ui->pswlineEdit->text() == psw)
            {

                w->show();
                this->close();
            }else
            {
                QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("密码错误"));
            }
        }
    }
}

void Login::on_exitButton_clicked()
{
    this->close();
}
