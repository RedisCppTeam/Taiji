/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file xxxxxxx
* @brief 文件的简单介绍
*
* 文件的详细介绍
*
* @author: yuhaiyang
* @date: 2016/5/12
*/

#include "CLogs.h"

namespace Taiji {

namespace TUtil {


CLogs& CLogs::instance()
{
    static CLogs singleton;
    return singleton;
}




void CLogs::createLog(const std::string &dir, const std::string &file, const std::string &name,
                      const std::string &level, const std::string &rotation, const std::string &purgeAge)
{
    std::shared_ptr<CLog> pLog( new CLog( dir, file, name, level, rotation, purgeAge) );
    _logMap.insert( std::pair<std::string,std::shared_ptr<CLog>>( name, pLog ) );
}

CLog &CLogs::getLog(const std::string &logName )
{
    auto itLog = _logMap.find( logName );
    if ( itLog == _logMap.end() )
    {
        throw ExceptNotFindLog("not find Clog object" );
    }
    return *(itLog->second);
}


}// namespace Util


}//namespace Taiji
