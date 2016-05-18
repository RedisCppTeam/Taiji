TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    gtest/UnitTest.cpp \
    Util/CLog.cpp \
    Util/CUtil.cpp \
    Util/Exception/Except.cpp \
    Util/CLogs.cpp \
    gtest/CUtilUnitTest.cpp \
    Util/CParams.cpp


HEADERS += \
    Util/CLog.h \
    Util/CUtil.h \
    Util/Exception/Except.h \
    Util/CLogs.h \
    gtest/CUtilUnitTest.h \
    Util/CParams.h


LIBS += \
        -lPocoFoundation	\
        -lPocoData		\
        -lPocoNet		\
        -lPocoDataMySQL		\
        -lgtest    		\
        -lgtest_main   		\
        -lpthread			\
        -lredisclient

unix:!macx: LIBS += -L/usr/local/lib/redis/ -lredisclient

INCLUDEPATH += /usr/local/lib/redis
DEPENDPATH += /usr/local/lib/redis
