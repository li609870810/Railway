#ifndef USERSWITCHING_H
#define USERSWITCHING_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class UserSwitching;
}

class UserSwitching : public QDialog
{
    Q_OBJECT

public:
    explicit UserSwitching(QWidget *parent = 0);
    ~UserSwitching();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::UserSwitching *ui;
    MainWindow *w;
};

#endif // USERSWITCHING_H
