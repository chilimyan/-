
//
//  main2-8.c
//  不带头结点的单链表
//
//  Created by chilim on 2018/10/14.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main2-8.h"

void main28(){
    LinkList L;
    ElemType e,e0;
    Status i;
    int j,k;
    InitList(&L);
    for (j = 1; j <= 5; j++) {
        i = ListInsert(&L, 1, j);
        if (!i) {
            exit(ERROR);
        }
    }
    printf("在L的表头依次插入1~5后:L=");
    ListTraverse(L, print);
    i = ListEmpty(L);
    printf("L是否空:i=%d(1:是 0:否)\n",i);
    ClearList(&L);
    printf("清空L后:L=");
    ListTraverse(L, print);
    i = ListEmpty(L);
    printf("L是否空:i=%d(1:是 0:否)\n",i);
    for (j = 1; j <= 10; j ++) {
        ListInsert(&L, j, j);
    }
    printf("在L的表尾依次插入1~10后:L=");
    ListTraverse(L, print);
    i = GetElem(L, 5, &e);
    if (i == OK) {
        printf("第5个元素的值为%d\n",e);
    }
    for (j = 0; j <= 1; j++) {
        k = LocateElem(L, j, equal);
        if (k) {
            printf("第%d个元素的值为%d\n",k,j);
        }else{
            printf("没有值为%d的元素\n",j);
        }
    }
    for (j = 1; j <= 2; j++) {
        GetElem(L, j, &e0);
        i = PriorElem(L, e0, &e);// 求e0的前驱
        if (i == INFEASIBLE) {
            printf("元素%d无前驱\n",e0);
        }else{
            printf("元素%d的前驱为%d\n",e0,e);
        }
    }
    for (j = ListLength(L) - 1; j <= ListLength(L); j ++) {
        GetElem(L, j, &e0);
        i = NextElem(L, e0, &e);// 求e0的后继
        if (i == INFEASIBLE) {
            printf("元素%d无后继\n",e0);
        }else{
            printf("元素%d的后继为%d\n",e0,e);
        }
    }
    k = ListLength(L);
    for (j = k+1; j >= k; j--) {
        i = ListDelete(L, j, &e);// 删除第j个数据
        if (i == ERROR) {
            printf("删除第%d个元素失败\n",j);
        }else{
            printf("删除第%d个元素成功，其值为%d\n",j,e);
        }
    }
    printf("依次输出L的元素:");
    ListTraverse(L, print);
    DestroyList(&L);
    printf("销毁L后:L=%u\n",L);
}
