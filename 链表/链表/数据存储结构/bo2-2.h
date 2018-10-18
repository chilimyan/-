//
//  bo2-2.h
//  链表
//
//  Created by chilim on 2018/10/13.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_2_h
#define bo2_2_h

#include <stdio.h>
#include "c2-2.h"

//===========带有头结点的单链表==============//
//构造一个空的线性表L
LinkList InitList();

//销毁线性表L
void DestroyList(LinkList *L);

//将L重置为空表
void ClearList(LinkList L);

//若L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(LinkList L);

//返回L中数据元素的个数
int ListLength(LinkList L);

// L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
Status GetElem(LinkList L,int i,ElemType *e);

// 返回L中第1个与e满足关系compare()的数据元素的位序。
// 若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
// 返回OK;否则操作失败，pre_e无定义，返回INFEASIBLE
Status PriorElem(LinkList L,ElemType cur_e, ElemType *pre_e);

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
// 返回OK;否则操作失败，next_e无定义，返回INFEASIBLE
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e);

// 在带头结点的单链线性表L中第i个位置之前插入元素e
Status ListInsert(LinkList L,int i,ElemType e);

//在带头结点的单链线性表L中，删除第i个元素，并由e返回其
Status ListDelete(LinkList L,int i,ElemType *e);

//依次对L的每个数据元素调用函数vi()
void ListTraverse(LinkList L,void(*vi)(ElemType));

#endif /* bo2_2_h */
