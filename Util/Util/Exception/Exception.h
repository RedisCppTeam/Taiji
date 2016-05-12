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
    Exception( const std::string &errInfo );

    ~Exception( ) noexcept;

    virtual const char* what( ) const noexcept;

private:
	std::string _errInfo;
};




#define TAIJI_NEW_EXCEPTION( name,parent ) \
    class name : public parent \
    { \
        public: 	\
            name( const std::string& pErrInfo) \
            : parent( pErrInfo) \
            { \
            } \
            \
            ~name( ) noexcept\
            { \
                \
            }\
    }


////////////////////////////////////基本模块异常///////////////////////////////////
//添加基类异常的时候注意不要重复编号
//
/////////////////////////////////////////////////////////////////////////////////
TAIJI_NEW_EXCEPTION( ExceptProtocal ,Exception );






}//namespace Taiji

#endif /* CEXCEPTION_H_ */

