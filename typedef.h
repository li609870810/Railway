#ifndef TYPEDEF_H
#define TYPEDEF_H

#include"stdint.h"
#include<QByteArray>
#include <QDateTime>

unsigned char CheckSum(const char *src, unsigned long sizes);

static unsigned short const wCRC16Table[256] = {
    0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
    0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
    0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
    0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
    0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
    0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
    0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
    0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
    0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
    0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
    0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
    0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
    0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
    0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
    0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
    0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
    0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
    0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
    0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
    0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
    0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
    0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
    0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
    0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
    0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
    0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
    0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
    0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
    0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
    0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
    0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
    0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040};

unsigned short CRC16(const char* pDataIn, int iLenIn);

//////////////////_400M////////////////////////////
typedef struct __400mEndColumnInfo //列尾
{
    uint16_t start;         //起始
    uint8_t lenth;          //帧长度
    uint8_t type;           //类型
    uint32_t LocomotiveNumber; //机车号
    uint8_t sendtype;       //发送设备类型
    uint8_t command;        //命令
    uint16_t WindPressure;  //风压
    uint32_t hostid;        //列尾主机ID
    uint8_t time_sce;       //秒
    uint8_t time_min;       //分
    uint8_t time_hour;      //时
    uint8_t time_day;       //日
    uint8_t time_mon ;      //月
    uint8_t time_year;      //年
    uint8_t field;          //信号接收场强
    uint8_t checkSum;       //校验和

    void toJData(const QByteArray& recvdata) //data To JDATA
    {

        QByteArray data = recvdata;
        if(data.size() < 21) return;
        start = static_cast<uint16_t>((data.at(0)<<8) + data.at(1));
        lenth = static_cast<uint8_t>(data.at(2));
        type = static_cast<uint8_t>(data.at(3));
        LocomotiveNumber = static_cast<uint32_t>((data.at(4)<<24) + (data.at(5)<<16) + (data.at(6)<<8) + data.at(7));
        sendtype = static_cast<uint8_t>(data.at(8));
        command = static_cast<uint8_t>(data.at(9));
        WindPressure = static_cast<uint16_t>((data.at(10)<<8) + data.at(11));
        hostid = static_cast<uint32_t>((data.at(12)<<16) + (data.at(13)<<8) + data.at(14));
        time_sce = static_cast<uint8_t>(data.at(15) & 0x3f);
        time_min = (data.at(15)>>6) & 0x3;
        time_min = static_cast<uint8_t>(((data.at(16) & 0xf)<<2) + time_min);
        time_hour = ((data.at(16)>>4) & 0xf);
        time_hour = static_cast<uint8_t>(((data.at(17) & 0x1)<<4) + time_hour);
        time_day = ((data.at(17)>>1) & 0x1f);
        time_mon = ((data.at(17)>>6) & 0x3);
        time_mon = static_cast<uint8_t>(((data.at(18) & 0x3)<<2) + time_mon);
        time_year = (data.at(18)>>2) & 0x3f;
        field = static_cast<uint8_t>(data.at(19));
        checkSum = static_cast<uint8_t>(data.at(20));
    }
    void toData(QByteArray& data) //JDATA To data
    {
        data.resize(21);
        data[0] = (start>>8) & 0xff;
        data[1] = start & 0xff;
        data[2] = lenth & 0xff;
        data[3] = type & 0xff;
        data[4] = (LocomotiveNumber>>24) & 0xff;
        data[5] = (LocomotiveNumber>>16) & 0xff;
        data[6] = (LocomotiveNumber>>8) & 0xff;
        data[7] = LocomotiveNumber & 0xff;
        data[8] = sendtype;
        data[9] = command;
        data[10] = (WindPressure>>8) & 0xff;
        data[11] = WindPressure & 0xff;
        data[12] = (hostid>>16) & 0xff;
        data[13] = (hostid>>8) & 0xff;
        data[14] = hostid & 0xff;
        data[15] = time_sce & 0x3f;
        data[15] = ((time_min & 0x3)<<6) + data[11];
        data[16] = ((time_min>>2) & 0xf) + ((time_hour & 0xf)<<4);
        data[17] = ((time_hour>>4) & 0x1) + ((time_day & 0x1f)<<1);
        data[17] = ((time_mon & 0x3)<<6) + data[13];
        data[18] = (time_mon>>2) & 0x3;
        data[18] = ((time_year & 0x3f)<<2) + data[14];
        data[19] = field;
        data[20] = CheckSum(data.data(),20);//校验和
    }

}_400mEndColumnInfo;//400m列尾信息共用体

struct _400mDataHead
{
    uint16_t start;         //起始
    uint8_t lenth;          //帧长度
    uint8_t type;           //类型

