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
#include <CRedisPool.h>
#include <memory>
#include <iostream>

namespace Taiji {




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
     * @param dir 日志文件的路径，如果日志路径不存在的话，会自动创建
     * @param file 日志文件的文件名
     * @param name 此日志对象的名字
     * @param level 日志等级 - none (turns off logging) - fatal critical	 error	 warning
     *                 notice information	 debug	 trace
     * @return None
     */
    void initLog( const std::string &dir, const std::string &file, const std::string &name, const std::string &level );

    /**
     * @brief getLog
     * @return 返回日志对象的引用
     *
     * eg: CLog& log = CUtil::instance().getLog();
     */
    CLog& getLog( void );



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
    bool initRedis(const std::string &host, uint16_t port, uint16_t maxSession);

    /**
     * @brief getRedis 从 CRedisPool 里获取一个链接。
     * @param place 获取的对象在链接池中的位置。可以快速放回连接池。
     * @param millisecond　如果所有链接都忙的话那么允许等待的最大的秒数。
     * @return 	返回一个可用的链接对象地址。
     */
    CRedisClient *getRedis(int32_t &place, long millisecond);

    /**
     * @brief putBackRedis 把　CRedisClient 对象放回链接池。
     * @param place 要放回的链接所在的位置。
     */
    void putBackRedis(int32_t place);
private:
    CUtil() = default;
    CRedisPool _redisPool;
    CLog _log;
    std::shared_ptr<Poco::Data::SessionPool> _pSessionPool;



    ///////////////////////////////// 私有函数声明 /////////////////////////////
    void __uninitMysql();
    void __uninitRedis();
};


} //namespace Taiji


#endif // CUTIL_H