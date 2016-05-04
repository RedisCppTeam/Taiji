/**
 *
 * @file	common.h		
 * @brief 此文件为项目公共文件。
 *
 * 此文件用于存放一些公共的同文件，宏定义，声明一些全局变量。
 * 声明一些公共函数。
 * @warning 每个全局变量一定要有注释。
 *
 * @author: 		yuhaiyang
 * @date: 		2015年4月20日
 * 修订说明:初始版本
 */
#ifndef COLLECTFAT_COMMON_H_
#define COLLECTFAT_COMMON_H_

#include <iostream>
#include "Poco/Util/ServerApplication.h"

///< 禁止拷贝构造的宏。
#define DISALLOW_COPY_AND_ASSIGN( TypeName ) 	\
					TypeName( const TypeName& ); 	\
					TypeName & operator=( const TypeName& )


///<  debug information
#define DEBUGOUT( argv, value )  	std::cout << "DEBUG INFO:" << argv << ":" << value << std::endl;

using std::string;

#endif /* COLLECTFAT_COMMON_H_ */


