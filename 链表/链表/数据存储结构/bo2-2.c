//
//  bo2-2.c
//  链表
//
//  Created by chilim on 2018/10/13.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-2.h"

//构造一个空的线性表L
LinkList InitList(){
    // 产生头结点，并使L指向此头结点
    LinkList L = NULL;
    L = (LinkList)malloc(sizeof(struct LNode));
    if (!L) {
        exit(OVERFLOW);
    }
    L->next = NULL;// 指针域为空
    return L;
}

//销毁线性表L
void DestroyList(LinkList *L){
    LinkList q;
    while (*L) {
        q = (*L)->next;
        free(*L);
        *L = q;
    }
}

//将L重置为空表
void ClearList(LinkList L){
    LinkList p,q;
    p = L->next;// p指向第一个结点
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    // 头结点指针域为空
    L->next = NULL;
}

//若L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(LinkList L){
    if (L->next) {
        return FALSE;
    }else{
        return TRUE;
    }
}

//返回L中数据元素的个数
int ListLength(LinkList L){
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i ++;
        p = p->next;
    }
    return i;
}

// L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK;否则返回ERROR
Status GetElem(LinkList L,int i,ElemType *e){
    int j = 1;//j为计数器
    LinkList p = L->next;// p指向第一个结点
    while (p && j < i) {
        p = p->next;
        j ++;
    }
    if (!p || j > i) {// 第i个元素不存在
        return ERROR;
    }
    *e = p->data;// 取第i个元素
    return OK;
}

// 返回L中第1个与e满足关系compare()的数据元素的位序。
// 若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i ++;
        if (compare(p->data, e)) { // 找到这样的数据元素
            return i;
        }
        p = p->next;
    }
    return 0;
}

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
// 返回OK;否则操作失败，pre_e无定义，返回INFEASIBLE
Status PriorElem(LinkList L,ElemType cur_e, ElemType *pre_e){
    LinkList q,p = L->next;// p指向第一个结点
    while (p->next) {// p所指结点有后继
        q = p->next;// q为p的后继
        if (q->data == cur_e) {
            *pre_e = p->data;
            return OK;
        }
        p = q;// p向后移
    }
    return INFEASIBLE;
}

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
// 返回OK;否则操作失败，next_e无定义，返回INFEASIBLE
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e){
    LinkList p = L->next;// p指向第一个结点
    while (p->next) {// p所指结点有后继
        if (p->data == cur_e) {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}

// 在带头结点的单链线性表L中第i个位置之前插入元素e
Status ListInsert(LinkList L,int i,ElemType e){
    int j = 0;
    LinkList p = L,s;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || j > i-1) {// i小于1或者大于表长
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(struct LNode));// 生成新结点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//在带头结点的单链线性表L中，删除第i个元素，并由e返回其
Status ListDelete(LinkList L,int i,ElemType *e){
    int j = 0;
    LinkList p = L,q;
    while (p->next && j < i-1) {// 寻找第i个结点，并令p指向其前驱
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) {// 删除位置不合理
        return ERROR;
    }
    q = p->next;// 删除并释放结点
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

//依次对L的每个数据元素调用函数vi()
void ListTraverse(LinkList L,void(*vi)(ElemType)){
    LinkList p = L->next;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}





