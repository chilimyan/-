//
//  bo3-1.h
//  栈的线性存储
//
//  Created by chilim on 2018/10/25.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef bo3_1_h
#define bo3_1_h

#include <stdio.h>
#include "c3-1.h"

// 构造一个空栈S
void InitStack(SqStack *s);

// 若栈S为空栈，则返回TRUE;否则返回FALSE
Status StackEmpty(SqStack *s);

// 把S置为空栈
void ClearStack(SqStack *s);

// 销毁栈S，S不再存在
void DestroyStack(SqStack *s);

// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK
Status Pop(SqStack *s, SElemType *e);

// 从栈底到栈顶依次对栈中每个元素调用函数visit()
void StackTraverse(SqStack s,void(*visit)(SElemType));

// 插入元素e为新的栈顶元素
void Push(SqStack *s,SElemType e);

// 若栈不空，则用e返回S的栈顶元素，并返回OK;否则返回ERROR
Status GetTop(SqStack *s,SElemType *e);

// 返回S的元素个数，即栈的长度
int StackLength(SqStack *s);

#endif /* bo3_1_h */
