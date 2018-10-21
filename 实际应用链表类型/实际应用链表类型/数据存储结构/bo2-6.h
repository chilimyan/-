//
//  bo2-6.h
//  实际应用链表类型
//
//  Created by chilim on 2018/10/21.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_6_h
#define bo2_6_h

#include <stdio.h>
#include "c2-5.h"
#include "func2-3.h"


// 分配由p指向的值为e的结点。若分配失败，则退出
void MakeNode(Link *p,ElemType e);

// 释放p所指结点
void FreeNode(Link *p);

// 构造一个空的线性链表L
void InitList(PLinkList *L);

// 将线性链表L重置为空表，并释放原链表的结点空间
void ClearList(PLinkList *L);

// 将指针s(s->data为第一个数据元素)所指(彼此以指针相链，以NULL结尾)的
// 一串结点链接在线性链表L的最后一个结点之后，并改变链表L的尾指针指向新的尾结点
void Append(PLinkList *L,Link s);

// h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。
// 若链表为空(h指向尾结点)，q=NULL，返回FALSE
Status DelFirst(PLinkList *L,Link h,Link *q);

//// h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前
void InsFirst(PLinkList *L,Link h,Link s);

// 销毁线性链表L，L不再存在
void DestroyList(PLinkList *L);

// 已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置。若无前驱，则返回NULL
Position PriorPos(PLinkList L,Link p);

// 删除线性链表L中的尾结点并以q返回，改变链表L的尾指针指向新的尾结点
Status Remove(PLinkList *L,Link *q);
// 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前，
// 并修改指针p指向新插入的结点
void InsBefore(PLinkList *L,Link *p,Link s);

// 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之后，
// 并修改指针p指向新插入的结点
void InsAfter(PLinkList *L, Link *p,Link s);

// 已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值
void SetCurElem(Link p,ElemType e);

// 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
ElemType GetCurElem(Link p);

// 若线性链表L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(PLinkList L);

// 返回线性链表L中元素个数
int ListLength(PLinkList L);

// 返回线性链表L中头结点的位置
Position GetHead(PLinkList L);

// 返回线性链表L中最后一个结点的位置
Position GetLast(PLinkList L);

// 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置。若无后继，则返回NULL
Position NextPos(Link p);

// 返回p指示线性链表L中第i个结点的位置，并返回OK，i值不合法时返回ERROR。i=0为头结点
Status LocatePos(PLinkList L,int i,Link *p);

// 返回线性链表L中第1个与e满足函数compare()判定关系的元素的位置，
Position LocateElem(PLinkList L,ElemType e,Status (*compare)(ElemType ,ElemType));

// 依次对L的每个数据元素调用函数visit()
void ListTraverse(PLinkList L,void(*visit)(ElemType));

// 已知L为有序线性链表，将元素e按非降序插入在L中。(用于一元多项式)
void OrderInsert(PLinkList *L, ElemType e,int (*comp)(ElemType,ElemType));

// 若升序链表L中存在与e满足判定函数compare()取值为0的元素，则q指示L中
// 第一个值为e的结点的位置，并返回TRUE;否则q指示第一个与e满足判定函数
Status LocateElem1(PLinkList L,ElemType e,Position *q,int (*compare)(ElemType,ElemType));

#endif /* bo2_6_h */
