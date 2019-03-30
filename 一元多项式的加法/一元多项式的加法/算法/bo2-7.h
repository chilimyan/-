//
//  bo2-7.h
//  一元多项式的加法
//
//  Created by chilim on 2018/10/22.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo2_7_h
#define bo2_7_h

#include <stdio.h>
#include "bo2-6.h"
#include "c2-5.h"

#define DestroyPolyn DestroyList
#define PolynLength ListLength

// 按有序判定函数compare()的约定，将值为e的结点插入或合并到升序链表L的适当位置
void OrderInsertMerge(PLinkList *L,ElemType e,int(*compare)(term,term));

///指数值的比较
int cmp(term a,term b);

// 输入m项的系数和指数，建立表示一元多项式的有序链表P
void CreatePolyn(PLinkList *L, int m);

// 打印输出一元多项式P
void PrintPolyn(PLinkList *L);

// 多项式加法:Pa=Pa+Pb，并销毁一元多项式Pb
void AddPolyn(PLinkList *pa,PLinkList *pb);

// 另一种多项式加法的算法:Pa=Pa+Pb，并销毁一元多项式Pb
void AddPolyn1(PLinkList *pa,PLinkList *pb);

// 一元多项式Pa系数取反
void Opposite(PLinkList pa);

// 多项式减法:Pa=Pa-Pb，并销毁一元多项式Pb
void SubtractPolyn(PLinkList *pa,PLinkList *pb);

// 多项式乘法:Pa=Pa×Pb，并销毁一元多项式Pb
void MultiplyPolyn(PLinkList *pa,PLinkList *pb);

#endif /* bo2_7_h */
