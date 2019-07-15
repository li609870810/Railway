#ifndef TYPEDEF_H
#define TYPEDEF_H

#include"stdint.h"
#include<QByteArray>
unsigned char checkSum(const char *src, unsigned long sizes);

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

typedef struct __400mEndColumnInfo //列尾
{
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

    void toJData(const char* data,const size_t len) //data To JDATA
    {
        if(len < 16) return;
        LocomotiveNumber = static_cast<uint32_t>((data[0]<<24) + (data[1]<<16) + (data[2]<<8) + data[3]);
        sendtype = static_cast<uint8_t>(data[4]);
        command = static_cast<uint8_t>(data[5]);
        WindPressure = static_cast<uint16_t>((data[6]<<8) + data[7]);
        hostid = static_cast<uint32_t>((data[8]<<16) + (data[9]<<8) + data[10]);
        time_sce = static_cast<uint8_t>(data[11] & 0x3f);
        time_min = (data[11]>>6) & 0x3;
        time_min = static_cast<uint8_t>(((data[12] & 0xf)<<2) + time_min);
        time_hour = ((data[12]>>4) & 0xf);
        time_hour = static_cast<uint8_t>(((data[13] & 0x1)<<4) + time_hour);
        time_day = ((data[13]>>1) & 0x1f);
        time_mon = ((data[13]>>6) & 0x3);
        time_mon = static_cast<uint8_t>(((data[14] & 0x3)<<2) + time_mon);
        time_year = (data[14]>>2) & 0x3f;
        field = static_cast<uint8_t>(data[15]);
    }
    void toData(char* data,const size_t len) //JDATA To data
    {
        if(len < 16) return;
        data[0] = (LocomotiveNumber>>24) & 0xff;
        data[1] = (LocomotiveNumber>>16) & 0xff;
        data[2] = (LocomotiveNumber>>8) & 0xff;
        data[3] = LocomotiveNumber & 0xff;
        data[4] = sendtype;
        data[5] = command;
        data[6] = (WindPressure>>8) & 0xff;
        data[7] = WindPressure & 0xff;
        data[8] = (hostid>>16) & 0xff;
        data[9] = (hostid>>8) & 0xff;
        data[10] = hostid & 0xff;

        data[11] = time_sce & 0x3f;

        data[11] = ((time_min & 0x3)<<6) + data[11];
        data[12] = ((time_min>>2) & 0xf) + ((time_hour & 0xf)<<4);
        data[13] = ((time_hour>>4) & 0x1) + ((time_day & 0x1f)<<1);
        data[13] = ((time_mon & 0x3)<<6) + data[13];
        data[14] = (time_mon>>2) & 0x3;
        data[14] = ((time_year & 0x3f)<<2) + data[14];
        data[15] = field;
    }

}_400mEndColumnInfo;//400m列尾信息共用体

typedef struct __400mLibraryInspectionInfor
{
    uint8_t fixed1;         //固定位1
    uint8_t fixed2;         //固定位2
    uint8_t JCQWBW;         //机车号千万百万位
    uint16_t JCSWWQ;       //机车号十万万千位
    uint16_t JCBSG;        //机车号百十个位
    uint8_t sendtype;       //发送设备的类型
    uint8_t command;        //指令低字节
    uint8_t KJSBBHH;        //库检设备编号高位

    void toData(char* data,const size_t len) //JDATA To data
    {
        if(len < 7) return;
        data[0] = fixed1 & 0x1;
        data[0] = ((fixed2 & 0xf)<<1) + data[1];
        data[0] = ((JCQWBW & 0x7)<<5) + data[1];
        data[1] = (JCQWBW>>3) & 0xf;
        data[1] = ((JCSWWQ & 0xf)<<4) + data[2];
        data[2] = (JCSWWQ>>4) & 0x3f;
        data[2] = ((JCBSG & 0x3)<<6) + data[3];
        data[3] = (JCBSG>>2) & 0xff;
        data[4] = sendtype;
        data[5] = command;
        data[6] = KJSBBHH;
    }
    void toJData(const char* data,const size_t len) //data To JDATA
    {
        if(len < 7) return;
        fixed1 = data[0] & 0x1;
        fixed2 = (data[0]>>1) & 0xf;
        JCQWBW = (data[0]>>5) & 0x7;
        JCQWBW = ((data[1] & 0xf)<<3) + JCQWBW;
        JCSWWQ = (data[1]>>4) & 0xf;
        JCSWWQ = ((data[2] & 0x3f)<<4) + JCSWWQ;
        JCBSG = ((data[2]>>6) & 0x3);
        JCBSG = (data[3]<<2) + JCBSG;
        sendtype = data[4];
        command = data[5];
        KJSBBHH = data[6];
    }
}_400mLibraryInspectionInfor;//400m库检信息前8个字节通用共用体

