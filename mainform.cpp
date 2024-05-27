#include "mainform.h"
#include "ui_mainform.h"
#include "iconhelper.h"
#include "loginwindow.h"
#include "addinfoform.h"
#include <QProcess>
#pragma execution_character_set("utf-8")


MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
     this->installEventFilter(this);
    m_autoResizeHandler=new AutoResize(this,this->rect().width(),this->rect().height());
    m_autoResizeHandler->setAutoResizeFlag(
               AutoResize::INCLUDE_BUTTON|AutoResize::INCLUDE_COMBOBOX|
               AutoResize::INCLUDE_EDITOR|AutoResize::INCLUDE_LABEL    );
       //add widget* manualy
       m_autoResizeHandler->addOtherItem(ui->progressBarGroup);
       m_autoResizeHandler->addOtherItem(ui->tabWidget);


       m_autoResizeHandler->pushAllResizeItem();
       ui->btnLogin->setVisible(false);

    //加载样式表
//    QFile file(":/qss/psblack.css");
//    if (file.open(QFile::ReadOnly)) {
//        QString qss = QLatin1String(file.readAll());
//        QString paletteColor = qss.mid(20, 7);
//        qApp->setPalette(QPalette(QColor(paletteColor)));
//        qApp->setStyleSheet(qss);
//        file.close();
//    }

    this->setWindowIcon(QIcon(":/new/prefix1/image/ai.png"));
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));



    ui->stackedWidget->setCurrentIndex(0);//主页面

    // 创建网络访问管理器--问答系统
    m_manger=new QNetworkAccessManager(this);
    //qDebug()<<m_manger->supportedSchemes();
    QUrl url("http://127.0.0.1:17860/api/chat_stream");
    request.setUrl(url);
    //设置需要设置响应报头
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      QVariant("application/json"));


    login_init( );//登录初始化

    //usb1相机抓取人脸 初始化
//    cameraFace = new usbCamera();
//    threadCameraFace =new QThread();
//    cameraFace->moveToThread(threadCameraFace);//将camera对象放在子线程
//    threadCameraFace->start();
//    connect(this, SIGNAL(cameraOperate(int)), cameraFace, SLOT(Operate(int)));
//    connect(cameraFace, SIGNAL(updateImage(QImage)), this, SLOT(updateFaceImage(QImage)));
//    emit cameraOperate(0);//开启


    redis=new my_redis();
    timerface = new QTimer(this);
    timerface->setSingleShot(true);// 设置单次触发
    connect(timerface, &QTimer::timeout, this, &MainForm::Timerface_process);
    timerface->start(0);//秒钟更新

//   faceThread = new MyThread;
//   connect(faceThread, SIGNAL(redis_updateImage(QImage)), this, SLOT(updateFaceImage(QImage)));//信号槽
//   faceThread->start();


    //相机抓取轨迹 初始化
    cameraTraj = new usbCamera();
    threadCameraTraj =new QThread();
    cameraTraj->moveToThread(threadCameraTraj);//将camera对象放在子线程
    threadCameraTraj->start();
    connect(this, SIGNAL(cameraOperate(int)), cameraTraj, SLOT(Operate(int)));
    connect(cameraTraj, SIGNAL(updateImage(QImage)), this, SLOT(updateTrajImage(QImage)));
    emit cameraOperate(1);//开启第一个相机

    threadTraj = new QThread();
    QObject::connect(threadTraj, &QThread::started, this, &MainForm::threadTrajProcess);


    //时间更新
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainForm::Timer_process);
    timer->start(1000);//1秒钟更新

    //启动脚本
    process = new QProcess();
    QString program = "G:/workspace/majun/code/zhiyuanchuang_scene_learning/zhiyuanchuang_scene_learning/code/project/body/body.bat"; // 替换为您的 .bat 文件的路径
    process->start(program);

    if (!process->waitForStarted()) {
        qDebug() << "无法启动" << program;
        return;
    }else{

        qDebug() << "bat 启动" << program;
    }



    tcpSocket = new QTcpSocket();
    myProtocol=new communicatprotol();
    //连接信号槽
    QObject::connect(tcpSocket, &QTcpSocket::readyRead, this, &MainForm::socket_Read_Data);
    QObject::connect(tcpSocket, &QTcpSocket::disconnected, this, &MainForm::socket_Disconnected);

    showDigitPerson();
}

void MainForm::showDigitPerson()
{
    QLabel *label = new QLabel(this);
    QMovie *movie = new QMovie(":/new/prefix1/image/digitPerson.gif");

    int x = this->width() -600; // 计算水平位置
    int y = this->height()-600; // 计算垂直位置
    //label->setGeometry(x, y, width, height);
    label->move(x, y);
    label->setMovie(movie);
    label->setStyleSheet("QLabel { background-color: transparent; }");
    movie->start();
    label->show();
    //      connect(movie, &QMovie::finished, this, [=]() {
    //          movie->stop();
    //          label->hide();
    //      });
    QTimer *timerTemp = new QTimer(this);
    timerTemp->start(3000);
    // 使用lambda表达式连接定时器的timeout信号
    connect(timerTemp, &QTimer::timeout, this, [=]() {
       movie->stop(); // 停止movie
       timerTemp->stop(); // 停止定时器，防止再次触发
        label->hide();
    });

    QString str="欢迎使用智慧场景学习平台";
    QTextToSpeech *Speecher=new QTextToSpeech;
    Speecher->say(str);

}

 void  MainForm::login_init( )
 {

    ui->globalUser_label->setText(" 用户名："+ global_reserve_name);
    getLoginInfo();
    getTaskAll();

    init_learnProcess_chart();
    build_learnProcess_chart();

    init_learnTimebar_chart();
    build_learnTimebar_chart();

    for(int i=0;i<login_group->listAllMember.count();i++)
        ui->comBoxGroupMem->addItem(login_group->listAllMember.at(i));//获取组员

    if(global_reserve_type=="group")//在线人员
    {
        for(int i=0;i<login_group->listLoginMember.count();i++)
            ui->comBoxLoginMem->addItem(login_group->listLoginMember.at(i));

    } else if(global_reserve_type=="person"){//个人登录不显示
        //ui->comBoxLoginMem->addItem(login_person->userName);
        ui->comBoxLoginMem->setVisible(false);
        ui->labelOnLine->setVisible(false);

    }

        init_python_home();
}

