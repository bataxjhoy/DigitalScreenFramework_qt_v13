#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "signupform.h"
#include "mainform.h"
#include "iconhelper.h"
#include <thread>
//#pragma execution_character_set("utf-8")

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->SignupBtn->setVisible(false);
    this->setProperty("canMove", true);
    this->setWindowIcon(QIcon(":/new/prefix1/image/main_person.png"));
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //IconHelper::Instance()->setIcon(ui->btn_close, QChar(0xf00d));
     this->installEventFilter(this);
    ui->textEditPassWord->setEchoMode(QLineEdit::Password);//隐藏密码


    ui->labelTip->setText("提示：当前预约为"+global_reserve_name);

    //usb相机初始化
    camera = new usbCamera();
    camera->moveToThread(&thread);//将camera对象放在子线程
    thread.start();
    connect(this, SIGNAL(cameraOperate(int)), camera, SLOT(Operate(int)));
    connect(camera, SIGNAL(updateImage(QImage)), this, SLOT(updateImage(QImage)));
    emit cameraOperate(0);

    init_login_python();

    qDebug()<<"camera->openFlag"<<camera->openFlag;

    timerCarema = new QTimer(this);
    if (camera->openFlag) {
       qDebug() << "USB 摄像头已打开";
       connect(timerCarema, &QTimer::timeout, this, &LoginWindow::Timer_process);
       timerCarema->start(10);//0.1秒钟更新
    }

}

void  LoginWindow::init_login_python()
{

    //加入python
    //Py_SetPythonHome(L"D:/software/computer/Anaconda/envs/face_test");
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
    //std::string path = "sys.path.append('G:/workspace/majun/code/zhiyuanchuang_face/code/project')";
    std::string path = "sys.path.append('G:/workspace/majun/code/zhiyuanchuang_scene_learning/zhiyuanchuang_scene_learning/code/project/face/project')";
    PyRun_SimpleString(&path[0]);
    PyRun_SimpleString("print(sys.path)");



    // 3. 找到要用的python文件
     PyObject * pModule = PyImport_ImportModule("login");
    if (pModule == NULL) {
        PyErr_Print(); // 打印 Python 错误信息
        qDebug() <<"Fail to load Python module (login.py)";
    }

    // 1. 找到Python的类
    PyObject* pDict = PyModule_GetDict(pModule);
    if(!pDict) {
        qDebug() << "Cant find dictionary.";
    }
     Py_DECREF(pModule);

    PyObject* pClassCalc = PyDict_GetItemString(pDict, "LogIn");
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

    pInstance = PyObject_CallObject(pConstruct,cons_args);
    if (!pInstance) {
        qDebug() << "Cant construct instance.";
    }
    Py_DECREF(cons_args);
    Py_DECREF(pConstruct);


     qDebug() << "python init success " ;

}

