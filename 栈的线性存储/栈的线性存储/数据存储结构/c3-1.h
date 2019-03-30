//
//  c3-1.h
//  栈的线性存储
//
//  Created by chilim on 2018/10/25.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c3_1_h
#define c3_1_h

#include <stdio.h>
#include "c1.h"

#define STACK_INIT_SIZE 10//存储空间初始分配量
#define STACK_INCREMENT 2//存储空间分配增量

typedef struct{
    SElemType *base;// 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top;// 栈顶指针
    int stacksize;
}SqStack;

typedef struct SqStack *PSqStack;

#endif /* c3_1_h */
