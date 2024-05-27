#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QMessageBox>//消息盒子
#include <QDebug>
#include <QDateTime>

#include "global.h"
#include "usbcamera.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:

        usbCamera* camera;
       QThread thread;
       QTimer *timerCarema ;
       QImage cameraImage;

    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    void  init_login_python();
    void UsePythonLogin( QImage qImage);
    void  seacherLonginPerson(QString avatarName);
    bool eventFilter(QObject *watched, QEvent *evt);
private slots:
    void updateImage(QImage);
    void on_LoginBtn_clicked();

    void on_SignupBtn_clicked();

    void on_btn_close_clicked();
    void Timer_process();
signals:
    void cameraOperate(int);
private:
    Ui::LoginWindow *ui;
};




#endif // LOGINWINDOW_H
