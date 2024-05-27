/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QWidget *widgetTitle;
    QLabel *labIco;
    QLabel *labTitle;
    QLabel *remainTime_label;
    QLabel *globalUser_label;
    QLabel *loginTime_label;
    QLabel *CurTime_label;
    QWidget *widget_top;
    QToolButton *btnExit;
    QToolButton *btnHelp;
    QToolButton *btnMain;
    QToolButton *btnData;
    QToolButton *btnConfig;
    QToolButton *btnLogin;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Min;
    QStackedWidget *stackedWidget;
    QWidget *main_page;
    QWidget *widget;
    QProgressBar *progressBarGroup;
    QLabel *labelTaskProcess;
    QComboBox *comBoxLoginMem;
    QLabel *labelLearnTsak;
    QLabel *labelOnLine;
    QLabel *labelTaskCurrent;
    QLabel *labelLearnTsak_2;
    QComboBox *comBoxTaskAll;
    QChartView *chartViewLearnProcess;
    QLabel *label_7;
    QChartView *chartViewLearnTimeBar;
    QLabel *label_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *labelTrj;
    QWidget *tab_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *m1p_led;
    QLabel *m2z_led;
    QLabel *m1z_led;
    QLabel *m1n_led;
    QLabel *m2p_led;
    QLabel *m2n_led;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *TrajLabel;
    QLabel *labelMvFs;
    QToolButton *btnSubmitTask;
    QToolButton *btnStartWork;
    QLabel *FaceLabel;
    QLabel *labelUsbFs;
    QLabel *labelResult;
    QWidget *config_page;
    QLabel *label_9;
    QLabel *label_3;
    QLabel *label_8;
    QTextEdit *IPTextEdit;
    QTextEdit *PORTTextEdit;
    QPushButton *ConnectBtn;
    QLabel *label_11;
    QTextEdit *IDTextEdit;
    QTextEdit *textEditRead;
    QPushButton *ClearBtn;
    QWidget *help_page;
    QLabel *label_4;
    QTextEdit *textEditRec;
    QTextEdit *textEditSend;
    QToolButton *btnSend;
    QToolButton *btnClearRec;
    QWidget *person_page;
    QLabel *info_label;
    QLabel *user_label;
    QLabel *Avatar_label;
    QLabel *stdNum_label;
    QLabel *major_label;
    QLabel *college_label;
    QToolButton *btnSetInfo;
    QComboBox *comBoxGroupMem;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(1633, 959);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainForm->sizePolicy().hasHeightForWidth());
        MainForm->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        MainForm->setFont(font);
        MainForm->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 91, 186);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(64, 103,120,  255), stop:1 rgba( 48,17, 60, 255));\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 103,255,  255), stop:1 rgba( 0,91, 186, 255));\n"
"\n"
""));
        widgetTitle = new QWidget(MainForm);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        widgetTitle->setGeometry(QRect(10, 10, 1621, 111));
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        widgetTitle->setStyleSheet(QString::fromUtf8("border-radius:7px;\n"
"background-color: rgb(82, 91, 255);\n"
"\n"
"border: 2px solid white;"));
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QString::fromUtf8("labIco"));
        labIco->setGeometry(QRect(20, 20, 61, 81));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labIco->sizePolicy().hasHeightForWidth());
        labIco->setSizePolicy(sizePolicy1);
        labIco->setMinimumSize(QSize(61, 71));
        labIco->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/ai.png);\n"
" size: 60px;\n"
"\n"
"border-radius:7px;"));
        labIco->setAlignment(Qt::AlignCenter);
        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        labTitle->setGeometry(QRect(70, 10, 331, 91));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy2);
        labTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 290 28pt \"Microsoft YaHei\";\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-radius:7px;\n"
"border:0px;"));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        remainTime_label = new QLabel(widgetTitle);
        remainTime_label->setObjectName(QString::fromUtf8("remainTime_label"));
        remainTime_label->setGeometry(QRect(1120, 60, 191, 41));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(remainTime_label->sizePolicy().hasHeightForWidth());
        remainTime_label->setSizePolicy(sizePolicy3);
        remainTime_label->setMinimumSize(QSize(171, 41));
        remainTime_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(200,255, 255);\n"
"background-color: rgba(38, 61, 139,255);\n"
"font: 12pt \"Arial\";\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"}\n"
"QLabel:hover{\n"
" border-bottom:2px solid #00DB00;\n"
"}"));
        globalUser_label = new QLabel(widgetTitle);
        globalUser_label->setObjectName(QString::fromUtf8("globalUser_label"));
        globalUser_label->setGeometry(QRect(930, 10, 181, 41));
        sizePolicy3.setHeightForWidth(globalUser_label->sizePolicy().hasHeightForWidth());
        globalUser_label->setSizePolicy(sizePolicy3);
        globalUser_label->setMinimumSize(QSize(171, 41));
        globalUser_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(200,255, 255);\n"
