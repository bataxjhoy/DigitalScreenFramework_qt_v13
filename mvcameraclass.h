#ifndef MVCAMERACLASS_H
#define MVCAMERACLASS_H
#include <QThread>
#include <QImage>
#include <windows.h>
#include "CameraApi.h"

class mvCameraClass
{
public:

    typedef struct _WIDTH_HEIGHT{
        int     display_width;
        int     display_height;
        int     xOffsetFOV;
        int     yOffsetFOV;
        int     sensor_width;
        int     sensor_height;
        int     buffer_size;
    }Width_Height;
    //SDK
    int                     g_hCamera = -1;     //设备句柄
    unsigned char           * g_pRawBuffer=NULL;     //raw数据
    unsigned char           * g_pRgbBuffer=NULL;     //处理后数据缓存区
    tSdkFrameHead           g_tFrameHead;       //图像帧头信息
    tSdkCameraCapbility     g_tCapability;      //设备描述信息


    int                     g_SaveParameter_num=0;    //保存参数组
    int                     g_SaveImage_type=0;         //保存图像格式

    Width_Height            g_W_H_INFO;         //显示画板到大小和图像大小
    BYTE                    *g_readBuf=NULL;    //画板显示数据区
    int                     g_read_fps=0;       //统计读取帧率
    int                     g_disply_fps=0;     //统计显示帧率
    bool                    g_record=false;//录制标志
     QVector<QRgb> grayColourTable;
    mvCameraClass();
    int init_SDK();
    void LoadParameter(int index);
    int set_Resolution(int index);
    void  set_TriggerMode(int index);
    void exposure_mode_Auto();
    void SetFrameSpeed(int index);
    void SetMirror(BOOL m_bHflip,BOOL m_bVflip);
    void InitRecord( char *pcSavePath);
    void StopRecord();
};


#endif // MVCAMERACLASS_H
