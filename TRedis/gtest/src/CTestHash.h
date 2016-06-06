#ifndef CTESTHASH_H
#define CTESTHASH_H
#include <gtest/gtest.h>
#include "Taiji/TRedis/CRedisClient.h"
using namespace Taiji::TRedis;
class CTestHash : public testing::Test
{
public:
    CTestHash() = default;
    ~CTestHash() = default;
    static void SetUpTestCase( void );
    static void TearDownTestCase( void );
    static void GetVecTuple(VecTupleString& vecTup, const string& keyPre, uint64_t start, uint64_t end);
    static CRedisClient  redis;


};


#endif // CTESTHASH_H
