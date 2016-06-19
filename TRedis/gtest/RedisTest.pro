TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += \
        -lPocoFoundation \
        -lPocoNet	\
        -lgtest \
        -lgtest_main \
        -lpthread \
        -lTaijiRedis \
        -lTaijiExcept



HEADERS += \
    src/CTestConnect.h \
    src/CTestHash.h \
    src/CTestKey.h \
    src/CTestList.h \
    src/CTestPool.h \
    src/CTestPub.h \
    src/CTestScript.h \
    src/CTestSet.h \
    src/CTestSortedSet.h \
    src/CTestString.h \



SOURCES += \
    src/CTestConnect.cpp \
    src/CTestHash.cpp \
    src/CTestKey.cpp \
    src/CTestList.cpp \
    src/CTestPool.cpp \
    src/CTestPub.cpp \
    src/CTestScript.cpp \
    src/CTestSet.cpp \
    src/CTestSortedSet.cpp \
    src/CTestString.cpp \
    src/testHyperLogLog.cpp \
    src/testList.cpp \
    src/testPSub.cpp \
    src/testscript.cpp \
    src/testServer.cpp \
    src/testString.cpp \
    src/testTransaction.cpp \
