#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include "mainwindow.h"

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
    //if((ui->userlineEdit->text() == "admin") && (ui->pswlineEdit->text() == "admin"))
    //{
            MainWindow *w = new MainWindow(this);
            w->hide();
            this->close();
            w->show();
    //}
   // else{
    //    QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("用户名或密码错误"));
    //}
}

void Login::on_exitButton_clicked()
{
    this->close();
}
