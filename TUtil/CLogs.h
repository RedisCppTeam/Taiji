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

#ifndef CLOGS_H
#define CLOGS_H

#include <string>
#include <map>
#include <memory>
#include "Taiji/TUtil/CLog.h"



namespace Taiji {

namespace TUtil {


TAIJI_NEW_EXCEPTION( ExceptNotFindLog, ExceptLog )


/**
 * @brief The CLogs class
 *
 * 单实例类用于全局的使用日志．
 */
class CLogs
{
public:
    CLogs( const CLogs& other ) = delete;
    CLogs& operator=( const CLogs& other ) = delete;


    ~CLogs() = default;


     /**
     * @brief instance
     * @return 返回全局单实例对象的引用
     */
    static CLogs& instance();



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



private:
    CLogs() = default;

private:
    std::map<std::string,std::shared_ptr<CLog>> _logMap;

};



}  //namespace Util

}  //namespace Taiji


#endif // CLOGS_H
