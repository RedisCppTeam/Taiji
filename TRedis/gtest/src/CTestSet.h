#ifndef CTESTSET_H
#define CTESTSET_H
#include <gtest/gtest.h>
#include "Taiji/TRedis/CRedisClient.h"
using namespace Taiji::TRedis;
class CTestSet : public testing::Test
{
public:
    CTestSet() = default;
    ~CTestSet() = default;
    static void SetUpTestCase( void );
    static void TearDownTestCase( void );

    static CRedisClient redis;
};



#endif // CTESTSET_H
