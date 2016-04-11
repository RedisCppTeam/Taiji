/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file Exception.cpp
* @brief Taiji 的基本异常类
*
*
* @author: yuhaiyang
* @date: 2016/4/11
*/

#include "Exception.h"

namespace Taiji {


//异常编号与异常名字组成的 map
ExceptInfoMap Exception::_codeMap;




Exception::Exception(const std::string &pErrInfo) :
    _errInfo(pErrInfo)
{

}

Exception::~Exception()
{

}

const char *Exception::what() noexcept
{
    return _errInfo.c_str();
}

const std::string Exception::getErrorCodeString() noexcept
{
    std::string errCode;
    std::stringstream ss;
    ss << _errCode;
    ss >> errCode;

    return errCode;
}

int Exception::getErrorCode()
{
    return _errCode;
}

const std::string Exception::getErrInfo()
{
    std::string errCode, errInfo;
    std::stringstream ss;
    ss << _errCode;
    ss >> errCode;
    errInfo = errCode + ":" + _errInfo;

    return errInfo;
}

CExceptionCheck::CExceptionCheck(int errCode, const std::string &name)
{
    auto it =
            Exception::_codeMap.insert(ExceptInfoMap::value_type(errCode,name));
    if ( !it.second )
    {
        std::cout <<"异常码重复，重复的是"<< it.first->second << "和"<<name<<std::endl;
        exit(1);
    }
}


TAIJI_NEW_EXCEPTION_CPP( 900,ExceptProtocal )


}

