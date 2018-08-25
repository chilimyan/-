//
//  bo1-1.h
//  DemoC
//
//  Created by Apple on 2018/8/24.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo1_1_h
#define bo1_1_h

#include <stdio.h>
#include "c1-1.h"

//构造三元组T，依次置T的3个元素的初值为v1，v2和v3
Status InitTriplet(Triplet *T, ElemType v1, ElemType v2, ElemType v3);

//三元组T被销毁
Status DestroyTriplet(Triplet *T);

//获取三元组的第i元的数据，并且用e返回
Status Get(Triplet T, int i, ElemType *e);

//设置三元组T的第i元值为e
Status Put(Triplet T, int i, ElemType e);

//如果三元组的3个元素按升序排列则返回1，否则返回0
Status IsAscending(Triplet T);

//如果三元组的3个元素按降序排列则返回1，否则返回0
Status IsDescending(Triplet T);

//用e返回三元组中最大的元素值
Status Max(Triplet T, ElemType *e);

//用e返回三元组中最小的元素值
Status Min(Triplet T, ElemType *e);

#endif /* bo1_1_h */
