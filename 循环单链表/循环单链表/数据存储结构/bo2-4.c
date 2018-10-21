//
//  bo2-4.c
//  循环单链表
//
//  Created by chilim on 2018/10/20.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-4.h"

//构造一个空的线性表L
void InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(struct LNode));
    if (!*L) {
        exit(OVERFLOW);
    }
    (*L)->next = *L;
}

//销毁线性表L
void DestroyList(LinkList *L){
    LinkList q,p = (*L)->next;// p指向头结点
    while (p != *L) {
        q = p->next;
        free(p);
    }
    free(*L);
    *L = NULL;
}

//将L重置为空表
void ClearList(LinkList *L){
    LinkList p,q;
    *L = (*L)->next;// L指向头结点
    p = (*L)->next;// p指向第一个结点
    while (p != *L) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = *L;
}

//返回L中数据元素个数
int ListLength(LinkList L){
    int i = 0;
    LinkList p = L->next;// p指向头结点
    while (p != L) {
        i ++;
        p = p->next;
    }
    return i;
}

Status ListEmpty(LinkList L){
    if (L->next == L) {
        return TRUE;
    }else{
        return FALSE;
    }
}

// 当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
Status GetElem(LinkList L,int i,ElemType *e){
    int j = 1;
    LinkList p = L->next->next;// p指向第一个结点
    if (i <= 0 || i > ListLength(L)) {
        return ERROR;
    }
    while (j < i) {
        p = p->next;
        j ++;
    }
    *e = p->data;
    return OK;
}
//返回L中第1个与e满足关系compare()的数据元素的位序。
//若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    int i = 0;
    LinkList p = L->next->next;
    while (p != L->next) {
        i ++;
        if (compare(p->data,e)) {
            return i;
        }
        p = p->next;
    }
    return 0;
}

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;
Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e){
    LinkList q,p = L->next->next;// p指向第一个结点
    q = p->next;
    while (q != L->next) {
        if (q->data == cur_e) {
            *pre_e = p->data;
            return TRUE;
        }
        p = q;
        q = q->next;
    }
    return FALSE;
}

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继;
Status NextELem(LinkList L,ElemType cur_e,ElemType *next_e){
    LinkList p = L->next->next;//p指向第一个结点
    while (p != L) {
        if (p->data == cur_e) {
            *next_e = p->next->data;
            return TRUE;
        }
        p = p->next;
    }
    return FALSE;
}

// 在L的第i个位置之前插入元素e
Status ListInsert(LinkList *L,int i, ElemType e){
    LinkList p = (*L)->next,s;
    int j = 0;
    if (i < 0 || i > ListLength(*L) + 1) {
        return ERROR;
    }
    while (j < i-1) {
        p = p->next;
        j++;
    }
    s = (LinkList)malloc(sizeof(struct LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    if (p == *L) {
        *L = s;
    }
    return OK;
}
 // 删除L的第i个元素，并由e返回其值
Status ListDelete(LinkList *L,int i,ElemType *e){
    LinkList p = (*L)->next,q;
    int j = 0;
    if (i <= 0 || i > ListLength(*L)) {
        return ERROR;
    }
    while (j < i -1) {
        p = p->next;
        j ++;
    }
    q = p->next;// q指向待删除结点
    p->next = q->next;
    *e = q->data;
    if ((*L) == q) {// 删除的是表尾元素
        *L = p;
    }
    free(q);
    return OK;
}

//依次对L的每个数据元素调用函数vi()
void ListTraverse(LinkList L,void(*vi)(ElemType)){
    LinkList p = L->next->next;// p指向首元结点
    while (p != L->next) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}
