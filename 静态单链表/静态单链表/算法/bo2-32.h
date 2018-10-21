//
//  bo2-32.h
//  静态单链表
//
//  Created by chilim on 2018/10/19.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_32_h
#define bo2_32_h

#include <stdio.h>
#include "c2-3.h"
#include "func2-2.h"

// 将一维数组L中各分量链成一个备用链表，L[0].cur为头指针。“0”表示空指针。
void InitSpace(SLinkList L);

// 构造一个空链表，返回值为空表在数组中的位序
int InitList(SLinkList L);

// 判断L中表头位序为n的链表是否空，若是空表返回TRUE;否则返回FALSE
Status ListEmpty(SLinkList L,int n);

// 返回L中表头位序为n的链表的数据元素个数
int ListLength(SLinkList L,int n);

// 初始条件:L中表头位序为n的静态链表已存在。操作结果:将此表重置为空表
void ClearList(SLinkList L,int n);

// 用e返回L中表头位序为n的链表的第i个元素的值
Status GetElem(SLinkList L,int n, int i,ElemType *e);

// 在L中表头位序为n的静态单链表中查找第1个值为e的元素。
// 若找到，则返回它在L中的位序;否则返回0。
int LocateElem(SLinkList L,int n,ElemType e);

//若cur_e是此单链表的数据元素，且不是第一个，
//则用pre_e返回它的前驱;否则操作失败，pre_e无定义
Status PriorElem(SLinkList L,int n,ElemType cur_e,ElemType *pre_e);

//若cur_e是此单链表的数据元素，且不是最后一个
//则用next_e返回它的后继;否则操作失败，next_e无定义
Status NextElem(SLinkList L,int n,ElemType cur_e,ElemType *next_e);

// 在L中表头位序为n的链表的第i个元素之前插入新的数据元素e
Status ListInsert(SLinkList L,int n,int i,ElemType e);

// 依次对L中表头位序为n的链表的每个数据元素调用函数vi()
void ListTraverse(SLinkList L,int n,void(*vi)(ElemType));

// 删除在L中表头位序为n的链表的第i个数据元素e，并返回其值
Status ListDelete(SLinkList L, int n,int i,ElemType *e);

#endif /* bo2_32_h */
