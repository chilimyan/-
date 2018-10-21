//
//  main2-32.c
//  静态单链表
//
//  Created by chilim on 2018/10/19.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main2-32.h"

void main232(){
    int j,k,La,Lb;
    Status i;
    ElemType e,e0;
    SLinkList L;
    InitSpace(L);// 建立备用链表
    La = InitList(L);// 初始化链表La
    Lb = InitList(L);// 初始化链表Lb
    printf("La表空否?%d(1:空 0:否) La的表长=%d\n",ListEmpty(L,La),ListLength(L,La));
    for (j = 1; j <= 5; j ++) {
        ListInsert(L, La, 1, j);
    }
    printf("在空表La的表头依次插入1~5后:La=");
    ListTraverse(L, La, print);
    for (j = 1; j <= 5; j ++) {
        ListInsert(L, Lb,j, j);
    }
    printf("在空表Lb的表尾依次插入1~5后:Lb=");
    ListTraverse(L, Lb, print);
    printf("La表空否?%d(1:空 0:否) La的表长=%d\n",ListEmpty(L,La),ListLength(L,La));
    ClearList(L, La);
    printf("清空La后:La=");
    ListTraverse(L, La, print);
    printf("La表空否?%d(1:空 0:否) La的表长=%d\n",ListEmpty(L,La),ListLength(L,La));
    for (j = 2; j < 8; j += 5) {
        i = GetElem(L, Lb, j, &e);
        if (i) {
            printf("Lb表的第%d个元素的值为%d\n",j,e);
        }else{
            printf("Lb表不存在第%d个元素!\n",j);
        }
    }
    for (j = 0; j <= 1; j ++) {
        k = LocateElem(L, Lb, j);
        if (k) {
            printf("Lb表中值为%d的元素在静态链表中的位序为%d\n",j,k);
        }else{
            printf("Lb表中没有值为%d的元素\n",j);
        }
    }
    for (j = 1; j <= 2; j ++) {
        GetElem(L, Lb, j, &e0);
        i = PriorElem(L, Lb, e0, &e);
        if (!i) {
            printf("Lb表中的元素%d无前驱\n",e0);
        }else{
            printf("Lb表中元素%d的前驱为%d\n",e0,e);
        }
    }
    for (j = ListLength(L, Lb) - 1;j <= ListLength(L, Lb) ; j ++) {
        GetElem(L, Lb, j, &e0);
        i = NextElem(L, Lb, e0, &e);
        if (!i) {
            printf("Lb表中元素%d无后继\n",e0);
        }else{
            printf("Lb表中元素%d的后继为%d\n",e0,e);
        }
    }
    k = ListLength(L, Lb);// k为表长
    for (j = k + 1; j >= k; j --) {
        i = ListDelete(L, Lb, j, &e);
        if (i) {
            printf("Lb表中第%d个元素为%d,已删除。\n",j,e);
        }else{
            printf("删除Lb表中第%d个元素失败(不存在此元素)。\n",j);
        }
    }
    printf("依次输出Lb的元素:");
    ListTraverse(L, Lb, print);// 依次对元素调用print()，输出元素的值
}
