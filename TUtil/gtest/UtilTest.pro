TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../../../

LIBS += \
        -lPocoUtil	\
        -lPocoFoundation \
        -lPocoNet	\
        -lPocoDataMySQL	\
        -lPocoData	\
        -lgtest    		\
        -lgtest_main   		\
        -lpthread		\
        -L../../../lib  -lTaijiRedis -lTaijiExcept -lTaijiUtil



HEADERS += \
    CUtilUnitTest.h \

SOURCES += \
    CUtilUnitTest.cpp \

