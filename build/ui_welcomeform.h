/********************************************************************************
** Form generated from reading UI file 'welcomeform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEFORM_H
#define UI_WELCOMEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcomeForm
{
public:
    QPushButton *enterBtn;
    QLabel *labelTip;
    QLabel *label;
    QLabel *labelPic;
    QPushButton *btn_close;
    QLabel *labelWelcome;

    void setupUi(QWidget *welcomeForm)
    {
        if (welcomeForm->objectName().isEmpty())
            welcomeForm->setObjectName(QString::fromUtf8("welcomeForm"));
        welcomeForm->resize(910, 502);
        welcomeForm->setStyleSheet(QString::fromUtf8(""));
        enterBtn = new QPushButton(welcomeForm);
        enterBtn->setObjectName(QString::fromUtf8("enterBtn"));
        enterBtn->setGeometry(QRect(410, 399, 171, 41));
        enterBtn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    border: 1px solid #555;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(0, 100, 255, 255));\n"
"	color: rgb(255, 255, 255); \n"
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
"}\n"
""));
        labelTip = new QLabel(welcomeForm);
        labelTip->setObjectName(QString::fromUtf8("labelTip"));
        labelTip->setGeometry(QRect(390, 230, 431, 71));
        labelTip->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Arial\";"));
        label = new QLabel(welcomeForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-30, -10, 971, 511));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/image/welcome.png);"));
        labelPic = new QLabel(welcomeForm);
        labelPic->setObjectName(QString::fromUtf8("labelPic"));
        labelPic->setGeometry(QRect(140, 150, 201, 251));
        labelPic->setStyleSheet(QString::fromUtf8(""));
        btn_close = new QPushButton(welcomeForm);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(790, 40, 51, 51));
        btn_close->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"background-color: rgba(0, 0, 0,0);\n"
"color: rgb(255, 255,255);\n"
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
        labelWelcome = new QLabel(welcomeForm);
        labelWelcome->setObjectName(QString::fromUtf8("labelWelcome"));
        labelWelcome->setGeometry(QRect(250, 80, 521, 71));
        labelWelcome->setStyleSheet(QString::fromUtf8("color: rgb(235, 0, 0);\n"
"font: 30pt \"Arial\";"));
        label->raise();
        enterBtn->raise();
        labelTip->raise();
        labelPic->raise();
        btn_close->raise();
        labelWelcome->raise();

        retranslateUi(welcomeForm);

        QMetaObject::connectSlotsByName(welcomeForm);
    } // setupUi

    void retranslateUi(QWidget *welcomeForm)
    {
        welcomeForm->setWindowTitle(QApplication::translate("welcomeForm", "Form", nullptr));
        enterBtn->setText(QApplication::translate("welcomeForm", "\350\277\233\345\205\245", nullptr));
        labelTip->setText(QApplication::translate("welcomeForm", "\346\217\220\347\244\272\357\274\232", nullptr));
        label->setText(QString());
        labelPic->setText(QString());
        btn_close->setText(QApplication::translate("welcomeForm", "X", nullptr));
        labelWelcome->setText(QApplication::translate("welcomeForm", "\346\254\242\350\277\216\344\275\277\347\224\250\346\231\272\346\205\247\345\234\272\346\231\257\345\255\246\344\271\240\345\271\263\345\217\260\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcomeForm: public Ui_welcomeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEFORM_H