    uint8_t crc16H;         //CRC16高字节
    uint8_t fixed1;         //固定位1
    uint8_t fixed2;         //固定位2
    uint8_t JCQWBW;         //机车号千万百万位
    uint16_t JCSWWQ;       //机车号十万万千位
    uint16_t JCBSG;        //机车号百十个位
    uint8_t sendtype;       //发送设备的类型
    uint8_t command;        //指令低字节
    uint8_t KJSBBHH;        //库检设备编号高位
    void toData(QByteArray& data) //JDATA To data
    {
        data.resize(21);
        data[0] = (start>>8) & 0xff;
        data[1] = start & 0xff;
        data[2] = lenth & 0xff;
        data[3] = type & 0xff;

        data[5] = fixed1 & 0x1;
        data[5] = ((fixed2 & 0xf)<<1) + data[1];
        data[5] = ((JCQWBW & 0x7)<<5) + data[1];
        data[6] = (JCQWBW>>3) & 0xf;
        data[6] = ((JCSWWQ & 0xf)<<4) + data[2];
        data[7] = (JCSWWQ>>4) & 0x3f;
        data[7] = ((JCBSG & 0x3)<<6) + data[3];
        data[8] = (JCBSG>>2) & 0xff;
        data[9] = sendtype;
        data[10] = command;
        data[11] = KJSBBHH;
    }
    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        if(data.size() < 21) return;
        start = static_cast<uint16_t>((data.at(0)<<8) + data.at(1));
        lenth = static_cast<uint8_t>(data.at(2));
        type = static_cast<uint8_t>(data.at(3));
        crc16H = static_cast<uint8_t>(data.at(4));

        fixed1 = data.at(5) & 0x1;
        fixed2 = (data.at(5)>>1) & 0xf;
        JCQWBW = (data.at(5)>>5) & 0x7;
        JCQWBW = ((data.at(6) & 0xf)<<3) + JCQWBW;
        JCSWWQ = (data.at(6)>>4) & 0xf;
        JCSWWQ = ((data.at(7) & 0x3f)<<4) + JCSWWQ;
        JCBSG = ((data.at(7)>>6) & 0x3);
        JCBSG = (data.at(8)<<2) + JCBSG;
        sendtype = data.at(9);
        command = data.at(10);
        KJSBBHH = data.at(11);
    }
};

typedef struct __400mDataTestCommand//400m数据测试结构体
{

    _400mDataHead Head;

    uint8_t crc16L;         //CRC16低字节
    uint8_t fixed3;             //固定位1
    uint8_t KJSBBHL;              //库检设备编号低位
    uint8_t LocomotiveHost;     //机车端号
    uint8_t ControlBox;         //控制盒端号
    uint8_t time_sce;       //秒
    uint8_t time_min;       //分
    uint8_t time_hour;      //时
    uint8_t time_day;       //日
    uint8_t time_mon;      //月
    uint8_t time_year;      //年

    uint8_t checkSum;       //校验和

    void toData(QByteArray& data) //JDATA To data
    {
        data.resize(21);
        Head.toData(data);

        data[13] = fixed3 & 0x1;
        data[13] = ((KJSBBHL & 0x7f)<<1) + data[0];
        data[14] = ((LocomotiveHost & 0x7f)<<1) + ((KJSBBHL>>7) & 0x1);
        data[15] = ((time_sce & 0xf)<<4) + ((ControlBox & 0x7)<<1) + ((LocomotiveHost>>7) & 0x1);
        data[16] = ((time_min & 0x3f)<<2) + ((time_sce>>4) & 0x3);
        data[17] = ((time_day & 0x7)<<5) + (time_hour & 0x1f);
        data[18] = ((time_year & 0x3)<<6) + ((time_mon & 0xf)<<2) + ((time_day>>3) & 0x3);
        data[19] = (time_year>>2) & 0xf;

        char crc14[14] = {0};
        for(int i=0;i<7;i++)
        {
            crc14[i] = data.at(i+5);
            crc14[i+7] = data.at(i+13);
        }
        uint16_t crc = CRC16(crc14,14);

        data[4] = (crc>>8) & 0xff;
        data[12] = crc & 0xff;

        data[20] = CheckSum(data.data(),20);//校验和
    }
    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        if(data.size() < 21) return;

        Head.toJData(data);

        crc16L = static_cast<uint8_t>(data.at(12));
        fixed3 = data.at(13) & 0x1;
        KJSBBHL = (data.at(13)>>1) & 0x7f;
        KJSBBHL = ((data.at(14) & 0x1)<<7) + KJSBBHL;
        LocomotiveHost = (data.at(14)>>1) & 0x7f;
        LocomotiveHost = ((data.at(15) & 0x1)<<7) + LocomotiveHost;
        ControlBox = (data.at(15) >>1) & 0x7;
        time_sce = (data.at(15)>>4) & 0xf;
        time_sce = ((data.at(16) & 0x3)<<4) + time_sce;
        time_min = (data.at(16)>>2) & 0x3f;
        time_hour = data.at(17) & 0x1f;
        time_day = (data.at(17)>>5) & 0x7;
        time_day = ((data.at(18) & 0x3)<<3) + time_day;
        time_mon = (data.at(18)>>2) & 0xf;
        time_year = (data.at(18)>>6) & 0x3;
        time_year = ((data.at(19) & 0xf)<<2) + time_year;

        checkSum  = static_cast<uint8_t>(data.at(20));
    }
}_400mDataTestCommand;//400m数据测试结构体

/*uint8_t time_sce :6;       //秒
uint8_t time_min :6;       //分
uint8_t time_hour :5;      //时
uint8_t time_day : 5;       //日
uint8_t time_mon :4;      //月
uint8_t time_year:6;      //年*/