void MainForm::init_python_home()
{
    //加入python
    Py_SetPythonHome(L"G:/workspace/majun/conda/envs/scene_learning_1");
    // 1. 类似于先连接上Python

    Py_Initialize();

    import_array1();
    if (!Py_IsInitialized()) {
        qDebug() << "Fail to init Python.";
    }


    // 2. 加入python文件的路径
    PyRun_SimpleString("import os");
    PyRun_SimpleString("import sys");

    std::string path = "sys.path.append('G:/workspace/majun/code/zhiyuanchuang_scene_learning/zhiyuanchuang_scene_learning/code/project/track/tools')";
    PyRun_SimpleString(&path[0]);

    std::string path1 = "sys.path.append('G:/workspace/majun/code/zhiyuanchuang_scene_learning/zhiyuanchuang_scene_learning/code/project/track/project')";
    PyRun_SimpleString(&path1[0]);
    PyRun_SimpleString("print(sys.path)");

    init_findTrack_python();
    init_getTrackGoal();

}

 void  MainForm::init_findTrack_python()
 {

     // 3. 找到要用的python文件
      PyObject * pModule = PyImport_ImportModule("track_api");
     if (pModule == NULL) {
         PyErr_Print(); // 打印 Python 错误信息
         qDebug() <<"Fail to load Python module (track_api.py)";
     }

     // 1. 找到Python的类
     PyObject* pDict = PyModule_GetDict(pModule);
     if(!pDict) {
         qDebug() << "Cant find dictionary.";
     }
      Py_DECREF(pModule);

     PyObject* pClassCalc = PyDict_GetItemString(pDict, "TrackAPI");
     if (!pClassCalc) {
         qDebug() << "Cant find PythonClass class.";
     }
     Py_DECREF(pDict);
     // 2. 初始化对象
     PyObject* pConstruct = PyInstanceMethod_New(pClassCalc);
     if (!pConstruct) {
         qDebug() << "Cant find PythonClass constructor.";
     }
     Py_DECREF(pClassCalc);

     PyObject* cons_args = PyTuple_New(0);

     findTrackPInstance = PyObject_CallObject(pConstruct,cons_args);
     if (!findTrackPInstance) {
         qDebug() << "Cant construct instance.";
     }
     Py_DECREF(cons_args);
     Py_DECREF(pConstruct);


      qDebug() << "python init success " ;

 }

 void MainForm::UsePythonFindTrack( )
 {

     if(!qImageForTraj.isNull())
     {
        // QMutexLocker locker(&qImageForTrajMutex); // 锁定互斥锁
         int width = qImageForTraj.width();
         int height = qImageForTraj.height();
         qDebug()<<"in "<<"qImageForTraj.width()"<<qImageForTraj.width()<<"qImageForTraj.height()"<<qImageForTraj.height()<<"qImageForTraj.format()"<<qImageForTraj.format()<<endl;

          unsigned char *CArrays = (unsigned  char*)malloc(sizeof(unsigned char) * width*height*3);


          memcpy(CArrays, qImageForTraj.bits(), width*height*3);
         //qImageForTrajMutex.unlock(); // 手动解锁互斥锁

         // 创建 NumPy 数组
         npy_intp dims[3] = { height, width, 3 }; // 假设图像是RGB格式的
         PyObject* imageArray = PyArray_SimpleNewFromData(3, dims, NPY_UINT8, (void*)CArrays);

         //class PyThreadStateLock PyThreadLock;//获取全局锁

        PyObject* pResult  = PyObject_CallMethod(findTrackPInstance, "create_img2qt", "Os", imageArray,exprimentLabel.toUtf8().constData());//函数传参
        Py_DECREF(imageArray);

        if (pResult == nullptr) {
            PyErr_Print(); // 打印 Python 错误信息
           qDebug()<<"cant UsePythonFindTrack"<<endl;
           return;
        }
        if (PyTuple_Check(pResult)) {
           Py_ssize_t size = PyTuple_Size(pResult);
            qDebug()<<"size="<<size<<endl;
            //1111111111111111111111111111111111111111111111.接收图片
            PyObject* imageData = PyTuple_GetItem(pResult, 0);
            if (imageData == nullptr) {
                    qDebug()<<"null"<<endl;
                    Py_DECREF(pResult);
                    return;
            }
            if (!PyArray_Check(imageData)) {
                qDebug() << "imageData is not a NumPy array" << endl;
                Py_DECREF(imageData);
                Py_DECREF(pResult);
                return;
            }


            memcpy(CArrays,PyArray_DATA(imageData),width*height*3);
            //Py_DECREF(imageData);//为啥会报错

            QImage imgData((unsigned char*)CArrays, width, height,  QImage::Format_RGB888);
            qDebug()<<"out "<<"imgData.width()"<<imgData.width()<<"imgData.height()"<<imgData.height()<<"imgData.format()"<<imgData.format()<<endl;

           if(!imgData.isNull())
           {
            ui->TrajLabel->setPixmap(QPixmap::fromImage(imgData.scaled(ui->TrajLabel->size(), Qt::KeepAspectRatio)));
            ui->TrajLabel->setScaledContents(true);
           }


            //2222222222222222222222222222222222222222222222222222222222222.轨迹接收
            PyObject* trjImage = PyTuple_GetItem(pResult,1);//解析名字  数组
            if (trjImage == nullptr) {
                    qDebug()<<"null"<<endl;
                    Py_DECREF(pResult);
                    return;
            }
            unsigned char *Arrays = (unsigned  char*)malloc(sizeof(unsigned char) * 640*640*3);
            mempcpy(Arrays,PyArray_DATA(trjImage),640*640*3);

            QImage imgTrj((unsigned char*)Arrays, 640, 640,  QImage::Format_RGB888);
            qDebug()<<"imgTrj.width()"<<imgTrj.width()<<"imgTrj.height()"<<imgTrj.height()<<"imgTrj.format()"<<imgTrj.format()<<endl;


            if(!imgTrj.isNull())
            {
             ui->labelTrj->setPixmap(QPixmap::fromImage(imgTrj.scaled(ui->labelTrj->size(), Qt::KeepAspectRatio)));
             ui->labelTrj->setScaledContents(true);
            }
            //Py_DECREF(trjImage);//为啥会报错
            free(Arrays) ;
            Arrays = nullptr;

        }
        Py_DECREF(pResult);
        free(CArrays) ;
        CArrays = nullptr;
    }
    else{
        qDebug()<<"qImage is null"<<endl;
     }

}


 void  MainForm::init_getTrackGoal()
 {


      qDebug() << "init getTrackGoal start";
     // 3. 找到要用的python文件
      PyObject * pModule = PyImport_ImportModule("track_score");
     if (pModule == NULL) {
         PyErr_Print(); // 打印 Python 错误信息
         qDebug() <<"Fail to load Python module (track_score.py)";
     }

     // 1. 找到Python的类
     PyObject* pDict = PyModule_GetDict(pModule);
     if(!pDict) {
         qDebug() << "Cant find dictionary.";
     }
      Py_DECREF(pModule);

     PyObject* pClassCalc = PyDict_GetItemString(pDict, "TrackScoring");
     if (!pClassCalc) {
         qDebug() << "Cant find PythonClass TrackScoring class.";
     }
     Py_DECREF(pDict);
     // 2. 初始化对象
     PyObject* pConstruct = PyInstanceMethod_New(pClassCalc);
     if (!pConstruct) {
         qDebug() << "Cant find PythonClass constructor.";
     }
     Py_DECREF(pClassCalc);

     PyObject* cons_args = PyTuple_New(0);

     getTrackGoalPInstance = PyObject_CallObject(pConstruct,cons_args);
     if (!getTrackGoalPInstance) {
         qDebug() << "Cant construct TrackScoring instance.";
     }
     Py_DECREF(cons_args);
     Py_DECREF(pConstruct);


      qDebug() << "python TrackScoring init success " ;
 }
 void  MainForm::UseGetTrackGoal()
 {
     qDebug() <<"UseGetTrackGoal start";
 //     class PyThreadStateLock PyThreadLock;//获取全局锁

     PyObject* restult=PyObject_CallMethod(getTrackGoalPInstance, "get_experiment_score", "s", exprimentLabel.toUtf8().constData());//函数传参
     if (restult == NULL) {

         PyErr_Print();
         qDebug() <<"get_experiment_score failed!";
         return;
     }
     else if (PyList_Check(restult))
     {         
          Py_ssize_t length = PyList_Size(restult);
          PyObject* item1 =  PyList_GetItem(restult, 0);
          PyObject* item2 =  PyList_GetItem(restult, 1);
          PyObject* item3 =  PyList_GetItem(restult, 2);
          PyObject* item4 =  PyList_GetItem(restult, 3);
          PyObject* item5 =  PyList_GetItem(restult, 4);

          ui->labelResult->setText(QString("实验结果相似度：直线：%1  圆形：%2  正方形：%3  三角形：%4 矩形：%5")
                  .arg(QString::number(PyFloat_AsDouble(item1))).arg(QString::number(PyFloat_AsDouble(item2)))
                  .arg(QString::number(PyFloat_AsDouble(item3))).arg(QString::number(PyFloat_AsDouble(item4))).arg(QString::number(PyFloat_AsDouble(item5))));
//           Py_DECREF(item1);
//           Py_DECREF(item2);//多次调用会报错，要注释
     }
     else
     {

         qDebug() <<"error PyList_Check";
     }
    // Py_DECREF(restult);//同时跑会报错，要注释
 }



