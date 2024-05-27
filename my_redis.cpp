#include "my_redis.h"


my_redis::my_redis()
{
    // 初始化 ip, 端口
    m_ip = "127.0.0.1";
    m_port = 6379;

    // 连接测试
    ConnectRedis();

}

// 连接 redis
void my_redis::ConnectRedis()
{

   // 连接到Redis服务器
   //m_context = redisConnect(m_ip,m_port);
     m_context = redisAsyncConnect(m_ip,m_port);
   if (m_context == NULL ) {

        qDebug() << "redis Connection error: " << m_context->errstr ;
        //redisFree(m_context);
        redisAsyncFree(m_context);

   }else{
       m_adapter.setContext(m_context);
       qDebug() << "redis Connection success ";

   }
}

// 执行 redis 命令
//void my_redis::ExecRedis(char * m_cmd)
//{
//    //m_reply = (redisReply*)redisCommand(m_context, m_cmd);
//    //redisAsyncCommand(m_context, replyCallback, NULL, m_cmd);
//}

// 释放 redis 资源
void my_redis::FreeRedis()
{
    // 释放数据库连接
    if(m_context)
    {
        //freeReplyObject(m_context);
         m_adapter.disconnect();
       redisAsyncFree(m_context);
    }
    // 释放可能没有释放掉的 redisReply
    FreeReply();
}

// 释放 reply 指针
void my_redis::FreeReply()
{
    if(m_reply != NULL)
    {
        freeReplyObject(m_reply);
    }
}

