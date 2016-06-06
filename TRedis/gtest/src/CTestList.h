#ifndef CTESTLIST_H
#define CTESTLIST_H
#include <gtest/gtest.h>
#include "Taiji/TRedis/CRedisClient.h"
using namespace Taiji::TRedis;
class CTestList : public testing::Test
{
public:
    CTestList() = default;
    ~CTestList() = default;
    static void SetUpTestCase( void );
    static void TearDownTestCase( void );

    static CRedisClient redis;
};

#endif // CTESTLIST_H