typedef struct __400mGroundTelemetryCommand//400m地面遥测命令结构体
{
    _400mDataHead Head;

    uint8_t crc16L;         //CRC16低字节
    uint8_t fixed3;             //固定位3
    uint8_t KJSBBHL;              //库检设备编号低位
    uint8_t LocomotiveHost;     //机车端号
    uint8_t ControlBox;         //控制盒端号
    uint8_t IP1;                 //质检台IP
    uint8_t IP2;                 //质检台IP
    uint8_t IP3;                 //质检台IP
    uint8_t IP4;                 //质检台IP

    uint8_t checkSum;       //校验和

    void toData(QByteArray& data) //JDATA To data
    {
        data.resize(21);
        Head.toData(data);

        data[13] = fixed3 & 0x1;
        data[13] = ((KJSBBHL & 0x7f)<<1) + data[0];
        data[14] = ((LocomotiveHost & 0x7f)<<1) + ((KJSBBHL>>7) & 0x1);
        data[15] = ((IP1 & 0xf)<<4) + ((ControlBox & 0x7)<<1) + ((LocomotiveHost>>7) & 0x1);
        data[16] = ((IP2 & 0xf)<<4) + ((IP1>>4) & 0xf);
        data[17] = ((IP3 & 0xf)<<4) + ((IP2>>4) & 0xf);
        data[18] = ((IP4 & 0xf)<<4) + ((IP3>>4) & 0xf);
        data[19] = ((IP4>>4) & 0xf);

        char crc14[14] = {0};
        for(int i=0;i<7;i++)
        {
            crc14[i] = data.at(i+5);
            crc14[i+7] = data.at(i+13);
        }
        uint16_t crc = CRC16(crc14,14);

        data[4] = (crc>>8) & 0xff;
        data[12] = crc & 0xff;

        data[20] = CheckSum(data.data(),20);//校验和

    }
    void Answer()
    {
        IP1 = 0;
        IP2 = 0;
        IP3 = 0;
        IP4 = 0;
    }
    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        if(data.size() < 21) return;
        Head.toJData(data);

        crc16L = static_cast<uint8_t>(data.at(12));
        fixed3 = data.at(13) & 0x1;
        KJSBBHL = (data.at(13)>>1) & 0x7f;
        KJSBBHL = ((data.at(14) & 0x1)<<7) + KJSBBHL;
        LocomotiveHost = (data.at(14)>>1) & 0x7f;
        LocomotiveHost = ((data.at(15) & 0x1)<<7) + LocomotiveHost;
        ControlBox = (data.at(15) >>1) & 0x7;

        checkSum  = static_cast<uint8_t>(data.at(20));
    }
}_400mGroundTelemetryCommand;//400m地面遥测命令结构体


typedef struct __400mGroundTelemetryResults//400m地面与上车遥测结果结构体
{
     _400mDataHead Head;

    uint8_t crc16L;         //CRC16低字节
    uint8_t fixed3;             //固定位1
    uint8_t KJSBBHL;              //库检设备编号低位
    uint8_t LocomotiveHost;     //机车端号
    uint8_t ControlBox;         //控制盒端号
    uint8_t GMS_RData;               //GMS_R数据状态
    uint8_t _400mData;               //400m数据状态
    uint8_t DisconnectButton;      //断连按键状态
    uint8_t ExhaustButton;       //排风按键状态
    uint8_t QueryButton;         //查询按键状态
    uint8_t OkButton;               //确认按键状态
    uint8_t RecordingUnit;        //记录单元故障状态
    uint8_t ClockUnit;            //时钟单元状态
    uint8_t GMS_RUnit;            //GMS_R单元配置
    uint8_t _400mUnit;            //400m单元配置

    uint8_t checkSum;       //校验和

    void Answer()
    {
        GMS_RData = 0;
        _400mData = 0;
        DisconnectButton = 0;
        ExhaustButton = 0;
        OkButton = 0;
        QueryButton = 0;
        RecordingUnit = 0;
        ClockUnit = 0;
        GMS_RUnit = 0;
    }
    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        if(data.size() < 21) return;
        Head.toJData(data);

        fixed3 = data.at(13) & 0x1;
        KJSBBHL = (data.at(13)>>1) & 0x7f;
        KJSBBHL = ((data.at(14) & 0x1)<<7) + KJSBBHL;
        LocomotiveHost = (data.at(14)>>1) & 0x7f;
        LocomotiveHost = ((data.at(15) & 0x1)<<7) + LocomotiveHost;
        ControlBox = (data.at(15) >>1) & 0x7;

        GMS_RData = (data.at(15)>>4) & 0x1;
        _400mData = (data.at(15)>>5) & 0x1;
        DisconnectButton = (data.at(15)>>6) & 0x1;
        ExhaustButton = (data.at(15)>>7) & 0x1;
        QueryButton = data.at(16) & 0x1;
        OkButton = (data.at(16)>>1) & 0x1;
        RecordingUnit = (data.at(16)>>2) & 0x1;
        ClockUnit = (data.at(16)>>3) & 0x1;
        GMS_RUnit = (data.at(16)>>4) & 0x1;
        _400mUnit = (data.at(16)>>5) & 0x1;

        checkSum  = static_cast<uint8_t>(data.at(20));
    }
    void toData(QByteArray& data) //JDATA To data
    {
        data.resize(21);
        Head.toData(data);

        data[13] = fixed3 & 0x1;
        data[13] = ((KJSBBHL & 0x7f)<<1) + data[0];
        data[14] = ((LocomotiveHost & 0x7f)<<1) + ((KJSBBHL>>7) & 0x1);
        data[15] = ((ExhaustButton & 0x1)<<7) + ((DisconnectButton & 0x1)<<6) + ((_400mData & 0x1)<<5)\
                + ((GMS_RData & 0x1)<<4) + ((ControlBox & 0x7)<<1) + ((LocomotiveHost>>7) & 0x1);

        data[16] = ((_400mUnit & 0x7)<<5) + ((GMS_RUnit & 0x7)<<4) + ((ClockUnit & 0x7)<<3) + ((RecordingUnit & 0x7)<<2) + ((OkButton & 0x7)<<1) + (QueryButton & 0x1);
        data[16] = data[3] & 0x1f;

        char crc14[14] = {0};
        for(int i=0;i<7;i++)
        {
            crc14[i] = data.at(i+5);
            crc14[i+7] = data.at(i+13);
        }
        uint16_t crc = CRC16(crc14,14);

        data[4] = (crc>>8) & 0xff;
        data[12] = crc & 0xff;

        data[20] = CheckSum(data.data(),20);//校验和
    }
}_400mGroundTelemetryResults;//400m地面遥测与上车结果结构体

