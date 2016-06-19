#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T14:13:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = TaijiUtil

TEMPLATE = lib

CONFIG += c++11

DEFINES += \

INCLUDEPATH += \
    ../../

LIBS += \
        -lPocoUtil	\
        -lPocoFoundation \
        -lPocoNet	\
        -lPocoDataMySQL	\
        -lPocoData	\

unix {
    target.path = /usr/local/lib
    INSTALLS += target
    headfile.files = *.h
    headfile.path = /usr/local/include/Taiji/TUtil
    INSTALLS += headfile
}



HEADERS += \
    CLog.h \
    CLogs.h \
    CParams.h \
    CUtil.h

SOURCES += \
    CLog.cpp \
    CLogs.cpp \
    CParams.cpp \
    CUtil.cpp


