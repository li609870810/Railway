#include "datetime.h"
#include "ui_datetime.h"

DateTime::DateTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateTime)
{
    ui->setupUi(this);
    //p = (MainWindow*)parent;
    QDateTime current_date_time =QDateTime::currentDateTime();
    ui->dateEdit->setDate(QDate(current_date_time.date()));
}

DateTime::~DateTime()
{
    delete ui;
}

void DateTime::on_pushButton_clicked()
{
    QString str;
    str.sprintf(":/data/%d-%d-%d",ui->dateEdit->date().year(),ui->dateEdit->date().month(),ui->dateEdit->date().day());
    emit selectTime(str);
    //p->Queryfile(str);
    this->close();
}

