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






Exception::Exception(const std::string &errInfo) :
    _errInfo(errInfo)
{

}

Exception::~Exception()
{

}

const char *Exception::what() const noexcept
{
    return _errInfo.c_str();
}






}

