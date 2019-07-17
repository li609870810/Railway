#include "usermanagement.h"
#include "ui_usermanagement.h"
#include<QMessageBox>

UserManagement::UserManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);

    w = (MainWindow *)parent;

    this->setWindowTitle(QString("当前用户: ") + w->getCurUserName());

    model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("用户名")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("密码")));

    //在第一行添加个人信息(setItem函数的第一个参数表示行号，第二个表示列号，第三个为要显示的数据)
    //model->setItem(0, 0, new QStandardItem(w->CurUserName));
    //model->setItem(0, 1, new QStandardItem(w->CurUserName));

    //设置单元格文本居中，数据设置为居中显示
    //model->item(0, 0)->setTextAlignment(Qt::AlignCenter);
    //model->item(0, 1)->setTextAlignment(Qt::AlignCenter);

    //利用setModel()方法将数据模型与QTableView绑定
    ui->tableView->setModel(model);


    //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
    ui->tableView->verticalHeader()->hide();
    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    //ui->tableView->verticalHeader()->hide();//不显示序号
    QSqlQuery sql_query;

    if(w->getCurUserName() == "admin")
    {
        ui->lineEdit_user->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_3->setEnabled(true);

        QString insert_sql = "select * from UserInfo;";
        sql_query.prepare(insert_sql);

        if(!sql_query.exec())
        {
            qDebug() << sql_query.lastError();
        }else{
            int i = 0;
            while(sql_query.next())
            {
                QString name = sql_query.value(0).toString();
                QString psw = sql_query.value(1).toString();
                model->setItem(i, 0, new QStandardItem(name));
                model->setItem(i, 1, new QStandardItem(psw));
                i++;
            }
        }
    }else{

        ui->lineEdit_user->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_3->setEnabled(false);

        sql_query.prepare("select PASSWORD from UserInfo WHERE NAME = ?;");
        sql_query.addBindValue(w->getCurUserName());
        if(sql_query.exec())
        {
            if(sql_query.next())
            {
                QString psw = sql_query.value(0).toString();
                model->setItem(0, 0, new QStandardItem(w->getCurUserName()));
                model->setItem(0, 1, new QStandardItem(psw));
            }
        }
    }
}

UserManagement::~UserManagement()
{
    delete ui;
    w = nullptr;
    delete w;
    delete model;
}

void UserManagement::on_tableView_clicked(const QModelIndex &index)
{
    QString name = model->item(index.row(),0)->text();
    ui->lineEdit_user->setText(name);
}

void UserManagement::on_pushButton_clicked()
{
    if((ui->lineEdit_user->text().size() <= 0) || (ui->lineEdit_psw->text().size() <= 0))
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("请输入用户名和密码。"));
        return;
    }
    QString name = ui->lineEdit_user->text();
    QSqlQuery sql_query;

    sql_query.prepare("insert into UserInfo values (?,?)");
    sql_query.addBindValue(name);
    sql_query.addBindValue(ui->lineEdit_psw->text());
    if(!sql_query.exec())
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("该用户名已存在。"));
        return;
    }

    int len = model->rowCount();
    model->setItem(len, 0, new QStandardItem(name));
    model->setItem(len, 1, new QStandardItem(ui->lineEdit_psw->text()));
}

void UserManagement::on_pushButton_2_clicked()  //修改密码
{
    if((ui->lineEdit_user->text().size() <= 0) || (ui->lineEdit_psw->text().size() <= 0))
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("请输入用户名和密码。"));
        return;
    }
    QString name = ui->lineEdit_user->text();
    QSqlQuery sql_query;

    sql_query.prepare("update UserInfo set PASSWORD = :PASSWORD where NAME = :NAME");
    sql_query.bindValue(":PASSWORD", ui->lineEdit_psw->text());
    sql_query.bindValue(":NAME", name);
    if(!sql_query.exec())
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("该用户名不存在。"));
        return;
    }

    QList<QStandardItem *> tList = model->findItems(name);
    QStandardItem* tItem = tList.at(0);


    model->item(tItem->row(),1)->setText(ui->lineEdit_psw->text());
    //设置单元格文本颜色，数据设置为红色
    model->item(tItem->row(),1)->setForeground(QBrush(QColor(255, 0, 0)));
}

void UserManagement::on_pushButton_3_clicked()
{
    if((ui->lineEdit_user->text().size() <= 0) || (ui->lineEdit_psw->text().size() <= 0))
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("请输入用户名和密码。"));
        return;
    }
    QString name = ui->lineEdit_user->text();
    QSqlQuery sql_query;

    sql_query.prepare("select NAME from UserInfo");
    if(!sql_query.exec()){return;}
    if(!sql_query.next())
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("该用户名不存在。"));
        return;
    }

    sql_query.prepare("delete from UserInfo where NAME = ?");
    sql_query.addBindValue(name);
    if(!sql_query.exec())
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("删除失败。"));
        return;
    }else{
        QList<QStandardItem *> tList = model->findItems(name);
        if(tList.size() > 0)
        {
            QStandardItem* tItem = tList.at(0);
            model->removeRow(tItem->row());
        }else
        {
            QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("该用户名不存在。"));
        }
    }
}
