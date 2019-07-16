#include "analysis.h"
#include"typedef.h"
#include<windows.h>
#include<QDateTime>

Analysis::Analysis():
    resendQueue(256)
{
    resendThread = std::thread(&Analysis::ResendThread,this); //新线程，接收函数
    resendThread.detach();
}

int Analysis::ResendThread()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        size_t len = resendQueue.size();
        for(size_t i=0;i<len;i++)
        {
            resendQueue[i].timeing += 10;
            if(resendQueue[i].timeing >= 400)
            {
                if(resendQueue[i].count == 2)
                {
                    resendQueue.erase(resendQueue.begin()+i);
                    continue;
                }
                emit signal_GMSRSend(resendQueue[i].senddata);
                resendQueue[i].timeing = 0;
                resendQueue[i].count++;
            }
        }

    }
    return 0;
}

void Analysis::_400mFrame(const QByteArray& recvdata)
{

    for(int i=0;i<recvdata.size();i++)//抛弃开头无效数据
    {
        //data.toHex();
        if((uchar)recvdata.at(i) != 0xa5) continue;
        if(recvdata.at(i+1) != 0x5a) continue;
        char len = recvdata.at(i+2);
        if(len > (recvdata.size()-i-4))return;//该帧无效
        uchar type = recvdata.at(i+3);

        bool ifAnswer = false; //是否应答
        QByteArray data = recvdata.mid(i);
        QString insert_sql = "INSERT INTO 表名 (机车号,...所有字段名) VALUES ("; //数据库语句

        switch (type) {
        case 0xca://列尾信息
            {
                _400mEndColumnInfo _400ECI;
                _400ECI.toJData(data);
                if(CheckSum(data.data(),20) != _400ECI.checkSum) return; //校验和失败

                //应答信号
                switch(_400ECI.command)
                {
                    case 0x24:
                    {
                    //信号 数据库操作
                    ifAnswer = true;
                    }
                    break;
                    case 0x91:
                    {
                    //信号 数据库操作
                    ifAnswer = true;
                    }
                    break;
                    case 0x83:
                    {
                    //信号 数据库操作
                    ifAnswer = true;
                    }
                    break;
                    case 0xb5:
                    {
                    //信号 数据库操作
                    ifAnswer = true;
                    }
                    break;
                    case 0x31:
                    {
                    //信号 数据库操作
                    ifAnswer = false;
                    }
                    break;
                    case 0xb1:
                    {
                    //信号 数据库操作
                    ifAnswer = false;
                    }
                    break;
                default:
                    ifAnswer =false;
                    break;
                }
                if(ifAnswer)
                {
                    _400ECI.sendtype = 0x5d;
                    _400ECI.command += 1;

                    QDateTime current_date_time = QDateTime::currentDateTime();
                    _400ECI.time_sce = current_date_time.time().second();
                    _400ECI.time_min = current_date_time.time().minute();
                    _400ECI.time_hour = current_date_time.time().hour();
                    _400ECI.time_day = current_date_time.date().day();
                    _400ECI.time_mon = current_date_time.date().month();
                    _400ECI.time_year = current_date_time.date().year()-2000;

                    _400ECI.toData(data);

                    emit signal_400mSend(data);
                }
                //信号 数据库操作
                //emit signal_SqlQuery(insert_sql);

                //信号 界面显示

            }
            return;
        case 0xce://库检信息
            {
                char crc14[14] = {0};
                for(int j=0;j<7;j++)
                {
                    crc14[j] = data.at(i+5+j);
                    crc14[j+7] = data.at(i+13+j);
                }
                uint16_t crc = CRC16(crc14,14);
                if((crc & 0xff) != data.at(4)) return; //前7个字节CRC错误，抛弃此帧
                if(((crc>>8) & 0xff) != data.at(12)) return; //后7个字节CRC错误，抛弃此帧
                if((CheckSum(data.data(),20)) != (data.at(20))); return; //校验和错误

                switch (data.at(3)) {
                case 0x40:
                {
                    _400mDataTestCommand _400mDTC;
                    _400mDTC.toJData(data);

                    //信号 数据库操作
                    //emit signal_SqlQuery(insert_sql);

                    _400mDTC.Head.command = 0x41;

                    QDateTime current_date_time =QDateTime::currentDateTime();
                    _400mDTC.time_sce = current_date_time.time().second();
                    _400mDTC.time_min = current_date_time.time().minute();
                    _400mDTC.time_hour = current_date_time.time().hour();
                    _400mDTC.time_day = current_date_time.date().day();
                    _400mDTC.time_mon = current_date_time.date().month();
                    _400mDTC.time_year = current_date_time.date().year()-2000;

                    _400mDTC.toData(data);

                    emit signal_400mSend(data);
                    //ifAnswer = true;
                }
                break;
                case 0x43:
                {
                    _400mGroundTelemetryCommand _400mGTC;
                    _400mGTC.toJData(data);

                    //信号 数据库操作
                    //emit signal_SqlQuery(insert_sql);
                }
                break;
                case 0x44:
                case 0x45:{
                    _400mGroundTelemetryResults _400mGTR;
                    _400mGTR.toJData(data);

                    //信号 数据库操作
                    //emit signal_SqlQuery(insert_sql);

                    _400mGTR.Head.command = 0x46;
                    _400mGTR.Answer();
                    _400mGTR.toData(data);

                    emit signal_400mSend(data);
                    }
                    break;
                default:
                    break;
                }
            }
            //信号 界面显示


            return;
        case 0xf6:
            //信号 数据库操作
            //400m握手应答
            //emit signal_SqlQuery(insert_sql);
            //信号 界面显示
            return;
        case 0xf3:
            //信号 数据库操作
            //400m信道切换
            //emit signal_SqlQuery(insert_sql);
            //信号 界面显示
            return;
        case 0x03:
            //信号 数据库操作
            //400m设置查询发射功率
            //emit signal_SqlQuery(insert_sql);
            //信号 界面显示
            return;
        default:
            return;
        }
    }
}

