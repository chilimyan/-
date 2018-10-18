//
//  bo2-31.h
//  静态单链表
//
//  Created by chilim on 2018/10/17.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_31_h
#define bo2_31_h

#include <stdio.h>
#include "c2-3.h"
#include "func2-2.h"

// DestroyList()和ClearList()的操作是一样的
#define DestroyList ClearList

//一个备用链表，表头为L的第一个单元L[0]，“0”表示空指针
void InitList(SLinkList L);

//将L重置为空表
void ClearList(SLinkList L);

// 若L是空表，返回TRUE;否则返回FALSE
Status ListEmpty(SLinkList L);

// 返回L中数据元素个数
int ListLength(SLinkList L);

// 用e返回L中第i个元素的值
Status GetElem(SLinkList L,int i,ElemType *e);

// 在静态单链线性表L中查找第1个值为e的元素。若找到，则返回它在L中的
// 位序;否则返回0。(与其它LocateElem()的定义不同)
int LocateElem(SLinkList L,ElemType e);

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;
Status PriorElem(SLinkList L,ElemType cur_e,ElemType *pre_e);

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继;
Status NextElem(SLinkList L,ElemType cur_e,ElemType *next_e);

// 在L中第i个元素之前插入新的数据元素e
Status ListInsert(SLinkList L,int i,ElemType e);

// 删除在L中第i个数据元素e，并返回其值
Status ListDelete(SLinkList L,int i,ElemType *e);

//依次对L的每个数据元素调用函数vi()
void ListTraverse(SLinkList L,void(*vi)(ElemType));

#endif /* bo2_31_h */