void LoginWindow::UsePythonLogin( QImage qImage)
{
    if(!qImage.isNull())
    {
        int width = qImage.width();
        int height = qImage.height();
        unsigned char *CArrays = (unsigned  char*)malloc(sizeof(unsigned char) * width*height*3);
        //qDebug()<<"qImage.width()"<<qImage.width()<<"qImage.height()"<<qImage.height()<<"qImage.format()"<<qImage.format()<<endl;

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
        PyObject* pResult = PyObject_CallMethod(pInstance, "process", "O", imageArray);
        //Py_DECREF(imageArray);
       if (pResult == nullptr) {
           PyErr_Print(); // 打印 Python 错误信息
          qDebug()<<"cant UsePythonLogin"<<endl;

          free(CArrays) ;
          CArrays = nullptr;
           return;
       }
       if (PyTuple_Check(pResult)) {
              Py_ssize_t size = PyTuple_Size(pResult);
               //qDebug()<<"size="<<size<<endl;
               PyObject* imageData = PyTuple_GetItem(pResult, 0);
               memcpy(CArrays,PyArray_DATA(imageData),width*height*3);
              QImage img((unsigned char*)CArrays, width, height,  QImage::Format_RGB888);
              qDebug()<<"img.width()"<<img.width()<<"img.height()"<<img.height()<<"img.format()"<<img.format()<<endl;

              Py_DECREF(imageData);

              if(!img.isNull())
              {
               ui->labelCamera->setPixmap(QPixmap::fromImage(img.scaled(ui->labelCamera->size(), Qt::KeepAspectRatio)));
               ui->labelCamera->setScaledContents(true);
              }


               PyObject* nameArrayObj = PyTuple_GetItem(pResult,1);//解析名字  数组
               if (nameArrayObj == nullptr) {
                       qDebug()<<"null"<<endl;
                       Py_DECREF(pResult);
                       free(CArrays) ;
                       CArrays = nullptr;
                       return;
               }
               if (!PyList_Check(nameArrayObj)) {
                       qDebug()<<"PyList_Check  fail"<<endl;
                       Py_DECREF(nameArrayObj);
                       Py_DECREF(pResult);
                       free(CArrays) ;
                       CArrays = nullptr;
                       return;
               }

               size = PyList_Size(nameArrayObj);
               //qDebug()<<"size="<<size<<endl;
               //QStringList nameList;

               for (Py_ssize_t i = 0; i < size; ++i) {
                   // 获取列表或元组中的每个元素
                   PyObject* itemObj = PyList_GetItem(nameArrayObj, i);
                   // 检查元素是否为字符串
                   if (PyUnicode_Check(itemObj)) {
                       // 将 Python 字符串转换为 C 字符串
                       PyObject* unicodeStr = PyUnicode_AsUTF8String(itemObj);
                       const char* cStr = PyBytes_AsString(unicodeStr);

                       // 将 C 字符串转换为 QString
                       QString name = QString::fromUtf8(cStr);

                       // 将 QString 添加到 QStringList 中
                       //nameList.append(name);
                       qDebug()<<name <<endl;
                       Py_DECREF(unicodeStr);// 减少引用计数
                       if(name!="UnKnow")
                        seacherLonginPerson(name);

                   } //Py_DECREF(itemObj);//不需要减少 pItem 的引用计数，因为它是元组的一部分，元组的析构会处理它
               }

               Py_DECREF(nameArrayObj);

         }
        Py_DECREF(pResult);
        free(CArrays) ;
        CArrays = nullptr;
   }
   else{
       qDebug()<<"qImage is null"<<endl;
    }
// 实时监测登录
//    if(global_login_flag==true)
//    {
//       timerCarema->stop();
//       QMessageBox msgBox;
//       msgBox.setWindowTitle("登录认证");
//       QString loginMember;
//       for(int i=0;i<login_group->listLoginMember.count();i++)//获取登录成员
//       {
//           loginMember.append(login_group->listLoginMember.at(i)+",");
//       }
//       msgBox.setText(global_reserve_name+" "+loginMember+" 登录成功,是否继续学习！");
//       msgBox.setIcon(QMessageBox::Information); // 设置图标为信息性图标

//       // 添加确定和取消按钮，并设置它们的角色
//       QPushButton *okButton = msgBox.addButton(QMessageBox::Ok);
//       okButton->setText("确定"); // 设置按钮文本为"确定"
//       QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
//       cancelButton->setText("取消"); // 设置按钮文本为"取消"

//       // 执行消息框，并获取用户点击的按钮
//       int ret = msgBox.exec();

//       if (ret == QMessageBox::Ok) {//登录成功后可以跳转到其他页面
//           on_btn_close_clicked();
//           MainForm* w= new MainForm();
//           w->show();
//       } else if (ret == QMessageBox::Cancel) {
//           timerCarema->start(10);
//          global_login_flag=false;
//          login_group->listLoginMember.clear();//清空列表
//       }
//    }
}
//人脸标签找登录名
void  LoginWindow::seacherLonginPerson(QString avatarName)
{
   QString sql=QString("select * from sys_user where avatar='%1'").arg(avatarName);

   QSqlQuery query;
   query.exec(sql);
   if (query.next()) {

       if(global_reserve_type=="group")//组登录
       {
          QString group = query.value("group").toString();
          if(group==global_reserve_name)
          {
                global_login_flag=true;
                QString user=query.value("username").toString();
                if(!login_group->listLoginMember.contains(user))
                login_group->listLoginMember.append(user);

                QString loginMember;
                for(int i=0;i<login_group->listLoginMember.count();i++)//获取登录成员
                {
                    loginMember.append(login_group->listLoginMember.at(i)+"  ");
                }
                if(login_group->listLoginMember.count()!=0)
                ui->labelTip->setText("提示：当前检测到"+global_reserve_name+":"+loginMember+ "可进行登录");
          }
       }else if(global_reserve_type=="person")//个人登录
       {
            QString username = query.value("username").toString();
            if(username==global_reserve_name)
                global_login_flag=true;
       }

   }else{
       qDebug()<<"no records found ";
       global_login_flag=false;
   }

}


