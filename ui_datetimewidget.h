/********************************************************************************
** Form generated from reading UI file 'datetimewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATETIMEWIDGET_H
#define UI_DATETIMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateTimeWidget
{
public:
    QWidget *dockWidgetContents;
    QDateEdit *dateEdit;

    void setupUi(QDockWidget *DateTimeWidget)
    {
        if (DateTimeWidget->objectName().isEmpty())
            DateTimeWidget->setObjectName(QStringLiteral("DateTimeWidget"));
        DateTimeWidget->resize(145, 79);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dateEdit = new QDateEdit(dockWidgetContents);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(10, 10, 131, 31));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        dateEdit->setFont(font);
        dateEdit->setCurrentSection(QDateTimeEdit::YearSection);
        dateEdit->setCalendarPopup(true);
        DateTimeWidget->setWidget(dockWidgetContents);

        retranslateUi(DateTimeWidget);

        QMetaObject::connectSlotsByName(DateTimeWidget);
    } // setupUi

    void retranslateUi(QDockWidget *DateTimeWidget)
    {
        DateTimeWidget->setWindowTitle(QApplication::translate("DateTimeWidget", "DockWidget", Q_NULLPTR));
        dateEdit->setDisplayFormat(QApplication::translate("DateTimeWidget", "yyyy-M-d", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DateTimeWidget: public Ui_DateTimeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATETIMEWIDGET_H
