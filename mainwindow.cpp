#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLibrary>
#include<QVBoxLayout>
#include<windows.h>
#include<QStandardItemModel>
#include<qDebug>
#include"typedef.h"


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
    serialport = new SerialPort;
    barchart = new BarChart(this);
    analysis = new Analysis;

    date = new DateTime(this);
    //connect(date,SIGNAL(selectTime(QString)),this,SLOT(Queryfile(QString)));

    connect(this,SIGNAL(signal_SqlQuery(const QString&)),this,SLOT(slot_SqlQuery(const QString&))); //数据库操作
    connect(analysis,SIGNAL(Analysis::signal_SqlQuery(const QString&)),this,SLOT(slot_SqlQuery(const QString&))); //数据库操作

    connect(this,SIGNAL(signal_400mAnalysis(const QByteArray&)),analysis,SLOT(Analysis::_400mFrame(const QByteArray&))); //400m应答
    connect(analysis,SIGNAL(Analysis::signal_400mSend(const QByteArray&)),this,SLOT(_400mAnswer(const QByteArray&))); //400m应答

    connect(this,SIGNAL(signal_GMSRAnalysis(const QByteArray&)),analysis,SLOT(Analysis::GMSRFrame(const QByteArray&))); //GMSR应答
    connect(analysis,SIGNAL(Analysis::signal_GMSRSend(const QByteArray&)),this,SLOT(GMSRAnswer(const QByteArray&))); //GMSR应答

    ui_init();//ui设置

    receiveThread = std::thread(&MainWindow::ReceiveThread,this); //新线程，接收函数
    receiveThread.detach();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete serialport;
    delete analysis;
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

int MainWindow::ReceiveThread()
{
    std::vector<QByteArray> bdata;  //接收
    int len = 0; //长度
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        len = serialport->Read_400m(bdata);
        if(len > 0)
        {
            //解析 显示
            for(int i=0;i<len;i++)
            {
                emit signal_400mAnalysis(bdata[i]);
            }

        }

        len = serialport->Read_GMSR(bdata);
        if(len > 0)
        {
            //解析 显示
            for(int i=0;i<len;i++)
            {
                emit signal_GMSRAnalysis(bdata[i]);
            }
        }
    }
    return 0;
}





void MainWindow::slot_SqlQuery(const QString &data)
{
    //QSqlQuery query;
   // query.prepare(data);
}
void MainWindow::_400mAnswer(const QByteArray &data)
{
    serialport->Write_400m(data);
}
void MainWindow::GMSRAnswer(const QByteArray &data)
{
    serialport->Write_GMSR(data);
}
void MainWindow::on_pushButton_2_clicked()
{
    /*QByteArray data;
    data.append(0x11);
    data.append(0x22);
    data.append(0x33);
    data.append(0x44);
    data.append(0x55);
    data.append(0x66);
    serialport->Write_400m(data);

    std::vector<QByteArray> bdata;

    serialport->Read_GMSR(bdata);
    data = bdata.at(0);*/
    date->show();
}

void MainWindow::on_statistics_clicked()
{
    barchart->show();
}
