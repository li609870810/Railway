#ifndef SERIALPORT_H
#define SERIALPORT_H
#include<QtSerialPort/QSerialPort>
#include<thread>
#include "mutexqueue.h"
#include "log.h"
#include<vector>
typedef Queue<QByteArray> FrameDataQueue;

class SerialPort
{
  //   Q_OBJECT

public:
    SerialPort();
    SerialPort(const SerialPort&) = delete;  //阻止拷贝
    SerialPort & operator = (const SerialPort&) = delete; //阻止赋值
    ~SerialPort();

    int Read_400m(std::vector<QByteArray>& data);
    int Read_GMSR(std::vector<QByteArray>& data);

    void Write_400m(const QByteArray& content );
    void Write_GMSR(const QByteArray& content );

private:
    QSerialPort  *serialport_400m;
    QSerialPort  *serialport_GMSR;
    Log log;

    FrameDataQueue Queue_400m;
    FrameDataQueue Queue_GMSR;

    std::thread receiveThread;
    int ReceiveThread();
};

#endif // SERIALPORT_H