void  MainForm::init_python_similarity()
{
    //加入python环境 不同接口环境不同
    Py_SetPythonHome(L"D:/software/computer/Anaconda/envs/resultDetect");
    // 1. 类似于先连接上Python

    Py_Initialize();
    import_array1();
    if (!Py_IsInitialized()) {
         qDebug() << "Fail to init Python.";
    }

    // 2. 加入python文件的路径
    PyRun_SimpleString("import os");
    PyRun_SimpleString("import sys");
    //轨迹识别
    std::string path= "sys.path.append('G:/DigitalScreen/yolo_tracking-master/yolo_tracking-master/track_fun')";
    PyRun_SimpleString(&path[0]);
    std::string path1= "sys.path.append('G:/DigitalScreen/yolo_tracking-master/yolo_tracking-master/')";
    PyRun_SimpleString(&path1[0]);

    PyRun_SimpleString("print(sys.path)");
    // 3. 找到要用的python文件
    pInstance= PyImport_ImportModule("similarity_xjh");
    if (pInstance == NULL) {
         PyErr_Print(); // 打印 Python 错误信息
         qDebug() <<"Fail to load Python module (similarity_xjh.py)";
    }

    UsePythonFindSimilarity();

}
void MainForm::UsePythonFindSimilarity()
{
    // 2. 构建参数，调用
    PyObject* pRet =PyObject_CallMethod(pInstance, "find_similarity", "ss", "G:/DigitalScreen/采集视频/矩形1.mp4","G:/DigitalScreen/采集视频/直角梯形_上边30下边50.mp4");

    // 3. 得到返回值
    if(!pRet)
    {
         PyErr_Print(); // 打印 Python 错误信息
         qDebug()<<"cant UsePython Find_Similarity"<<endl;

    }else{
          PyErr_Print(); // 打印 Python 错误信息
         double ret = PyFloat_AsDouble(pRet);

         qDebug() << "相似度: " << ret;
    }Py_DECREF(pRet);

}

void  MainForm::init_python_emo()
{

    //加入python
    Py_SetPythonHome(L"D:/software/computer/Anaconda/envs/yolwf");
    // 1. 类似于先连接上Python

    Py_Initialize();
    import_array1();
    if (!Py_IsInitialized()) {
         qDebug() << "Fail to init Python.";
    }

    // 2. 加入python文件的路径
    PyRun_SimpleString("import os");
    PyRun_SimpleString("import sys");
    std::string path = "sys.path.append('G:/DigitalScreen/YOWOF-main')";
    PyRun_SimpleString(&path[0]);
    PyRun_SimpleString("print(sys.path)");

    // 3. 找到要用的python文件
    pInstance= PyImport_ImportModule("demo_xjh");
    if (pInstance == NULL) {
         PyErr_Print(); // 打印 Python 错误信息
         qDebug() <<"Fail to load Python module (demo_xjh.py)";
    }
    else qDebug() << "init_python_emo success.";
    //通过图片检测---怎么会为空
    //QImage qImage ("G:/DigitalScreen/StuEmo/images/1.png");
//    QImage qImage("C:/Users/Administrator/Desktop/DigitalScreenFramework_qt_v2/1.png");
//    qDebug()<<"qImage.width()"<<qImage.width()<<"qImage.height()"<<qImage.height()<<"qImage.format()"<<qImage.format()<<endl;
//    UsePythonFindEmo(qImage);

}

void MainForm::UsePythonFindEmo( QImage qImage)
{
    if(!qImage.isNull())
    {
         int width = qImage.width();
         int height = qImage.height();
         unsigned char *CArrays  = new unsigned char[width * height * 3];
         qDebug()<<"qImage.width()"<<qImage.width()<<"qImage.height()"<<qImage.height()<<"qImage.format()"<<qImage.format()<<endl;

         int index =0;
         for (int i = 0; i < height; i++)
         {
             for (int j = 0; j < width; j++)
             {
                 QRgb pixel = qImage.pixel( j,i);

                 CArrays[index++] = qRed(pixel);
                 CArrays[index++] = qGreen(pixel);
                 CArrays[index++] = qBlue(pixel);
             }
         }
         // 创建 NumPy 数组
         npy_intp dims[3] = { height, width, 3 }; // 假设图像是RGB格式的
         PyObject* imageArray = PyArray_SimpleNewFromData(3, dims, NPY_UINT8, (void*)CArrays);


         // 2. 构建参数，调用
        PyObject * imageData =  PyObject_CallMethod(pInstance, "detect_person_emo", "O", imageArray);

         // 3. 得到返回值
         Py_DECREF(imageArray);
         if(!imageData)
         {
             PyErr_Print(); // 打印 Python 错误信息
             qDebug()<<"cant UsePythonFindEmo"<<endl;
             return ;
         }

         // qDebug()<<"end UsePythonface"<<endl;
         mempcpy(CArrays,PyArray_DATA(imageData),width*height*3);
         QImage img((unsigned char*)CArrays, width, height,  QImage::Format_RGB888);
         //qDebug()<<"img.width()"<<img.width()<<"img.height()"<<img.height()<<"img.format()"<<img.format()<<endl;

         CArrays = nullptr;
         delete[] CArrays;

         Py_DECREF(imageData);

         if(!img.isNull())
         {
          ui->FaceLabel->setPixmap(QPixmap::fromImage(img.scaled(ui->FaceLabel->size(), Qt::KeepAspectRatio)));
          ui->FaceLabel->setScaledContents(true);
         }
    }
    else{

        qDebug()<<"qImage is null"<<endl;

    }
}

