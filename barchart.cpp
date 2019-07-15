#include "barchart.h"
#include "ui_barchart.h"



#include<QDateTime>
#include<QPushButton>


BarChart::BarChart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BarChart)
{
    ui->setupUi(this);

    //connect(date,SIGNAL(selectTime(QString)),this,SLOT(getdate(QString)));


    //date->show();
    //![1]
       set0 = new QBarSet("通过");
       set1 = new QBarSet("不通过");
       set2 = new QBarSet("未知");
        //QBarSet *set3 = new QBarSet("Mary");
        //QBarSet *set4 = new QBarSet("Samantha");

        *set0 << 5 << 10 << 15 << 20 << 50 << 20;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
        //*set3 << 5 << 6 << 7 << 3 << 4 << 5;
        //*set4 << 9 << 7 << 5 << 3 << 1 << 2;
    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->setBarWidth(0.7);
        series->setLabelsPosition(QAbstractBarSeries::LabelsInsideBase); // 设置数据系列标签的位置于数据柱内测上方
        series->setLabelsVisible(true); // 设置显示数据系列标签
        series->append(set0);
        series->append(set1);
        series->append(set2);
        //series->append(set3);
        //series->append(set4);
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("按日期统计");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        //chart->setFont(5);
    //![3]

    //![4]
    //!
     QStringList categories;
        categories << "一月" << "二月" << "三月" << "四月" << "五月" << "六月"\
                   <<"七月"<<"八月"<<"九月"<<"十月"<<"十一月"<<"十二月";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
        //chart->setAxisX(axis, series);//设置坐标轴
        /*QStringList categories;
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->setAxisX(axisX, series);

        QValueAxis *axisY = new QValueAxis();
        chart->setAxisY(axisY, series);
        axisY->applyNiceNumbers();//设置坐标轴*/
    //![4]

    //![5]
        chart->legend()->setVisible(true);//设置图例为显示状态
        chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]

    chartView->setAttribute(Qt::WA_TransparentForMouseEvents,true);//设置为下层图层
    this->setCentralWidget(chartView);

    date = new QLineEdit(this);
    date->setGeometry(QRect(this->width()/2+50,20,50,25));
    //date->setValidator(new QIntValidator(1,5000,this));
    QDateTime current_date_time =QDateTime::currentDateTime();

    date->setText(current_date_time.date().toString("yyyy"));
    QPushButton *select = new QPushButton(this);
    select->setGeometry(QRect(date->x()+60,20,30,25));
    select->setText("查询");

    connect(select, SIGNAL(clicked()), this, SLOT(getdate()));

}

BarChart::~BarChart()
{
    delete ui;
}
void BarChart::getdate()
{
    QString datestr = date->text();
    set0->replace(0,200);
}
