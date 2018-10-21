//
//  bo2-5.h
//  双向链表
//
//  Created by chilim on 2018/10/21.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_5_h
#define bo2_5_h

#include <stdio.h>
#include "c2-4.h"

//带头结点的双向循环链表

// 产生空的双向循环链表L
void InitList(DuLinkList *L);

//销毁双向循环链表L
void DestroyList(DuLinkList *L);

//将L重置为空表
void ClearList(DuLinkList L);

//若L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(DuLinkList L);

//返回L中数据元素个数
int ListLength(DuLinkList L);

// 当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
Status GetElem(DuLinkList L,int i,ElemType *e);

//返回L中第1个与e满足关系compare()的数据元素的位序。
//若这样的数据元素不存在，则返回值为0
int LocateElem(DuLinkList L,ElemType e,Status(*compare)(ElemType,ElemType));

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;
Status PriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e);

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
Status NextElem(DuLinkList L,ElemType cur_e,ElemType *next_e);

// 在双向链表L中返回第i个元素的地址。i为0，返回头结点的地址。若第i个元素不存在返回NULL
DuLinkList GetElemP(DuLinkList L,int i);

// 删除带头结点的双链循环线性表L的第i个元素，i的合法值为1≤i≤表长
Status ListDelete(DuLinkList L,int i,ElemType *e);

// 由双链循环线性表L的头结点出发，逆序对每个数据元素调用函数visit()
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType));

// 由双链循环线性表L的头结点出发，正序对每个数据元素调用函数visit()
void ListTraverse(DuLinkList L,void(*visit)(ElemType));

// 在带头结点的双链循环线性表L中第i个位置之前插入元素e，i的合法值为1≤i≤表长+1
Status ListInsert(DuLinkList L,int i,ElemType e);

#endif /* bo2_5_h */
