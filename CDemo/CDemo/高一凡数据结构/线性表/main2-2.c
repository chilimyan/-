//
//  main2-2.c
//  CDemo
//
//  Created by chilim on 2018/9/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main2-2.h"

void main26(){
    LinkList L = NULL;
    ElemType e, e0;
    Status i;
    int j,k;
    InitList1(&L);
    for (j = 1; j <= 5; j ++) {
        i = ListInsert1(L,j, j);
    }
    printf("在L的表头一次插入1-5后：L=");
    ListTraverse1(L, print);
    i = ListEmpty1(L);
    printf("L是否为空:i= %d(1是0否)\n",i);
    ClearList1(L);
    printf("清空L后：L = ");
    ListTraverse1(L, print);
    i = ListEmpty1(L);
    printf("L是否为空:i = %d(1是0否)\n",i);
    for (j = 1; j <= 10; j++) {
        ListInsert1(L, j, j);
    }
    printf("在L的表尾一次插入1-10后：L=");
    ListTraverse1(L, print);
    GetElem1(L, 5, &e);
    printf("第5个元素的值为%d\n",e);
    for (j = 0; j <= 1; j++) {
        k = LocateElem1(L, j, equal);
        if (k) {
            printf("第%d个元素的值为%d\n",k,j);
        }else{
            printf("没有值为%d的元素\n",j);
        }
    }
    for (j = 1; j <= 2; j++) {
        GetElem1(L, j, &e0);//求第j个数据付给e0
        i = PriorElem1(L, e0, &e);//求e0的前驱
        if (i == INFEASIBLE) {
            printf("元素%d无前驱\n",e0);
        }else{
            printf("元素%d的前驱为%d\n",e0,e);
        }
    }
    for (j = ListLength1(L) - 1; j <= ListLength1(L); j++) {
        GetElem1(L, j, &e0);//把第j个数据给e0
        i= NextElem1(L, e0, &e);//求e0的后继
        if (i == INFEASIBLE) {
            printf("元素%d无后继\n",e0);
        }else{
            printf("元素%d的后继为%d\n",e0,e);
        }
    }
    k = ListLength1(L);
    for (j = k+1; j >= k; j --) {
        i = ListDelete1(L, j, &e);
        if (i == ERROR) {
            printf("删除第%d个元素失败\n",j);
        }else{
            printf("删除第%d个元素成功,其值为%d\n",j, e);
        }
    }
    printf("一次输出元素L:");
    ListTraverse1(L, print);
    DestroyList1(&L);
    printf("销毁L后：L = %p\n",L);
}

