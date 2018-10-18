//
//  c2-3.h
//  静态单链表
//
//  Created by chilim on 2018/10/17.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c2_3_h
#define c2_3_h

#include <stdio.h>
#include "c1.h"

#define MAX_SIZE 100 // 链表的最大长度

//#define N 6 // 字符串长度
//typedef char ElemType[N];

typedef struct {
    ElemType data;
    int cur;
}component,SLinkList[MAX_SIZE];

#endif /* c2_3_h */
