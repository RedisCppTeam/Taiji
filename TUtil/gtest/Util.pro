TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../../../

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

HEADERS += \
    CUtilUnitTest.h \
    ../CLog.h \
    ../CLogs.h \
    ../CParams.h \
    ../CUtil.h

SOURCES += \
    CUtilUnitTest.cpp \
    UnitTest.cpp \
    ../CLog.cpp \
    ../CLogs.cpp \
    ../CParams.cpp \
    ../CUtil.cpp
