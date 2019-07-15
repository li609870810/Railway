#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLibrary>
#include<QVBoxLayout>
#include<windows.h>
#include<QStandardItemModel>
#include<qDebug>



//在注册表该目录下增加新内容
#define TASKMANAGERSystem "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
#define TASKMANAGERExplorer "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"

HHOOK keyHook = NULL;
HHOOK mouseHook = NULL;
void hook(bool flag); //功能键
void showTaskWindow(bool flag); //显示任务栏
void enableTaskManager(bool flag); //任务管理器

//键盘钩子过程
LRESULT CALLBACK keyProc(int nCode,WPARAM wParam,LPARAM lParam )
{
    //在WH_KEYBOARD_LL模式下lParam 是指向KBDLLHOOKSTRUCT类型地址
    KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *) lParam;
    //如果nCode等于HC_ACTION则处理该消息，如果小于0，则钩子子程就必须将该消息传递给 CallNextHookEx
    if(nCode == HC_ACTION)
    {
        if((pkbhs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL)& 0x8000 && GetAsyncKeyState(VK_SHIFT)&0x8000)|| //"Ctrl+Shift+Esc"
            (pkbhs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL) & 0x8000) || //"Ctrl+Esc"
            //(pkbhs->vkCode == VK_TAB && pkbhs->flags & LLKHF_ALTDOWN )|| //"Alt+Tab"
            (pkbhs->vkCode == VK_ESCAPE && pkbhs->flags &LLKHF_ALTDOWN )|| //"Alt+Esc"
            (pkbhs->vkCode == VK_LWIN || pkbhs->vkCode == VK_RWIN )||	// "LWIN/RWIN"
            (pkbhs->vkCode == VK_F4 && pkbhs->flags & LLKHF_ALTDOWN )) //"Alt+F4"
        {
            return 1;//返回1表示截取消息不再传递,返回0表示不作处理,消息继续传递
        }

        // 		if(pkbhs->vkCode == VK_F12)
        // 		{
        // 			void unHook();
        // 			qApp->quit();
        // 		}
    }
    return CallNextHookEx(keyHook, nCode, wParam, lParam);
}

//安装钩子,调用该函数即安装钩子
void hook(bool flag)
{
    if (flag)
    {
        //这两个底层钩子,不要DLL就可以全局
        //底层键盘钩子
        keyHook =SetWindowsHookEx( WH_KEYBOARD_LL,keyProc,GetModuleHandle(NULL),0);
        //底层鼠标钩子
        //    mouseHook =SetWindowsHookEx( WH_MOUSE_LL,mouseProc,GetModuleHandle(NULL),0);
    }
    else
    {
        UnhookWindowsHookEx(keyHook);
        //  UnhookWindowsHookEx(mouseHook);
    }
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRect rect0;

    rect0 = geometry();//记录widget位置，恢复时使用

    setWindowFlags(Qt::Window);

    showFullScreen();

    hook(true);
    serialport = new SerialPort(this);
    connect(serialport, SIGNAL(recv_signal(QByteArray)), this, SLOT(analysis(QByteArray)));
    barchart = new BarChart(this);

    date = new DateTime(this);
    connect(date,SIGNAL(selectTime(QString)),this,SLOT(Queryfile(QString)));


    connect(ui->menu_setcom, SIGNAL(triggered()), this, SLOT(on_setcom_clicked()));
    connect(ui->menu_statistics, SIGNAL(triggered()), this, SLOT(on_statistics_clicked()));


    ui_init();//ui设置
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}


void MainWindow::ui_init()
{
    QString ButtonStyle =
            //正常状态样式
            "QPushButton{"
                "color:rgb(233, 236, 243);"
                "border-style:solid;"
                "border-top-left-radius:2px;"
                "border-top-right-radius:2px;"
                "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241), \
                                            stop: 0.3 rgb(33,184,150),  \
                                              stop: 1 rgb(29,170,140));"
                "border:2px;"
                "border-radius:5px;padding:2px 4px;"/*border-radius控制圆角大小*/
                "}"
            //鼠标按下样式
            "QPushButton:pressed{"
                "color:rgb(233, 236, 243);"
                "border-style:solid;"
                "border-top-left-radius:2px;"
                "border-top-right-radius:2px;"
                "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),  \
                                            stop: 0.3 rgb(38,190,255),  \
                                              stop: 1 rgb(33,184,240));"
                "border:1px;"
                "border-radius:5px;padding:2px 4px;"
                "}"
            //鼠标悬停样式
            "QPushButton:hover{"
            "color:rgb(233, 236, 243);"
                "border-style:solid;"
                "border-top-left-radius:2px;"
                "border-top-right-radius:2px;"
                "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),  \
                                            stop: 0.3 rgb(37,189,252),  \
                                              stop: 1 rgb(32,170,240));"
                "border:1px;"
                "border-radius:5px;padding:2px 4px;"
            "};";

    ui->pushButton->setStyleSheet(ButtonStyle);

    ui->pushButton_2->setStyleSheet(ButtonStyle);

    ui->pushButton_3->setStyleSheet(ButtonStyle);


    //准备数据模型
    QStandardItemModel *student_model = new QStandardItemModel();
    student_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Name")));
    student_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("NO.")));
    student_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Sex")));
    student_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Age")));
    student_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("College")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->tableView->setModel(student_model);
    //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
    ui->tableView->verticalHeader()->hide();
    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);




    //在第一行添加学生张三的个人信息(setItem函数的第一个参数表示行号，第二个表示列号，第三个为要显示的数据)
    student_model->setItem(0, 0, new QStandardItem("张三"));
    student_model->setItem(0, 1, new QStandardItem("20120202"));
    student_model->setItem(0, 2, new QStandardItem("男"));
    student_model->setItem(0, 3, new QStandardItem("18"));
    student_model->setItem(0, 4, new QStandardItem("土木学院"));
    //student_model->item(0, 4)->setBackground(QBrush(QColor(255, 0, 0)));

    //设置单元格文本居中，张三的数据设置为居中显示
    student_model->item(0, 0)->setTextAlignment(Qt::AlignCenter);
    student_model->item(0, 1)->setTextAlignment(Qt::AlignCenter);
    student_model->item(0, 2)->setTextAlignment(Qt::AlignCenter);
    student_model->item(0, 3)->setTextAlignment(Qt::AlignCenter);
    student_model->item(0, 4)->setTextAlignment(Qt::AlignCenter);

    //设置单元格文本颜色，张三的数据设置为红色
    student_model->item(0, 0)->setForeground(QBrush(QColor(255, 0, 0)));
    //将字体加粗
    student_model->item(0, 0)->setFont( QFont( "Times", 10, QFont::Black ));


}


void MainWindow::on_pushButton_2_clicked()
{

    date->show();
}

void MainWindow::Queryfile(const QString &date)
{
   /* const char* str = "我";
    QByteArray str1;
    str1.append(str[0]);
    str1.append(str[1]);
    serialport->Write(str1);

    qDebug()<<(str1[0]<<8+str1[1]);*/

}
void MainWindow::analysis(const QByteArray &content)
{
    //解析
    //存储
    //显示
}

void MainWindow::on_pushButton_3_clicked()
{
    //
    if(serialport->Start("com2"))
    {
        log.writelog("L串口打开失败，串口已被打开或占用。");
    }
}
void MainWindow::on_setcom_clicked()
{

}
void MainWindow::on_statistics_clicked()
{
    barchart->show();
}