void  MainForm::init_python()
{

    //加入python
    Py_SetPythonHome(L"D:/software/computer/Anaconda/envs/digitalscreen");
    // 1. 类似于先连接上Python

    Py_Initialize();
    import_array1();
    if (!Py_IsInitialized()) {
        qDebug() << "Fail to init Python.";
    }


    // 2. 加入python文件的路径
    PyRun_SimpleString("import os");
    PyRun_SimpleString("import sys");
    std::string path = "sys.path.append('G:/DigitalScreen/StuEmo/realtime_detect')";
    PyRun_SimpleString(&path[0]);
    PyRun_SimpleString("print(sys.path)");

    // 3. 找到要用的python文件
     PyObject * pModule = PyImport_ImportModule("capture_xjh");
    if (pModule == NULL) {
        qDebug() <<"Fail to load Python module (capture_xjh.py)";
    }

    // 1. 找到Python的类
    PyObject* pDict = PyModule_GetDict(pModule);
    if(!pDict) {
        qDebug() << "Cant find dictionary.";
    }
     Py_DECREF(pModule);

    PyObject* pClassCalc = PyDict_GetItemString(pDict, "RtDetector");
    if (!pClassCalc) {
        qDebug() << "Cant find PythonClass class.";
    }
    Py_DECREF(pDict);
    // 2. 初始化对象
    PyObject* pConstruct = PyInstanceMethod_New(pClassCalc);
    if (!pConstruct) {
        qDebug() << "Cant find PythonClass constructor.";
    }
    Py_DECREF(pClassCalc);

    PyObject* cons_args = PyTuple_New(5);
    PyTuple_SetItem(cons_args, 0, Py_BuildValue("s",  "group1"));
    PyTuple_SetItem(cons_args, 1, Py_BuildValue("s",  "G:/DigitalScreen/StuEmo/GROUP_DATA/"));
    PyTuple_SetItem(cons_args, 2, Py_BuildValue("s",   "G:/DigitalScreen/StuEmo/weights/detr_face_body.pt"));
    PyTuple_SetItem(cons_args, 3, Py_BuildValue("s",   "G:/DigitalScreen/StuEmo/realtime_detect/Person_reID/model/ft_ResNet50/net_last.pth"));
    PyTuple_SetItem(cons_args, 4, Py_BuildValue("O",   Py_True));

    pInstance = PyObject_CallObject(pConstruct, cons_args);
    if (!pInstance) {
        qDebug() << "Cant construct instance.";
    }
    Py_DECREF(cons_args);
    Py_DECREF(pConstruct);
     qDebug() << "success " ;
    // PyObject* methods = PyObject_Dir(pInstance);
    // if (methods) {
    //     // 遍历返回的方法列表
    //     for (Py_ssize_t i = 0; i < PyList_GET_SIZE(methods); ++i) {
    //         PyObject* method = PyList_GET_ITEM(methods, i);
    //         const char* methodName = PyUnicode_AsUTF8(method);
    //         qDebug() << "Method Name:" << methodName;
    //     }
    //     Py_DECREF(methods);
    // } else {
    //     qDebug() << "Failed to get methods of the instance.";
    // }

    //测试
    // PyObject* pRet =PyObject_CallMethod(pInstance,"addTest1","ii",5,6);
    // if (!pRet) {
    //     qDebug() << "Cant addTest.";
    // }
    // else{
    //     double ret = PyFloat_AsDouble(pRet);
    //     qDebug() << "sum: " << ret;
    // }

    // Py_DECREF(pRet);

    //通过图片检测
//     QImage qImage ("G:/DigitalScreen/StuEmo/images/1.png");
//     UsePythonface(qImage);
}

void MainForm::UsePythonface( QImage qImage)
{
    if(!qImage.isNull())
    {
        int width = qImage.width();
        int height = qImage.height();
        unsigned char *CArrays  = new unsigned char[width * height * 3];
        qDebug()<<"qImage.width()"<<qImage.width()<<"qImage.height()"<<qImage.height()<<"qImage.format()"<<qImage.format()<<endl;

        int index =0;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                QRgb pixel = qImage.pixel( j,i);

                CArrays[index++] = qRed(pixel);
                CArrays[index++] = qGreen(pixel);
                CArrays[index++] = qBlue(pixel);
            }
        }
        //qDebug()<< CArrays[width*height*3-1] <<endl;
        // 创建 NumPy 数组
        npy_intp dims[3] = { height, width, 3 }; // 假设图像是RGB格式的
        PyObject* imageArray = PyArray_SimpleNewFromData(3, dims, NPY_UINT8, (void*)CArrays);

        PyObject* imageData = PyObject_CallMethod(pInstance, "process_frame", "O", imageArray);
        Py_DECREF(imageArray);
        if(!imageData)
        {
            PyErr_Print(); // 打印 Python 错误信息
            qDebug()<<"cant UsePythonface"<<endl;
            return ;
        }

        // qDebug()<<"end UsePythonface"<<endl;
        mempcpy(CArrays,PyArray_DATA(imageData),width*height*3);
        QImage img((unsigned char*)CArrays, width, height,  QImage::Format_RGB888);
        //qDebug()<<"img.width()"<<img.width()<<"img.height()"<<img.height()<<"img.format()"<<img.format()<<endl;

        CArrays = nullptr;
        delete[] CArrays;

        Py_DECREF(imageData);

        if(!img.isNull())
        {
         ui->FaceLabel->setPixmap(QPixmap::fromImage(img.scaled(ui->FaceLabel->size(), Qt::KeepAspectRatio)));
         ui->FaceLabel->setScaledContents(true);
        }

   }
   else{

       qDebug()<<"qImage is null"<<endl;

   }
}


