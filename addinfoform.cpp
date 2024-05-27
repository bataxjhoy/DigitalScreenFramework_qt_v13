#include "addinfoform.h"
#include "ui_addinfoform.h"
#include "loginwindow.h"
#include "iconhelper.h"
#include "mainform.h"

addInfoForm::addInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addInfoForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/image/main_person.png"));
    this->setWindowFlags( Qt::FramelessWindowHint|Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    IconHelper::Instance()->setIcon(ui->btn_close, QChar(0xf00d));
    ui->textEditUser->setText( login_person->userName);
}

addInfoForm::~addInfoForm()
{
    delete ui;
}

void addInfoForm::on_btn_close_clicked()
{
    close();
}

//保存
void addInfoForm::on_SaveBtn_clicked()
{
    QString username = login_person->userName;

    QString sql=QString("UPDATE sys_user SET avatar = '%1', studentnum = '%2', college = '%3', major = '%4' WHERE username = '%5';")
                      .arg(ui->textEditAvatar->toPlainText()).arg(ui->textEditStdNum->toPlainText()).arg(ui->textEditCollege->toPlainText()).arg(ui->textEditMajor->toPlainText()).arg(username);
    //创建执行语句对象
    QSqlQuery query;
    //判断执行结果
    if(!query.exec(sql))
    {
        qDebug()<<"save error";
        QMessageBox::information(this,"添加个人信息","添加个人信息失败");
    }
    else
    {
        qDebug()<<"Login success";
        QMessageBox::information(this,"添加个人信息","添加个人信息成功");
        //登录成功后可以跳转到其他页面
        global_login_flag=true;
        MainForm *w = new MainForm;
        w->show();

        this->close();
    }
}

