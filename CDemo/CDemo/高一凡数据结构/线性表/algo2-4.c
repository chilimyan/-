//
//  algo2-4.c
//  CDemo
//
//  Created by chilim on 2018/8/31.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-4.h"

void MergeList2(struct Sqlist La, struct Sqlist Lb, struct Sqlist *Lc){
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;
    Lc->listsize = La.length + Lb.length;
    pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
    if (!Lc->elem) {
        exit(OVERFLOW);
    }
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        switch (comp(*pa, *pb)) {
            case 0:
                pb ++;
                break;
            case -1:
                *pc ++ = *pa ++;
                break;
            case 1:
                *pc ++ = *pb ++;
                break;
            default:
                break;
        }
    }
    while (pa <= pa_last) {
        *pc ++ = *pa ++;
    }
    while (pb <= pb_last) {
        *pc ++ = *pb ++;
    }
    Lc->length = pc - Lc->elem;
}

void main25(){
    struct Sqlist La, Lb, Lc;
    int j;
    InitList(&La);//创建空表La
    for (j = 1; j <= 5; j ++) {
        ListInsert(&La, j, j);
    }
    printf("La = ");//打印La中内容
    ListTraverse(La, print1);
    InitList(&Lb);
    for (j = 1; j <= 5; j ++) {
        ListInsert(&Lb, j, 2*j);
    }
    printf("Lb = ");//输出Lb表的内容
    ListTraverse(Lb, print1);
    MergeList2(La, Lb, &Lc);
    printf("Lc = ");//打印Lc的内容
    ListTraverse(Lc, print1);
}
