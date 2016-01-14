/**
 * Copyright (c) 2016, 爱wifi（版权声明）
 *
 * @file	Exception.h
 * @brief 此文件的简单描述。(必填字段)
 *
 * 此文件的详细功能描述。(可选字段)
 *
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

enum class EExceptCode: int
{
	/*基本异常*/
        REDIS_EXCEPT = 10, 	///< redis异常
        MYSQL_EXCEPT = 20, 	///< 数据库异常
        SERVER_EXCEPT = 30,	///< 服务器异常
        FILE_EXCEPT = 40, 		///< 文件异常
        DATA_EXCEPT = 50, 	///< 数值异常
        REQUEST_EXCEPT = 60, ///< 请求错误

	/*自定义派生异常*/
        TYPE_CONVER_EXCEPT = 51, 	///<类型转换错误
        INVALID_ARG_EXCEPT = 52, 		///<参数错误
        EXCEED_MAX_EXCEPT = 53, 		///<超过最大值
        OVERFLOW_EXCEPT = 54, 		///<数值溢出
        OUT_Of_RANGE_EXCEPT = 55, 	///<各种数据结构的访问越界异常
        NULLPTR_EXCEPT = 56,			///< 空指针异常

        REDIS_CONN_EXCEPT = 11, 		///< redis连接异常
        MYSQL_CONN_EXCEPT = 21,		///< mysql 链接异常
        SERVER_CONN_EXCEPT = 31,	///< 服务器链接异常
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
		int tmp = (int) _errCode;
		ss << tmp;
		ss >> errCode;

		return errCode;
	}

        int getErrorCode( )
	{
                return  (int)_errCode;
	}

        const std::string getErrInfo( )
	{
                std::string errCode, errInfo;
                std::stringstream ss;
		int tmp = (int) _errCode;
		ss << tmp;
		ss >> errCode;
		errInfo = errCode + ":" + _errInfo;

		return errInfo;
	}

protected:
	std::string _errInfo;
        EExceptCode _errCode;
};

#define NEW_EXCEPTION( name,parent,code ) \
    class name : public parent \
    { \
        public: 	\
            name( const std::string& pErrInfo) \
            : parent( pErrInfo) \
            { \
        	_errCode=code;\
            }	\
            \
            ~name( ) throw()\
            { \
                \
            }\
    };

///< 空指针异常
NEW_EXCEPTION( ExceptNullptr,Exception,EExceptCode::NULLPTR_EXCEPT)
///<  redis error
NEW_EXCEPTION(ExceptRedis, Exception, EExceptCode::REDIS_EXCEPT)
///<  数据库连接不成功
NEW_EXCEPTION(ExceptMysql, Exception, EExceptCode::MYSQL_EXCEPT)
///<  服务器连接超时
NEW_EXCEPTION(ExceptServer, Exception, EExceptCode::SERVER_EXCEPT)
///<  配置文件不存在
NEW_EXCEPTION(ExceptFile, Exception, EExceptCode::FILE_EXCEPT)
///<  类型转换除错
NEW_EXCEPTION(ExceptTypeConvert, Exception, EExceptCode::TYPE_CONVER_EXCEPT)
///< 参数错误
NEW_EXCEPTION(ExceptInvalidArg, Exception, EExceptCode::INVALID_ARG_EXCEPT)
///< 超过最大值
NEW_EXCEPTION(ExceptExceedMax, Exception, EExceptCode::EXCEED_MAX_EXCEPT)
///< 各种数据结构的访问越界异常
NEW_EXCEPTION(ExceptOutOfRange, Exception, EExceptCode::OUT_Of_RANGE_EXCEPT)
///< 数值溢出
NEW_EXCEPTION(ExceptOverflow, Exception, EExceptCode::OVERFLOW_EXCEPT)

/**********测试自定义继承异常************/
///<  redis连接不成功
NEW_EXCEPTION(ExceptRedisConn, ExceptRedis, EExceptCode::REDIS_CONN_EXCEPT)
NEW_EXCEPTION(ExceptMysqlConn, ExceptMysql, EExceptCode::MYSQL_CONN_EXCEPT)
}
#endif /* CEXCEPTION_H_ */
