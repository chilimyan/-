//
//  bo2-2.h
//  CDemo
//
//  Created by chilim on 2018/9/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_2_h
#define bo2_2_h

#include <stdio.h>
#include "c2-2.h"
#include "func2-3.h"
//带头结点的单链表,头结点不存储数据
void InitList1(LinkList *L);

void DestroyList1(LinkList *L);

void ClearList1(LinkList L);

Status ListEmpty1(LinkList L);

int ListLength1(LinkList L);

Status GetElem1(LinkList L, int i, ElemType *e);

int LocateElem1(LinkList L, ElemType e, Status(*compare)(ElemType,ElemType));

Status PriorElem1(LinkList L,ElemType cur_e,ElemType *pre_e);

Status NextElem1(LinkList L, ElemType cur_e, ElemType *next_e);

Status ListInsert1(LinkList L, int i, ElemType e);

Status ListDelete1(LinkList L, int i, ElemType *e);

void ListTraverse1(LinkList L, void(*vi)(ElemType));

#endif /* bo2_2_h */
