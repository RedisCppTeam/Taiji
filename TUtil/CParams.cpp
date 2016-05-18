/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @file	   CParams.cpp
 * @brief      参数检验
 * @author:    zhangxinhao
 * @date: 	   2016-03-29
 * Revision Description: initial version
 */
#include "CParams.h"
#include <chrono>
namespace Taiji {
namespace TUtil {

void CParams::checkCapMac(const std::string &mac)
{
    if (mac.size() != 12)
    {
        throw ExceptInvalidArg("Invalid mac address");
    }
    for (const auto &ch : mac)
    {
        if (('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'F'))
            continue;
        throw ExceptInvalidArg("Invalid mac address");
    }
}

void CParams::checkIP(const std::string &ip)
{
    uint ipSize = ip.size();
    if (ipSize > 15)
    {
        throw ExceptInvalidArg("Invalid ip address");
    }
    bool preIsDot = true;
    uint num = 0;
    uint DotNum = 0;
    for (uint i = 0; i < ipSize; i++)
    {
        if (preIsDot)
        {
            if (!('0' <= ip[i] && ip[i] <= '9'))
            {
                throw ExceptInvalidArg("Invalid ip address");
            }
            num = ip[i] - '0';
            preIsDot = false;
        }
        else if ('0' <= ip[i] && ip[i] <= '9')
        {
            if (0 == num)
            {
                throw ExceptInvalidArg("Invalid ip address");
            }
            num = num * 10 + ip[i] - '0';
            if (num > 255)
            {
                throw ExceptInvalidArg("Invalid ip address");
            }
        }
        else if ('.' == ip[i])
        {
            num = 0;
            preIsDot = true;
            DotNum++;
        }
        else
        {
            throw ExceptInvalidArg("Invalid ip address");
        }
    }
    if (3 != DotNum)
    {
        throw ExceptInvalidArg("Invalid ip address");
    }
}


std::string CParams::getCapMac(const std::string &mac)
{
    string capMac = mac;
    uint i = 0;
    while (i < capMac.size())
    {
        if (capMac[i] >= 'a' && capMac[i] <= 'f')
        {
            capMac[i] = capMac[i] - 32;
        }
        else if (!((capMac[i] >= '0' && capMac[i] <= '9') ||
                   (capMac[i] >= 'A' && capMac[i] <= 'F')))
        {
            capMac.erase(i, 1);
            continue;
        }
        i++;
    }
    return capMac;
}

std::string CParams::getNowTime()
{
    auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm* ptm = localtime(&tt);
    char date[60] = {0};
    sprintf(date, "%d-%02d-%02d %02d:%02d:%02d",
            (int)ptm->tm_year + 1900,(int)ptm->tm_mon + 1,(int)ptm->tm_mday,
            (int)ptm->tm_hour,(int)ptm->tm_min,(int)ptm->tm_sec);
    return string(date);
}

std::string CParams::getAfterTime(int seconds)
{
    int t = (int)std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::time_t tt = (std::time_t) (t + seconds);
    struct tm* ptm = localtime(&tt);
    char date[60] = {0};
    sprintf(date, "%d-%02d-%02d %02d:%02d:%02d",
            (int)ptm->tm_year + 1900,(int)ptm->tm_mon + 1,(int)ptm->tm_mday,
            (int)ptm->tm_hour,(int)ptm->tm_min,(int)ptm->tm_sec);
    return string(date);
}



}
}