"background-color: rgba(38, 61, 139,255);\n"
"font: 12pt \"Arial\";\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"}\n"
"QLabel:hover{\n"
" border-bottom:2px solid #00DB00;\n"
"}"));
        loginTime_label = new QLabel(widgetTitle);
        loginTime_label->setObjectName(QString::fromUtf8("loginTime_label"));
        loginTime_label->setGeometry(QRect(930, 60, 181, 41));
        sizePolicy3.setHeightForWidth(loginTime_label->sizePolicy().hasHeightForWidth());
        loginTime_label->setSizePolicy(sizePolicy3);
        loginTime_label->setMinimumSize(QSize(171, 41));
        loginTime_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(200,255, 255);\n"
"background-color: rgba(38, 61, 139,255);\n"
"font: 12pt \"Arial\";\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"}\n"
"QLabel:hover{\n"
" border-bottom:2px solid #00DB00;\n"
"}"));
        CurTime_label = new QLabel(widgetTitle);
        CurTime_label->setObjectName(QString::fromUtf8("CurTime_label"));
        CurTime_label->setGeometry(QRect(1120, 10, 191, 41));
        sizePolicy3.setHeightForWidth(CurTime_label->sizePolicy().hasHeightForWidth());
        CurTime_label->setSizePolicy(sizePolicy3);
        CurTime_label->setMinimumSize(QSize(171, 41));
        CurTime_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(200,255, 255);\n"
"background-color: rgba(38, 61, 139,255);\n"
"font: 12pt \"Arial\";\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"}\n"
"QLabel:hover{\n"
" border-bottom:2px solid #00DB00;\n"
"}"));
        widget_top = new QWidget(widgetTitle);
        widget_top->setObjectName(QString::fromUtf8("widget_top"));
        widget_top->setGeometry(QRect(390, 20, 511, 81));
        widget_top->setStyleSheet(QString::fromUtf8("border:0px;"));
        btnExit = new QToolButton(widget_top);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(350, 0, 76, 71));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy4);
        btnExit->setMinimumSize(QSize(66, 71));
        btnExit->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{\n"
"	font: 14pt \"Arial\";\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding:5px;	\n"
"	border-radius:7px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(64, 103,120,  0), stop:1 rgba( 0, 185,185, 0));	\n"
"border:1px solid #DCDCDC;\n"
"\n"
"}\n"
"QToolButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #999900,stop:1 #525252);\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:checked{\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"   color: #333333;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/main_exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon);
        btnExit->setIconSize(QSize(32, 32));
        btnExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnHelp = new QToolButton(widget_top);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        btnHelp->setGeometry(QRect(265, 0, 76, 71));
        sizePolicy4.setHeightForWidth(btnHelp->sizePolicy().hasHeightForWidth());
        btnHelp->setSizePolicy(sizePolicy4);
        btnHelp->setMinimumSize(QSize(71, 71));
        btnHelp->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{\n"
"	font: 14pt \"Arial\";\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding:5px;	\n"
"	border-radius:7px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(64, 103,120,  0), stop:1 rgba( 0, 185,185, 0));	\n"
"border:1px solid #DCDCDC;\n"
"\n"
"}\n"
"QToolButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #999900,stop:1 #525252);\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:checked{\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"   color: #333333;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/image/avatar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon1);
        btnHelp->setIconSize(QSize(32, 32));
        btnHelp->setCheckable(true);
        btnHelp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnMain = new QToolButton(widget_top);
        btnMain->setObjectName(QString::fromUtf8("btnMain"));
        btnMain->setGeometry(QRect(23, 0, 71, 71));
        sizePolicy4.setHeightForWidth(btnMain->sizePolicy().hasHeightForWidth());
        btnMain->setSizePolicy(sizePolicy4);
        btnMain->setMinimumSize(QSize(71, 71));
        btnMain->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{\n"
"	font: 14pt \"Arial\";\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding:5px;	\n"
"	border-radius:7px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(64, 103,120,  0), stop:1 rgba( 0, 185,185, 0));	\n"
"border:1px solid #DCDCDC;\n"
"\n"
"}\n"
"QToolButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #999900,stop:1 #525252);\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:checked{\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"   color: #333333;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/image/main_main.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMain->setIcon(icon2);
        btnMain->setIconSize(QSize(32, 32));
        btnMain->setCheckable(true);
        btnMain->setChecked(true);
        btnMain->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnData = new QToolButton(widget_top);
        btnData->setObjectName(QString::fromUtf8("btnData"));
        btnData->setGeometry(QRect(182, 0, 77, 71));
        sizePolicy4.setHeightForWidth(btnData->sizePolicy().hasHeightForWidth());
        btnData->setSizePolicy(sizePolicy4);
        btnData->setMinimumSize(QSize(66, 71));
        btnData->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{\n"
"	font: 14pt \"Arial\";\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding:5px;	\n"
"	border-radius:7px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(64, 103,120,  0), stop:1 rgba( 0, 185,185, 0));	\n"
"border:1px solid #DCDCDC;\n"
"\n"
"}\n"
"QToolButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #999900,stop:1 #525252);\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:checked{\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"   color: #333333;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/image/main_person.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnData->setIcon(icon3);
        btnData->setIconSize(QSize(32, 32));
        btnData->setCheckable(true);
        btnData->setChecked(false);
        btnData->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnConfig = new QToolButton(widget_top);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));
        btnConfig->setGeometry(QRect(100, 0, 76, 71));
        sizePolicy4.setHeightForWidth(btnConfig->sizePolicy().hasHeightForWidth());
        btnConfig->setSizePolicy(sizePolicy4);
        btnConfig->setMinimumSize(QSize(71, 71));
        btnConfig->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{\n"
"	font: 14pt \"Arial\";\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding:5px;	\n"
"	border-radius:7px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(64, 103,120,  0), stop:1 rgba( 0, 185,185, 0));	\n"
"border:1px solid #DCDCDC;\n"
"\n"
"}\n"
"QToolButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #999900,stop:1 #525252);\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:checked{\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"   color: #333333;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/image/main_config.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfig->setIcon(icon4);
        btnConfig->setIconSize(QSize(32, 32));
        btnConfig->setCheckable(true);
        btnConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnLogin = new QToolButton(widget_top);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(430, 0, 77, 71));
        sizePolicy4.setHeightForWidth(btnLogin->sizePolicy().hasHeightForWidth());
        btnLogin->setSizePolicy(sizePolicy4);
        btnLogin->setMinimumSize(QSize(71, 71));
        btnLogin->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{\n"
"	font: 14pt \"Arial\";\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding:5px;	\n"
"	border-radius:7px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(64, 103,120,  0), stop:1 rgba( 0, 185,185, 0));	\n"
"border:1px solid #DCDCDC;\n"
"\n"
"}\n"
"QToolButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #999900,stop:1 #525252);\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:checked{\n"
" border-bottom:2px solid #00DB00;\n"
"}\n"
"QToolButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"   color: #333333;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/image/Button_deng.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLogin->setIcon(icon5);
        btnLogin->setIconSize(QSize(32, 32));
        btnLogin->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnMenu_Max = new QPushButton(widgetTitle);
        btnMenu_Max->setObjectName(QString::fromUtf8("btnMenu_Max"));
        btnMenu_Max->setGeometry(QRect(1534, 31, 30, 30));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy5);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);
        btnMenu_Max->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"border-radius:3px;\n"
"color: rgb(255, 255,255);\n"
"padding:3px;\n"
"margin:0px;\n"
"background:rgb(255, 85,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"color:#FFFFFF;\n"
"margin:1px 1px 2px 1px;\n"
"background-color:rgba(255,0,0,230);\n"
"}"));
        btnMenu_Close = new QPushButton(widgetTitle);
        btnMenu_Close->setObjectName(QString::fromUtf8("btnMenu_Close"));
        btnMenu_Close->setGeometry(QRect(1570, 31, 30, 30));
        sizePolicy5.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy5);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);
        btnMenu_Close->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"border-radius:3px;\n"
