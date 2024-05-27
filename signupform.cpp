#include "signupform.h"
#include "ui_signupform.h"
#include "loginwindow.h"
#include "mainform.h"
#include "iconhelper.h"
#include "addinfoform.h"
//#pragma execution_character_set("utf-8")
SignupForm::SignupForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignupForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/image/main_person.png"));
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    IconHelper::Instance()->setIcon(ui->btn_close, QChar(0xf00d));
}

SignupForm::~SignupForm()
{
    delete ui;
}


//注册
void SignupForm::on_SignupBtn_clicked()
{

    QString username = ui->textEditUserName->toPlainText();
    QString password = ui->textEditPassWord->toPlainText();
    QString surepass = ui->textEditPassWord_Ensure->toPlainText();
     QDateTime  currentDateTime=QDateTime::currentDateTime();
    login_person->userName=username;
    //判断密码是否一致
    if(password == surepass)
    {
        QString sql=QString("insert into sys_user(username,password,created) values('%1','%2','%3');")
                          .arg(username).arg(password).arg(currentDateTime.toString("yyyy-MM-dd HH:mm:ss"));
        //创建执行语句对象
        QSqlQuery query;
        //判断执行结果
        if(!query.exec(sql))
        {
            qDebug()<<"insert into error";
            QMessageBox::information(this,"注册认证","插入失败,存在相同的用户！");
        }
        else
        {
            qDebug()<<"insert into success";
            QMessageBox::information(this,"注册认证","插入成功！");
            addInfoForm *w = new addInfoForm;
            w->show();
            this->close();
        }

    }else{
        QMessageBox::information(this,"注册认证","两次密码输入不一致");
    }

}

//返回
void SignupForm::on_BackBtn_clicked()
{
    LoginWindow *w = new LoginWindow;
    w->show();
    this->close();
}

//关闭
void SignupForm::on_btn_close_clicked()
{
    close();
}

