//
//  bo2-6.c
//  实际应用链表类型
//
//  Created by chilim on 2018/10/21.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-6.h"

// 分配由p指向的值为e的结点。若分配失败，则退出
void MakeNode(Link *p,ElemType e){
    *p = (Link)malloc(sizeof(struct LNode));
    if (!*p) {
        exit(ERROR);
    }
    (*p)->data = e;
}
// 释放p所指结点
void FreeNode(Link *p){
    free(*p);
    *p = NULL;
}

// 构造一个空的线性链表L
void InitList(PLinkList *L){
    Link p = NULL;
    p = (Link)malloc(sizeof(struct LNode));
    *L = (PLinkList)malloc(sizeof(struct LinkList));
    if (p) {
        p->next = NULL;
        (*L)->head = (*L)->tail = p;
        (*L)->len = 0;
    }else{
        exit(ERROR);
    }
}

// 将线性链表L重置为空表，并释放原链表的结点空间
void ClearList(PLinkList *L){
    Link p,q;
    if ((*L)->head != (*L)->tail) {// 不是空表
        p = q = (*L)->head->next;
        (*L)->head->next = NULL;
        while (p != (*L)->tail) {
            p = q->next;
            free(q);
            q = p;
        }
        free(q);
        (*L)->tail = (*L)->head;
        (*L)->len = 0;
    }
}
// 销毁线性链表L，L不再存在
void DestroyList(PLinkList *L){
    ClearList(L);// 清空链表
    FreeNode(&(*L)->head);
    (*L)->tail = NULL;
    (*L)->len = 0;
}

//// h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前
void InsFirst(PLinkList *L,Link h,Link s){
    s->next = h->next;
    h->next = s;
    if (h == (*L)->tail) {// h指向尾结点
        (*L)->tail = h->next;// 修改尾指针
    }
    (*L)->len++;
}

// h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。
// 若链表为空(h指向尾结点)，q=NULL，返回FALSE
Status DelFirst(PLinkList *L,Link h,Link *q){
    *q = h->next;//第一个节点
    if (*q) {// 链表非空
        h->next = (*q)->next;
        if (!h->next) {// 删除尾结点
            (*L)->tail = h;// 修改尾指针
        }
        (*L)->len --;
        return OK;
    }else{
        return FALSE;// 链表空
    }
}
// 将指针s(s->data为第一个数据元素)所指(彼此以指针相链，以NULL结尾)的
// 一串结点链接在线性链表L的最后一个结点之后，并改变链表L的尾指针指向新的尾结点
void Append(PLinkList *L,Link s){
    int i = 1;
    (*L)->tail->next = s;
    while (s->next) {
        s = s->next;
        i ++;
    }
    (*L)->tail = s;
    (*L)->len += i;
}

// 已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置。若无前驱，则返回NULL
Position PriorPos(PLinkList L,Link p){
    Link q;
    q = L->head->next;
    if (q == p) {
        return NULL;
    }else{
        while (q->next != p) {// q不是p的直接前驱
            q = q->next;
        }
        return q;
    }
}

// 删除线性链表L中的尾结点并以q返回，改变链表L的尾指针指向新的尾结点
Status Remove(PLinkList *L,Link *q){
    Link p = (*L)->head;
    if ((*L)->len == 0) {// 空表
        q = NULL;
        return FALSE;
    }
    while (p ->next != (*L)->tail) {
        p= p->next;
    }
    *q = (*L)->tail;
    p->next = NULL;
    (*L)->tail = p;//尾指针指向新的尾节点
    (*L)->len --;
    return OK;
}

// 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前，
// 并修改指针p指向新插入的结点
void InsBefore(PLinkList *L,Link *p,Link s){
    Link q;
    q = PriorPos(*L, *p);// q是p的前驱
    if (!q) {
        q = (*L)->head;
    }
    s->next = *p;
    q->next = s;
    *p = s;
    (*L)->len ++;
}

// 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之后，
// 并修改指针p指向新插入的结点
void InsAfter(PLinkList *L, Link *p,Link s){
    if (*p == (*L)->tail) {
        (*L)->tail = s;
    }
    s->next = (*p)->next;
    (*p)->next = s;
    *p = s;
    (*L)->len ++;
}

// 已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值
void SetCurElem(Link p,ElemType e){
    p->data = e;
}

// 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
ElemType GetCurElem(Link p){
    return p->data;
}

// 若线性链表L为空表，则返回TRUE;否则返回FALSE
Status ListEmpty(PLinkList L){
    if (L->len) {
        return FALSE;
    }else{
        return TRUE;
    }
}

// 返回线性链表L中元素个数
int ListLength(PLinkList L){
    return L->len;
}

// 返回线性链表L中头结点的位置
Position GetHead(PLinkList L){
    return L->head;
}

// 返回线性链表L中最后一个结点的位置
Position GetLast(PLinkList L){
    return L->tail;
}

// 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置。若无后继，则返回NULL
Position NextPos(Link p){
    return p->next;
}

// 返回p指示线性链表L中第i个结点的位置，并返回OK，i值不合法时返回ERROR。i=0为头结点
Status LocatePos(PLinkList L,int i,Link *p){
    int j;
    if (i < 0 || i > L->len) {
        return ERROR;
    }else{
        *p = L->head;
        for (j = 1; j<= i; j++) {
            *p = (*p)->next;
        }
        return OK;
    }
}
// 返回线性链表L中第1个与e满足函数compare()判定关系的元素的位置，
Position LocateElem(PLinkList L,ElemType e,Status (*compare)(ElemType ,ElemType)){
    Link p = L->head;
    do {
        p = p->next;
    } while (p && !(compare(p->data,e)));
    return p;
}
// 依次对L的每个数据元素调用函数visit()
void ListTraverse(PLinkList L,void(*visit)(ElemType)){
    Link p = L->head->next;
    int j;
    for (j = 1; j <= L->len; j ++) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    
}

// 已知L为有序线性链表，将元素e按非降序插入在L中。(用于一元多项式)
void OrderInsert(PLinkList *L, ElemType e,int (*comp)(ElemType,ElemType)){
    Link o,p,q;
    q = (*L)->head;//q指向头结点
    p = q->next;//p指向q的后面一个节点
    while (p != NULL && comp(p->data,e) < 0) {
        q = p;
        p = p->next;
    }
    o = (Link)malloc(sizeof(struct LNode));// 生成结点
    o->data = e;
    q->next = o;
    o->next = p;
    (*L)->len++;
    if (!p) {// 插在表尾
        (*L)->tail = o;// 修改尾结点
    }
}
// 若升序链表L中存在与e满足判定函数compare()取值为0的元素，则q指示L中
// 第一个值为e的结点的位置，并返回TRUE;否则q指示第一个与e满足判定函数
Status LocateElem1(PLinkList L,ElemType e,Position *q,int (*compare)(ElemType,ElemType)){
    Link p = L->head,pp;
    do {
        pp = p;//pp指向p的上一个节点
        p = p->next;
    } while (p && (compare(p->data,e)<0));
    if (!p || compare(p->data,e)>0) {// 到表尾或compare(p->data,e)>0
        *q = pp;
        return FALSE;
    }else{
        *q = p;
        return TRUE;
    }
}






