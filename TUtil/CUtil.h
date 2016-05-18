/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file CUtil.h
* @brief 通用的类集合
*
* @author: yuhaiyang
* @date: 2015/01/5
*/

#ifndef CUTIL_H
#define CUTIL_H

#include "CLog.h"
#include <Poco/Data/SessionPool.h>
#include <redis/CRedisPool.h>
#include <memory>
#include <iostream>
#include <memory>
#include "CLogs.h"
#include "Taiji/Except/Except.h"


namespace Taiji {

namespace TUtil {

TAIJI_NEW_EXCEPTION( ExceptTUtil, Except )

/**
 * @brief The CUtil class
 *
 * 单实例对象，不可构造，用于通用类的集合
 * 包含 mysql 连接池类
 * 包含 redis 链接池类
 * 包含 log 类。
 */
class CUtil
{
public:
    CUtil( const CUtil& other) = delete;
    CUtil& operator = ( const CUtil& other ) = delete;

    ~CUtil();

    /**
     * @brief instance
     * @return 返回全局单实例对象的引用
     */
    static CUtil& instance();

    /**
      * @brief __initLog 创建一个日志
      * @param dir 日志文件的路径，如果日志路径不存在的话，会自动创建.路径后要带反斜杠
      * @param file 日志文件的文件名
      * @param name 此日志对象的名字
      * @param level 日志等级 - none (turns off logging) - fatal critical	 error	 warning
      *                 notice information	 debug	 trace
      * @return None
      *
      * @example     CLogs::instance().createLog( "./log/","test.log","TEST_LOG" );
      */
     void createLog( const std::string &dir, const std::string &file, const std::string &name,
                     const std::string &level=CLog::DEFAULT_LOG_LEVEL,
                     const std::string &rotation=CLog::DEFAULT_LOG_ROTATION,
                     const std::string& purgeAge=CLog::DEFAULT_LOG_PURGEAGE );



     /**
      * @brief getLog
      * @return 返回日志对象的引用
      *
      * eg: CLog& log = CUtil::instance().getLog();
      * @warning 找不到会抛出 ExceptionNotFindLog 异常
      */
     CLog &getLog(const std::string &logName);





    /**
     * @brief initMysql 初始化 mysql
     * @param host ip
     * @param port 端口
     * @param user mysql 用户
     * @param pass mysql 用户 pass
     * @param db mysql db
     * @param minSession 最小链接数
     * @param maxSession 最大链接数
     */
    void initMysql(const string &host, uint16_t port, const string &user, const string &pass,
                          const string &db, uint16_t minSession, uint16_t maxSession);

    /**
     * @brief getMysql 获取　mysql 对象。
     * @return 返回一个　mysql Session。
     */
    Poco::Data::Session getMysql();


    /**
     * @brief initRedis 初始化 redis 链接池
     * @param host ip
     * @param port 端口
     * @param maxSession 最大链接数
     * @return true 成功。false 失败
     */
    void initRedis(const std::string &host, uint16_t port, uint16_t maxSession);

    /**
     * @brief getRedis 从 CRedisPool 里获取一个链接。
     * @param place 获取的对象在链接池中的位置。可以快速放回连接池。
     * @param millisecond　如果所有链接都忙的话那么允许等待的最大的秒数。
     * @return 	返回一个可用的链接对象地址。
     */
     Redis::CRedisPool::Handle getRedis(long millisecond );

private:
    CUtil() = default;
    std::shared_ptr<Redis::CRedisPool> _redisPool = nullptr;
    std::shared_ptr<Poco::Data::SessionPool> _pSessionPool = nullptr;
    std::shared_ptr<CLogs> _logs = nullptr;


    ///////////////////////////////// 私有函数声明 /////////////////////////////
    void __uninitMysql();
    void __uninitRedis();
};


}

} //namespace Taiji


#endif // CUTIL_H
