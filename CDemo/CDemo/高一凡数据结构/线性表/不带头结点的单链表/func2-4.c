//
//  func2-4.c
//  CDemo
//
//  Created by chilim on 2018/9/2.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "func2-4.h"

void InserAscend(LinkList *L, ElemType e, int(*compare)(ElemType, ElemType)){
    //按关键字非降序将e插入表L。函数compare()返回值为形参1的关键字-形参2的关键字
    LinkList q = *L;
    if (!*L || compare(e, (*L)->data) < 0) {
        ListInsert2(L, 1, e);//将e插入到表头
    }else{
        while (q->next && compare(q->next->data, e) < 0) {
            q = q->next;
        }
        ListInsert2(&q, 2, e);
    }
}

LinkList Point(LinkList L, ElemType e, Status(*equal)(ElemType, ElemType), LinkList *p){
    // 查找表L中满足条件的结点。如找到，返回指向该结点的指针，p指向该结点的前驱(若该结点是 // 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL，p无定义。
    // 函数equal()的两形参的关键字相等，返回OK;否则返回ERROR
    int i, j;
    i = LocateElem2(L, e, equal);
    if (i) {//找到
        if (i == 1) {//如果是第一个节点
            *p = NULL;
            return L;
        }
        *p = L;
        for (j = 2; j < i; j ++) {
            *p = (*p)->next;
        }
        return (*p)->next;
    }else{
        return NULL;//没找到
    }
}

Status DeleteElem(LinkList *L, ElemType *e, Status(*equal)(ElemType, ElemType)){
    // 删除表L中满足条件的结点，并返回TRUE;如无此结点，则返回FALSE。
    // 函数equal()的两形参的关键字相等，返回OK;否则返回ERROR
    LinkList p,q;
    q = Point(*L, *e, equal, &p);//找到要删除的节点；
    if (q) {
        if (p) {//该节点不是第一个节点
           ListDelete2(L, 2, e);
        }else{
            ListDelete2(L, 1, e);
        }
        return TRUE;
    }
    return FALSE;
}