//////////////////GSMR////////////////////////////
void addDLE(QByteArray& data);//遇到DLE字符在后面再加一个

void deleteDLE(QByteArray& data);//接受信息中遇到DLE字符删除一个

struct _GSMRDataHead
{
    uint16_t start; //起始
    uint16_t lenth;//帧长度
    uint8_t SourcePort; //源端口
    uint8_t SourceAddrLen; //源地址长度
    uint8_t SourceAddr[4];//源地址
    uint8_t TargetPort; //目的端口
    uint8_t TargetAddrLen; //目的地址长度
    uint8_t TargetAddr[4];//目的地址
    uint8_t FrameType; //业务类型
    uint8_t FrameCommand;//命令

    void toData(QByteArray& data) //JDATA To data
    {
        data.append(static_cast<char>((start>>8) & 0xff));
        data.append(static_cast<char>(start & 0xff));
        data.append(static_cast<char>((lenth>>8) & 0xff));
        data.append(static_cast<char>(lenth & 0xff));
        data.append(static_cast<char>(SourcePort & 0xff));
        data.append(static_cast<char>(SourceAddrLen & 0xff)) ;
        if(SourceAddrLen > 4) SourceAddrLen = 4;
        for(int i=0;i<SourceAddrLen;i++)
        {
            data.append(static_cast<char>(SourceAddr[i]));
        }
        data.append(static_cast<char>(TargetPort & 0xff));
        data.append(static_cast<char>(TargetAddrLen & 0xff));
        if(TargetAddrLen > 4) TargetAddrLen = 4;
        for(int i=0;i<TargetAddrLen;i++)
        {
            data.append(static_cast<char>(TargetAddr[i]));
        }
        data.append(static_cast<char>(FrameType & 0xff));
        data.append(static_cast<char>(FrameCommand & 0xff));

    }
    int toJData(const QByteArray& data) //data To JDATA
    {
        int re = 0;
        start = static_cast<uint16_t>((data.at(0)<<8) + data.at(1));
        lenth = static_cast<uint16_t>((data.at(2)<<8) + data.at(3));
        SourcePort = static_cast<uint8_t>(data.at(4));
        SourceAddrLen = static_cast<uint8_t>(data.at(5));
        re += 5;
        for(int i=0;i<SourceAddrLen;i++)
        {
            SourceAddr[i] = static_cast<uint8_t>(data.at(i+re));
        }
        re += SourceAddrLen;
        TargetPort = static_cast<uint8_t>(data.at(re++));
        TargetAddrLen  = static_cast<uint8_t>(data.at(re++));
        re += 2;
        for(int i=0;i<TargetAddrLen;i++)
        {
            TargetAddr[i] = static_cast<uint8_t>(data.at(i+re));
        }
        re += TargetAddrLen;

        FrameType = static_cast<uint8_t>(data.at(re++));
        FrameCommand = static_cast<uint8_t>(data.at(re++));

        return re;
    }
};

