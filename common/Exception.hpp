/**
 * Copyright (c) 2016, 爱wifi（版权声明）
 *
 * @file	Exception.h
 * @brief 此文件的简单描述。(必填字段)
 *
 * 此文件的详细功能描述。(可选字段)
 * ExceptCode枚举类:只列出几个基类，如果不够用，可根据需要可派生子类
 * Exception类:_inheritNum属性代表继承的次数，当继承次数大于3次时，则_errCode为第三次继承时的相反数
 * @author: 		cj
 * @date: 		2016年1月6日
 *
 * 修订说明:初始版本
 */
#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <sstream>
#include <map>
#include <iostream>

namespace Taiji
{

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
	int _errCode = 0;
	int _inheritNum = 0;

private:
        friend class CExceptionCheck;
	static std::map<int , std::string> _codeMap;
};

std::map<int , std::string> Exception::_codeMap;

class CExceptionCheck
{
public:
        CExceptionCheck( int errCode , const std::string &name )
	{
		std::pair<std::map<int , std::string>::const_iterator , bool> it =
				Exception::_codeMap.insert(
						std::map<int , std::string>::value_type(errCode,
								name));
		if ( !it.second )
		{
			std::cout <<"异常码重复，重复的是"<< it.first->second << "和"<<name<<std::endl;
			exit(1);
		}
	}
};

#define TAIJI_NEW_EXCEPTION_INCLUDE( name,parent,code ) \
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
        static CExceptionCheck _check;\
    };

#define TAIJI_NEW_EXCEPTION_CPP(errCode,exceptionName) CExceptionCheck exceptionName::_check(errCode,#exceptionName);


}//namespace Taiji

#endif /* CEXCEPTION_H_ */

