#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T14:13:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = TaijiRedis

TEMPLATE = lib

CONFIG += c++11

DEFINES += \


INCLUDEPATH += ../../

unix {
    target.path = ../lib
    INSTALLS += target
}

HEADERS += \
    Command.h \
    CRedisClient.h \
    CRedisPool.h \
    CRedisSocket.h \
    CResult.h \
    ExceptRedis.h \
    redisCommon.h

SOURCES += \
    Command.cpp \
    CRedisClient.cpp \
    CRedisPool.cpp \
    CRedisSocket.cpp \
    CResult.cpp \
    RedisClientConnection.cpp \
    RedisClientHash.cpp \
    RedisClientHyperLogLog.cpp \
    RedisClientKey.cpp \
    RedisClientList.cpp \
    RedisClientPSub.cpp \
    RedisClientScript.cpp \
    RedisClientServer.cpp \
    RedisClientSet.cpp \
    RedisClientSortedSet.cpp \
    RedisClientString.cpp \
    RedisTransaction.cpp