//十六进制转字符串
QString MainForm::arrToString(QByteArray buf){
    QString strDis;
    QString strTemp = buf.toHex().data();//以十六进制显示
    strTemp = strTemp.toUpper ();//转换为大写
    for(int i = 0;i<strTemp.length ();i+=2)//填加空格
    {
        QString st = strTemp.mid (i,2);
        strDis += st;
        strDis += " ";
    }
    return strDis;
}
//tcp数据读取
void MainForm::socket_Read_Data()
{

    QByteArray dataBuff = tcpSocket->readAll();
    QByteArray jsonArr;
    int res=myProtocol->checkData(dataBuff);
    if(res==0)//接收成功
    {
       unsigned char cmd=dataBuff.at(2)& 0xFF;

       if(cmd==0x1c)//状态上报
       {
            unsigned char ledStatus=dataBuff.at(4)& 0xFF;
            if(ledStatus&0x01)
            {
                ui->m1p_led->setStyleSheet(ui->m1p_led->styleSheet()+ "border-image: url(:/new/prefix1/image/redLed.png);");
            }else{
                ui->m1p_led->setStyleSheet(ui->m1p_led->styleSheet()+ "border-image: url(:/new/prefix1/image/grayLed.png);");
            }
            if(ledStatus&0x02)
            {
                ui->m1z_led->setStyleSheet(ui->m1z_led->styleSheet()+ "border-image: url(:/new/prefix1/image/redLed.png);");
            }else{
                ui->m1z_led->setStyleSheet(ui->m1z_led->styleSheet()+ "border-image: url(:/new/prefix1/image/grayLed.png);");
            }
            if(ledStatus&0x04)
            {
                ui->m1n_led->setStyleSheet(ui->m1n_led->styleSheet()+ "border-image: url(:/new/prefix1/image/redLed.png);");
            }else{
                ui->m1n_led->setStyleSheet(ui->m1n_led->styleSheet()+ "border-image: url(:/new/prefix1/image/grayLed.png);");
            }
            if(ledStatus&0x08)
            {
                ui->m2p_led->setStyleSheet(ui->m2p_led->styleSheet()+ "border-image: url(:/new/prefix1/image/redLed.png);");
            }else{
                ui->m2p_led->setStyleSheet(ui->m2p_led->styleSheet()+ "border-image: url(:/new/prefix1/image/grayLed.png);");
            }if(ledStatus&0x10)
            {
                ui->m2z_led->setStyleSheet(ui->m2z_led->styleSheet()+ "border-image: url(:/new/prefix1/image/redLed.png);");
            }else{
                ui->m2z_led->setStyleSheet(ui->m2z_led->styleSheet()+ "border-image: url(:/new/prefix1/image/grayLed.png);");
            }
            if(ledStatus&0x20)
            {
                ui->m2n_led->setStyleSheet(ui->m2n_led->styleSheet()+ "border-image: url(:/new/prefix1/image/redLed.png);");
            }else{
                ui->m2n_led->setStyleSheet(ui->m2n_led->styleSheet()+ "border-image: url(:/new/prefix1/image/grayLed.png);");
            }
       }
       ui->textEditRead->append(arrToString(dataBuff));//显示读到的数据
       ui->textEditRead->moveCursor(QTextCursor::EndOfLine);

       dataBuff.clear();
    }
    else if(res==-3)//接收失败
    {
       ui->textEditRead->setText(arrToString(dataBuff));
       dataBuff.clear();
    }

}
//断开连接时
void MainForm::socket_Disconnected()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    connectFlag=false;
    ui->ConnectBtn->setText("连接");
   ui->ConnectBtn->setStyleSheet(ui->ConnectBtn->styleSheet()+ "QPushButton{ color: blue;}");
   ui->IPTextEdit->setEnabled(true);
   ui->PORTTextEdit->setEnabled(true);
}
//连接
void MainForm::on_ConnectBtn_clicked()
{
    if(connectFlag==false)
    {
        QString IP;
        int port;

        //获取IP地址
        IP = ui->IPTextEdit->toPlainText();
        //获取端口号
        port = ui->PORTTextEdit->toPlainText().toInt();

        //取消已有的连接
        tcpSocket->abort();
        //连接服务器
        tcpSocket->connectToHost(IP, port);

        //等待连接成功
        if(!tcpSocket->waitForConnected(3000))
        {
            qDebug() << "Connection failed!";
            return;
        }
        qDebug() << "Connect successfully!";

        connectFlag=true;
        ui->ConnectBtn->setText("断开");
       ui->ConnectBtn->setStyleSheet(ui->ConnectBtn->styleSheet()+ "QPushButton{ color: red;}");
       ui->IPTextEdit->setEnabled(false);
       ui->PORTTextEdit->setEnabled(false);
    }
    else
    {
        //断开连接
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
        connectFlag=false;
        ui->ConnectBtn->setText("连接");
        ui->ConnectBtn->setStyleSheet(ui->ConnectBtn->styleSheet()+ "QPushButton{ color: blue;}");
        ui->IPTextEdit->setEnabled(true);
        ui->PORTTextEdit->setEnabled(true);
    }
}
MainForm::~MainForm()
{

    // 关闭Python
//    Py_DECREF(pInstance);
//    Py_Finalize();
    if(NULL != tcpSocket)
    {
        //主动和客户端端口断开连接
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
        tcpSocket = NULL;
    }

    redis->FreeRedis();
    delete ui;
}
void MainForm::resizeEvent(QResizeEvent *event)
{
    m_autoResizeHandler->doAutoResize();
}

//图片居中显示,图片大小与label大小相适应
QImage MainForm::ImageCenter(QImage  qimage,QLabel *qLabel)
{
    QImage image;
    QSize imageSize = qimage.size();
    QSize labelSize = qLabel->size();

    double dWidthRatio = 1.0*imageSize.width() / labelSize.width();
    double dHeightRatio = 1.0*imageSize.height() / labelSize.height();
    if (dWidthRatio>dHeightRatio)
    {
        image = qimage.scaledToWidth(labelSize.width());
    }
    else
    {
        image = qimage.scaledToHeight(labelSize.height());
    }
    return image;

}


//更新图片
void MainForm::updateTrajImage(QImage image)
{

    //qImageForTraj=new QImage(image);
    qImageForTraj=image;
    cameraTraj->g_read_fps++;
    if(!image.isNull()&&startTask==false)
    {
     ui->TrajLabel->setPixmap(QPixmap::fromImage(image.scaled(ui->TrajLabel->size(), Qt::KeepAspectRatio)));
     ui->TrajLabel->setScaledContents(true);
    }

}
//线程处理
void MainForm::threadTrajProcess()
{

    while(startTask)
    {
        cameraTraj->g_disply_fps++;
        if(!qImageForTraj.isNull())//开始任务
        {
            UsePythonFindTrack();
        }
        qDebug()<<"UsePythonFindTrack";
        //QThread::msleep(10);//会阻塞线程
        QEventLoop loop;//非阻塞延时
        QTimer::singleShot(50, &loop, SLOT(quit())); // 等待0.05秒后退出循环
        loop.exec(); // 进入事件循环等待
    }
}
 void MainForm::replyCallback(redisAsyncContext *redisContext, void *r, void *privdata) {
   MainForm *self = static_cast<MainForm*>(privdata);
   redisReply *reply = static_cast<redisReply*>(r);
    //qDebug()<<"get redis replyCallback ";
   if(reply== NULL|| reply->type != REDIS_REPLY_STRING)
   {

       qDebug()<<"Failed to get image\n";
       self->timerface->setSingleShot(true);
       self->timerface->start(0);
       return;
   }
   QByteArray imageData = QByteArray::fromBase64(reply->str);
   //qDebug() << "Decoded image data size:" << imageData.size();

    if (!imageData.isEmpty()) {
        // 尝试从解码后的数据创建 QImage
        QImage qImageFace((unsigned char*)imageData.constData(), 1920, 1080, QImage::Format_RGB888);

        if (!qImageFace.isNull()) {
            self->ui->FaceLabel->setPixmap(QPixmap::fromImage(qImageFace.scaled(self->ui->FaceLabel->size(), Qt::KeepAspectRatio)));
            self->ui->FaceLabel->setScaledContents(true);
        } else {
            // 加载图像失败
           qDebug() << "Image format:" << qImageFace.format();
           qDebug()<<"qImageFace isNull";
        }
    }
    self->timerface->setSingleShot(true);
    self->timerface->start(0);
   /* 释放回复对象 */
  // freeReplyObject(reply);释放会崩溃
}

