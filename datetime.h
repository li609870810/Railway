#ifndef DATETIME_H
#define DATETIME_H

#include <QDialog>

namespace Ui {
class DateTime;
}

class DateTime : public QDialog
{
    Q_OBJECT

public:
    explicit DateTime(QWidget *parent = 0);
    ~DateTime();

private slots:
    void on_pushButton_clicked();
signals:
    void selectTime(const QString& str);
private:
    Ui::DateTime *ui;
};

#endif // DATETIME_H
