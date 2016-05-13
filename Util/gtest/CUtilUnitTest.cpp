/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file xxxxxxx
* @brief 文件的简单介绍
*
* 文件的详细介绍
*
* @author: yuhaiyang
* @date: 2016/5/13
*/

#include "CUtilUnitTest.h"
#include "../Util/CLogs.h"
#include "Util/CUtil.h"

using namespace Taiji::Util;
using Poco::Data::Keywords::now;
using Poco::Data::Keywords::into;


void CUtilUnitTest::SetUpTestCase()
{

}

void CUtilUnitTest::TearDownTestCase()
{

}




TEST_F( CUtilUnitTest, Logs_test )
{
    CLogs::instance().createLog( "./log/","test.log","TEST_LOG" );
    CLogs::instance().createLog( "./log/","test2.log","TEST_LOG2" );


    CLog& log1 = CLogs::instance().getLog( "TEST_LOG" );
    log1.information( ELogType::IN, typeid(*this).name(),__func__,"This is %s\n", std::string("test") );

    CLog& log2 = CLogs::instance().getLog( "TEST_LOG2" );
    log2.information( ELogType::IN, typeid(*this).name(),__func__,"This is %s\n", std::string("test") );
}


TEST_F( CUtilUnitTest, Mysql_test )
{
    CUtil::instance().initMysql( "127.0.0.1", 3306, "root", "123","mysql", 10, 20 );
    Poco::Data::Session session = CUtil::instance().getMysql();

    std::vector<string> tables;

    session << "SHOW TABLES ", into(tables), now;

    for ( const auto& it : tables )
    {
        std::cout << it << std::endl;
    }
    ASSERT_GT( tables.size(), 1 );
}

TEST_F( CUtilUnitTest, Redis_test )
{
    CUtil::instance().initRedis( "127.0.0.1",6379, 100 );
    std::shared_ptr<CRedisClient> predis  = CUtil::instance().getRedis( 1000 );
    predis->set( "unitTest","unitTest" );

    std::string val;
    predis->get( "unitTest", val );

    ASSERT_EQ( "unitTest", val );
}


TEST_F( CUtilUnitTest, CUtil_Log )
{
    CUtil::instance().createLog( "./log/","unitTest.log","UNIT_TEST_LOG" );
    CLog& log = CUtil::instance().getLog( "UNIT_TEST_LOG" );
    log.information( ELogType::IN, typeid(*this).name(),__func__,"This is %s\n", std::string("test") );
}



