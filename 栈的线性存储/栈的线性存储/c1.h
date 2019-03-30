//
//  c1.h
//  绪论
//
//  Created by chilim on 2018/10/9.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c1_h
#define c1_h

#include <stdio.h>//标准输入输出
#include <string.h>//关于字符数组的函数定义，常用函数有strlen、strcmp、strcpy等等
#include <ctype.h>//字符测试函数,检查是否数字，大小写等
#include <malloc/malloc.h>//动态内存分配
#include <limits.h>//检测整型数据数据类型的表达值范围
#include <stdlib.h>//定义了五种类型、一些宏和通用工具函数
#include <aio.h>//
#include <math.h>//数学运算
//#include <process.h>//
//#include <iostream.h>

//函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean;// Boolean是布尔类型,其值是TRUE或FALSE

#define NAMELEN 8  // 姓名最大长度
#define CLASSLEN 8 // 班级名最大长度

typedef int SElemType;
//typedef struct {
//    float coef;//系数
//    int expn;//指数
//}term,ElemType;// 两个类型名:term用于本ADT，ElemType为LinkList的数据对象名




#endif /* c1_h */
