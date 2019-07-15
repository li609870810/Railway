#ifndef BARCHART_H
#define BARCHART_H

#include <QMainWindow>

namespace Ui {
class BarChart;
}

class BarChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit BarChart(QWidget *parent = 0);
    ~BarChart();

private:
    Ui::BarChart *ui;
};

#endif // BARCHART_H