"color: rgb(255, 255,255);\n"
"padding:3px;\n"
"margin:0px;\n"
"background:rgb(255, 85,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"color:#FFFFFF;\n"
"margin:1px 1px 2px 1px;\n"
"background-color:rgba(255,0,0,230);\n"
"}"));
        btnMenu_Min = new QPushButton(widgetTitle);
        btnMenu_Min->setObjectName(QString::fromUtf8("btnMenu_Min"));
        btnMenu_Min->setGeometry(QRect(1498, 31, 30, 30));
        sizePolicy5.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy5);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);
        btnMenu_Min->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"border-radius:3px;\n"
"color: rgb(255, 255,255);\n"
"padding:3px;\n"
"margin:0px;\n"
"background:rgb(255, 85,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"color:#FFFFFF;\n"
"margin:1px 1px 2px 1px;\n"
"background-color:rgba(255,0,0,230);\n"
"}"));
        stackedWidget = new QStackedWidget(MainForm);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 140, 1621, 811));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget {\n"
"border:1px solid #ffffff;\n"
"border-radius:1px;\n"
"}"));
        main_page = new QWidget();
        main_page->setObjectName(QString::fromUtf8("main_page"));
        sizePolicy.setHeightForWidth(main_page->sizePolicy().hasHeightForWidth());
        main_page->setSizePolicy(sizePolicy);
        widget = new QWidget(main_page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 191, 781));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"border-right:1px solid #00ff99;"));
        progressBarGroup = new QProgressBar(widget);
        progressBarGroup->setObjectName(QString::fromUtf8("progressBarGroup"));
        progressBarGroup->setGeometry(QRect(10, 400, 151, 33));
        progressBarGroup->setMaximumSize(QSize(151, 16777215));
        progressBarGroup->setAutoFillBackground(false);
        progressBarGroup->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QProgressBar{\n"
"min-height:10px;\n"
"background-color: rgb(115, 115, 115);\n"
"font: 87 12pt \"Arial Black\";\n"
"text-align:center;\n"
"border-radius:5px;\n"
"border:1px solid #484848;\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"border-radius:5px;\n"
"font: 87 12pt \"Arial Black\";\n"
"text-align:center;\n"
"background-color:#00f000;\n"
"}\n"
""));
        progressBarGroup->setValue(0);
        labelTaskProcess = new QLabel(widget);
        labelTaskProcess->setObjectName(QString::fromUtf8("labelTaskProcess"));
        labelTaskProcess->setGeometry(QRect(9, 360, 112, 29));
        labelTaskProcess->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        comBoxLoginMem = new QComboBox(widget);
        comBoxLoginMem->setObjectName(QString::fromUtf8("comBoxLoginMem"));
        comBoxLoginMem->setGeometry(QRect(10, 70, 151, 32));
        comBoxLoginMem->setMaximumSize(QSize(151, 16777215));
        comBoxLoginMem->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(0, 0, 255);\n"