//1s定时器
 void MainForm::Timerface_process()
{
     g_disply_fps++;
    char strCmd[30];
    sprintf(strCmd,  "LINDEX camera_images %d", -1);
    int retval=redisAsyncCommand( redis->m_context, replyCallback, this, strCmd);

    //qDebug()<<"get redis retval "<<retval;
}

void MainForm::updateFaceImage(QImage image)
{
    //cameraFace->g_read_fps++;
    if(!image.isNull())
    {
     ui->FaceLabel->setPixmap(QPixmap::fromImage(image.scaled(ui->FaceLabel->size(), Qt::KeepAspectRatio)));
     ui->FaceLabel->setScaledContents(true);
    }
}


//1s定时器
void MainForm::Timer_process()
{

    QTime  currentTime;
    timeCount++;


    //显示帧率
    //if(timeCount%10==0)
    {
        ui->labelMvFs->setText(QString("Capture fps: %1  Display fps :%2").arg(QString::number(cameraTraj->g_read_fps, 'f', 2)).arg(QString::number(cameraTraj->g_disply_fps, 'f', 2)));
        cameraTraj->g_read_fps=0;
        cameraTraj->g_disply_fps=0;
//        ui->labelUsbFs->setText(QString("Capture fps: %1  Display fps :%2").arg(QString::number(cameraFace->g_read_fps, 'f', 2)).arg(QString::number(cameraFace->g_disply_fps, 'f', 2)));
//        cameraFace->g_read_fps=0;
//        cameraFace->g_disply_fps=0;
        ui->labelUsbFs->setText(QString(" Display fps :%1").arg(QString::number(g_disply_fps, 'f', 2)));
        g_disply_fps=0;
        currentTime= QTime::currentTime();
        ui->CurTime_label->setText(" 当前时间: "+currentTime.toString(" HH:mm:ss"));
    }

    if(timeCount>=60)//一分钟更新
    {
        timeCount=0;
        currentTime= QTime::currentTime();

        QTime temp=global_reserve_endtime.time();
        int diff=currentTime.secsTo(temp);

        if(diff>0)//设定一小时
        {
            int minutes=diff/60;
            ui->remainTime_label->setText(" 剩余时长："+QString::number(minutes)+" 分钟");

        }else{
            ui->remainTime_label->setText(" 剩余时长：0 分钟");
        //            QMessageBox::information(this,"提示：","学习时间已用完！");
        //            this->close();
        }
    }


}
//获取登录时间
void MainForm::getTaskAll()
{
    QSqlQuery query;
    int taskCount=0;
    bool findCurrentTaskFlag=0;
    bool findNectTaskFlag=0;
    QString sql= QString("SELECT * FROM sys_Task  ORDER BY id ASC  ");
    if(query.exec(sql))
    {
        taskCount=query.size();
        global_task_count=taskCount;
        while (query.next()) {
            QString index = query.value("id").toString();
             QString task_name = query.value("task_name").toString();

                ui->comBoxTaskAll->addItem(index+" "+task_name);
             if(global_reserve_type=="group")//组登录
             {
                if(findCurrentTaskFlag==true&&findNectTaskFlag==false)
                {
                    login_group->nextTask=task_name;
                    findNectTaskFlag=true;
                }
                 if(task_name==login_group->currentTask)
                 {
                     login_group->currentTaskIndex=index.toInt();
                     findCurrentTaskFlag=true;

                 }else if(findCurrentTaskFlag==false){
                      login_group->lastTask=task_name;
                 }
             }else if(global_reserve_type=="person"){
                 if(findCurrentTaskFlag==true&&findNectTaskFlag==false)
                 {
                     login_person->nextTask=task_name;
                     findNectTaskFlag=true;
                 }
                  if(task_name==login_person->currentTask)
                  {
                      login_person->currentTaskIndex=index.toInt();
                      findCurrentTaskFlag=true;

                  }else if(findCurrentTaskFlag==false){
                       login_person->lastTask=task_name;
                  }
             }
        }
        if(findCurrentTaskFlag==true)
        {
            if(global_reserve_type=="group")//组登录
            {
//                ui->textEditLeanTask->append("上次任务："+login_group->lastTask);
//                ui->textEditLeanTask->append("当前任务："+login_group->currentTask);
//                ui->textEditLeanTask->append("下次任务："+login_group->nextTask);
                int pecent=login_group->currentTaskIndex*100/taskCount;
                ui->progressBarGroup->setValue(pecent);//学习进度
            }
            else if(global_reserve_type=="person"){
//                ui->textEditLeanTask->append("上次任务："+login_person->lastTask);
//                ui->textEditLeanTask->append("当前任务："+login_person->currentTask);
//                ui->textEditLeanTask->append("下次任务："+login_person->nextTask);
                int pecent=login_person->currentTaskIndex*100/taskCount;
                ui->progressBarGroup->setValue(pecent);//学习进度
            }

        }

    }
    else {
        qDebug() << "No records found.";
    }
}

