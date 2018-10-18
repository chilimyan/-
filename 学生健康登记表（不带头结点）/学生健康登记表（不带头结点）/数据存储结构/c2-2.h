//
//  c2-2.h
//  链表
//
//  Created by chilim on 2018/10/13.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c2_2_h
#define c2_2_h

#include <stdio.h>
#include "c1.h"

struct LNode{
    ElemType data;
    struct LNode *next;
};

typedef struct LNode *LinkList;

#endif /* c2_2_h */
