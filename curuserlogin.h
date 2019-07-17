#ifndef CURUSERLOGIN_H
#define CURUSERLOGIN_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class CurUserLogin;
}

class CurUserLogin : public QDialog
{
    Q_OBJECT

public:
    explicit CurUserLogin(QWidget *parent = 0);
    ~CurUserLogin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CurUserLogin *ui;
    MainWindow *w;
};

#endif // CURUSERLOGIN_H
