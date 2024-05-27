#ifndef WELCOMEFORM_H
#define WELCOMEFORM_H

#include <QWidget>
#include <QTimer>
#include "global.h"
namespace Ui {
class welcomeForm;
}
class welcomeForm : public QWidget
{
    Q_OBJECT

public:
     QTimer *timer ;
    explicit welcomeForm(QWidget *parent = nullptr);
    ~welcomeForm();
    bool eventFilter(QObject *watched, QEvent *evt);
private slots:
    void on_enterBtn_clicked();
    void Timer_process();

    void on_btn_close_clicked();

private:
    Ui::welcomeForm *ui;
};

#endif // WELCOMEFORM_H