void Analysis::GMSRFrame(const QByteArray &recvdata)
{
    for(int i=0;i<recvdata.size();i++)//抛弃开头无效数据
    {
        //data.toHex();
        if((uchar)recvdata.at(i) != 0x10) continue;
        if(recvdata.at(i+1) != 0x02) continue;
        QByteArray data = recvdata.mid(i);

        int len = (data.at(2)<<8) + data.at(3);
        if(len > (data.size()-6))return;//该帧无效

        uint16_t crc = CRC16(data.data()+2,len);

        uint16_t datacrc = (data.at(len)<<8) + data.at(len+1);
        if(crc != datacrc) return; //crc错误

        if(data.at(data.size()-2) != 0x10)return ;//结束错误
        if(data.at(data.size()-1) != 0x03)return ;//结束错误

        //接收到应答帧
        if(data.at(9) == 0x91)
        {
            size_t qulen = resendQueue.size();
            for(size_t qui=0;qui<qulen;qui++)
            {
                if(resendQueue[qui].AnswerFrame == false)
                {
                    if(resendQueue[qui].Answer == true)
                    {
                        resendQueue.erase(resendQueue.begin()+qui);
                        return;
                    }
                    resendQueue[qui].AnswerFrame = true;
                }
            }
            return;
        }
        //发送应答帧
        QByteArray  AnswerFrame;
        GSMRAnswerFrame(AnswerFrame);
        emit signal_GMSRSend(data);

        _GSMRDataHead GSMRHead;
        GSMRHead.toJData(data);

        //消重发
        size_t qulen = resendQueue.size();
        for(size_t qui=0;qui<qulen;qui++)
        {
            _GSMRDataHead resendGSMRHead;
            resendGSMRHead.toJData(resendQueue[qui].senddata);
            if(resendGSMRHead.FrameCommand == GSMRHead.FrameCommand)
            { resendQueue.erase(resendQueue.begin()+qui); break;}
        }

        switch (GSMRHead.FrameCommand) {
            case 0x11:{
                _GSMREndColumnInfo GSMRECI;
                GSMRECI.toJData(data);
                if(GSMRECI.end != 0x1003)return ;//结束错误
                //应答
                switch (GSMRECI.command) {
                    case 0x24:
                    //数据库操作
                    case 0x91:
                    //数据库操作
                    case 0x93:
                    //数据库操作
                    case 0x83:
                    //数据库操作
                    case 0xb5:
                    //数据库操作
                    {
                        GSMRECI.command++;
                        QDateTime current_date_time =QDateTime::currentDateTime();
                        GSMRECI.time_sce = static_cast<uint8_t>(current_date_time.time().second());
                        GSMRECI.time_min = static_cast<uint8_t>(current_date_time.time().minute());
                        GSMRECI.time_hour = static_cast<uint8_t>(current_date_time.time().hour());
                        GSMRECI.time_day = static_cast<uint8_t>(current_date_time.date().day());
                        GSMRECI.time_mon = static_cast<uint8_t>(current_date_time.date().month());
                        GSMRECI.time_year = static_cast<uint8_t>(current_date_time.date().year()-2000);
                        GSMRECI.sendtype = 0x5d;
                        GSMRECI.toData(data);
                        emit signal_GMSRSend(data);
                    }
                    break;

                    case 0x31:
                    //数据库操作
                    break;
                    case 0xb1:
                    //数据库操作
                    break;
                default:
                    return;
                }
                //界面显示
            }
            break;

            case 0x21:{//GSMR模块状态
                _GSMRStatus GSMRstatus;
                GSMRstatus.toJData(data);

                //数据库操作
            }
            break;

            case 0x23:{//GSMR网络注册
                _GSMRNetworkRegist GSMRNR;
                GSMRNR.toJData(data);

                //数据库操作
            }
            break;

            case 0x25:{//GSMR网络注销
                _GSMRNetworkLogout GSMRNL;
                GSMRNL.toJData(data);
                //数据库操作
            }
            break;

            case 0x27:{//GSMR模块关机
                _GSMRNetworkLogout GSMRNL;
                GSMRNL.toJData(data);
                //数据库操作
            }
            break;

            case 0x29:{//GSMR查询IP
                _GSMRInquireIP GSMRIIP;
                GSMRIIP.toJData(data);
                //数据库操作
            }
            break;
        }
    }
}
void Analysis::addResendQueue(const QByteArray& senddata, bool Answer)
{
    Resend resend;
    if(Answer == false)
    {
        resend.Answer = true;
    }else{
        resend.Answer = false;
    }
    resend.senddata.append(senddata);
    resendQueue.push_back(resend);
}
