#include "log.h"

Log::Log()
{

}
void Log::writelog(const QString& log)
{
    QFile file("Log.txt");

    file.open(QIODevice::Append | QIODevice::Text);
    /*if(!file.isOpen())
    {
        //QFile *file = new QFile(Logpath);
        file.open(QIODevice::Append | QIODevice::Text );
    }*/


    QDateTime time =QDateTime::currentDateTime();
    QString timestr;
    timestr.sprintf("      %d-%d-%d  %d:%d:%d",time.date().year(),time.date().month(),\
                    time.date().day(),time.time().hour(),time.time().minute(),time.time().second());

    QTextStream in(&file);

    in << log << timestr << "\r\n\r\n";

    file.flush();

    file.close();
}
