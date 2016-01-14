#include <iostream>
#include "CUtil.h"
#include "CLog.h"
#include <Poco/Exception.h>
#include <thread>
#include "common.h"

using Poco::Data::Keywords::now;
using Poco::Data::Keywords::into;


using namespace std;
using namespace Taiji;

void TestMysql()
{
    CUtil::instance().initMysql( "127.0.0.1", 3306, "root","123","awifi_device_bus", 10, 100 );

    Poco::Data::Session session = CUtil::instance().getMysql();
    //1.取出所有支持的任务名
    typedef Poco::Tuple<int , string , string> taskListType;
    std::vector<taskListType> taskList;

    Poco::Data::Statement select( session );
    string sql = "select taskID,taskName,detailTable from awifi_nas_taskList where enable =1";
    DEBUGOUT(sql, "sql")
    select << sql, into(taskList), now;
    string taskName;
    string taskdetailTable;
    const int count = taskList.size();
    DEBUGOUT("数据库读取，可支持的任务个数为", count)
                    for (int  taskCnt = 0; taskCnt < count ; taskCnt++ )
    {
        taskName = taskList[taskCnt].get<1>();
        taskdetailTable = taskList[taskCnt].get<2>();
        DEBUGOUT("taskName", taskName);
        DEBUGOUT("tablename", taskdetailTable);
    }
}

void TestLog( void )
{
    CUtil::instance().initLog("./log/","test.log","Test","debug" );
    CLog& pLog = CUtil::instance().getLog();
    pLog.debug( ELogType::SEND,"main","main_f","%s  %s", string( "test1") ,string( "test2") );
    pLog.fatal( ELogType::SEND,"main","main_f","%s  %s %s", string( "error"), string("dsadsa"),string("123") );
}

void TestRedis( void )
{
    CUtil::instance().initRedis( "127.0.0.1",6379, 100 );
    int place;
    CRedisClient* redis = CUtil::instance().getRedis( place, 1000 );
    CRedisClient::VecString vals;
    redis->keys( "*", vals );

    for ( auto &it : vals )
    {
        std::cout << it << std::endl;
    }
    CUtil::instance().putBackRedis( place );
}


int main()
{
    TestLog();
    TestMysql();
    TestRedis();
    return 0;
}

