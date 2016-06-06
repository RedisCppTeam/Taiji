TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH +=	\
        ../../../

LIBS += \
        -lgtest    \
        -lgtest_main   \
        -lpthread

HEADERS += \
    ../Except.h

SOURCES += \
    UnitTest.cpp \
    ../Except.cpp

