/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @file	   CParams.h
 * @brief      参数检验
 * @author:    zhangxinhao
 * @date: 	   2016-03-29
 * Revision Description: initial version
 */
#ifndef CPARAMS_H
#define CPARAMS_H
#include "Exception/Except.h"
#include <iostream>
#include <string>


namespace Taiji {
namespace Util {




TAIJI_NEW_EXCEPTION(ExceptInvalidArg, ExceptProtocal)

using std::string;

class CParams
{
public:
    static void checkCapMac(const string &mac);
    static void checkIP(const string &ip);
    static string getCapMac(const string &mac);

    static string getNowTime();
    static string getAfterTime(int seconds);
};




}
}
#endif // CPARAMS_H
