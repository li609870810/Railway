#ifndef BARCHART_H
#define BARCHART_H

#include <QMainWindow>
#include<QLineEdit>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QHorizontalBarSeries>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class BarChart;
}

class BarChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit BarChart(QWidget *parent = 0);
    ~BarChart();
private slots:
    void getdate();
private:
    Ui::BarChart *ui;
    QLineEdit *date;
    QBarSet *set0;
    QBarSet *set1;
    QBarSet *set2;
};

#endif // BARCHART_H
