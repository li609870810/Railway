#include "userswitching.h"
#include "ui_userswitching.h"

UserSwitching::UserSwitching(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSwitching)
{
    ui->setupUi(this);

    w = (MainWindow *)parent;
    this->setWindowTitle(QString("当前用户: ") + w->getCurUserName());

}

UserSwitching::~UserSwitching()
{
    w = nullptr;
    delete w;
    delete ui;
}

void UserSwitching::on_pushButton_2_clicked()
{
    ui->label_3->setStyleSheet("color:rgb(250, 0, 0)");
    QSqlQuery sql_query;
    sql_query.prepare("select PASSWORD from UserInfo WHERE NAME = ?;");
    QString name = ui->lineEdit_user->text();
    sql_query.addBindValue(name);
    if(!sql_query.exec())
    {
        ui->label_3->setText("数据库查询出错。");
        return;
    }
    if(!sql_query.next())
    {
        ui->label_3->setText("用户名不存在。");
        return;
    }

    QString psw = sql_query.value(0).toString();
    if(psw == ui->lineEdit_psw->text())
    {
        w->setCurUserName(name);
        this->close();
    }else{
        ui->label_3->setText("密码错误。");
    }
}

void UserSwitching::on_pushButton_3_clicked()
{
    this->close();
}
