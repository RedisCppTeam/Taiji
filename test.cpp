#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include <unistd.h>

#include "Exception.hpp"
#include<typeinfo>
#include <sstream>
#include <exception>
#include <stdexcept>

int main( )
{
	using namespace Taiji;
	try
	{
		throw ExceptMysqlConn("sfsf");
	} catch( Exception &e )
	{
		cout << e.what() << endl;
		cout << e.getErrorCode() << endl;
		cout << e.getErrInfo() << endl;
		cout << e.getErrorCodeString() << endl;
	}

	return 1;
}
