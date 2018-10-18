//
//  bo2-8.c
//  不带头结点的单链表
//
//  Created by chilim on 2018/10/14.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-8.h"

//构造一个空的线性表L
void InitList(LinkList *L){
    *L = NULL;
}

//将L重置为空表
void ClearList(LinkList *L){
    LinkList p = NULL;
    while (*L) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
}

//若L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(LinkList L){
    if (L) {
        return FALSE;
    }else{
        return TRUE;
    }
}

//返回L中数据元素的个数
int ListLength(LinkList L){
    int i = 0;
    LinkList p = L;
    while (p) {
        p = p->next;
        i ++;
    }
    return i;
}

// L为不带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
Status GetElem(LinkList L,int i,ElemType *e){
    int j = 1;
    LinkList p = L;
    if (i < 1) {
        return ERROR;
    }
    while (j < i && p) {
        j ++;
        p = p->next;
    }
    if (j == i) {// 存在第i个元素
        *e = p->data;
        return OK;
    }else{
        return ERROR;
    }
}

//返回L中第1个与e满足关系compare()的数据元素的位序。
// 若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    int i = 0;
    LinkList p = L;
    while (p) {
        i ++;
        if (compare(p->data,e)) {
            return i;
        }
        p = p->next;
    }
    return 0;
}

// 在不带头结点的单链线性表L中第i个位置之前插入元素e
Status ListInsert(LinkList *L, int i, ElemType e){
    int j = 1;
    LinkList p = *L,s;
    if (i < 1) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(struct LNode));// 生成新结点
    s->data = e;// 给s的data域赋值
    if (i == 1) {// 插在表头
        s->next = *L;
        *L = s;
    }else{
        // 插在表的其余处
        while (p && j < i-1) {
            p = p->next;
            j ++;
        }
        if (!p) {
            return ERROR;
        }
        s->next = p->next;
        p->next = s;
    }
    return OK;
}

// 在不带头结点的单链线性表L中,删除第i个元素,并由e返回其值
Status ListDelete(LinkList L,int i,ElemType *e){
    int j =1;
    LinkList p = L,q;
    if (i == 1) {// 删除第1个结点
        L = p->next;
        *e = p->data;
        free(p);
    }
    else{// 寻找第i个结点,并令p指向其前驱
        while (p->next && j < i-1) {
            p = p->next;
            j++;
        }
        if (!p->next || j > i-1) {
            return ERROR;
        }
        q = p->next;// 删除并释放结点
        p->next = q->next;
        *e = q->data;
        free(q);
    }
    return OK;
}

//依次对L的每个数据元素调用
// 函数vi()
void ListTraverse(LinkList L,void(*vi)(ElemType)){
    LinkList p = L;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}


//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
//返回OK;否则操作失败，pre_e无定义，返回INFEASIBLE
Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e){
    LinkList q,p = L;
    while (p->next) {
        q = p->next;
        if (q->data == cur_e) {
            *pre_e = p->data;
            return OK;
        }
        p = q;// p向后移
    }
    return INFEASIBLE;
}

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
//返回OK;否则操作失败，next_e无定义，返回INFEASIBLE
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e){
    LinkList p = L;
    while (p->next) {//p所指结点有后继
        if (p->data == cur_e) {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}
