TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += \
        -lgtest    \
        -lgtest_main   \
        -lpthread


SOURCES += \
    gtest/UnitTest.cpp \
    Exception.cpp

HEADERS += \
    Exception.h
