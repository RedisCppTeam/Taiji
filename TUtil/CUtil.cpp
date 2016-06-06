/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file CUtil.cpp
* @brief 通用的类集合
*
* @author: yuhaiyang
* @date: 2015/12/25
*/

#include "CUtil.h"
#include <sstream>
#include <Poco/Data/MySQL/Connector.h>
#include <string>

namespace  Taiji {

namespace TUtil {

using namespace Poco;

CUtil::~CUtil()
{
    __uninitMysql();
    __uninitRedis();
}

CUtil &CUtil::instance()
{
    static CUtil singleton;
    return singleton;
}

void CUtil::createLog(const std::string &dir, const std::string &file, const std::string &name,
                      const std::string &level, const std::string &rotation, const std::string &purgeAge)
{
    CLogs::instance().createLog( dir, file, name, level, rotation, purgeAge );
}

CLog &CUtil::getLog(const std::string &logName)
{
   return( CLogs::instance().getLog( logName ));
}



void CUtil::initMysql( const string& host, uint16_t port, const string& user, const string&pass,
                       const string& db, uint16_t minSession,uint16_t maxSession )
{
    std::stringstream ss;
    ss << port;
    std::string sPort = ss.str();
    std::string connectInfo = "host=" + host + " ; " + "port=" +sPort + " ; "
                    + "user=" + user + " ; " + "password=" +pass + " ; " + "db="
                    + db + " ; " + "auto-reconnect=" + "true";
    //DEBUGOUT( "connectInfo", connectInfo );
    //------------------------初始化数据库连接池-------------------------
    Poco::Data::MySQL::Connector::registerConnector();
    _pSessionPool =std::unique_ptr<Poco::Data::SessionPool>( new Poco::Data::SessionPool("MySQL", connectInfo, minSession, maxSession) );
}

Data::Session CUtil::getMysql( void )
{
    return _pSessionPool->get();
}

void CUtil::__uninitMysql()
{
    if ( _pSessionPool!= nullptr )
    {
        _pSessionPool->shutdown();
        Poco::Data::MySQL::Connector::unregisterConnector();
    }
}

void CUtil::initRedis( const std::string& host, uint16_t port, uint16_t maxSession )
{
    _pRedisPool = std::shared_ptr<TRedis::CRedisPool>( new TRedis::CRedisPool );
    _pRedisPool->init( host, port,0,maxSession,5 );
}

void CUtil::__uninitRedis()
{
    if ( _pRedisPool != nullptr )
    {
        _pRedisPool->closeConnPool();
    }
}

TRedis::CRedisPool::Handle CUtil::getRedis( long millisecond )
{
    return( _pRedisPool->getRedis( millisecond ) );
}



}

} //namespace Taiji
