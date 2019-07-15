/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *picturelabel;
    QPushButton *loginButton;
    QPushButton *exitButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *userlineEdit;
    QLabel *label_3;
    QLineEdit *pswlineEdit;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 300);
        picturelabel = new QLabel(Login);
        picturelabel->setObjectName(QStringLiteral("picturelabel"));
        picturelabel->setGeometry(QRect(0, 0, 401, 171));
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(80, 270, 75, 23));
        exitButton = new QPushButton(Login);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(210, 270, 75, 23));
        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(91, 191, 189, 48));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        userlineEdit = new QLineEdit(layoutWidget);
        userlineEdit->setObjectName(QStringLiteral("userlineEdit"));
        userlineEdit->setEnabled(true);
        userlineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        userlineEdit->setReadOnly(false);
        userlineEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(userlineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        pswlineEdit = new QLineEdit(layoutWidget);
        pswlineEdit->setObjectName(QStringLiteral("pswlineEdit"));
        pswlineEdit->setEnabled(true);
        pswlineEdit->setLayoutDirection(Qt::LeftToRight);
        pswlineEdit->setEchoMode(QLineEdit::Password);
        pswlineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pswlineEdit->setReadOnly(false);

        gridLayout->addWidget(pswlineEdit, 1, 1, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", Q_NULLPTR));
        picturelabel->setText(QString());
        loginButton->setText(QApplication::translate("Login", "\347\231\273\351\231\206", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Login", "\351\200\200\345\207\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        userlineEdit->setInputMask(QString());
        userlineEdit->setText(QString());
        label_3->setText(QApplication::translate("Login", "  \345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pswlineEdit->setInputMask(QString());
        pswlineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
