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
    target.path = ../lib
    INSTALLS += target
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


