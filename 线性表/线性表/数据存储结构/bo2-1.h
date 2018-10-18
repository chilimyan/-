//
//  bo2-1.h
//  线性表
//
//  Created by chilim on 2018/10/11.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_1_h
#define bo2_1_h

#include <stdio.h>
#include "c2-1.h"

// 操作结果:构造一个空的顺序线性表L
void InitList(PSqlist L);

// 初始条件:顺序线性表L已存在。操作结果:销毁顺序线性表L
void DestoryList(PSqlist L);

// 初始条件:顺序线性表L已存在。操作结果:将L重置为空表
void ClearList(PSqlist L);

// 初始条件:顺序线性表L已存在。操作结果:若L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(PSqlist L);

// 返回L中数据元素的个数
int ListLength(PSqlist L);

// 用e返回L中第i个数据元素的值
Status GetElem(PSqlist L, int i, ElemType *e);

//返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。
int LocateElem(PSqlist L, ElemType e, Status(*compare)(ElemType,ElemType));

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;否则操作失败，pre_e无定义
Status PriorElem(PSqlist L, ElemType cur_e, ElemType *pre_e);

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继;否则操作失败，next_e无定义
Status NextElem(PSqlist L, ElemType cur_e,ElemType *next_e);

//在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert(PSqlist L, int i, ElemType e);

//删除L的第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete(PSqlist L, int i, ElemType *e);

//依次对L的每个数据元素调用函数vi()
// vi()的形参加′&′，表明可通过调用vi()改变元素的值
void ListTraverse(PSqlist L, void(*vi)(ElemType *));

#endif /* bo2_1_h */
