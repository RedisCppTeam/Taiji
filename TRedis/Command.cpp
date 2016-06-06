/**
 * @file	Command.cpp
 * @brief 生成 redis 指令的代码。
 *
 * @author: 		yuhaiyang
 * @date: 		2015年5月6日
 *
 */
#include "Command.h"
namespace Taiji {
namespace TRedis {



const char* Command::_CRLF = "\r\n";	///< 一行的结束标志



string Command::getCommand()
{
    return ( *_param.begin() );
}



}
}
