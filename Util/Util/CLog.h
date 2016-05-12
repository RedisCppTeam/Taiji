/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file CLog.h
* @brief 日志类的头文件
*
* 一个写日志的类
*
* @author: yuhaiyang
* @date: 2016/1/6
*/

#ifndef CLOG_H
#define CLOG_H

#include <iostream>
#include <string>
#include <Poco/Logger.h>
#include "Exception/Except.h"


namespace Taiji
{

namespace Util {


TAIJI_NEW_EXCEPTION( ExceptLog, ExceptUtil )
TAIJI_NEW_EXCEPTION( ExceptNullptr, ExceptLog )


/**
 * @brief The ELogType enum
 *
 * 日志的类型。
 * 如果为网络发送过来的数据则为 **RECV** 开头。
 * 如果为网络发送出去的数据为 **SEND** 开头。
 * 如果为内处处理过程中的日志为 ** IN ** 开头。
 *
 *  CLog log;
 *  log.initLog( "./log/","test.log","Test","debug" );
 *  log.debug( ELogType::SEND,"main","main_f","%s  %s", string( "test1") ,string( "test2") );
 *  log.fatal( ELogType::SEND,"main","main_f","%s  %s %s", string( "error"), string("dsadsa"),string("123") );
 */
enum class ELogType
{
    RECV = 0x01,						///<通过网络接受的原始数据
    SEND,									///<通过网络发送的数据
    IN										///<内部处理中的数据
};


/**
 * @brief The CLog class
 *
 * 日志类,强制统一了日志类型。
 */
class CLog
{

public:
    //以下为字符串常量
    static const  std::string HEAD_FMT;									///< 默认的是日志头格式
    static const  std::string DEFAULT_LOG_ROTATION; 		///< 默认的日志文件更新时间
    static const  std::string DEFAULT_LOG_PURGEAGE;		///< 默认的日志文件保留时间
    static const  std::string DEFAULT_LOG_LEVEL;				///< 默认的日志输出等级

public:
    CLog( ) = default;
    ~CLog( ) = default;
    /**
     * @brief 构造一个可用日志
     * @param dir 日志文件的路径，如果日志路径不存在的话，会自动创建
     * @param file 日志文件的文件名
     * @param name 此日志对象的名字
     * @param level 日志等级 - none (turns off logging) - fatal critical	 error	 warning
     *                 notice information	 debug	 trace
     * @return None
     */
    CLog(const std::string &dir, const std::string &file, const std::string &name,
         const std::string &level=DEFAULT_LOG_LEVEL,
         const std::string &rotation=DEFAULT_LOG_ROTATION,
         const std::string& purgeAge=DEFAULT_LOG_PURGEAGE);
    CLog( CLog& ) = delete;
    CLog& operator ==( const CLog& ) = delete;

    /**
     * @brief __initLog 创建一个日志
     * @param dir 日志文件的路径，如果日志路径不存在的话，会自动创建
     * @param file 日志文件的文件名
     * @param name 此日志对象的名字
     * @param level 日志等级 - none (turns off logging) - fatal critical	 error	 warning
     *                 notice information	 debug	 trace
     * @return None
     */
    void initLog(const std::string &dir, const std::string &file, const std::string &name,
                 const std::string &level=DEFAULT_LOG_LEVEL,
                 const std::string &rotation=DEFAULT_LOG_ROTATION,
                 const std::string& purgeAge=DEFAULT_LOG_PURGEAGE );

    void debug(ELogType type, const std::string&className, const std::string& func,
                const std::string& fmt );

    void debug(ELogType type, const std::string&className, const std::string& func,
                const std::string& fmt, const Poco::Any& value1 );

    void debug( ELogType type,const std::string&className,const std::string& func,
                const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2 );

    void debug(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3 );

    void debug(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3,const Poco::Any& value4 );


    void information(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt );

    void information(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1 );

    void information( ELogType type,const std::string&className,const std::string& func,
                const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2 );

    void information(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3 );

    void information(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3, const Poco::Any& value4 );



    void warning(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt );

    void warning(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1 );

    void warning( ELogType type,const std::string&className,const std::string& func,
                const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2 );

    void warning(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3 );

    void warning(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3,const Poco::Any& value4 );



    void error(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt );

    void error(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1 );

    void error( ELogType type,const std::string&className,const std::string& func,
                const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2 );

    void error(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3 );

    void error(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3,const Poco::Any& value4 );



    void fatal(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt );

    void fatal(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1 );

    void fatal( ELogType type,const std::string&className,const std::string& func,
                const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2 );

    void fatal(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3 );

    void fatal(ELogType type, const std::string&className, const std::string& func,
               const std::string& fmt, const Poco::Any& value1, const Poco::Any& value2,
               const Poco::Any& value3,const Poco::Any& value4 );



private:
    Poco::Logger* _pLog = nullptr; 			///< 保存 Poco::Logger 对象。
    const std::string _dir;			///< 日志路径
    const std::string _file;		///< 日志路径
    const std::string _name;	///< 日志模块的名字。
    const std::string _level; 		///< 日志级别
    const std::string _rotation;///< 日志 rotation
    const std::string _purgeAge;///< 日志的删除周期

    //内部函数

    void __getLogHead(ELogType type, const std::string &className, const std::string &func,std::string& head);
    /**
     * @brief __getRealFmt  获取加上头信息之后的 fmt
     * @param fmt [in]  原 fmt
     * @param realFmt [out] 加上头信息之后的 fmt
     */
    inline void __getRealFmt( const std::string& fmt,std::string& realFmt )
    {
        //要在日志以前插入日志头
       realFmt += "%s";
       realFmt += fmt;
    }

};


}	//namespace Util

} //namespace Taiji
#endif // CLOG_H
