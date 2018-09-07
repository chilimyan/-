//
//  bo2-1.h
//  CDemo
//
//  Created by chilim on 2018/8/29.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_1_h
#define bo2_1_h

#include <stdio.h>
#include "c2-1.h"

void InitList(struct Sqlist *L);

void DestroyList(struct Sqlist *L);

void ClearList(struct Sqlist *L);

Status ListEmpty(struct Sqlist L);

int ListLength(struct Sqlist L);

Status GetElem(struct Sqlist L, int i, ElemType *e);

int LocateElem(struct Sqlist L, ElemType e, Status(*compare)(ElemType, ElemType));

Status PriorElem(struct Sqlist L, ElemType cur_e, ElemType *pre_e);

Status NextElem(struct Sqlist L, ElemType cur_e, ElemType *next_e);

Status ListInsert(struct Sqlist *L, int i, ElemType e);

Status ListDelete(struct Sqlist *L, int i, ElemType *e);

void ListTraverse(struct Sqlist L, void(*vi)(ElemType *));

#endif /* bo2_1_h */
