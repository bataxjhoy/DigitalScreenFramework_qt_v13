QT       += core gui
QT       += sql
QT       += network
QT       += charts
QT       += texttospeech
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addinfoform.cpp \
    autoresize.cpp \
    global.cpp \
    iconhelper.cpp \
    main.cpp \
    loginwindow.cpp \
    mainform.cpp \
    mvcameraclass.cpp \
    my_redis.cpp \
    myprotocol.cpp \
    signupform.cpp \
    usbcamera.cpp \
    welcomeform.cpp

HEADERS += \
    addinfoform.h \
    autoresize.h \
    global.h \
    iconhelper.h \
    loginwindow.h \
    mainform.h \
    mvcameraclass.h \
    my_redis.h \
    myprotocol.h \
    signupform.h \
    usbcamera.h \
    welcomeform.h

FORMS += \
    addinfoform.ui \
    loginwindow.ui \
    mainform.ui \
    signupform.ui \
    welcomeform.ui

INCLUDEPATH += $$PWD\sdk\Include

LIBS    += $$PWD\sdk\MVCAMSDK_X64.lib


# INCLUDEPATH += C:\opencv\mybuild\install\include
# LIBS += C:\opencv\mybuild\install\x64\mingw\lib\libopencv_*.a
# LIBS += C:\opencv\mybuild\install\x64\mingw\bin\libopencv_*.dll

LIBS += -L$$PWD/QtHiRedis_Lib_PATH/libs -lQtHiRedis
INCLUDEPATH += $$PWD/QtHiRedis_Lib_PATH/include
HEADERS += $$PWD/QtHiRedis_Lib_PATH/include/adapters/qt.h


INCLUDEPATH += D:\opencv\build\install\include
LIBS +=  D:\opencv\build\install\x64\mingw\lib\libopencv_*.a
LIBS +=  D:\opencv\build\install\x64\mingw\bin\libopencv_*.dll


#INCLUDEPATH += \
#    -I D:\soft\python3_9\include
#INCLUDEPATH += \
#    -I D:\soft\python3_9\Lib\site-packages\numpy\core\include
#LIBS += \
#    -L D:\soft\python3_9\libs -lpython39


INCLUDEPATH += \
    -I G:\workspace\majun\conda\envs\scene_learning_1\include
INCLUDEPATH += \
    -I G:\workspace\majun\conda\envs\scene_learning_1\Lib\site-packages\numpy\core\include
LIBS += \
    -L G:\workspace\majun\conda\envs\scene_learning_1\libs -lpython39


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qss.qrc \
    res.qrc

DISTFILES +=
