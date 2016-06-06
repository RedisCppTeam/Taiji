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
    target.path = ../lib
    INSTALLS += target
}

HEADERS += \
    Except.h

SOURCES += \
    Except.cpp