typedef struct __GSMREndColumnInfo //GSMR 列尾
{
    _GSMRDataHead Head;

    uint32_t LocomotiveNumber; //机车号
    uint8_t sendtype;       //发送设备类型
    uint8_t command;        //命令
    uint16_t WindPressure;  //风压
    uint32_t hostid;        //列尾主机ID
    uint8_t time_sce;       //秒
    uint8_t time_min;       //分
    uint8_t time_hour;      //时
    uint8_t time_day;       //日
    uint8_t time_mon ;      //月
    uint8_t time_year;      //年
    uint16_t Position;      //位置区号
    uint16_t CellNumber;      //小区号
    uint16_t Voltage;       //工作电压
    uint16_t Current;       //工作电流
    uint32_t Battery;       //电池编号
    uint8_t Reserved[6];    //预留
    uint16_t crc16;         //CRC
    uint16_t end;           //帧结束

    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        deleteDLE(data);
        if(data.size() < 0x36) return;
        Head.toJData(data);

        LocomotiveNumber = static_cast<uint32_t>((data.at(18)<<24) + (data.at(19)<<16) + (data.at(20)<<8) + data.at(21));
        sendtype = static_cast<uint8_t>(data.at(22));
        command = static_cast<uint8_t>(data.at(23));

        WindPressure = static_cast<uint16_t>((data.at(24)<<8) + data.at(25));
        hostid = static_cast<uint32_t>((data.at(26)<<16) + (data.at(27)<<8) + data.at(28));
        time_sce = static_cast<uint8_t>(data.at(29) & 0x3f);
        time_min = (data.at(29)>>6) & 0x3;
        time_min = static_cast<uint8_t>(((data.at(30) & 0xf)<<2) + time_min);
        time_hour = ((data.at(30)>>4) & 0xf);
        time_hour = static_cast<uint8_t>(((data.at(31) & 0x1)<<4) + time_hour);
        time_day = ((data.at(31)>>1) & 0x1f);
        time_mon = ((data.at(31)>>6) & 0x3);
        time_mon = static_cast<uint8_t>(((data.at(32) & 0x3)<<2) + time_mon);
        time_year = (data.at(32)>>2) & 0x3f;
        Position = static_cast<uint16_t>((data.at(33)<<8) + data.at(34));
        CellNumber = static_cast<uint16_t>((data.at(35)<<8) + data.at(36));
        Voltage = static_cast<uint16_t>((data.at(37)<<8) + data.at(38));
        Current = static_cast<uint16_t>((data.at(39)<<8) + data.at(40));
        Battery = static_cast<uint32_t>((data.at(41)<<16) + (data.at(42)<<8) + data.at(43));
        for(int i=0;i<6;i++)
        {
            Reserved[i] = 0xff;
        }
        crc16 = static_cast<uint16_t>((data.at(50)<<8) + data.at(51));
        end = static_cast<uint16_t>((data.at(52)<<8) + data.at(53));
    }
    void toData(QByteArray& data) //JDATA To data
    {
        data.clear();
        Head.toData(data);
        data.append(static_cast<char>((LocomotiveNumber>>24) & 0xff));
        data.append(static_cast<char>((LocomotiveNumber>>16) & 0xff));
        data.append(static_cast<char>((LocomotiveNumber>>8) & 0xff));
        data.append(static_cast<char>(LocomotiveNumber & 0xff));
        data.append(static_cast<char>(sendtype & 0xff));
        data.append(static_cast<char>(command & 0xff));
        data.append(static_cast<char>((WindPressure>>8) & 0xff));
        data.append(static_cast<char>( WindPressure & 0xff));
        data.append(static_cast<char>((hostid>>16) & 0xff));
        data.append(static_cast<char>((hostid>>8) & 0xff));
        data.append(static_cast<char>( hostid & 0xff));

        data.append(static_cast<char>(((time_min & 0x3)<<6) + (time_sce & 0x3f)));
        data.append(static_cast<char>(((time_min>>2) & 0xf) + ((time_hour & 0xf)<<4)));
        data.append(static_cast<char>(((time_mon & 0x3)<<6) + ((time_day & 0x1f)<<1) + ((time_hour>>4) & 0x1)));
        data.append(static_cast<char>(((time_year & 0x3f)<<2) + ((time_mon>>2) & 0x3)));
        data.append(static_cast<char>((Position>>8) & 0xff));
        data.append(static_cast<char>(Position & 0xff));
        data.append(static_cast<char>((CellNumber>>8) & 0xff));
        data.append(static_cast<char>(CellNumber & 0xff));
        data.append(static_cast<char>((Voltage>>8) & 0xff));
        data.append(static_cast<char>(Voltage & 0xff));
        data.append(static_cast<char>((Current>>8) & 0xff));
        data.append(static_cast<char>(Current & 0xff));
        data.append(static_cast<char>((Battery>>16) & 0xff));
        data.append(static_cast<char>((Battery>>8) & 0xff));
        data.append(static_cast<char>(Battery & 0xff));
        data.append(0xff);
        data.append(static_cast<char>(0xff));
        data.append(static_cast<char>(0xff));
        data.append(static_cast<char>( 0xff));
        data.append(static_cast<char>(0xff));
        data.append(static_cast<char>(0xff));
        Head.lenth = data.size() -2;
        data[2] = static_cast<char>((Head.lenth>>8) & 0xff);
        data[3] = static_cast<char>(Head.lenth & 0xff);

        addDLE(data);
        unsigned short crc = CRC16(data.data()+2, Head.lenth);
        data.append(static_cast<char>((crc>>8) & 0xff));
        data.append(static_cast<char>(crc & 0xff));
        data.append(static_cast<char>((end>>8) & 0xff));
        data.append(static_cast<char>(end & 0xff));
        addDLE(data);
    }

}_GSMREndColumnInfo;//400m列尾信息共用体

typedef struct __GSMRStatus  //GSMR模块状态
{
    _GSMRDataHead Head;

    uint8_t Rstatus1;             //模块状态1
    uint8_t Rstatus2;              //模块状态2
    uint8_t RSSI;               //RSSI值
    uint16_t LAC;               //LAC
    uint16_t CI;               //CI
    uint16_t UDPPost;               //UDP监听端口
    uint8_t Version;            //软件版本号

    uint16_t crc16;         //CRC
    uint16_t end;           //帧结束

    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        deleteDLE(data);
        if(data.size() < 22) return;
        Head.toJData(data);

        Rstatus1 = (data.at(10)>>4) & 0xf;
        Rstatus2 = data.at(10) & 0xf;
        RSSI = static_cast<uint8_t>(data.at(11));
        LAC = static_cast<uint16_t>((data.at(12) <<8) + data.at(13));
        CI = static_cast<uint16_t>((data.at(14) <<8) + data.at(15));
        UDPPost = static_cast<uint16_t>((data.at(16) <<8) + data.at(17));
        Version = static_cast<uint8_t>(data.at(19));

        crc16 = static_cast<uint16_t>((data.at(20)<<8) + data.at(21));
        end = static_cast<uint16_t>((data.at(22)<<8) + data.at(23));

    }
}_GSMRStatus;

