
#include "Command.h"
#include "CRedisClient.h"
namespace Taiji {
namespace TRedis {




uint64_t CRedisClient::zadd(const string &key, const VecTupleString &map)
{
    Command cmd( "ZADD" );
    cmd << key;
    VecTupleString::const_iterator it = map.begin();
    VecTupleString::const_iterator end = map.end();

    for ( ; it !=end ; ++it )
    {
        cmd << std::get<0>(*it);
        cmd << std::get<1>(*it);
    }
    int64_t num;
    _getInt(cmd,num);
    return num;
}

uint64_t CRedisClient::zcard(const string& key)
{
    Command cmd( "ZCARD" );
    cmd << key;
    int64_t num;
    _getInt(cmd,num);
    return num;

}



uint64_t CRedisClient::zcount(const string& key,const string& min,const string& max)
{
    Command cmd( "ZCOUNT" );
    cmd << key << min << max;
    int64_t num;
    _getInt(cmd,num);
    return num;
}



double CRedisClient::zincrby(const string& key,double increment,const string& member)
{
    Command cmd( "ZINCRBY" );
    cmd << key << increment<< member;
    string str;
    _getString(cmd,str);
    return _valueFromString<double>( str );
}





uint64_t CRedisClient::zrange(const string &key, const int64_t start, const int64_t stop, VecString& reply)
{
    Command cmd( "ZRANGE" );
    cmd << key << start<< stop;

    uint64_t num = 0;
    _getArry(cmd,reply,num);
    return num;
}
uint64_t CRedisClient::zrangeWithscore(const string &key, const int64_t start, const int64_t stop, VecTupleString &reply)
{
    Command cmd( "ZRANGE" );
    cmd << key << start<< stop;
    cmd<<"WITHSCORES";

    uint64_t num = 0;
    _getArry( cmd,reply, num );
    return num;
}


uint64_t CRedisClient::zrangebyscore(const string &key, const string &min, const string &max, VecString &reply,int64_t offset,int64_t count)
{
    Command cmd( "ZRANGEBYSCORE" );
    cmd << key << min<< max;

    if(0!=count)
        cmd<<"LIMIT"<<offset<<count;

    uint64_t num = 0;
    _getArry( cmd,reply, num );
    return num;
}

uint64_t CRedisClient::zrangebyscoreWithscore(const string &key, const string &min, const string &max, VecTupleString &reply,int64_t offset,int64_t count)
{
    _socket.clearBuffer();
    Command cmd( "ZRANGEBYSCORE" );
    cmd << key << min<< max;
    cmd<<"WITHSCORES";

    if(0!=count)
        cmd<<"LIMIT"<<offset<<count;

    uint64_t num = 0;
    _getArry( cmd,reply, num );
    return num;
}

bool CRedisClient::zrank(const string& key,const string& member,int64_t& reply)
{
    Command cmd( "ZRANK" );
    cmd << key << member;

    return _getInt(cmd,reply);
}


uint64_t CRedisClient::zrem(const string& key,const VecString& members)

{
    Command cmd( "ZREM" );
    cmd << key;

    VecString::const_iterator it = members.begin();
    VecString::const_iterator end=members.end();
    for ( ; it !=end; ++it )
    {
        cmd << *it;
    }
    int64_t num;
    _getInt(cmd,num);
    return num;
}


uint64_t CRedisClient::zremrangebyrank(const string& key,const int64_t start,const int64_t stop)
{
    Command cmd( "ZREMRANGEBYRANK" );
    cmd << key << start << stop;
    int64_t num;
    _getInt(cmd,num);
    return num;

}



uint64_t CRedisClient::zremrangebyscore(const string& key,const string& min,const string& max)
{
    Command cmd( "ZREMRANGEBYSCORE" );
    cmd << key << min << max;
    int64_t num;
    _getInt(cmd,num);
    return num;
}

uint64_t CRedisClient::zrevrange(const string &key, const int64_t start, const int64_t stop, VecString &reply)
{
    Command cmd( "ZREVRANGE" );
    cmd << key << start<< stop;

    uint64_t num = 0;
    _getArry( cmd,reply,num );
    return num;
}

uint64_t CRedisClient::zrevrangeWithscore(const string &key, const int64_t start, const int64_t stop, VecTupleString &reply)
{
    Command cmd( "ZREVRANGE" );
    cmd << key << start<< stop;
    cmd<<"WITHSCORES";

    uint64_t num = 0;
    _getArry( cmd,reply,num );
    return num;
}





uint64_t CRedisClient::zrevrangebyscore(const string &key, const string &max, const string &min, VecString &reply, int64_t offset,int64_t count)
{
    Command cmd( "ZREVRANGEBYSCORE");
    cmd << key << max<< min;

    if(0!=count)
        cmd<<"LIMIT"<<offset<<count;

    uint64_t num = 0;
    _getArry( cmd,reply, num );
    return num;
}

uint64_t CRedisClient::zrevrangebyscoreWithscore(const string &key, const string &max, const string &min, VecTupleString &reply, int64_t offset,int64_t count)
{
    Command cmd( "ZREVRANGEBYSCORE");
    cmd << key << max<< min;
    cmd<<"WITHSCORES";

    if(0!=count)
        cmd<<"LIMIT"<<offset<<count;

    uint64_t num = 0;
    _getArry( cmd, reply, num );
    return num;
}



bool CRedisClient::zrevrank(const string& key,const string& member,int64_t& reply)
{
    Command cmd( "ZREVRANK" );
    cmd << key << member;
    return _getInt(cmd,reply);
}





bool CRedisClient::zscore(const string& key,const string& member,string& reply)
{
    Command cmd( "ZSCORE" );
    cmd << key <<  member;
    return _getString(cmd,reply);
}

void CRedisClient::addAggregate(Command& cmd,SORTEDSET_OPTION  aggregate)
{
    static const char * aggre[]={"SUM","MIN","MAX"};
    cmd <<"AGGREGATE";
    cmd<<aggre[aggregate];
}



uint64_t CRedisClient::zunionstore (const string& destination,const VecString& keys,const VecString& weigets,SORTEDSET_OPTION  aggregate)
{

    uint64_t keysNum=keys.size();
    if (keysNum==0)
        return 0;
    Command cmd( "ZUNIONSTORE" );
    cmd << destination <<  keysNum;

    VecString::const_iterator it = keys.begin();
    VecString::const_iterator end = keys.end();
    for ( ; it !=end; ++it )
    {
        cmd << *it;
    }

    cmd <<"WEIGHTS";
    VecString::const_iterator it2 = weigets.begin();
    VecString::const_iterator end2 = weigets.end();
    for ( ; it2 !=end2; ++it2 )
    {
        cmd << *it2;
    }
    addAggregate(cmd,aggregate);
    int64_t num;
    _getInt(cmd,num);
    return num;

}


uint64_t CRedisClient::zunionstore (const string& destination,const VecString& keys,SORTEDSET_OPTION  aggregate)
{
    uint64_t keysNum=keys.size();
    if (keysNum==0)
        return 0;
    Command cmd( "ZUNIONSTORE" );
    cmd << destination <<  keysNum;

    VecString::const_iterator it = keys.begin();
    VecString::const_iterator end = keys.end();
    for ( ; it !=end; ++it )
    {
        cmd << *it;
    }
    addAggregate(cmd,aggregate);
    int64_t num;
    _getInt(cmd,num);
    return num;

}

//.................................................................................................................

uint64_t CRedisClient::zinterstore (const string& destination,const VecString& keys,const VecString& weigets,SORTEDSET_OPTION aggregate)
{
    uint64_t keysNum=keys.size();
    if (keysNum==0)
        return 0;
    Command cmd( "ZINTERSTORE" );
    cmd << destination <<  keysNum;

    VecString::const_iterator it = keys.begin();
    VecString::const_iterator end = keys.end();
    for ( ; it !=end; ++it )
    {
        cmd << *it;
    }

    cmd <<"WEIGHTS";
    VecString::const_iterator it2 = weigets.begin();
    VecString::const_iterator end2 = weigets.end();
    for ( ; it2 !=end2; ++it2 )
    {
        cmd << *it2;
    }

    addAggregate(cmd,aggregate);
    int64_t num;
    _getInt(cmd,num);
    return num;

}


uint64_t CRedisClient::zinterstore (const string& destination,const VecString& keys,SORTEDSET_OPTION aggregate)
{
    uint64_t keysNum=keys.size();
    if (keysNum==0)
        return 0;
    Command cmd( "ZINTERSTORE" );
    cmd << destination <<  keysNum;

    VecString::const_iterator it = keys.begin();
    VecString::const_iterator end = keys.end();
    for ( ; it !=end; ++it )
    {
        cmd << *it;
    }
    addAggregate(cmd,aggregate);
    int64_t num;
    _getInt(cmd,num);
    return num;


}
bool CRedisClient::zscan(const string &key, int64_t &cursor, VecTupleString &reply, const string &match, uint64_t count )
{
    CResult result;
    Command cmd( "ZSCAN" );
    cmd << key << cursor;

    if ( "" != match )
    {
        cmd << "MATCH" << match;
    }

    if ( 0 != count )
    {
        cmd << "COUNT" << count;
    }
    _getArry( cmd, result );
    CResult::ListCResult::const_iterator it = result.getArry().begin();
    cursor = _valueFromString<uint64_t>( it->getString() );
    ++ it;
    _getStringTupleFromArry( it->getArry(), reply );
    return ( cursor == 0 ? false : true );
}

uint64_t CRedisClient::zrangebylex(const string &key, const string &min, const string &max, VecString &reply, int64_t offset,int64_t count)
{
    Command cmd( "ZRANGEBYLEX" );
    cmd << key << min<< max;
    if (count>0)
        cmd<<"LIMIT"<<offset<<count;

    uint64_t num = 0;
    _getArry( cmd, reply, num );
    return num;
}

uint64_t CRedisClient::zlexcount(const string &key, const string &min, const string &max)
{
    Command cmd( "ZLEXCOUNT" );
    cmd << key << min << max;
    int64_t num;
    _getInt(cmd,num);
    return num;

}

uint64_t CRedisClient::zremrangebylex(const string &key, const string &min, const string &max)
{
    Command cmd( "ZREMRANGEBYLEX" );
    cmd << key << min << max;
    int64_t num;
    _getInt(cmd,num);
    return num;
}



}
}
