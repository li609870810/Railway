#include "serialport.h"
#include <thread>
#include <future>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <rapidjson/istreamwrapper.h>
#include <fstream>
#include <iostream>
#include"typedef.h"

using namespace rapidjson;

SerialPort::SerialPort():
    Queue_400m(65000)
    ,Queue_GMSR(65000)
{
    serialport_400m  = new QSerialPort;
    serialport_GMSR  = new QSerialPort;

    rapidjson::Document document;

    std::string devconffilename = "./CONF/com_conf.json";

    std::ifstream deviveconf(devconffilename);
    IStreamWrapper data(deviveconf);

    if (!deviveconf) {
        log.writelog("驱动配置文件不存在");
        return;
    }
    /*char data[1024];
    memset(data, 0, sizeof(data));
    deviveconf.read(data, sizeof(data));

    deviveconf.close();*/
    document.ParseStream(data);

    const Value& com = document["com"];

    if (!com.IsArray()) {
        log.writelog("串口配置文件com_conf.json错误： com 不是数组。");
        return;
    }
    //auto _400m = com[0];

    //for(auto com:document["com"].GetArray())
    if (!com[0]["name"].IsString()) {
        log.writelog("串口配置文件com_conf.json错误： name 不是字符串。");
        return;
    }

    serialport_400m->setPortName(com[0]["name"].GetString());      //设置串口名
    if(!serialport_400m->open(QIODevice::ReadWrite))      //打开串口
    {
        log.writelog("串口400m打开失败，端口被占用或无此端口。");
        return;
    }
    if (!com[0]["baudrate"].IsInt()) {
        log.writelog( "串口配置文件com_conf.json错误： baudrate 不是整数。");
        return;
    }
    serialport_400m->setBaudRate(com[0]["baudrate"].GetInt());      //设置波特率
    serialport_400m->setDataBits(QSerialPort::Data8);      //设置数据位数
    serialport_400m->setParity(QSerialPort::NoParity);        //设置奇偶校验
    serialport_400m->setStopBits(QSerialPort::OneStop);      //设置停止位
    serialport_400m->setFlowControl(QSerialPort::NoFlowControl);    //设置流控制


    //auto GMSR = document["com"].GetArray().end();
    if (!com[1]["name"].IsString()) {
        log.writelog("串口配置文件com_conf.json错误： name 不是字符串。");
        return;
    }

    serialport_GMSR->setPortName(com[1]["name"].GetString());      //设置串口名
    if(!serialport_GMSR->open(QIODevice::ReadWrite))      //打开串口
    {
        log.writelog("串口400m打开失败，端口被占用或无此端口。");
        return;
    }
    if (!com[1]["baudrate"].IsInt()) {
        log.writelog( "串口配置文件com_conf.json错误： baudrate 不是整数。");
        return;
    }
    serialport_GMSR->setBaudRate(com[1]["baudrate"].GetInt());      //设置波特率
    serialport_GMSR->setDataBits(QSerialPort::Data8);      //设置数据位数
    serialport_GMSR->setParity(QSerialPort::NoParity);        //设置奇偶校验
    serialport_GMSR->setStopBits(QSerialPort::OneStop);      //设置停止位
    serialport_GMSR->setFlowControl(QSerialPort::NoFlowControl);    //设置流控制

    receiveThread = std::thread(&SerialPort::ReceiveThread,this); //新线程，接收函数
    receiveThread.detach();
}
SerialPort::~SerialPort()
{
    serialport_400m->clear();
    serialport_400m->close();
    serialport_GMSR->clear();
    serialport_GMSR->close();

    delete serialport_400m;
    delete serialport_GMSR;
}


int SerialPort::ReceiveThread()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        if(!serialport_400m->atEnd())
        {
            QByteArray content_400m = serialport_400m->readAll();
            if(!content_400m.isEmpty())
            {
                Queue_400m.push(content_400m);
            }
        }
        if(!serialport_GMSR->atEnd())
        {
            QByteArray content_GMSR = serialport_GMSR->readAll();
            if(!content_GMSR.isEmpty())
            {
                Queue_GMSR.push(content_GMSR);
            }
        }
    }
    return 0;
}
int SerialPort::Read_400m(std::vector<QByteArray> &data)
{
    size_t size = Queue_400m.size();
    if(size == 0) return 0;
    data.clear();
    int re = 0;
    for(size_t i=0;i<size;i++)
    {
        QByteArray bdata;
        Queue_400m.pop(bdata);
        data.push_back(bdata);
        re++;
    }
    return re;
}

int SerialPort::Read_GMSR(std::vector<QByteArray> &data)
{
    size_t size = Queue_GMSR.size();
    if(size == 0) return 0;
    data.clear();
    int re = 0;
    for(size_t i=0;i<size;i++)
    {
        QByteArray bdata;
        Queue_GMSR.pop(bdata);
        data.push_back(bdata);
        re++;
    }
    return re;
}

void SerialPort::Write_400m(const QByteArray &content)
{
    serialport_400m->write(content);
    serialport_400m->write(content);
}

void SerialPort::Write_GMSR(const QByteArray &content)
{
    serialport_GMSR->write(content);
}

