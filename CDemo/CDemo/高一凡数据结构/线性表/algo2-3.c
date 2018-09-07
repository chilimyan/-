//
//  algo2-3.c
//  CDemo
//
//  Created by chilim on 2018/8/31.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-3.h"

void MergeList1(struct Sqlist La, struct Sqlist Lb, struct Sqlist *Lc){
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;
    Lc->listsize = Lc->length = La.length + Lb.length;//不需要InitList创建空表Lc
    pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
    if (!Lc->elem) {//存储分配失败
        exit(OVERFLOW);
    }
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc ++ = *pa ++;//将pa所指单元的值赋给pc所指单元后，pa和pc分别+1(指向下一个单元)
        }else{
            *pc ++ = *pb ++;
        }
    }
    while (pa <= pa_last) {
        *pc ++ = *pa ++;
    }
    while (pb <= pb_last) {
        *pc ++ = *pb ++;
    }
}

void main24(){
    struct Sqlist La, Lb, Lc;
    int j;
    InitList(&La);//创建空表La
    for (j = 1; j <= 5; j++) {//在La表中插入5个元素
        ListInsert(&La, j, j);
    }
    printf("La = ");//输出表La的内容
    ListTraverse(La, print1);
    InitList(&Lb);//创建空表Lb
    for (j = 1; j <= 5; j ++) {//在表Lb中插入5个元素
        ListInsert(&Lb, j, 2*j);
    }
    printf("Lb = ");//输出Lb表中的内容
    ListTraverse(Lb, print1);
    MergeList1(La, Lb, &Lc);
    printf("Lc = ");//输出Lc表内容
    ListTraverse(Lc, print1);
}