/*uint8_t time_sce :6;       //秒
uint8_t time_min :6;       //分
uint8_t time_hour :5;      //时
uint8_t time_day : 5;       //日
uint8_t time_mon :4;      //月
uint8_t time_year:6;      //年*/
typedef struct __400mDataTestCommand
{
    uint8_t fixed1;             //固定位1
    uint8_t KJSBBHL;              //库检设备编号低位
    uint8_t LocomotiveHost;     //机车端号
    uint8_t ControlBox;         //控制盒端号
    uint8_t time_sce;       //秒
    uint8_t time_min;       //分
    uint8_t time_hour;      //时
    uint8_t time_day;       //日
    uint8_t time_mon;      //月
    uint8_t time_year;      //年

    void toJData(const char* data,const size_t len) //data To JDATA
    {
        if(len < 7) return;
        fixed1 = data[0] & 0x1;
        KJSBBHL = (data[0]>>1) & 0x7f;
        KJSBBHL = ((data[1] & 0x1)<<7) + KJSBBHL;
        LocomotiveHost = (data[1]>>1) & 0x7f;
        LocomotiveHost = ((data[2] & 0x1)<<7) + LocomotiveHost;
        ControlBox = (data[2] >>1) & 0x7;
        time_sce = (data[2]>>4) & 0xf;
        time_sce = ((data[3] & 0x3)<<4) + time_sce;
        time_min = (data[3]>>2) & 0x3f;
        time_hour = data[4] & 0x1f;
        time_day = (data[4]>>5) & 0x7;
        time_day = ((data[5] & 0x3)<<3) + time_day;
        time_mon = (data[5]>>2) & 0xf;
        time_year = (data[5]>>6) & 0x3;
        time_year = ((data[6] & 0xf)<<2) + time_year;
    }
    void toData(char* data,const size_t len) //JDATA To data
    {
         if(len < 7) return;
        data[0] = fixed1 & 0x1;
        data[0] = ((KJSBBHL & 0x7f)<<1) + data[0];
        data[1] = ((LocomotiveHost & 0x7f)<<1) + ((KJSBBHL>>7) & 0x1);
        data[2] = ((time_sce & 0xf)<<4) + ((ControlBox & 0x7)<<1) + ((LocomotiveHost>>7) & 0x1);
        data[3] = ((time_min & 0x3f)<<2) + ((time_sce>>4) & 0x3);
        data[4] = ((time_day & 0x7)<<5) + (time_hour & 0x1f);
        data[5] = ((time_year & 0x3)<<6) + ((time_mon & 0xf)<<2) + ((time_day>>3) & 0x3);
        data[6] = (time_year>>2) & 0xf;
    }
}_400mDataTestCommand;//400m数据测试共用体


