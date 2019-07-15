/********************************************************************************
** Form generated from reading UI file 'datetime.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATETIME_H
#define UI_DATETIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DateTime
{
public:
    QDateEdit *dateEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *DateTime)
    {
        if (DateTime->objectName().isEmpty())
            DateTime->setObjectName(QStringLiteral("DateTime"));
        DateTime->resize(229, 118);
        dateEdit = new QDateEdit(DateTime);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(60, 10, 110, 22));
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setReadOnly(false);
        dateEdit->setCalendarPopup(true);
        pushButton = new QPushButton(DateTime);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 60, 75, 31));

        retranslateUi(DateTime);

        QMetaObject::connectSlotsByName(DateTime);
    } // setupUi

    void retranslateUi(QDialog *DateTime)
    {
        DateTime->setWindowTitle(QApplication::translate("DateTime", "Dialog", Q_NULLPTR));
        dateEdit->setDisplayFormat(QApplication::translate("DateTime", "yyyy/M/d", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DateTime", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DateTime: public Ui_DateTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATETIME_H
