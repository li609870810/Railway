#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"log.h"
#include"serialport.h"
#include"barchart.h"
#include "datetime.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ui_init();


    Log log;
    SerialPort *serialport;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void analysis(const QByteArray& content);
    void Queryfile(const QString &date);
    void on_pushButton_3_clicked();
    void on_setcom_clicked();
    void on_statistics_clicked();

private:
    Ui::MainWindow *ui;
    BarChart* barchart;
    DateTime *date;
};

#endif // MAINWINDOW_H
