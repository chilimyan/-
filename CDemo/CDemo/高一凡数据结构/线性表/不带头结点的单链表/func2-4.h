//
//  func2-4.h
//  CDemo
//
//  Created by chilim on 2018/9/2.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef func2_4_h
#define func2_4_h

#include <stdio.h>
#include "c2-2.h"
#include "bo2-3.h"
#include "func2-3.h"
#include "bo2-2.h"

//不带头结点的单链表部分操作

void InserAscend(LinkList *L, ElemType e, int(*compare)(ElemType, ElemType));

LinkList Point(LinkList L, ElemType e, Status(*equal)(ElemType, ElemType), LinkList *p);

Status DeleteElem(LinkList *L, ElemType *e, Status(*equal)(ElemType, ElemType));

#endif /* func2_4_h */
