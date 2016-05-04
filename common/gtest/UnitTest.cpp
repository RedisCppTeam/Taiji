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

#include "Exception.h"
#include <iostream>

namespace Taiji
{
TAIJI_NEW_EXCEPTION_INCLUDE( RunTimeException, Exception, 100 )
TAIJI_NEW_EXCEPTION_CPP( RunTimeException, Exception, 100 )


//测试编号重复问题,程序会直接退出
//TAIJI_NEW_EXCEPTION_INCLUDE( DataException, Exception, 100 )
//TAIJI_NEW_EXCEPTION_CPP( DataException,Exception, 100 )

TAIJI_NEW_EXCEPTION_INCLUDE( DataException, Exception, 100 )
TAIJI_NEW_EXCEPTION_CPP( DataException,Exception, 100 )

}


int main( )
{
//	try
//	{
//		throw Taiji::RunTimeException("sdf");
//	} catch( Taiji::RunTimeException &e )
//	{
//		std::cout << e.getErrInfo() << std::endl;
//
//	}
//
//	return 0;
}

