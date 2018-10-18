//
//  bo1-1.h
//  绪论
//
//  Created by chilim on 2018/10/9.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo1_1_h
#define bo1_1_h

#include <stdio.h>
#include "c1-1.h"

// 操作结果:构造三元组T，依次置T的3个元素的初值为v1，v2和v3
Triplet InitTriplet(ElemType v1, ElemType v2, ElemType v3);

// 操作结果:三元组T被销毁
Status DestoryTriplet(Triplet *T);

// 初始条件:三元组T已存在，1≤i≤3。操作结果:用e返回T的第i元的值
Status Get(Triplet T, int i, ElemType *e);

// 初始条件:三元组T已存在，1≤i≤3。操作结果:改变T的第i元的值为e
Status Put(Triplet T, int i, ElemType e);

// 初始条件:三元组T已存在。操作结果:如果T的3个元素按升序排列，则返回1;否则返回0
Status IsAscending(Triplet T);

// 初始条件:三元组T已存在。操作结果:如果T的3个元素按降序排列，则返回1;否则返回0
Status IsDescending(Triplet T);

// 初始条件:三元组T已存在。操作结果:用e返回指向T的最大元素的值
Status Max(Triplet T, ElemType *e);

// 初始条件:三元组T已存在。操作结果:用e返回指向T的最小元素的值
Status Min(Triplet T,ElemType *e);

#endif /* bo1_1_h */
