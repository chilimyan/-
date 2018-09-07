//
//  c2-2.h
//  CDemo
//
//  Created by chilim on 2018/9/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c2_2_h
#define c2_2_h

#include <stdio.h>
#include "c2-1.h"

//定义一个节点
typedef struct NODE{
    ElemType data;
    struct NODE *next;
}LNode, *LinkList;

#endif /* c2_2_h */