"font: 87 16pt \"Arial\";\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QComboBox:hover{\n"
"background-color: rgb(0, 255, 0);\n"
"}"));
        labelLearnTsak = new QLabel(widget);
        labelLearnTsak->setObjectName(QString::fromUtf8("labelLearnTsak"));
        labelLearnTsak->setGeometry(QRect(9, 242, 141, 29));
        labelLearnTsak->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        labelOnLine = new QLabel(widget);
        labelOnLine->setObjectName(QString::fromUtf8("labelOnLine"));
        labelOnLine->setGeometry(QRect(9, 34, 93, 29));
        labelOnLine->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"background-color: rgba(255, 255, 255,0);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        labelOnLine->setWordWrap(false);
        labelTaskCurrent = new QLabel(widget);
        labelTaskCurrent->setObjectName(QString::fromUtf8("labelTaskCurrent"));
        labelTaskCurrent->setGeometry(QRect(10, 280, 151, 31));
        labelTaskCurrent->setMaximumSize(QSize(151, 16777215));
        labelTaskCurrent->setStyleSheet(QString::fromUtf8("font: 290 16pt \"Microsoft YaHei\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 205, 0,255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        labelLearnTsak_2 = new QLabel(widget);
        labelLearnTsak_2->setObjectName(QString::fromUtf8("labelLearnTsak_2"));
        labelLearnTsak_2->setGeometry(QRect(10, 130, 112, 29));
        labelLearnTsak_2->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        comBoxTaskAll = new QComboBox(widget);
        comBoxTaskAll->setObjectName(QString::fromUtf8("comBoxTaskAll"));
        comBoxTaskAll->setGeometry(QRect(10, 170, 151, 32));
        comBoxTaskAll->setMaximumSize(QSize(151, 16777215));
        comBoxTaskAll->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(0, 0, 255);\n"
"font: 87 16pt \"Arial\";\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QComboBox:hover{\n"
"background-color: rgb(0, 255, 0);\n"
"}"));
        chartViewLearnProcess = new QChartView(main_page);
        chartViewLearnProcess->setObjectName(QString::fromUtf8("chartViewLearnProcess"));
        chartViewLearnProcess->setGeometry(QRect(1250, 120, 341, 221));
        chartViewLearnProcess->setStyleSheet(QString::fromUtf8("border:1px solid #776688;"));
        label_7 = new QLabel(main_page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1250, 40, 141, 41));
        label_7->setStyleSheet(QString::fromUtf8("font: 290 16pt \"Microsoft YaHei\";\n"
"background-color: rgb(71, 60, 139);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        chartViewLearnTimeBar = new QChartView(main_page);
        chartViewLearnTimeBar->setObjectName(QString::fromUtf8("chartViewLearnTimeBar"));
        chartViewLearnTimeBar->setGeometry(QRect(1260, 530, 331, 221));
        chartViewLearnTimeBar->setStyleSheet(QString::fromUtf8("border:1px solid #776688;"));
        label_6 = new QLabel(main_page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1260, 450, 141, 41));
        label_6->setStyleSheet(QString::fromUtf8("font: 290 16pt \"Microsoft YaHei\";\n"
"background-color: rgb(71, 60, 139);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        tabWidget = new QTabWidget(main_page);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(240, 440, 451, 331));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget QWidget{\n"
"	border:1px solid #ffffff;\n"
"\n"
"	border-radius:1px;\n"
"	font: 12pt \"Arial\";\n"
"	background-color:rgb(155, 155, 155); \n"
"     	\n"
"}  \n"
"  \n"
"QTabBar::tab:selected {  \n"
"    background-color:rgb(0, 155, 0); /* \350\256\276\347\275\256\351\200\211\344\270\255 tab \347\232\204\350\203\214\346\231\257\350\211\262 */ \n"
"}  \n"
"  \n"
"QTabBar::tab:hover {  \n"
"    background-color:rgb(0, 255, 0); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204 tab \350\203\214\346\231\257\350\211\262 */  \n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        labelTrj = new QLabel(tab);
        labelTrj->setObjectName(QString::fromUtf8("labelTrj"));
        labelTrj->setGeometry(QRect(10, 10, 401, 281));
        labelTrj->setStyleSheet(QString::fromUtf8("font: 290 12pt \"Microsoft YaHei\";\n"
"border-radius:3px;\n"
"border:0px solid #776688;\n"
"background-color: rgba(255, 255, 255,0);\n"
"\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 111, 71, 31));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"Arial\";\n"
"background-color: rgba(255, 255, 255,0);"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 170, 71, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"Arial\";\n"
"background-color: rgba(255, 255, 255,0);"));
        m1p_led = new QLabel(tab_2);
        m1p_led->setObjectName(QString::fromUtf8("m1p_led"));
        m1p_led->setGeometry(QRect(220, 110, 31, 31));
        m1p_led->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/grayLed.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        m2z_led = new QLabel(tab_2);
        m2z_led->setObjectName(QString::fromUtf8("m2z_led"));
        m2z_led->setGeometry(QRect(280, 170, 31, 31));
        m2z_led->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/grayLed.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        m1z_led = new QLabel(tab_2);
        m1z_led->setObjectName(QString::fromUtf8("m1z_led"));
        m1z_led->setGeometry(QRect(280, 110, 31, 31));
        m1z_led->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/grayLed.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        m1n_led = new QLabel(tab_2);
        m1n_led->setObjectName(QString::fromUtf8("m1n_led"));
        m1n_led->setGeometry(QRect(340, 110, 31, 31));
        m1n_led->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/grayLed.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        m2p_led = new QLabel(tab_2);
        m2p_led->setObjectName(QString::fromUtf8("m2p_led"));
        m2p_led->setGeometry(QRect(220, 170, 31, 31));
        m2p_led->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/grayLed.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        m2n_led = new QLabel(tab_2);
        m2n_led->setObjectName(QString::fromUtf8("m2n_led"));
        m2n_led->setGeometry(QRect(340, 170, 31, 31));
        m2n_led->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/grayLed.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(220, 140, 41, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 8pt \"Arial\";\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:0px solid #776688;"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(280, 140, 41, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 8pt \"Arial\";\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:0px solid #776688;"));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(340, 140, 41, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 8pt \"Arial\";\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:0px solid #776688;"));
        tabWidget->addTab(tab_2, QString());
        TrajLabel = new QLabel(main_page);
        TrajLabel->setObjectName(QString::fromUtf8("TrajLabel"));
        TrajLabel->setGeometry(QRect(230, 20, 451, 321));
        sizePolicy.setHeightForWidth(TrajLabel->sizePolicy().hasHeightForWidth());
        TrajLabel->setSizePolicy(sizePolicy);
        TrajLabel->setStyleSheet(QString::fromUtf8("font: 290 48pt \"Microsoft YaHei\";\n"
"border-radius:3px;\n"
"border:1px solid #776688;\n"
""));
        labelMvFs = new QLabel(main_page);
        labelMvFs->setObjectName(QString::fromUtf8("labelMvFs"));
        labelMvFs->setGeometry(QRect(230, 350, 491, 20));
        labelMvFs->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Arial\";\n"
"background-color: rgba(255, 255, 255,0);"));
        btnSubmitTask = new QToolButton(main_page);
        btnSubmitTask->setObjectName(QString::fromUtf8("btnSubmitTask"));
        btnSubmitTask->setGeometry(QRect(970, 660, 134, 44));
        btnSubmitTask->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{\n"
"	color: rgb(0, 0, 255);\n"
"	font: 290 20pt \"Microsoft YaHei\";\n"
"	border-radius:7px;\n"
"	padding:5px;	\n"
"	border:1px solid #484848;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245,245,  255), stop:1 rgba( 55,200,55, 255));\n"
"}\n"
"QToolButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #005200);\n"
"}\n"
""));
        btnStartWork = new QToolButton(main_page);
        btnStartWork->setObjectName(QString::fromUtf8("btnStartWork"));
        btnStartWork->setGeometry(QRect(760, 660, 134, 44));
        btnStartWork->setStyleSheet(QString::fromUtf8("\n"
"\n"
"\n"
"QToolButton{\n"
"	color: rgb(0, 0, 255);\n"
"	font: 290 20pt \"Microsoft YaHei\";\n"
"	border-radius:7px;\n"
"	padding:5px;	\n"
"	border:1px solid #484848;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245,245,  255), stop:1 rgba( 55,200,55, 255));\n"
"}\n"
"QToolButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #005200);\n"
"}\n"
""));
        FaceLabel = new QLabel(main_page);
        FaceLabel->setObjectName(QString::fromUtf8("FaceLabel"));
        FaceLabel->setGeometry(QRect(740, 20, 461, 321));
        FaceLabel->setStyleSheet(QString::fromUtf8("font: 290 48pt \"Microsoft YaHei\";\n"
"border-radius:3px;\n"
"border:1px solid #776688;\n"
""));
        labelUsbFs = new QLabel(main_page);
        labelUsbFs->setObjectName(QString::fromUtf8("labelUsbFs"));
        labelUsbFs->setGeometry(QRect(740, 350, 491, 21));
        labelUsbFs->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Arial\";\n"