typedef struct __400mGroundTelemetryResults
{
    uint8_t fixed1;             //固定位1
    uint8_t KJSBBHL;              //库检设备编号低位
    uint8_t LocomotiveHost;     //机车端号
    uint8_t ControlBox;         //控制盒端号
    uint8_t GMS_RData;               //GMS_R数据状态
    uint8_t _400mData;               //400m数据状态
    uint8_t DisconnectButton;      //断连按键状态
    uint8_t ExhaustButton;       //排风按键状态
    uint8_t QueryButton;         //查询按键状态
    uint8_t RecordingUnit;        //记录单元故障状态
    uint8_t ClockUnit;            //时钟单元状态
    uint8_t GMS_RUnit;            //GMS_R单元配置
    uint8_t _400mUnit;            //400m单元配置

    void toJData(const char* data,const size_t len) //data To JDATA
    {
        if(len < 7) return;
        fixed1 = data[0] & 0x1;
        KJSBBHL = (data[0]>>1) & 0x7f;
        KJSBBHL = ((data[1] & 0x1)<<7) + KJSBBHL;
        LocomotiveHost = (data[1]>>1) & 0x7f;
        LocomotiveHost = ((data[2] & 0x1)<<7) + LocomotiveHost;
        ControlBox = (data[2] >>1) & 0x7;
        GMS_RData = (data[2]>>4) & 0x1;
        _400mData = (data[2]>>5) & 0x1;
        DisconnectButton = (data[2]>>6) & 0x1;
        ExhaustButton = (data[2]>>7) & 0x1;
        QueryButton = data[3] & 0x1;
        RecordingUnit = (data[3]>>1) & 0x1;
        ClockUnit = (data[3]>>2) & 0x1;
        GMS_RUnit = (data[3]>>3) & 0x1;
        _400mUnit = (data[3]>>4) & 0x1;
    }
    void toData(char* data,const size_t len) //JDATA To data
    {
         if(len < 7) return;
        data[0] = fixed1 & 0x1;
        data[0] = ((KJSBBHL & 0x7f)<<1) + data[0];
        data[1] = ((LocomotiveHost & 0x7f)<<1) + ((KJSBBHL>>7) & 0x1);
        data[2] = ((ExhaustButton & 0x1)<<7) + ((DisconnectButton & 0x1)<<6) + ((_400mData & 0x1)<<5)\
                + ((GMS_RData & 0x1)<<4) + ((ControlBox & 0x7)<<1) + ((LocomotiveHost>>7) & 0x1);
        data[3] = ((_400mUnit & 0x7)<<4) + ((GMS_RUnit & 0x7)<<3) + ((ClockUnit & 0x7)<<2) + ((RecordingUnit & 0x7)<<1) + (QueryButton & 0x1);
        data[3] = data[3] & 0x1f;
    }
}_400mGroundTelemetryResults;//400m地面遥测结果共用体

void addDLE(QByteArray& data);//遇到DLE字符在后面再加一个

void deleteDLE(QByteArray& data);//接受信息中遇到DLE字符删除一个

