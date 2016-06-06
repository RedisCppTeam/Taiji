#ifndef CTESTPOOL_H
#define CTESTPOOL_H
#include <gtest/gtest.h>
#include "Taiji/TRedis/CRedisPool.h"
using namespace Taiji::TRedis;
class CTestPool : public testing::Test
{
public:
    CTestPool() = default;
    ~CTestPool() = default;
    static void SetUpTestCase( void );
    static void TearDownTestCase( void );
};


#endif // CTESTPOOL_H