"background-color: rgba(255, 255, 255,0);"));
        labelResult = new QLabel(main_page);
        labelResult->setObjectName(QString::fromUtf8("labelResult"));
        labelResult->setGeometry(QRect(750, 580, 501, 41));
        labelResult->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"Arial\";\n"
"background-color: rgba(255, 255, 255,0);"));
        stackedWidget->addWidget(main_page);
        config_page = new QWidget();
        config_page->setObjectName(QString::fromUtf8("config_page"));
        sizePolicy.setHeightForWidth(config_page->sizePolicy().hasHeightForWidth());
        config_page->setSizePolicy(sizePolicy);
        label_9 = new QLabel(config_page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 20, 151, 51));
        label_9->setStyleSheet(QString::fromUtf8("font: 290 24pt \"Microsoft YaHei\";\n"
"background-color: rgb(71, 60, 139);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        label_3 = new QLabel(config_page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 170, 71, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(36);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"background-color: rgba(71, 60, 139,255);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        label_8 = new QLabel(config_page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(690, 170, 71, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"background-color: rgba(71, 60, 139,255);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        IPTextEdit = new QTextEdit(config_page);
        IPTextEdit->setObjectName(QString::fromUtf8("IPTextEdit"));
        IPTextEdit->setGeometry(QRect(210, 160, 151, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(36);
        IPTextEdit->setFont(font2);
        IPTextEdit->setStyleSheet(QString::fromUtf8("font: 290 12pt \"Microsoft YaHei\";\n"
"color: rgb(0, 255, 255);"));
        PORTTextEdit = new QTextEdit(config_page);
        PORTTextEdit->setObjectName(QString::fromUtf8("PORTTextEdit"));
        PORTTextEdit->setGeometry(QRect(490, 160, 131, 31));
        PORTTextEdit->setFont(font2);
        PORTTextEdit->setStyleSheet(QString::fromUtf8("font: 290 12pt \"Microsoft YaHei\";\n"
"color: rgb(0, 255, 255);"));
        ConnectBtn = new QPushButton(config_page);
        ConnectBtn->setObjectName(QString::fromUtf8("ConnectBtn"));
        ConnectBtn->setGeometry(QRect(1010, 150, 161, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(36);
        ConnectBtn->setFont(font3);
        ConnectBtn->setAutoFillBackground(false);
        ConnectBtn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	color: rgb(0, 0, 255);\n"
"	font: 290 20pt \"Microsoft YaHei\";\n"
"	border-radius:7px;\n"
"	padding:5px;	\n"
"	border:1px solid #484848;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245,245,  255), stop:1 rgba( 55,200,55, 255));\n"
"}\n"
"QPushButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #005200);\n"
"}\n"
""));
        label_11 = new QLabel(config_page);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(380, 170, 71, 21));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"background-color: rgba(71, 60, 139,255);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        IDTextEdit = new QTextEdit(config_page);
        IDTextEdit->setObjectName(QString::fromUtf8("IDTextEdit"));
        IDTextEdit->setGeometry(QRect(790, 160, 131, 31));
        IDTextEdit->setFont(font2);
        IDTextEdit->setStyleSheet(QString::fromUtf8("font: 290 12pt \"Microsoft YaHei\";\n"
"color: rgb(0, 255, 255);"));
        textEditRead = new QTextEdit(config_page);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setGeometry(QRect(110, 230, 981, 471));
        textEditRead->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 136, 136);"));
        ClearBtn = new QPushButton(config_page);
        ClearBtn->setObjectName(QString::fromUtf8("ClearBtn"));
        ClearBtn->setGeometry(QRect(940, 720, 161, 41));
        ClearBtn->setFont(font3);
        ClearBtn->setAutoFillBackground(false);
        ClearBtn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	color: rgb(0, 0, 255);\n"
"	font: 290 20pt \"Microsoft YaHei\";\n"
"	border-radius:7px;\n"
"	padding:5px;	\n"
"	border:1px solid #484848;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245,245,  255), stop:1 rgba( 55,200,55, 255));\n"
"}\n"
"QPushButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #005200);\n"
"}\n"
""));
        stackedWidget->addWidget(config_page);
        help_page = new QWidget();
        help_page->setObjectName(QString::fromUtf8("help_page"));
        sizePolicy.setHeightForWidth(help_page->sizePolicy().hasHeightForWidth());
        help_page->setSizePolicy(sizePolicy);
        label_4 = new QLabel(help_page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 161, 71));
        label_4->setStyleSheet(QString::fromUtf8("font: 290 24pt \"Microsoft YaHei\";\n"
"background-color: rgb(71, 60, 139);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        textEditRec = new QTextEdit(help_page);
        textEditRec->setObjectName(QString::fromUtf8("textEditRec"));
        textEditRec->setGeometry(QRect(210, 60, 841, 441));
        textEditRec->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        textEditSend = new QTextEdit(help_page);
        textEditSend->setObjectName(QString::fromUtf8("textEditSend"));
        textEditSend->setGeometry(QRect(213, 520, 641, 41));
        textEditSend->setStyleSheet(QString::fromUtf8("font: 290 16pt \"Microsoft YaHei UI Light\";\n"
"color: rgb(0, 0, 255);"));
        btnSend = new QToolButton(help_page);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(860, 520, 111, 41));
        btnSend->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: 290 20pt \"Microsoft YaHei\";"));
        btnClearRec = new QToolButton(help_page);
        btnClearRec->setObjectName(QString::fromUtf8("btnClearRec"));
        btnClearRec->setGeometry(QRect(980, 520, 111, 41));
        btnClearRec->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: 290 20pt \"Microsoft YaHei\";"));
        stackedWidget->addWidget(help_page);
        person_page = new QWidget();
        person_page->setObjectName(QString::fromUtf8("person_page"));
        sizePolicy.setHeightForWidth(person_page->sizePolicy().hasHeightForWidth());
        person_page->setSizePolicy(sizePolicy);
        info_label = new QLabel(person_page);
        info_label->setObjectName(QString::fromUtf8("info_label"));
        info_label->setGeometry(QRect(10, 10, 321, 51));
        info_label->setStyleSheet(QString::fromUtf8("font: 24pt \"Arial\";\n"
"background-color: rgb(71, 60, 139);\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;"));
        user_label = new QLabel(person_page);
        user_label->setObjectName(QString::fromUtf8("user_label"));
        user_label->setGeometry(QRect(470, 110, 221, 51));
        user_label->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"color: rgb(180,255, 200);"));
        Avatar_label = new QLabel(person_page);
        Avatar_label->setObjectName(QString::fromUtf8("Avatar_label"));
        Avatar_label->setGeometry(QRect(470, 180, 221, 51));
        Avatar_label->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"color: rgb(180,255, 200);"));
        stdNum_label = new QLabel(person_page);
        stdNum_label->setObjectName(QString::fromUtf8("stdNum_label"));
        stdNum_label->setGeometry(QRect(470, 260, 221, 51));
        stdNum_label->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"color: rgb(180,255, 200);"));
        major_label = new QLabel(person_page);
        major_label->setObjectName(QString::fromUtf8("major_label"));
        major_label->setGeometry(QRect(810, 170, 221, 51));
        major_label->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"color: rgb(180,255, 200);"));
        college_label = new QLabel(person_page);
        college_label->setObjectName(QString::fromUtf8("college_label"));
        college_label->setGeometry(QRect(810, 110, 221, 51));
        college_label->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei\";\n"
