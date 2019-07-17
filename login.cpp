#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    mysqlmodel = new MysqlModel;

}

Login::~Login()
{
    delete ui;
    delete mysqlmodel;
}

void Login::on_loginButton_clicked()
{
    if((ui->userlineEdit->text().size() <= 0) || (ui->pswlineEdit->text().size() <= 0))
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("请输入用户名和密码"));
        return;
    }

    QSqlQuery sql_query;
    QString insert_sql = "select PASSWORD from UserInfo WHERE NAME = ?;";
    sql_query.prepare(insert_sql);

    sql_query.addBindValue(ui->userlineEdit->text());

    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
        return;
    }else{
        if(sql_query.next())
        {
            QString psw = sql_query.value(0).toString();
            if(ui->pswlineEdit->text() == psw)
            {
                mysqlmodel->close();
                MainWindow* w = new MainWindow;
                w->init();
                w->setCurUserName(ui->userlineEdit->text());
                this->close();
                w->show();
            }else
            {
                QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("密码错误"));
            }
        }else{
            QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("用户名不存在。"));
            return;
        }
    }
}

void Login::on_exitButton_clicked()
{
    this->close();
}
