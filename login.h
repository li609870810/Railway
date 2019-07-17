#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"mysqlmodel.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_loginButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Login *ui;
    MysqlModel *mysqlmodel;
};

#endif // LOGIN_H
