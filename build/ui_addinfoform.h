/********************************************************************************
** Form generated from reading UI file 'addinfoform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINFOFORM_H
#define UI_ADDINFOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addInfoForm
{
public:
    QPushButton *btn_close;
    QPushButton *SaveBtn;
    QTextEdit *textEditAvatar;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEditStdNum;
    QTextEdit *textEditCollege;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEditMajor;
    QLabel *label_5;
    QTextEdit *textEditUser;
    QLabel *label_6;

    void setupUi(QWidget *addInfoForm)
    {
        if (addInfoForm->objectName().isEmpty())
            addInfoForm->setObjectName(QString::fromUtf8("addInfoForm"));
        addInfoForm->resize(589, 531);
        addInfoForm->setStyleSheet(QString::fromUtf8("border-color: rgb( 0,0,255);"));
        btn_close = new QPushButton(addInfoForm);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(530, 10, 41, 41));
        btn_close->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        SaveBtn = new QPushButton(addInfoForm);
        SaveBtn->setObjectName(QString::fromUtf8("SaveBtn"));
        SaveBtn->setGeometry(QRect(170, 440, 161, 31));
        SaveBtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(14, 145, 252, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
" \n"
"border:0px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 14pt \"Candara\";"));
        textEditAvatar = new QTextEdit(addInfoForm);
        textEditAvatar->setObjectName(QString::fromUtf8("textEditAvatar"));
        textEditAvatar->setGeometry(QRect(140, 130, 161, 31));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEditAvatar->sizePolicy().hasHeightForWidth());
        textEditAvatar->setSizePolicy(sizePolicy);
        textEditAvatar->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 230);\n"
"font: 290 12pt \"Microsoft YaHei\";"));
        textEditAvatar->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditAvatar->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(addInfoForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 130, 81, 31));
        label->setStyleSheet(QString::fromUtf8("font: 290 24pt \"Microsoft YaHei\";\n"
"color: rgb(0, 85, 255);"));
        label_2 = new QLabel(addInfoForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 190, 81, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 290 24pt \"Microsoft YaHei\";\n"
"color: rgb(0, 85, 255);"));
        textEditStdNum = new QTextEdit(addInfoForm);
        textEditStdNum->setObjectName(QString::fromUtf8("textEditStdNum"));
        textEditStdNum->setGeometry(QRect(140, 190, 161, 31));
        sizePolicy.setHeightForWidth(textEditStdNum->sizePolicy().hasHeightForWidth());
        textEditStdNum->setSizePolicy(sizePolicy);
        textEditStdNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 230);\n"
"font: 290 12pt \"Microsoft YaHei\";\n"
""));
        textEditStdNum->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditStdNum->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditCollege = new QTextEdit(addInfoForm);
        textEditCollege->setObjectName(QString::fromUtf8("textEditCollege"));
        textEditCollege->setGeometry(QRect(140, 250, 161, 31));
        sizePolicy.setHeightForWidth(textEditCollege->sizePolicy().hasHeightForWidth());
        textEditCollege->setSizePolicy(sizePolicy);
        textEditCollege->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 230);\n"
"font: 290 12pt \"Microsoft YaHei\";"));
        textEditCollege->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditCollege->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_3 = new QLabel(addInfoForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 250, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 290 24pt \"Microsoft YaHei\";\n"
"color: rgb(0, 85, 255);"));
        label_4 = new QLabel(addInfoForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 310, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 290 24pt \"Microsoft YaHei\";\n"
"color: rgb(0, 85, 255);"));
        textEditMajor = new QTextEdit(addInfoForm);
        textEditMajor->setObjectName(QString::fromUtf8("textEditMajor"));
        textEditMajor->setGeometry(QRect(140, 310, 161, 31));
        sizePolicy.setHeightForWidth(textEditMajor->sizePolicy().hasHeightForWidth());
        textEditMajor->setSizePolicy(sizePolicy);
        textEditMajor->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 230);\n"
"font: 290 12pt \"Microsoft YaHei\";"));
        textEditMajor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditMajor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_5 = new QLabel(addInfoForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 251, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 290 24pt \"Microsoft YaHei\";\n"
"color: rgb(0, 85, 255);"));
        textEditUser = new QTextEdit(addInfoForm);
        textEditUser->setObjectName(QString::fromUtf8("textEditUser"));
        textEditUser->setGeometry(QRect(140, 80, 161, 31));
        sizePolicy.setHeightForWidth(textEditUser->sizePolicy().hasHeightForWidth());
        textEditUser->setSizePolicy(sizePolicy);
        textEditUser->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 230);\n"
"font: 290 12pt \"Microsoft YaHei\";"));
        textEditUser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditUser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_6 = new QLabel(addInfoForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 80, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 290 24pt \"Microsoft YaHei\";\n"
"color: rgb(0, 85, 255);"));

        retranslateUi(addInfoForm);

        QMetaObject::connectSlotsByName(addInfoForm);
    } // setupUi

    void retranslateUi(QWidget *addInfoForm)
    {
        addInfoForm->setWindowTitle(QApplication::translate("addInfoForm", "Form", nullptr));
        btn_close->setText(QString());
        SaveBtn->setText(QApplication::translate("addInfoForm", "\344\277\235\345\255\230", nullptr));
        label->setText(QApplication::translate("addInfoForm", "\345\210\253\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("addInfoForm", "\345\255\246\345\217\267\357\274\232", nullptr));
        textEditStdNum->setHtml(QApplication::translate("addInfoForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei'; font-size:12pt; font-weight:288; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        textEditCollege->setHtml(QApplication::translate("addInfoForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei'; font-size:12pt; font-weight:288; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("addInfoForm", "\345\255\246\351\231\242\357\274\232", nullptr));
        label_4->setText(QApplication::translate("addInfoForm", "\344\270\223\344\270\232\357\274\232", nullptr));
        textEditMajor->setHtml(QApplication::translate("addInfoForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei'; font-size:12pt; font-weight:288; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("addInfoForm", "\345\256\214\345\226\204\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        label_6->setText(QApplication::translate("addInfoForm", "\345\210\253\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addInfoForm: public Ui_addInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINFOFORM_H
