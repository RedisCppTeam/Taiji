#ifndef CTESTCONNECT_H
#define CTESTCONNECT_H
#include <gtest/gtest.h>
#include "Taiji/TRedis/CRedisClient.h"
using namespace Taiji::TRedis;
class CTestConnect : public testing::Test
{
public:
    CTestConnect() = default;
    ~CTestConnect() = default;
    static void SetUpTestCase( void );
    static void TearDownTestCase( void );
};

#endif // CTESTCONNECT_H
