//
//  main3-1.c
//  栈的线性存储
//
//  Created by chilim on 2018/10/25.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main3-1.h"

void print(SElemType c){
    printf("%d ",c);
}

void main31(){
    int j;
    SqStack s;
    SElemType e;
    InitStack(&s);
    for (j = 1; j <= 12; j ++) {
        Push(&s, j);
    }
    printf("栈中元素依次为");
    StackTraverse(s, print);
    Pop(&s, &e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否:%d(1:空 0:否)\n",StackEmpty(&s));
    GetTop(&s, &e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(&s));
    ClearStack(&s);
    printf("清空栈后，栈空否:%d(1:空 0:否)\n",StackEmpty(&s));
    DestroyStack(&s);
    printf("销毁栈后，s.top=%u s.base=%u s.stacksize=%d\n",s.top,s.base, s.stacksize);
}
