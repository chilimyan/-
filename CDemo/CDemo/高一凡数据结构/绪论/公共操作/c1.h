//
//  c1.h
//  DemoC
//
//  Created by Apple on 2018/8/24.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c1_h
#define c1_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc/malloc.h> //malloc()等
#include <limits.h>
#include <stdlib.h>//atoi()
#include <aio.h>//eof()
#include <math.h>//floor(),ceil(),abs()
//#include<process.h> // exit()
//#include<iostream.h> // cout,cin
//函数结构状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
typedef int Status;//Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean;//Boolean是布尔类型,其值是TRUE或FALSE


#endif /* c1_h */
