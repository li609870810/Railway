#ifndef ANALYSIS_H
#define ANALYSIS_H
#include<QByteArray>
#include<QObject>
#include<thread>
#include<vector>

class Analysis : public QObject
{
    Q_OBJECT
public:
    Analysis();
    Analysis(const Analysis&) = delete;  //阻止拷贝
    Analysis & operator = (const Analysis&) = delete; //阻止赋值
    //~Analysis()= delete; //阻止赋值

    void addResendQueue(const QByteArray &senddata, bool Answer = true);//加入重发，senddata：要重发的帧，AnswerFrame：此帧是否需要应答,默认需要应答

private:
    std::thread resendThread;
    int ResendThread();
    struct Resend
    {
        QByteArray senddata;
        int timeing;
        bool Answer;
        bool AnswerFrame;
        int count;
        Resend():timeing(0),Answer(false),AnswerFrame(false),count(0){}
    };
    typedef std::vector<Resend> ResendQueue;
    ResendQueue resendQueue;

public slots:
    void _400mFrame(const QByteArray& data);
    void GMSRFrame(const QByteArray& data);

signals:
    void signal_400mSend(const QByteArray& data);
    void signal_GMSRSend(const QByteArray& data);
    void signal_SqlQuery(const QString& data);
};

#endif // ANALYSIS_H
