//
//  bo2-3.c
//  CDemo
//
//  Created by chilim on 2018/9/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-3.h"

void InitList2(LinkList *L){
    //构造一个空的线性表L
    *L = NULL;//
}

void ClearList2(LinkList *L){
    //线性表L已存在。操作结果:将L重置为空表
    LinkList p;
    while (*L) {
        p = *L;//p指向L的首节点
        *L = (*L)->next;//L指向下一个节点
        free(p);//释放节点
    }
}

Status ListEmpty2(LinkList L){
    //若L为空表，则返回TRUE;否则返回FALSE
    if (L) {
        return FALSE;
    }else{
        return TRUE;
    }
}

int ListLength2(LinkList L){
    //返回L中数据元素的个数
    int i = 0;
    LinkList p = L;
    while (p) {//p指向节点
        p = p->next;
        i ++;
    }
    return i;
}

Status GetElem2(LinkList L, int i, ElemType *e){
    //L为不带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
    int j = 1;
    LinkList p = L;
    if (i < 1) {
        return ERROR;
    }
    while (j < i && p) {
        j++;
        p = p->next;
    }
    if (j == i) {
        *e = p->data;
        return OK;
    }
    return ERROR;
}

int LocateElem2(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)){
    // 操作结果:返回L中第1个与e满足关系compare()的数据元素的位序。
    // 若这样的数据元素不存在，则返回值为0
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

Status ListInsert2(LinkList *L, int i, ElemType e){
    // 在不带头结点的单链线性表L中第i个位置之前插入元素e
    int j = 1;
    LinkList p = *L, s;
    if (i < 1) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(LNode));//生成新节点
    s->data = e;
    if (i == 1) {
        s->next = *L;
        *L = s;
    }else{
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
Status ListDelete2(LinkList *L, int i, ElemType *e){
    //在不带头结点的单链线性表L中,删除第i个元素,并由e返回其值
    int j = 1;
    LinkList p = *L,q;
    if (i == 1) {
        *L = p->next;//L由第二个节点开始
        *e = p->data;
        free(p);
    }else{
        while (p->next && j < i-1) {
            p = p->next;
            j++;
        }
        if (!p->next || j >i-1) {
            return ERROR;
        }
        q = p->next;//要删除的节点q
        p->next = q->next;
        *e = q->data;
        free(q);
    }
    return OK;
}

void ListTraverse2(LinkList L, void(*vi)(ElemType)){
    // 操作结果:依次对L的每个数据元素调用
    // 函数vi()
    LinkList p = L;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

Status PriorElem2(LinkList L, ElemType cur_e, ElemType *pre_e){
    //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
    //返回OK;否则操作失败，pre_e无定义，返回INFEASIBLE
    LinkList q, p = L;
    while (p->next) {//p所指节点有后继
        q = p->next;
        if (q->data == cur_e) {
            *pre_e = p->data;
            return OK;
        }
        p = q;//p向后移
    }
    return INFEASIBLE;
}

Status NextElem2(LinkList L, ElemType cur_e, ElemType *next_e){
    //若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
    //返回OK;否则操作失败，next_e无定义，返回INFEASIBLE
    LinkList p = L;
    while (p->next) {
        if (p->data == cur_e) {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}



