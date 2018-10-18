//
//  algo2-12.c
//  链表
//
//  Created by chilim on 2018/10/14.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-12.h"

// 将所有在线性表Lb中但不在La中的数据元素插入到La中
void Union(LinkList La,LinkList Lb){
    ElemType e;
    int La_len,Lb_len;
    int i;
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i++) {
        GetElem(Lb, i, &e);
        if (!LocateElem(La, e, equal)) {
            ListInsert(La, ++La_len, e);
        }
    }
}

void main212(){
    LinkList La = NULL,Lb = NULL;
    int j;
    La = InitList();
    for (j = 1; j <= 5; j++) {
        ListInsert(La, j, j);
    }
    printf("La= "); // 输出表La的内容
    ListTraverse(La, print);
    Lb = InitList();
    for (j = 1; j <= 5; j ++) {// 在表Lb中插入5个元素
        ListInsert(Lb, j, 2*j);
    }
    printf("Lb= "); // 输出表Lb的内容
    ListTraverse(Lb, print);
    Union(La, Lb);
    printf("new La= "); // 输出新表La的内容
    ListTraverse(La,print);
}
