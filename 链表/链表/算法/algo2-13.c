//
//  algo2-13.c
//  链表
//
//  Created by chilim on 2018/10/14.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-13.h"


// 已知线性表La和Lb中的数据元素按值非递减排列。
// 归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
void MergeList(LinkList La,LinkList Lb,LinkList *Lc){
    int i = 1,j = 1,k = 0;
    int La_len,Lb_len;
    ElemType ai,bj;
    *Lc = InitList();// 创建空表Lc
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    while (i <= La_len && j <= Lb_len) {
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);
        if (ai <= bj) {
            ListInsert(*Lc, ++k, ai);
            ++ i;
        }else{
            ListInsert(*Lc, ++k, bj);
            ++ j;
        }
    }
    while (i <= La_len) {
        GetElem(La, i ++, &ai);
        ListInsert(*Lc, ++ k, ai);
    }
    while (j <= Lb_len) {
        GetElem(Lb, j ++, &bj);
        ListInsert(*Lc, ++ k, bj);
    }
}

void main213(){
    LinkList La = NULL, Lb = NULL, Lc = NULL;
    int j,a[4] = {3,5,8,11},b[7] = {2,6,8,9,11,15,20};
    La = InitList(); // 创建空表La
    for (j = 1; j <= 4; j ++) {
        ListInsert(La, j, a[j-1]);
    }
    printf("La= "); // 输出表La的内容
    ListTraverse(La, print);
    Lb = InitList();
    for (j = 1; j <= 7; j++) {
        ListInsert(Lb, j,b[j-1]);
    }
    printf("Lb= "); // 输出表Lb的内容
    ListTraverse(Lb, print);
    MergeList(La, Lb, &Lc);
    printf("Lc= "); // 输出表Lc的内容
    ListTraverse(Lc, print);
}
