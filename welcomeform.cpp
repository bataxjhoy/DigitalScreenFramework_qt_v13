#include "welcomeform.h"
#include "ui_welcomeform.h"
#include "loginwindow.h"
#include "iconhelper.h"
welcomeForm::welcomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcomeForm)
{
    ui->setupUi(this);
    this->setProperty("canMove", true);
    this->setWindowIcon(QIcon(":/new/prefix1/image/main_person.png"));
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //IconHelper::Instance()->setIcon(ui->btn_close, QChar(0xf00d));
     this->installEventFilter(this);
    QImage qimage=QImage(":/new/prefix1/image/AI3.png");
    ui->labelPic->setPixmap(QPixmap::fromImage(qimage.scaled(ui->labelPic->size(), Qt::KeepAspectRatio)));

    mql_init();
    timer = new QTimer(this);
    connect(timer , &QTimer::timeout, this, &welcomeForm::Timer_process);
    timer->start(10);//0.01秒钟更新
}

welcomeForm::~welcomeForm()
{
    timer->stop();
    delete ui;
}
//定时器1
int timeCount=10000;
void welcomeForm::Timer_process()
{
    timeCount++;
    if(timeCount%600==0)
    {
        ui->labelPic->clear();
        QImage qimage=QImage(":/new/prefix1/image/AI3.png");
        ui->labelPic->setPixmap(QPixmap::fromImage(qimage.scaled(ui->labelPic->size(), Qt::KeepAspectRatio)));
    } else if(timeCount%400==0)
    {
        ui->labelPic->clear();
        QImage qimage=QImage(":/new/prefix1/image/AI2.png");
        ui->labelPic->setPixmap(QPixmap::fromImage(qimage.scaled(ui->labelPic->size(), Qt::KeepAspectRatio)));
    }else  if(timeCount%200==0)
    {
        ui->labelPic->clear();
        QImage qimage=QImage(":/new/prefix1/image/AI1.png");
        ui->labelPic->setPixmap(QPixmap::fromImage(qimage.scaled(ui->labelPic->size(), Qt::KeepAspectRatio)));
    }
    if(timeCount>10000){

        QString sql=QString("SELECT * FROM sys_reserve WHERE reservetime < NOW() - INTERVAL 30 MINUTE AND NOW()<longtime");
        QSqlQuery query;
        query.exec(sql);
        if (query.next()) {
            QString deviceId = query.value("deviceid").toString();
            if(deviceId==global_deviceId)//设备为本机
            {
                 global_reserve_name = query.value("reservename").toString();
                  global_reserve_type = query.value("type").toString();
                  global_reserve_endtime=  query.value("longtime").toDateTime();;
                 if(global_reserve_type=="group")
                 {
                    ui->labelTip->setText(QString(" 提示：该场景已被预约，预约小组为 '%1' ").arg(global_reserve_name));
                 }
                 else if(global_reserve_type=="person"){
                     ui->labelTip->setText(QString(" 提示：该场景已被预约，预约者为 '%1' ").arg(global_reserve_name));
                 }
            }
        }else{
            qDebug()<<"no records found ";
            ui->labelTip->setText(" 提示：该场景为空闲状态");
        }
        timeCount=0;
    }
}
void welcomeForm::on_enterBtn_clicked()
{
    if(global_reserve_type=="group")//获取组成员
    {
        login_group->groupname=global_reserve_name;
        QString sql=QString("SELECT * FROM sys_group WHERE  groupname='%1'").arg(login_group->groupname);
        QSqlQuery query;
        query.exec(sql);
        if (query.next()) {
            login_group->listAllMember.clear();
            for(int i=1;i<=5;i++)
            {
                QString member=query.value(QString("member%1").arg(i)).toString();

                if(member!="")
                    login_group->listAllMember.append(member );

            } //qDebug()<<login_group->listAllMember.count();

        }else{
            qDebug()<<"no records found ";

        }
    }
    else if(global_reserve_type=="person"){

        login_person->userName=global_reserve_name;

        QString sql=QString("SELECT * FROM sys_user WHERE  username='%1'").arg(login_person->userName);//sys_user  找组名
        QSqlQuery query;
        query.exec(sql);
        if (query.next()) {

            login_group->groupname=query.value(QString("group")).toString();
            //qDebug()<<login_group->groupname;

            sql=QString("SELECT * FROM sys_group WHERE  groupname='%1'").arg(login_group->groupname);//找组成员
            query.exec(sql);
            if (query.next()) {
                login_group->listAllMember.clear();
                for(int i=1;i<=5;i++)
                {
                    QString member=query.value(QString("member%1").arg(i)).toString();
                    if(member!="")
                        login_group->listAllMember.append(member );

                } //qDebug()<<login_group->listAllMember.count();

            }else{
                qDebug()<<"no records found ";

            }
        }
    }

    this->close();
    LoginWindow* w=new LoginWindow;
    w->show();


}


void welcomeForm::on_btn_close_clicked()
{
     close();
}

//移动窗体
bool welcomeForm::eventFilter(QObject *watched, QEvent *evt)
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
