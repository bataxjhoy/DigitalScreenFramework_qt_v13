#include "global.h"
 PyObject* pInstance;//对象
int  global_task_count;
QString  global_reserve_type;
QString  global_deviceId="1234";
QString  global_reserve_name;//预约名
QDateTime  global_reserve_endtime;//预约结束时间
loginPerson* login_person   = new loginPerson;
bool global_login_flag=false;
 loginGroup* login_group   = new loginGroup;
void mql_init()
{
    QSqlDatabase data_base = QSqlDatabase::addDatabase("QMYSQL");//添加驱动
    data_base.setHostName("127.0.0.1");  //设置主机地址
    data_base.setPort(3306);  //mysql设置端口
    data_base.setDatabaseName("digitalscreen_xjh");  //设置数据库名称
    data_base.setUserName("root");  //设置用户名
    data_base.setPassword("123456");  //设置密码
    if(!data_base.open())//打开数据库
    {
        qDebug()<<"connect failed";
        qDebug() << data_base.lastError();//.databaseText()  输出错误信息
    }
    else
        qDebug()<<"data base open success";
}
