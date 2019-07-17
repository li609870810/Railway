#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QDialog>
#include "mainwindow.h"
#include<QStandardItemModel>
#include<QSqlQueryModel>
namespace Ui {
class UserManagement;
}

class UserManagement : public QDialog
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = 0);
    ~UserManagement();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::UserManagement *ui;
    MainWindow *w;
    QStandardItemModel *model;
};

#endif // USERMANAGEMENT_H