//更新图片
void LoginWindow::updateImage(QImage image)
{
    //ui->labelCamera->setPixmap(QPixmap::fromImage(image.scaled(ui->labelCamera->size(), Qt::KeepAspectRatio)));
    cameraImage=image;
}

//定时器1
void LoginWindow::Timer_process()
{
    UsePythonLogin(cameraImage);//人脸认证

}



LoginWindow::~LoginWindow()
{
    // 关闭Python
      //Py_DECREF(pInstance);
      //Py_Finalize();
    delete ui;
}
//登录
void LoginWindow::on_LoginBtn_clicked()
{


    if(login_group->listLoginMember.count()!=0)//人脸识别--直接登录
    {
        qDebug()<<"Login success";

        QMessageBox::information(this,"登录认证","登录成功,请继续学习！");
        //登录成功后可以跳转到其他页面
        global_login_flag=true;
        on_btn_close_clicked();
        MainForm *w = new MainForm;
        w->show();
        return;
    }

    //组名，用户名 密码登录
    QString username = ui->textEditUserName->text();
    QString password = ui->textEditPassWord->text();


    if(global_reserve_name!=username){
        if (  login_group->listAllMember.contains(username)) {//预约组包含该人
            login_group->listLoginMember.clear();//清空列表
            login_group->listLoginMember.append(username);

        } else {
            QMessageBox::information(this,"登录认证","登录失败，该用户当前时间没有预约");
            return;
        }
    }

     QString sql;
    if(global_reserve_type=="group")//组登录
    {
        sql=QString("select * from sys_group where groupname='%1' and password='%2'")
               .arg(global_reserve_name).arg(password);

    }else if(global_reserve_type=="person")//个人登录
    {
        sql=QString("select * from sys_user where username='%1' and password='%2'")
               .arg(username).arg(password);
    }


    //创建执行语句对象
    QSqlQuery query(sql);
    //判断执行结果
    if(!query.next())
    {
        qDebug()<<"Login error";
        QMessageBox::information(this,"登录认证","登录失败,账户或者密码错误");
    }
    else
    {
        qDebug()<<"Login success";

        QMessageBox::information(this,"登录认证","登录成功,请继续学习！");
        //登录成功后可以跳转到其他页面
        global_login_flag=true;
        on_btn_close_clicked();
        MainForm *w = new MainForm;
        w->show();
    }

}

//注册
void LoginWindow::on_SignupBtn_clicked()
{
    on_btn_close_clicked();
    SignupForm *s = new SignupForm;
    s->show();
}

//关闭窗体
void LoginWindow::on_btn_close_clicked()
{
    if(timerCarema!=nullptr)
       {
           timerCarema->stop();
           delete timerCarema; // 销毁 timer 对象
           timerCarema = nullptr; // 将指针设置为 nullptr
       }
       thread.terminate();
       camera->close();

    close();
}
//移动窗体
bool LoginWindow::eventFilter(QObject *watched, QEvent *evt)
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

