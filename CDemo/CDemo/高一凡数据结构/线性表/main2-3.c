//
//  main2-3.c
//  CDemo
//
//  Created by chilim on 2018/9/2.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main2-3.h"

void main29(){
    LinkList L;
    ElemType e, e0;
    Status i;
    int j,k;
    InitList2(&L);
    for (j = 1; j<=5; j++) {
        i = ListInsert2(&L, 1, j);
        if (!i) {//插入失败
            exit(OVERFLOW);
        }
    }
    printf("在L的表头一次插入1-5后：L=");
    ListTraverse2(L, print);
    i = ListEmpty2(L);
    printf("L是否空:i = %d(1是，0否)\n",i);
    ClearList2(&L);
    printf("清空L后：L");
    ListTraverse2(L, print);
    i = ListEmpty2(L);
    printf("L是否为空:i = %d(1是0否)\n",i);
    for (j = 1; j <= 10; j++) {
        ListInsert2(&L, j, j);
    }
    printf("在L的表尾依次插入1-10后：L=");
    ListTraverse2(L, print);
    i = GetElem2(L, 5, &e);
    if (i == OK) {
        printf("第五个元素的值为%d\n",e);
    }
    for (j = 0; j <= 1; j ++) {
        k = LocateElem2(L, j, equal);
        if (k) {
            printf("第%d个元素的值为%d\n",k,j);
        }else{
            printf("没有值为%d的元素\n",j);
        }
    }
    for (j = ListLength2(L)-1; j <= ListLength2(L); j++) {
        GetElem2(L, j, &e0);//把第j个数据付给e0
        i = NextElem2(L, e0, &e);//求e0的后继
        if (i == INFEASIBLE) {
            printf("元素%d无后继\n",e0);
        }else{
            printf("元素%d的后继为%d\n",e0,e);
        }
    }
    k = ListLength2(L);//表长
    for (j = k+1; j >= k; j--) {
        i = ListDelete2(&L, j, &e);//删除第j个元素
        if (i == ERROR) {
            printf("删除第%d个元素失败\n",j);
        }else{
            printf("删除第%d个元素成功，其值为%d\n",j,e);
        }
    }
    printf("依次输出L的元素:");
    ListTraverse2(L, print);
    DestroyList1(&L);
    printf("销毁后L=%p\n",L);
}

