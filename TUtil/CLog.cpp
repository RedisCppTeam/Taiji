/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file CLog.cpp
* @brief 日志类的实现文件
*
*	一个写日志文件的类
*
* @author: yuhaiyang
* @date: 2016/1/6
*/

#include <iostream>
#include "CLog.h"

//日志相关的头文件
#include <Poco/FileChannel.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <Poco/Logger.h>
#include <Poco/AutoPtr.h>
#include <Poco/Thread.h>



namespace Taiji
{

namespace TUtil {


//



 //一些默认值常量
const std::string CLog::HEAD_FMT			  =		"[**%s**] [tid:%lu] [class:%s] [func:%s] MSG:";
const std::string CLog::HEAD_FMT_INDEX		  =		"[**%s**] [tid:%lu] [class:%s] [func:%s] [%s:%s] MSG:";
const std::string CLog::DEFAULT_LOG_ROTATION  =		"1 days";
const std::string CLog::DEFAULT_LOG_PURGEAGE  =		"1 months";
const std::string CLog::DEFAULT_LOG_LEVEL	  =		"information";


CLog::CLog(const std::string& dir, const std::string& file, const std::string& name ,
           const std::string &level , const std::string &rotation, const std::string &purgeAge):
    _dir( dir ),_file( file ),_name( name ),_level( level ),_rotation( rotation),_purgeAge( purgeAge )
{
    initLog( _dir, _file, _name, _level, _rotation,_purgeAge );
}


void CLog::initLog(const std::string& dir, const std::string& file, const std::string& name ,
                   const std::string &level , const std::string &rotation, const std::string &purgeAge)
{
    using Poco::FileChannel;
    //检查当前目录下是否有log目录，否则创建一个
    if ( access(  dir.c_str(), F_OK) != 0 )
    {
        //如果不存在就用mkdir函数来创建
        if ( mkdir( dir.c_str(), 0777) )
        {
            std::cerr << strerror( errno ) << std::endl;
        }
    }

    //日志部分。
    Poco::AutoPtr<Poco::Channel> channel;
    {
        Poco::AutoPtr<FileChannel> fileChannel(new FileChannel);
        //指定日志路径及文件名
        fileChannel->setProperty(FileChannel::PROP_PATH, dir+file );
        //设置 rotation 策略。
        fileChannel->setProperty(FileChannel::PROP_ROTATION, rotation );
        //日志备份的后缀名加时间戳。
        fileChannel->setProperty(FileChannel::PROP_ARCHIVE, "timestamp");
        //日志备份之后会有时间后缀，默认是 utc 时间(国际标准时间), local (本地化，当地时间)
        fileChannel->setProperty(FileChannel::PROP_TIMES, "local");
        //把 备份的日志文件，进行压缩保存。
        fileChannel->setProperty(FileChannel::PROP_COMPRESS, "true");
        //不开启日志缓冲
        fileChannel->setProperty(FileChannel::PROP_FLUSH,"true");
        //删除过期的日志文件,格式为 "基数 单位" 支持的单位为 minutes, hours,days,weeks,months,
        //基数是可选的。默认为1
        fileChannel->setProperty(FileChannel::PROP_PURGEAGE, purgeAge );

        //每条日志的格式。
        Poco::AutoPtr<Poco::PatternFormatter> patternFormatter(
                                new Poco::PatternFormatter());
        patternFormatter->setProperty("pattern", "%L%Y-%m-%d %H:%M:%S (%p): %t");

        //初始化　Channel
        channel = new Poco::FormattingChannel(patternFormatter, fileChannel);
    }
    Poco::Logger::create(name,channel,Poco::Logger::parseLevel(level) );
    _pLog = &Poco::Logger::get( name );
}

void CLog::debug(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt)
{
    _pLog->debug(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue));

}

void CLog::debug(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1)
{
    _pLog->debug(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1);

}

void CLog::debug(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2)
{
    _pLog->debug(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2);

}

void CLog::debug(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3)
{
    _pLog->debug(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3);

}

void CLog::debug(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3, const Poco::Any& value4)
{
    _pLog->debug(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3, value4);

}






void CLog::information(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt)
{
    _pLog->information(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue));

}

void CLog::information(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1)
{
    _pLog->information(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1);

}

void CLog::information(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2)
{
    _pLog->information(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2);

}

void CLog::information(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3)
{
    _pLog->information(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3);

}

void CLog::information(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3, const Poco::Any& value4)
{
    _pLog->information(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3, value4);

}





void CLog::warning(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt)
{
    _pLog->warning(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue));

}

void CLog::warning(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1)
{
    _pLog->warning(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1);

}

void CLog::warning(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2)
{
    _pLog->warning(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2);

}

void CLog::warning(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3)
{
    _pLog->warning(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3);

}

void CLog::warning(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3, const Poco::Any& value4)
{
    _pLog->warning(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3, value4);

}





void CLog::error(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt)
{
    _pLog->error(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue));

}

void CLog::error(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1)
{
    _pLog->error(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1);

}

void CLog::error(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2)
{
    _pLog->error(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2);

}

void CLog::error(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3)
{
    _pLog->error(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3);

}

void CLog::error(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3, const Poco::Any& value4)
{
    _pLog->error(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3, value4);

}







void CLog::fatal(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt)
{
    _pLog->fatal(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue));

}

void CLog::fatal(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1)
{
    _pLog->fatal(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1);

}

void CLog::fatal(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2)
{
    _pLog->fatal(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2);

}

void CLog::fatal(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3)
{
    _pLog->fatal(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3);

}

void CLog::fatal(ELogType type, const std::string &className, const std::string &func, const std::string &indexName, const std::string &indexValue, const std::string &fmt,
                 const Poco::Any& value1, const Poco::Any& value2, const Poco::Any& value3, const Poco::Any& value4)
{
    _pLog->fatal(__getRealFmt(fmt), __getLogHead(type, className, func, indexName, indexValue), value1, value2, value3, value4);

}







std::string CLog::__getLogHead(ELogType type, const std::string &className, const std::string &func,
                               const std::string &indexName, const std::string &indexValue)
{
    if( nullptr == _pLog )
    {
        throw ExceptNullptr( "没有初始日志对象" );
    }
    //获取类型的字符串
    std::string stype;
    switch ( type ) {
    case ELogType::IN:			stype = "IN";	break;
    case ELogType::RECV:		stype = "RECV";	break;
    case ELogType::SEND:		stype = "SEND";	break;
    default:
        throw std::invalid_argument( "invalid type" );
    }
    //获取线程 id
    Poco::Thread::TID tid = Poco::Thread::currentTid();
    //获取日志头
    std::string head;
    if ("" != indexName)
    {
        Poco::format(head, HEAD_FMT_INDEX, stype, tid, className, func, indexName, indexValue);
    }
    else
    {
        Poco::format(head, HEAD_FMT, stype, tid, className, func);
    }

    return head;
}


} //namespace Util

} //namespace Taiji