typedef struct __GSMREndColumnInfo //GSMR 列尾
{
    uint16_t start; //起始
    uint16_t lenth;//帧长度
    uint8_t SourcePort; //源端口
    uint8_t SourceAddrLen; //源地址长度
    uint32_t SourceAddr;//源地址
    uint8_t TargetPort; //目的端口
    uint8_t TargetAddrLen; //目的地址长度
    uint32_t TargetAddr;//目的地址
    uint8_t FrameType; //业务类型
    uint8_t FrameCommand;//命令

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
        start = static_cast<uint16_t>((data.at(0)<<8) + data.at(1));
        lenth = static_cast<uint16_t>((data.at(2)<<8) + data.at(3));
        SourcePort = static_cast<uint8_t>(data.at(4));
        SourceAddrLen = static_cast<uint8_t>(data.at(5));
        SourceAddr = static_cast<uint32_t>((data.at(6)<<24) + (data.at(7)<<16) + (data.at(8)<<8) + data.at(9));
        TargetPort = static_cast<uint8_t>(data.at(10));
        TargetAddrLen  = static_cast<uint8_t>(data.at(11));
        TargetAddr = static_cast<uint32_t>((data.at(12)<<24) + (data.at(13)<<16) + (data.at(14)<<8) + data.at(15));
        FrameType = static_cast<uint8_t>(data.at(16));
        FrameCommand = static_cast<uint8_t>(data.at(17));

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
        //6
        crc16 = static_cast<uint16_t>((data.at(50)<<8) + data.at(51));
        end = static_cast<uint16_t>((data.at(52)<<8) + data.at(53));
    }
    void toData(QByteArray& data) //JDATA To data
    {
        data.resize(0x36);
        data[0] = (start>>8) & 0xff;
        data[1] = start & 0xff;
        data[2] = (lenth>>8) & 0xff;
        data[3] = lenth & 0xff;
        data[4] = SourcePort & 0xff;
        data[5] = SourceAddrLen & 0xff ;
        data[6] = (SourceAddr>>24) & 0xff;
        data[7] = (SourceAddr>>16) & 0xff;
        data[8] = (SourceAddr>>8) & 0xff;
        data[9] = SourceAddr & 0xff;
        data[10] = TargetPort & 0xff;
        data[11] = TargetAddrLen & 0xff;
        data[12] = SourceAddrLen & 0xff ;
        data[13] = (TargetAddr>>24) & 0xff;
        data[14] = (TargetAddr>>16) & 0xff;
        data[15] = (TargetAddr>>8) & 0xff;
        data[16] = TargetAddr & 0xff;
        data[17] = FrameType & 0xff;
        data[18] = FrameCommand & 0xff;
        data[19] = (LocomotiveNumber>>24) & 0xff;
        data[20] = (LocomotiveNumber>>16) & 0xff;
        data[21] = (LocomotiveNumber>>8) & 0xff;
        data[22] = LocomotiveNumber & 0xff;
        data[23] = sendtype & 0xff;
        data[24] = command & 0xff;
        data[25] = (WindPressure>>8) & 0xff;
        data[26] = WindPressure & 0xff;
        data[27] = (hostid>>16) & 0xff;
        data[28] = (hostid>>8) & 0xff;
        data[29] = hostid & 0xff;
        data[30] = time_sce & 0x3f;

        data[30] = static_cast<char>(((time_min & 0x3)<<6) + data[30]);
        data[31] = static_cast<char>(((time_min>>2) & 0xf) + ((time_hour & 0xf)<<4));
        data[32] = static_cast<char>(((time_hour>>4) & 0x1) + ((time_day & 0x1f)<<1));
        data[32] = static_cast<char>(((time_mon & 0x3)<<6) + data[32]);
        data[33] = static_cast<char>((time_mon>>2) & 0x3);
        data[33] = static_cast<char>(((time_year & 0x3f)<<2) + data[33]);
        data[34] = (Position>>8) & 0xff;
        data[35] = Position & 0xff;
        data[36] = (CellNumber>>8) & 0xff;
        data[37] = CellNumber & 0xff;
        data[38] = (Voltage>>8) & 0xff;
        data[39] = Voltage & 0xff;
        data[40] = (Current>>8) & 0xff;
        data[41] = Current & 0xff;
        data[42] = (Battery>>16) & 0xff;
        data[43] = (Battery>>8) & 0xff;
        data[44] = Battery & 0xff;
        data[45] = 0xff;
        data[46] = 0xff;
        data[47] = 0xff;
        data[48] = 0xff;
        data[49] = 0xff;
        data[50] = 0xff;
        unsigned short crc = CRC16(data.data()+2, lenth);
        data[51] = (crc>>8) & 0xff;
        data[52] = crc & 0xff;
        data[53] = (end>>8) & 0xff;
        data[54] = end & 0xff;
        addDLE(data);
    }

}_GSMREndColumnInfo;//400m列尾信息共用体

