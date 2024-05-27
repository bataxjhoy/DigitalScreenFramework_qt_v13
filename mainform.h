#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTime>
#include "mvcameraclass.h"
#include <QThread>
#include <QGraphicsScene>
#include <QString>
#include <stdio.h>
#include <stdlib.h>

#include "usbcamera.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QWaitCondition>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QChartView>
#include <QtCharts>
#include <QTextToSpeech>
#pragma push_macro("slots")
#undef slots
#include <Python.h>
#include <numpy/arrayobject.h>
#pragma pop_macro("slots")
#include "my_redis.h"
#include "autoresize.h"
#include<QThread>
#include <QTcpServer> //监听套接字
#include <QTcpSocket> //通信套接字//对方的(客户端的)套接字(通信套接字)
#include "myprotocol.h"
namespace Ui {
class MainForm;
}


class MainForm : public QWidget
{
    Q_OBJECT

public:

    my_redis* redis;

    bool startTask=false;
    bool startFace=false;
    usbCamera* cameraTraj;//轨迹抓取
    QThread* threadCameraTraj;//出图
    QThread* threadTraj;

//    usbCamera* cameraFace;//人脸抓取
//    QThread* threadCameraFace;//出图
//    QThread* threadFace;
    QTcpSocket *tcpSocket; //通信套接字
    communicatprotol* myProtocol;
    bool connectFlag=false;//tcp connect flag
     int g_disply_fps;

     QTimer *timerface ;

    QString exprimentLabel;//实验标签

    QImage qImageForTraj;//用于轨迹检测
    //QMutex qImageForTrajMutex;

    QTimer *timer ;
    int  timeCount=60;

    QProcess *process ;


    AutoResize *m_autoResizeHandler;
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

    void getTaskAll();
    void getLoginInfo();

    void Timer_process();
    void Timerface_process();
    static void replyCallback(redisAsyncContext *redisContext, void *r, void *privdata);
    void openUsbCarema(bool caremaStatus );

    QImage ImageCenter(QImage  qimage,QLabel *qLabel);

    // 创建网络访问管理器
    QNetworkAccessManager* m_manger;
    // 创建请求对象
    QNetworkRequest request;
    void replyFinished(QNetworkReply *reply);

    void  login_init( );
    void showDigitPerson();

    void  seacherLonginPerson(QString avatarName);

    void init_python_home();

     PyObject* findTrackPInstance;//对象    
    void  init_findTrack_python();
    void UsePythonFindTrack();

    PyObject* getTrackGoalPInstance;//对象
    void  init_getTrackGoal();
    void  UseGetTrackGoal();

    PyObject* pInstance;//对象
    void  init_python();
    void  init_python_emo();
    void  init_python_similarity();
    void UsePythonface(QImage qImage);//人脸检测
    void UsePythonFindEmo( QImage qImage);//行为识别
    void UsePythonFindSimilarity();

    void init_learnTimebar_chart();
    void build_learnTimebar_chart();

    void init_learnProcess_chart();
    void build_learnProcess_chart();
    bool eventFilter(QObject *watched, QEvent *evt);
    QString arrToString(QByteArray buf);
private slots:

    void updateTrajImage(QImage);//traj
    void updateFaceImage(QImage);// face
    void on_btnMenu_Close_clicked();

    void on_btnMenu_Max_clicked();

    void on_btnMenu_Min_clicked();

    void on_btnExit_clicked();

    void on_btnMain_clicked();

    void on_btnConfig_clicked();

    void on_btnData_clicked();

    void on_btnHelp_clicked();

    void on_btnSetInfo_clicked();



    void on_btnStartWork_clicked();

    void on_btnSend_clicked();

    void on_btnClearRec_clicked();

    void on_btnLogin_clicked();

    void on_comBoxGroupMem_currentIndexChanged(int index);

    void on_btnSubmitTask_clicked();

    void threadTrajProcess();
//    void threadFaceProcess();

    void socket_Read_Data();
    void socket_Disconnected();
    void on_ConnectBtn_clicked();

    void on_ClearBtn_clicked();

signals:
    void cameraOperate(int);
    void redisOperate();
private:
    Ui::MainForm *ui;
    void resizeEvent(QResizeEvent *event);

};

#endif // MAINFORM_H
