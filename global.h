#ifndef GLOBAL_H
#define GLOBAL_H
#include <QMainWindow>
#include<QDebug>
#include <QSqlDatabase> //数据驱动
#include <QSqlQuery> //数据库执行语句
#include <QSqlTableModel>
#include <QSqlError>
#include <QDateTime>

#pragma push_macro("slots")
#undef slots
#include <Python.h>
#include <numpy/arrayobject.h>
#pragma pop_macro("slots")
extern PyObject* pInstance;//对象
extern QString  global_reserve_type;
extern QString  global_deviceId;
extern QString  global_reserve_name;
extern QDateTime  global_reserve_endtime;
extern int  global_task_count;
struct loginPerson {
    QString userName;
    QString  avatar;
    QDateTime loginTime;
    QString lastTask;//上一任务
    QString currentTask;//当前任务
    int currentTaskIndex;
     QString nextTask;//上一任务
};

struct loginGroup{
    QString groupname;
    QList<QString> listAllMember;
    QList<QString> listLoginMember;
    QDateTime loginTime;
    QString lastTask;//上一任务
    QString currentTask;//当前任务
    int currentTaskIndex;
    QString nextTask;//上一任务
};

extern loginPerson* login_person ;
extern loginGroup* login_group ;
extern bool global_login_flag;
void mql_init();


#endif // GLOBAL_H
