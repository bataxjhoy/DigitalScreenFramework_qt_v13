#include "mvcameraclass.h"
#include <QDebug>


mvCameraClass::mvCameraClass()
{

}



// SDK等初始化操作
int mvCameraClass::init_SDK()
{
    int                     iCameraCounts = 4;
    int                     iStatus=-1;
    tSdkCameraDevInfo       tCameraEnumList[4];

    CameraSdkInit(1);//sdk初始化  0 English 1中文

    CameraEnumerateDevice(tCameraEnumList,&iCameraCounts);//枚举设备，并建立设备列表

    if(iCameraCounts==0){//没有连接设备
        return -1;
    }

    //相机初始化。初始化成功后，才能调用任何其他相机相关的操作接口
    iStatus = CameraInit(&tCameraEnumList[0],-1,-1,&g_hCamera);

    //初始化失败
    if(iStatus!=CAMERA_STATUS_SUCCESS){
        return -1;
    }
    //获得相机的特性描述结构体。该结构体中包含了相机可设置的各种参数的范围信息。决定了相关函数的参数
    CameraGetCapability(g_hCamera,&g_tCapability);

    //申请内存
    g_pRgbBuffer = (unsigned char*)malloc(g_tCapability.sResolutionRange.iHeightMax*g_tCapability.sResolutionRange.iWidthMax*3);
    g_readBuf = (unsigned char*)malloc(g_tCapability.sResolutionRange.iHeightMax*g_tCapability.sResolutionRange.iWidthMax*3);

    /*让SDK进入工作模式，开始接收来自相机发送的图像
    数据。如果当前相机是触发模式，则需要接收到
    触发帧以后才会更新图像。    */
    CameraPlay(g_hCamera);

    //设置图像处理的输出格式，彩色黑白都支持RGB24位
    if(g_tCapability.sIspCapacity.bMonoSensor){
        CameraSetIspOutFormat(g_hCamera,CAMERA_MEDIA_TYPE_MONO8);
    }else{
        CameraSetIspOutFormat(g_hCamera,CAMERA_MEDIA_TYPE_RGB8);
    }
     qDebug() << "MV connect success" << endl;
    return 0;
}
//加载参数组
void mvCameraClass::LoadParameter(int index)
{
    g_SaveParameter_num=index;

    //加载指定组的参数到相机中。
    CameraLoadParameter(g_hCamera,g_SaveParameter_num);
}

//设置分辨率
int  mvCameraClass::set_Resolution(int index)
{

    tSdkImageResolution     *pImageSizeDesc=g_tCapability.pImageSizeDesc;// 预设分辨率选择

    g_W_H_INFO.sensor_width=pImageSizeDesc[index].iWidth;
    g_W_H_INFO.sensor_height=pImageSizeDesc[index].iHeight;
    g_W_H_INFO.buffer_size= g_W_H_INFO.sensor_width*g_W_H_INFO.sensor_height;

    //设置预览的分辨率。
    CameraSetImageResolution(g_hCamera,&(pImageSizeDesc[index]));
    qDebug() << "MV SetImageResolution"<<g_W_H_INFO.sensor_width<<g_W_H_INFO.sensor_height <<endl;
    return 1;
}


//设置的触发模式。0表示连续采集模式；1表示软件触发模式；2表示硬件触发模式。
void  mvCameraClass::set_TriggerMode(int index)
{
    CameraSetTriggerMode(g_hCamera,index);
    qDebug() << "MV SetTriggerMode" << endl;
}


//曝光模式 自动
void mvCameraClass::exposure_mode_Auto()
{

    CameraSetAeState(g_hCamera,true);
//    //设置自动曝光时抗频闪功能的使能状态。对于手动曝光模式下无效。
//    CameraSetAntiFlick(g_hCamera,true);
//    CameraSetLightFrequency(g_hCamera,1);

    qDebug() << "MV exposure_mode_Auto" << endl;
}

//速度选择
void mvCameraClass::SetFrameSpeed(int index)
{
        /*
            设定相机输出图像的帧率。相机可供选择的帧率模式由
            CameraGetCapability获得的信息结构体中iFrameSpeedDesc
            表示最大帧率选择模式个数。
        */
        CameraSetFrameSpeed(g_hCamera,index);
    qDebug() << "MV SetFrameSpeed" << endl;
}
//设置镜像
void mvCameraClass::SetMirror(BOOL m_bHflip,BOOL m_bVflip)
{
    //获得图像的镜像状态。
    CameraSetMirror(g_hCamera, MIRROR_DIRECTION_HORIZONTAL, m_bHflip);
    CameraSetMirror(g_hCamera, MIRROR_DIRECTION_VERTICAL,   m_bVflip);
    qDebug() << "MV SetMirror" << endl;

}
//开始录制
void mvCameraClass::InitRecord( char *pcSavePath)
{

    CameraInitRecord
        (
            g_hCamera,
            1,      //mscv方式压缩
            pcSavePath,
            false,  //如果为 TRUE,则档大亍 2G 时自动分割
            80,     //录像的质量因子
            10     //录制帧率
            );
}
//停止录制
void mvCameraClass::StopRecord()
{

    CameraStopRecord(g_hCamera );
}
