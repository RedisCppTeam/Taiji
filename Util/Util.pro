TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    gtest/UnitTest.cpp \
    Util/CLog.cpp \
    Util/CUtil.cpp \
    Util/Exception/Exception.cpp

HEADERS += \
    Util/CLog.h \
    Util/CUtil.h \
    Util/Exception/Exception.h


LIBS += \
        -lPocoFoundation	\
        -lPocoData		\
        -lRedisclient		\
        -lPocoNet		\
        -lPocoDataMySQL
