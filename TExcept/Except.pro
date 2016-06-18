#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T14:13:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = TaijiExcept

TEMPLATE = lib

CONFIG += c++11

DEFINES += \

unix {
    target.path = /usr/local/lib
    INSTALLS += target
    headfile.files = *.h
    headfile.path = /usr/local/include/Taiji/TExcept
    INSTALLS += headfile
}

HEADERS += \
    Except.h

SOURCES += \
    Except.cpp