typedef struct __GSMRNetworkRegist  //GSMR网络注册
{
    _GSMRDataHead Head;

    uint8_t RegistStatus;    //注册状态
    uint8_t IP1;              //IP1
    uint8_t IP2;               //IP2
    uint8_t IP3;               //IP3
    uint8_t IP4;               //IP4
    uint8_t APNAddr[24];           //APN地址
    uint8_t APNAddrlen;             //不参与帧，发送前一定要先设置长度

    uint8_t APNName[16];           //APN用户名
    uint8_t APNNamelen;             //不参与帧，发送前一定要先设置长度

    uint8_t APNPSW[16];           //APN密码
    uint8_t APNPSWlen;              //不参与帧，发送前一定要先设置长度


    uint16_t crc16;         //CRC
    uint16_t end;           //帧结束
    void toData(QByteArray& data) //JDATA To data
    {
        data.clear();
        Head.toData(data);

        for(int i=0;i<APNAddrlen;i++)
        {
            data.append(static_cast<char>(APNAddr[i]));
        }
        data.append(static_cast<char>(0x20));
        for(int i=0;i<APNNamelen;i++)
        {
            data.append(static_cast<char>(APNName[i]));
        }
        data.append(static_cast<char>(0x20));
        for(int i=0;i<APNPSWlen;i++)
        {
            data.append(static_cast<char>(APNPSW[i]));
        }
        data.append(static_cast<char>(0x20));
        Head.lenth = data.size()-2;
        data[2] = (Head.lenth>>8) & 0xff;
        data[3] = Head.lenth & 0xff;

        addDLE(data);
        auto newcrc16 = CRC16(data.data()+2,Head.lenth);
        data.append(static_cast<char>((newcrc16>>8) & 0xff));
        data.append(static_cast<char>(newcrc16 & 0xff));
        data.append(static_cast<char>(0x10));
        data.append(static_cast<char>(0x03));
        addDLE(data);

    }
    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        deleteDLE(data);
        if(data.size() < 24) return;
        Head.toJData(data);

        RegistStatus = static_cast<uint8_t>(data.at(10));
        IP1 = static_cast<uint8_t>(data.at(11));
        IP2 = static_cast<uint8_t>(data.at(12));
        IP3 = static_cast<uint8_t>(data.at(13));
        IP4 = static_cast<uint8_t>(data.at(14));

        for(int i=0;i<Head.lenth-8;i++)
        {
            if(data.at(15+i) == 0x20)
            {
                crc16 = static_cast<uint16_t>((data.at(16+i)<<8) + data.at(17+i));
                end = static_cast<uint16_t>((data.at(18+i)<<8) + data.at(19+i));
                break;
            }else{
                APNName[i] = static_cast<uint8_t>(data.at(15+i));
            }
        }
    }

}_GSMRNetworkRegist;
typedef struct __GSMRNetworkLogout//GSMR网络注销,模块关机
{
    _GSMRDataHead Head;

    uint8_t Status;         //状态

    uint16_t crc16;         //CRC
    uint16_t end;           //帧结束
    void toData(QByteArray& data) //JDATA To data
    {
        data.clear();
        Head.toData(data);
        data.append(static_cast<char>(Status));

        Head.lenth = data.size()-2;
        data[2] = (Head.lenth>>8) & 0xff;
        data[3] = Head.lenth & 0xff;

        addDLE(data);
        auto newcrc16 = CRC16(data.data()+2,Head.lenth);
        data.append(static_cast<char>((newcrc16>>8) & 0xff));
        data.append(static_cast<char>(newcrc16 & 0xff));
        data.append(static_cast<char>(0x10));
        data.append(static_cast<char>(0x03));
        addDLE(data);

    }
    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        deleteDLE(data);
        if(data.size() < 15) return;
        Head.toJData(data);
        Status = static_cast<uint8_t>(data.at(10));

        crc16 = static_cast<uint16_t>((data.at(11)<<8) + data.at(12));
        end = static_cast<uint16_t>((data.at(13)<<8) + data.at(14));
    }

}_GSMRNetworkLogout;

