//
//  bo2-2.c
//  CDemo
//
//  Created by chilim on 2018/9/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-2.h"

void InitList1(LinkList *L){
    //构造一个空链表
    *L = (LinkList)malloc(sizeof(LNode));
    if (!*L) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;//指针域置空
}

void DestroyList1(LinkList *L){
    //销毁链表L
    LinkList q = NULL;
    while (*L) {
        q = (*L)->next;
        free(*L);
        *L = q;
    }
}

void ClearList1(LinkList L){
    //将链表L置为空
    LinkList p, q;
    p = L->next;//p指向第一个节点
    while (p) {//没到表尾
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;//头指针置空
}

Status ListEmpty1(LinkList L){
    //若L为空表，则返回TRUE;否则返回FALSE
    if (L->next) {
        return FALSE;
    }else{
        return TRUE;
    }
}

int ListLength1(LinkList L){
    //返回L中数据元素的个数
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i ++;
        p = p->next;
    }
    return i;
}

Status GetElem1(LinkList L, int i, ElemType *e){
    //当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
    int j = 1;//计数器
    LinkList p = L->next;//p指向第一个结点
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {//第i个元素不存在
        return ERROR;
    }
    *e = p->data;
    return OK;
}

int LocateElem1(LinkList L, ElemType e, Status(*compare)(ElemType,ElemType)){
    //返回L中第1个与e满足关系compare()的数据元素的位序。
    // 若这样的数据元素不存在，则返回值为0
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i ++;
        if (compare(p->data,e)) {
            return i;
        }
        p = p->next;
    }
    return 0;
}

Status PriorElem1(LinkList L,ElemType cur_e,ElemType *pre_e){
    //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
    // 返回OK;否则操作失败，pre_e无定义，返回INFEASIBLE
    LinkList q, p = L->next;//p指向第一个节点
    while (p->next) {
        q = p->next;
        if (q->data == cur_e) {
            *pre_e = p->data;
            return OK;
        }
        p = q;//p向后移一个位置
    }
    return INFEASIBLE;
}

Status NextElem1(LinkList L, ElemType cur_e, ElemType *next_e){
    //若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
    // 返回OK;否则操作失败，next_e无定义，返回INFEASIBLE
    LinkList p = L->next;//p指向第一个节点
    while (p->next) {//p所指向结点有后继，也就是说p不是最后一个节点
        if (p->data == cur_e) {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}

Status ListInsert1(LinkList L, int i, ElemType e){
    //在带头结点的单链线性表L中第i个位置之前插入元素e
    int j = 0;
    LinkList p = L, s;
    while (p && j < i -1) {//寻找第i-1个节点
        p = p->next;
        j++;
    }
    if (!p || j > i -1) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(LNode));//生成新的结点
    s->data = e;//将e插入新的结点
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete1(LinkList L, int i, ElemType *e){
    //在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
    int j = 0;
    LinkList p = L, q;
    while (p->next && j < i-1) {//寻找第i个节点,和它的前驱
        p = p->next;
        j++;
    }
    if (!p->next || j > i-1) {
        return ERROR;
    }
    q = p->next;//要删除的节点
    p->next = q->next;
    *e = q->data;
    free(q);
    q = NULL;
    return OK;
}

void ListTraverse1(LinkList L, void(*vi)(ElemType)){
    //依次对L的每个数据元素调用函数vi()
    LinkList p = L->next;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}




