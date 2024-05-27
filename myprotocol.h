#ifndef MYPROTOCOL_H
#define MYPROTOCOL_H

#include <QObject>
class communicatprotol
{
public:
    communicatprotol();
    int checkData(QByteArray data);
    int checkSum(QByteArray sendArray,int start_index,int end_index);
    uint16_t checkCRC16(QByteArray senddata,int startIndex,int len);
};

#endif // COMMUNICATPROTOL_H