//获取登录时间
void MainForm::getLoginInfo()
{
    timeCount=60;//保证第一次得到剩余时间
    QSqlQuery query;
    QString sql;
    if(global_reserve_type=="group")//组登录
    {
        sql= QString("select * from sys_group where groupname ='%1' ").arg( login_group->groupname);
        if(query.exec(sql))
        {
            if (query.next()) {  //查询日期

                login_group->currentTask= query.value("currenttask").toString();
                ui->labelTaskCurrent->setText(login_group->currentTask);//当前任务

                QDateTime  datetime= query.value("loginTime").toDateTime();
                quint8 day = datetime.date().day();
                if(day==QDateTime::currentDateTime().date().day())//日期一致，不更新登录时间
                {
                    login_group->loginTime=datetime;
                    ui->loginTime_label->setText(" 登录时间："+ datetime.toString(" HH:mm:ss"));
                    return;
                }
                else{

                    QDateTime  currentTime= QDateTime::currentDateTime();
                    login_group->loginTime=currentTime;
                    //可以通过格式化的方法转换成想要显示的时间格式
                    QString now = currentTime.toString("yyyy-MM-dd HH:mm:ss");

                    ui->loginTime_label->setText(" 登录时间："+currentTime.toString(" HH:mm:ss"));
                    sql=QString("UPDATE sys_group SET loginTime = '%1' WHERE groupname  = '%2';").arg(now).arg( login_group->groupname);

                    //判断执行结果
                    if(!query.exec(sql))
                    {
                        qDebug()<<"update sys_group loginTime error";
                    }

                    for(int i=0;i<login_group->listLoginMember.count();i++)//更新登录时间
                    {
                        sql=QString("UPDATE sys_user SET loginTime = '%1' WHERE userame  = '%2';").arg(now).arg( login_group->listLoginMember.at(i));

                        //判断执行结果
                        if(!query.exec(sql))
                        {
                            qDebug()<<"update sys_user loginTime error";
                        }
                    }
                }
            }
            else {
                qDebug() << "No records found.";
            }

        }

    }else if(global_reserve_type=="person")//个人登录
    {
        sql= QString("select * from sys_user where username ='%1' ").arg( login_person->userName);
        if(query.exec(sql))
        {
            if (query.next()) {  //查询日期

                login_person->currentTask= query.value("currenttask").toString();
                ui->labelTaskCurrent->setText(login_person->currentTask);//当前任务

                QDateTime  datetime= query.value("loginTime").toDateTime();
                quint8 day = datetime.date().day();
                if(day==QDateTime::currentDateTime().date().day())//日期一致，不更新登录时间
                {
                    login_person->loginTime=datetime;
                    ui->loginTime_label->setText(" 登录时间："+ datetime.toString(" HH:mm:ss"));
                    return;
                }
                else{

                    QDateTime  currentTime= QDateTime::currentDateTime();
                    login_person->loginTime=currentTime;
                    //可以通过格式化的方法转换成想要显示的时间格式
                    QString now = currentTime.toString("yyyy-MM-dd HH:mm:ss");

                    ui->loginTime_label->setText(" 登录时间："+currentTime.toString(" HH:mm:ss"));
                    sql=QString("UPDATE sys_user SET loginTime = '%1' WHERE username  = '%2';").arg(now).arg( login_person->userName);

                    //判断执行结果
                    if(!query.exec(sql))
                    {
                        qDebug()<<"update error";
                    }
                }
            }
            else {
                qDebug() << "No records found.";
            }

        }
    }


}


//关闭
void MainForm::on_btnMenu_Close_clicked()
{
    timer->stop();
    if(startTask)
    {
        startTask=false;
        threadTraj->quit();
    }
    threadTraj->terminate();
    threadCameraTraj->terminate();

    cameraTraj->close();
    timerface->stop();

    QProcess *process1 = new QProcess();
    QString program = "G:/workspace/majun/code/zhiyuanchuang_scene_learning/zhiyuanchuang_scene_learning/code/project/body/body_finish.bat"; //
    process1->start(program);
    if (!process1->waitForStarted()) {
        qDebug() << "无法启动" << program;
        return;
    }else{

        qDebug() << "bat 启动" << program;
    }
        if (!process1->waitForFinished()) {
            qDebug() << "进程仍在运行...";
        } else {
            QString output = process1->readAllStandardOutput();
            QString error = process1->readAllStandardError();
            if (!output.isEmpty()) {
                qDebug() << "输出:" << output;
            }
            if (!error.isEmpty()) {
                qDebug() << "错误:" << error;
            }
        }

    delete process1;
    delete process;
//    faceThread->quit();
//    faceThread->wait();
    close();
}

//最大化
void MainForm::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
    }

    this->setProperty("canMove", max);
    max = !max;
}

//最小化
void MainForm::on_btnMenu_Min_clicked()
{
     showMinimized();
}

//用户退出
void MainForm::on_btnExit_clicked()
{

    QMessageBox::information(this,"提示：", login_group->groupname+"退出成功");
    on_btnMenu_Close_clicked();
}

//主界面
void MainForm::on_btnMain_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
    ui->btnMain->setChecked(true);
    ui->btnConfig->setChecked(false);
    ui->btnHelp->setChecked(false);
     ui->btnData->setChecked(false);
}

//设置界面
void MainForm::on_btnConfig_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
     ui->btnMain->setChecked(false);
     ui->btnConfig->setChecked(true);
     ui->btnHelp->setChecked(false);
     ui->btnData->setChecked(false);
}

//用户登录
void MainForm::on_btnLogin_clicked()
{
    on_btnMenu_Close_clicked();

    LoginWindow *w = new LoginWindow;
    w->show();
}

//辅导
void MainForm::on_btnHelp_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
     ui->btnMain->setChecked(false);
     ui->btnConfig->setChecked(false);
     ui->btnHelp->setChecked(true);
      ui->btnData->setChecked(false);
}
//个人信息
void MainForm::on_btnData_clicked()
{

     ui->stackedWidget->setCurrentIndex(3);
     ui->comBoxGroupMem->setCurrentIndex(0);
     ui->btnMain->setChecked(false);
     ui->btnConfig->setChecked(false);
     ui->btnHelp->setChecked(false);
      ui->btnData->setChecked(true);

}

void MainForm::on_comBoxGroupMem_currentIndexChanged(int index)
{
    QString sql = QString("select * from sys_user where username='%1' ").arg( ui->comBoxGroupMem->currentText());
    QSqlQuery query;
    if(query.exec(sql)) //执行sql语句是否成功
    {
       if (query.next()) {
           //qDebug() << query.value("username").toString();
           ui->user_label->setText("用户名： "+query.value("username").toString());
           ui->Avatar_label->setText("别名： "+query.value("avatar").toString());
           ui->stdNum_label->setText("学号： "+query.value("studentnum").toString());
           ui->college_label->setText("学院： "+query.value("college").toString());
           ui->major_label->setText("专业： "+query.value("major").toString());
       }
       else {
           qDebug() << "No records found.";
       }

    }else
    {
       qDebug()<<"Error ";
    }
}

//完善个人信息
void MainForm::on_btnSetInfo_clicked()
{
//    on_btnMenu_Close_clicked();
//     addInfoForm *w = new addInfoForm;
//     w->show();    
}




