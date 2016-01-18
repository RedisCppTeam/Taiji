/**
 * Copyright (c) 2016, 爱wifi（版权声明）
 *
 * @file	Exception.h
 * @brief 此文件的简单描述。(必填字段)
 *
 * 此文件的详细功能描述。(可选字段)
 * ExceptCode枚举类:只列出几个基类，如果不够用，可根据需要可派生子类
 * Exception类:_inheritNum属性代表继承的次数，当继承次数大于2次时，则_errCode为第二次继承时的相反数
 * @author: 		cj
 * @date: 		2016年1月6日
 *
 * 修订说明:初始版本
 */
#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <sstream>

namespace Taiji
{

enum class ExceptCode: int
{
	/*没有异常编号*/
	NO_EXCEPT_CODE = 0,	///< 没有异常编号
	/*基本异常*/
	REDIS_EXCEPT = 100, 	///< redis异常
	MYSQL_EXCEPT = 200, 	///< 数据库异常
	FILE_EXCEPT = 300, 		///< 文件异常
	RUNTIME_EXCEPT = 400, ///< 运行时异常
	SERVER_EXCEPT = 500, ///< 服务器异常
};

class Exception: public std::exception
{

public:
	Exception( const std::string &pErrInfo ) :
			_errInfo(pErrInfo)
	{

	}

	~Exception( ) noexcept
	{

	}

	virtual const char* what( ) noexcept
	{
		return _errInfo.c_str();
	}

	const std::string getErrorCodeString( ) noexcept
	{
		std::string errCode;
		std::stringstream ss;
		ss << _errCode;
		ss >> errCode;

		return errCode;
	}

	int getErrorCode( )
	{
		return _errCode;
	}

	const std::string getErrInfo( )
	{
		std::string errCode, errInfo;
		std::stringstream ss;
		ss << _errCode;
		ss >> errCode;
		errInfo = errCode + ":" + _errInfo;

		return errInfo;
	}

protected:
	std::string _errInfo;
	int _errCode;
	int _inheritNum;
};

#define TAIJI_NEW_EXCEPTION( name,parent,code ) \
    class name : public parent \
    { \
        public: 	\
            name( const std::string& pErrInfo) \
            : parent( pErrInfo) \
            { \
        	_inheritNum++;\
        	if(_inheritNum>3){ \
        		if(_errCode>0) {\
        			_errCode=-_errCode; \
			} \
		}else{ \
			_errCode=(int)code+parent::_errCode;\
		} \
            }	\
            \
            ~name( ) throw()\
            { \
                \
            }\
    };

/******************基类异常*********************/
///<  redis异常
TAIJI_NEW_EXCEPTION(ExceptRedis, Exception, ExceptCode::REDIS_EXCEPT)
///<  数据库异常
TAIJI_NEW_EXCEPTION(ExceptMysql, Exception, ExceptCode::MYSQL_EXCEPT)
///<  文件异常
TAIJI_NEW_EXCEPTION(ExceptFile, Exception, ExceptCode::FILE_EXCEPT)
///<  运行时异常
TAIJI_NEW_EXCEPTION(ExceptRuntime, Exception, ExceptCode::RUNTIME_EXCEPT)
///<  服务器异常
TAIJI_NEW_EXCEPTION(ExceptServer, Exception, ExceptCode::SERVER_EXCEPT)

/********** redis 派生类异常************/
///<  redis连接不成功
TAIJI_NEW_EXCEPTION(ExceptRedisConn, ExceptRedis, 10)

/*********** mysql 的派生类异常 ********************/
///<  mysql连接不成功
TAIJI_NEW_EXCEPTION(ExceptMysqlConn, ExceptMysql, 10)

/*********** 文件的派生类异常 ********************/
///<  文件创建异常
TAIJI_NEW_EXCEPTION(ExceptCreateFile, ExceptFile, 10)
///<  文件打开异常
TAIJI_NEW_EXCEPTION(ExceptOpenFile, ExceptFile, 20)
///<  文件写异常
TAIJI_NEW_EXCEPTION(ExceptWriteFile, ExceptFile, 30)
///<  文件读异常
TAIJI_NEW_EXCEPTION(ExceptReadFile, ExceptFile, 40)

/******************运行时派生类异常*******************/
///<  数据异常
TAIJI_NEW_EXCEPTION(ExceptData, ExceptRuntime, 10)
///< 内存不足
TAIJI_NEW_EXCEPTION(ExceptOutOfMemory, ExceptRuntime, 20)

/******************服务器派生类异常*******************/
///<  服务器链接异常
TAIJI_NEW_EXCEPTION(ExceptServerConn, ExceptServer, 10)

/******************数据的派生类异常(第三层)*******************/
///<  类型转换除错
TAIJI_NEW_EXCEPTION(ExceptTypeConvert, ExceptData, 1)
///< 参数错误
TAIJI_NEW_EXCEPTION(ExceptInvalidArg, ExceptData, 2)
///< 超过最大值
TAIJI_NEW_EXCEPTION(ExceptExceedMax, ExceptData, 3)
///< 各种数据结构的访问越界异常
TAIJI_NEW_EXCEPTION(ExceptOutOfRange, ExceptData, 4)
///< 数值溢出
TAIJI_NEW_EXCEPTION(ExceptOverflow, ExceptData, 5)
///< 空指针异常
TAIJI_NEW_EXCEPTION(ExceptNullptr, ExceptData, 6)



} //namespace Taiji

#endif /* CEXCEPTION_H_ */
