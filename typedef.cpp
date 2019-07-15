#include"typedef.h"

unsigned short CRC16(const char* pDataIn, int iLenIn)
{
     unsigned short wResult = 0;
     unsigned short wTableNo = 0;
     int i = 0;
    for( i = 0; i < iLenIn; i++)
    {
        wTableNo = ((wResult & 0xff) ^ (pDataIn[i] & 0xff));
        wResult = ((wResult >> 8) & 0xff) ^ wCRC16Table[wTableNo];
    }

    return wResult;
}

unsigned char checkSum(const char *src, unsigned long sizes) {
    unsigned char ret = 0;
    unsigned long i = 0;
    unsigned int sum = 0;
    const char *ptr = nullptr;

    ptr = src;
    if (ptr != nullptr) for (i = 0; i < sizes; i++) {
        sum += ((unsigned char*)ptr)[i];
    }
    ret = sum & 0xff;
    ret = ~ret;
    ret += 1;
    return ret;
}
void addDLE(QByteArray &data)
{
    int len = data.size();
    for (int i=1;i<len;i++) {
        if(data.at(i) == 0x10)
        {
            if(i != (len-2))
            {
                data.insert(i-1,0x10);
            }
        }
    }

}

void deleteDLE(QByteArray &data)
{
    int len = data.size();
    for (int i=0;i<len;i++) {
        if(data.at(i) == 0x10)
        {
            if((i+1)<len)
            {
                if(data.at(i) == 0x10)
                {
                   data.remove(i,1);
                }
            }
        }
    }
}
