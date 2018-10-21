//
//  bo2-5.c
//  双向链表
//
//  Created by chilim on 2018/10/21.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-5.h"

// 产生空的双向循环链表L
void InitList(DuLinkList *L){
    *L = (DuLinkList)malloc(sizeof(struct DuLNode));
    if (*L) {
        (*L)->next = (*L)->prior = *L;
    }else{
        exit(OVERFLOW);
    }
}

//销毁双向循环链表L
void DestroyList(DuLinkList *L){
    DuLinkList q,p = (*L)->next;// p指向第一个结点
    while (p != *L) {// p没到表头
        q = p->next;
        free(p);
        p = q;
    }
    free(*L);
    *L = NULL;
}

//将L重置为空表
void ClearList(DuLinkList L){
    DuLinkList q,p = L->next;// p指向第一个结点
    while (p != L) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = L->prior = L;// 头结点的两个指针域均指向自身
}

//若L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(DuLinkList L){
    if (L->next == L && L->prior == L) {
        return TRUE;
    }else{
        return FALSE;
    }
}
//返回L中数据元素个数
int ListLength(DuLinkList L){
    int i = 0;
    DuLinkList p = L->next;
    while (p != L) {
        i ++;
        p = p->next;
    }
    return i;
}

// 当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
Status GetElem(DuLinkList L,int i,ElemType *e){
    int j = 1;
    DuLinkList p = L->next;// p指向第1个结点
    while (p != L && j < i) {
        p = p->next;
        j ++;
    }
    if (p == L || j > i) {// 第i个元素不存在
        return ERROR;
    }
    *e = p->data;// 取第i个元素
    return OK;
}

//返回L中第1个与e满足关系compare()的数据元素的位序。
//若这样的数据元素不存在，则返回值为0
int LocateElem(DuLinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    int i = 0;
    DuLinkList p = L->next;// p指向第1个元素
    while (p != L) {
        i ++;
        if (compare(p->data,e)) {
            return i;
        }
        p= p->next;
    }
    return 0;
}

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;
Status PriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e){
    DuLinkList p = L->next->next;// p指向第2个元素
    while (p != L) {
        if (p->data == cur_e) {
            *pre_e = p->prior->data;
            return TRUE;
        }
        p = p->next;
    }
    return FALSE;
}

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
Status NextElem(DuLinkList L,ElemType cur_e,ElemType *next_e){
    DuLinkList p = L->next->next;// p指向第2个元素
    while (p != L) {
        if (p ->prior->data == cur_e) {
            *next_e = p->data;
            return TRUE;
        }
        p = p->next;
    }
    return FALSE;
}

// 在双向链表L中返回第i个元素的地址。i为0，返回头结点的地址。若第i个元素不存在返回NULL
DuLinkList GetElemP(DuLinkList L,int i){
    int j;
    DuLinkList p = L;// p指向头结点
    if (i < 0 || i > ListLength(L)) {
        return NULL;
    }
    for (j = 1; j <= i; j ++) {
        p = p->next;
    }
    return p;
}

// 在带头结点的双链循环线性表L中第i个位置之前插入元素e，i的合法值为1≤i≤表长+1
Status ListInsert(DuLinkList L,int i,ElemType e){
    DuLinkList p,s;
    if (i < 1 || i > ListLength(L) + 1) {
        return ERROR;
    }
    p = GetElemP(L, i-1);//在L中确定第i个元素前驱的位置指针p
    if (!p) {
        return ERROR;
    }
    s = (DuLinkList)malloc(sizeof(struct DuLNode));
    if (!s) {
        return OVERFLOW;
    }
    s->data = e;
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
    return OK;
}

// 删除带头结点的双链循环线性表L的第i个元素，i的合法值为1≤i≤表长
Status ListDelete(DuLinkList L,int i,ElemType *e){
    DuLinkList p;
    if (i < 1) {
        return ERROR;
    }
    p = GetElemP(L, i);// 在L中确定第i个元素的位置指针p
    if (!p) {// p=NULL,即第i个元素不存在
        return ERROR;
    }
    *e = p->data;
    p->prior->next = p ->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

// 由双链循环线性表L的头结点出发，正序对每个数据元素调用函数visit()
void ListTraverse(DuLinkList L,void(*visit)(ElemType)){
    DuLinkList p = L->next;// p指向头结点
    while (p != L) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

// 由双链循环线性表L的头结点出发，逆序对每个数据元素调用函数visit()
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType)){
    DuLinkList p = L->prior;// p指向尾结点
    while (p != L) {
        visit(p->data);
        p = p->prior;
    }
    printf("\n");
}





