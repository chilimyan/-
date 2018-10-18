//
//  c2-1.h
//  线性表
//
//  Created by chilim on 2018/10/11.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c2_1_h
#define c2_1_h

#include <stdio.h>
#include "c1.h"

#define LIST_INIT_SIZE 10 // 线性表存储空间的初始分配量
#define LIST_INCREMENT 2 // 线性表存储空间的分配增量

struct SqList
{
    ElemType *elem; // 存储空间基址
    int length; // 当前长度
    int listsize; // 当前分配的存储容量(以sizeof(ElemType)为单位)
};

typedef struct SqList *PSqlist;

#endif /* c2_1_h */
