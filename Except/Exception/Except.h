/**
 * Copyright (c) 2016, 爱wifi（版权声明）
 *
 * @file	Except.h
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

#include <exception>
#include <string>

namespace Taiji
{



class Except: public std::exception
{
public:
    Except( const std::string &errInfo );

    ~Except( ) noexcept;

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
TAIJI_NEW_EXCEPTION( ExceptProtocal ,Except );






}//namespace Taiji

#endif /* CEXCEPTION_H_ */