void MainForm::init_learnProcess_chart()
{
    QChart *chart = new QChart();
    chart->setTitle("学习进度展示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewLearnProcess->setChart(chart);
    ui->chartViewLearnProcess->setRenderHint(QPainter::Antialiasing);
}

void MainForm::build_learnProcess_chart()
{
    QChart *chart = ui->chartViewLearnProcess->chart();
    chart->removeAllSeries();
    if(chart->axisX() != NULL)
        chart->removeAxis(chart->axisX());
    if(chart->axisY() != NULL)
        chart->removeAxis(chart->axisY());

    int count=login_group->listAllMember.count();
    //数据集
    QBarSet *setLearnProcess= new QBarSet("学习进度");
    setLearnProcess->setColor("green");

    double sum=0;
    for(int i=0;i<count;i++)
    {


        QString  sql=QString("select * from sys_user where username='%1'").arg(login_group->listAllMember.at(i));

         //创建执行语句对象
         QSqlQuery query;
         query.exec(sql);
         //判断执行结果
         if(query.next())
         {
              QString currenttask = query.value("currenttask").toString();

               sql= QString("SELECT * FROM sys_task  where task_name='%1'").arg(currenttask);
               //qDebug()<<sql;
                query.exec(sql);
              if(query.next())
              {
                  int  currentTaskIndex= query.value("id").toString().toInt();
                  int pecent= currentTaskIndex*100/global_task_count;
                  setLearnProcess->append(pecent);
                  sum+=pecent;
              }
         }else{
             qDebug()<<"no records found ";
         }
    }
    setLearnProcess->append(sum/count);
    //序列
    QBarSeries *series = new QBarSeries;

    series->append(setLearnProcess);
    chart->addSeries(series);

    //坐标轴
    QStringList categories;
    for(int i=0;i<count;i++)
    {
        categories<<login_group->listAllMember.at(i);
    }
     categories<<"平均";
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->setCategories(categories);
    chart->setAxisX(axisX,series);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0,100);
    axisY->setTitleText("百分比");
    chart->setAxisY(axisY,series);

    chart->legend()->setAlignment(Qt::AlignBottom);
}

void MainForm::init_learnTimebar_chart()
{
    QChart *chart = new QChart();
    chart->setTitle("学习时长展示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewLearnTimeBar->setChart(chart);
    ui->chartViewLearnTimeBar->setRenderHint(QPainter::Antialiasing);
}

void MainForm::build_learnTimebar_chart()
{
    QChart *chart = ui->chartViewLearnTimeBar->chart();
    chart->removeAllSeries();
    if(chart->axisX() != NULL)
        chart->removeAxis(chart->axisX());
    if(chart->axisY() != NULL)
        chart->removeAxis(chart->axisY());

    int count=login_group->listAllMember.count();
    //数据集
    QBarSet *setLearnTime = new QBarSet("学习时长");
    setLearnTime->setColor("blue");

    double sum=0;
    double maxValue=0;
    for(int i=0;i<count;i++)
    {

        QString sql=QString("select * from sys_user where username='%1'").arg(login_group->listAllMember.at(i));

        QSqlQuery query;
        query.exec(sql);
        if (query.next()) {
            int learnTime = query.value("learntime").toInt();
            setLearnTime->append(learnTime);
            sum+=learnTime;
            if(maxValue<learnTime) maxValue=learnTime;
        }

    }
    setLearnTime->append(sum/count);
    //序列
    QBarSeries *series = new QBarSeries;

    series->append(setLearnTime);
    chart->addSeries(series);

    //坐标轴
    QStringList categories;
    for(int i=0;i<count;i++)
    {
        categories<<login_group->listAllMember.at(i);
    }
     categories<<"平均";
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->setCategories(categories);
    chart->setAxisX(axisX,series);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0,maxValue);
    axisY->setTitleText("小时");
    chart->setAxisY(axisY,series);

    chart->legend()->setAlignment(Qt::AlignBottom);
}



//开始任务
void MainForm::on_btnStartWork_clicked()
{

     if(startTask==false)//开始
     {                
        ui->btnStartWork->setText("结束任务");
        ui->btnStartWork->setStyleSheet(ui->btnStartWork->styleSheet()+ "QToolButton{ color: red;}");
        QTime  currentTime= QTime::currentTime();
        exprimentLabel=currentTime.toString("HH_mm_ss");
        startTask=true;
        threadTraj->start(); // 启动线程
     }
     else
     {
        ui->btnStartWork->setText("开始任务");
        ui->btnStartWork->setStyleSheet(ui->btnStartWork->styleSheet()+ "QToolButton{color: blue;}");
        startTask=false;
        threadTraj->quit();
        UseGetTrackGoal();
     }
}



void MainForm::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        // 请求成功，处理响应数据

        //ui->textEditRec->append(reply->readAll());
        // QByteArray responseData = reply->readAll();
        // qDebug() << responseData;

        QString str=reply->readAll();
        QStringList parts = str.split("///");
        if (!parts.isEmpty()) {
            ui->textEditRec->append(QTime::currentTime().toString(" HH:mm:ss")+" :"+parts[parts.size() - 2]);//parts.last()
        }

    } else {
        // 请求失败，处理错误信息
        qDebug() << "Request failed:" << reply->errorString();
    }

    // 请求完成后，清理资源
    reply->deleteLater();
  }
//发送提问
void MainForm::on_btnSend_clicked()
{


    QString str = QString("{\"prompt\":\"%1\",\"keyword\":\"%1\",\"temperature\":0.8,\"top_p\":0.8,\"max_length\":2048,\"history\":[],\"zhishiku\":false}").arg(ui->textEditSend->toPlainText());

    QByteArray data = str.toUtf8();
    qDebug() << QString::fromUtf8(data);
    ui->textEditRec->append(QTime::currentTime().toString(" HH:mm:ss")+" :"+ui->textEditSend->toPlainText());
    //data数据的处理流程
    QNetworkReply *reply = m_manger->post(request,data);
    // 连接请求完成的信号
    connect(m_manger, &QNetworkAccessManager::finished, this, &MainForm::replyFinished);

}

//清空接收
void MainForm::on_btnClearRec_clicked()
{
    ui->textEditRec->setText("");
}




//提交任务
void MainForm::on_btnSubmitTask_clicked()
{
    showDigitPerson();
//    //测试 redis        
//    char* m_cmd = "set m_int 110";
//    redis->ExecRedis(m_cmd);
//    if(redis->m_reply != NULL)
//    {
//        qDebug() << redis->m_reply->str;
//    }else{
//        qDebug() << "no reply";
//    }
//    redis->FreeReply();

//    // 获取设置到的整数
//    m_cmd = "get m_int";
//    redis->ExecRedis(m_cmd);
//    if(redis->m_reply != NULL)
//    {
//        qDebug() << redis->m_reply->str;
//    }
//    else
//    {
//     qDebug() << "no reply";
//    }
}
//移动窗体
bool MainForm::eventFilter(QObject *watched, QEvent *evt)
{

    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - this->pos();

            return true;
        } else {
            //exit(0);
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            this->move(event->globalPos() - mousePoint);
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);
}



//清空
void MainForm::on_ClearBtn_clicked()
{
    ui->textEditRead->setText("");
}

