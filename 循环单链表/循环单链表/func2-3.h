//
//  func2-3.h
//  线性表
//
//  Created by chilim on 2018/10/11.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef func2_3_h
#define func2_3_h

#include <stdio.h>
#include "c1.h"

// 判断是否相等的函数
Status equal(ElemType c1, ElemType c2);

// 根据a<、=或>b，分别返回-1、0或1
int comp(ElemType a, ElemType b);

void print(ElemType c);

void print2(ElemType c);

void print1(ElemType *c);

#endif /* func2_3_h */
