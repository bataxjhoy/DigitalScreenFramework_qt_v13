/********************************************************************************
** Form generated from reading UI file 'signupform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFORM_H
#define UI_SIGNUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignupForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEditPassWord;
    QTextEdit *textEditUserName;
    QTextEdit *textEditPassWord_Ensure;
    QPushButton *SignupBtn;
    QPushButton *BackBtn;
    QPushButton *btn_close;

    void setupUi(QWidget *SignupForm)
    {
        if (SignupForm->objectName().isEmpty())
            SignupForm->setObjectName(QString::fromUtf8("SignupForm"));
        SignupForm->resize(699, 355);
        SignupForm->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);"));
        label = new QLabel(SignupForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 321, 321));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: gainsboro;\n"
"border-image: url(:/new/prefix1/image/login_image.jpg);\n"
""));
        label_2 = new QLabel(SignupForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(460, 20, 101, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 290 18pt \"Microsoft YaHei\";"));
        label_3 = new QLabel(SignupForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(460, 60, 141, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));
        textEditPassWord = new QTextEdit(SignupForm);
        textEditPassWord->setObjectName(QString::fromUtf8("textEditPassWord"));
        textEditPassWord->setGeometry(QRect(460, 140, 151, 31));
        textEditPassWord->setStyleSheet(QString::fromUtf8("color: rgb(109, 109, 109);\n"
"font: 12pt \"Arial\";"));
        textEditUserName = new QTextEdit(SignupForm);
        textEditUserName->setObjectName(QString::fromUtf8("textEditUserName"));
        textEditUserName->setGeometry(QRect(460, 90, 151, 31));
        textEditUserName->setStyleSheet(QString::fromUtf8("color: rgb(109, 109, 109);\n"
"font: 12pt \"Arial\";"));
        textEditPassWord_Ensure = new QTextEdit(SignupForm);
        textEditPassWord_Ensure->setObjectName(QString::fromUtf8("textEditPassWord_Ensure"));
        textEditPassWord_Ensure->setGeometry(QRect(460, 190, 151, 31));
        textEditPassWord_Ensure->setStyleSheet(QString::fromUtf8("color: rgb(109, 109, 109);\n"
"font: 12pt \"Arial\";"));
        SignupBtn = new QPushButton(SignupForm);
        SignupBtn->setObjectName(QString::fromUtf8("SignupBtn"));
        SignupBtn->setGeometry(QRect(460, 240, 161, 31));
        SignupBtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(14, 145, 252, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
" \n"
"border:0px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 14pt \"Candara\";"));
        BackBtn = new QPushButton(SignupForm);
        BackBtn->setObjectName(QString::fromUtf8("BackBtn"));
        BackBtn->setGeometry(QRect(460, 280, 161, 31));
        BackBtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(14, 145, 252, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
" \n"
"border:0px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 14pt \"Candara\";"));
        btn_close = new QPushButton(SignupForm);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(640, 10, 41, 41));
        btn_close->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        retranslateUi(SignupForm);

        QMetaObject::connectSlotsByName(SignupForm);
    } // setupUi

    void retranslateUi(QWidget *SignupForm)
    {
        SignupForm->setWindowTitle(QApplication::translate("SignupForm", "signUpWindow", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("SignupForm", "\346\254\242\350\277\216", nullptr));
        label_3->setText(QApplication::translate("SignupForm", "\345\212\240\345\205\245\346\231\272\346\205\247\346\225\231\350\202\262\345\271\263\345\217\260", nullptr));
        textEditPassWord->setHtml(QApplication::translate("SignupForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:9pt;\">password</span></p></body></html>", nullptr));
        textEditUserName->setHtml(QApplication::translate("SignupForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:9pt;\">user name</span></p></body></html>", nullptr));
        textEditPassWord_Ensure->setHtml(QApplication::translate("SignupForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:9pt;\">Ensure password</span></p></body></html>", nullptr));
        SignupBtn->setText(QApplication::translate("SignupForm", "\346\263\250\345\206\214", nullptr));
        BackBtn->setText(QApplication::translate("SignupForm", "\350\277\224\345\233\236", nullptr));
        btn_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignupForm: public Ui_SignupForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
