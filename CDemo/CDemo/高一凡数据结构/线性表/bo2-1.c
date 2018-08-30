//
//  bo2-1.c
//  CDemo
//
//  Created by chilim on 2018/8/29.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-1.h"

void InitList(struct Sqlist *L){
    //构造一个空的顺序线性表L
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        exit(OVERFLOW);// 存储分配失败
    }
    L->length = 0;// 空表长度为0
    L->listsize = LIST_INIT_SIZE;// 初始存储容量
}

void DestroyList(struct Sqlist *L){
    //销毁顺序线性表
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
}

void ClearList(struct Sqlist *L){
    //将线性表重置为空表
    L->length = 0;
}

Status ListEmpty(struct Sqlist L){
    //判断线性表L是否为空表
    if (L.length == 0) {
        return TRUE;
    }else{
        return FALSE;
    }
}

int ListLength(struct Sqlist L){
    //返回线性表的长度
    return L.length;
}

Status GetElem(struct Sqlist L, int i, ElemType *e){
    //用e返回L中第i个元素的值
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    *e = *(L.elem + i - 1);
    return OK;
}

int LocateElem(struct Sqlist L, ElemType e, Status(*compare)(ElemType, ElemType)){
    //返回L中第一个与e满足关系compare()的数据元素的位序，若这样的数据元素不存在，则返回值为0.
    ElemType *p;
    int i = 1;//i的初值为第一个元素位序
    p = L.elem;//p的初值为第一个元素的存储位置
    while (i <= L.length && !compare(*p++,e)) {
        ++ i;
    }
    if (i <= L.length) {
        return i;
    }
    return 0;
}

Status PriorElem(struct Sqlist L, ElemType cur_e, ElemType *pre_e){
    //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;
    //否则操作失败，pre_e无定义
    int i = 2;
    ElemType *p = L.elem + 1;
    while (i <= L.length && *p != cur_e) {
        p++;
        i++;
    }
    if (i > L.length) {
        return INFEASIBLE;
    }else{
        *pre_e = *(--p);
        return OK;
    }
}

Status NextElem(struct Sqlist L, ElemType cur_e, ElemType *next_e){
    //初始条件:顺序线性表L已存在 操作结果:若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继;
    //否则操作失败，next_e无定义
    int i = 1;
    ElemType *p = L.elem;
    while (i < L.length && *p != cur_e) {
        i ++;
        p ++;
    }
    if (i == L.length) {
        return INFEASIBLE;
    }else{
        *next_e = *(++p);
        return OK;
    }
}

Status ListInsert(struct Sqlist *L, int i, ElemType e){
    //在L中第i个位置之前插入新的数据元素e，L的长度加1
    ElemType *newBase, *q, *p;
    if (i < 1 || i > L->length+1) {//i值不合法
        return ERROR;
    }
    if (L->length >= L->listsize) {//当前存储空间已满，增加分配
        if (!(newBase = (ElemType *)realloc(L->elem, (L->listsize + LIST_INCREMENT)*sizeof(ElemType)))) {
            exit(OVERFLOW);//存储分配失败
        }
        L->elem = newBase;
        L->listsize = L->listsize + LIST_INCREMENT;
    }
    q = L->elem + i - 1;//q为插入的位置
    for (p = L->elem + L->length - 1; p >= q; p--) {
        *(p+1) = * p;
    }
    *q = e;//插入1
    ++ L->length;//表长增1
    return OK;
}

Status ListDelete(struct Sqlist *L, int i, ElemType *e){
    //删除L的第i个数据元素，并用e返回其值，L的长度减1
    ElemType *p, *q;
    if (i < 1 || i >L->length) {
        return ERROR;
    }
    p = L->elem + i - 1;//被删除的元素
    *e = *p;
    q = L->elem + L->length -1;
    for (++p ; p <= q; ++p) {
        *(p-1) = *p;
    }
    L->length --;//表长减1
    return OK;
}

void ListTraverse(struct Sqlist L, void(*vi)(ElemType *)){
    //依次对L的每个数据元素调用函数vi()
    // vi()的形参加′&′，表明可通过调用vi()改变元素的值
    ElemType *p;
    int i;
    p = L.elem;
    for (i = 1; i <= L.length; i ++) {
        vi(p++);
    }
    printf("\n");
}




