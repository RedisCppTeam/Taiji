#include "CRedisSocket.h"
#include "ExceptRedis.h"
namespace Taiji {
namespace TRedis {





CRedisSocket::CRedisSocket():
    _pBuffer(0),
    _pNext(0),
    _pEnd(0)
{
    _allocBuffer();
}

CRedisSocket::CRedisSocket(const Poco::Net::SocketAddress &address ):
    StreamSocket(address),
    _pBuffer(0),
    _pNext(0),
    _pEnd(0)
{
    _allocBuffer();
}



CRedisSocket::~CRedisSocket()
{
    delete [] _pBuffer;
}

int CRedisSocket::get()
{
    _refill();
    if (_pNext != _pEnd)
        return std::char_traits<char>::to_int_type(*_pNext++);
    else
        return EOF_CHAR;
}

int CRedisSocket::peek()
{
    _refill();
    if (_pNext != _pEnd)
        return std::char_traits<char>::to_int_type(*_pNext);
    else
        return EOF_CHAR;
}

bool CRedisSocket::readLine( string& line )
{
    line.clear();
    int ch = get();
    //----修复读取一行的内容中只包含'\r'或'\n'的情况----by FanYongTao ,needs review
    while(1)
    {
        if( ch == EOF_CHAR )
        {
            return false;
        }else if( ch == '\r' && peek() == '\n')
        {
            get();
            return true;
        }else
        {
            line += ch;
            ch = get();
        }
    }
}

void CRedisSocket::readN(const uint64_t n, string& data )
{
    uint64_t readed = 0;
    char ch = 0;
    data.clear();

    for ( readed=0; readed != n; ++readed )
    {
        ch = get();
        if ( ch == EOF_CHAR )
        {
            break;
        }
        data += ch;
    }
}

void CRedisSocket::clearBuffer( void )
{
    _pNext = _pBuffer;
    _pEnd = _pBuffer;
    _flushSocketRecvBuff();
}

//----------------------------------------------protected----------------------------------------------------
void CRedisSocket::_allocBuffer()
{
    _pBuffer = new char [RECEIVE_BUFFER_SIZE];
    _pNext   = _pBuffer;
    _pEnd    = _pBuffer;
}

void CRedisSocket::_refill()
{
    if (_pNext == _pEnd)
    {
        int n = receiveBytes(_pBuffer, RECEIVE_BUFFER_SIZE);
        if ( n <=0 )
        {
            throw ExceptConnect( "socket is disconnect!" );
        }
        if (n > 0)
        {
            _pNext = _pBuffer;
            _pEnd  = _pBuffer + n;
        }
    }
}

void CRedisSocket::_flushSocketRecvBuff()
{
    Poco::Net::Socket::SocketList readList = {*(static_cast<Poco::Net::Socket *>(this))};
    Poco::Net::Socket::SocketList writeList;
    Poco::Net::Socket::SocketList exceptList;
    Poco::Timespan timeout(0, 0);
    char tmp[256];
    while((Poco::Net::Socket::select(readList, writeList, exceptList, timeout) > 0)
          && (this->receiveBytes(tmp, 256) > 0));

}





}
}
