//
//  bo2-3.h
//  CDemo
//
//  Created by chilim on 2018/9/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_3_h
#define bo2_3_h

#include <stdio.h>
#include "c2-2.h"
#include "func2-3.h"

//不带头结点的单链表
void InitList2(LinkList *L);

void ClearList2(LinkList *L);

Status ListEmpty2(LinkList L);

int ListLength2(LinkList L);

Status GetElem2(LinkList L, int i, ElemType *e);

int LocateElem2(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));

Status ListInsert2(LinkList *L, int i, ElemType e);

Status ListDelete2(LinkList *L, int i, ElemType *e);

void ListTraverse2(LinkList L, void(*vi)(ElemType));

Status PriorElem2(LinkList L, ElemType cur_e, ElemType *pre_e);

Status NextElem2(LinkList L, ElemType cur_e, ElemType *next_e);

#endif /* bo2_3_h */
