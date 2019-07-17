#include "curuserlogin.h"
#include "ui_curuserlogin.h"

CurUserLogin::CurUserLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CurUserLogin)
{
    ui->setupUi(this);

    w = (MainWindow *)parent;
    this->setWindowTitle(QString("当前用户: ") + w->getCurUserName());
}

CurUserLogin::~CurUserLogin()
{
    w = nullptr;
    delete w;
    delete ui;
}

void CurUserLogin::on_pushButton_clicked()
{
    QString inputpsw = ui->lineEdit->text();
    if(inputpsw.size() == 0){ui->label->setText("密码不能为空，请重新输入。");}

    QSqlQuery sql_query;
    QString insert_sql = "select PASSWORD from UserInfo WHERE NAME = ?;";
    sql_query.prepare(insert_sql);

    sql_query.addBindValue(w->getCurUserName());

    if(!sql_query.exec())
    {

    }else{
        if(!sql_query.next())
        {
            ui->label->setText("用户名不存在");
        }else{
            QString psw = sql_query.value(0).toString();
            if(inputpsw == psw)
            {
                w->LoginOk = true;
                this->close();
                return;
            }else
            {
                ui->label->setText("密码错误，请重新输入。");
                return;
            }
        }
    }
}

void CurUserLogin::on_pushButton_2_clicked()
{
    this->close();
}
