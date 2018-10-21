//
//  bo2-4.h
//  循环单链表
//
//  Created by chilim on 2018/10/20.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_4_h
#define bo2_4_h
//设立尾指针的单循环链表
#include <stdio.h>
#include "c2-2.h"

//构造一个空的线性表L
void InitList(LinkList *L);

//销毁线性表L
void DestroyList(LinkList *L);

//将L重置为空表
void ClearList(LinkList *L);

//返回L中数据元素个数
int ListLength(LinkList L);

// 当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
Status GetElem(LinkList L,int i,ElemType *e);

//返回L中第1个与e满足关系compare()的数据元素的位序。
//若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;
Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e);

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继;
Status NextELem(LinkList L,ElemType cur_e,ElemType *next_e);

Status ListEmpty(LinkList L);

//依次对L的每个数据元素调用函数vi()
void ListTraverse(LinkList L,void(*vi)(ElemType));

// 删除L的第i个元素，并由e返回其值
Status ListDelete(LinkList *L,int i,ElemType *e);

// 在L的第i个位置之前插入元素e
Status ListInsert(LinkList *L,int i, ElemType e);

#endif /* bo2_4_h */
