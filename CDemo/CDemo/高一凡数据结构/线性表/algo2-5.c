//
//  algo2-5.c
//  CDemo
//
//  Created by chilim on 2018/9/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-5.h"

void Union1(LinkList La, LinkList Lb){
    //将所有在线性表Lb中但不在La中的数据元素插入到La中
    ElemType e;
    int La_len,Lb_len;
    int i;
    La_len = ListLength1(La);
    Lb_len = ListLength1(Lb);
    for (i = 1; i <= Lb_len; i ++) {
        GetElem1(Lb, i, &e);//取Lb中第i个元素付给e
        if (!LocateElem1(La, e, equal)) {
            ListInsert1(La, ++ La_len, e);
        }
    }
}

void main27(){
    LinkList La, Lb;
    int j;
    InitList1(&La);
    for (j = 1; j <= 5; j++) {
        ListInsert1(La, j, j);
    }
    printf("La = ");//输出La表的内容
    ListTraverse1(La, print);
    InitList1(&Lb);
    for (j = 1; j <= 5; j++) {
        ListInsert1(Lb, j, 2*j);
    }
    printf("Lb = ");//输出Lb表中的内容
    ListTraverse1(Lb, print);
    Union1(La, Lb);
    printf("new La = ");//输出新表La的内容
    ListTraverse1(La, print);
}
