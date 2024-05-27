#include "usbcamera.h"
int usbCamera::cameracount=0;

usbCamera::usbCamera()
{

}

usbCamera::~usbCamera()
{
    if(!capture.isOpened())
    {
        capture.release();
    }
}

bool usbCamera::open(int _index)
{
    qDebug()<<"open index="<<_index;
//    int desiredWidth = 1920; // 你想要的宽度
//    int desiredHeight = 1080; // 你想要的高度
    int desiredWidth = 1080; // 你想要的宽度
    int desiredHeight = 720; // 你想要的高度

    if(capture.open(_index, cv::CAP_DSHOW))
    {
        openFlag=true;
        capture.set(cv::CAP_PROP_FPS, 30);
        capture.set(cv::CAP_PROP_FRAME_WIDTH, desiredWidth);
        capture.set(cv::CAP_PROP_FRAME_HEIGHT, desiredHeight);
        capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G'));
        return true;
    } else {
        openFlag=false;
        return false;
    }
}

void usbCamera::close()
{
    capture.release();
}

cv::Mat usbCamera::read()
{
    cv::Mat mat;
    capture.read(mat);
    return mat;
}

void usbCamera::Operate(int _index)
{
    if(open(_index))
    {
        qDebug()<<"Camera open success!";
    } else {
        qDebug()<<"Camera open failed";
        return;
    }
    while(1)
    {
        //qApp->processEvents();
        cv::Mat matin=read();
        QImage image= Mat2QImage(matin);
        emit updateImage(image);
    }
}

QImage usbCamera::Mat2QImage(cv::Mat const& mat)
{

    cv::Mat temp;
    cv::cvtColor(mat, temp,CV_BGR2RGB);
    QImage image((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    image.bits();
    return image;
}

cv::Mat usbCamera::QImage2Mat(QImage const& image)
{
    cv::Mat tmp(image.height(),image.width(),CV_8UC3,(uchar*)image.bits(),image.bytesPerLine());
    cv::Mat mat;
    cv::cvtColor(tmp, mat,CV_BGR2RGB);
    return mat;
}

