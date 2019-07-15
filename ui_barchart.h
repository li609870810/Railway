/********************************************************************************
** Form generated from reading UI file 'barchart.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCHART_H
#define UI_BARCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BarChart
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *BarChart)
    {
        if (BarChart->objectName().isEmpty())
            BarChart->setObjectName(QStringLiteral("BarChart"));
        BarChart->resize(1085, 465);
        centralwidget = new QWidget(BarChart);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        BarChart->setCentralWidget(centralwidget);

        retranslateUi(BarChart);

        QMetaObject::connectSlotsByName(BarChart);
    } // setupUi

    void retranslateUi(QMainWindow *BarChart)
    {
        BarChart->setWindowTitle(QApplication::translate("BarChart", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BarChart: public Ui_BarChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCHART_H
