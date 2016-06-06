#ifndef CTESTSTRING_H
#define CTESTSTRING_H
#include <gtest/gtest.h>
#include "Taiji/TRedis/CRedisClient.h"
using namespace Taiji::TRedis;
class CTestString : public testing::Test
{
public:
    CTestString() = default;
    ~CTestString() = default;
    static void SetUpTestCase( void );
    static void TearDownTestCase( void );

    static CRedisClient redis;
};

#endif // CTESTSTRING_H
