//
//  bo1-1.c
//  绪论
//
//  Created by chilim on 2018/10/9.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo1-1.h"

// 操作结果:构造三元组T，依次置T的3个元素的初值为v1，v2和v3
Triplet InitTriplet(ElemType v1, ElemType v2, ElemType v3){
    Triplet T = NULL;
    if (!(T = (Triplet)malloc(3*sizeof(ElemType)))) {
        exit(OVERFLOW);
    }
    T[0] = v1;
    T[1] = v2;
    T[2] = v3;
    return T;
}

// 操作结果:三元组T被销毁
Status DestoryTriplet(Triplet *T){
    free(*T);
    *T = NULL;
    return OK;
}

// 初始条件:三元组T已存在，1≤i≤3。操作结果:用e返回T的第i元的值
Status Get(Triplet T, int i, ElemType *e){
    if (i < 1 || i > 3) {
        return ERROR;
    }
    *e = T[i-1];
    return OK;
}

// 初始条件:三元组T已存在，1≤i≤3。操作结果:改变T的第i元的值为e
Status Put(Triplet T, int i, ElemType e){
    if (i < 1 || i > 3) {
        return ERROR;
    }
    T[i-1] = e;
    return OK;
}

// 初始条件:三元组T已存在。操作结果:如果T的3个元素按升序排列，则返回1;否则返回0
Status IsAscending(Triplet T){
    return (T[0] <= T[1] && T[1] <= T[2]);
}

// 初始条件:三元组T已存在。操作结果:如果T的3个元素按降序排列，则返回1;否则返回0
Status IsDescending(Triplet T){
    return (T[0] >= T[1] && T[1] >= T[2]);
}

// 初始条件:三元组T已存在。操作结果:用e返回指向T的最大元素的值
Status Max(Triplet T, ElemType *e){
    *e = T[0] >= T[1] ? T[0] >= T[2] ? T[0] : T[2] : T[1] >= T[2] ? T[1] : T[2];
    return OK;
}

// 初始条件:三元组T已存在。操作结果:用e返回指向T的最小元素的值
Status Min(Triplet T,ElemType *e)
{
    *e=T[0]<=T[1]?T[0]<=T[2]?T[0]:T[2]:T[1]<=T[2]?T[1]:T[2];
    return OK;
}

