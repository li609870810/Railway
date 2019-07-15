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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ui_init();


    Log log;
    SerialPort *serialport;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void slot_SqlQuery(const QString &data);  //操作数据库
    void Analysis_400mFrame(const QByteArray& data);
    void Analysis_GMSRFrame(const QByteArray& data);


    void on_statistics_clicked();

private:
    Ui::MainWindow *ui;
    BarChart* barchart;
    DateTime *date;

    std::thread receiveThread;
    int ReceiveThread();
    void _400mAnswer(const QByteArray &data);  //400m应答
    void GMSRAnswer(const QByteArray &data);  //GMSR应答

signals:
    void signal_SqlQuery(const QString& data);
    void signal_400mAnalysis(const QByteArray& data);
    void signal_GMSRAnalysis(const QByteArray& data);
};

#endif // MAINWINDOW_H
