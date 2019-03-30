//
//  algo3-1.c
//  栈的线性存储
//
//  Created by chilim on 2018/11/10.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo3-1.h"

void conversion(){
    SqStack s;
    unsigned n;
    SElemType e;
    InitStack(&s);//初始化栈
    printf("将十进制整数n转换为%d进制数，请输入:n(>=0)=",N);
    scanf("%u",&n); // 输入非负十进制整数n
    while (n) {
        Push(&s,n%N);// 入栈n除以N的余数(N进制的低位)
        n = n/N;
    }
    while (!StackEmpty(&s)) {// 当栈不空
        Pop(&s,&e);// 弹出栈顶元素且赋值给e
        printf("%d",e); // 输出e
    }
    printf("\n");
}
