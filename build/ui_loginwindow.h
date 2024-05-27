/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelCamera;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *LoginBtn;
    QPushButton *SignupBtn;
    QPushButton *btn_close;
    QLineEdit *textEditUserName;
    QLineEdit *textEditPassWord;
    QLabel *labelTip;
    QLabel *label;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->setEnabled(true);
        LoginWindow->resize(1008, 553);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelCamera = new QLabel(centralwidget);
        labelCamera->setObjectName(QString::fromUtf8("labelCamera"));
        labelCamera->setGeometry(QRect(30, 70, 521, 381));
        labelCamera->setAutoFillBackground(false);
        labelCamera->setStyleSheet(QString::fromUtf8("background-color: gainsboro;\n"
"border-image: url(:/new/prefix1/image/login_image.jpg);\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(600, 30, 311, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 28pt \"Arial\";\n"
"color: rgb(0, 0, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255,255,  255), stop:1 rgba( 0, 255,255, 255));\n"
"border-radius:7px; "));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 80, 151, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 12pt \"Bahnschrift Light\";\n"
"color: rgb(0, 85, 255);\n"
"background-color: rgba(255, 255, 255,0);"));
        LoginBtn = new QPushButton(centralwidget);
        LoginBtn->setObjectName(QString::fromUtf8("LoginBtn"));
        LoginBtn->setGeometry(QRect(670, 360, 221, 51));
        LoginBtn->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border: 1px solid #555;\n"
"	background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(14, 145, 252, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(255, 255, 255);\n"
" \n"
"	border:0px groove gray;\n"
"	border-radius:7px;\n"
"	padding:2px 4px;\n"
"	font: 16pt \"Arial\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(85, 170, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"   color: #333333;\n"
"}\n"
""));
        SignupBtn = new QPushButton(centralwidget);
        SignupBtn->setObjectName(QString::fromUtf8("SignupBtn"));
        SignupBtn->setEnabled(false);
        SignupBtn->setGeometry(QRect(670, 420, 221, 51));
        SignupBtn->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border: 1px solid #555;\n"
"	background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(14, 145, 252, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(255, 255, 255);\n"
" \n"
"	border:0px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"	font: 16pt \"Arial\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(85, 170, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"   color: #333333;\n"
"}"));
        btn_close = new QPushButton(centralwidget);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(930, 20, 61, 61));
        btn_close->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"background-color: rgba(0, 0, 0,0);\n"
"color: rgb(0, 0, 0);\n"
"	font: 16pt \"Arial\";\n"
"border-radius:7px; \n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(190, 30, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"   color: #333333;\n"
"}\n"
"\n"
""));
        textEditUserName = new QLineEdit(centralwidget);
        textEditUserName->setObjectName(QString::fromUtf8("textEditUserName"));
        textEditUserName->setGeometry(QRect(670, 120, 211, 61));
        textEditUserName->setStyleSheet(QString::fromUtf8("font: 16pt \"Arial\";\n"
"background-color: rgb(255, 255, 255);"));
        textEditPassWord = new QLineEdit(centralwidget);
        textEditPassWord->setObjectName(QString::fromUtf8("textEditPassWord"));
        textEditPassWord->setGeometry(QRect(670, 190, 211, 61));
        textEditPassWord->setStyleSheet(QString::fromUtf8("font: 16pt \"Arial\";\n"
"background-color: rgb(255, 255, 255);"));
        labelTip = new QLabel(centralwidget);
        labelTip->setObjectName(QString::fromUtf8("labelTip"));
        labelTip->setGeometry(QRect(670, 270, 321, 31));
        labelTip->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"border-radius:7px; "));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1011, 561));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245,245,  255), stop:1 rgba( 0, 255,255, 255));"));
        LoginWindow->setCentralWidget(centralwidget);
        label->raise();
        labelCamera->raise();
        label_2->raise();
        label_3->raise();
        LoginBtn->raise();
        SignupBtn->raise();
        btn_close->raise();
        textEditUserName->raise();
        textEditPassWord->raise();
        labelTip->raise();

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", nullptr));
        labelCamera->setText(QString());
        label_2->setText(QApplication::translate("LoginWindow", "\346\231\272\346\205\247\345\234\272\346\231\257\345\255\246\344\271\240\345\271\263\345\217\260", nullptr));
        label_3->setText(QApplication::translate("LoginWindow", "\344\270\223\346\263\250\346\231\272\346\205\247\346\225\231\350\202\262\345\271\263\345\217\260", nullptr));
        LoginBtn->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        SignupBtn->setText(QApplication::translate("LoginWindow", "\346\263\250\345\206\214", nullptr));
        btn_close->setText(QApplication::translate("LoginWindow", "X", nullptr));
        textEditUserName->setText(QApplication::translate("LoginWindow", "\350\260\242\351\207\221\350\276\211", nullptr));
        textEditUserName->setPlaceholderText(QApplication::translate("LoginWindow", "userName", nullptr));
        textEditPassWord->setText(QApplication::translate("LoginWindow", "123456", nullptr));
        textEditPassWord->setPlaceholderText(QApplication::translate("LoginWindow", "passWord", nullptr));
        labelTip->setText(QApplication::translate("LoginWindow", "\346\217\220\347\244\272\357\274\232", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
