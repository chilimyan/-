//
//  bo2-1.c
//  线性表
//
//  Created by chilim on 2018/10/11.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-1.h"

// 操作结果:构造一个空的顺序线性表L
void InitList(PSqlist L){
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        exit(OVERFLOW);// 存储分配失败
    }
    L->length = 0;// 空表长度为0
    L->listsize = LIST_INIT_SIZE;// 初始存储容量
}

// 初始条件:顺序线性表L已存在。操作结果:销毁顺序线性表L
void DestoryList(PSqlist L){
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
}

// 初始条件:顺序线性表L已存在。操作结果:将L重置为空表
void ClearList(PSqlist L){
    L->length = 0;
}

// 初始条件:顺序线性表L已存在。操作结果:若L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(PSqlist L){
    if (L->length == 0) {
        return TRUE;
    }else{
        return FALSE;
    }
}

// 返回L中数据元素的个数
int ListLength(PSqlist L){
    return L->length;
}

// 用e返回L中第i个数据元素的值
Status GetElem(PSqlist L, int i, ElemType *e){
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    *e = *(L->elem + i -1);
    return OK;
}

//返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。
int LocateElem(PSqlist L, ElemType e, Status(*compare)(ElemType,ElemType)){
    ElemType *p;
    int i = 1;//i的初值为第1个元素的位序
    p = L->elem;
    while (i <= L->length && !compare(*p++,e)) {
        ++i;
    }
    if (i <= L->length) {
        return i;
    }else{
        return 0;
    }
}

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;否则操作失败，pre_e无定义
Status PriorElem(PSqlist L, ElemType cur_e, ElemType *pre_e){
    int i = 2;
    ElemType *p = L->elem + 1;
    while (i <= L->length && *p != cur_e) {
        p ++;
        i ++;
    }
    if (i > L->length) {
        return INFEASIBLE;
    }else{
        *pre_e = *(--p);
        return OK;
    }
}

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继;否则操作失败，next_e无定义
Status NextElem(PSqlist L, ElemType cur_e,ElemType *next_e){
    int i = 1;
    ElemType *p = L->elem;
    while (i < L->length && *p != cur_e) {
        i ++;
        p ++;
    }
    if (i == L->length) {
        return INFEASIBLE;
    }else{
        *next_e = *(++p);
        return OK;
    }
}

//在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert(PSqlist L, int i, ElemType e){
    ElemType *newBase;
    // 判断i值是否合法
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    // 当前存储空间已满,增加分配
    if (L->length >= L->listsize) {
        if (!(newBase = (ElemType *)realloc(L->elem, (L->listsize + LIST_INCREMENT)*sizeof(ElemType)))) {
            exit(OVERFLOW);
        }
        L->elem = newBase;//新的基址
        L->listsize += LIST_INCREMENT;// 增加存储容量
    }
    ElemType *p, *q;
    q = L->elem + i - 1;//要插入的位置
    for (p = L->elem + L->length - 1; p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;//插入e
    ++ L->length;//表长增1
    return OK;
}
//删除L的第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete(PSqlist L, int i, ElemType *e){
    //i值是否合法
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    ElemType *p;//被删除的位置
    p = L->elem + i - 1;
    *e = *p;
    ElemType *q;//表尾位置
    q = L->elem + L->length - 1;
    for (++ p; p <= q; ++p) {
        *(p-1) = *p;
    }
    L->length --;//表长减1
    return OK;
}

//依次对L的每个数据元素调用函数vi()
// vi()的形参加′&′，表明可通过调用vi()改变元素的值
void ListTraverse(PSqlist L, void(*vi)(ElemType *)){
    ElemType *p;
    int i;
    p = L->elem;
    for (i = 1; i <= L->length; i ++) {
        vi(p++);
    }
    printf("\n");
}