typedef struct __GSMRInquireIP//GSMR查询IP
{
    _GSMRDataHead Head;

    uint8_t mainIP1;         //主用IP
    uint8_t mainIP2;         //主用IP
    uint8_t mainIP3;         //主用IP
    uint8_t mainIP4;         //主用IP

    uint8_t backIP1;         //备用IP
    uint8_t backIP2;         //备用IP
    uint8_t backIP3;         //备用IP
    uint8_t backIP4;         //备用IP

    uint8_t APNName[16];     //车载设备域名
    uint8_t APNNamelen;      //不参与帧，发送前一定要先设置长度

    uint8_t Status;         //查询状态
    uint8_t CheckDeskIP1;      //库检台IP
    uint8_t CheckDeskIP2;      //库检台IP
    uint8_t CheckDeskIP3;      //库检台IP
    uint8_t CheckDeskIP4;      //库检台IP

    uint16_t crc16;         //CRC
    uint16_t end;           //帧结束

    void toData(QByteArray& data) //JDATA To data
    {
        data.clear();
        Head.toData(data);
        data.append(static_cast<char>(mainIP1));
        data.append(static_cast<char>(mainIP2));
        data.append(static_cast<char>(mainIP3));
        data.append(static_cast<char>(mainIP4));

        data.append(static_cast<char>(backIP1));
        data.append(static_cast<char>(mainIP2));
        data.append(static_cast<char>(mainIP3));
        data.append(static_cast<char>(mainIP4));

        for(int i=0;i<APNNamelen;i++)
        {
            data.append(static_cast<char>(APNName[i]));
        }
        data.append(static_cast<char>(0x20));

        Head.lenth = data.size()-2;
        data[2] = static_cast<char>((Head.lenth>>8) & 0xff);
        data[3] = static_cast<char>(Head.lenth & 0xff);

        addDLE(data);
        auto newcrc16 = CRC16(data.data()+2,Head.lenth);
        data.append(static_cast<char>((newcrc16>>8) & 0xff));
        data.append(static_cast<char>(newcrc16 & 0xff));
        data.append(static_cast<char>(0x10));
        data.append(static_cast<char>(0x03));
        addDLE(data);

    }
    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        deleteDLE(data);
        if(data.size() < 19) return;
        Head.toJData(data);

        Status = static_cast<uint8_t>(data.at(10));
        CheckDeskIP1 = static_cast<uint8_t>(data.at(11));
        CheckDeskIP2 = static_cast<uint8_t>(data.at(12));
        CheckDeskIP3 = static_cast<uint8_t>(data.at(13));
        CheckDeskIP4 = static_cast<uint8_t>(data.at(14));

        crc16 = static_cast<uint16_t>((data.at(15)<<8) + data.at(16));
        end = static_cast<uint16_t>((data.at(17)<<8) + data.at(18));
    }

}_GSMRInquireIP;
typedef struct __GSMRLibraryInspectionInfo //GSMR库检信息
{
    _GSMRDataHead Head;

    uint32_t LocomotiveNumber; //机车号
    uint8_t sendtype;       //发送设备类型
    uint8_t command;        //命令
    uint16_t KJSBBH;              //库检设备编号低位
    uint8_t LocomotiveHost;     //机车端号
    uint8_t ControlBox;         //控制盒端号

    uint8_t GMS_RData;               //GMS_R数据状态
    uint8_t _400mData;               //400m数据状态
    uint8_t DisconnectButton;      //断连按键状态
    uint8_t ExhaustButton;       //排风按键状态
    uint8_t QueryButton;         //查询按键状态
    uint8_t OkButton;               //确认按键状态
    uint8_t RecordingUnit;        //记录单元故障状态
    uint8_t ClockUnit;            //时钟单元状态

    uint8_t Reserved[22];    //预留
    uint16_t crc16;         //CRC
    uint16_t end;           //帧结束

    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        deleteDLE(data);
        if(data.size() < 0x36) return;
        Head.toJData(data);
        LocomotiveNumber = static_cast<uint32_t>((data.at(18)<<24) + (data.at(19)<<16) + (data.at(20)<<8) + data.at(21));
        sendtype = static_cast<uint8_t>(data.at(22));
        command = static_cast<uint8_t>(data.at(23));
        KJSBBH = static_cast<uint16_t>((data.at(24)<<8) + data.at(25));
        LocomotiveHost = static_cast<uint8_t>(data.at(26));
        ControlBox = static_cast<uint8_t>(data.at(27));
        //6
        crc16 = static_cast<uint16_t>((data.at(50)<<8) + data.at(51));
        end = static_cast<uint16_t>((data.at(52)<<8) + data.at(53));
    }
    void toData(QByteArray& data) //JDATA To data
    {
        data.clear();
        Head.toData(data);
        data.append(static_cast<char>((LocomotiveNumber>>24) & 0xff));
        data.append(static_cast<char>((LocomotiveNumber>>16) & 0xff));
        data.append(static_cast<char>((LocomotiveNumber>>8) & 0xff));
        data.append(static_cast<char>(LocomotiveNumber & 0xff));
        data.append(static_cast<char>(sendtype & 0xff));
        data.append(static_cast<char>(command & 0xff));
        data.append(static_cast<char>((KJSBBH>>8) & 0xff));
        data.append(static_cast<char>(KJSBBH & 0xff));
        data.append(static_cast<char>(LocomotiveHost & 0xff));
        data.append(static_cast<char>(ControlBox & 0xff));
        for(int i=0;i<22;i++)
        {
            data.append(static_cast<char>(0xff));
        }
        Head.lenth = data.size() -2;
        data[2] = static_cast<char>((Head.lenth>>8) & 0xff);
        data[3] = static_cast<char>(Head.lenth & 0xff);

        addDLE(data);
        unsigned short crc = CRC16(data.data()+2, Head.lenth);
        data.append(static_cast<char>((crc>>8) & 0xff));
        data.append(static_cast<char>(crc & 0xff));
        data.append(static_cast<char>((end>>8) & 0xff));
        data.append(static_cast<char>(end & 0xff));
        addDLE(data);
    }

    void toDataTestData(QByteArray& data) //JDATA To data
    {
        data.clear();
        Head.toData(data);
        data.append(static_cast<char>((LocomotiveNumber>>24) & 0xff));
        data.append(static_cast<char>((LocomotiveNumber>>16) & 0xff));
        data.append(static_cast<char>((LocomotiveNumber>>8) & 0xff));
        data.append(static_cast<char>(LocomotiveNumber & 0xff));
        data.append(static_cast<char>(sendtype & 0xff));
        data.append(static_cast<char>(command & 0xff));
        data.append(static_cast<char>((KJSBBH>>8) & 0xff));
        data.append(static_cast<char>(KJSBBH & 0xff));
        data.append(static_cast<char>(LocomotiveHost & 0xff));
        data.append(static_cast<char>(ControlBox & 0xff));

        QDateTime current_date_time =QDateTime::currentDateTime();
        uint8_t time_sce = static_cast<uint8_t>(current_date_time.time().second());
        uint8_t time_min = static_cast<uint8_t>(current_date_time.time().minute());
        uint8_t time_hour = static_cast<uint8_t>(current_date_time.time().hour());
        uint8_t time_day = static_cast<uint8_t>(current_date_time.date().day());
        uint8_t time_mon = static_cast<uint8_t>(current_date_time.date().month());
        uint8_t time_year = static_cast<uint8_t>(current_date_time.date().year()-2000);

        data.append(static_cast<char>(((time_min & 0x3)<<6) + (time_sce & 0x3f)));
        data.append(static_cast<char>(((time_min>>2) & 0xf) + ((time_hour & 0xf)<<4)));
        data.append(static_cast<char>(((time_mon & 0x3)<<6) + ((time_day & 0x1f)<<1) + ((time_hour>>4) & 0x1)));
        data.append(static_cast<char>(((time_year & 0x3f)<<2) + ((time_mon>>2) & 0x3)));

        for(int i=0;i<18;i++)
        {
            data.append(static_cast<char>(0xff));
        }
        Head.lenth = data.size() -2;
        data[2] = static_cast<char>((Head.lenth>>8) & 0xff);
        data[3] = static_cast<char>(Head.lenth & 0xff);
        addDLE(data);
        unsigned short crc = CRC16(data.data()+2, Head.lenth);
        data.append(static_cast<char>((crc>>8) & 0xff));
        data.append(static_cast<char>(crc & 0xff));
        data.append(static_cast<char>((end>>8) & 0xff));
        data.append(static_cast<char>(end & 0xff));
        addDLE(data);
    }
    void toGroundResultJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        deleteDLE(data);
        if(data.size() < 0x36) return;
        Head.toJData(data);
        LocomotiveNumber = static_cast<uint32_t>((data.at(18)<<24) + (data.at(19)<<16) + (data.at(20)<<8) + data.at(21));
        sendtype = static_cast<uint8_t>(data.at(22));
        command = static_cast<uint8_t>(data.at(23));
        KJSBBH = static_cast<uint16_t>((data.at(24)<<8) + data.at(25));
        LocomotiveHost = static_cast<uint8_t>(data.at(26));
        ControlBox = static_cast<uint8_t>(data.at(27));

        GMS_RData = static_cast<uint8_t>(data.at(28));
        _400mData = static_cast<uint8_t>(data.at(29));
        DisconnectButton = static_cast<uint8_t>(data.at(30));
        ExhaustButton = static_cast<uint8_t>(data.at(31));
        QueryButton = static_cast<uint8_t>(data.at(32));
        OkButton = static_cast<uint8_t>(data.at(33));
        RecordingUnit = static_cast<uint8_t>(data.at(34));
        ClockUnit = static_cast<uint8_t>(data.at(35));

        //6
        crc16 = static_cast<uint16_t>((data.at(50)<<8) + data.at(51));
        end = static_cast<uint16_t>((data.at(52)<<8) + data.at(53));
    }
    void toGroundResultData(QByteArray& data)
    {
        data.clear();
        Head.toData(data);
        data.append(static_cast<char>((LocomotiveNumber>>24) & 0xff));
        data.append(static_cast<char>((LocomotiveNumber>>16) & 0xff));
        data.append(static_cast<char>((LocomotiveNumber>>8) & 0xff));
        data.append(static_cast<char>(LocomotiveNumber & 0xff));
        data.append(static_cast<char>(sendtype & 0xff));
        data.append(static_cast<char>(command & 0xff));
        data.append(static_cast<char>((KJSBBH>>8) & 0xff));
        data.append(static_cast<char>(KJSBBH & 0xff));
        data.append(static_cast<char>(LocomotiveHost & 0xff));
        data.append(static_cast<char>(ControlBox & 0xff));
        for(int i=0;i<14;i++)
        {
            data.append(static_cast<char>(0xff));
        }
        Head.lenth = data.size() -2;
        data[2] = static_cast<char>((Head.lenth>>8) & 0xff);
        data[3] = static_cast<char>(Head.lenth & 0xff);
        addDLE(data);
        unsigned short crc = CRC16(data.data()+2, Head.lenth);
        data.append(static_cast<char>((crc>>8) & 0xff));
        data.append(static_cast<char>(crc & 0xff));
        data.append(static_cast<char>((end>>8) & 0xff));
        data.append(static_cast<char>(end & 0xff));
        addDLE(data);
    }
}_GSMRLibraryInspectionInfo;//GSMR库检信息

void GSMRAnswerFrame(QByteArray& data);


#endif // TYPEDEF_H
