/**
 * Copyright (c) 2016, 爱wifi（版权声明）
 *
 * @file	main.cpp
 * @brief 此文件的简单描述。(必填字段)
 *
 * 此文件的详细功能描述。(可选字段)
 *
 * @author: 		cj
 * @date: 		2016年3月29日
 *
 * 修订说明:初始版本
 */

#include "Exception/Exception.h"
#include <iostream>
#include <gtest/gtest.h>


namespace Taiji
{
TAIJI_NEW_EXCEPTION_INCLUDE( RunTimeException, Exception, 100 )
TAIJI_NEW_EXCEPTION_CPP( RunTimeException, Exception, 100 )


//测试编号重复问题,程序会直接退出
//TAIJI_NEW_EXCEPTION_INCLUDE( DataException, Exception, 100 )
//TAIJI_NEW_EXCEPTION_CPP( DataException,Exception, 100 )

TAIJI_NEW_EXCEPTION_INCLUDE( DataException, Exception, 200 )
TAIJI_NEW_EXCEPTION_CPP( DataException,Exception, 200 )

}

using namespace Taiji;

class CExceptUnitTest : public testing::Test
{
public:
    CExceptUnitTest() = default;
    ~CExceptUnitTest() = default;

    static void SetUpTestCase( void )
    {
        std::cout << "开始异常测试" << std::endl;
    }



    static void TearDownTestCase( void )
    {
        std::cout << "结束异常测试" << std::endl;
    }

};


TEST_F( CExceptUnitTest, Except_Ok )
{
    ASSERT_THROW( throw ExceptProtocal( "testing protocal exception" ), ExceptProtocal );
}









