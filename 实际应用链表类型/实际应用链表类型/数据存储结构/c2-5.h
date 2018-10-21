//
//  c2-5.h
//  实际应用链表类型
//
//  Created by chilim on 2018/10/21.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef c2_5_h
#define c2_5_h

#include <stdio.h>
#include "c1.h"

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}*Link,*Position;

typedef struct LinkList{
    Link head,tail;// 分别指向线性链表中的头结点和最后一个结点
    int len;// 指示线性链表中数据元素的个数
}*PLinkList;

#endif /* c2_5_h */