typedef struct __GSMRStatus  //GSMR模块状态
{
    uint16_t start; //起始
    uint16_t lenth;//帧长度
    uint8_t SourcePort; //源端口
    uint8_t SourceAddrLen; //源地址长度
    uint32_t SourceAddr;//源地址
    uint8_t TargetPort; //目的端口
    uint8_t TargetAddrLen; //目的地址长度
    uint32_t TargetAddr;//目的地址
    uint8_t FrameType; //业务类型
    uint8_t FrameCommand;//命令

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
        if(data.size() < 31) return;
        start = static_cast<uint16_t>((data.at(0)<<8) + data.at(1));
        lenth = static_cast<uint16_t>((data.at(2)<<8) + data.at(3));
        SourcePort = static_cast<uint8_t>(data.at(4));
        SourceAddrLen = static_cast<uint8_t>(data.at(5));
        SourceAddr = static_cast<uint32_t>((data.at(6)<<24) + (data.at(7)<<16) + (data.at(8)<<8) + data.at(9));
        TargetPort = static_cast<uint8_t>(data.at(10));
        TargetAddrLen  = static_cast<uint8_t>(data.at(11));
        TargetAddr = static_cast<uint32_t>((data.at(12)<<24) + (data.at(13)<<16) + (data.at(14)<<8) + data.at(15));
        FrameType = static_cast<uint8_t>(data.at(16));
        FrameCommand = static_cast<uint8_t>(data.at(17));

        Rstatus1 = (data.at(18)>>4) & 0xf;
        Rstatus2 = data.at(18) & 0xf;
        RSSI = static_cast<uint8_t>(data.at(19));
        LAC = static_cast<uint16_t>((data.at(20) <<8) + data.at(21));
        CI = static_cast<uint16_t>((data.at(22) <<8) + data.at(23));
        UDPPost = static_cast<uint16_t>((data.at(24) <<8) + data.at(25));
        Version = static_cast<uint8_t>(data.at(27));

        crc16 = static_cast<uint16_t>((data.at(28)<<8) + data.at(29));
        end = static_cast<uint16_t>((data.at(30)<<8) + data.at(31));
    }
}_GSMRStatus;

typedef struct __GSMRNetworkRegist  //GSMR网络注册
{
    uint16_t start; //起始
    uint16_t lenth;//帧长度
    uint8_t SourcePort; //源端口
    uint8_t SourceAddrLen; //源地址长度
    uint32_t SourceAddr;//源地址
    uint8_t TargetPort; //目的端口
    uint8_t TargetAddrLen; //目的地址长度
    uint32_t TargetAddr;//目的地址
    uint8_t FrameType; //业务类型
    uint8_t FrameCommand;//命令

    uint8_t RegistRstatus;    //注册状态
    uint8_t IP1;              //IP1
    uint8_t IP2;               //IP2
    uint8_t IP3;               //IP3
    uint8_t IP4;               //IP4
    uint8_t APNName[16];           //APN用户名
    uint8_t Separate;            //分隔符

    uint16_t crc16;         //CRC
    uint16_t end;           //帧结束

    void toJData(const QByteArray& recvdata) //data To JDATA
    {
        QByteArray data = recvdata;
        deleteDLE(data);
        if(data.size() < 30) return;
        start = static_cast<uint16_t>((data.at(0)<<8) + data.at(1));
        lenth = static_cast<uint16_t>((data.at(2)<<8) + data.at(3));
        SourcePort = static_cast<uint8_t>(data.at(4));
        SourceAddrLen = static_cast<uint8_t>(data.at(5));
        SourceAddr = static_cast<uint32_t>((data.at(6)<<24) + (data.at(7)<<16) + (data.at(8)<<8) + data.at(9));
        TargetPort = static_cast<uint8_t>(data.at(10));
        TargetAddrLen  = static_cast<uint8_t>(data.at(11));
        TargetAddr = static_cast<uint32_t>((data.at(12)<<24) + (data.at(13)<<16) + (data.at(14)<<8) + data.at(15));
        FrameType = static_cast<uint8_t>(data.at(16));
        FrameCommand = static_cast<uint8_t>(data.at(17));

        RegistRstatus = static_cast<uint8_t>(data.at(18));
        IP1 = static_cast<uint8_t>(data.at(19));
        IP2 = static_cast<uint8_t>(data.at(20));
        IP3 = static_cast<uint8_t>(data.at(21));
        IP4 = static_cast<uint8_t>(data.at(22));
        for(int i=0;i<lenth-16;i++)
        {
            APNName[i] = static_cast<uint8_t>(data.at(23+i));
            if(APNName[i] == 0x20)
            {
                Separate = 0x20;
                crc16 = static_cast<uint16_t>((data.at(24+i)<<8) + data.at(25+i));
                end = static_cast<uint16_t>((data.at(26+i)<<8) + data.at(27+i));
                break;
            }
        }
    }
}_GSMRNetworkRegist;
#endif // TYPEDEF_H
