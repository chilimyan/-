//
//  bo3-1.c
//  栈的线性存储
//
//  Created by chilim on 2018/10/25.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo3-1.h"

// 构造一个空栈S
void InitStack(SqStack *s){
    if (!((s->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType))))) {
        exit(OVERFLOW);
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}

// 销毁栈S，S不再存在
void DestroyStack(SqStack *s){
    free(s->base);
    s->base = NULL;
    s->top = NULL;
    s->stacksize = 0;
}

// 把S置为空栈
void ClearStack(SqStack *s){
    s->top = s->base;
}

// 若栈S为空栈，则返回TRUE;否则返回FALSE
Status StackEmpty(SqStack *s){
    if (s->top == s->base) {
        return TRUE;
    }else{
        return FALSE;
    }
}
// 返回S的元素个数，即栈的长度
int StackLength(SqStack *s){
    return s->top - s->base;
}

// 若栈不空，则用e返回S的栈顶元素，并返回OK;否则返回ERROR
Status GetTop(SqStack *s,SElemType *e){
    if (s->top > s->base) {
        *e = *(s->top -1);
        return OK;
    }else{
        return ERROR;
    }
}
// 插入元素e为新的栈顶元素
void Push(SqStack *s,SElemType e){
    //栈满了，新增存储空间
    if ((*s).top - (*s).base >= (*s).stacksize) {
        (*s).base = (SElemType *)realloc((*s).base, ((*s).stacksize + STACK_INCREMENT*sizeof(SElemType)));
        if (!(*s).base) {
            exit(OVERFLOW);
        }
        (*s).top = (*s).base + (*s).stacksize;
        (*s).stacksize += STACK_INCREMENT;
    }
    *((*s).top) = e;
    (*s).top ++;
}

// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK
Status Pop(SqStack *s, SElemType *e){
    if ((*s).top == (*s).base) {
        return ERROR;
    }
    *e = *(--(*s).top);
    return OK;
}

// 从栈底到栈顶依次对栈中每个元素调用函数visit()
void StackTraverse(SqStack s,void(*visit)(SElemType)){
    while (s.top > s.base) {
        visit(*(s.base++));
    }
    printf("\n");
}