"color: rgb(180,255, 200);"));
        btnSetInfo = new QToolButton(person_page);
        btnSetInfo->setObjectName(QString::fromUtf8("btnSetInfo"));
        btnSetInfo->setGeometry(QRect(620, 380, 241, 44));
        sizePolicy4.setHeightForWidth(btnSetInfo->sizePolicy().hasHeightForWidth());
        btnSetInfo->setSizePolicy(sizePolicy4);
        btnSetInfo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: 20pt \"Arial\";"));
        btnSetInfo->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        comBoxGroupMem = new QComboBox(person_page);
        comBoxGroupMem->setObjectName(QString::fromUtf8("comBoxGroupMem"));
        comBoxGroupMem->setGeometry(QRect(20, 80, 301, 31));
        comBoxGroupMem->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: 87 16pt \"Arial\";\n"
"background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(person_page);

        retranslateUi(MainForm);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "\346\231\272\346\205\247\345\234\272\346\231\257\346\225\231\350\202\262\345\271\263\345\217\260", nullptr));
        labIco->setText(QString());
        labTitle->setText(QApplication::translate("MainForm", "  \346\231\272\346\205\247\345\234\272\346\231\257\345\255\246\344\271\240\345\271\263\345\217\260 ", nullptr));
        remainTime_label->setText(QApplication::translate("MainForm", "\345\211\251\344\275\231\346\227\266\351\225\277\357\274\232", nullptr));
        globalUser_label->setText(QApplication::translate("MainForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        loginTime_label->setText(QApplication::translate("MainForm", "\347\231\273\345\275\225\346\227\266\351\227\264\357\274\232", nullptr));
        CurTime_label->setText(QApplication::translate("MainForm", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        btnExit->setText(QApplication::translate("MainForm", "\347\224\250\346\210\267\351\200\200\345\207\272", nullptr));
        btnHelp->setText(QApplication::translate("MainForm", "\346\231\272\350\203\275\350\276\205\345\257\274", nullptr));
        btnMain->setText(QApplication::translate("MainForm", "\344\270\273\347\225\214\351\235\242", nullptr));
        btnData->setText(QApplication::translate("MainForm", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        btnConfig->setText(QApplication::translate("MainForm", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnLogin->setText(QApplication::translate("MainForm", "\350\264\246\345\217\267\347\231\273\345\275\225", nullptr));
#ifndef QT_NO_TOOLTIP
        btnMenu_Max->setToolTip(QApplication::translate("MainForm", "\346\234\200\345\244\247\345\214\226", nullptr));
#endif // QT_NO_TOOLTIP
        btnMenu_Max->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("MainForm", "\345\205\263\351\227\255", nullptr));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("MainForm", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
        labelTaskProcess->setText(QApplication::translate("MainForm", "\345\255\246\344\271\240\350\277\233\345\272\246\357\274\232", nullptr));
        labelLearnTsak->setText(QApplication::translate("MainForm", "\345\275\223\345\211\215\345\255\246\344\271\240\347\233\256\346\240\207\357\274\232", nullptr));
        labelOnLine->setText(QApplication::translate("MainForm", "\345\234\250\347\272\277\344\272\272\345\221\230", nullptr));
        labelTaskCurrent->setText(QString());
        labelLearnTsak_2->setText(QApplication::translate("MainForm", "\344\273\273\345\212\241\346\200\273\350\247\210:", nullptr));
        label_7->setText(QApplication::translate("MainForm", "\345\233\242\351\230\237\345\255\246\344\271\240\350\277\233\345\272\246", nullptr));
        label_6->setText(QApplication::translate("MainForm", "\345\233\242\351\230\237\345\255\246\344\271\240\346\227\266\351\225\277", nullptr));
        labelTrj->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainForm", "\350\277\220\345\212\250\350\275\250\350\277\271", nullptr));
        label->setText(QApplication::translate("MainForm", "1\345\217\267\347\224\265\346\234\272", nullptr));
        label_2->setText(QApplication::translate("MainForm", "2\345\217\267\347\224\265\346\234\272", nullptr));
        m1p_led->setText(QString());
        m2z_led->setText(QString());
        m1z_led->setText(QString());
        m1n_led->setText(QString());
        m2p_led->setText(QString());
        m2n_led->setText(QString());
        label_12->setText(QApplication::translate("MainForm", "\346\255\243\351\231\220\344\275\215", nullptr));
        label_13->setText(QApplication::translate("MainForm", "\351\233\266\351\231\220\344\275\215", nullptr));
        label_14->setText(QApplication::translate("MainForm", "\350\264\237\351\231\220\344\275\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainForm", "\351\231\220\344\275\215\344\277\241\345\217\267", nullptr));
        TrajLabel->setText(QApplication::translate("MainForm", "\346\230\276\347\244\272\345\234\272\346\231\257", nullptr));
        labelMvFs->setText(QApplication::translate("MainForm", " \345\270\247\347\216\207\357\274\232", nullptr));
        btnSubmitTask->setText(QApplication::translate("MainForm", "\346\217\220\344\272\244\344\273\273\345\212\241", nullptr));
        btnStartWork->setText(QApplication::translate("MainForm", "\345\274\200\345\247\213\344\273\273\345\212\241", nullptr));
        FaceLabel->setText(QApplication::translate("MainForm", "\346\230\276\347\244\272\344\272\272\350\204\270", nullptr));
        labelUsbFs->setText(QApplication::translate("MainForm", " \345\270\247\347\216\207\357\274\232", nullptr));
        labelResult->setText(QApplication::translate("MainForm", "\345\256\236\351\252\214\347\273\223\346\236\234\357\274\232", nullptr));
        label_9->setText(QApplication::translate("MainForm", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label_3->setText(QApplication::translate("MainForm", "IP:", nullptr));
        label_8->setText(QApplication::translate("MainForm", "ID\357\274\232", nullptr));
        IPTextEdit->setHtml(QApplication::translate("MainForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei'; font-size:12pt; font-weight:288; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-weight:400;\">192.168.1.155</span></p></body></html>", nullptr));
        PORTTextEdit->setHtml(QApplication::translate("MainForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei'; font-size:12pt; font-weight:288; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-weight:400;\">8080</span></p></body></html>", nullptr));
        ConnectBtn->setText(QApplication::translate("MainForm", "\350\277\236\346\216\245", nullptr));
        label_11->setText(QApplication::translate("MainForm", "\347\253\257\345\217\243\357\274\232", nullptr));
        IDTextEdit->setHtml(QApplication::translate("MainForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei'; font-size:12pt; font-weight:288; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-weight:400;\">ID</span></p></body></html>", nullptr));
        ClearBtn->setText(QApplication::translate("MainForm", "\346\270\205\347\251\272", nullptr));
        label_4->setText(QApplication::translate("MainForm", "\346\231\272\350\203\275\350\276\205\345\257\274", nullptr));
        textEditSend->setHtml(QApplication::translate("MainForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI Light'; font-size:16pt; font-weight:288; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:18px; background-color:#ffffff;\"><span style=\" font-family:'IBMPlexMono','Courier New','monospace','Consolas','Courier New','monospace'; font-size:9pt; font-weight:600; color:#0451a5;\">\347\216\211\344\275\251\346\230\257\344\273\200\344\271\210</span></p></body></html>", nullptr));
        btnSend->setText(QApplication::translate("MainForm", "\345\217\221\351\200\201", nullptr));
        btnClearRec->setText(QApplication::translate("MainForm", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        info_label->setText(QApplication::translate("MainForm", " \345\233\242\351\230\237\346\210\220\345\221\230--\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        user_label->setText(QApplication::translate("MainForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        Avatar_label->setText(QApplication::translate("MainForm", "\345\210\253\345\220\215\357\274\232", nullptr));
        stdNum_label->setText(QApplication::translate("MainForm", "\345\255\246\345\217\267\357\274\232", nullptr));
        major_label->setText(QApplication::translate("MainForm", "\344\270\223\344\270\232\357\274\232", nullptr));
        college_label->setText(QApplication::translate("MainForm", "\345\255\246\351\231\242\357\274\232", nullptr));
        btnSetInfo->setText(QApplication::translate("MainForm", "\345\256\214\345\226\204\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
