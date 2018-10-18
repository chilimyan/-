//
//  func2-1.c
//  不带头结点的单链表
//
//  Created by chilim on 2018/10/15.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "func2-1.h"

// 按关键字非降序将e插入表L。函数compare()返回值为形参1的关键字-形参2的关键字
void InsertAscend(LinkList *L, ElemType e,int(*compare)(ElemType,ElemType)){
    LinkList q = *L;
    if (*L == NULL) {
        ListInsert(L,1 , e);
        q = *L;
    }else{
        while (q->next && compare(q->next->data,e) < 0) {
            q = q->next;
        }
        ListInsert(&q, 2, e);// 插在q所指结点后(将q作为头指针)
    }
}

// 查找表L中满足条件的结点。如找到，返回指向该结点的指针，p指向该结点的前驱(若该结点是 // 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL，p无定义。
// 函数equal()的两形参的关键字相等，返回OK;否则返回ERROR
LinkList Point(LinkList L,ElemType e,Status(*epual)(ElemType,ElemType),LinkList *p){
    int i,j;
    i = LocateElem(L, e, epual);
    if (i) {
        if (i == 1) {
            *p = NULL;
            return L;
        }
        *p = L;
        for (j = 2; j < i; j ++) {
            *p = (*p)->next;
        }
        return (*p)->next;
    }
    return NULL;
}

// 删除表L中满足条件的结点，并返回TRUE;如无此结点，则返回FALSE。
// 函数equal()的两形参的关键字相等，返回OK;否则返回ERROR
Status DeleteElem(LinkList *L,ElemType *e,Status(*equal)(ElemType,ElemType)){
    LinkList p,q;
    q = Point(*L, *e, equal, &p);
    if (q) {
        if (q) {
            ListDelete(p, 2, e);
        }else{
            ListDelete(*L, 1, e);
        }
        return TRUE;
    }
    return FALSE;
}
