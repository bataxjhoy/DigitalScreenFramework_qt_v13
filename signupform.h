#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>


namespace Ui {
class SignupForm;
}

class SignupForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignupForm(QWidget *parent = nullptr);
    ~SignupForm();

private slots:
    void on_SignupBtn_clicked();

    void on_BackBtn_clicked();

    void on_btn_close_clicked();

private:
    Ui::SignupForm *ui;
};

#endif // SIGNUPFORM_H
