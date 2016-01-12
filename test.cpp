#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include <unistd.h>

#include "Exception.hpp"
#include<typeinfo>
#include <sstream>
int main( )
{
	using namespace Taiji;
//	using Taiji::MysqlConnErr;
//	using Taiji::Exception;
	try
	{
		throw MysqlConnErr("sfsf");
	} catch( Exception &e )
	{
		cout << e.what() << endl;
		cout <<e.getErrorCode() << endl;
		cout<<e.getErrInfo()<<endl;
	}

	return 1;
}
