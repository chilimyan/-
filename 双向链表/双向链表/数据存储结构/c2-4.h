//
//  c2-4.h
//  双向链表
//
//  Created by chilim on 2018/10/21.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c2_4_h
#define c2_4_h

#include <stdio.h>
#include "c1.h"

struct DuLNode{
    ElemType data;
    struct DuLNode *prior,*next;
};

typedef struct DuLNode *DuLinkList;


#endif /* c2_4_h */
