//
//  algo2-1.c
//  线性表
//
//  Created by chilim on 2018/10/13.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-1.h"

// 将所有在线性表Lb中但不在La中的数据元素插入到La中
void Union(PSqlist La, PSqlist Lb){
    ElemType e;
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);
    for (int i = 1; i <= Lb_len; i ++) {
        // 取Lb中第i个数据元素赋给e
        GetElem(Lb, i, &e);
        if (!LocateElem(La, e, equal)) {
            ListInsert(La, ++La_len, e);
        }
    }
}

void main22(){
    struct SqList La,Lb;
    int j;
    InitList(&La);// 创建空表La。如不成功，则会退出程序的运行
    for (j = 1; j <= 5; j ++) {
        ListInsert(&La, j, j);
    }
    printf("La= "); // 输出表La的内容
    ListTraverse(&La, print1);
    InitList(&Lb);
    for (j = 1; j <= 5; j++) {
        ListInsert(&Lb, j, j*2);
    }
    printf("Lb= "); // 输出表Lb的内容
    ListTraverse(&Lb, print1);
    Union(&La, &Lb);// 调用Union()，将Lb中满足条件的元素插入La
    printf("new La= "); // 输出新表La的内容
    ListTraverse(&La, print1);
}
