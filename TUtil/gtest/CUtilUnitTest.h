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

#ifndef CUTILUNITTEST_H
#define CUTILUNITTEST_H


#include <gtest/gtest.h>


class CUtilUnitTest : public testing::Test
{
public:
    CUtilUnitTest() = default;
    ~CUtilUnitTest() = default;


    static void SetUpTestCase( void );
    static void TearDownTestCase( void );

};

#endif // CUTILUNITTEST_H
