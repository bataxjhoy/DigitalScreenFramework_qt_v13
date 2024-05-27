#ifndef USBCAMERA_H
#define USBCAMERA_H


#include <QObject>
#include <QDebug>
#include <QImage>
#include <QString>
#include <QThread>
#include <QTime>
#include <QApplication>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "iostream"

// 相机类：提供相机的基本操作
class usbCamera : public QObject
{
    Q_OBJECT
    cv::VideoCapture capture; //视频流捕获器
    static int cameracount; //存储相机数目

public:

    int                     g_read_fps=0;       //统计读取帧率
    int                     g_disply_fps=0;     //统计显示帧率

    usbCamera();
    ~usbCamera();
    bool openFlag=false;
    bool open(int _index);
    void close();
    cv::Mat read();
    cv::Mat matnow;
    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& src);
    static int getCameraCount(){//获取可用相机数目
        if(cameracount>0)return cameracount;
        cv::VideoCapture _capture;
        while(_capture.open(cameracount,cv::CAP_DSHOW)){
            cameracount++;
            _capture.release();
        }
        return cameracount;

    }

signals:
    void updateImage(QImage const&);

public slots:
    void Operate(int); // 当Camera类被MovetoThread时，该槽函数相当于QThread::run()

};


#endif // USBCAMERA_H
