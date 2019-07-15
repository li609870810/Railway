#include <QtGlobal>
#if QT_VERSION >= 0x050000
#include <QApplication>
#else
#include <QtGui/QApplication>
#endif

#include <QTextCodec>
#include"login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if QT_VERSION < 0x050000
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
#endif

    Login login;
    login.show();
    //MainWindow w;
    //w.show();
    return a.exec();
}
