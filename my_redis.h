#ifndef MY_REDIS_H
#define MY_REDIS_H
#include <QObject>
#include <adapters/qt.h>
#include <hiredis.h>
#include <read.h>
#include <QApplication>
#include <QDebug>
#include <QImage>
#include <QApplication>
#include <QThread>
#include <QTimer>
class my_redis: public QObject {
    Q_OBJECT

public:
    // redis 句柄
    RedisQtAdapter m_adapter;
    redisAsyncContext* m_context;
    // redis 执行返回数据
    redisReply *m_reply;

    my_redis();

    // 连接 redis
    void ConnectRedis();

    // 执行 redis命令
   // void ExecRedis(char * m_cmd);

    // 释放资源
    void FreeRedis();

    // 释放 reply 指针
    void FreeReply();


private:


    // 执行命令的 cmd 字符串
    char * m_cmd;

    // 连接 ip，端口
    char * m_ip;
    int m_port;



};


#endif // MY_REDIS_H
