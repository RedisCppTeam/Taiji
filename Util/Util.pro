TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    gtest/UnitTest.cpp \
    Util/CLog.cpp \
    Util/CUtil.cpp

HEADERS += \
    Util/CLog.h \
    Util/common.h \
    Util/CUtil.h \
    Util/Exception.hpp


LIBS += \
        -lPocoFoundation	\
        -lPocoData		\
        -lRedisclient		\
        -lPocoNet		\
        -lPocoDataMySQL
