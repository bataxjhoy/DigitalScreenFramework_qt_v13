#ifndef ADDINFOFORM_H
#define ADDINFOFORM_H

#include <QWidget>

//#pragma execution_character_set("utf-8")
namespace Ui {
class addInfoForm;
}

class addInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit addInfoForm(QWidget *parent = nullptr);
    ~addInfoForm();

private slots:
    void on_btn_close_clicked();

    void on_SaveBtn_clicked();

private:
    Ui::addInfoForm *ui;
};

#endif // ADDINFOFORM_H
