//
//  main2-31.c
//  静态单链表
//
//  Created by chilim on 2018/10/17.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main2-31.h"

void main231(){
    int j,k;
    Status i;
    ElemType e,e0;
    SLinkList L;
    InitList(L);
    for (j = 1; j <= 5; j ++) {
        i = ListInsert(L, 1, j);
    }
    printf("在L的表头依次插入1~5后:L=");
    ListTraverse(L, print);
    i = ListEmpty(L);
    printf("L是否空:i=%d(1:是 0:否)表L的长度=%d\n",i,ListLength(L));
    ClearList(L);
    printf("清空L后:L=");
    ListTraverse(L, print);
    i = ListEmpty(L);
    printf("L是否空:i=%d(1:是 0:否)表L的长度=%d\n",i,ListLength(L));
    for (j = 1; j <= 10; j++) {
        ListInsert(L, j, j);
    }
    printf("在L的表尾依次插入1~10后:L=");
    ListTraverse(L, print);
    GetElem(L, 5, &e);
    printf("第5个元素的值为%d\n",e);
    for (j = 0; j <= 1; j ++) {
        k = LocateElem(L, j);
        if (k) {
            printf("值为%d的元素在静态链表中的位序为%d\n",j,k);
        }else{
            printf("没有值为%d的元素\n",j);
        }
    }
    for (j = 1; j <= 2; j ++) {// 测试头两个数据
        GetElem(L, j, &e0);// 把第j个数据赋给e0
        i = PriorElem(L, e0, &e);
        if (!i) {
            printf("元素%d无前驱\n",e0);
        }else{
            printf("元素%d的前驱为%d\n",e0,e);
        }
    }
    for (j = ListLength(L) - 1; j <= ListLength(L); j ++) {// 最后两个数据
        GetElem(L, j, &e0);// 把第j个数据赋给e0
        i = NextElem(L, e0, &e);
        if (!i) {
            printf("元素%d无后继\n",e0);
        }else{
            printf("元素%d的后继为%d\n",e0,e);
        }
    }
    k = ListLength(L);
    for (j = k+1; j >= k; j --) {
        i = ListDelete(L, j, &e);// 删除第j个数据
        if (i) {
            printf("第%d个元素为%d,已删除。\n",j,e);
        }else{
            printf("删除第%d个元素失败(不存在此元素)。\n",j);
        }
    }
    printf("依次输出L的元素:");
    ListTraverse(L, print);
    
}
