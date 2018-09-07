//
//  algo2-1.c
//  CDemo
//
//  Created by chilim on 2018/8/31.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-1.h"

void Union(struct Sqlist *La, struct Sqlist Lb){
    //将所有在线性表Lb中但不在La中的数据元素插入到La中
    ElemType e;
    int La_len,Lb_len;
    int i;
    La_len = ListLength(*La);//求线性表的长度
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i ++) {
        GetElem(Lb, i, &e);//取出第i个元素赋值给e
        if (!LocateElem(*La, e, equal)) {
            ListInsert(La, ++La_len, e);
        }
    }
}

void main21(){
    struct Sqlist La,Lb;
    int j;
    InitList(&La);//创建空表La.如不成功，则会退出程序的运行
    for (j = 1; j <= 5; j++) {
        //在La表中插入5个元素依次为1、2、3、4、5
        ListInsert(&La, j, j);
    }
    printf("La=");//输出表La
    ListTraverse(La, print1);
    InitList(&Lb);//创建表Lb的内容
    for (j = 1; j <= 5; j++) {
        ListInsert(&Lb, j, j*2);
    }
    printf("Lb=");//输出表Lb的内容
    ListTraverse(Lb, print1);
    Union(&La, Lb);//调用Union()，将Lb中满足条件的元素插入La
    printf("\nnew La = ");//输出新表La的内容
    ListTraverse(La, print1);
}
