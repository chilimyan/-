
//
//  bo1-1.c
//  DemoC
//
//  Created by Apple on 2018/8/24.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo1-1.h"

//构造三元组T，依次置T的3个元素的初值为v1，v2和v3
Status InitTriplet(Triplet *T, ElemType v1, ElemType v2, ElemType v3){
    if (!(*T = (ElemType *)malloc(3*sizeof(ElemType)))) {
        exit(OVERFLOW);
    }
    (*T)[0] = v1;
    (*T)[1] = v2;
    (*T)[2] = v3;
    return OK;
}

//三元组T被销毁
Status DestroyTriplet(Triplet *T){
    free(*T);
    *T = NULL;
    return OK;
}

//获取三元组的第i元的数据，并且用e返回
Status Get(Triplet T, int i, ElemType *e){
    if (i < 1 || i > 3) {
        return ERROR;
    }
    *e = T[i-1];
    return OK;
}
//设置三元组T的第i元值为e
Status Put(Triplet T, int i, ElemType e){
    if (i < 1 || i > 3) {
        return ERROR;
    }
    T[i-1] = e;
    return OK;
}

//如果三元组的3个元素按升序排列则返回1，否则返回0
Status IsAscending(Triplet T){
    return (T[0] <= T[1] && T[1] <= T[2]);
}

//如果三元组的3个元素按降序排列则返回1，否则返回0
Status IsDescending(Triplet T){
    return (T[0] >= T[1] && T[1] >= T[2]);
}

//用e返回三元组中最大的元素值
Status Max(Triplet T, ElemType *e){
    if (T[0] >= T[1] && T[0] >= T[2]) {
        *e = T[0];
    }else{
        if (T[1] > T[2]) {
            *e = T[1];
        }else{
            *e = T[2];
        }
    }
    return OK;
}

//用e返回三元组中最小的元素值
Status Min(Triplet T, ElemType *e){
    if (T[0] <= T[1] && T[0] <= T[2]) {
        *e = T[0];
    }else{
        if (T[1] > T[2]) {
            *e = T[2];
        }else{
            *e = T[1];
        }
    }
    return OK;
}


