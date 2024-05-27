#include "loginwindow.h"
#include <QFile>
#include <QApplication>
#include <iostream>

#include <QGuiApplication>
#include <Windows.h>
#include <WinUser.h>
#include "welcomeform.h"
using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);


    welcomeForm w;
    w.show();
    return a.exec();
}
